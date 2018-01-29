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



#ifndef DRAMSPEC_SCALED_SI_UNITS
#define DRAMSPEC_SCALED_SI_UNITS

#include <boost/units/systems/si.hpp>
#include <boost/units/systems/si/io.hpp>
#include <boost/units/systems/si/prefixes.hpp>
#include <boost/units/cmath.hpp>

namespace boost {

namespace units {

namespace dramspec {

// Length dimension
typedef make_scaled_unit<si::length,scale<10, static_rational<15>>>::type petameter_unit;
BOOST_UNITS_STATIC_CONSTANT(petameter, petameter_unit);
BOOST_UNITS_STATIC_CONSTANT(petameters, petameter_unit);
typedef make_scaled_unit<si::length,scale<10, static_rational<12>>>::type terameter_unit;
BOOST_UNITS_STATIC_CONSTANT(terameter, terameter_unit);
BOOST_UNITS_STATIC_CONSTANT(terameters, terameter_unit);
typedef make_scaled_unit<si::length,scale<10, static_rational<9>>>::type gigameter_unit;
BOOST_UNITS_STATIC_CONSTANT(gigameter, gigameter_unit);
BOOST_UNITS_STATIC_CONSTANT(gigameters, gigameter_unit);
typedef make_scaled_unit<si::length,scale<10, static_rational<6>>>::type megameter_unit;
BOOST_UNITS_STATIC_CONSTANT(megameter, megameter_unit);
BOOST_UNITS_STATIC_CONSTANT(megameters, megameter_unit);
typedef make_scaled_unit<si::length,scale<10, static_rational<3>>>::type kilometer_unit;
BOOST_UNITS_STATIC_CONSTANT(kilometer, kilometer_unit);
BOOST_UNITS_STATIC_CONSTANT(kilometers, kilometer_unit);
typedef make_scaled_unit<si::length,scale<10, static_rational<0>>>::type meter_unit;
BOOST_UNITS_STATIC_CONSTANT(meter, meter_unit);
BOOST_UNITS_STATIC_CONSTANT(meters, meter_unit);
typedef make_scaled_unit<si::length,scale<10, static_rational<-3>>>::type millimeter_unit;
BOOST_UNITS_STATIC_CONSTANT(millimeter, millimeter_unit);
BOOST_UNITS_STATIC_CONSTANT(millimeters, millimeter_unit);
typedef make_scaled_unit<si::length,scale<10, static_rational<-6>>>::type micrometer_unit;
BOOST_UNITS_STATIC_CONSTANT(micrometer, micrometer_unit);
BOOST_UNITS_STATIC_CONSTANT(micrometers, micrometer_unit);
typedef make_scaled_unit<si::length,scale<10, static_rational<-9>>>::type nanometer_unit;
BOOST_UNITS_STATIC_CONSTANT(nanometer, nanometer_unit);
BOOST_UNITS_STATIC_CONSTANT(nanometers, nanometer_unit);
typedef make_scaled_unit<si::length,scale<10, static_rational<-12>>>::type picometer_unit;
BOOST_UNITS_STATIC_CONSTANT(picometer, picometer_unit);
BOOST_UNITS_STATIC_CONSTANT(picometers, picometer_unit);
typedef make_scaled_unit<si::length,scale<10, static_rational<-15>>>::type femtometer_unit;
BOOST_UNITS_STATIC_CONSTANT(femtometer, femtometer_unit);
BOOST_UNITS_STATIC_CONSTANT(femtometers, femtometer_unit);
typedef make_scaled_unit<si::length,scale<10, static_rational<-18>>>::type attometer_unit;
BOOST_UNITS_STATIC_CONSTANT(attometer, attometer_unit);
BOOST_UNITS_STATIC_CONSTANT(attometers, attometer_unit);
// Length dimension

// Area dimension
typedef make_scaled_unit<si::area,scale<10, static_rational<6>>>::type square_kilometer_unit;
BOOST_UNITS_STATIC_CONSTANT(square_kilometer, square_kilometer_unit);
BOOST_UNITS_STATIC_CONSTANT(square_kilometers, square_kilometer_unit);
typedef make_scaled_unit<si::area,scale<10, static_rational<0>>>::type square_meter_unit;
BOOST_UNITS_STATIC_CONSTANT(square_meter, square_meter_unit);
BOOST_UNITS_STATIC_CONSTANT(square_meters, square_meter_unit);
typedef make_scaled_unit<si::area,scale<10, static_rational<-6>>>::type square_millimeter_unit;
BOOST_UNITS_STATIC_CONSTANT(square_millimeter, square_millimeter_unit);
BOOST_UNITS_STATIC_CONSTANT(square_millimeters, square_millimeter_unit);
typedef make_scaled_unit<si::area,scale<10, static_rational<-12>>>::type square_micrometer_unit;
BOOST_UNITS_STATIC_CONSTANT(square_micrometer, square_micrometer_unit);
BOOST_UNITS_STATIC_CONSTANT(square_micrometers, square_micrometer_unit);
typedef make_scaled_unit<si::area,scale<10, static_rational<-18>>>::type square_nanometer_unit;
BOOST_UNITS_STATIC_CONSTANT(square_nanometer, square_nanometer_unit);
BOOST_UNITS_STATIC_CONSTANT(square_nanometers, square_nanometer_unit);
// Area dimension


// Current dimension
typedef make_scaled_unit<si::current,scale<10, static_rational<15>>>::type petaampere_unit;
BOOST_UNITS_STATIC_CONSTANT(petaampere, petaampere_unit);
BOOST_UNITS_STATIC_CONSTANT(petaamperes, petaampere_unit);
typedef make_scaled_unit<si::current,scale<10, static_rational<12>>>::type teraampere_unit;
BOOST_UNITS_STATIC_CONSTANT(teraampere, teraampere_unit);
BOOST_UNITS_STATIC_CONSTANT(teraamperes, teraampere_unit);
typedef make_scaled_unit<si::current,scale<10, static_rational<9>>>::type gigaampere_unit;
BOOST_UNITS_STATIC_CONSTANT(gigaampere, gigaampere_unit);
BOOST_UNITS_STATIC_CONSTANT(gigaamperes, gigaampere_unit);
typedef make_scaled_unit<si::current,scale<10, static_rational<6>>>::type megaampere_unit;
BOOST_UNITS_STATIC_CONSTANT(megaampere, megaampere_unit);
BOOST_UNITS_STATIC_CONSTANT(megaamperes, megaampere_unit);
typedef make_scaled_unit<si::current,scale<10, static_rational<3>>>::type kiloampere_unit;
BOOST_UNITS_STATIC_CONSTANT(kiloampere, kiloampere_unit);
BOOST_UNITS_STATIC_CONSTANT(kiloamperes, kiloampere_unit);
typedef make_scaled_unit<si::current,scale<10, static_rational<0>>>::type ampere_unit;
BOOST_UNITS_STATIC_CONSTANT(ampere, ampere_unit);
BOOST_UNITS_STATIC_CONSTANT(amperes, ampere_unit);
typedef make_scaled_unit<si::current,scale<10, static_rational<-3>>>::type milliampere_unit;
BOOST_UNITS_STATIC_CONSTANT(milliampere, milliampere_unit);
BOOST_UNITS_STATIC_CONSTANT(milliamperes, milliampere_unit);
typedef make_scaled_unit<si::current,scale<10, static_rational<-6>>>::type microampere_unit;
BOOST_UNITS_STATIC_CONSTANT(microampere, microampere_unit);
BOOST_UNITS_STATIC_CONSTANT(microamperes, microampere_unit);
typedef make_scaled_unit<si::current,scale<10, static_rational<-9>>>::type nanoampere_unit;
BOOST_UNITS_STATIC_CONSTANT(nanoampere, nanoampere_unit);
BOOST_UNITS_STATIC_CONSTANT(nanoamperes, nanoampere_unit);
typedef make_scaled_unit<si::current,scale<10, static_rational<-12>>>::type picoampere_unit;
BOOST_UNITS_STATIC_CONSTANT(picoampere, picoampere_unit);
BOOST_UNITS_STATIC_CONSTANT(picoamperes, picoampere_unit);
typedef make_scaled_unit<si::current,scale<10, static_rational<-15>>>::type femtoampere_unit;
BOOST_UNITS_STATIC_CONSTANT(femtoampere, femtoampere_unit);
BOOST_UNITS_STATIC_CONSTANT(femtoamperes, femtoampere_unit);
typedef make_scaled_unit<si::current,scale<10, static_rational<-18>>>::type attoampere_unit;
BOOST_UNITS_STATIC_CONSTANT(attoampere, attoampere_unit);
BOOST_UNITS_STATIC_CONSTANT(attoamperes, attoampere_unit);
// Current dimension

// Time dimension
typedef make_scaled_unit<si::time,scale<10, static_rational<15>>>::type petasecond_unit;
BOOST_UNITS_STATIC_CONSTANT(petasecond, petasecond_unit);
BOOST_UNITS_STATIC_CONSTANT(petaseconds, petasecond_unit);
typedef make_scaled_unit<si::time,scale<10, static_rational<12>>>::type terasecond_unit;
BOOST_UNITS_STATIC_CONSTANT(terasecond, terasecond_unit);
BOOST_UNITS_STATIC_CONSTANT(teraseconds, terasecond_unit);
typedef make_scaled_unit<si::time,scale<10, static_rational<9>>>::type gigasecond_unit;
BOOST_UNITS_STATIC_CONSTANT(gigasecond, gigasecond_unit);
BOOST_UNITS_STATIC_CONSTANT(gigaseconds, gigasecond_unit);
typedef make_scaled_unit<si::time,scale<10, static_rational<6>>>::type megasecond_unit;
BOOST_UNITS_STATIC_CONSTANT(megasecond, megasecond_unit);
BOOST_UNITS_STATIC_CONSTANT(megaseconds, megasecond_unit);
typedef make_scaled_unit<si::time,scale<10, static_rational<3>>>::type kilosecond_unit;
BOOST_UNITS_STATIC_CONSTANT(kilosecond, kilosecond_unit);
BOOST_UNITS_STATIC_CONSTANT(kiloseconds, kilosecond_unit);
typedef make_scaled_unit<si::time,scale<10, static_rational<0>>>::type second_unit;
BOOST_UNITS_STATIC_CONSTANT(second, second_unit);
BOOST_UNITS_STATIC_CONSTANT(seconds, second_unit);
typedef make_scaled_unit<si::time,scale<10, static_rational<-3>>>::type millisecond_unit;
BOOST_UNITS_STATIC_CONSTANT(millisecond, millisecond_unit);
BOOST_UNITS_STATIC_CONSTANT(milliseconds, millisecond_unit);
typedef make_scaled_unit<si::time,scale<10, static_rational<-6>>>::type microsecond_unit;
BOOST_UNITS_STATIC_CONSTANT(microsecond, microsecond_unit);
BOOST_UNITS_STATIC_CONSTANT(microseconds, microsecond_unit);
typedef make_scaled_unit<si::time,scale<10, static_rational<-9>>>::type nanosecond_unit;
BOOST_UNITS_STATIC_CONSTANT(nanosecond, nanosecond_unit);
BOOST_UNITS_STATIC_CONSTANT(nanoseconds, nanosecond_unit);
typedef make_scaled_unit<si::time,scale<10, static_rational<-12>>>::type picosecond_unit;
BOOST_UNITS_STATIC_CONSTANT(picosecond, picosecond_unit);
BOOST_UNITS_STATIC_CONSTANT(picoseconds, picosecond_unit);
typedef make_scaled_unit<si::time,scale<10, static_rational<-15>>>::type femtosecond_unit;
BOOST_UNITS_STATIC_CONSTANT(femtosecond, femtosecond_unit);
BOOST_UNITS_STATIC_CONSTANT(femtoseconds, femtosecond_unit);
typedef make_scaled_unit<si::time,scale<10, static_rational<-18>>>::type attosecond_unit;
BOOST_UNITS_STATIC_CONSTANT(attosecond, attosecond_unit);
BOOST_UNITS_STATIC_CONSTANT(attoseconds, attosecond_unit);
// Time dimension

// Frequency dimension
typedef make_scaled_unit<si::frequency,scale<10, static_rational<15>>>::type petahertz_unit;
BOOST_UNITS_STATIC_CONSTANT(petahertz, petahertz_unit);
typedef make_scaled_unit<si::frequency,scale<10, static_rational<12>>>::type terahertz_unit;
BOOST_UNITS_STATIC_CONSTANT(terahertz, terahertz_unit);
typedef make_scaled_unit<si::frequency,scale<10, static_rational<9>>>::type gigahertz_unit;
BOOST_UNITS_STATIC_CONSTANT(gigahertz, gigahertz_unit);
typedef make_scaled_unit<si::frequency,scale<10, static_rational<6>>>::type megahertz_unit;
BOOST_UNITS_STATIC_CONSTANT(megahertz, megahertz_unit);
typedef make_scaled_unit<si::frequency,scale<10, static_rational<3>>>::type kilohertz_unit;
BOOST_UNITS_STATIC_CONSTANT(kilohertz, kilohertz_unit);
typedef make_scaled_unit<si::frequency,scale<10, static_rational<0>>>::type hertz_unit;
BOOST_UNITS_STATIC_CONSTANT(hertz, hertz_unit);
typedef make_scaled_unit<si::frequency,scale<10, static_rational<-3>>>::type millihertz_unit;
BOOST_UNITS_STATIC_CONSTANT(millihertz, millihertz_unit);
typedef make_scaled_unit<si::frequency,scale<10, static_rational<-6>>>::type microhertz_unit;
BOOST_UNITS_STATIC_CONSTANT(microhertz, microhertz_unit);
typedef make_scaled_unit<si::frequency,scale<10, static_rational<-9>>>::type nanohertz_unit;
BOOST_UNITS_STATIC_CONSTANT(nanohertz, nanohertz_unit);
typedef make_scaled_unit<si::frequency,scale<10, static_rational<-12>>>::type picohertz_unit;
BOOST_UNITS_STATIC_CONSTANT(picohertz, picohertz_unit);
typedef make_scaled_unit<si::frequency,scale<10, static_rational<-15>>>::type femtohertz_unit;
BOOST_UNITS_STATIC_CONSTANT(femtohertz, femtohertz_unit);
typedef make_scaled_unit<si::frequency,scale<10, static_rational<-18>>>::type attohertz_unit;
BOOST_UNITS_STATIC_CONSTANT(attohertz, attohertz_unit);
// Frequency dimension

// Resistance dimension
typedef make_scaled_unit<si::resistance,scale<10, static_rational<15>>>::type petaohm_unit;
BOOST_UNITS_STATIC_CONSTANT(petaohm, petaohm_unit);
BOOST_UNITS_STATIC_CONSTANT(petaohms, petaohm_unit);
typedef make_scaled_unit<si::resistance,scale<10, static_rational<12>>>::type teraohm_unit;
BOOST_UNITS_STATIC_CONSTANT(teraohm, teraohm_unit);
BOOST_UNITS_STATIC_CONSTANT(teraohms, teraohm_unit);
typedef make_scaled_unit<si::resistance,scale<10, static_rational<9>>>::type gigaohm_unit;
BOOST_UNITS_STATIC_CONSTANT(gigaohm, gigaohm_unit);
BOOST_UNITS_STATIC_CONSTANT(gigaohms, gigaohm_unit);
typedef make_scaled_unit<si::resistance,scale<10, static_rational<6>>>::type megaohm_unit;
BOOST_UNITS_STATIC_CONSTANT(megaohm, megaohm_unit);
BOOST_UNITS_STATIC_CONSTANT(megaohms, megaohm_unit);
typedef make_scaled_unit<si::resistance,scale<10, static_rational<3>>>::type kiloohm_unit;
BOOST_UNITS_STATIC_CONSTANT(kiloohm, kiloohm_unit);
BOOST_UNITS_STATIC_CONSTANT(kiloohms, kiloohm_unit);
typedef make_scaled_unit<si::resistance,scale<10, static_rational<0>>>::type ohm_unit;
BOOST_UNITS_STATIC_CONSTANT(ohm, ohm_unit);
BOOST_UNITS_STATIC_CONSTANT(ohms, ohm_unit);
typedef make_scaled_unit<si::resistance,scale<10, static_rational<-3>>>::type milliohm_unit;
BOOST_UNITS_STATIC_CONSTANT(milliohm, milliohm_unit);
BOOST_UNITS_STATIC_CONSTANT(milliohms, milliohm_unit);
typedef make_scaled_unit<si::resistance,scale<10, static_rational<-6>>>::type microohm_unit;
BOOST_UNITS_STATIC_CONSTANT(microohm, microohm_unit);
BOOST_UNITS_STATIC_CONSTANT(microohms, microohm_unit);
typedef make_scaled_unit<si::resistance,scale<10, static_rational<-9>>>::type nanoohm_unit;
BOOST_UNITS_STATIC_CONSTANT(nanoohm, nanoohm_unit);
BOOST_UNITS_STATIC_CONSTANT(nanoohms, nanoohm_unit);
typedef make_scaled_unit<si::resistance,scale<10, static_rational<-12>>>::type picoohm_unit;
BOOST_UNITS_STATIC_CONSTANT(picoohm, picoohm_unit);
BOOST_UNITS_STATIC_CONSTANT(picoohms, picoohm_unit);
typedef make_scaled_unit<si::resistance,scale<10, static_rational<-15>>>::type femtoohm_unit;
BOOST_UNITS_STATIC_CONSTANT(femtoohm, femtoohm_unit);
BOOST_UNITS_STATIC_CONSTANT(femtoohms, femtoohm_unit);
typedef make_scaled_unit<si::resistance,scale<10, static_rational<-18>>>::type attoohm_unit;
BOOST_UNITS_STATIC_CONSTANT(attoohm, attoohm_unit);
BOOST_UNITS_STATIC_CONSTANT(attoohms, attoohm_unit);
// Resistance dimension

// Capacitance dimension
typedef make_scaled_unit<si::capacitance,scale<10, static_rational<15>>>::type petafarad_unit;
BOOST_UNITS_STATIC_CONSTANT(petafarad, petafarad_unit);
BOOST_UNITS_STATIC_CONSTANT(petafarads, petafarad_unit);
typedef make_scaled_unit<si::capacitance,scale<10, static_rational<12>>>::type terafarad_unit;
BOOST_UNITS_STATIC_CONSTANT(terafarad, terafarad_unit);
BOOST_UNITS_STATIC_CONSTANT(terafarads, terafarad_unit);
typedef make_scaled_unit<si::capacitance,scale<10, static_rational<9>>>::type gigafarad_unit;
BOOST_UNITS_STATIC_CONSTANT(gigafarad, gigafarad_unit);
BOOST_UNITS_STATIC_CONSTANT(gigafarads, gigafarad_unit);
typedef make_scaled_unit<si::capacitance,scale<10, static_rational<6>>>::type megafarad_unit;
BOOST_UNITS_STATIC_CONSTANT(megafarad, megafarad_unit);
BOOST_UNITS_STATIC_CONSTANT(megafarads, megafarad_unit);
typedef make_scaled_unit<si::capacitance,scale<10, static_rational<3>>>::type kilofarad_unit;
BOOST_UNITS_STATIC_CONSTANT(kilofarad, kilofarad_unit);
BOOST_UNITS_STATIC_CONSTANT(kilofarads, kilofarad_unit);
typedef make_scaled_unit<si::capacitance,scale<10, static_rational<0>>>::type farad_unit;
BOOST_UNITS_STATIC_CONSTANT(farad, farad_unit);
BOOST_UNITS_STATIC_CONSTANT(farads, farad_unit);
typedef make_scaled_unit<si::capacitance,scale<10, static_rational<-3>>>::type millifarad_unit;
BOOST_UNITS_STATIC_CONSTANT(millifarad, millifarad_unit);
BOOST_UNITS_STATIC_CONSTANT(millifarads, millifarad_unit);
typedef make_scaled_unit<si::capacitance,scale<10, static_rational<-6>>>::type microfarad_unit;
BOOST_UNITS_STATIC_CONSTANT(microfarad, microfarad_unit);
BOOST_UNITS_STATIC_CONSTANT(microfarads, microfarad_unit);
typedef make_scaled_unit<si::capacitance,scale<10, static_rational<-9>>>::type nanofarad_unit;
BOOST_UNITS_STATIC_CONSTANT(nanofarad, nanofarad_unit);
BOOST_UNITS_STATIC_CONSTANT(nanofarads, nanofarad_unit);
typedef make_scaled_unit<si::capacitance,scale<10, static_rational<-12>>>::type picofarad_unit;
BOOST_UNITS_STATIC_CONSTANT(picofarad, picofarad_unit);
BOOST_UNITS_STATIC_CONSTANT(picofarads, picofarad_unit);
typedef make_scaled_unit<si::capacitance,scale<10, static_rational<-15>>>::type femtofarad_unit;
BOOST_UNITS_STATIC_CONSTANT(femtofarad, femtofarad_unit);
BOOST_UNITS_STATIC_CONSTANT(femtofarads, femtofarad_unit);
typedef make_scaled_unit<si::capacitance,scale<10, static_rational<-18>>>::type attofarad_unit;
BOOST_UNITS_STATIC_CONSTANT(attofarad, attofarad_unit);
BOOST_UNITS_STATIC_CONSTANT(attofarads, attofarad_unit);
// Capacitance dimension

// Electric charge dimension
typedef make_scaled_unit<si::electric_charge,scale<10, static_rational<15>>>::type petacoulomb_unit;
BOOST_UNITS_STATIC_CONSTANT(petacoulomb, petacoulomb_unit);
BOOST_UNITS_STATIC_CONSTANT(petacoulombs, petacoulomb_unit);
typedef make_scaled_unit<si::electric_charge,scale<10, static_rational<12>>>::type teracoulomb_unit;
BOOST_UNITS_STATIC_CONSTANT(teracoulomb, teracoulomb_unit);
BOOST_UNITS_STATIC_CONSTANT(teracoulombs, teracoulomb_unit);
typedef make_scaled_unit<si::electric_charge,scale<10, static_rational<9>>>::type gigacoulomb_unit;
BOOST_UNITS_STATIC_CONSTANT(gigacoulomb, gigacoulomb_unit);
BOOST_UNITS_STATIC_CONSTANT(gigacoulombs, gigacoulomb_unit);
typedef make_scaled_unit<si::electric_charge,scale<10, static_rational<6>>>::type megacoulomb_unit;
BOOST_UNITS_STATIC_CONSTANT(megacoulomb, megacoulomb_unit);
BOOST_UNITS_STATIC_CONSTANT(megacoulombs, megacoulomb_unit);
typedef make_scaled_unit<si::electric_charge,scale<10, static_rational<3>>>::type kilocoulomb_unit;
BOOST_UNITS_STATIC_CONSTANT(kilocoulomb, kilocoulomb_unit);
BOOST_UNITS_STATIC_CONSTANT(kilocoulombs, kilocoulomb_unit);
typedef make_scaled_unit<si::electric_charge,scale<10, static_rational<0>>>::type coulomb_unit;
BOOST_UNITS_STATIC_CONSTANT(coulomb, coulomb_unit);
BOOST_UNITS_STATIC_CONSTANT(coulombs, coulomb_unit);
typedef make_scaled_unit<si::electric_charge,scale<10, static_rational<-3>>>::type millicoulomb_unit;
BOOST_UNITS_STATIC_CONSTANT(millicoulomb, millicoulomb_unit);
BOOST_UNITS_STATIC_CONSTANT(millicoulombs, millicoulomb_unit);
typedef make_scaled_unit<si::electric_charge,scale<10, static_rational<-6>>>::type microcoulomb_unit;
BOOST_UNITS_STATIC_CONSTANT(microcoulomb, microcoulomb_unit);
BOOST_UNITS_STATIC_CONSTANT(microcoulombs, microcoulomb_unit);
typedef make_scaled_unit<si::electric_charge,scale<10, static_rational<-9>>>::type nanocoulomb_unit;
BOOST_UNITS_STATIC_CONSTANT(nanocoulomb, nanocoulomb_unit);
BOOST_UNITS_STATIC_CONSTANT(nanocoulombs, nanocoulomb_unit);
typedef make_scaled_unit<si::electric_charge,scale<10, static_rational<-12>>>::type picocoulomb_unit;
BOOST_UNITS_STATIC_CONSTANT(picocoulomb, picocoulomb_unit);
BOOST_UNITS_STATIC_CONSTANT(picocoulombs, picocoulomb_unit);
typedef make_scaled_unit<si::electric_charge,scale<10, static_rational<-15>>>::type femtocoulomb_unit;
BOOST_UNITS_STATIC_CONSTANT(femtocoulomb, femtocoulomb_unit);
BOOST_UNITS_STATIC_CONSTANT(femtocoulombs, femtocoulomb_unit);
typedef make_scaled_unit<si::electric_charge,scale<10, static_rational<-18>>>::type attocoulomb_unit;
BOOST_UNITS_STATIC_CONSTANT(attocoulomb, attocoulomb_unit);
BOOST_UNITS_STATIC_CONSTANT(attocoulombs, attocoulomb_unit);
// Electric charge dimension

} // namespace dramspec

} // namespace units

} // namespace boost

#endif // DRAMSPEC_SCALED_SI_UNITS
