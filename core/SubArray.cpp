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

bool
SubArray::subArrayStorageCalc()
{
    subArrayStorage =   (cellsPerLWL - cellsPerLWLRedundancy)
                      * (cellsPerLBL - cellsPerLBLRedundancy)
                      * drs::bit_per_cell;

    return true;
}

bool
SubArray::subArrayLengthCalc()
{
    subArrayWidth = cellsPerLWL * cellWidth + WLDriverWidth/drs::wl_subarray;

    subArrayHeight = cellsPerLBL * cellHeight;

    return true;
}

bool
SubArray::driversinit()
{
    // The value for global ( master ) wordline driver resistance is
    // give for a page size of 2 kB.If the page size becomes
    // smaller we will need a to drive less => bigger resistance
    // and if the page size gets
    if ( pageSize < 2*drs::kibibyte ) {
        GWLDriverResistance = GWLDriverResistance + 200*si::ohm;
    }
    else if ( pageSize == 2*drs::kibibyte ) {
        GWLDriverResistance = GWLDriverResistance;
    }
    else if( pageSize == 4*drs::kibibyte ) {
        GWLDriverResistance = GWLDriverResistance - 200*si::ohm;
    }
    else if( pageSize == 8*drs::kibibyte ) {
        GWLDriverResistance = GWLDriverResistance - 300*si::ohm;
    }
    else {
        GWLDriverResistance = GWLDriverResistance - 400*si::ohm;
    }

    if((cellsPerLWL - cellsPerLWLRedundancy) < 256*drs::wl_cells_per_wl_subarray ) {
        LWLDriverResistance = LWLDriverResistance + 200*drs::ohms_per_wl_subarray ;
        WRResistance = WRResistance + 200*drs::ohms_per_bl_subarray;
    }
    else if((cellsPerLWL - cellsPerLWLRedundancy) == 256*drs::wl_cells_per_wl_subarray ) {
        LWLDriverResistance = LWLDriverResistance + 100*drs::ohms_per_wl_subarray;
        WRResistance = WRResistance + 100*drs::ohms_per_bl_subarray ;
    }
    else if((cellsPerLWL - cellsPerLWLRedundancy) == 512*drs::wl_cells_per_wl_subarray) {
        LWLDriverResistance = LWLDriverResistance;
        WRResistance = WRResistance;    
    }
    else if((cellsPerLWL - cellsPerLWLRedundancy) == 1024*drs::wl_cells_per_wl_subarray) {
        LWLDriverResistance = LWLDriverResistance  - 100*drs::ohms_per_wl_subarray ;
        WRResistance = WRResistance - 100*drs::ohms_per_bl_subarray ;

    } else {
        LWLDriverResistance = LWLDriverResistance - 200*drs::ohms_per_wl_subarray;
        WRResistance = WRResistance - 200*drs::ohms_per_bl_subarray ;
    }

    return true;
}

bool
SubArray::subArrayInit()
{
    readjson(Techname,Paraname);
    subArrayLengthCalc();
    return true;
}
