/** @defgroup K20DX portcontrol_file Port Control

@ingroup K20DXxx

@brief <b>libopencm3 K20DX Port Control</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2016 Gwenhael Goavec-Merou <gwenhael.goavec-merou@trabucayre.com>

@date 24 May 2016

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

/**@{*/

#include <libopencm3/k20dx/portcontrol.h>

/** @brief Set IO Mode for pins
 *
 * @param[in] portctl uint32_t: Port Control base address
 * @param[in] mode uint16_t: pin mode (pullup/pulldown, open drain, function)
 * @param[in] gpios uint32_t
 */
void port_set_mode(uint32_t portctl, uint16_t mode, uint32_t gpios)
{
	/** PORTn_GPCHR and PORTn_GPCLR can be used to configure
	 * in the same mode more than one Pin mux, drive, drain,
	 * filter rate and pull
	 */
	uint32_t gpio_h = gpios & 0xffff0000;
	uint32_t gpio_l = gpios & 0xffff;
	if (gpio_h)
		PORTn_GPCHR(portctl) = gpio_h | mode;
	if (gpio_l)
		PORTn_GPCLR(portctl) = (gpio_l << 16) | mode;
}

/** @brief Enable Interrupt for pins
 *
 * @param[in] portctl uint32_t: Port Control base address
 * @param[in] type uint8_t: interrupt type (edge, level, dma)
 * @param[in] gpios uint32_t
 */
void port_enable_interrupt(uint32_t portctl, uint8_t type, uint32_t gpios)
{
	uint32_t gpio;

	/* for each gpio set irq mode and enable, if needed irq */
	for (gpio = 0; gpio < 32; gpio++) {
		if ((gpios >> gpio) & 0x01) {
			PORTx_PCRn(portctl, gpio) = (PORTx_PCRn(portctl, gpio) &
				~PORT_IRQC(PORT_IRQC_MASK))
				| PORT_ISF | PORT_IRQC(type);
		}
	}
}

/** @brief Disable Interrupt for pins
 *
 * @param[in] portctl uint32_t: Port Control base address
 * @param[in] gpios uint32_t
 */
void port_disable_interrupt(uint32_t portctl, uint32_t gpios)
{
	uint32_t gpio;

	/* for each gpio disable irq */
	for (gpio = 0; gpio < 32; gpio++) {
		if ((gpios >> gpio) & 0x01)
			PORTx_PCRn(portctl, gpio) &= ~PORT_ISF;
	}
}

/**@}*/

