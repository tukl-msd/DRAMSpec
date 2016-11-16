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

/*
* This structure describes something that has little if any meaning
*  in the DRAM overall structure,
*  being a "MemoryArray" a row of subArrays.
* Instead, the Tile structure will be implemented as the third
*  abstraction level of the DRAM structure.
*/

#include "MemoryArray.h"
#include <math.h>

void 
MemoryArray::calculateSubArrayxy()
{
    // Number of rowcells without redundant cells
//    [bit/sa_row] [bit/sa_row]     [bit/sa_row]
    int rowcells = cellPerLWL - cellsPerLWLRedundancy;

    // Number of columncells without redundant cells
//     [bit/sa_col]    [bit/sa_col]         [bit/sa_col]
    int columncells = cellsPerLBL - cellsPerLBLRedundancy;

    // Size of the subarray (value presented in Kbit)
//          [bit]       [bit/sa_row] [bit/sa_col] ![row]*[column] = []!
    int sizeofSubArray = (rowcells * columncells)/(1024);



    //FIXME: This part does not verify the number of tiles per bank. Why?
    // Calculate number of subarrays in x direction (rowbuffersize is in
    // kbytes) divided by 2 because half the page is opened per half bank!!
//    [sa_row/ma_row]                     [KByte]
    subproMemoryArrayx = (int)(((float)pageSize
//                                    []
                                * subArrayRatioToPage
//                         [KByte -> Kbit]
                                * 8
//                           [Kbit -> bit]
                                * 1024
//                               [??]
                                / 2)
//                                      [bit/sa_row]
                                / (float)rowcells);

    // Size of memoryarray (subarrays in x direction size ) in Mbit
//     [Kbit/row]         [sa_row/ma_row]         [bit]   [bit -> Kbit]
    sizeofMemoryArray = (subproMemoryArrayx * sizeofSubArray)/1024;
}

void 
MemoryArray::calculateSubArrayxylength()
{
    // calculate length of memory array in x direction assuming open
    // bitline array structure
//     [um/ma_row]      [sa_row/ma_row]      [um/sa_row]   [um/ma_row] !ma_wldwidth != sa_wldwidth!
    MemoryArraywidth = subproMemoryArrayx * subArrayWidth + wldwidth;

    //FIXME: Why is it just 1 subarray?
    // calculate length of memory array in y direction
//     [um/ma_col]  [sa_col/ma_col] [um/sa_col]
    MemoryArrayheight = 1   *    subArrayHeight; //JUST SUB ARRAY
}

void 
MemoryArray::MemoryArrayinit()
{
    calculateSubArrayxy();
    calculateSubArrayxylength();
}
