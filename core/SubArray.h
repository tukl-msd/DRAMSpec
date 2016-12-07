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

//This class presents the second level of abstraction of the DRAM structure,
//of the DRAM which is a subarray.
#ifndef SUBARRAY_H
#define SUBARRAY_H
#include "../parser/TechnologyValues.h"
class SubArray : public TechnologyValues
{
  public:
    //constructor for subarray class
    SubArray(const std::string& techname, const std::string& paraname) :
        TechnologyValues(techname,paraname),
        subArrayWidth(0*drs::micrometer_per_sa_row),
        subArrayHeight(0*drs::micrometer_per_sa_col)
    {
        //Order of functions is important
        bool SINIT = false;
        SINIT = subArrayInit();
        if(SINIT == false){
            std::cout<<"ERROR: Func. for subarray initialization not called"
                <<"\t"<<"Order of Functions is important"<<"\n";
            throw(" Function for subarry initialization not called");
        }
        bool DINIT = false;
        DINIT = driversinit();
        if(DINIT == false){
            std::cout<<"ERROR: Function for driver initialization not called"
                <<"\t"<<"Order of Functions is important"<<"\n";
            throw(" Function for driver initialization not called");
        }
    }
    //the width of the subarray which should be calculated
//         [um/sa_row]
    bu::quantity<drs::micrometer_per_subarray_row_unit> subArrayWidth;

    //the height of the subarray which should be calculated
//         [um/sa_col]
    bu::quantity<drs::micrometer_per_subarray_column_unit>  subArrayHeight;

    // function which calculates the height and width of the subarray
    bool subArrayLengthCalc();

    //function to initialize the drivers resistances
    bool driversinit();

    //function to init subarray
    bool subArrayInit();
};
#endif//SUBARRAY_H
