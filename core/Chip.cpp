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

#include "Chip.h"


void
Chip::chipInitialize()
{
    chipStorage = 0*drs::gibibit;
    chipWidth = 0*drs::micrometer;
    chipHeight = 0*drs::micrometer;
    chipArea = 0*drs::square_millimeter;
}

void
Chip::chipStorageCalc()
{
    chipStorage = dramSize;
}

void
Chip::chipLenghtCalc()
{

    if ( nBanks == 1.0*drs::bank ) {
        chipWidth = 1.0 * bankWidth * drs::bank
                    + 0.0 * bankSpacingWidth;

        chipHeight = 1.0 * bankHeight * drs::bank
                     + 1.0 * DQDriverHeight;
    }

    else if ( nBanks == 2.0*drs::bank ) {
        chipWidth = 2.0 * bankWidth * drs::bank
                    + 1.0 * bankSpacingWidth;

        chipHeight = 1.0 * bankHeight * drs::bank
                     + 1.0 * DQDriverHeight;
    }

    else if ( nBanks == 4.0*drs::bank ) {
        chipWidth = 2.0 * bankWidth * drs::bank
                    + 1.0 * bankSpacingWidth;

        chipHeight = 2.0 * bankHeight * drs::bank
                     + 1.0 * DQDriverHeight;
    }

    else if ( nBanks == 6.0*drs::bank ) {
        chipWidth = 3.0 * bankWidth * drs::bank
                    + 2.0 * bankSpacingWidth;

        chipHeight = 2.0 * bankHeight * drs::bank
                     + 1.0 * DQDriverHeight;
    }

    else if ( nBanks == 8.0*drs::bank ) {
        chipWidth = 4.0 * bankWidth * drs::bank
                    + 3.0 * bankSpacingWidth;

        chipHeight = 2.0 * bankHeight * drs::bank
                     + 1.0 * DQDriverHeight;
    }

    else {
        std::string exceptionMsgThrown("[ERROR] Architecture must have ");
        exceptionMsgThrown.append("1, 2, 4, 6 or 8 banks.");
        throw exceptionMsgThrown;
    }
}


void
Chip::chipAreaCalc()
{
    chipArea =  SCALE_QUANTITY(chipWidth, drs::millimeter_unit)
                * SCALE_QUANTITY(chipHeight, drs::millimeter_unit);
}

void
Chip::chipCompute()
{
    chipStorageCalc();

    chipLenghtCalc();

    chipAreaCalc();
}
