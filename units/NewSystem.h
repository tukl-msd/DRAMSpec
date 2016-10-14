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

#ifndef NEW_SYSTEM_H
#define NEW_SYSTEM_H

///START: DRAMSPEC_SYSTEM_H

#include <string>

#include <boost/units/static_constant.hpp>
#include <boost/units/unit.hpp>
#include <boost/units/make_system.hpp>

#include <boost/units/base_units/si/meter.hpp>
#include <boost/units/base_units/si/kilogram.hpp>
#include <boost/units/base_units/si/second.hpp>
#include <boost/units/base_units/si/ampere.hpp>
//#include <boost/units/base_units/si/kelvin.hpp>
//#include <boost/units/base_units/si/mole.hpp>
//#include <boost/units/base_units/si/candela.hpp>
//#include <boost/units/base_units/angle/radian.hpp>
//#include <boost/units/base_units/angle/steradian.hpp>

#include "NewBaseUnits.h"


namespace boost {

namespace units {

namespace dramspec {

/// placeholder class defining dramspec unit system
typedef make_system<cell_base_unit,
                    row_base_unit,
                    column_base_unit,
                    vaultsperlayer_base_unit,
                    bank_base_unit,
                    tile_base_unit,
                    boost::units::si::meter_base_unit,
                    boost::units::si::kilogram_base_unit,
                    boost::units::si::second_base_unit,
                    boost::units::si::ampere_base_unit>::type system;

} // namespace dramspec

} // namespace units

} // namespace boost

///END: DRAMSPEC_SYSTEM_H

#endif // NEW_SYSTEM_H
