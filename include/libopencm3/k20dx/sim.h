/** @defgroup sim_defines System Integration Module Defines

@brief <b>Defined Constants and Types for the K20DX System Integration Module</b>

@ingroup K20DXxx_defines

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2016 Gwenhael Goavec-Merou <gwenhael.goavec-merou@trabucayre.com>

@date 20 May 2016

LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * Copyright (C) 2016 Gwenhael Goavec-Merou <gwenhael.goavec-merou@trabucayre.com>
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef K20DX_SIM_H
#define K20DX_SIM_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/k20dx/memorymap.h>

/* --- SIM registers ------------------------------------------------------ */

#define SIM_SOPT1		MMIO32(SIM_BASE + 0x00)
#define SIM_SOPT1CFG	MMIO32(SIM_BASE + 0x04)
#define SIM_SOPT2		MMIO32(SIM_BASE + 0x08)
#define SIM_SOPT4		MMIO32(SIM_BASE + 0x0c)
#define SIM_SOPT5		MMIO32(SIM_BASE + 0x10)
#define SIM_SOPT7		MMIO32(SIM_BASE + 0x18)
#define SIM_SDID		MMIO32(SIM_BASE + 0x24)
#define SIM_SCGC(offset)	MMIO32(SIM_BASE + 0x28 + (4*offset))
#define SIM_CLKDIV1		MMIO32(SIM_BASE + 0x44)
#define SIM_CLKDIV2		MMIO32(SIM_BASE + 0x48)
#define SIM_FCFG1		MMIO32(SIM_BASE + 0x4c)
#define SIM_FCFG2		MMIO32(SIM_BASE + 0x50)
#define SIM_UIDH		MMIO32(SIM_BASE + 0x54)
#define SIM_UIDMH		MMIO32(SIM_BASE + 0x58)
#define SIM_UIDML		MMIO32(SIM_BASE + 0x5c)
#define SIM_UIDL		MMIO32(SIM_BASE + 0x60)

/* --- registers values ---------------------------------------------------- */

/* SOPT1: System Option Register 1 */
#define SIM_SOPT1_USBREGEN (1 << 31)
#define SIM_SOPT1_USBSSTBY (1 << 30)
#define SIM_SOPT1_USBVSTBY (1 << 29)

/* 32k oscillator clock sel */
#define SIM_SOPT1_OSC32KSEL(_sel) 	(_sel << 18)
#define SIM_SOPT1_OSC32KSEL_SYS_OSC 0x0
#define SIM_SOPT1_OSC32KSEL_RTC 	0x2
#define SIM_SOPT1_OSC32KSEL_LPO 	0x3
#define SIM_SOPT1_OSC32KSEL_MASK 	0x3

/* ram size */
#define SIM_SOPT1_RAMSIZE_SHIFT 12
#define SIM_SOPT1_RAMSIZE_MASK (0xf << 12)

/* SOPT1CFG: SOPT1 Configuration Register */
#define SIM_SOPT1CFG_USSWE	(1 << 26)
#define SIM_SOPT1CFG_UVSWE	(1 << 25)
#define SIM_SOPT1CFG_URWE	(1 << 24)

/* SOPT1: System Option Register 1 */
#define SIM_SOPT2_USBRC			(1 << 18)
#define SIM_SOPT2_PLLFLLSEL		(1 << 16)
#define SIM_SOPT2_TRACECLKSEL	(1 << 12)
#define SIM_SOPT2_PTD7PAD		(1 << 11)

/* CLKOUT select */
#define SIM_SOPT2_CLKOUTSEL(_sel) 		(_sel << 5)
#define SIM_SOPT2_CLKOUTSEL_FLASH_CLK 	0x2
#define SIM_SOPT2_CLKOUTSEL_LP0_CLK 	0x3
#define SIM_SOPT2_CLKOUTSEL_MCGIRCLK 	0x4
#define SIM_SOPT2_CLKOUTSEL_RTC 		0x5
#define SIM_SOPT2_CLKOUTSEL_OSCERCLK0 	0x6
#define SIM_SOPT2_CLKOUTSEL_MASK 		0x7

#define SIM_SOPT2_RTCCLKOUTSEL			(1 << 4)

/* SOPT4: System Option Register 4 */
#define SIM_SOPT4_FTM0TRG1SRC		(1 << 29)
#define SIM_SOPT4_FTM0TRG0SRC		(1 << 28)
#define SIM_SOPT4_FTM2CLKSEL		(1 << 26)
#define SIM_SOPT4_FTM1CLKSEL		(1 << 25)
#define SIM_SOPT4_FTM0CLKSEL		(1 << 24)
#define SIM_SOPT4_FTM2CH0SRC(_src)	(_src << 20)
#define SIM_SOPT4_FTM1CH0SRC(_src)	(_src << 18)
#define SIM_SOPT4_FTMxCH0SRC_CH0	0x0
#define SIM_SOPT4_FTMxCH0SRC_CMP0	0x1
#define SIM_SOPT4_FTMxCH0SRC_CMP1	0x2
#define SIM_SOPT4_FTMxCH0SRC_USB	0x3
#define SIM_SOPT4_FTMxCH0SRC_MASK	0x3

#define SIM_SOPT4_FTM2FLT0			(1 << 8)
#define SIM_SOPT4_FTM1FLT0			(1 << 4)
#define SIM_SOPT4_FTM0FLT2			(1 << 2)
#define SIM_SOPT4_FTM0FLT1			(1 << 1)
#define SIM_SOPT4_FTM0FLT0			(1 << 0)


/* SOPT5: System Option Register 5 */
#define SIM_SOPT5_UART1RXSRC(_src)		(_src << 6)
#define SIM_SOPT5_UART1TXSRC(_src)		(_src << 4)
#define SIM_SOPT5_UART0RXSRC(_src)		(_src << 2)
#define SIM_SOPT5_UART0TXSRC(_src)		(_src << 0)

#define SIM_SOPT5_UARTnRXSRC_RX_PIN		0x0
#define SIM_SOPT5_UARTnRXSRC_CMP0		0x1
#define SIM_SOPT5_UARTnRXSRC_CMP1		0x2
#define SIM_SOPT5_UARTnRXSRC_MASK		0x3

#define SIM_SOPT5_UARTnTXSRC_TX_PIN		0x0
#define SIM_SOPT5_UARTnTXSRC_CMP0		0x1
#define SIM_SOPT5_UARTnTXSRC_CMP1		0x2
#define SIM_SOPT5_UARTnTXSRC_MASK		0x3

/* SOPT7: System Option Register 7 */
#define SIM_SOPT7_ADC1ALTTRGEN			(1 << 15)
#define SIM_SOPT7_ADC1PRETRGSEL			(1 << 12)
#define SIM_SOPT7_ADC1_TRGSEL(_sel)		(_sel << 8)
#define SIM_SOPT7_ADC0ALTTRGEN			(1 << 7)
#define SIM_SOPT7_ADC0PRETRGSEL			(1 << 4)
#define SIM_SOPT7_ADC0_TRGSEL(_sel)		(_sel << 0)

#define SIM_SOPT7_ADCx_TRGSEL_EXT		0x0
#define SIM_SOPT7_ADCx_TRGSEL_HSC0		0x1
#define SIM_SOPT7_ADCx_TRGSEL_HSC1		0x2
#define SIM_SOPT7_ADCx_TRGSEL_HSC2		0x3
#define SIM_SOPT7_ADCx_TRGSEL_PIT0		0x4
#define SIM_SOPT7_ADCx_TRGSEL_PIT1		0x5
#define SIM_SOPT7_ADCx_TRGSEL_PIT2		0x6
#define SIM_SOPT7_ADCx_TRGSEL_PIT3		0x7
#define SIM_SOPT7_ADCx_TRGSEL_FTM0		0x8
#define SIM_SOPT7_ADCx_TRGSEL_FTM1		0x9
#define SIM_SOPT7_ADCx_TRGSEL_FTM2		0xa
#define SIM_SOPT7_ADCx_TRGSEL_RTC_ALR	0xc
#define SIM_SOPT7_ADCx_TRGSEL_RTC_SEC	0xd
#define SIM_SOPT7_ADCx_TRGSEL_LPTT		0xe
#define SIM_SOPT7_ADCx_TRGSEL_MASK		0xf	

/* SDID: System Device Identification Register */
#define SIM_SDID_REVID_SHIFT	28
#define SIM_SDID_REVID_MASK		(0xf << 28)
#define SIM_SDID_FAMID_SHIFT	4
#define SIM_SDID_FAMID_MASK		(0x7 << 4)
#define SIM_SDID_PINID_SHIFT	0
#define SIM_SDID_PINID_MASK		(0xf << 0)

/* CLKDIV1: System Clock Divider Register 1 */
#define SIM_CLKDIV1_OUTDIV1(_div)	(_div << 28)
#define SIM_CLKDIV1_OUTDIV2(_div)	(_div << 24)
#define SIM_CLKDIV1_OUTDIV4(_div)	(_div << 16)

#define SIM_CLKDIV1_OUTDIV_DIV_1	0x0
#define SIM_CLKDIV1_OUTDIV_DIV_2	0x1
#define SIM_CLKDIV1_OUTDIV_DIV_3	0x2
#define SIM_CLKDIV1_OUTDIV_DIV_4	0x3
#define SIM_CLKDIV1_OUTDIV_DIV_5	0x4
#define SIM_CLKDIV1_OUTDIV_DIV_6	0x5
#define SIM_CLKDIV1_OUTDIV_DIV_7	0x6
#define SIM_CLKDIV1_OUTDIV_DIV_8	0x7
#define SIM_CLKDIV1_OUTDIV_DIV_9	0x8
#define SIM_CLKDIV1_OUTDIV_DIV_10	0x9
#define SIM_CLKDIV1_OUTDIV_DIV_11	0xa
#define SIM_CLKDIV1_OUTDIV_DIV_12	0xb
#define SIM_CLKDIV1_OUTDIV_DIV_13	0xc
#define SIM_CLKDIV1_OUTDIV_DIV_14	0xd
#define SIM_CLKDIV1_OUTDIV_DIV_15	0xe
#define SIM_CLKDIV1_OUTDIV_DIV_16	0xf
#define SIM_CLKDIV1_OUTDIV_MASK		0xf

/* CLKDIV2: System Clock Divider Register 2 */
#define SIM_CLKDIV2_USBDIV_SHIFT	1
#define SIM_CLKDIV2_USBDIV_MASK		(0x7 << 1)
#define SIM_CLKDIV2_USBFRAC_SHIFT	0
#define SIM_CLKDIV2_USBFRAC_MASK	(0x1 << 0)

static inline void set_outdiv1_div(uint8_t div)
{
	SIM_CLKDIV1 = (SIM_CLKDIV1 & ~SIM_CLKDIV1_OUTDIV1(SIM_CLKDIV1_OUTDIV_MASK))
		| SIM_CLKDIV1_OUTDIV1(div);
}

static inline void set_outdiv2_div(uint8_t div)
{
	SIM_CLKDIV1 = (SIM_CLKDIV1 & ~SIM_CLKDIV1_OUTDIV2(SIM_CLKDIV1_OUTDIV_MASK))
		| SIM_CLKDIV1_OUTDIV2(div);
}

static inline void set_outdiv4_div(uint8_t div)
{
	SIM_CLKDIV1 = (SIM_CLKDIV1 & ~SIM_CLKDIV1_OUTDIV4(SIM_CLKDIV1_OUTDIV_MASK))
		| SIM_CLKDIV1_OUTDIV4(div);
}

/* FCFG1: Flash Configuration Register 1 */
#define SIM_FCFG2_NVMSIZE_SHIFT		28
#define SIM_FCFG2_NVMSIZE_MASK		0xf
#define SIM_FCFG2_PFSIZE_SHIFT		24
#define SIM_FCFG2_PFSIZE_MASK		0xf
#define SIM_FCFG2_EESIZE_SHIFT		16
#define SIM_FCFG2_EESIZE_MASK		0xf
#define SIM_FCFG2_DEPART_SHIFT		8
#define SIM_FCFG2_DEPART_MASK		0xf
#define SIM_FCFG2_FLASHDOZE			(1 << 1)
#define SIM_FCFG2_FLASHDIS			(1 << 0)

/* FCFG2: Flash Configuration Register 2 */
#define SIM_FCFG2_MAXADDR0_SHIFT	24
#define SIM_FCFG2_MAXADDR0_MASK		0x7f
#define SIM_FCFG2_PFLSH_SHIFT		23
#define SIM_FCFG2_PFLSH_MASK		0x1
#define SIM_FCFG2_MAXADDR1_SHIFT	16
#define SIM_FCFG2_MAXADDR1_MASK		0x7f

/* --- Variables definitions ----------------------------------------------- */
enum sim_clock_gate {
	/* SIM_SCGC1 */
	/* SIM_SCGC2 */
	CGC_DAC0 = 44,
	/* SIM_SCGC3 */
	CGC_FTM2 = 88,
	CGC_RESERVED89,
	CGC_RESERVED90,
	CGC_ADC1,
	/* SIM_SCGC4 */
	CGC_RESERVED96,
	CGC_EWM = 97,
	CGC_CMT,
	CGC_RESERVED99,
	CGC_RESERVED100,
	CGC_RESERVED101,
	CGC_I2C0,
	CGC_I2C1,
	CGC_RESERVED104,
	CGC_RESERVED105,
	CGC_UART0,
	CGC_UART1,
	CGC_UART2,
	CGC_RESERVED106,
	CGC_RESERVED107,
	CGC_RESERVED108,
	CGC_RESERVED109,
	CGC_RESERVED110,
	CGC_USBOTG,
	CGC_CMP,
	CGC_VREF,
	/* SIM_SCGC5 */
	CGC_LPTIMER = 128,
	CGC_RESERVED129,
	CGC_RESERVED130,
	CGC_RESERVED131,
	CGC_RESERVED132,
	CGC_TSI,
	CGC_RESERVED133,
	CGC_RESERVED134,
	CGC_RESERVED135,
	CGC_PORTA,
	CGC_PORTB,
	CGC_PORTC,
	CGC_PORTD,
	CGC_PORTE,
	/* SIM_SCGC6 */
	CGC_FTFL= 160,
	CGC_DMAMUX,
	CGC_RESERVED162,
	CGC_RESERVED163,
	CGC_FLEXCAN0
	/* GGM TBD */

};

BEGIN_DECLS

void sim_clock_gate_enable(enum sim_clock_gate gr);
void sim_clock_gate_disable(enum sim_clock_gate gr);

END_DECLS

/**@}*/

#endif

