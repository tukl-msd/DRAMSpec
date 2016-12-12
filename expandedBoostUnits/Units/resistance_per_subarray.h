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

#ifndef DRAMSPEC_RESISTANCE_PER_SQUARE_ROOT_SUBARRAY_UNIT_H
#define DRAMSPEC_RESISTANCE_PER_SQUARE_ROOT_SUBARRAY_UNIT_H

#include <boost/units/make_scaled_unit.hpp>

#include "../dramSpecUnitsSystem.h"
#include "../DerivedDimensions/resistance_per_subarray.h"

namespace boost {

namespace units {

namespace dramspec {

typedef unit<resistance_per_square_root_subarray_dimension,dramspec::system> resistance_per_square_root_subarray_unit;

typedef make_scaled_unit<resistance_per_square_root_subarray_unit,
                         scale<1, static_rational<0>>>::type resistance_per_wordline_subarray_unit;
BOOST_UNITS_STATIC_CONSTANT(ohm_per_wl_subarray,resistance_per_wordline_subarray_unit);
BOOST_UNITS_STATIC_CONSTANT(ohms_per_wl_subarray,resistance_per_wordline_subarray_unit);

typedef make_scaled_unit<resistance_per_square_root_subarray_unit,
                         scale<1, static_rational<0>>>::type resistance_per_bitline_subarray_unit;
BOOST_UNITS_STATIC_CONSTANT(ohm_per_bl_subarray,resistance_per_bitline_subarray_unit);
BOOST_UNITS_STATIC_CONSTANT(ohms_per_bl_subarray,resistance_per_bitline_subarray_unit);

} // namespace dramspec

inline std::string name_string(const reduce_unit<dramspec::resistance_per_square_root_subarray_unit>::type&)   { return "ohm/sqrt_subarray"; }
inline std::string symbol_string(const reduce_unit<dramspec::resistance_per_square_root_subarray_unit>::type&) { return "ohm/sqrt_subarray"; }

} // namespace units

} // namespace boost


#endif // DRAMSPEC_RESISTANCE_PER_SQUARE_ROOT_SUBARRAY_UNIT_H