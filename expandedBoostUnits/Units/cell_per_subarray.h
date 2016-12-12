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

#ifndef DRAMSPEC_SQUARE_ROOT_CELL_PER_SQUARE_ROOT_SUBARRAY_UNIT_H
#define DRAMSPEC_SQUARE_ROOT_CELL_PER_SQUARE_ROOT_SUBARRAY_UNIT_H

#include "../dramSpecUnitsSystem.h"
#include "../DerivedDimensions/cell_per_subarray.h"

namespace boost {

namespace units {

namespace dramspec {

typedef unit<square_root_cell_per_square_root_subarray_dimension,dramspec::system> square_root_cell_per_square_root_subarray_unit;

typedef make_scaled_unit<square_root_cell_per_square_root_subarray_unit,
                         scale<1, static_rational<0>>>::type wordline_cell_per_wordline_subarray_unit;
BOOST_UNITS_STATIC_CONSTANT(wl_cell_per_wl_subarray,wordline_cell_per_wordline_subarray_unit);
BOOST_UNITS_STATIC_CONSTANT(wl_cells_per_wl_subarray,wordline_cell_per_wordline_subarray_unit);

typedef make_scaled_unit<square_root_cell_per_square_root_subarray_unit,
                         scale<1, static_rational<0>>>::type bitline_cell_per_bitline_subarray_unit;
BOOST_UNITS_STATIC_CONSTANT(bl_cell_per_bl_subarray,bitline_cell_per_bitline_subarray_unit);
BOOST_UNITS_STATIC_CONSTANT(bl_cells_per_bl_subarray,bitline_cell_per_bitline_subarray_unit);

} // namespace dramspec

inline std::string name_string(const reduce_unit<dramspec::square_root_cell_per_square_root_subarray_unit>::type&)   { return "sqrt_cell/sqrt_subarray"; }
inline std::string symbol_string(const reduce_unit<dramspec::square_root_cell_per_square_root_subarray_unit>::type&) { return "sqrt_cell/sqrt_subarray"; }
} // namespace units

} // namespace boost

#endif // DRAMSPEC_SQUARE_ROOT_CELL_PER_SQUARE_ROOT_SUBARRAY_UNIT_H
