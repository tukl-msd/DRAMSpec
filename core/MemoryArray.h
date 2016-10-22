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
*  for the DRAM overall structure,
*  being a "MemoryArray" a row of subArrays.
* Instead, the Tile structure will be implemented as the third
*  abstraction level of the DRAM structure.
*/

// This class repesents a memoryarray. The memory array is a matrix of 
// subarrays in the horizantal and vertical direction. The memory array
// class inherits from subarray class

#ifndef MEMORYARRAY_H
#define MEMORYARRAY_H
#include "SubArray.h"
#include <iostream>

class MemoryArray:public SubArray
{
  public:
    MemoryArray(const std::string& techname, const std::string& paraname)
    :SubArray(techname,paraname), subproMemoryArrayx(0), sizeofMemoryArray(0),
    MemoryArrayheight(0), MemoryArraywidth(0)
    {
        MemoryArrayinit();
    }
    
    //The number of subarrays pro memory array(should be calculated)
    //The number of subarrays in x direction 
    int subproMemoryArrayx;

    // Size of memory array
    int sizeofMemoryArray;

    // The total height of the memory array
    float MemoryArrayheight;

    // The total width of the memory array
    float  MemoryArraywidth;
  
    // function which calculates the number of subarrays in x and y directions
    void 
    calculateSubArrayxy();

    // function which calc the total width and height of the memory array
    void 
    calculateSubArrayxylength();

    // Function which delivers all the missing parameter of the memory array
    // needed for further calculations(x and y quadratic distribution)
    // this function initializes the memory array
    void 
    MemoryArrayinit();
};
#endif//MEMORYARRAY_H
