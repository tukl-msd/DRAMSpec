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

#ifndef NEW_DERIVED_DIMENSIONS_H
#define NEW_DERIVED_DIMENSIONS_H

///START: DRAMSPEC_CLOCK_PERIOD_DERIVED_DIMENSION

#include <boost/units/derived_dimension.hpp>

#include <boost/units/physical_dimensions/time.hpp>
#include "NewBaseDimensions.h"

namespace boost {

namespace units {

/// derived dimension for time per clock: T^1 CLOCK^-1
typedef derived_dimension<time_base_dimension,1,
                          clock_base_dimension,-1>::type clock_period_dimension;

} // namespace units

} // namespace boost

///END: DRAMSPEC_CLOCK_PERIOD_DERIVED_DIMENSION




///START: DRAMSPEC_CLOCK_FREQUENCY_DERIVED_DIMENSION

#include <boost/units/derived_dimension.hpp>

#include <boost/units/physical_dimensions/time.hpp>
#include "NewBaseDimensions.h"

namespace boost {

namespace units {

/// derived dimension for clock per time: CLOCK^1 T^-1
typedef derived_dimension<time_base_dimension,-1,
                          clock_base_dimension,1>::type clock_frequency_dimension;

} // namespace units

} // namespace boost

///END: DRAMSPEC_CLOCK_FREQUENCY_DERIVED_DIMENSION




///START: DRAMSPEC_CAPACITANCE_PER_CELL_DERIVED_DIMENSION

#include <boost/units/derived_dimension.hpp>

#include <boost/units/physical_dimensions/length.hpp>
#include <boost/units/physical_dimensions/mass.hpp>
#include <boost/units/physical_dimensions/time.hpp>
#include <boost/units/physical_dimensions/current.hpp>
#include "NewBaseDimensions.h"

namespace boost {

namespace units {

/// derived dimension for capacitance per cell: L^-2 M^-1 T^4 I^2 CELL^-1
typedef derived_dimension<length_base_dimension,-2,
                          mass_base_dimension,-1,
                          time_base_dimension,4,
                          current_base_dimension,2,
                          cell_base_dimension,-1>::type capacitance_per_cell_dimension;

} // namespace units

} // namespace boost

///END: DRAMSPEC_CAPACITANCE_PER_CELL_DERIVED_DIMENSION




///START: DRAMSPEC_RESISTANCE_PER_CELL_DERIVED_DIMENSION

#include <boost/units/derived_dimension.hpp>

#include <boost/units/physical_dimensions/length.hpp>
#include <boost/units/physical_dimensions/mass.hpp>
#include <boost/units/physical_dimensions/time.hpp>
#include <boost/units/physical_dimensions/current.hpp>
#include "NewBaseDimensions.h"

namespace boost {

namespace units {

/// derived dimension for resistance per cell: L^2 M^1 T^-3 I^-2 CELL^-1
typedef derived_dimension<length_base_dimension,2,
                          mass_base_dimension,1,
                          time_base_dimension,-3,
                          current_base_dimension,-2,
                          cell_base_dimension,-1>::type resistance_per_cell_dimension;

} // namespace units

} // namespace boost

///END: DRAMSPEC_RESISTANCE_PER_CELL_DERIVED_DIMENSION




///START: DRAMSPEC_LENGTH_PER_CELL_DERIVED_DIMENSION

#include <boost/units/derived_dimension.hpp>

#include <boost/units/physical_dimensions/length.hpp>
#include "NewBaseDimensions.h"

namespace boost {

namespace units {

/// derived dimension for length per cell: L^1 CELL^-1
typedef derived_dimension<length_base_dimension,1,
                          cell_base_dimension,-1>::type length_per_cell_dimension;

} // namespace units

} // namespace boost

///END: DRAMSPEC_LENGTH_PER_CELL_DERIVED_DIMENSION




///START: DRAMSPEC_CELL_PER_SUBARRAY_ROW_DERIVED_DIMENSION

#include <boost/units/derived_dimension.hpp>

#include <boost/units/physical_dimensions/length.hpp>
#include "NewBaseDimensions.h"

namespace boost {

namespace units {

/// derived dimension for length per cell: CELL^1 SA_ROW^-1
typedef derived_dimension<cell_base_dimension,1,
                          subarray_row_base_dimension,-1>::type cell_per_subarray_row_dimension;

} // namespace units

} // namespace boost

///END: DRAMSPEC_CELL_PER_SUBARRAY_ROW_DERIVED_DIMENSION




///START: DRAMSPEC_CELL_PER_SUBARRAY_COLUMN_DERIVED_DIMENSION

#include <boost/units/derived_dimension.hpp>

#include <boost/units/physical_dimensions/length.hpp>
#include "NewBaseDimensions.h"

namespace boost {

namespace units {

/// derived dimension for length per cell: SA_ROW^-1 = SA_COL^1
typedef derived_dimension<subarray_row_base_dimension,-1>::type cell_per_subarray_column_dimension;

} // namespace units

} // namespace boost

///END: DRAMSPEC_CELL_PER_SUBARRAY_COLUMN_DERIVED_DIMENSION




///START: DRAMSPEC_CAPACITANCE_PER_LENGTH_DERIVED_DIMENSION

#include <boost/units/derived_dimension.hpp>

#include <boost/units/physical_dimensions/length.hpp>
#include <boost/units/physical_dimensions/mass.hpp>
#include <boost/units/physical_dimensions/time.hpp>
#include <boost/units/physical_dimensions/current.hpp>
#include "NewBaseDimensions.h"

namespace boost {

namespace units {

/// derived dimension for capacitance per length: L^-3 M^-1 T^4 I^2
typedef derived_dimension<length_base_dimension,-3,
                          mass_base_dimension,-1,
                          time_base_dimension,4,
                          current_base_dimension,2>::type capacitance_per_length_dimension;

} // namespace units

} // namespace boost

///END: DRAMSPEC_CAPACITANCE_PER_LENGTH_DERIVED_DIMENSION




///START: DRAMSPEC_RESISTANCE_PER_LENGTH_DERIVED_DIMENSION

#include <boost/units/derived_dimension.hpp>

#include <boost/units/physical_dimensions/length.hpp>
#include <boost/units/physical_dimensions/mass.hpp>
#include <boost/units/physical_dimensions/time.hpp>
#include <boost/units/physical_dimensions/current.hpp>
#include "NewBaseDimensions.h"

namespace boost {

namespace units {

/// derived dimension for resistance per length: L^1 M^1 T^-3 I^-2
typedef derived_dimension<length_base_dimension,1,
                          mass_base_dimension,1,
                          time_base_dimension,-3,
                          current_base_dimension,-2>::type resistance_per_length_dimension;

} // namespace units

} // namespace boost

///END: DRAMSPEC_RESISTANCE_PER_LENGTH_DERIVED_DIMENSION




///START: DRAMSPEC_TILE_PER_BANK_DERIVED_DIMENSION

#include <boost/units/derived_dimension.hpp>

#include "NewBaseDimensions.h"

namespace boost {

namespace units {

/// derived dimension for tiles per bank: TILE^1 BANK^-1
typedef derived_dimension<tile_base_dimension,1,
                          bank_base_dimension,-1>::type tile_per_bank_dimension;

} // namespace units

} // namespace boost

///END: DRAMSPEC_TILE_PER_BANK_DERIVED_DIMENSION




///START: DRAMSPEC_CURRENT_PER_FREQUENCY_DERIVED_DIMENSION

#include <boost/units/derived_dimension.hpp>

#include <boost/units/physical_dimensions/time.hpp>
#include <boost/units/physical_dimensions/current.hpp>
#include "NewBaseDimensions.h"

namespace boost {

namespace units {

/// derived dimension for resistance per length: I^1 T^1
typedef derived_dimension<current_base_dimension,1,
                          time_base_dimension,1>::type current_per_frequency_dimension;

} // namespace units

} // namespace boost

///END: DRAMSPEC_CURRENT_PER_FREQUENCY_DERIVED_DIMENSION







#endif // NEW_DERIVED_DIMENSIONS_H
