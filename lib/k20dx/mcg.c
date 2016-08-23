/** @defgroup mcg_file System Integration Module

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

#include <libopencm3/k20dx/mcg.h>
#include <libopencm3/k20dx/sim.h>

void mcg_setup_16_in_PEE_72(void)
{
	uint32_t in_freq = 16000000;
	uint16_t range;

	if (in_freq <= 40000)
		range = MCG_C2_RANGE0_LF;
	else if (in_freq <= 8000000)
		range = MCG_C2_RANGE0_HF;
	else
		range = MCG_C2_RANGE0_VHF;
	/* FEI to FBE */
	/* 		enable external clk, frequency and gain in C2 */
	MCG_C2 &= ~(MCG_C2_RANGE0(MCG_C2_RANGE0_MASK) | MCG_C2_EREFS0 | MCG_C2_HGO0);
	MCG_C2 |= MCG_C2_RANGE0(range) | /*MCG_C2_HGO0 |*/ MCG_C2_EREFS0;
	/*		select clk mode in C1 => clear IREFS clks => 0x2
	 *			set FRDIV 16MHz to 31.25 to 39.0625
	 */
	MCG_C1 = (MCG_C1 & ~(MCG_C1_CLKS(MCG_C1_CLKS_MASK) |
		MCG_C1_FRDIV(MCG_C1_FRDIV_MASK) | MCG_C1_IREFS)) |
		MCG_C1_CLKS(MCG_C1_CLKS_EXTERNAL) |
		MCG_C1_FRDIV(MCG_C1_FRDIV_16_OR_512);
	/*		wait for affected bits :
	 *			C2[EREFS0] => S[OSCINIT0 bit to '1'
	 *			S[IREFST] = '0' and S[CLKST] = '10'
	 */
	// wait for eref initialized
	while (!(MCG_S & MCG_S_OSCINIT0));
	// wait for eref as ref clock
	while (MCG_S & MCG_S_IREFST);
	// wait for eref selected for MCGOUTCLK
	while ((MCG_S & MCG_S_CLKST_MASK) != MCG_S_CLKST_EXTERNAL);

	/* Now in FBE */
	MCG_C6 |= MCG_C6_CME0;
	/* PLL divisor */
	MCG_C5 = (MCG_C5 & ~MCG_C5_PRDIV0(MCG_C5_PRDIV0_MASK)) |
		MCG_C5_PRDIV0(MCG_C5_PRDIV0_8);

	/* enable PLL and set multiplier factor */
	MCG_C6 = (MCG_C6 & ~MCG_C6_VDIV0(MCG_C6_VDIV0_MASK)) |
		MCG_C6_VDIV0(MCG_C6_VDIV0_36) | MCG_C6_PLLS;

	/* wait for PLL as current source for PLLS */
	while (!(MCG_S & MCG_S_PLLST));
	/* wait for PLL lock */
	while (!(MCG_S & MCG_S_LOCK0));
	/* now in PBE */
	
	/* swith from PBE to PEE */
	MCG_C1 = (MCG_C1 & ~MCG_C1_CLKS(MCG_C1_CLKS_MASK)) |
		MCG_C1_CLKS(MCG_C1_CLKS_FLL_PLL);
	/* wait for PLL as source for MCGOUTCLK*/
	while ((MCG_S & MCG_S_CLKST_MASK) != MCG_S_CLKST_PLL);

	set_outdiv1_div(0);
	set_outdiv2_div(0);
	set_outdiv4_div(1);

}

/**@}*/

