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
bool 
SubArray::subArrayLengthCalc()
{
//   [um/sa_row]   [cell/sa_row] [um/cell]     [um]       [sa_row]
    subArrayWidth = cellPerLWL * cellwidth + wldwidth;// /drs::sa_row;

//   [um/sa_col]    [cell/sa_col]   [um/cell]
    subArrayHeight = cellsPerLBL * cellheight;

    return true; 
}
bool 
SubArray::driversinit()
{
    // The value for global ( master ) wordline driver resistance is 
    // give for a page size of 2 kB.If the rowbuffersize becomes 
    // smaller we will need a to drive less => bigger resistance 
    // and if the rowbuffersize gets
// [KByte/page] [KByte/page]
    if (pageSize < 2) {
//          [ohm]           [ohm]         [ohm]
        GWLDresistance = GWLDresistance + 200;
    } else if ( pageSize == 2 ) {
        GWLDresistance = GWLDresistance;
    } else if( pageSize == 4 ) {
        GWLDresistance = GWLDresistance - 200 ;
    } else if( pageSize == 8 ) {
        GWLDresistance = GWLDresistance - 300;
    } else {
        GWLDresistance = GWLDresistance - 400;
    }

//     [bit/sa_row]       [bit/sa_row]      [bit/sa_row]
    if((cellPerLWL - cellsPerLWLRedundancy) < 256 ) {
//      [ohm/sa_row]   [ohm/sa_row] [ohm/sa_row]
        LWDresistance = LWDresistance + 200 ;
//      [ohm/sa_col]   [ohm/sa_col] [ohm/sa_col]
        WRresistance = WRresistance + 200;
    } else if((cellPerLWL - cellsPerLWLRedundancy) == 256) {
        LWDresistance = LWDresistance + 100 ;
        WRresistance = WRresistance + 100 ; 
    } else if((cellPerLWL - cellsPerLWLRedundancy) == 512) {
        LWDresistance = LWDresistance;
        WRresistance = WRresistance;
    } else if((cellPerLWL - cellsPerLWLRedundancy) == 1024) {
        LWDresistance = LWDresistance  - 100 ;
        WRresistance = WRresistance - 100 ;
    } else {
        LWDresistance = LWDresistance - 200 ;
        WRresistance = WRresistance - 200 ;
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
