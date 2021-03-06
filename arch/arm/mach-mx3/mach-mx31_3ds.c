/*
 *  Copyright 2008 Freescale Semiconductor, Inc. All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <linux/delay.h>
#include <linux/types.h>
#include <linux/init.h>
#include <linux/clk.h>
#include <linux/irq.h>
#include <linux/gpio.h>
#include <linux/platform_device.h>
#include <linux/mfd/mc13783.h>
#include <linux/spi/spi.h>
#include <linux/regulator/machine.h>
#include <linux/usb/otg.h>
#include <linux/usb/ulpi.h>

#include <mach/hardware.h>
#include <asm/mach-types.h>
#include <asm/mach/arch.h>
#include <asm/mach/time.h>
#include <asm/memory.h>
#include <asm/mach/map.h>
#include <mach/common.h>
#include <mach/iomux-mx3.h>
#include <mach/3ds_debugboard.h>
#include <mach/ulpi.h>

#include "devices-imx31.h"
#include "devices.h"

/* CPLD IRQ line for external uart, external ethernet etc */
#define EXPIO_PARENT_INT	IOMUX_TO_IRQ(MX31_PIN_GPIO1_1)

/*
 * This file contains the board-specific initialization routines.
 */

static int mx31_3ds_pins[] = {
	/* UART1 */
	MX31_PIN_CTS1__CTS1,
	MX31_PIN_RTS1__RTS1,
	MX31_PIN_TXD1__TXD1,
	MX31_PIN_RXD1__RXD1,
	IOMUX_MODE(MX31_PIN_GPIO1_1, IOMUX_CONFIG_GPIO),
	/* SPI 1 */
	MX31_PIN_CSPI2_SCLK__SCLK,
	MX31_PIN_CSPI2_MOSI__MOSI,
	MX31_PIN_CSPI2_MISO__MISO,
	MX31_PIN_CSPI2_SPI_RDY__SPI_RDY,
	MX31_PIN_CSPI2_SS0__SS0,
	MX31_PIN_CSPI2_SS2__SS2, /*CS for MC13783 */
	/* MC13783 IRQ */
	IOMUX_MODE(MX31_PIN_GPIO1_3, IOMUX_CONFIG_GPIO),
	/* USB OTG reset */
	IOMUX_MODE(MX31_PIN_USB_PWR, IOMUX_CONFIG_GPIO),
	/* USB OTG */
	MX31_PIN_USBOTG_DATA0__USBOTG_DATA0,
	MX31_PIN_USBOTG_DATA1__USBOTG_DATA1,
	MX31_PIN_USBOTG_DATA2__USBOTG_DATA2,
	MX31_PIN_USBOTG_DATA3__USBOTG_DATA3,
	MX31_PIN_USBOTG_DATA4__USBOTG_DATA4,
	MX31_PIN_USBOTG_DATA5__USBOTG_DATA5,
	MX31_PIN_USBOTG_DATA6__USBOTG_DATA6,
	MX31_PIN_USBOTG_DATA7__USBOTG_DATA7,
	MX31_PIN_USBOTG_CLK__USBOTG_CLK,
	MX31_PIN_USBOTG_DIR__USBOTG_DIR,
	MX31_PIN_USBOTG_NXT__USBOTG_NXT,
	MX31_PIN_USBOTG_STP__USBOTG_STP,
	/*Keyboard*/
	MX31_PIN_KEY_ROW0_KEY_ROW0,
	MX31_PIN_KEY_ROW1_KEY_ROW1,
	MX31_PIN_KEY_ROW2_KEY_ROW2,
	MX31_PIN_KEY_COL0_KEY_COL0,
	MX31_PIN_KEY_COL1_KEY_COL1,
	MX31_PIN_KEY_COL2_KEY_COL2,
	MX31_PIN_KEY_COL3_KEY_COL3,
	/* USB Host 2 */
	IOMUX_MODE(MX31_PIN_USBH2_CLK, IOMUX_CONFIG_FUNC),
	IOMUX_MODE(MX31_PIN_USBH2_DIR, IOMUX_CONFIG_FUNC),
	IOMUX_MODE(MX31_PIN_USBH2_NXT, IOMUX_CONFIG_FUNC),
	IOMUX_MODE(MX31_PIN_USBH2_STP, IOMUX_CONFIG_FUNC),
	IOMUX_MODE(MX31_PIN_USBH2_DATA0, IOMUX_CONFIG_FUNC),
	IOMUX_MODE(MX31_PIN_USBH2_DATA1, IOMUX_CONFIG_FUNC),
	IOMUX_MODE(MX31_PIN_PC_VS2, IOMUX_CONFIG_ALT1),
	IOMUX_MODE(MX31_PIN_PC_BVD1, IOMUX_CONFIG_ALT1),
	IOMUX_MODE(MX31_PIN_PC_BVD2, IOMUX_CONFIG_ALT1),
	IOMUX_MODE(MX31_PIN_PC_RST, IOMUX_CONFIG_ALT1),
	IOMUX_MODE(MX31_PIN_IOIS16, IOMUX_CONFIG_ALT1),
	IOMUX_MODE(MX31_PIN_PC_RW_B, IOMUX_CONFIG_ALT1),
	/* USB Host2 reset */
	IOMUX_MODE(MX31_PIN_USB_BYP, IOMUX_CONFIG_GPIO),
};

/*
 * Matrix keyboard
 */

static const uint32_t mx31_3ds_keymap[] = {
	KEY(0, 0, KEY_UP),
	KEY(0, 1, KEY_DOWN),
	KEY(1, 0, KEY_RIGHT),
	KEY(1, 1, KEY_LEFT),
	KEY(1, 2, KEY_ENTER),
	KEY(2, 0, KEY_F6),
	KEY(2, 1, KEY_F8),
	KEY(2, 2, KEY_F9),
	KEY(2, 3, KEY_F10),
};

static const struct matrix_keymap_data mx31_3ds_keymap_data __initconst = {
	.keymap		= mx31_3ds_keymap,
	.keymap_size	= ARRAY_SIZE(mx31_3ds_keymap),
};

/* Regulators */
static struct regulator_init_data pwgtx_init = {
	.constraints = {
		.boot_on	= 1,
		.always_on	= 1,
	},
};

static struct regulator_init_data gpo_init = {
	.constraints = {
		.boot_on = 1,
		.always_on = 1,
	}
};

static struct mc13783_regulator_init_data mx31_3ds_regulators[] = {
	{
		.id = MC13783_REG_PWGT1SPI, /* Power Gate for ARM core. */
		.init_data = &pwgtx_init,
	}, {
		.id = MC13783_REG_PWGT2SPI, /* Power Gate for L2 Cache. */
		.init_data = &pwgtx_init,
	}, {

		.id = MC13783_REGU_GPO1, /* Turn on 1.8V */
		.init_data = &gpo_init,
	}, {
		.id = MC13783_REGU_GPO3, /* Turn on 3.3V */
		.init_data = &gpo_init,
	},
};

/* MC13783 */
static struct mc13783_platform_data mc13783_pdata __initdata = {
	.regulators = mx31_3ds_regulators,
	.num_regulators = ARRAY_SIZE(mx31_3ds_regulators),
	.flags  = MC13783_USE_REGULATOR | MC13783_USE_TOUCHSCREEN,
};

/* SPI */
static int spi1_internal_chipselect[] = {
	MXC_SPI_CS(0),
	MXC_SPI_CS(2),
};

static const struct spi_imx_master spi1_pdata __initconst = {
	.chipselect	= spi1_internal_chipselect,
	.num_chipselect	= ARRAY_SIZE(spi1_internal_chipselect),
};

static struct spi_board_info mx31_3ds_spi_devs[] __initdata = {
	{
		.modalias	= "mc13783",
		.max_speed_hz	= 1000000,
		.bus_num	= 1,
		.chip_select	= 1, /* SS2 */
		.platform_data	= &mc13783_pdata,
		.irq		= IOMUX_TO_IRQ(MX31_PIN_GPIO1_3),
		.mode = SPI_CS_HIGH,
	},
};

/*
 * NAND Flash
 */
static const struct mxc_nand_platform_data
mx31_3ds_nand_board_info __initconst = {
	.width		= 1,
	.hw_ecc		= 1,
#ifdef MACH_MX31_3DS_MXC_NAND_USE_BBT
	.flash_bbt	= 1,
#endif
};

/*
 * USB OTG
 */

#define USB_PAD_CFG (PAD_CTL_DRV_MAX | PAD_CTL_SRE_FAST | PAD_CTL_HYS_CMOS | \
		     PAD_CTL_ODE_CMOS | PAD_CTL_100K_PU)

#define USBOTG_RST_B IOMUX_TO_GPIO(MX31_PIN_USB_PWR)
#define USBH2_RST_B IOMUX_TO_GPIO(MX31_PIN_USB_BYP)

static int mx31_3ds_usbotg_init(void)
{
	int err;

	mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA0, USB_PAD_CFG);
	mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA1, USB_PAD_CFG);
	mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA2, USB_PAD_CFG);
	mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA3, USB_PAD_CFG);
	mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA4, USB_PAD_CFG);
	mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA5, USB_PAD_CFG);
	mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA6, USB_PAD_CFG);
	mxc_iomux_set_pad(MX31_PIN_USBOTG_DATA7, USB_PAD_CFG);
	mxc_iomux_set_pad(MX31_PIN_USBOTG_CLK, USB_PAD_CFG);
	mxc_iomux_set_pad(MX31_PIN_USBOTG_DIR, USB_PAD_CFG);
	mxc_iomux_set_pad(MX31_PIN_USBOTG_NXT, USB_PAD_CFG);
	mxc_iomux_set_pad(MX31_PIN_USBOTG_STP, USB_PAD_CFG);

	err = gpio_request(USBOTG_RST_B, "otgusb-reset");
	if (err) {
		pr_err("Failed to request the USB OTG reset gpio\n");
		return err;
	}

	err = gpio_direction_output(USBOTG_RST_B, 0);
	if (err) {
		pr_err("Failed to drive the USB OTG reset gpio\n");
		goto usbotg_free_reset;
	}

	mdelay(1);
	gpio_set_value(USBOTG_RST_B, 1);
	return 0;

usbotg_free_reset:
	gpio_free(USBOTG_RST_B);
	return err;
}

static int mx31_3ds_host2_init(struct platform_device *pdev)
{
	int err;

	mxc_iomux_set_pad(MX31_PIN_USBH2_CLK, USB_PAD_CFG);
	mxc_iomux_set_pad(MX31_PIN_USBH2_DIR, USB_PAD_CFG);
	mxc_iomux_set_pad(MX31_PIN_USBH2_NXT, USB_PAD_CFG);
	mxc_iomux_set_pad(MX31_PIN_USBH2_STP, USB_PAD_CFG);
	mxc_iomux_set_pad(MX31_PIN_USBH2_DATA0, USB_PAD_CFG);
	mxc_iomux_set_pad(MX31_PIN_USBH2_DATA1, USB_PAD_CFG);
	mxc_iomux_set_pad(MX31_PIN_PC_VS2, USB_PAD_CFG);
	mxc_iomux_set_pad(MX31_PIN_PC_BVD1, USB_PAD_CFG);
	mxc_iomux_set_pad(MX31_PIN_PC_BVD2, USB_PAD_CFG);
	mxc_iomux_set_pad(MX31_PIN_PC_RST, USB_PAD_CFG);
	mxc_iomux_set_pad(MX31_PIN_IOIS16, USB_PAD_CFG);
	mxc_iomux_set_pad(MX31_PIN_PC_RW_B, USB_PAD_CFG);

	err = gpio_request(USBH2_RST_B, "usbh2-reset");
	if (err) {
		pr_err("Failed to request the USB Host 2 reset gpio\n");
		return err;
	}

	err = gpio_direction_output(USBH2_RST_B, 0);
	if (err) {
		pr_err("Failed to drive the USB Host 2 reset gpio\n");
		goto usbotg_free_reset;
	}

	mdelay(1);
	gpio_set_value(USBH2_RST_B, 1);
	return 0;

usbotg_free_reset:
	gpio_free(USBH2_RST_B);
	return err;
}

#if defined(CONFIG_USB_ULPI)
static struct mxc_usbh_platform_data otg_pdata __initdata = {
	.portsc	= MXC_EHCI_MODE_ULPI,
	.flags	= MXC_EHCI_POWER_PINS_ENABLED,
};

static struct mxc_usbh_platform_data usbh2_pdata __initdata = {
	.init = mx31_3ds_host2_init,
	.portsc	= MXC_EHCI_MODE_ULPI,
	.flags	= MXC_EHCI_POWER_PINS_ENABLED,
};
#endif

static const struct fsl_usb2_platform_data usbotg_pdata __initconst = {
	.operating_mode = FSL_USB2_DR_DEVICE,
	.phy_mode	= FSL_USB2_PHY_ULPI,
};

static int otg_mode_host;

static int __init mx31_3ds_otg_mode(char *options)
{
	if (!strcmp(options, "host"))
		otg_mode_host = 1;
	else if (!strcmp(options, "device"))
		otg_mode_host = 0;
	else
		pr_info("otg_mode neither \"host\" nor \"device\". "
			"Defaulting to device\n");
	return 0;
}
__setup("otg_mode=", mx31_3ds_otg_mode);

static const struct imxuart_platform_data uart_pdata __initconst = {
	.flags = IMXUART_HAVE_RTSCTS,
};

/*
 * Set up static virtual mappings.
 */
static void __init mx31_3ds_map_io(void)
{
	mx31_map_io();
}

/*!
 * Board specific initialization.
 */
static void __init mxc_board_init(void)
{
	mxc_iomux_setup_multiple_pins(mx31_3ds_pins, ARRAY_SIZE(mx31_3ds_pins),
				      "mx31_3ds");

	imx31_add_imx_uart0(&uart_pdata);
	imx31_add_mxc_nand(&mx31_3ds_nand_board_info);

	imx31_add_spi_imx1(&spi1_pdata);
	spi_register_board_info(mx31_3ds_spi_devs,
						ARRAY_SIZE(mx31_3ds_spi_devs));

	imx31_add_imx_keypad(&mx31_3ds_keymap_data);

	mx31_3ds_usbotg_init();
#if defined(CONFIG_USB_ULPI)
	if (otg_mode_host) {
		otg_pdata.otg = otg_ulpi_create(&mxc_ulpi_access_ops,
				ULPI_OTG_DRVVBUS | ULPI_OTG_DRVVBUS_EXT);

		imx31_add_mxc_ehci_otg(&otg_pdata);
	}
	usbh2_pdata.otg = otg_ulpi_create(&mxc_ulpi_access_ops,
				ULPI_OTG_DRVVBUS | ULPI_OTG_DRVVBUS_EXT);
	imx31_add_mxc_ehci_hs(2, &usbh2_pdata);
#endif
	if (!otg_mode_host)
		imx31_add_fsl_usb2_udc(&usbotg_pdata);

	if (mxc_expio_init(MX31_CS5_BASE_ADDR, EXPIO_PARENT_INT))
		printk(KERN_WARNING "Init of the debug board failed, all "
				    "devices on the debug board are unusable.\n");
	imx31_add_imx2_wdt(NULL);
}

static void __init mx31_3ds_timer_init(void)
{
	mx31_clocks_init(26000000);
}

static struct sys_timer mx31_3ds_timer = {
	.init	= mx31_3ds_timer_init,
};

/*
 * The following uses standard kernel macros defined in arch.h in order to
 * initialize __mach_desc_MX31_3DS data structure.
 */
MACHINE_START(MX31_3DS, "Freescale MX31PDK (3DS)")
	/* Maintainer: Freescale Semiconductor, Inc. */
	.boot_params    = MX3x_PHYS_OFFSET + 0x100,
	.map_io         = mx31_3ds_map_io,
	.init_irq       = mx31_init_irq,
	.init_machine   = mxc_board_init,
	.timer          = &mx31_3ds_timer,
MACHINE_END
