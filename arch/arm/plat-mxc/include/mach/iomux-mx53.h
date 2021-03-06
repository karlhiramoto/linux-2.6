/*
 * Copyright (C) 2010 Freescale Semiconductor, Inc. All Rights Reserved.
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
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc..
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef __MACH_IOMUX_MX53_H__
#define __MACH_IOMUX_MX53_H__

#include <mach/iomux-v3.h>

/*
 * various IOMUX alternate output functions (1-7)
 */
typedef enum iomux_config {
	IOMUX_CONFIG_ALT0,
	IOMUX_CONFIG_ALT1,
	IOMUX_CONFIG_ALT2,
	IOMUX_CONFIG_ALT3,
	IOMUX_CONFIG_ALT4,
	IOMUX_CONFIG_ALT5,
	IOMUX_CONFIG_ALT6,
	IOMUX_CONFIG_ALT7,
	IOMUX_CONFIG_GPIO, /* added to help user use GPIO mode */
	IOMUX_CONFIG_SION = 0x1 << 4, /* LOOPBACK:MUX SION bit */
} iomux_pin_cfg_t;

/* These 2 defines are for pins that may not have a mux register, but could
 * have a pad setting register, and vice-versa. */
#define NON_MUX_I	0x00
#define NON_PAD_I	0x00

#define MX53_UART_PAD_CTRL		(PAD_CTL_PKE | PAD_CTL_PUE |	\
		PAD_CTL_DSE_HIGH | PAD_CTL_SRE_FAST | PAD_CTL_HYS)
/* UART1 */
#define MX53_PAD_CSI0_D10__UART1_TXD	IOMUX_PAD(0x414, 0xE8, 2, 0x0, 0, MX53_UART_PAD_CTRL)
#define MX53_PAD_CSI0_D11__UART1_RXD	IOMUX_PAD(0x418, 0xEC, 2, 0x878, 1, MX53_UART_PAD_CTRL)
#define MX53_PAD_ATA_DIOW__UART1_TXD	IOMUX_PAD(0x5F0, 0x270, 3, 0x0,	0, MX53_UART_PAD_CTRL)
#define MX53_PAD_ATA_DMACK__UART1_RXD	IOMUX_PAD(0x5F4, 0x274, 3, 0x880, 3, MX53_UART_PAD_CTRL)

/* UART2 */
#define MX53_PAD_ATA_BUFFER_EN__UART2_RXD	IOMUX_PAD(0x5FC, 0x27C, 3, 0x880, 3, MX53_UART_PAD_CTRL)
#define MX53_PAD_ATA_DMARQ__UART2_TXD	IOMUX_PAD(0x5F8, 0x278, 3, 0x0, 0, MX53_UART_PAD_CTRL)
#define MX53_PAD_ATA_DIOR__UART2_RTS	IOMUX_PAD(0x604, 0x284, 3, 0x87C, 3, MX53_UART_PAD_CTRL)
#define MX53_PAD_ATA_INTRQ__UART2_CTS	IOMUX_PAD(0x600, 0x280, 3, 0x0, 0, MX53_UART_PAD_CTRL)

/* UART3 */
#define MX53_PAD_ATA_CS_0__UART3_TXD	IOMUX_PAD(0x61C, 0x29C, 4, 0x0, 0, MX53_UART_PAD_CTRL)
#define MX53_PAD_ATA_CS_1__UART3_RXD	IOMUX_PAD(0x620, 0x2A0, 4, 0x888, 3, MX53_UART_PAD_CTRL)
#define MX53_PAD_ATA_DA_1__UART3_CTS	IOMUX_PAD(0x614, 0x294, 4, 0x0, 0, MX53_UART_PAD_CTRL)
#define MX53_PAD_ATA_DA_2__UART3_RTS	IOMUX_PAD(0x618, 0x298, 4, 0x884, 5, MX53_UART_PAD_CTRL)

#define MX53_PAD_GPIO_19__GPIO_4_5		IOMUX_PAD(0x348, 0x20,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_KEY_COL0__GPIO_4_6		IOMUX_PAD(0x34C, 0x24,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_KEY_ROW0__GPIO_4_7		IOMUX_PAD(0x350, 0x28,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_KEY_COL1__GPIO_4_8		IOMUX_PAD(0x354, 0x2C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_KEY_ROW1__GPIO_4_9		IOMUX_PAD(0x358, 0x30,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_KEY_COL2__GPIO_4_10		IOMUX_PAD(0x35C, 0x34,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_KEY_ROW2__GPIO_4_11	IOMUX_PAD(0x360, 0x38,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_KEY_COL3__GPIO_4_12		IOMUX_PAD(0x364, 0x3C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_KEY_ROW3__GPIO_4_13	IOMUX_PAD(0x368, 0x40,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_KEY_COL4__GPIO_4_14		IOMUX_PAD(0x36C, 0x44,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_KEY_ROW4__GPIO_4_15	IOMUX_PAD(0x370, 0x48,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_NVCC_KEYPAD__NVCC_KEYPAD	IOMUX_PAD(0x374, NON_MUX_I,IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DI0_DISP_CLK__GPIO_4_16	IOMUX_PAD(0x378, 0x4C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DI0_PIN15__GPIO_4_17	IOMUX_PAD(0x37C, 0x50,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DI0_PIN2__GPIO_4_18		IOMUX_PAD(0x380, 0x54,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DI0_PIN3__GPIO_4_19		IOMUX_PAD(0x384, 0x58,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DI0_PIN4__GPIO_4_20		IOMUX_PAD(0x388, 0x5C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DISP0_DAT0__GPIO_4_21	IOMUX_PAD(0x38C, 0x60,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DISP0_DAT1__GPIO_4_22	IOMUX_PAD(0x390, 0x64,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DISP0_DAT2__GPIO_4_23	IOMUX_PAD(0x394, 0x68,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DISP0_DAT3__GPIO_4_24	IOMUX_PAD(0x398, 0x6C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DISP0_DAT4__GPIO_4_25	IOMUX_PAD(0x39C, 0x70,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DISP0_DAT5__GPIO_4_26	IOMUX_PAD(0x3A0, 0x74,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DISP0_DAT6__GPIO_4_27	IOMUX_PAD(0x3A4, 0x78,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DISP0_DAT7__GPIO_4_28	IOMUX_PAD(0x3A8, 0x7C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DISP0_DAT8__GPIO_4_29	IOMUX_PAD(0x3AC, 0x80,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DISP0_DAT9__GPIO_4_30	IOMUX_PAD(0x3B0, 0x84,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DISP0_DAT10__GPIO_4_31	IOMUX_PAD(0x3B4, 0x88,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DISP0_DAT11__GPIO_5_5	IOMUX_PAD(0x3B8, 0x8C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DISP0_DAT12__GPIO_5_6	IOMUX_PAD(0x3BC, 0x90,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DISP0_DAT13__GPIO_5_7	IOMUX_PAD(0x3C0, 0x94,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DISP0_DAT14__GPIO_5_8	IOMUX_PAD(0x3C4, 0x98,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DISP0_DAT15__GPIO_5_9	IOMUX_PAD(0x3C8, 0x9C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DISP0_DAT16__GPIO_5_10	IOMUX_PAD(0x3CC, 0xA0,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DISP0_DAT17__GPIO_5_11	IOMUX_PAD(0x3D0, 0xA4,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DISP0_DAT18__GPIO_5_12	IOMUX_PAD(0x3D4, 0xA8,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DISP0_DAT19__GPIO_5_13	IOMUX_PAD(0x3D8, 0xAC,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DISP0_DAT20__GPIO_5_14	IOMUX_PAD(0x3DC, 0xB0,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DISP0_DAT21__GPIO_5_15	IOMUX_PAD(0x3E0, 0xB4,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DISP0_DAT22__GPIO_5_16	IOMUX_PAD(0x3E4, 0xB8,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DISP0_DAT23__GPIO_5_17	IOMUX_PAD(0x3E8, 0xBC,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_CSI0_PIXCLK__GPIO_5_18	IOMUX_PAD(0x3EC, 0xC0,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_CSI0_MCLK__GPIO_5_19	IOMUX_PAD(0x3F0, 0xC4,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_CSI0_DATA_EN__GPIO_5_20	IOMUX_PAD(0x3F4, 0xC8,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_CSI0_VSYNC__GPIO_5_21	IOMUX_PAD(0x3F8, 0xCC,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_CSI0_D4__GPIO_5_22		IOMUX_PAD(0x3FC, 0xD0,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_CSI0_D5__GPIO_5_23		IOMUX_PAD(0x400, 0xD4,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_CSI0_D6__GPIO_5_24		IOMUX_PAD(0x404, 0xD8,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_CSI0_D7__GPIO_5_25		IOMUX_PAD(0x408, 0xDC,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_CSI0_D8__GPIO_5_26		IOMUX_PAD(0x40C, 0xE0,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_CSI0_D9__GPIO_5_27		IOMUX_PAD(0x410, 0xE4,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_CSI0_D10__GPIO_5_28		IOMUX_PAD(0x414, 0xE8,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_CSI0_D11__GPIO_5_29		IOMUX_PAD(0x418, 0xEC,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_CSI0_D12__GPIO_5_30		IOMUX_PAD(0x41C, 0xF0,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_CSI0_D13__GPIO_5_31		IOMUX_PAD(0x420, 0xF4,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_CSI0_D14__GPIO_6_0		IOMUX_PAD(0x424, 0xF8,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_CSI0_D15__GPIO_6_1		IOMUX_PAD(0x428, 0xFC,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_CSI0_D16__GPIO_6_2		IOMUX_PAD(0x42C, 0x100,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_CSI0_D17__GPIO_6_3		IOMUX_PAD(0x430, 0x104,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_CSI0_D18__GPIO_6_4		IOMUX_PAD(0x434, 0x108,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_CSI0_D19__GPIO_6_5		IOMUX_PAD(0x438, 0x10C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_NVCC_CSI0__NVCC_CSI0	IOMUX_PAD(0x43C, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_JTAG_TMS__JTAG_TMS		IOMUX_PAD(0x440, NON_MUX_I,IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_JTAG_MOD__JTAG_MOD		IOMUX_PAD(0x444, NON_MUX_I,IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_JTAG_TRSTB__JTAG_TRSTB	IOMUX_PAD(0x448, NON_MUX_I,IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_JTAG_TDI__JTAG_TDI		IOMUX_PAD(0x44C, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_JTAG_TCK__JTAG_TCK		IOMUX_PAD(0x450, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_JTAG_TDO__JTAG_TDO		IOMUX_PAD(0x454, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_A25__GPIO_5_2		IOMUX_PAD(0x458, 0x110,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_EB2__GPIO_2_30		IOMUX_PAD(0x45C, 0x114,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_D16__GPIO_3_16		IOMUX_PAD(0x460, 0x118,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_D17__GPIO_3_17		IOMUX_PAD(0x464, 0x11C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_D18__GPIO_3_18		IOMUX_PAD(0x468, 0x120,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_D19__GPIO_3_19		IOMUX_PAD(0x46C, 0x124,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_D20__GPIO_3_20		IOMUX_PAD(0x470, 0x128,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_D21__GPIO_3_21		IOMUX_PAD(0x474, 0x12C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_D22__GPIO_3_22		IOMUX_PAD(0x478, 0x130,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_D23__GPIO_3_23		IOMUX_PAD(0x47C, 0x134,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_EB3__GPIO_2_31		IOMUX_PAD(0x480, 0x138,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_D24__GPIO_3_24		IOMUX_PAD(0x484, 0x13C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_D25__GPIO_3_25		IOMUX_PAD(0x488, 0x140,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_D26__GPIO_3_26		IOMUX_PAD(0x48C, 0x144,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_D27__GPIO_3_27		IOMUX_PAD(0x490, 0x148,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_D28__GPIO_3_28		IOMUX_PAD(0x494, 0x14C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_D29__GPIO_3_29		IOMUX_PAD(0x498, 0x150,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_D30__GPIO_3_30		IOMUX_PAD(0x49C, 0x154,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_D31__GPIO_3_31		IOMUX_PAD(0x4A0, 0x158,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_NVCC_EIM1__NVCC_EIM1	IOMUX_PAD(0x4A4, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_A24__GPIO_5_4		IOMUX_PAD(0x4A8, 0x15C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_A23__GPIO_6_6		IOMUX_PAD(0x4AC, 0x160,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_A22__GPIO_2_16		IOMUX_PAD(0x4B0, 0x164,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_A21__GPIO_2_17		IOMUX_PAD(0x4B4, 0x168,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_A20__GPIO_2_18		IOMUX_PAD(0x4B8, 0x16C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_A19__GPIO_2_19		IOMUX_PAD(0x4BC, 0x170,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_A18__GPIO_2_20		IOMUX_PAD(0x4C0, 0x174,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_A17__GPIO_2_21		IOMUX_PAD(0x4C4, 0x178,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_A16__GPIO_2_22		IOMUX_PAD(0x4C8, 0x17C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_CS0__GPIO_2_23		IOMUX_PAD(0x4CC, 0x180,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_CS1__GPIO_2_24		IOMUX_PAD(0x4D0, 0x184,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_OE__GPIO_2_25		IOMUX_PAD(0x4D4, 0x188,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_RW__GPIO_2_26		IOMUX_PAD(0x4D8, 0x18C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_LBA__GPIO_2_27		IOMUX_PAD(0x4DC, 0x190,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_NVCC_EIM4__NVCC_EIM4	IOMUX_PAD(0x4E0, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_EB0__GPIO_2_28		IOMUX_PAD(0x4E4, 0x194,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_EB1__GPIO_2_29		IOMUX_PAD(0x4E8, 0x198,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_DA0__GPIO_3_0		IOMUX_PAD(0x4EC, 0x19C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_DA1__GPIO_3_1		IOMUX_PAD(0x4F0, 0x1A0,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_DA2__GPIO_3_2		IOMUX_PAD(0x4F4, 0x1A4,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_DA3__GPIO_3_3		IOMUX_PAD(0x4F8, 0x1A8,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_DA4__GPIO_3_4		IOMUX_PAD(0x4FC, 0x1AC,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_DA5__GPIO_3_5		IOMUX_PAD(0x500, 0x1B0,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_DA6__GPIO_3_6		IOMUX_PAD(0x504, 0x1B4,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_DA7__GPIO_3_7		IOMUX_PAD(0x508, 0x1B8,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_DA8__GPIO_3_8		IOMUX_PAD(0x50C, 0x1BC,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_DA9__GPIO_3_9		IOMUX_PAD(0x510, 0x1C0,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_DA10__GPIO_3_10		IOMUX_PAD(0x514, 0x1C4,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_DA11__GPIO_3_11		IOMUX_PAD(0x518, 0x1C8,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_DA12__GPIO_3_12		IOMUX_PAD(0x51C, 0x1CC,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_DA13__GPIO_3_13		IOMUX_PAD(0x520, 0x1D0,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_DA14__GPIO_3_14		IOMUX_PAD(0x524, 0x1D4,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_DA15__GPIO_3_15		IOMUX_PAD(0x528, 0x1D8,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_NANDF_WE_B__GPIO_6_12	IOMUX_PAD(0x52C, 0x1DC,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_NANDF_RE_B__GPIO_6_13	IOMUX_PAD(0x530, 0x1E0,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_WAIT__GPIO_5_0		IOMUX_PAD(0x534, 0x1E4,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_EIM_BCLK__EIM_BCLK		IOMUX_PAD(0x538, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_NVCC_EIM7__NVCC_EIM7	IOMUX_PAD(0x53C, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_LVDS1_TX3_P__GPIO_6_22	IOMUX_PAD(NON_PAD_I, 0x1EC, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_LVDS1_TX2_P__GPIO_6_24	IOMUX_PAD(NON_PAD_I, 0x1F0, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_LVDS1_CLK_P__GPIO_6_26	IOMUX_PAD(NON_PAD_I, 0x1F4, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_LVDS1_TX1_P__GPIO_6_28	IOMUX_PAD(NON_PAD_I, 0x1F8, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_LVDS1_TX0_P__GPIO_6_30	IOMUX_PAD(NON_PAD_I, 0x1FC, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_LVDS0_TX3_P__GPIO_7_22	IOMUX_PAD(NON_PAD_I, 0x200, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_LVDS0_CLK_P__GPIO_7_24	IOMUX_PAD(NON_PAD_I, 0x204, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_LVDS0_TX2_P__GPIO_7_26	IOMUX_PAD(NON_PAD_I, 0x208, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_LVDS0_TX1_P__GPIO_7_28	IOMUX_PAD(NON_PAD_I, 0x20C, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_LVDS0_TX0_P__GPIO_7_30	IOMUX_PAD(NON_PAD_I, 0x210, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GPIO_10__GPIO_4_0		IOMUX_PAD(0x540, 0x214, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GPIO_11__GPIO_4_1		IOMUX_PAD(0x544, 0x218, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GPIO_12__GPIO_4_2		IOMUX_PAD(0x548, 0x21C, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GPIO_13__GPIO_4_3		IOMUX_PAD(0x54C, 0x220, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GPIO_14__GPIO_4_4		IOMUX_PAD(0x550, 0x224, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DRAM_DQM3__DRAM_DQM3	IOMUX_PAD(0x554, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DRAM_SDQS3__DRAM_SDQS3	IOMUX_PAD(0x558, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DRAM_SDCKE1__DRAM_SDCKE1	IOMUX_PAD(0x55C, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DRAM_DQM2__DRAM_DQM2	IOMUX_PAD(0x560, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DRAM_SDODT1__DRAM_SDODT1	IOMUX_PAD(0x564, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DRAM_SDQS2__DRAM_SDQS2	IOMUX_PAD(0x568, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DRAM_RESET__DRAM_RESET	IOMUX_PAD(0x56C, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DRAM_SDCLK1__DRAM_SDCLK1	IOMUX_PAD(0x570, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DRAM_CAS__DRAM_CAS		IOMUX_PAD(0x574, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DRAM_SDCLK0__DRAM_SDCLK0	IOMUX_PAD(0x578, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DRAM_SDQS0__DRAM_SDQS0	IOMUX_PAD(0x57C, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DRAM_SDODT0__DRAM_SDODT0	IOMUX_PAD(0x580, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DRAM_DQM0__DRAM_DQM0	IOMUX_PAD(0x584, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DRAM_RAS__DRAM_RAS		IOMUX_PAD(0x588, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DRAM_SDCKE0__DRAM_SDCKE0	IOMUX_PAD(0x58C, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DRAM_SDQS1__DRAM_SDQS1	IOMUX_PAD(0x590, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_DRAM_DQM1__DRAM_DQM1	IOMUX_PAD(0x594, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_PMIC_ON_REQ__PMIC_ON_REQ	IOMUX_PAD(0x598, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_PMIC_STBY_REQ__PMIC_STBY_REQ	IOMUX_PAD(0x59C, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_NANDF_CLE__GPIO_6_7		IOMUX_PAD(0x5A0, 0x228,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_NANDF_ALE__GPIO_6_8	IOMUX_PAD(0x5A4, 0x22C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_NANDF_WP_B__GPIO_6_9	IOMUX_PAD(0x5A8, 0x230,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_NANDF_RB0__GPIO_6_10	IOMUX_PAD(0x5AC, 0x234,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_NANDF_CS0__GPIO_6_11	IOMUX_PAD(0x5B0, 0x238,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_NANDF_CS1__GPIO_6_14	IOMUX_PAD(0x5B4, 0x23C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_NANDF_CS2__GPIO_6_15	IOMUX_PAD(0x5B8, 0x240,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_NANDF_CS3__GPIO_6_16	IOMUX_PAD(0x5BC, 0x244,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_NVCC_NANDF__NVCC_NANDF	IOMUX_PAD(0x5C0, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_FEC_MDIO__GPIO_1_22		IOMUX_PAD(0x5C4, 0x248,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_FEC_REF_CLK__GPIO_1_23	IOMUX_PAD(0x5C8, 0x24C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_FEC_RX_ER__GPIO_1_24	IOMUX_PAD(0x5CC, 0x250,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_FEC_CRS_DV__GPIO_1_25	IOMUX_PAD(0x5D0, 0x254,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_FEC_RXD1__GPIO_1_26		IOMUX_PAD(0x5D4, 0x258,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_FEC_RXD0__GPIO_1_27		IOMUX_PAD(0x5D8, 0x25C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_FEC_TX_EN__GPIO_1_28	IOMUX_PAD(0x5DC, 0x260,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_FEC_TXD1__GPIO_1_29		IOMUX_PAD(0x5E0, 0x264,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_FEC_TXD0__GPIO_1_30		IOMUX_PAD(0x5E4, 0x268,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_FEC_MDC__GPIO_1_31		IOMUX_PAD(0x5E8, 0x26C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_NVCC_FEC__NVCC_FEC		IOMUX_PAD(0x5EC, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_DIOW__GPIO_6_17	IOMUX_PAD(0x5F0, 0x270,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_DMACK__GPIO_6_18	IOMUX_PAD(0x5F4, 0x274,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_DMARQ__GPIO_7_0	IOMUX_PAD(0x5F8, 0x278,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_BUFFER_EN__GPIO_7_1	IOMUX_PAD(0x5FC, 0x27C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_INTRQ__GPIO_7_2		IOMUX_PAD(0x600, 0x280,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_DIOR__GPIO_7_3		IOMUX_PAD(0x604, 0x284,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_RESET_B__GPIO_7_4	IOMUX_PAD(0x608, 0x288,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_IORDY__GPIO_7_5		IOMUX_PAD(0x60C, 0x28C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_DA_0__GPIO_7_6		IOMUX_PAD(0x610, 0x290,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_DA_1__GPIO_7_7		IOMUX_PAD(0x614, 0x294,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_DA_2__GPIO_7_8		IOMUX_PAD(0x618, 0x298,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_CS_0__GPIO_7_9		IOMUX_PAD(0x61C, 0x29C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_CS_1__GPIO_7_10		IOMUX_PAD(0x620, 0x2A0,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_NVCC_ATA2__NVCC_ATA2	IOMUX_PAD(0x624, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_DATA0__GPIO_2_0	IOMUX_PAD(0x628, 0x2A4,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_DATA1__GPIO_2_1	IOMUX_PAD(0x62C, 0x2A8,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_DATA2__GPIO_2_2	IOMUX_PAD(0x630, 0x2AC,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_DATA3__GPIO_2_3	IOMUX_PAD(0x634, 0x2B0,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_DATA4__GPIO_2_4	IOMUX_PAD(0x638, 0x2B4,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_DATA5__GPIO_2_5	IOMUX_PAD(0x63C, 0x2B8,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_DATA6__GPIO_2_6	IOMUX_PAD(0x640, 0x2BC,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_DATA7__GPIO_2_7	IOMUX_PAD(0x644, 0x2C0,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_DATA8__GPIO_2_8	IOMUX_PAD(0x648, 0x2C4,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_DATA9__GPIO_2_9	IOMUX_PAD(0x64C, 0x2C8,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_DATA10__GPIO_2_10	IOMUX_PAD(0x650, 0x2CC,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_DATA11__GPIO_2_11	IOMUX_PAD(0x654, 0x2D0,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_DATA12__GPIO_2_12	IOMUX_PAD(0x658, 0x2D4,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_DATA13__GPIO_2_13	IOMUX_PAD(0x65C, 0x2D8,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_DATA14__GPIO_2_14	IOMUX_PAD(0x660, 0x2DC,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_ATA_DATA15__GPIO_2_15	IOMUX_PAD(0x664, 0x2E0,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_NVCC_ATA0__NVCC_ATA0	IOMUX_PAD(0x668, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_SD1_DATA0__GPIO_1_16	IOMUX_PAD(0x66C, 0x2E4,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_SD1_DATA1__GPIO_1_17	IOMUX_PAD(0x670, 0x2E8,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_SD1_CMD__GPIO_1_18		IOMUX_PAD(0x674, 0x2EC,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_SD1_DATA2__GPIO_1_19	IOMUX_PAD(0x678, 0x2F0,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_SD1_CLK__GPIO_1_20		IOMUX_PAD(0x67C, 0x2F4,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_SD1_DATA3__GPIO_1_21	IOMUX_PAD(0x680, 0x2F8,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_NVCC_SD1__NVCC_SD1		IOMUX_PAD(0x684, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_SD2_CLK__GPIO_1_10		IOMUX_PAD(0x688, 0x2FC,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_SD2_CMD__GPIO_1_11		IOMUX_PAD(0x68C, 0x300,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_SD2_DATA3__GPIO_1_12	IOMUX_PAD(0x690, 0x304,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_SD2_DATA2__GPIO_1_13	IOMUX_PAD(0x694, 0x308,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_SD2_DATA1__GPIO_1_14	IOMUX_PAD(0x698, 0x30C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_SD2_DATA0__GPIO_1_15	IOMUX_PAD(0x69C, 0x310,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_NVCC_SD2__NVCC_SD2		IOMUX_PAD(0x6A0, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GPIO_0__GPIO_1_0		IOMUX_PAD(0x6A4, 0x314,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GPIO_1__GPIO_1_1		IOMUX_PAD(0x6A8, 0x318,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GPIO_9__GPIO_1_9		IOMUX_PAD(0x6AC, 0x31C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GPIO_3__GPIO_1_3		IOMUX_PAD(0x6B0, 0x320,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GPIO_6__GPIO_1_6		IOMUX_PAD(0x6B4, 0x324,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GPIO_2__GPIO_1_2		IOMUX_PAD(0x6B8, 0x328,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GPIO_4__GPIO_1_4		IOMUX_PAD(0x6BC, 0x32C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GPIO_5__GPIO_1_5		IOMUX_PAD(0x6C0, 0x330,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GPIO_7__GPIO_1_7		IOMUX_PAD(0x6C4, 0x334,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GPIO_8__GPIO_1_8		IOMUX_PAD(0x6C8, 0x338,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GPIO_16__GPIO_7_11		IOMUX_PAD(0x6CC, 0x33C,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GPIO_17__GPIO_7_12		IOMUX_PAD(0x6D0, 0x340,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GPIO_18__GPIO_7_13		IOMUX_PAD(0x6D4, 0x344,IOMUX_CONFIG_ALT1, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_NVCC_GPIO__NVCC_GPIO	IOMUX_PAD(0x6D8, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_POR_B__POR_B			IOMUX_PAD(0x6DC, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_BOOT_MODE1__BOOT_MODE1	IOMUX_PAD(0x6E0, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_RESET_IN_B__RESET_IN_B	IOMUX_PAD(0x6E4, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_BOOT_MODE0__BOOT_MODE0	IOMUX_PAD(0x6E8, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_TEST_MODE__TEST_MODE	IOMUX_PAD(0x6EC, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GRP_ADDDS__GRP_ADDDS	IOMUX_PAD(0x6F0, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GRP_DDRMODE_CTL__GRP_DDRMODE_CTL	IOMUX_PAD(0x6F4, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GRP_DDRPKE__GRP_DDRPKE	IOMUX_PAD(0x6FC, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GRP_DDRPK__GRP_DDRPK	IOMUX_PAD(0x708, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GRP_TERM_CTL3__GRP_TERM_CTL3	IOMUX_PAD(0x70C, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GRP_DDRHYS__GRP_DDRHYS	IOMUX_PAD(0x710, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GRP_DDRMODE__GRP_DDRMODE	IOMUX_PAD(0x714, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GRP_B0DS__GRP_B0DS		IOMUX_PAD(0x718, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GRP_B1DS__GRP_B1DS		IOMUX_PAD(0x71C, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GRP_CTLDS__GRP_CTLDS	IOMUX_PAD(0x720, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GRP_DDR_TYPE__GRP_DDR_TYPE	IOMUX_PAD(0x724, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GRP_B2DS__GRP_B2DS		IOMUX_PAD(0x728, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)
#define MX53_PAD_GRP_B3DS__GRP_B3DS		IOMUX_PAD(0x72C, NON_MUX_I, IOMUX_CONFIG_ALT0, 0x0, 0, NO_PAD_CTRL)

#endif	/* __MACH_IOMUX_MX53_H__ */
