/** @defgroup mcg_defines System Integration Module Defines

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

#ifndef K20DX_MCG_H
#define K20DX_MCG_H

/**@{*/

#include <libopencm3/cm3/common.h>
#include <libopencm3/k20dx/memorymap.h>

/* --- MCG registers ------------------------------------------------------ */

#define MCG_C1 MMIO8(MCG_BASE + 0x0)
#define MCG_C2 MMIO8(MCG_BASE + 0x1)
#define MCG_C3 MMIO8(MCG_BASE + 0x2)
#define MCG_C4 MMIO8(MCG_BASE + 0x3)
#define MCG_C5 MMIO8(MCG_BASE + 0x4)
#define MCG_C6 MMIO8(MCG_BASE + 0x5)
#define MCG_S MMIO8(MCG_BASE + 0x6)
#define MCG_SC MMIO8(MCG_BASE + 0x8)
#define MCG_ATCVH MMIO8(MCG_BASE + 0xa)
#define MCG_ATCVL MMIO8(MCG_BASE + 0xb)
#define MCG_C7 MMIO8(MCG_BASE + 0xc)
#define MCG_C8 MMIO8(MCG_BASE + 0xd)


/* --- registers values ---------------------------------------------------- */

/* MCG_C1: Control Register 1 */
#define MCG_C1_CLKS(_clk)			((_clk) << 6)
#define MCG_C1_CLKS_FLL_PLL			(0x0)
#define MCG_C1_CLKS_INTERNAL		(0x1)
#define MCG_C1_CLKS_EXTERNAL		(0x2)
#define MCG_C1_CLKS_MASK			(0x3)
#define MCG_C1_FRDIV(_div)			((_div) << 3)
#define MCG_C1_FRDIV_1_OR_32		(0x0)
#define MCG_C1_FRDIV_2_OR_64		(0x1)
#define MCG_C1_FRDIV_4_OR_128		(0x2)
#define MCG_C1_FRDIV_8_OR_256		(0x3)
#define MCG_C1_FRDIV_16_OR_512		(0x4)
#define MCG_C1_FRDIV_32_OR_1024		(0x5)
#define MCG_C1_FRDIV_64_OR_1280		(0x6)
#define MCG_C1_FRDIV_128_OR_1536	(0x7)
#define MCG_C1_FRDIV_MASK			(0x7)
#define MCG_C1_IREFS			(1 << 2)
#define MCG_C1_IRCLKEN			(1 << 1)
#define MCG_C1_IREFSTEN			(1 << 0)

/* MCG_C2: Control Register 2 */
#define MCG_C2_LOCRE0 				(1 << 7)
/* [6]: reserved */
#define MCG_C2_RANGE0(_range)		((_range) << 4)
#define MCG_C2_RANGE0_LF			(0x0)
#define MCG_C2_RANGE0_HF			(0x1)
#define MCG_C2_RANGE0_VHF			(0x2)
#define MCG_C2_RANGE0_MASK			(0x3)
#define MCG_C2_HGO0					(1 << 3)
#define MCG_C2_EREFS0				(1 << 2)
#define MCG_C2_LP					(1 << 1)
#define MCG_C2_IRCS					(1 << 0)


/* MCG_SCTRIM */

/* MCG_C4: Control Register 4 */
#define MCG_C4_DMX32				(1 << 7)
#define MCG_C4_DRST_DRS(_range)		((_range) << 5)
#define MCG_C4_DRST_DRS_LOW_RANGE	(0x0)
#define MCG_C4_DRST_DRS_MID_RANGE	(0x1)
#define MCG_C4_DRST_DRS_MID_HIGH_RANGE	(0x2)
#define MCG_C4_DRST_DRS_HIGH_RANGE	(0x3)
#define MCG_C4_DRST_DRS_MASK		(0x3)
#define MCG_C4_FCTRIM(_trim)		((_trim) << 1)
#define MCG_C4_SCFTRIM				(1 << 0)

/* MCG_C5: Control Register 5 */
/* [7]: reserved */
#define MCG_C5_PLLCLKEN0			(1 << 6)
#define MCG_C5_PLLSTEN0				(1 << 5)
#define MCG_C5_PRDIV0(_div)			((_div) << 0)
#define MCG_C5_PRDIV0_1				(0x00)
#define MCG_C5_PRDIV0_2				(0x01)
#define MCG_C5_PRDIV0_3				(0x02)
#define MCG_C5_PRDIV0_4				(0x03)
#define MCG_C5_PRDIV0_5				(0x04)
#define MCG_C5_PRDIV0_6				(0x05)
#define MCG_C5_PRDIV0_7				(0x06)
#define MCG_C5_PRDIV0_8				(0x07)
#define MCG_C5_PRDIV0_9				(0x08)
#define MCG_C5_PRDIV0_10			(0x09)
#define MCG_C5_PRDIV0_11			(0x0a)
#define MCG_C5_PRDIV0_12			(0x0b)
#define MCG_C5_PRDIV0_13			(0x0c)
#define MCG_C5_PRDIV0_14			(0x0d)
#define MCG_C5_PRDIV0_15			(0x0e)
#define MCG_C5_PRDIV0_16			(0x0f)
#define MCG_C5_PRDIV0_17			(0x10)
#define MCG_C5_PRDIV0_18			(0x11)
#define MCG_C5_PRDIV0_19			(0x12)
#define MCG_C5_PRDIV0_20			(0x13)
#define MCG_C5_PRDIV0_21			(0x14)
#define MCG_C5_PRDIV0_22			(0x15)
#define MCG_C5_PRDIV0_23			(0x16)
#define MCG_C5_PRDIV0_24			(0x17)
#define MCG_C5_PRDIV0_25			(0x18)
#define MCG_C5_PRDIV0_MASK			(0x1f)

/* MCG_C6: Control Register 6 */
#define MCG_C6_LOLIE0 				(1 << 7)
#define MCG_C6_PLLS					(1 << 6)
#define MCG_C6_CME0					(1 << 5)
#define MCG_C6_VDIV0(_mult)			((_mult) << 0)
#define MCG_C6_VDIV0_24				(0x00)
#define MCG_C6_VDIV0_25				(0x01)
#define MCG_C6_VDIV0_26				(0x02)
#define MCG_C6_VDIV0_27				(0x03)
#define MCG_C6_VDIV0_28				(0x04)
#define MCG_C6_VDIV0_29				(0x05)
#define MCG_C6_VDIV0_30				(0x06)
#define MCG_C6_VDIV0_31				(0x07)
#define MCG_C6_VDIV0_32				(0x08)
#define MCG_C6_VDIV0_33				(0x09)
#define MCG_C6_VDIV0_34				(0x0a)
#define MCG_C6_VDIV0_35				(0x0b)
#define MCG_C6_VDIV0_36				(0x0c)
#define MCG_C6_VDIV0_37				(0x0d)
#define MCG_C6_VDIV0_38				(0x0e)
#define MCG_C6_VDIV0_39				(0x0f)
#define MCG_C6_VDIV0_40				(0x10)
#define MCG_C6_VDIV0_41				(0x11)
#define MCG_C6_VDIV0_42				(0x12)
#define MCG_C6_VDIV0_43				(0x13)
#define MCG_C6_VDIV0_44				(0x14)
#define MCG_C6_VDIV0_45				(0x15)
#define MCG_C6_VDIV0_46				(0x16)
#define MCG_C6_VDIV0_47				(0x17)
#define MCG_C6_VDIV0_48				(0x18)
#define MCG_C6_VDIV0_49				(0x19)
#define MCG_C6_VDIV0_50				(0x1a)
#define MCG_C6_VDIV0_51				(0x1b)
#define MCG_C6_VDIV0_52				(0x1c)
#define MCG_C6_VDIV0_53				(0x1d)
#define MCG_C6_VDIV0_54				(0x1e)
#define MCG_C6_VDIV0_55				(0x1f)
#define MCG_C6_VDIV0_MASK			(0x1f)

/* MCG_S: Status Register */
#define MCG_S_LOLS0 				(1 << 7)
#define MCG_S_LOCK0					(1 << 6)
#define MCG_S_PLLST					(1 << 5)
#define MCG_S_IREFST				(1 << 4)
#define MCG_S_CLKST_SHIFT			2
#define MCG_S_CLKST_FLL				(0x0 << 2)
#define MCG_S_CLKST_INTERNAL		(0x1 << 2)
#define MCG_S_CLKST_EXTERNAL		(0x2 << 2)
#define MCG_S_CLKST_PLL				(0x3 << 2)
#define MCG_S_CLKST_MASK			(0x3 << 2)
#define MCG_S_OSCINIT0				(1 << 1)
#define MCG_S_IRCST					(1 << 0)

/* MCG_SC: Status And Control Register */
#define MCG_SC_ATME					(1 << 7)
#define MCG_SC_ATMS					(1 << 6)
#define MCG_SC_ATMF					(1 << 5)
#define MCG_SC_FLTPRSRV				(1 << 4)
#define MCG_SC_FCRDIV(_div)			((_div) << 1)
#define MCG_SC_FCRDIV_SHIFT			1
#define MCG_SC_FCRDIV_1 			0x0
#define MCG_SC_FCRDIV_2 			0x1
#define MCG_SC_FCRDIV_4 			0x2
#define MCG_SC_FCRDIV_8 			0x3
#define MCG_SC_FCRDIV_16			0x4
#define MCG_SC_FCRDIV_32			0x5
#define MCG_SC_FCRDIV_64			0x6
#define MCG_SC_FCRDIV_128			0x7
#define MCG_SC_FCRDIV_MASK			0x7
#define MCG_SC_LOCS0				(1 << 0)

/* MCG_ATCVH: Auto Trim Compare Value High Register */

/* MCG_ATCVL: Auto Trim Compare Value Low Register */

/* MCG_C7: Control Register 7 */
/* [7:1]: reserved */
#define MCG_C7_OSCSEL				(1 << 0)

/* MCG_C8: Control Register 8 */
/* [7:1]: reserved */
#define MCG_C8_LOCRE1				(1 << 7)
#define MCG_C8_LOLRE				(1 << 6)
#define MCG_C8_CME1					(1 << 5)
/* [4:1]: reserved */ 
#define MCG_C8_LOCS1				(1 << 0)

BEGIN_DECLS

void mcg_setup_16_in_PEE_72(void);

END_DECLS

/**@}*/

#endif

