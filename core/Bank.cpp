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



#include "Bank.h"

void
Bank::bankInitialize()
{
  bankStorage = 0*drs::bit_per_bank;
  bankWidth = 0*drs::micrometer_per_bank;
  bankHeight = 0*drs::micrometer_per_bank;

  effectivePageStorage = 0*drs::bits_per_bank;
  nBankLogicalRows = 0;
  nRowAddressLines = 0;
  nBankLogicalColumns = 0;
  nColumnAddressLines = 0;

}

void
Bank::bankStorageCalc()
{
  bankStorage =  SCALE_QUANTITY(channelSize, drs::bit_unit) / nBanks;
}

void
Bank::bankTilesPlacementAssess()
{
  if ( isPowerOfTwo(nTilesPerBank.value()) == false ) {
      std::string exceptionMsgThrown("[ERROR] ");
      exceptionMsgThrown.append("Total number of tiles per bank ");
      exceptionMsgThrown.append("must be a power of two.");
      throw exceptionMsgThrown;
  }

  // Defining default tiles placement on bank
  nVerticalTiles = pow(2, floor(log(nTilesPerBank.value())/log(4.0)) ) * drs::tiles_per_bank;
  nHorizontalTiles = nTilesPerBank / nVerticalTiles * drs::tiles_per_bank;

}

void
Bank::bankLenghtCalc()
{
  bankWidth = nHorizontalTiles * tileWidth;

  bankHeight = nVerticalTiles * tileHeight
               + 1.0 * DQDriverHeight / drs::bank;

}

void
Bank::bankLogicAssess()
{

  effectivePageStorage = (SCALE_QUANTITY(pageStorage, drs::bit_per_page_unit)
                          * nTilesPerBank
                          * pageSpanningFactor
                          );
  // Number of (addressable) rows in a bank
  nBankLogicalRows = bankStorage
                     / effectivePageStorage;
  nRowAddressLines = ceil(log2(nBankLogicalRows));

  // Number of (addressable) columns in a bank
  nBankLogicalColumns = 1.0*drs::bank
                         * effectivePageStorage / interface;
  nColumnAddressLines = ceil(log2(nBankLogicalColumns));
}

void
Bank::bankCompute()
{
  bankStorageCalc();
  try{
      bankTilesPlacementAssess();
  } catch(string exceptionMsgThrown) {
      throw exceptionMsgThrown;
  }
  bankLenghtCalc();
  bankLogicAssess();
}
