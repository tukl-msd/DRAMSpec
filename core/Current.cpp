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



#include "Current.h"
#include <math.h>
#include <iostream>
#include <fstream>

void
Current::currentInitialize()
{
    // TODO: Find appropriate var. names and whether it should or not be an user input
    IDD2nPercentageIfNotDll = 0.6;
    vppPumpsEfficiency = 0.3;
    currentPerPageSizeSlope = 2.0*drs::milliamperes_page_per_kibibyte;
    SSAActiveTime = 1.5*drs::nanoseconds;
    bitProCSL = 8 * drs::bits;

    // Intermediate values added as variables for code cleanness
    nActiveSubarrays = 0;
    nLocalBitlines = 0;
    IDD0TotalCharge = 0*drs::nanocoulomb;
    effectiveTrc = 0*drs::nanosecond;
    IDD0ChargingCurrent = 0*si::amperes;
    IDD1TotalCharge = 0*drs::nanocoulomb;
    IDD1ChargingCurrent = 0*si::amperes;
    IDD4TotalCharge = 0*drs::nanocoulomb;
    ioTermRdCurrent = 0*drs::milliamperes;
    IDD4ChargingCurrent = 0*si::amperes;
    ioTermWrCurrent = 0*drs::milliamperes;
    refreshCharge = 0*drs::nanocoulomb;
    effectiveTrfc = 0*drs::nanosecond;
    IDD5ChargingCurrent = 0*si::amperes;
    nRowActivations = 0;

    // Main variables
    IDD0 = 0*drs::milliamperes;
    IDD1 = 0*drs::milliamperes;
    IDD4R = 0*drs::milliamperes;
    IDD4W = 0*drs::milliamperes;
    IDD2n = 0*drs::milliamperes;
    IDD3n = 0*drs::milliamperes;
    IDD5 = 0*drs::milliamperes;

    masterWordlineCharge = 0*drs::nanocoulomb;
    localWordlineCharge = 0*drs::nanocoulomb;
    localBitlineCharge = 0*drs::nanocoulomb;
    nLDQs = 0*drs::bits;
    SSACharge = 0*drs::nanocoulomb;
    nCSLs = 0;
    CSLCharge = 0*drs::nanocoulomb;
    masterDatalineCharge = 0*drs::nanocoulomb;
    DQWireCharge = 0*drs::nanocoulomb;
    readingCharge = 0*drs::nanocoulomb;

    includeIOTerminationCurrent = false;
}

// Background current calculation
void
Current::backgroundCurrentCalc()
{
    // Precharge background current (scaling with Freq)
    IDD2n = backgroundCurrentSlope * dramFreq
            + backgroundCurrentOffset;

    if ( !isDLL ) {
        IDD2n = IDD2nPercentageIfNotDll * IDD2n;
    }

    // Active background current:
    // IDD3n is equal to IDD2n + active-adder
    // Assumption : active-adder current = 4mA for 2K page
    // and changes linearly while changing page size
    IDD3n = IDD2n + currentPerPageSizeSlope * pageStorage;

}

void
Current::IDD0Calc()
{
    //   !!! CHECK !!!
    // Number of active subarrays
    //    [subarray / page] ???
    nActiveSubarrays =
            SCALE_QUANTITY(pageStorage, drs::bit_per_page_unit) * 1.0*drs::page
            / ( subArrayRowStorage * 1.0*drs::subarray );

    // Charge of master wordline
    masterWordlineCharge = globalWordlineCapacitance * 1.0*drs::tile
                           *  vpp / vppPumpsEfficiency;

    // Charge of local wordline
    localWordlineCharge = localWordlineCapacitance * 1.0*drs::subarray
                          * vpp
                          * nActiveSubarrays
                          / vppPumpsEfficiency ;

    //charge of local bitline
    nLocalBitlines = SCALE_QUANTITY(pageStorage, drs::bit_per_page_unit)*drs::page/drs::bit;
    localBitlineCharge = localBitlineCapacitance * 1.0*drs::subarray
                         * vdd / 2.0 // <<-- WHY DIVIDED BY 2??
                         * nLocalBitlines;

    rowAddrsLinesCharge =
            SCALE_QUANTITY(wireCapacitance, drs::nanofarad_per_millimeter_unit)
            * SCALE_QUANTITY(tileHeight, drs::millimeter_per_tile_unit)
            * nTilesPerBank * 1.0*drs::bank
            * nTileRowAddressLines
            * vdd;

    IDD0TotalCharge = ( masterWordlineCharge
                      + localWordlineCharge
                      + localBitlineCharge
                      + rowAddrsLinesCharge)
                            * 2.0 ; // !! Why times 2? Maybe number of tiles?

    // Clock cycles of trc in ns
    effectiveTrc = trc_clk * clkPeriod;
    // Current caused by charging and discharging of capas in mA
    IDD0ChargingCurrent = IDD0TotalCharge / effectiveTrc;

    IDD0 = IDD3n
           + SCALE_QUANTITY(IDD0ChargingCurrent, drs::milliampere_unit);

}

void
Current::IDD1Calc()
{

    nLDQs = interface * prefetch;

    // Charges of SSA
    SSACharge = nLDQs
                * SCALE_QUANTITY(Issa, drs::ampere_per_bit_unit)
                * SSAActiveTime;

    // nCSLs includes CSLEN and !CSLEN lines (+ 2),
    //  and we consider they have the same capacitance as CSLs.
    nCSLs = nSubArraysPerArrayBlock * nHorizontalTiles * 1.0*drs::bank/drs::subarrays + 2.0;
    CSLCharge = CSLCapacitance * 1.0*drs::bank
                * vdd
                * nCSLs;

    // Charge of global Dataline
    masterDatalineCharge = globalDatalineCapacitance * 1.0*drs::bank
                           * vdd
                           * interface
                           * prefetch
                            / drs::bit; // TODO: remove the work around

    // Charges for Dataqueue // 1 Read is done for interface x prefetch
    DQWireCharge = DQWireCapacitance
                   * vdd
                   * interface
                   * prefetch
                    / drs::bit; // TODO: remove the work around

    // read charges in pC
    readingCharge = SSACharge
                    + 2.0*CSLCharge // !! Why times 2? Maybe number of tiles?
                    + 2.0*masterDatalineCharge // !! Why times 2? Maybe number of tiles?
                    + DQWireCharge;
    IDD1TotalCharge = (masterWordlineCharge
                       + localWordlineCharge
                       + localBitlineCharge
                       + readingCharge)
                            * 2.0; // !! Why times 2? Maybe number of tiles?

    IDD1ChargingCurrent = IDD1TotalCharge / effectiveTrc;

    IDD1 = IDD3n
           + SCALE_QUANTITY(IDD1ChargingCurrent, drs::milliampere_unit);

}

void
Current::IDD4RCalc()
{
    // Scale the IDD_OCD_RCV with frequency linearly
    IddOcdRcv = IddOcdRcvSlope * dramFreq / drs::bit;

    colAddrsLinesCharge =
            SCALE_QUANTITY(wireCapacitance, drs::nanofarad_per_millimeter_unit)
            * SCALE_QUANTITY(tileWidth, drs::millimeter_per_tile_unit)
            * nTilesPerBank * 1.0*drs::bank
            * nTileColumnAddressLines
            * vdd;

    IDD4TotalCharge = readingCharge + colAddrsLinesCharge;
    // Number of output signals for read = interface number
    // + 1 datastrobe signal pro 4 bits
    if (includeIOTerminationCurrent) {
       ioTermRdCurrent = (interface + interface/4.0)
                         * SCALE_QUANTITY(IddOcdRcv, drs::milliampere_per_bit_unit);
    }
    else {
       ioTermRdCurrent = 0*drs::milliamperes;
    }

    IDD4ChargingCurrent = IDD4TotalCharge
                          * SCALE_QUANTITY(dramCoreFreq, drs::gigahertz_clock_unit)
                          / (1.0*drs::clock);

    IDD4R = IDD3n
            + ioTermRdCurrent
            + SCALE_QUANTITY(IDD4ChargingCurrent, drs::milliampere_unit);

}

void
Current::IDD4WCalc()
{
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! //
    // !!!! TODO: DISCUSS THESE VALUES WITH CHRISTIAN IN FURTHER MEETINGS !!!! //
    //number of signals for write is number of signals for read
    //+ 1 extra signal for rcv per 8 bits
    int rcvconst;
    if(interface/8.0 < 1*drs::bit) {
        rcvconst = 1 ;
    } else {
        rcvconst = 0 ;
    }
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! //

    //additional IO term current for Writes
    if (includeIOTerminationCurrent) {
        ioTermWrCurrent = (interface/8.0 + rcvconst*drs::bit)
                          * SCALE_QUANTITY(IddOcdRcv, drs::milliampere_per_bit_unit);
    }
    else {
        ioTermWrCurrent = 0*drs::milliamperes;
    }

    IDD4W = IDD4R + ioTermWrCurrent;

}

void
Current::IDD5Calc()
{
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! //
    // !!!! TODO: DISCUSS THESE VALUES WITH CHRISTIAN IN FURTHER MEETINGS !!!! //
    // Charges for refresh
    // Charges of IDD0 x 2 ( 2 rows pro command)x # of banksrefreshed pro
    // x # of rows pro command
    refreshCharge = ( masterWordlineCharge
                      + localWordlineCharge    // <- Should't it be IDD0ChargingCurrent?
                      + localBitlineCharge )
                    * 2.0
                    * 2.0
                    * banksRefreshFactor
                    * nBanks / (1.0*drs::bank);
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! //

    // Refresh current
    effectiveTrfc = trfc_clk * clkPeriod;

    IDD5ChargingCurrent = refreshCharge / effectiveTrfc;

    IDD5 = IDD3n
           + SCALE_QUANTITY(IDD5ChargingCurrent, drs::milliampere_unit);

    // Checking the current for the required refresh period
    // Calculate the number of times each row if refreshed in 64 ms
    // retention time
    nRowActivations = SCALE_QUANTITY(trefI, drs::microsecond_unit)
                    / requiredTrefI;


}

void
Current::currentCompute()
{
    backgroundCurrentCalc();
    IDD0Calc();
    IDD1Calc();
    IDD4RCalc();
    IDD4WCalc();
    IDD5Calc();
}
