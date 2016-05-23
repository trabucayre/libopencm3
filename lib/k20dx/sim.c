/** @defgroup sim_file System Integration Module

@brief <b>K20DX System Integration Module</b>

@ingroup K20DXxx

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

/**@{*/

#include <libopencm3/k20dx/sim.h>

void sim_clock_gate_enable(enum sim_clock_gate gr)
{
	uint32_t offset = (uint32_t) gr / 32;
	uint32_t gr_mask = 0x1 << (gr % 32);
	SIM_SCGC(offset) |= gr_mask;
}

void sim_clock_gate_disable(enum sim_clock_gate gr)
{
	uint32_t offset = (uint32_t) gr / 32;
	uint32_t gr_mask = 0x1 << (gr % 32);
	SIM_SCGC(offset) &= ~gr_mask;
}

/**@}*/

