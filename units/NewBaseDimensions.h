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

#ifndef NEW_BASE_DIMENSIONS_H
#define NEW_BASE_DIMENSIONS_H

///START: DRAMSPEC_CLOCK_BASE_DIMENSION

#include <boost/units/config.hpp>
#include <boost/units/base_dimension.hpp>

namespace boost {

namespace units {

/// base dimension of number of clocks
struct clock_base_dimension :
    boost::units::base_dimension<clock_base_dimension,-29>
{ };

} // namespace units

} // namespace boost

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(boost::units::clock_base_dimension)

#endif

namespace boost {

namespace units {

/// dimension of number of clocks (#)
typedef clock_base_dimension::dimension_type     clock_dimension;

} // namespace units

} // namespace boost

///END: DRAMSPEC_CLOCK_BASE_DIMENSION




///START: DRAMSPEC_CELL_BASE_DIMENSION

#include <boost/units/config.hpp>
#include <boost/units/base_dimension.hpp>

namespace boost {

namespace units {

/// base dimension of number of cells
struct cell_base_dimension :
    boost::units::base_dimension<cell_base_dimension,-30>
{ };

} // namespace units

} // namespace boost

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(boost::units::cell_base_dimension)

#endif

namespace boost {

namespace units {

/// dimension of number of cells (#)
typedef cell_base_dimension::dimension_type     cell_dimension;

} // namespace units

} // namespace boost

///END: DRAMSPEC_CELL_BASE_DIMENSION




///START: DRAMSPEC_SUBARRAY_ROW_BASE_DIMENSION

#include <boost/units/config.hpp>
#include <boost/units/base_dimension.hpp>

namespace boost {

namespace units {

/// base dimension of number of subarray rows
struct subarray_row_base_dimension :
    boost::units::base_dimension<subarray_row_base_dimension,-31>
{ };

} // namespace units

} // namespace boost

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(boost::units::subarray_row_base_dimension)

#endif

namespace boost {

namespace units {

/// dimension of number of rows (#)
typedef subarray_row_base_dimension::dimension_type     subarray_row_dimension;

} // namespace units

} // namespace boost

///END: DRAMSPEC_SUBARRAY_ROW_BASE_DIMENSION




///START: DRAMSPEC_COLUMN_BASE_DIMENSION

#include <boost/units/config.hpp>
#include <boost/units/base_dimension.hpp>

namespace boost {

namespace units {

/// base dimension of number of columns
struct column_base_dimension :
    boost::units::base_dimension<column_base_dimension,-32>
{ };

} // namespace units

} // namespace boost

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(boost::units::column_base_dimension)

#endif

namespace boost {

namespace units {

/// dimension of number of columns (#)
typedef column_base_dimension::dimension_type     column_dimension;

} // namespace units

} // namespace boost

///END: DRAMSPEC_COLUMN_BASE_DIMENSION




///START: DRAMSPEC_VAULTPERLAYER_BASE_DIMENSION

#include <boost/units/config.hpp>
#include <boost/units/base_dimension.hpp>

namespace boost {

namespace units {

/// base dimension of number of vaults per layer
struct vaultsperlayer_base_dimension :
    boost::units::base_dimension<vaultsperlayer_base_dimension,-33>
{ };

} // namespace units

} // namespace boost

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(boost::units::vaultsperlayer_base_dimension)

#endif

namespace boost {

namespace units {

/// dimension of number of vaults per layer (#)
typedef vaultsperlayer_base_dimension::dimension_type vaultsperlayer_dimension;

} // namespace units

} // namespace boost

///END: DRAMSPEC_VAULTPERLAYER_BASE_DIMENSION




///START: DRAMSPEC_BANK_BASE_DIMENSION

#include <boost/units/config.hpp>
#include <boost/units/base_dimension.hpp>

namespace boost {

namespace units {

/// base dimension of number of banks
struct bank_base_dimension :
    boost::units::base_dimension<bank_base_dimension,-34>
{ };

} // namespace units

} // namespace boost

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(boost::units::bank_base_dimension)

#endif

namespace boost {

namespace units {

/// dimension of number of bank (#)
typedef bank_base_dimension::dimension_type     bank_dimension;

} // namespace units

} // namespace boost

///END: DRAMSPEC_BANK_BASE_DIMENSION




///START: DRAMSPEC_TILE_BASE_DIMENSION

#include <boost/units/config.hpp>
#include <boost/units/base_dimension.hpp>

namespace boost {

namespace units {

/// base dimension of number of tiles
struct tile_base_dimension :
    boost::units::base_dimension<tile_base_dimension,-35>
{ };

} // namespace units

} // namespace boost

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(boost::units::tile_base_dimension)

#endif

namespace boost {

namespace units {

/// dimension of number of tiles (#)
typedef tile_base_dimension::dimension_type     tile_dimension;

} // namespace units

} // namespace boost

///END: DRAMSPEC_TILE_BASE_DIMENSION




#endif // NEW_BASE_DIMENSIONS_H
