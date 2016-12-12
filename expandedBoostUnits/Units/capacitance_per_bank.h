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

#ifndef DRAMSPEC_CAPACITANCE_PER_SQUARE_ROOT_BANK_UNIT_H
#define DRAMSPEC_CAPACITANCE_PER_SQUARE_ROOT_BANK_UNIT_H

#include <boost/units/make_scaled_unit.hpp>

#include "../dramSpecUnitsSystem.h"
#include "../DerivedDimensions/capacitance_per_bank.h"

namespace boost {

namespace units {

namespace dramspec {

typedef unit<capacitance_per_square_root_bank_dimension,dramspec::system> capacitance_per_square_root_bank_unit;

typedef make_scaled_unit<capacitance_per_square_root_bank_unit,
                         scale<1, static_rational<0>>>::type capacitance_per_wordline_bank_unit;
BOOST_UNITS_STATIC_CONSTANT(farad_per_wl_bank,capacitance_per_wordline_bank_unit);
BOOST_UNITS_STATIC_CONSTANT(farads_per_wl_bank,capacitance_per_wordline_bank_unit);

typedef make_scaled_unit<capacitance_per_wordline_bank_unit,scale<10, static_rational<-9>>>::type nanofarad_per_wordline_bank_unit;
BOOST_UNITS_STATIC_CONSTANT(nanofarad_per_wl_bank,nanofarad_per_wordline_bank_unit);
BOOST_UNITS_STATIC_CONSTANT(nanofarads_per_wl_bank,nanofarad_per_wordline_bank_unit);
typedef make_scaled_unit<capacitance_per_wordline_bank_unit,scale<10, static_rational<-12>>>::type picofarad_per_wordline_bank_unit;
BOOST_UNITS_STATIC_CONSTANT(picofarad_per_wl_bank,picofarad_per_wordline_bank_unit);
BOOST_UNITS_STATIC_CONSTANT(picofarads_per_wl_bank,picofarad_per_wordline_bank_unit);
typedef make_scaled_unit<capacitance_per_wordline_bank_unit,scale<10, static_rational<-15>>>::type femtofarad_per_wordline_bank_unit;
BOOST_UNITS_STATIC_CONSTANT(femtofarad_per_wl_bank,femtofarad_per_wordline_bank_unit);
BOOST_UNITS_STATIC_CONSTANT(femtofarads_per_wl_bank,femtofarad_per_wordline_bank_unit);
typedef make_scaled_unit<capacitance_per_wordline_bank_unit,scale<10, static_rational<-18>>>::type attofarad_per_wordline_bank_unit;
BOOST_UNITS_STATIC_CONSTANT(attofarad_per_wl_bank,attofarad_per_wordline_bank_unit);
BOOST_UNITS_STATIC_CONSTANT(attofarads_per_wl_bank,attofarad_per_wordline_bank_unit);


typedef make_scaled_unit<capacitance_per_square_root_bank_unit,
                         scale<1, static_rational<0>>>::type capacitance_per_bitline_bank_unit;
BOOST_UNITS_STATIC_CONSTANT(farad_per_bl_bank,capacitance_per_bitline_bank_unit);
BOOST_UNITS_STATIC_CONSTANT(farads_per_bl_banks,capacitance_per_bitline_bank_unit);

typedef make_scaled_unit<capacitance_per_bitline_bank_unit,scale<10, static_rational<-9>>>::type nanofarad_per_bitline_bank_unit;
BOOST_UNITS_STATIC_CONSTANT(nanofarad_per_bl_bank,nanofarad_per_bitline_bank_unit);
BOOST_UNITS_STATIC_CONSTANT(nanofarads_per_bl_bank,nanofarad_per_bitline_bank_unit);
typedef make_scaled_unit<capacitance_per_bitline_bank_unit,scale<10, static_rational<-12>>>::type picofarad_per_bitline_bank_unit;
BOOST_UNITS_STATIC_CONSTANT(picofarad_per_bl_bank,picofarad_per_bitline_bank_unit);
BOOST_UNITS_STATIC_CONSTANT(picofarads_per_bl_bank,picofarad_per_bitline_bank_unit);
typedef make_scaled_unit<capacitance_per_bitline_bank_unit,scale<10, static_rational<-15>>>::type femtofarad_per_bitline_bank_unit;
BOOST_UNITS_STATIC_CONSTANT(femtofarad_per_bl_bank,femtofarad_per_bitline_bank_unit);
BOOST_UNITS_STATIC_CONSTANT(femtofarads_per_bl_bank,femtofarad_per_bitline_bank_unit);
typedef make_scaled_unit<capacitance_per_bitline_bank_unit,scale<10, static_rational<-18>>>::type attofarad_per_bitline_bank_unit;
BOOST_UNITS_STATIC_CONSTANT(attofarad_per_bl_bank,attofarad_per_bitline_bank_unit);
BOOST_UNITS_STATIC_CONSTANT(attofarads_per_bl_bank,attofarad_per_bitline_bank_unit);


} // namespace dramspec

inline std::string name_string(const reduce_unit<dramspec::capacitance_per_square_root_bank_unit>::type&)   { return "farad/sqrt_bank"; }
inline std::string symbol_string(const reduce_unit<dramspec::capacitance_per_square_root_bank_unit>::type&) { return "farad/sqrt_bank"; }

} // namespace units

} // namespace boost

#endif // DRAMSPEC_CAPACITANCE_PER_SQUARE_ROOT_BANK_UNIT_H
