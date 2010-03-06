/*
 * arch/arm/mach-ixp4xx/nsb-pci.c
 *
 * nsb  board-level PCI initialization
 *
 * Copyright (C) 2010 Iron Gate S.L.
 *
 * Based on ixdp425-pci.c
 *
 * Maintainer: Karl Hiramoto <karl@hiramoto.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */

#include <linux/kernel.h>
#include <linux/pci.h>
#include <linux/init.h>
#include <linux/irq.h>
#include <linux/delay.h>
#include <asm/mach/pci.h>
#include <asm/irq.h>
#include <mach/hardware.h>
#include <asm/mach-types.h>

#define MAX_DEV		4
#define IRQ_LINES	4

/* PCI controller GPIO to IRQ pin mappings */
#define INTA		11  // GPIO 11 IRQ 28
#define INTB		10
#define INTC		9
#define INTD		8

#define IRQ_LINES   4
#define MAX_DEV     4

static void __init nsb_pci_preinit(void)
{
	set_irq_type(INTA, IRQ_TYPE_LEVEL_LOW);
	set_irq_type(INTB, IRQ_TYPE_LEVEL_LOW);
	set_irq_type(INTC, IRQ_TYPE_LEVEL_LOW);
	set_irq_type(INTD, IRQ_TYPE_LEVEL_LOW);

	ixp4xx_pci_preinit();
}

static int __init nsb_map_irq(struct pci_dev *dev, u8 slot, u8 pin)
{
	static int pci_irq_table[MAX_DEV][IRQ_LINES] = {
		{INTA, INTB, -1 , -1}, // IDE
		{INTA, INTB, -1,  -1 }, // Mini-PCI
		{INTA, INTB, INTC, -1}, // USB
		{INTD, -1, -1, -1}  // Ethernet
	};

	int irq = -1;
	if (slot >= 1 && slot <= MAX_DEV &&
		pin >= 1 && pin <= IRQ_LINES)  {
			irq = pci_irq_table[slot-1][pin-1];
	}

	return irq;
}


static int __init nsb400_map_irq(struct pci_dev *dev, u8 slot, u8 pin)
{
	static int pci_irq_table[MAX_DEV][IRQ_LINES] = {
		{INTB, INTA, -1, -1},  /* Mini-PCI slot 0 J13*/
		{INTD, INTC, -1, -1},  /* Mini-PCI slot 1 J14*/
		{INTA, INTB, INTC, INTD},  /* 3.3V PCI slot */
		{INTA, INTB, INTC, INTD}
	};

	int irq = -1;
	if (slot >= 1 && slot <= MAX_DEV &&
		pin >= 1 && pin <= IRQ_LINES)  {
			irq = pci_irq_table[slot - 1][pin - 1];
	}
	pr_debug("nsb400_map_irq slot=%d pin=%d irq=%d\n", slot, pin, irq);

	return irq;
}
struct hw_pci nsb_pci __initdata = {
	.nr_controllers = 1,
	.preinit	= nsb_pci_preinit,
	.swizzle	= pci_std_swizzle,
	.setup		= ixp4xx_setup,
	.scan		= ixp4xx_scan_bus,
	.map_irq	= nsb_map_irq,
};

struct hw_pci nsb400_pci __initdata = {
	.nr_controllers = 1,
	.preinit	= nsb_pci_preinit,
	.swizzle	= pci_std_swizzle,
	.setup		= ixp4xx_setup,
	.scan		= ixp4xx_scan_bus,
	.map_irq	= nsb400_map_irq,
};


int __init nsb_pci_init(void)
{
	if (machine_is_nsb()) {
		pci_common_init(&nsb_pci);
	} else if (machine_is_nsb400() || machine_is_nsb667()) {
		pci_common_init(&nsb400_pci);
	}

	return 0;
}


subsys_initcall(nsb_pci_init);

