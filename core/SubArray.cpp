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



#include "SubArray.h"

namespace si=boost::units::si;
namespace drs=boost::units::dramspec;

void
SubArray::subArrayInitialize()
{
    subArrayRowStorage = 0*drs::bits;
    subArrayWidth = 0*drs::micrometers;
    subArrayHeight = 0*drs::micrometers;
}

void
SubArray::subArrayStorageCalc()
{
    subArrayRowStorage = (cellsPerLWL - cellsPerLWLRedundancy)
                         * drs::bits;

    subArrayColumnStorage = (cellsPerLBL - cellsPerLBLRedundancy)
                         * drs::bits;

    subArrayStorage = subArrayRowStorage * subArrayColumnStorage
                      / drs::bits;
}

void
SubArray::subArrayLengthCalc()
{
    subArrayWidth = cellsPerLWL * cellWidth + LWLDriverWidth;

    subArrayHeight = cellsPerLBL * cellHeight + BLSenseAmpHeight;
}

void
SubArray::subArrayCompute()
{
    try {
        subArrayStorageCalc();
    }catch (std::string exceptionMsgThrown){
        throw exceptionMsgThrown;
    }
    subArrayLengthCalc();
}

void
SubArray::driverUpdate()
{

    // TODO: CHANGE FOR A ABSOLUTE VALUE
    // OR SLOPE
    // AND USER CHOOSE ONE OR THE OTHER


    // The value for global ( master ) wordline driver resistance is
    // give for a page size of 2 kB.If the page size becomes
    // smaller we will need a to drive less => bigger resistance
    // and if the page size gets
    if ( pageStorage < 2*drs::kibibytes ) {
        GWLDriverResistance = GWLDriverResistance + 200*drs::ohm;
    }
    else if ( pageStorage == 2*drs::kibibytes ) {
        GWLDriverResistance = GWLDriverResistance;
    }
    else if( pageStorage == 4*drs::kibibytes ) {
        GWLDriverResistance = GWLDriverResistance - 200*drs::ohm;
    }
    else if( pageStorage == 8*drs::kibibytes ) {
        GWLDriverResistance = GWLDriverResistance - 300*drs::ohm;
    }
    else {
        GWLDriverResistance = GWLDriverResistance - 400*drs::ohm;
    }

    if(subArrayRowStorage < 256*drs::bits ) {
        LWLDriverResistance = LWLDriverResistance + 200*drs::ohms;
        WRDriverResistance = WRDriverResistance + 200*drs::ohms;
    }
    else if(subArrayRowStorage < 512*drs::bits ) {
        LWLDriverResistance = LWLDriverResistance + 100*drs::ohms;
        WRDriverResistance = WRDriverResistance + 100*drs::ohms;
    }
    else if(subArrayRowStorage < 1024*drs::bits ) {
        LWLDriverResistance = LWLDriverResistance;
        WRDriverResistance = WRDriverResistance;    
    }
    else if(subArrayRowStorage < 1025*drs::bits ) {
        LWLDriverResistance = LWLDriverResistance  - 100*drs::ohms;
        WRDriverResistance = WRDriverResistance - 100*drs::ohms;

    } else {
        LWLDriverResistance = LWLDriverResistance - 200*drs::ohms;
        WRDriverResistance = WRDriverResistance - 200*drs::ohms;
    }
}
