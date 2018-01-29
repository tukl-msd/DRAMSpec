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



#include "Channel.h"

void
Channel::channelInitialize()
{
    channelStorage = 0*drs::gibibit;
    channelWidth = 0*drs::micrometer;
    channelHeight = 0*drs::micrometer;
    channelArea = 0*drs::square_millimeter;
}

void
Channel::channelStorageCalc()
{
    channelStorage = channelSize;
}

void
Channel::channelBanksPlacementAssess()
{
    if ( isPowerOfTwo(nBanks) == false ) {
        std::string exceptionMsgThrown("[ERROR] ");
        exceptionMsgThrown.append("Total number of banks ");
        exceptionMsgThrown.append("must be a power of two.");
        throw exceptionMsgThrown;
    }

    // Defining default bank placement on channel,
    // executed when the number of banks in neither direction is defined
    // in the input file
    if ( nHorizontalBanks == 0 && nVerticalBanks == 0 )
    {
        nVerticalBanks = pow(2, floor(log(nBanks)/log(4.0)) );
        nHorizontalBanks = nBanks / nVerticalBanks;
    }

    // If one direction only is defined
    // define the other one.
    else if ( nHorizontalBanks == 0 )
    {
        if ( isPowerOfTwo(nVerticalBanks) == false
             || nVerticalBanks > nBanks ) {
            std::string exceptionMsgThrown("[ERROR] ");
            exceptionMsgThrown.append("Number of banks in either direction ");
            exceptionMsgThrown.append("must be a power of two and ");
            exceptionMsgThrown.append("less than or equal to the ");
            exceptionMsgThrown.append("total number of banks.");
            throw exceptionMsgThrown;
        }

        nHorizontalBanks = nBanks / nVerticalBanks;
    }
    else if ( nVerticalBanks == 0 )
    {
        if ( isPowerOfTwo(nHorizontalBanks) == false
             || nVerticalBanks > nBanks ) {
            std::string exceptionMsgThrown("[ERROR] ");
            exceptionMsgThrown.append("Number of banks in either direction ");
            exceptionMsgThrown.append("must be a power of two and ");
            exceptionMsgThrown.append("less than or equal to the ");
            exceptionMsgThrown.append("total number of banks.");
            throw exceptionMsgThrown;
        }

        nVerticalBanks = nBanks / nHorizontalBanks ;
    }

    // If number of banks in both directions is defined
    // make sure it matched with the defined total number of banks
    else if ( nBanks != nHorizontalBanks * nVerticalBanks ) {
        std::string exceptionMsgThrown("[ERROR] ");
        exceptionMsgThrown.append("Total number of banks does not match with ");
        exceptionMsgThrown.append("the number of banks in both directions.");
        throw exceptionMsgThrown;
    }
}

void
Channel::channelLenghtCalc()
{
    channelWidth = nHorizontalBanks * bankWidth;

    channelHeight = nVerticalBanks * bankHeight
                    + 1.0 * DQDriverHeight;
    // Add TSV area if is 3D design
    if ( is3D ) {
        channelHeight = channelHeight + 1.0 * TSVHeight;
    }
}


void
Channel::channelAreaCalc()
{
    channelArea =  SCALE_QUANTITY(channelWidth, drs::millimeter_unit)
                   * SCALE_QUANTITY(channelHeight, drs::millimeter_unit);
}

void
Channel::channelCompute()
{
    channelStorageCalc();

    try {
        channelBanksPlacementAssess();
        channelLenghtCalc();
    }catch (string exceptionMsgThrown){
        throw exceptionMsgThrown;
    }

    channelAreaCalc();
}
