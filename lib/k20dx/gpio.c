/** @defgroup K20DX gpio_file General Purpose I/O

@ingroup K20DXxx

@brief <b>libopencm3 K20DX General Purpose I/O</b>

@version 1.0.0

@author @htmlonly &copy; @endhtmlonly 2016 Gwenhael Goavec-Merou <gwenhael.goavec-merou@trabucayre.com>

@date 07 May 2016

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

#include <libopencm3/k20dx/gpio.h>

/** @brief Get pin input value
 *
 * @param[in] gpioport uint32_t: GPIO Port base address
 * @param[in] gpio uint32_t
 */
bool gpio_get(uint32_t gpioport, uint32_t gpio)
{
	return !!(GPIO_PDIR(gpioport) & gpio);
}

/** @brief Atomic set output
 *
 * @param[in] gpioport uint32_t: GPIO Port base address
 * @param[in] gpios uint32_t
 */
void gpio_set(uint32_t gpioport, uint32_t gpios)
{
	GPIO_PSOR(gpioport) = gpios;
}

/** @brief Atomic clear output
 *
 * @param[in] gpioport uint32_t: GPIO Port base address
 * @param[in] gpios uint32_t
 */
void gpio_clear(uint32_t gpioport, uint32_t gpios)
{
	GPIO_PCOR(gpioport) = gpios;
}

/** @brief Atomic toggle output
 *
 * @param[in] gpioport uint32_t: GPIO Port base address
 * @param[in] gpios uint32_t
 */
void gpio_toggle(uint32_t gpioport, uint32_t gpios)
{
	GPIO_PTOR(gpioport) = gpios;
}

/** @brief Atomic Real a whole GPIO Port
 *
 * @param[in] gpioport uint32_t: GPIO Port base address
 */
uint32_t gpio_port_read(uint32_t gpioport)
{
	return GPIO_PDIR(gpioport);
}

/** @brief Atomic Write a whole GPIO Port
 *
 * @param[in] gpioport uint32_t: GPIO Port base address
 * @param[in] data uint32_t: GPIO Port value
 */
void gpio_port_write(uint32_t gpioport, uint32_t data)
{
	GPIO_PDOR(gpioport) = data;
}

/**@}*/

