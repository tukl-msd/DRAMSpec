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



#ifndef DRAMSPEC_CURRENT_PER_CLOCK_FREQUENCY_UNIT_H
#define DRAMSPEC_CURRENT_PER_CLOCK_FREQUENCY_UNIT_H

#include "../dramSpecUnitsSystem.h"
#include "../DerivedDimensions/current_per_clock_frequency.h"

namespace boost {

namespace units {

namespace dramspec {

typedef unit<current_per_clock_frequency_dimension,dramspec::system_bit>    current_per_clock_frequency;

BOOST_UNITS_STATIC_CONSTANT(ampere_per_clock_hertz,current_per_clock_frequency);
BOOST_UNITS_STATIC_CONSTANT(amperes_per_clock_hertz,current_per_clock_frequency);

// milliampere / (megahertz clock) = nanoampere / (hertz clock)
typedef make_scaled_unit<current_per_clock_frequency,scale<10, static_rational<-9>>>::type milliampere_per_megahertz_clock_unit;
BOOST_UNITS_STATIC_CONSTANT(milliampere_per_megahertz_clock,milliampere_per_megahertz_clock_unit);
BOOST_UNITS_STATIC_CONSTANT(milliamperes_per_megahertz_clock,milliampere_per_megahertz_clock_unit);

// microampere / (megahertz clock) = picoampere / (hertz clock)
typedef make_scaled_unit<current_per_clock_frequency,scale<10, static_rational<-12>>>::type microampere_per_megahertz_clock_unit;
BOOST_UNITS_STATIC_CONSTANT(microampere_per_megahertz_clock,microampere_per_megahertz_clock_unit);
BOOST_UNITS_STATIC_CONSTANT(microamperes_per_megahertz_clock,microampere_per_megahertz_clock_unit);

} // namespace dramspec

} // namespace units

} // namespace boost

#endif // DRAMSPEC_CURRENT_PER_CLOCK_FREQUENCY_UNIT_H
