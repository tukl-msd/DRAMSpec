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



#ifndef SUBARRAY_H
#define SUBARRAY_H

//This class presents the second level of abstraction of the DRAM structure,
//of the DRAM which is a subarray.

#include "../parser/TechnologyValues.h"

namespace bu=boost::units;
namespace si=boost::units::si;
namespace inf=boost::units::information;
namespace drs=boost::units::dramspec;

class SubArray : public TechnologyValues
{
  public:
    SubArray() : //Empty constructor for test proposes
        TechnologyValues()
    {
        subArrayInitialize();
    }

    SubArray(const string& technologyFileName,
             const string& architectureFileName) :
        TechnologyValues(technologyFileName, architectureFileName)
    {
        subArrayInitialize();
        try {
            subArrayCompute();
        }catch (string exceptionMsgThrown){
            throw exceptionMsgThrown;
        }
        driverUpdate();
    }

    // Size in number of bits of a single subarray
    bu::quantity<drs::bit_unit> subArrayStorage;

    // Size in number of bits of a single physical row of a subarray
    bu::quantity<drs::bit_unit> subArrayRowStorage;

    // Size in number of bits of a single column physical of a subarray
    bu::quantity<drs::bit_unit> subArrayColumnStorage;

    //the width of the subarray which should be calculated
    bu::quantity<drs::micrometer_unit> subArrayWidth;

    //the height of the subarray which should be calculated
    bu::quantity<drs::micrometer_unit>  subArrayHeight;

    void subArrayInitialize();

    void subArrayStorageCalc();

    void subArrayLengthCalc();

    void subArrayCompute();

    void driverUpdate();
};
#endif//SUBARRAY_H
