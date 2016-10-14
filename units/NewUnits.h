/*
 * Copyright (c) 2015, University of Kaiserslautern
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors: Omar Naji, Matthias Jung, Christian Weis, Kamal Haddad, Andr'e Lucas Chinazzo
 */

#ifndef NEW_UNITS_H
#define NEW_UNITS_H

///START: DRAMSPEC_CELL_UNIT

#include "NewSystem.h"

namespace boost {

namespace units {

namespace dramspec {

typedef unit<cell_dimension,dramspec::system>    cell_unit;

BOOST_UNITS_STATIC_CONSTANT(cell,cell_unit);
BOOST_UNITS_STATIC_CONSTANT(cells,cell_unit);

} // namespace dramspecs

} // namespace units

} // namespace boost

///END: DRAMSPEC_CELL_UNIT





///START: DRAMSPEC_ROW_BASE_UNIT_H

#include "NewSystem.h"

namespace boost {

namespace units {

namespace dramspec {

typedef unit<row_dimension,dramspec::system>    row_unit;

BOOST_UNITS_STATIC_CONSTANT(row,row_unit);
BOOST_UNITS_STATIC_CONSTANT(rows,row_unit);

} // namespace dramspecs

} // namespace units

} // namespace boost

///END: DRAMSPEC_ROW_BASE_UNIT_H




///START: DRAMSPEC_COLUMN_BASE_UNIT_H

#include "NewSystem.h"

namespace boost {

namespace units {

namespace dramspec {

typedef unit<column_dimension,dramspec::system>    column_unit;

BOOST_UNITS_STATIC_CONSTANT(column,column_unit);
BOOST_UNITS_STATIC_CONSTANT(columns,column_unit);

} // namespace dramspecs

} // namespace units

} // namespace boost

///END: DRAMSPEC_COLUMN_BASE_UNIT_H




///START: DRAMSPEC_VAULTPERLAYER_BASE_UNIT_H

#include "NewSystem.h"

namespace boost {

namespace units {

namespace dramspec {

typedef unit<vaultsperlayer_dimension,dramspec::system>    vaultsperlayer_unit;

BOOST_UNITS_STATIC_CONSTANT(vaultsperlayer,vaultsperlayer_unit);
BOOST_UNITS_STATIC_CONSTANT(vaultsperlayers,vaultsperlayer_unit);

} // namespace dramspecs

} // namespace units

} // namespace boost

///END: DRAMSPEC_VAULTPERLAYER_BASE_UNIT_H




///START: DRAMSPEC_BANK_BASE_UNIT_H

#include "NewSystem.h"

namespace boost {

namespace units {

namespace dramspec {

typedef unit<bank_dimension,dramspec::system>    bank_unit;

BOOST_UNITS_STATIC_CONSTANT(bank,bank_unit);
BOOST_UNITS_STATIC_CONSTANT(banks,bank_unit);

} // namespace dramspecs

} // namespace units

} // namespace boost

///END: DRAMSPEC_BANK_BASE_UNIT_H




///START: DRAMSPEC_TILE_BASE_UNIT_H

#include "NewSystem.h"

namespace boost {

namespace units {

namespace dramspec {

typedef unit<tile_dimension,dramspec::system>    tile_unit;

BOOST_UNITS_STATIC_CONSTANT(tile,tile_unit);
BOOST_UNITS_STATIC_CONSTANT(tiles,tile_unit);

} // namespace dramspecs

} // namespace units

} // namespace boost

///END: DRAMSPEC_TILE_BASE_UNIT_H




///START: DRAMSPEC_CAPACITANCE_PER_CELL_UNIT

#include "NewSystem.h"
#include "NewDerivedDimensions.h"

namespace boost {

namespace units {

namespace dramspec {

typedef unit<capacitance_per_cell_dimension,dramspec::system>    capacitance_per_cell;

BOOST_UNITS_STATIC_CONSTANT(farad_per_cell,capacitance_per_cell);
BOOST_UNITS_STATIC_CONSTANT(farads_per_cell,capacitance_per_cell);

} // namespace dramspecs

} // namespace units

} // namespace boost

///END: DRAMSPEC_CAPACITANCE_PER_CELL_UNIT




///START: DRAMSPEC_RESISTANCE_PER_CELL_UNIT

#include "NewSystem.h"
#include "NewDerivedDimensions.h"

namespace boost {

namespace units {

namespace dramspec {

typedef unit<resistance_per_cell_dimension,dramspec::system>    resistance_per_cell;

BOOST_UNITS_STATIC_CONSTANT(ohm_per_cell,resistance_per_cell);
BOOST_UNITS_STATIC_CONSTANT(ohms_per_cell,resistance_per_cell);

} // namespace dramspecs

} // namespace units

} // namespace boost

///END: DRAMSPEC_RESISTANCE_PER_CELL_UNIT




///START: DRAMSPEC_CAPACITANCE_PER_LENGHT_UNIT

#include "NewSystem.h"
#include "NewDerivedDimensions.h"

namespace boost {

namespace units {

namespace dramspec {

typedef unit<capacitance_per_length_dimension,dramspec::system>    capacitance_per_length;

BOOST_UNITS_STATIC_CONSTANT(farad_per_meter,capacitance_per_length);
BOOST_UNITS_STATIC_CONSTANT(farads_per_meter,capacitance_per_length);

} // namespace dramspecs

} // namespace units

} // namespace boost

///END: DRAMSPEC_CAPACITANCE_PER_LENGHT_UNIT




///START: DRAMSPEC_RESISTANCE_PER_LENGTH_UNIT

#include "NewSystem.h"
#include "NewDerivedDimensions.h"

namespace boost {

namespace units {

namespace dramspec {

typedef unit<resistance_per_length_dimension,dramspec::system>    resistance_per_length;

BOOST_UNITS_STATIC_CONSTANT(ohm_per_meter,resistance_per_length);
BOOST_UNITS_STATIC_CONSTANT(ohms_per_meter,resistance_per_length);

} // namespace dramspecs

} // namespace units

} // namespace boost

///END: DRAMSPEC_RESISTANCE_PER_LENGTH_UNIT

#endif // NEW_UNITS_H
