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
 * Authors: Omar Naji, Matthias Jung, Christian Weis
 */

#include "SubArray.h"

namespace si=boost::units::si;
namespace drs=boost::units::dramspec;

void
SubArray::subArrayInitialize()
{
    subArrayRowStorage = 0*drs::bit_per_subarray;
    subArrayWidth = 0*drs::micrometer_per_subarray;
    subArrayHeight = 0*drs::micrometer_per_subarray;
}

void
SubArray::subArrayStorageCalc()
{
    subArrayRowStorage = (cellsPerLWL - cellsPerLWLRedundancy)
                         * drs::bit_per_cell;

    subArrayColumnStorage = (cellsPerLBL - cellsPerLBLRedundancy)
                         * drs::bit_per_cell;

    subArrayStorage = subArrayRowStorage * subArrayColumnStorage
                      / drs::bits_per_subarray;
}

void
SubArray::subArrayLengthCalc()
{
    subArrayWidth = cellsPerLWL * cellWidth + WLDriverWidth/drs::subarray;

    subArrayHeight = cellsPerLBL * cellHeight + BLSenseAmpHeight/drs::subarray;
}

void
SubArray::subArrayCompute()
{
    subArrayStorageCalc();
    subArrayLengthCalc();
}

void
SubArray::driverUpdate()
{
    // The value for global ( master ) wordline driver resistance is
    // give for a page size of 2 kB.If the page size becomes
    // smaller we will need a to drive less => bigger resistance
    // and if the page size gets
    if ( pageStorage < 2*drs::kibibytes_per_page ) {
        GWLDriverResistance = GWLDriverResistance + 200*si::ohm;
    }
    else if ( pageStorage == 2*drs::kibibytes_per_page ) {
        GWLDriverResistance = GWLDriverResistance;
    }
    else if( pageStorage == 4*drs::kibibytes_per_page ) {
        GWLDriverResistance = GWLDriverResistance - 200*si::ohm;
    }
    else if( pageStorage == 8*drs::kibibytes_per_page ) {
        GWLDriverResistance = GWLDriverResistance - 300*si::ohm;
    }
    else {
        GWLDriverResistance = GWLDriverResistance - 400*si::ohm;
    }

    if(subArrayRowStorage < 256*drs::bits_per_subarray ) {
        LWLDriverResistance = LWLDriverResistance + 200*drs::ohms_per_subarray ;
        WRResistance = WRResistance + 200*drs::ohms_per_subarray;
    }
    else if(subArrayRowStorage < 512*drs::bits_per_subarray ) {
        LWLDriverResistance = LWLDriverResistance + 100*drs::ohms_per_subarray;
        WRResistance = WRResistance + 100*drs::ohms_per_subarray ;
    }
    else if(subArrayRowStorage < 1024*drs::bits_per_subarray ) {
        LWLDriverResistance = LWLDriverResistance;
        WRResistance = WRResistance;    
    }
    else if(subArrayRowStorage < 1025*drs::bits_per_subarray ) {
        LWLDriverResistance = LWLDriverResistance  - 100*drs::ohms_per_subarray ;
        WRResistance = WRResistance - 100*drs::ohms_per_subarray ;

    } else {
        LWLDriverResistance = LWLDriverResistance - 200*drs::ohms_per_subarray;
        WRResistance = WRResistance - 200*drs::ohms_per_subarray ;
    }
}
