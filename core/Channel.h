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



#ifndef CHANNEL_H
#define CHANNEL_H

//This class repesents the fifth level of abstraction of the DRAM structure,
//being the channel a grouping of banks.

#include "Bank.h"

namespace bu=boost::units;
namespace si=boost::units::si;
namespace inf=boost::units::information;
namespace drs=boost::units::dramspec;

class Channel : public Bank
{
  public:
    Channel() : //Empty constructor for test proposes
        Bank()
    {
        channelInitialize();
    }

    Channel(const string& technologyFileName,
         const string& architectureFileName) :
        Bank(technologyFileName, architectureFileName)
    {
        channelInitialize();
        channelCompute();
    }

    // Size in number of bits of the channel
    bu::quantity<drs::gibibit_unit> channelStorage;

    // Width in micrometer of the channel
    bu::quantity<drs::micrometer_unit> channelWidth;
    // Height in micrometer of the channel
    bu::quantity<drs::micrometer_unit> channelHeight;

    // Area in micrometer squared of the channel
    bu::quantity<drs::square_millimeter_unit> channelArea;

    void channelInitialize();

    void channelStorageCalc();

    void channelBanksPlacementAssess();

    void channelLenghtCalc();

    void channelAreaCalc();

    void channelCompute();

};

#endif // CHANNEL_H
