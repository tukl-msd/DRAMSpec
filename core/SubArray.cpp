/*
Copyright (c)  2014, University of Kaiserslautern
All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software without
specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
Author: Omar Naji
*/
#include "SubArray.h"
bool 
SubArray::SubArraycal()
{
    //width of subarray is number of cells x cell width + WLDriver width
    SubArraywidth = cellsperrow * cellwidth + wldwidth;
    //height of subarray is number of cells x cell height + BLSA height
    SubArrayheight = cellspercolumn * cellheight + blsaheight;
    return true; 
}
bool 
SubArray::driversinit()
{
    //the value for global ( master ) wordline driver resistance is 
    //give for a page size of 2 kB.If the rowbuffersize becomes 
    //smaller we will need a to drive less => bigger resistance 
    //and if the rowbuffersize gets 
    if (rowbuffersize < 2) {
        GWLDresistance = GWLDresistance + 200;
    } else if ( rowbuffersize == 2 ) {
        GWLDresistance = GWLDresistance;
    } else if( rowbuffersize == 4 ) {
        GWLDresistance = GWLDresistance - 200 ;
    } else if( rowbuffersize == 8 ) {
        GWLDresistance = GWLDresistance - 300; 
    } else {
    GWLDresistance = GWLDresistance - 400;
    }

    if((cellsperrow - cellsperrowredundancy) < 256 ) {
        LWDresistance = LWDresistance + 200 ;
        WRresistance = WRresistance + 200;
    } else if((cellsperrow - cellsperrowredundancy) == 256) {
        LWDresistance = LWDresistance + 100 ;
        WRresistance = WRresistance + 100 ; 
    } else if((cellsperrow - cellsperrowredundancy) == 512) {
        LWDresistance = LWDresistance;
        WRresistance = WRresistance;
    } else if((cellsperrow - cellsperrowredundancy) == 1024) {
        LWDresistance = LWDresistance  - 100 ;
        WRresistance = WRresistance - 100 ;
    } else {
        LWDresistance = LWDresistance - 200 ;
        WRresistance = WRresistance - 200 ;
    }
    return true;
}
bool
SubArray::SubArrayinit()
{
    readjson(Techname,Paraname);
        SubArraycal();
    return true;
}

