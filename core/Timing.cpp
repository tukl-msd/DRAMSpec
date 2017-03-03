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
 *    documentation and/or other materials provided with the distributio
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permissio
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

#include "Timing.h"
#include <math.h>
#include <iostream>
#include <fstream>

void
Timing::timingInitialize()
{
    cellDelay = 0*drs::nanoseconds;

    localWordlineResistance = 0*drs::ohms_per_subarray;
    localWordlineCapacitance = 0*drs::nanofarads_per_subarray;
    localWordlineDelay = 0*drs::nanoseconds;

    localBitlineResistance = 0*drs::ohms_per_subarray;
    localBitlineCapacitance = 0*drs::nanofarads_per_subarray;
    localBitlineDelay = 0*drs::nanoseconds;

    globalWordlineResistance = 0*drs::ohms_per_tile;
    globalWordlineCapacitance = 0*drs::nanofarads_per_tile;
    globalWordlineDelay = 0*drs::nanoseconds;

    trcd = 0*drs::nanoseconds;

    tcsl = 0*drs::nanoseconds;

    globalDatalineResistance = 0*drs::ohms_per_bank;
    globalDatalineCapacitance = 0*drs::nanofarads_per_bank;
    tgdl = 0*drs::nanoseconds;

    DQWireLength = 0*drs::millimeters;
    bankWidthFactor = 0*drs::kibibytes_per_page;
    DQWireResistance = 0*si::ohms;
    DQWireCapacitance = 0*drs::nanofarads;
    tdq = 0*drs::nanoseconds;

    tcas = 0*drs::nanoseconds;

    trtp = 0*drs::nanoseconds;

    tccd = 0*drs::nanoseconds;

    tras = 0*drs::nanoseconds;

    twr = 0*drs::nanoseconds;

    trp = 0*drs::nanoseconds;

    trc = 0*drs::nanoseconds;

    trfc = 0*drs::nanoseconds;

    tref1 = 0*drs::nanoseconds;

    maxCoreFreq = 0*drs::megahertz_clock;
    actualCoreFreq = 0*drs::megahertz_clock;

    clk = 0*drs::nanoseconds_per_clock;
    actualClk = 0*drs::nanoseconds_per_clock;

    trcd_clk = 0*drs::clocks;
    tcas_clk = 0*drs::clocks;
    tcas_actualClk = 0*drs::clocks;
    tras_clk = 0*drs::clocks;
    trp_clk = 0*drs::clocks;
    trc_clk = 0*drs::clocks;
    trl_clk = 0*drs::clocks;
    trl_actualClk = 0*drs::clocks;
    twl_clk = 0*drs::clocks;
    trtp_clk = 0*drs::clocks;
    tccd_clk = 0*drs::clocks;
    tccd_actualClk = 0*drs::clocks;
    twr_clk = 0*drs::clocks;
    trfc_clk = 0*drs::clocks;
    tref1_clk = 0*drs::clocks;
}

double
Timing::timeToPercentage(double percentage)
{
    return -log(1.0 - percentage/100.0);
}

void
Timing::trcdCalc()
{
    // Trcd is divided as following:
    // the first part is for wordline driver delay estimated as 2 ns
    // the second part is the delay throught the local wordline and
    // local bitline and delay coming from cell itself
    // the 3rd part is the delay of the ssa and is estimated to 2 ns
    // calculating tau for wl
    // calculating wordline total resistance ( value in Ohm )
    // local wordline resistance equals resistance of local wordline driver+
    // resistance of cells in wordline direction

    // Calculating tau for cell celltau ( in ns )
    cellDelay = timeToPercentage(90)
              * SCALE_QUANTITY(capacitancePerCell, drs::nanofarad_per_cell_unit)
              * resistancePerCell
              * drs::cell * drs::cell;

    localWordlineResistance = LWLDriverResistance
                              + (cellsPerLWL *  resistancePerWLCell);

    // Calculating wordline total capacitance ( value in ff)
    localWordlineCapacitance = cellsPerLWL
            * SCALE_QUANTITY(capacitancePerWLCell, drs::nanofarad_per_cell_unit);

    // Calculating wltau( in ns )
    localWordlineDelay = timeToPercentage(90)
            * localWordlineCapacitance
            * localWordlineResistance
            * drs::subarray * drs::subarray;

    // Calculating bitline total resistance
    localBitlineResistance = cellsPerLBL * resistancePerBLCell;

    // Calculating bitline total capacitance
    localBitlineCapacitance = cellsPerLBL
          * SCALE_QUANTITY(capacitancePerBLCell, drs::nanofarad_per_cell_unit);

    // Calculating the bltau( in ns )
    // for timing of bitline, the voltage should reach 90% of the value
    // or else the BLSA can kipp to the wrong value => tau*2.3
    localBitlineDelay = timeToPercentage(90)
            * localBitlineResistance * drs::subarray
            * localBitlineCapacitance * drs::subarray;

    //calculating GWL decoder + wiring femtofarad_per_bank_unitdelay
    //calculating global wordline total capa in fF
    globalWordlineResistance = wireResistance
           * SCALE_QUANTITY(tileWidth, drs::millimeter_per_tile_unit);

    globalWordlineCapacitance = SCALE_QUANTITY(wireCapacitance, drs::nanofarad_per_millimeter_unit)
           * SCALE_QUANTITY(tileWidth, drs::millimeter_per_tile_unit);

    // Calculating delay through global wordline driver and wiring
    globalWordlineDelay = driverOffset +
            timeToPercentage(90) * GWLDriverResistance * globalWordlineCapacitance * drs::tile +
            timeToPercentage(63) * globalWordlineResistance * drs::tile * globalWordlineCapacitance * drs::tile;
    
    // Calculating trcd
    trcd = globalWordlineDelay + localWordlineDelay + cellDelay + localBitlineDelay + SSADelay;

}

void
Timing::trasCalc()
{
//     tras is divided into 4 parts: trcd + tCAS + time for precharging
//     SSA(~2ns) + time needed to restore the bits into the cells
//     (tau bitline)

//     Calculating tCAS:
//     tCAS has delay from CSL driver + Wire ,Local Dataline driver
//     + wire (~1 ns ), Global Data line driver + wire, Delay from
//     SSA to Dataqueue(DQ)


    CSLResistance = SCALE_QUANTITY(bankHeight, drs::millimeter_per_bank_unit)
                      * wireResistance;

    CSLCapacitance = SCALE_QUANTITY(bankHeight, drs::millimeter_per_bank_unit)
                      * SCALE_QUANTITY(wireCapacitance, drs::nanofarad_per_millimeter_unit)
                     + SCALE_QUANTITY(CSLLoadCapacitance, drs::nanofarad_per_bank_unit);

    // delay through CSL
    tcsl = driverOffset
           + timeToPercentage(90) * CSLDriverResistance
            * CSLCapacitance * drs::bank
           + timeToPercentage(63) * CSLResistance
            * CSLCapacitance * drs::bank * drs::bank;



    globalDatalineResistance = SCALE_QUANTITY(bankHeight, drs::millimeter_per_bank_unit)
                      * wireResistance;

    globalDatalineCapacitance = SCALE_QUANTITY(bankHeight, drs::millimeter_per_bank_unit)
                      * SCALE_QUANTITY(wireCapacitance, drs::nanofarad_per_millimeter_unit);

    // delay through global dataline
    tgdl = driverOffset
           + timeToPercentage(90) * GDLDriverResistance
             * globalDatalineCapacitance * drs::bank
           + timeToPercentage(63) * globalDatalineResistance
             * globalDatalineCapacitance * drs::bank * drs::bank;


    // Delay from SSA to DQ//assume wire length = 5mm
    // the length of the DQ wire depends on the width of the bank
    // Factor which defines the rowbuffer*subarray2rowbuffer relation
    bankWidthFactor = pageStorage * subArrayToPageFactor;

    // Currently we assume 5 mm taken from a DDR3 ( 8 banks config)
    // when the number of banks increases this distance from bank to
    // DQ should increas. We do not model this yet due to lack of input.
    // This should be changed in the future.
    std::string exceptionMsgThrown;
    if (ThreeD == "ON") {
        DQWireLength = 1 * drs::millimeters;
    } else {
        if (bankWidthFactor < 0.5 * drs::kibibytes_per_page) {
            DQWireLength = 5 * drs::millimeters;

            exceptionMsgThrown.append("[WARNING] ");
            exceptionMsgThrown.append("Your ");
            exceptionMsgThrown.append("pageSize * subArrayToPageFactor ");
            exceptionMsgThrown.append("is too small!!\n");
        }
        else if(bankWidthFactor == 0.5 * drs::kibibytes_per_page) {
            DQWireLength = 2 * drs::millimeters;
        } else if (bankWidthFactor == 1 * drs::kibibytes_per_page) {
            DQWireLength = 3 * drs::millimeters;
        } else if (bankWidthFactor == 2 * drs::kibibytes_per_page) {
            DQWireLength = 5 * drs::millimeters;
        } else if(bankWidthFactor == 4 * drs::kibibytes_per_page) {
            DQWireLength = 7 * drs::millimeters;
        } else if(bankWidthFactor == 8 * drs::kibibytes_per_page) {
            DQWireLength = 9 * drs::millimeters;
        } else if (bankWidthFactor > 8 * drs::kibibytes_per_page) {
            DQWireLength = 5 * drs::millimeters;

            exceptionMsgThrown.append("[WARNING] ");
            exceptionMsgThrown.append("Your ");
            exceptionMsgThrown.append("pageSize * subArrayToPageFactor ");
            exceptionMsgThrown.append("is too big!!\n");
        } else {
            exceptionMsgThrown.append("[ERROR] ");
            exceptionMsgThrown.append("Unexpected behaviour!!\n");
            exceptionMsgThrown.append("Could not define the length of DQ wire!");
        }
    }

    DQWireResistance = DQWireLength * wireResistance;

    DQWireCapacitance = DQWireLength
                      * SCALE_QUANTITY(wireCapacitance, drs::nanofarad_per_millimeter_unit);

    // delay through global dataline
    tdq = driverOffset
           + timeToPercentage(90) * DQDriverResistance
             * DQWireCapacitance
           + timeToPercentage(63) * DQWireResistance
             * DQWireCapacitance;
    
    // Calculating tcl:
    // command decoding latency (consider for now 2ns) +
    // ( readout-sensing of SSA ) + tDQ + 1 ns (interface delay)
    tcas = cmdDecoderLatency + tcsl + interfaceLatency
          + tgdl + SSADelay + tdq + IODelay;
    
    // Calculating trtp:
    // read to precharge
    // trtp is tCSL + tGDL + delay for sense amps.
    // This is the point in time where precharging is allowed
    // std::cout<<"bltau"<<bltau<<std::endl;
    // std::cout<<"tCSL"<<tCSL<<std::endl;
    // remove the command decoding latency
    trtp = tcsl + tgdl + SSADelay;
    
    // Calculating tccd:
    // tccd ( column to column delay) is equal time to select another CSL
    //  + precharging secondary SSA + Global Dataline delay...
    // - 0.5(delay of CSL driver isnot in the critical path)
    tccd = tcsl + SSAPrechargeDelay + tgdl - driverOffset;
    
    // Calculating tras:
//    tras = trcd + tcas + bitlineDelay - tdq - 1; TODO - Discuss with Christian about this timing!!!!
    // From Matthias thesis pg. 20 Fig. 2.5: Basic DRAM protocol -> tras = trcd + tccd + trtp
    tras = trcd + tccd + trtp;

    // Calculating twr + 2 (command decoding) + 1 (security margin):
    twr = cmdDecoderLatency + localBitlineDelay + tgdl + securityMargin;

    if ( !exceptionMsgThrown.empty() ) {
     throw exceptionMsgThrown;
    }
}

void
Timing::trpCalc()
{
    //calculating trp
    //trp = Master wordline delay ( discharging ) + local wordline delay
    // (discharging ) + 1 ns ( equalizer delay )
    trp =  localWordlineDelay + localBitlineDelay + equalizerDelay;
}

void
Timing::trcCalc()
{
    //calculating trc
    trc = tras + trp;
}

void
Timing::trfcCalc()
{
    //time for refresh cycle
    //numberofbanks refreshed*(5(Act cmd delay ) +
    // 5(pre cmd delay)) + 10 ns (offset)) + trc
    if (ThreeD == "ON") {
////      [ns]           [??]              [??/bank]
//        trfc = rowRefreshRate * banksRefreshFactor
////                     [bank]           []         [] []
//                * nBanks/vaultsPerLayer*(5+5)
////               [ns]   [ns]
//                + 10  + trc;
    } else {
//        !!!!!! CHECK RELATION BETWEEN nBanks AND banksRefreshFactor !!!!!!
        trfc = nBanks/drs::banks * banksRefreshFactor
               * (actCmdDelay + preCmdDelay)
               + offset  + trc;
    }
}

void
Timing::tref1Calc()
{
    //time for average refresh period
    //number of rows
    //number of rows = (DRAM SIZE/#ofbanks) / rowbuffer
//     !!!! [page/bank] !!!!
    double numberofrows = SCALE_QUANTITY(dramSize, drs::kibibyte_unit)
                        / nBanks
                        / pageStorage
                        *drs::bank / drs::page; // !!! Check dimension mismatch !!!

//   [ns]    !!!! [??] !!!!            [ms]        [page/bank]
    tref1 = banksRefreshFactor
            * SCALE_QUANTITY(retentionTime, drs::nanosecond_unit)
            / numberofrows;
}

void
Timing::clkTiming()
{

   maxCoreFreq = drs::clock / SCALE_QUANTITY(tccd, drs::microsecond_unit);

    // if we specified a core Freq then take the value else calculate it
    if (dramCoreFreq != 0*drs::megahertz_clock) {
        actualCoreFreq = dramCoreFreq;
    }
    else {
        if (dramType == "DDR") {
            clockFactor = 2;
        } else {
            clockFactor = 1;
        }

        actualCoreFreq = dramFreq / (Prefetch / clockFactor);
    }

    clk = 1.0 / SCALE_QUANTITY(dramFreq, drs::gigahertz_clock_unit);
    actualClk = 1.0 / SCALE_QUANTITY(actualCoreFreq, drs::gigahertz_clock_unit);

    //trcd in clk cycles round-up
    trcd_clk = ceil(trcd/clk);

    //tcl in clk cycles
    tcas_clk = ceil(tcas/clk);

    //tcl_act in clk cycles
    tcas_actualClk = ceil(tcas/actualClk);

    //tras in clk cycles
    tras_clk = ceil(tras/clk);

    //trp in clk cycles
    trp_clk = ceil(trp/clk);

    //trc in clk cycles
    trc_clk = ceil(trc/clk);
    
    //trl in clk cycles
    //tal is additional latency defined in tech. parameter
    trl_clk = ceil(tcas/clk);
    trl_clk += additionalLatencyTrl;

    //trl_act in clk cycles
    //tal is additional latency defined in tech. parameter
    trl_actualClk = ceil(tcas/actualClk);
    trl_actualClk +=  additionalLatencyTrl;

    //twl in clk cycles
    twl_clk = trl_clk - 1*drs::clock;

    //trtp in clk cycles
    trtp_clk = ceil(trtp/clk);

    //tccd in clk cycles
    tccd_clk = ceil(tccd/clk);

    //tccd_act in clk cycles
    tccd_actualClk = ceil(tccd/actualClk);

    //twr in clk cycles
    twr_clk = ceil(twr/clk);

    //trfc in clk cycles
    trfc_clk = ceil(trfc/clk);
    
    //tref1 in clk cycles
    tref1_clk = ceil(tref1/clk);

    // If frequency is too high, do all calculations anyway but warn the user
    if( actualCoreFreq > maxCoreFreq ) {
        std::string exceptionMsgThrown("[WARNING] ");
        exceptionMsgThrown.append("Specified frequency ");
        exceptionMsgThrown.append("too high for DRAM Desing. ");
        exceptionMsgThrown.append("Go Down with Frequency!!\n");
        exceptionMsgThrown.append("If user wants to keep the high frequency, ");
        exceptionMsgThrown.append("try using a smaller bank or a higher ");
        exceptionMsgThrown.append("subarray2rowbufferfactor\n");
        throw exceptionMsgThrown;
    }

}

void
Timing::timingCompute()
{
    trcdCalc();

    trasCalc();

    trpCalc();

    trcCalc();

    trfcCalc();

    tref1Calc();

    try {
        clkTiming();
    }catch (std::string exceptionMsgThrown){
        throw exceptionMsgThrown;
    }
}

void
Timing::printTiming()
{
    //print analog timings
    std::cout << "Timing Parameters in ns"      << "\n";
    std::cout << "trcd"     << "\t" << trcd     << ".\n";
    std::cout << "tcl"      << "\t" << tcas     << ".\n";
    std::cout << "trtp"     << "\t" << trtp     << ".\n";
    std::cout << "tccd"     << "\t" << tccd     << ".\n";
    std::cout << "tras"     << "\t" << tras     << ".\n";
    std::cout << "twr"      << "\t" << twr      << "\n" ;
    std::cout << "trp"      << "\t" << trp      << ".\n";
    std::cout << "trc"      << "\t" << trc      << ".\n";
    std::cout << "trfc"     << "\t" << trfc     << "\n";
    std::cout << "tref1"    << "\t" << tref1    << "\n";
}
