/*
 * Copyright (c) 2017, University of Kaiserslautern
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
 * Authors: Omar Naji,
 *          Matthias Jung,
 *          Christian Weis,
 *          Kamal Haddad,
 *          Andre Lucas Chinazzo
 */



#ifndef DRAMSPEC_UNITS_SYSTEM_H
#define DRAMSPEC_UNITS_SYSTEM_H

#include <boost/units/static_constant.hpp>
#include <boost/units/unit.hpp>
#include "expanded_make_system.hpp"

#include <boost/units/base_units/si/meter.hpp>
#include <boost/units/base_units/si/kilogram.hpp>
#include <boost/units/base_units/si/second.hpp>
#include <boost/units/base_units/si/ampere.hpp>
#include <boost/units/base_units/temperature/celsius.hpp>
#include <boost/units/base_units/information/bit.hpp>
#include <boost/units/base_units/information/byte.hpp>

#include "BaseUnits/clock.h"
//#include "BaseUnits/cell.h"
//#include "BaseUnits/subarray.h"
//#include "BaseUnits/tile.h"
//#include "BaseUnits/bank.h"
//#include "BaseUnits/page.h"

// Conversion between SCALED UNITS
// 'from' is a quantity,
// while 'to' is a unit dimension
#define SCALE_QUANTITY(from, to) \
    (static_cast<bu::quantity< to >> (from))

// Macro to round up quantities at a given decimal place
#define ROUND_UP(number, nDecimalPlaces) \
    ( ceil( pow(10, nDecimalPlaces) * number) / pow(10,nDecimalPlaces) )

namespace boost {

namespace units {

namespace dramspec {

/// placeholder class defining dramspec unit system
///  with information base unit being bit
typedef make_system<clock_base_unit,
                    boost::units::si::meter_base_unit,
                    boost::units::si::kilogram_base_unit,
                    boost::units::si::second_base_unit,
                    boost::units::si::ampere_base_unit,
                    boost::units::temperature::celsius_base_unit,
                    boost::units::information::bit_base_unit>::type system_bit;

/// placeholder class defining dramspec unit system
///  with information base unit being Byte
typedef make_system<clock_base_unit,
                    boost::units::si::meter_base_unit,
                    boost::units::si::kilogram_base_unit,
                    boost::units::si::second_base_unit,
                    boost::units::si::ampere_base_unit,
                    boost::units::temperature::celsius_base_unit,
                    boost::units::information::byte_base_unit>::type system_byte;

} // namespace dramspec

} // namespace units

} // namespace boost

#endif // DRAMSPEC_UNITS_SYSTEM_H
