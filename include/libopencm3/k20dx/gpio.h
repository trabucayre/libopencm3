/** @defgroup gpio_defines General Purpose I/O Defines
 *
 * @brief <b>Defined Constants and Types for the K20DX General Purpose I/O</b>
 *
 * @ingroup K20DXxx_defines
 *
 * @version 1.0.0
 *
 * @author @htmlonly &copy; @endhtmlonly 2016 Gwenhael Goavec-Merou <gwenhael.goavec-merou@trabucayre.com>
 *
 * @date 07 May 2016
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

#ifndef K20DX_GPIO_H
#define K20DX_GPIO_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/k20dx/memorymap.h>

/* --- Convenience macros -------------------------------------------------- */

/****************************************************************************/
/** @defgroup gpio_reg_base GPIO register base addresses
@ingroup k20dx_gpio_defines

@{*/
/* GPIO port base addresses (for convenience) */
#define GPIOA			(GPIO_BASE + 0x000)
#define GPIOB			(GPIO_BASE + 0x040)
#define GPIOC			(GPIO_BASE + 0x080)
#define GPIOD			(GPIO_BASE + 0x0C0)
#define GPIOE			(GPIO_BASE + 0x100)
/**@}*/

/* GPIO number definitions (for convenience) */
#define GPIO0			(1 << 0)
#define GPIO1			(1 << 1)
#define GPIO2			(1 << 2)
#define GPIO3			(1 << 3)
#define GPIO4			(1 << 4)
#define GPIO5			(1 << 5)
#define GPIO6			(1 << 6)
#define GPIO7			(1 << 7)
#define GPIO8			(1 << 8)
#define GPIO9			(1 << 9)
#define GPIO10			(1 << 10)
#define GPIO11			(1 << 11)
#define GPIO12			(1 << 12)
#define GPIO13			(1 << 13)
#define GPIO14			(1 << 14)
#define GPIO15			(1 << 15)
#define GPIO16			(1 << 16)
#define GPIO17			(1 << 17)
#define GPIO18			(1 << 18)
#define GPIO19			(1 << 19)
#define GPIO20			(1 << 20)
#define GPIO21			(1 << 21)
#define GPIO22			(1 << 22)
#define GPIO23			(1 << 23)
#define GPIO24			(1 << 24)
#define GPIO25			(1 << 25)
#define GPIO26			(1 << 26)
#define GPIO27			(1 << 27)
#define GPIO28			(1 << 28)
#define GPIO29			(1 << 29)
#define GPIO30			(1 << 30)
#define GPIO31			(1 << 31)

/* --- GPIO registers ------------------------------------------------------ */

/* Port Data Output Register (GPIOn_PDOR) */
#define GPIO_PDOR(port)			MMIO32((port) + 0x000)
#define GPIOA_PDOR			GPIO_PDOR(GPIOA)
#define GPIOB_PDOR			GPIO_PDOR(GPIOB)
#define GPIOC_PDOR			GPIO_PDOR(GPIOC)
#define GPIOD_PDOR			GPIO_PDOR(GPIOD)
#define GPIOE_PDOR			GPIO_PDOR(GPIOE)

/* Port Set Output Register (GPIOn_PSOR) */
#define GPIO_PSOR(port)			MMIO32((port) + 0x004)
#define GPIOA_PSOR			GPIO_PSOR(GPIOA)
#define GPIOB_PSOR			GPIO_PSOR(GPIOB)
#define GPIOC_PSOR			GPIO_PSOR(GPIOC)
#define GPIOD_PSOR			GPIO_PSOR(GPIOD)
#define GPIOE_PSOR			GPIO_PSOR(GPIOE)

/* Port Clear Output Register (GPIOn_PCOR) */
#define GPIO_PCOR(port)			MMIO32((port) + 0x008)
#define GPIOA_PCOR			GPIO_PCOR(GPIOA)
#define GPIOB_PCOR			GPIO_PCOR(GPIOB)
#define GPIOC_PCOR			GPIO_PCOR(GPIOC)
#define GPIOD_PCOR			GPIO_PCOR(GPIOD)
#define GPIOE_PCOR			GPIO_PCOR(GPIOE)

/* Port Toggle Output Register (GPIOn_PTOR) */
#define GPIO_PTOR(port)			MMIO32((port) + 0x00C)
#define GPIOA_PTOR			GPIO_PTOR(GPIOA)
#define GPIOB_PTOR			GPIO_PTOR(GPIOB)
#define GPIOC_PTOR			GPIO_PTOR(GPIOC)
#define GPIOD_PTOR			GPIO_PTOR(GPIOD)
#define GPIOE_PTOR			GPIO_PTOR(GPIOE)

/* Port Data Input Register (GPIOn_PDIR) */
#define GPIO_PDIR(port)			MMIO32((port) + 0x010)
#define GPIOA_PDIR			GPIO_PDIR(GPIOA)
#define GPIOB_PDIR			GPIO_PDIR(GPIOB)
#define GPIOC_PDIR			GPIO_PDIR(GPIOC)
#define GPIOD_PDIR			GPIO_PDIR(GPIOD)
#define GPIOE_PDIR			GPIO_PDIR(GPIOE)

/* Port Data Direction Register (GPIOn_PDDR) */
#define GPIO_PDDR(port)			MMIO32((port) + 0x014)
#define GPIOA_PDDR			GPIO_PDDR(GPIOA)
#define GPIOB_PDDR			GPIO_PDDR(GPIOB)
#define GPIOC_PDDR			GPIO_PDDR(GPIOC)
#define GPIOD_PDDR			GPIO_PDDR(GPIOD)
#define GPIOE_PDDR			GPIO_PDDR(GPIOE)

BEGIN_DECLS

bool gpio_get(uint32_t gpioport, uint32_t gpio);
void gpio_set(uint32_t gpioport, uint32_t gpios);
void gpio_clear(uint32_t gpioport, uint32_t gpios);
void gpio_toggle(uint32_t gpioport, uint32_t gpios);
uint32_t gpio_port_read(uint32_t gpioport);
void gpio_port_write(uint32_t gpioport, uint32_t data);

END_DECLS

/**@}*/

#endif
