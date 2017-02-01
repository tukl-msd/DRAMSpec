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

#include "Bank.h"

void
Bank::bankStorageCalc()
{
    bankStorage =  SCALE_QUANTITY(dramSize, drs::bit_unit) / nBanks;
}

void
Bank::bankLenghtCalc()
{

    if ( tilesPerBank == 1*drs::tiles_per_bank ) {
        bankWidth = 1.0 * tileWidth * drs::tile_per_bank
                    + 1.0 * rowDecoderWidth / drs::bank;

        bankHeight = 1.0 * tileHeight * drs::tile_per_bank
                     + 1.0 * colDecoderHeight / drs::bank;
    }

    else if ( tilesPerBank == 2*drs::tiles_per_bank ) {
        bankWidth = tileWidth * 2.0 * drs::tile_per_bank
                     + 2.0 * rowDecoderWidth / drs::bank;

        bankHeight = tileHeight * 1.0 * drs::tile_per_bank
                     + 1.0 * colDecoderHeight / drs::bank;
    }

    else if ( tilesPerBank == 4*drs::tiles_per_bank ) {
        bankWidth = tileWidth * 2.0 * drs::tile_per_bank
                     + 2.0 * rowDecoderWidth / drs::bank;

        bankHeight = tileHeight * 2.0 * drs::tile_per_bank
                     + 2.0 * colDecoderHeight / drs::bank;
    }

}

void
Bank::bankInitialize()
{
    bankStorageCalc();

    bankLenghtCalc();
}
