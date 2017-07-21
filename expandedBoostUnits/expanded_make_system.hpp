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


#ifndef BOOST_UNITS_MAKE_SYSTEM_HPP
#define BOOST_UNITS_MAKE_SYSTEM_HPP

/// \file
/// \brief Metafunction returning a homogeneous system that can
///    represent any combination of the base units.
/// \details
/// Metafunction make_system returning a homogeneous system that can
/// represent any combination of the base units.  There must
/// be no way to represent any of the base units in terms
/// of the others.  make_system<foot_base_unit, meter_base_unit>::type
/// is not allowed, for example.

#include <boost/units/config.hpp>
#include <boost/units/dimensionless_type.hpp>
#include <boost/units/homogeneous_system.hpp>
#include <boost/units/detail/dimension_list.hpp>
#include <boost/units/detail/sort.hpp>

namespace boost {

namespace units {

#ifdef BOOST_UNITS_DOXYGEN

namespace detail {

struct unspecified {};

}

/// Metafunction returning a homogeneous system that can
/// represent any combination of the base units.  There must
/// be no way to represent any of the base units in terms
/// of the others.  make_system<foot_base_unit, meter_base_unit>::type
/// is not allowed, for example.
template<class BaseUnit0, class BaseUnit1, class BaseUnit2, ..., class BaseUnitN>
struct make_system
{
    typedef homogeneous_system<detail::unspecified> type;
};

#else

struct na {};

template<
    class U0 = na,
    class U1 = na,
    class U2 = na,
    class U3 = na,
    class U4 = na,
    class U5 = na,
    class U6 = na,
    class U7 = na,
    class U8 = na,
    class U9 = na,
    class U10 = na,
    class U11 = na,
    class U12 = na,
    class U13 = na,
    class U14 = na,
    class U15 = na,
    class U16 = na,
    class U17 = na,
    class U18 = na,
    class U19 = na
>
struct make_system;

template<>
struct make_system<>
{
    typedef homogeneous_system<dimensionless_type> type;
};

// Codewarrior 9.2 doesn't like using the defaults.  Need
// to specify na explicitly.
template<class T0>
struct make_system<T0, na, na, na, na, na, na, na, na, na, na, na, na, na, na, na, na, na, na, na>
{
    typedef homogeneous_system<list<T0, dimensionless_type> > type;
};

template<class T0, class T1>
struct make_system<T0, T1, na, na, na, na, na, na, na, na, na, na, na, na, na, na, na, na, na, na>
{
    typedef homogeneous_system<typename detail::insertion_sort<list<T0, list<T1, dimensionless_type> > >::type> type;
};

template<class T0, class T1, class T2>
struct make_system<T0, T1, T2, na, na, na, na, na, na, na, na, na, na, na, na, na, na, na, na, na>
{
    typedef homogeneous_system<typename detail::insertion_sort<list<T0, list<T1, list<T2, dimensionless_type> > > >::type> type;
};

template<class T0, class T1, class T2, class T3>
struct make_system<T0, T1, T2, T3, na, na, na, na, na, na, na, na, na, na, na, na, na, na, na, na>
{
    typedef homogeneous_system<typename detail::insertion_sort<list<T0, list<T1, list<T2, list<T3, dimensionless_type> > > > >::type> type;
};

template<class T0, class T1, class T2, class T3, class T4>
struct make_system<T0, T1, T2, T3, T4, na, na, na, na, na, na, na, na, na, na, na, na, na, na, na>
{
    typedef homogeneous_system<typename detail::insertion_sort<list<T0, list<T1, list<T2, list<T3, list<T4, dimensionless_type> > > > > >::type> type;
};

template<class T0, class T1, class T2, class T3, class T4, class T5>
struct make_system<T0, T1, T2, T3, T4, T5, na, na, na, na, na, na, na, na, na, na, na, na, na, na>
{
    typedef homogeneous_system<typename detail::insertion_sort<list<T0, list<T1, list<T2, list<T3, list<T4, list<T5, dimensionless_type> > > > > > >::type> type;
};

template<class T0, class T1, class T2, class T3, class T4, class T5, class T6>
struct make_system<T0, T1, T2, T3, T4, T5, T6, na, na, na, na, na, na, na, na, na, na, na, na, na>
{
    typedef homogeneous_system<typename detail::insertion_sort<list<T0, list<T1, list<T2, list<T3, list<T4, list<T5, list<T6, dimensionless_type> > > > > > > >::type> type;
};

template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7>
struct make_system<T0, T1, T2, T3, T4, T5, T6, T7, na, na, na, na, na, na, na, na, na, na, na, na>
{
    typedef homogeneous_system<typename detail::insertion_sort<list<T0, list<T1, list<T2, list<T3, list<T4, list<T5, list<T6, list<T7, dimensionless_type> > > > > > > > >::type> type;
};

template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8>
struct make_system<T0, T1, T2, T3, T4, T5, T6, T7, T8, na, na, na, na, na, na, na, na, na, na, na>
{
    typedef homogeneous_system<typename detail::insertion_sort<list<T0, list<T1, list<T2, list<T3, list<T4, list<T5, list<T6, list<T7, list<T8, dimensionless_type> > > > > > > > > >::type> type;
};

template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9>
struct make_system<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, na, na, na, na, na, na, na, na, na, na>
{
    typedef homogeneous_system<typename detail::insertion_sort<list<T0, list<T1, list<T2, list<T3, list<T4, list<T5, list<T6, list<T7, list<T8, list<T9, dimensionless_type> > > > > > > > > > >::type> type;
};

template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10>
struct make_system<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, na, na, na, na, na, na, na, na, na>
{
    typedef homogeneous_system<typename detail::insertion_sort<list<T0, list<T1, list<T2, list<T3, list<T4, list<T5, list<T6, list<T7, list<T8, list<T9, list<T10, dimensionless_type> > > > > > > > > > > >::type> type;
};

template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11>
struct make_system<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, na, na, na, na, na, na, na, na>
{
    typedef homogeneous_system<typename detail::insertion_sort<list<T0, list<T1, list<T2, list<T3, list<T4, list<T5, list<T6, list<T7, list<T8, list<T9, list<T10, list<T11, dimensionless_type> > > > > > > > > > > > >::type> type;
};

template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12>
struct make_system<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, na, na, na, na, na, na, na>
{
    typedef homogeneous_system<typename detail::insertion_sort<list<T0, list<T1, list<T2, list<T3, list<T4, list<T5, list<T6, list<T7, list<T8, list<T9, list<T10, list<T11, list<T12, dimensionless_type> > > > > > > > > > > > > >::type> type;
};

template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13>
struct make_system<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, na, na, na, na, na, na>
{
    typedef homogeneous_system<typename detail::insertion_sort<list<T0, list<T1, list<T2, list<T3, list<T4, list<T5, list<T6, list<T7, list<T8, list<T9, list<T10, list<T11, list<T12, list<T13, dimensionless_type> > > > > > > > > > > > > > >::type> type;
};

template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14>
struct make_system<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, na, na, na, na, na>
{
    typedef homogeneous_system<typename detail::insertion_sort<list<T0, list<T1, list<T2, list<T3, list<T4, list<T5, list<T6, list<T7, list<T8, list<T9, list<T10, list<T11, list<T12, list<T13, list<T14, dimensionless_type> > > > > > > > > > > > > > > >::type> type;
};

template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15>
struct make_system<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, na, na, na, na>
{
    typedef homogeneous_system<typename detail::insertion_sort<list<T0, list<T1, list<T2, list<T3, list<T4, list<T5, list<T6, list<T7, list<T8, list<T9, list<T10, list<T11, list<T12, list<T13, list<T14, list<T15, dimensionless_type> > > > > > > > > > > > > > > > >::type> type;
};

template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15, class T16>
struct make_system<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, na, na, na>
{
    typedef homogeneous_system<typename detail::insertion_sort<list<T0, list<T1, list<T2, list<T3, list<T4, list<T5, list<T6, list<T7, list<T8, list<T9, list<T10, list<T11, list<T12, list<T13, list<T14, list<T15, list<T16, dimensionless_type> > > > > > > > > > > > > > > > > >::type> type;
};

template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15, class T16, class T17>
struct make_system<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, na, na>
{
    typedef homogeneous_system<typename detail::insertion_sort<list<T0, list<T1, list<T2, list<T3, list<T4, list<T5, list<T6, list<T7, list<T8, list<T9, list<T10, list<T11, list<T12, list<T13, list<T14, list<T15, list<T16, list<T17, dimensionless_type> > > > > > > > > > > > > > > > > > >::type> type;
};

template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15, class T16, class T17, class T18>
struct make_system<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, na>
{
    typedef homogeneous_system<typename detail::insertion_sort<list<T0, list<T1, list<T2, list<T3, list<T4, list<T5, list<T6, list<T7, list<T8, list<T9, list<T10, list<T11, list<T12, list<T13, list<T14, list<T15, list<T16, list<T17, list<T18, dimensionless_type> > > > > > > > > > > > > > > > > > > >::type> type;
};
/*
template<class T0, class T1, class T2, class T3, class T4, class T5, class T6, class T7, class T8, class T9, class T10, class T11, class T12, class T13, class T14, class T15, class T16, class T17, class T18, class T19>
struct make_system<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, T13, T14, T15, T16, T17, T18, T19>
{
    typedef homogeneous_system<typename detail::insertion_sort<list<T0, list<T1, list<T2, list<T3, list<T4, list<T5, list<T6, list<T7, list<T8, list<T9, list<T10, list<T11, list<T12, list<T13, list<T14, list<T15, list<T16, list<T17, list<T18, list<T19, dimensionless_type> > > > > > > > > > > > > > > > > > > > >::type> type;
};
*/

#endif

} // namespace units

} // namespace boost

#endif
