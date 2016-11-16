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

///START: DRAMSPEC_CLOCK_UNIT

#include "NewSystem.h"

namespace boost {

namespace units {

namespace dramspec {

typedef unit<clock_dimension,dramspec::system>    clock_unit;

BOOST_UNITS_STATIC_CONSTANT(clock,clock_unit);
BOOST_UNITS_STATIC_CONSTANT(clocks,clock_unit);

} // namespace dramspecs

} // namespace units

} // namespace boost

///END: DRAMSPEC_CLOCK_UNIT





///START: DRAMSPEC_CLOCK_PERIOD_UNIT

#include "NewSystem.h"
#include "NewDerivedDimensions.h"
#include <boost/units/systems/si.hpp>
#include <boost/units/systems/si/io.hpp>
#include <boost/units/systems/si/prefixes.hpp>

namespace boost {

namespace units {

namespace dramspec {

typedef unit<clock_period_dimension,dramspec::system>    clock_period_unit;

BOOST_UNITS_STATIC_CONSTANT(second_per_clock,clock_period_unit);
BOOST_UNITS_STATIC_CONSTANT(seconds_per_clock,clock_period_unit);

typedef make_scaled_unit<clock_period_unit,scale<10, static_rational<-6>>>::type microsecond_per_clock;
typedef make_scaled_unit<clock_period_unit,scale<10, static_rational<-9>>>::type nanosecond_per_clock;

} // namespace dramspecs

} // namespace units

} // namespace boost

///END: DRAMSPEC_CLOCK_PERIOD_UNIT





///START: DRAMSPEC_CLOCK_FREQUENCY_UNIT

#include "NewSystem.h"
#include "NewDerivedDimensions.h"
#include <boost/units/systems/si.hpp>
#include <boost/units/systems/si/io.hpp>
#include <boost/units/systems/si/prefixes.hpp>

namespace boost {

namespace units {

namespace dramspec {

typedef unit<clock_frequency_dimension,dramspec::system>    clock_frequency_unit;

BOOST_UNITS_STATIC_CONSTANT(clock_per_second,clock_period_unit);
BOOST_UNITS_STATIC_CONSTANT(clocks_per_second,clock_period_unit);
BOOST_UNITS_STATIC_CONSTANT(clock_hertz,clock_period_unit);

typedef make_scaled_unit<clock_frequency_unit,scale<10, static_rational<6>>>::type clock_megahertz;
typedef make_scaled_unit<clock_frequency_unit,scale<10, static_rational<9>>>::type clock_gigahertz;

} // namespace dramspecs

} // namespace units

} // namespace boost

///END: DRAMSPEC_CLOCK_FREQUENCY_UNIT





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

typedef unit<subarray_row_dimension,dramspec::system>    subarray_row_unit;

BOOST_UNITS_STATIC_CONSTANT(sa_row,subarray_row_unit);
BOOST_UNITS_STATIC_CONSTANT(sa_rows,subarray_row_unit);

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




///START: DRAMSPEC_TILE_PER_BANK_BASE_UNIT_H

#include "NewSystem.h"

namespace boost {

namespace units {

namespace dramspec {

typedef unit<tile_per_bank_dimension,dramspec::system>    tile_per_bank_unit;

BOOST_UNITS_STATIC_CONSTANT(tile_per_bank,tile_per_bank_unit);
BOOST_UNITS_STATIC_CONSTANT(tiles_per_bank,tile_per_bank_unit);

} // namespace dramspecs

} // namespace units

} // namespace boost

///END: DRAMSPEC_TILE_BASE_UNIT_H




///START: DRAMSPEC_CAPACITANCE_PER_CELL_UNIT

#include "NewSystem.h"
#include "NewDerivedDimensions.h"
#include <boost/units/systems/si.hpp>
#include <boost/units/systems/si/io.hpp>
#include <boost/units/systems/si/prefixes.hpp>

namespace boost {

namespace units {

namespace dramspec {

typedef unit<capacitance_per_cell_dimension,dramspec::system>    capacitance_per_cell;

BOOST_UNITS_STATIC_CONSTANT(farad_per_cell,capacitance_per_cell);
BOOST_UNITS_STATIC_CONSTANT(farads_per_cell,capacitance_per_cell);

typedef make_scaled_unit<capacitance_per_cell,scale<10, static_rational<-9>>>::type nanofarad_per_cell;
typedef make_scaled_unit<capacitance_per_cell,scale<10, static_rational<-12>>>::type picofarad_per_cell;
typedef make_scaled_unit<capacitance_per_cell,scale<10, static_rational<-15>>>::type femtofarad_per_cell;
typedef make_scaled_unit<capacitance_per_cell,scale<10, static_rational<-18>>>::type attofarad_per_cell;

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




///START: DRAMSPEC_LENGTH_PER_CELL_UNIT

#include "NewSystem.h"
#include "NewDerivedDimensions.h"
#include <boost/units/systems/si.hpp>
#include <boost/units/systems/si/io.hpp>
#include <boost/units/systems/si/prefixes.hpp>

namespace boost {

namespace units {

namespace dramspec {

typedef unit<length_per_cell_dimension,dramspec::system>    length_per_cell;

BOOST_UNITS_STATIC_CONSTANT(meter_per_cell,length_per_cell);
BOOST_UNITS_STATIC_CONSTANT(meters_per_cell,length_per_cell);

typedef make_scaled_unit<length_per_cell,scale<10, static_rational<-6>>>::type micrometer_per_cell;

} // namespace dramspecs

} // namespace units

} // namespace boost

///END: DRAMSPEC_LENGTH_PER_CELL_UNIT




///START: DRAMSPEC_CELL_PER_SUBARRAY_ROW_UNIT

#include "NewSystem.h"
#include "NewDerivedDimensions.h"

namespace boost {

namespace units {

namespace dramspec {

typedef unit<cell_per_subarray_row_dimension,dramspec::system>    cell_per_subarray_row_unit;

BOOST_UNITS_STATIC_CONSTANT(cell_per_sa_row,cell_per_subarray_row_unit);
BOOST_UNITS_STATIC_CONSTANT(cells_per_sa_row,cell_per_subarray_row_unit);

} // namespace dramspecs

} // namespace units

} // namespace boost

///END: DRAMSPEC_CELL_PER_SUBARRAY_ROW_UNIT




///START: DRAMSPEC_CELL_PER_SUBARRAY_COLUMN_UNIT

#include "NewSystem.h"
#include "NewDerivedDimensions.h"

namespace boost {

namespace units {

namespace dramspec {

typedef unit<cell_per_subarray_column_dimension,dramspec::system>    cell_per_subarray_column_unit;

BOOST_UNITS_STATIC_CONSTANT(cell_per_sa_col,cell_per_subarray_column_unit);
BOOST_UNITS_STATIC_CONSTANT(cells_per_sa_col,cell_per_subarray_column_unit);

} // namespace dramspecs

} // namespace units

} // namespace boost

///END: DRAMSPEC_CELL_PER_SUBARRAY_COLUMN_UNIT



///START: DRAMSPEC_CAPACITANCE_PER_LENGHT_UNIT

#include "NewSystem.h"
#include "NewDerivedDimensions.h"

namespace boost {

namespace units {

namespace dramspec {

typedef unit<capacitance_per_length_dimension,dramspec::system>    capacitance_per_length;

BOOST_UNITS_STATIC_CONSTANT(farad_per_meter,capacitance_per_length);
BOOST_UNITS_STATIC_CONSTANT(farads_per_meter,capacitance_per_length);

// femtofarad / millimeter = picofarad / meter
typedef make_scaled_unit<capacitance_per_length,scale<10, static_rational<-12>>>::type femtofarad_per_millimeter;

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

// ohm / millimeter = kiloohm / meter
typedef make_scaled_unit<resistance_per_length,scale<10, static_rational<3>>>::type ohm_per_millimeter;

} // namespace dramspecs

} // namespace units

} // namespace boost

///END: DRAMSPEC_RESISTANCE_PER_LENGTH_UNIT




///START: DRAMSPEC_CURRENT_PER_FREQUENCY_UNIT

#include "NewSystem.h"
#include "NewDerivedDimensions.h"

namespace boost {

namespace units {

namespace dramspec {

typedef unit<current_per_frequency_dimension,dramspec::system>    current_per_frequency;

BOOST_UNITS_STATIC_CONSTANT(ampere_per_hertz,current_per_frequency);
BOOST_UNITS_STATIC_CONSTANT(amperes_per_hertz,current_per_frequency);

// milliampere / megahertz = nanoampere / hertz
typedef make_scaled_unit<current_per_frequency,scale<10, static_rational<-9>>>::type milliampere_per_megahertz;

} // namespace dramspecs

} // namespace units

} // namespace boost

///END: DRAMSPEC_CURRENT_PER_FREQUENCY_UNIT




///START: DRAMSPEC_SCALED_SI_UNIT

#include "NewSystem.h"
#include "NewDerivedDimensions.h"
#include <boost/units/systems/si.hpp>
#include <boost/units/systems/si/io.hpp>
#include <boost/units/systems/si/prefixes.hpp>
#include <boost/units/cmath.hpp>

namespace boost {

namespace units {

namespace dramspec {

typedef make_scaled_unit<si::length,scale<10, static_rational<-6>>>::type micrometer;
typedef make_scaled_unit<si::length,scale<10, static_rational<-9>>>::type nanometer;

typedef make_scaled_unit<si::current,scale<10, static_rational<-6>>>::type microampere;

typedef make_scaled_unit<si::frequency,scale<10, static_rational<6>>>::type megahertz;
typedef make_scaled_unit<si::frequency,scale<10, static_rational<9>>>::type gigahertz;

typedef make_scaled_unit<si::time,scale<10, static_rational<-3>>>::type millisecond;
typedef make_scaled_unit<si::time,scale<10, static_rational<-6>>>::type microsecond;
typedef make_scaled_unit<si::time,scale<10, static_rational<-9>>>::type nanosecond;


} // namespace dramspecs

} // namespace units

} // namespace boost

///END: DRAMSPEC_SCALED_SI_UNIT




///START: DRAMSPEC_SCALED_INFORMATION_UNIT

#include "NewSystem.h"
#include "NewDerivedDimensions.h"
#include <boost/units/scale.hpp>
#include <boost/units/systems/information/prefixes.hpp>
#include <boost/units/systems/information/bit.hpp>
#include <boost/units/systems/information/byte.hpp>
#include <boost/units/systems/si/prefixes.hpp>
#include <boost/units/conversion.hpp>
#include <boost/units/io.hpp>

namespace boost {

namespace units {

namespace dramspec {

typedef make_scaled_unit<information::hu::bit::info,scale<2, static_rational<0>>>::type bit;
typedef make_scaled_unit<information::hu::bit::info,scale<2, static_rational<30>>>::type gibibit;

typedef make_scaled_unit<information::hu::byte::info,scale<2, static_rational<0>>>::type byte;
typedef make_scaled_unit<information::hu::byte::info,scale<2, static_rational<20>>>::type kibibyte;

} // namespace dramspecs

} // namespace units

} // namespace boost

///END: DRAMSPEC_SCALED_INFORMATION_UNIT


#endif // NEW_UNITS_H
