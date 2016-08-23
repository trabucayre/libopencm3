/** @defgroup portcontrol_defines Port Control and Interrupts Defines
 *
 * @brief <b>Defined Constants and Types for the K20DX Port Control and Interrupts</b>
 *
 * @ingroup K20DXxx_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2016 Gwenhael Goavec-Merou <gwenhael.goavec-merou@trabucayre.com>
 *
 * @date 24 May 2016
 *
 * LGPL License Terms @ref lgpl_license
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

#ifndef K20DX_PORTCONTROL_H
#define K20DX_PORTCONTROL_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/k20dx/memorymap.h>

/* --- Convenience macros -------------------------------------------------- */

/****************************************************************************/
/** @defgroup gpio_reg_base PORTCONTROL register base addresses
@ingroup k20dx_gpio_defines

@{*/
/* PORTCONTROL port base addresses (for convenience) */
#define PORTA_CONTROL			(PORTA_MUX_BASE)
#define PORTB_CONTROL			(PORTB_MUX_BASE)
#define PORTC_CONTROL			(PORTC_MUX_BASE)
#define PORTD_CONTROL			(PORTD_MUX_BASE)
#define PORTE_CONTROL			(PORTE_MUX_BASE)
/**@}*/

/* --- PORTCONTROL registers ----------------------------------------------- */

/* Pin Control Register n (PORTx_PCRn) */
#define PORTx_PCRn(port, pin)	MMIO32(port + (pin << 2))
#define PORTA_PCRn(pin)			PORTx_PCRn(PORTA_CONTROL, pin)
#define PORTB_PCRn(pin)			PORTx_PCRn(PORTB_CONTROL, pin)
#define PORTC_PCRn(pin)			PORTx_PCRn(PORTC_CONTROL, pin)
#define PORTD_PCRn(pin)			PORTx_PCRn(PORTD_CONTROL, pin)
#define PORTE_PCRn(pin)			PORTx_PCRn(PORTE_CONTROL, pin)

/* Global Pin Control Low Register (PORTn_GPCLR) */
#define PORTn_GPCLR(port)		MMIO32(port + 0x80)
#define PORTA_GPCLR				PORTn_GPCLR(PORTA_CONTROL)
#define PORTB_GPCLR				PORTn_GPCLR(PORTB_CONTROL)
#define PORTC_GPCLR				PORTn_GPCLR(PORTC_CONTROL)
#define PORTD_GPCLR				PORTn_GPCLR(PORTD_CONTROL)
#define PORTE_GPCLR				PORTn_GPCLR(PORTE_CONTROL)

/* Global Pin Control High Register (PORTn_GPCHR) */
#define PORTn_GPCHR(port)		MMIO32(port + 0x84) 
#define PORTA_GPCHR				PORTn_GPCHR(PORTA_CONTROL)
#define PORTB_GPCHR				PORTn_GPCHR(PORTB_CONTROL)
#define PORTC_GPCHR				PORTn_GPCHR(PORTC_CONTROL)
#define PORTD_GPCHR				PORTn_GPCHR(PORTD_CONTROL)
#define PORTE_GPCHR				PORTn_GPCHR(PORTE_CONTROL)

/* Interrupt Status Flag Register (PORTx_ISFR) */
#define PORTx_ISFR(port)		MMIO32(port + 0xA0) 
#define PORTA_ISFR				PORTx_ISFR(PORTA_CONTROL)
#define PORTB_ISFR				PORTx_ISFR(PORTB_CONTROL)
#define PORTC_ISFR				PORTx_ISFR(PORTC_CONTROL)
#define PORTD_ISFR				PORTx_ISFR(PORTD_CONTROL)
#define PORTE_ISFR				PORTx_ISFR(PORTE_CONTROL)

/* --- registers values ----------------------------------------------- */
#define PORT_ISF 					(1 << 24)
#define PORT_IRQC(_irq) 			(_irq << 16)
#define PORT_IRQC_DIS				0x0
#define PORT_IRQC_DMA_RISING		0x1
#define PORT_IRQC_DMA_FALLING		0x2
#define PORT_IRQC_DMA_BOTH			0x3
#define PORT_IRQC_LOW_LEVEL			0x8
#define PORT_IRQC_RIGING_EDGE		0x9
#define PORT_IRQC_FALLING_EDGE		0xa
#define PORT_IRQC_BOTH_EDGE			0xb
#define PORT_IRQC_HIGH_LEVEL		0xc
#define PORT_IRQC_MASK				0xc

#define PORT_LK						(1 << 15)

#define PORT_MUX(_mux)				(_mux << 8)
#define PORT_MUX_DIS				0x0
#define PORT_MUX_ALT1				0x1
#define PORT_MUX_ALT2				0x2
#define PORT_MUX_ALT3				0x3
#define PORT_MUX_ALT4				0x4
#define PORT_MUX_ALT5				0x5
#define PORT_MUX_ALT6				0x6
#define PORT_MUX_ALT7				0x7
#define PORT_MUX_MASK				0x7

#define PORT_DSE					(1 << 6)
#define PORT_ODE					(1 << 5)
#define PORT_PFE					(1 << 4)
#define PORT_SRE					(1 << 2)
#define PORT_PE						(1 << 1)
#define PORT_PS						(1 << 0)

#define PORT_PULLUP_EN				(PORT_PE | PORT_PS)
#define PORT_PULLDOWN_EN			(PORT_PE)

BEGIN_DECLS

void port_set_mode(uint32_t gpioport, uint16_t mode, uint32_t gpios);
void port_enable_interrupt(uint32_t gpioport, uint8_t mode, uint32_t gpios);
void port_disable_interrupt(uint32_t gpioport, uint32_t gpios);

END_DECLS

/**@}*/

#endif
