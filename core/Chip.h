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
 * Authors: Omar Naji,
 *          Matthias Jung,
 *          Christian Weis,
 *          Kamal Haddad,
 *          Andr'e Lucas Chinazzo
 */

#ifndef CHIP_H
#define CHIP_H

//This class repesents the fifth level of abstraction of the DRAM structure,
//being the chip a grouping of banks.

#include "Bank.h"

namespace bu=boost::units;
namespace si=boost::units::si;
namespace inf=boost::units::information;
namespace drs=boost::units::dramspec;

class Chip : public Bank
{
  public:
    Chip() : //Empty constructor for test proposes
        Bank()
    {
        chipInitialize();
    }

    Chip(const string& technologyFileName,
         const string& architectureFileName) :
        Bank(technologyFileName, architectureFileName)
    {
        chipInitialize();
        chipCompute();
    }

    // Size in number of bits of the chip
    bu::quantity<drs::gibibit_unit> chipStorage;

    // Width in micrometer of the chip
    bu::quantity<drs::micrometer_unit> chipWidth;
    // Height in micrometer of the chip
    bu::quantity<drs::micrometer_unit> chipHeight;

    // Area in micrometer squared of the chip
    bu::quantity<drs::square_millimeter_unit> chipArea;

    void chipInitialize();

    void chipStorageCalc();

    void chipLenghtCalc();

    void chipAreaCalc();

    void chipCompute();

};

#endif // CHIP_H
