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

#ifndef DRAMSPEC_SCALED_SI_UNITS
#define DRAMSPEC_SCALED_SI_UNITS

#include <boost/units/systems/si.hpp>
#include <boost/units/systems/si/io.hpp>
#include <boost/units/systems/si/prefixes.hpp>
#include <boost/units/cmath.hpp>

namespace boost {

namespace units {

namespace dramspec {

typedef make_scaled_unit<si::length,scale<10, static_rational<-3>>>::type millimeter_unit;
BOOST_UNITS_STATIC_CONSTANT(millimeter,millimeter_unit);
BOOST_UNITS_STATIC_CONSTANT(millimeters,millimeter_unit);
typedef make_scaled_unit<si::length,scale<10, static_rational<-6>>>::type micrometer_unit;
BOOST_UNITS_STATIC_CONSTANT(micrometer,micrometer_unit);
BOOST_UNITS_STATIC_CONSTANT(micrometers,micrometer_unit);
typedef make_scaled_unit<si::length,scale<10, static_rational<-9>>>::type nanometer_unit;
BOOST_UNITS_STATIC_CONSTANT(nanometer,nanometer_unit);
BOOST_UNITS_STATIC_CONSTANT(nanometers,nanometer_unit);

typedef make_scaled_unit<si::area,scale<10, static_rational<-6>>>::type square_millimeter_unit;
BOOST_UNITS_STATIC_CONSTANT(square_millimeter,square_millimeter_unit);
BOOST_UNITS_STATIC_CONSTANT(millimeters_squared,square_millimeter_unit);
typedef make_scaled_unit<si::area,scale<10, static_rational<-12>>>::type micrometer_squared_unit;
BOOST_UNITS_STATIC_CONSTANT(micrometer_squared,micrometer_squared_unit);
BOOST_UNITS_STATIC_CONSTANT(micrometers_squared,micrometer_squared_unit);

typedef make_scaled_unit<si::current,scale<10, static_rational<-3>>>::type milliampere_unit;
BOOST_UNITS_STATIC_CONSTANT(milliampere,milliampere_unit);
BOOST_UNITS_STATIC_CONSTANT(milliamperes,milliampere_unit);
typedef make_scaled_unit<si::current,scale<10, static_rational<-6>>>::type microampere_unit;
BOOST_UNITS_STATIC_CONSTANT(microampere,microampere_unit);
BOOST_UNITS_STATIC_CONSTANT(microamperes,microampere_unit);

typedef make_scaled_unit<si::frequency,scale<10, static_rational<6>>>::type megahertz_unit;
BOOST_UNITS_STATIC_CONSTANT(megahertz,megahertz_unit);
typedef make_scaled_unit<si::frequency,scale<10, static_rational<9>>>::type gigahertz_unit;
BOOST_UNITS_STATIC_CONSTANT(gigahertz,gigahertz_unit);

typedef make_scaled_unit<si::time,scale<10, static_rational<-3>>>::type millisecond_unit;
BOOST_UNITS_STATIC_CONSTANT(millisecond,millisecond_unit);
BOOST_UNITS_STATIC_CONSTANT(milliseconds,millisecond_unit);
typedef make_scaled_unit<si::time,scale<10, static_rational<-6>>>::type microsecond_unit;
BOOST_UNITS_STATIC_CONSTANT(microsecond,microsecond_unit);
BOOST_UNITS_STATIC_CONSTANT(microseconds,microsecond_unit);
typedef make_scaled_unit<si::time,scale<10, static_rational<-9>>>::type nanosecond_unit;
BOOST_UNITS_STATIC_CONSTANT(nanosecond,nanosecond_unit);
BOOST_UNITS_STATIC_CONSTANT(nanoseconds,nanosecond_unit);
typedef make_scaled_unit<si::time,scale<10, static_rational<-12>>>::type picosecond_unit;
BOOST_UNITS_STATIC_CONSTANT(picosecond,picosecond_unit);
BOOST_UNITS_STATIC_CONSTANT(picoseconds,picosecond_unit);

typedef make_scaled_unit<si::capacitance,scale<10, static_rational<-9>>>::type nanofarad_unit;
BOOST_UNITS_STATIC_CONSTANT(nanofarad,nanofarad_unit);
BOOST_UNITS_STATIC_CONSTANT(nanofarads,nanofarad_unit);
typedef make_scaled_unit<si::capacitance,scale<10, static_rational<-15>>>::type femtofarad_unit;
BOOST_UNITS_STATIC_CONSTANT(femtofarad,femtofarad_unit);
BOOST_UNITS_STATIC_CONSTANT(femtofarads,femtofarad_unit);

typedef make_scaled_unit<si::electric_charge,scale<10, static_rational<-9>>>::type nanocoulomb_unit;
BOOST_UNITS_STATIC_CONSTANT(nanocoulomb,nanocoulomb_unit);
BOOST_UNITS_STATIC_CONSTANT(nanocoulombs,nanocoulomb_unit);

} // namespace dramspec

} // namespace units

} // namespace boost

#endif // DRAMSPEC_SCALED_SI_UNITS
