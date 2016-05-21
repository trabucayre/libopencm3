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

#ifndef K20DX_MEMORYMAP_H
#define K20DX_MEMORYMAP_H

#include <libopencm3/cm3/memorymap.h>

/* --- K20DX specific peripheral definitions ----------------------------- */

/* Memory map for all buses */
#define PERIPH_BASE	(0x40000000U)
#define PERIPH_BASE_AIPS0	(PERIPH_BASE + 0x00000)
#define PERIPH_BASE_AIPS1	(PERIPH_BASE + 0x80000)

/* Peripheral addresses */

/* AIPS0 */
#define CROSSBAR_BASE			(PERIPH_BASE_AIPS0 + 0x04000)

#define DMA_BASE				(PERIPH_BASE_AIPS0 + 0x08000)
#define DMA_TCD_BASE			(PERIPH_BASE_AIPS0 + 0x09000)

#define FLASH_MEMORY_CTL_BASE	(PERIPH_BASE_AIPS0 + 0x1F000)
#define FLASH_MEMORY_BASE		(PERIPH_BASE_AIPS0 + 0x20000)
#define DMA_MUX0_BASE			(PERIPH_BASE_AIPS0 + 0x21000)

#define FLEXCAN0_BASE			(PERIPH_BASE_AIPS0 + 0x24000)

#define SPI0_BASE				(PERIPH_BASE_AIPS0 + 0x2C000)
#define SPI1_BASE				(PERIPH_BASE_AIPS0 + 0x2D000)

#define I2S0_BASE				(PERIPH_BASE_AIPS0 + 0x2F000)

#define CRC_BASE				(PERIPH_BASE_AIPS0 + 0x32000)

#define USB_DCD_BASE			(PERIPH_BASE_AIPS0 + 0x35000)
#define PDB_BASE				(PERIPH_BASE_AIPS0 + 0x36000)
#define PIT_BASE				(PERIPH_BASE_AIPS0 + 0x37000)
#define FTM0_BASE				(PERIPH_BASE_AIPS0 + 0x38000)
#define FTM1_BASE				(PERIPH_BASE_AIPS0 + 0x39000)

#define ADC0_BASE				(PERIPH_BASE_AIPS0 + 0x3B000)

#define RTC_BASE				(PERIPH_BASE_AIPS0 + 0x3D000)
#define VBAT_BASE				(PERIPH_BASE_AIPS0 + 0x3E000)

#define LPTMR_BASE				(PERIPH_BASE_AIPS0 + 0x40000)
#define SYS_REG_BASE			(PERIPH_BASE_AIPS0 + 0x41000)

#define TSI_BASE				(PERIPH_BASE_AIPS0 + 0x45000)

#define SIM_LPL_BASE			(PERIPH_BASE_AIPS0 + 0x47000)
#define SIM_BASE				(PERIPH_BASE_AIPS0 + 0x48000)
#define PORTA_MUX_BASE			(PERIPH_BASE_AIPS0 + 0x49000)
#define PORTB_MUX_BASE			(PERIPH_BASE_AIPS0 + 0x4A000)
#define PORTC_MUX_BASE			(PERIPH_BASE_AIPS0 + 0x4B000)
#define PORTD_MUX_BASE			(PERIPH_BASE_AIPS0 + 0x4C000)
#define PORTE_MUX_BASE			(PERIPH_BASE_AIPS0 + 0x4D000)

#define SOFT_WDG_BASE			(PERIPH_BASE_AIPS0 + 0x52000)

#define EXT_WDG_BASE			(PERIPH_BASE_AIPS0 + 0x61000)
#define CMT_BASE				(PERIPH_BASE_AIPS0 + 0x62000)

#define MCG_BASE				(PERIPH_BASE_AIPS0 + 0x64000)
#define OSC_BASE				(PERIPH_BASE_AIPS0 + 0x65000)
#define I2C0_BASE				(PERIPH_BASE_AIPS0 + 0x66000)
#define I2C1_BASE				(PERIPH_BASE_AIPS0 + 0x67000)

#define UART0_BASE				(PERIPH_BASE_AIPS0 + 0x6A000)
#define UART1_BASE				(PERIPH_BASE_AIPS0 + 0x6B000)
#define UART2_BASE				(PERIPH_BASE_AIPS0 + 0x6C000)

#define USBOTG_BASE				(PERIPH_BASE_AIPS0 + 0x72000)
#define CMP_BASE				(PERIPH_BASE_AIPS0 + 0x73000)
#define VREF_BASE				(PERIPH_BASE_AIPS0 + 0x74000)

#define LLWU_BASE				(PERIPH_BASE_AIPS0 + 0x7C000)
#define PMC_BASE				(PERIPH_BASE_AIPS0 + 0x7D000)
#define SMC_BASE				(PERIPH_BASE_AIPS0 + 0x7E000)
#define RCM_BASE				(PERIPH_BASE_AIPS0 + 0x7F000)

/* AIPS0 */
#define FTM2_BASE				(PERIPH_BASE_AIPS1 + 0xB8000)

#define ADC1_BASE				(PERIPH_BASE_AIPS1 + 0xBB000)

#define DAC0_BASE				(PERIPH_BASE_AIPS1 + 0xBC000)

/* GPIO module */
#define GPIO_BASE				(PERIPH_BASE + 0xFF000)


#define SYSTEMCONTROL_BASE		(0x400FE000U)

#endif
