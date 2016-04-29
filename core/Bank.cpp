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

#include "Bank.h"
#include <iostream>

bool 
Bank::Bankinit()
{
    // Calculate size of bank * 1024 (transform to MBits)
    sizeofBank = dramsize * 1024 / numberofbanks;

    // Calculate size of halfbank
    sizeofhalfBank = sizeofBank/2;

    // Calculate number of memoryarrays pro halfbank + 1
    // (open-bit array structure)
    numberofMemoryArrays = sizeofhalfBank/sizeofMemoryArray + 1;

    // Calculate bank height required for CSL and MDQ...
    // 5u space btw subarrays
     Bankheight = numberofMemoryArrays * MemoryArraywidth +
    (numberofMemoryArrays - 1) * 5;    
                                 
    std::cout << "AREA of DRAM"<<"\n";
    std::cout <<"height of bank in micrometers"<<"\t" <<  
    Bankheight << ".\n";
    return true;
}

bool 
Bank::calcchiparea()
{
    // Calculate number of subarrrays in the width
    // direction * 1024 (to Bytes) * 8 (to bits)
    int numbersubarraysinx = ((float)0.5*1024*8 / 
    //int numbersubarraysinx = ((float)rowbuffersize*1024*8 / 
    (float)(cellsperrow - cellsperrowredundancy)) * subarray2rowbufferfactor;

    // mwldwidth//master wordline driver width ( value taken from a real
    // chip designed)
    float mwldwidth = 240;

    // Width of bank ... 10u space btw subarrays
    Bankwidth = numbersubarraysinx * SubArraywidth + wldwidth + mwldwidth ;
    std::cout<<"bank width in micrometers" << "\t"<<Bankwidth<<"\n";

    // Chipwidth ( half of the banks are placed above the Dataqueues and
    // the other half below)
    chipwidth = (numberofbanks/2)*Bankwidth;
    std::cout<<"chip width in micrometers"<< "\t" << chipwidth <<"\n";

    // columnlogicwidth values taken from a real chip design
    float columnlogicwidth = 200;

    // dq width values taken from a real chip design
    float dqwidth = 500;

    //chip heigth
    chipheight = Bankheight *2 + columnlogicwidth + dqwidth;
    std::cout<<"chip height in micrometers"<<"\t"<<chipheight<<"\n";

    //chip area in mm^2
    chiparea = chipwidth * chipheight/1000000;
    std::cout<<"chip area in mm^2"<<"\t"<<chiparea<<"\n";
    return true; 
}
