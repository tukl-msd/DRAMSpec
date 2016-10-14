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

#ifndef NEW_BASE_UNITS_H
#define NEW_BASE_UNITS_H

///START: DRAMSPEC_CELL_BASE_UNIT_H

#include <string>

#include <boost/units/config.hpp>
#include <boost/units/base_unit.hpp>
#include "NewBaseDimensions.h"

namespace boost {

namespace units {

namespace dramspec {

struct cell_base_unit : public base_unit<cell_base_unit, cell_dimension, -30>
{
    static std::string name()   { return("cell"); }
    static std::string symbol() { return("cell"); }
};

} // namespace dramspec

} // namespace units

} // namespace boost

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(boost::units::dramspec::cell_base_unit)

#endif

///END: DRAMSPEC_CELL_BASE_UNIT_H




///START: DRAMSPEC_ROW_BASE_UNIT_H

#include <string>

#include <boost/units/config.hpp>
#include <boost/units/base_unit.hpp>
#include "NewBaseDimensions.h"

namespace boost {

namespace units {

namespace dramspec {

struct row_base_unit : public base_unit<row_base_unit, row_dimension, -31>
{
    static std::string name()   { return("row"); }
    static std::string symbol() { return("row"); }
};

} // namespace dramspec

} // namespace units

} // namespace boost

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(boost::units::dramspec::row_base_unit)

#endif

///END: DRAMSPEC_ROW_BASE_UNIT_H




///START: DRAMSPEC_COLUMN_BASE_UNIT_H

#include <string>

#include <boost/units/config.hpp>
#include <boost/units/base_unit.hpp>
#include "NewBaseDimensions.h"

namespace boost {

namespace units {

namespace dramspec {

struct column_base_unit :
        public base_unit<column_base_unit, column_dimension, -32>
{
    static std::string name()   { return("column"); }
    static std::string symbol() { return("column"); }
};

} // namespace dramspec

} // namespace units

} // namespace boost

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(boost::units::dramspec::column_base_unit)

#endif

///END: DRAMSPEC_COLUMN_BASE_UNIT_H




///START: DRAMSPEC_VAULTPERLAYER_BASE_UNIT_H

#include <string>

#include <boost/units/config.hpp>
#include <boost/units/base_unit.hpp>
#include "NewBaseDimensions.h"

namespace boost {

namespace units {

namespace dramspec {

struct vaultsperlayer_base_unit :
        public base_unit<vaultsperlayer_base_unit,
                                   vaultsperlayer_dimension, -33>
{
    static std::string name()   { return("vaultsperlayer"); }
    static std::string symbol() { return("vaultsperlayer"); }
};

} // namespace dramspec

} // namespace units

} // namespace boost

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(boost::units::dramspec::vaultsperlayer_base_unit)

#endif

///END: DRAMSPEC_VAULTPERLAYER_BASE_UNIT_H




///START: DRAMSPEC_BANK_BASE_UNIT_H

#include <string>

#include <boost/units/config.hpp>
#include <boost/units/base_unit.hpp>
#include "NewBaseDimensions.h"

namespace boost {

namespace units {

namespace dramspec {

struct bank_base_unit : public base_unit<bank_base_unit, bank_dimension, -34>
{
    static std::string name()   { return("bank"); }
    static std::string symbol() { return("bank"); }
};

} // namespace dramspec

} // namespace units

} // namespace boost

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(boost::units::dramspec::bank_base_unit)

#endif

///END: DRAMSPEC_BANK_BASE_UNIT_H




///START: DRAMSPEC_TILE_BASE_UNIT_H

#include <string>

#include <boost/units/config.hpp>
#include <boost/units/base_unit.hpp>
#include "NewBaseDimensions.h"

namespace boost {

namespace units {

namespace dramspec {

struct tile_base_unit : public base_unit<tile_base_unit, tile_dimension, -35>
{
    static std::string name()   { return("tile"); }
    static std::string symbol() { return("tile"); }
};

} // namespace dramspec

} // namespace units

} // namespace boost

#if BOOST_UNITS_HAS_BOOST_TYPEOF

#include BOOST_TYPEOF_INCREMENT_REGISTRATION_GROUP()

BOOST_TYPEOF_REGISTER_TYPE(boost::units::dramspec::tile_base_unit)

#endif

///END: DRAMSPEC_TILE_BASE_UNIT_H




#endif // NEW_BASE_UNITS_H
