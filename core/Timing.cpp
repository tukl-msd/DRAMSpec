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



#include "Timing.h"
#include <math.h>
#include <iostream>
#include <fstream>

void
Timing::timingInitialize()
{

    cellDelay = 0*drs::nanoseconds;

    localWordlineResistance = 0*drs::ohms;
    localWordlineCapacitance = 0*drs::nanofarads;
    localWordlineDelay = 0*drs::nanoseconds;

    localBitlineResistance = 0*drs::ohms;
    localBitlineCapacitance = 0*drs::nanofarads;
    localBitlineDelay = 0*drs::nanoseconds;

    globalWordlineResistance = 0*drs::ohms;
    globalWordlineCapacitance = 0*drs::nanofarads;
    globalWordlineDelay = 0*drs::nanoseconds;

    trcd = 0*drs::nanoseconds;

    tcsl = 0*drs::nanoseconds;

    globalDatalineResistance = 0*drs::ohms;
    globalDatalineCapacitance = 0*drs::nanofarads;
    tgdl = 0*drs::nanoseconds;

    DQWireLength = 0*drs::micrometers;
    DQWireResistance = 0*si::ohms;
    DQWireCapacitance = 0*drs::nanofarads;
    tdq = 0*drs::nanoseconds;

    tcas = 0*drs::nanoseconds;

    trl = 0*drs::nanoseconds;

    trtp = 0*drs::nanoseconds;

    tccd = 0*drs::nanoseconds;

    tras = 0*drs::nanoseconds;

    twr = 0*drs::nanoseconds;

    trp = 0*drs::nanoseconds;

    trc = 0*drs::nanoseconds;

    trefI = 0*drs::nanoseconds;

    nRowsRefreshedPerARCmd = 0;
    trfc = 0*drs::nanoseconds;

    maxCoreFreq = 0*drs::megahertz_clock;
    dramCoreFreq = 0*drs::megahertz_clock;

    clkPeriod = 0*drs::nanoseconds_per_clock;
    coreClkPeriod = 0*drs::nanoseconds_per_clock;

    trcd_clk = 0*drs::clocks;
    tcas_clk = 0*drs::clocks;
    tcas_coreClk = 0*drs::clocks;
    tras_clk = 0*drs::clocks;
    trp_clk = 0*drs::clocks;
    trc_clk = 0*drs::clocks;
    trl_clk = 0*drs::clocks;
    trl_coreClk = 0*drs::clocks;
    twl_clk = 0*drs::clocks;
    trtp_clk = 0*drs::clocks;
    tccd_clk = 0*drs::clocks;
    tccd_coreClk = 0*drs::clocks;
    twr_clk = 0*drs::clocks;
    trfc_clk = 0*drs::clocks;
    trefI_clk = 0*drs::clocks;

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
              * SCALE_QUANTITY(capacitancePerCell, drs::nanofarad_unit)
              * SCALE_QUANTITY(resistancePerCell, drs::ohm_unit);

    localWordlineResistance = LWLDriverResistance
                              + (cellsPerLWL *  resistancePerWLCell);

    // Calculating wordline total capacitance
    localWordlineCapacitance = cellsPerLWL
            * SCALE_QUANTITY(capacitancePerWLCell, drs::nanofarad_unit);

    // Calculating wltau( in ns )
    localWordlineDelay = timeToPercentage(90)
            * localWordlineCapacitance
            * localWordlineResistance;

    // Calculating bitline total resistance
    localBitlineResistance = cellsPerLBL * resistancePerBLCell;

    // Calculating bitline total capacitance
    localBitlineCapacitance = cellsPerLBL
          * SCALE_QUANTITY(capacitancePerBLCell, drs::nanofarad_unit);

    // Calculating the bltau( in ns )
    localBitlineDelay = timeToPercentage(90)
            * localBitlineResistance
            * localBitlineCapacitance;


    // TODO: Global word line driving needs re-check!
    //  WLDV signal seems to be the "bottleneck"
    //calculating GWL decoder + wiring delay
    //calculating global wordline total capa
    globalWordlineResistance = wireResistance
           * SCALE_QUANTITY(tileWidth, drs::millimeter_unit);

    globalWordlineCapacitance =
           SCALE_QUANTITY(wireCapacitance, drs::nanofarad_per_millimeter_unit)
           * SCALE_QUANTITY(tileWidth, drs::millimeter_unit);

    // Calculating delay through global wordline driver and wiring
    globalWordlineDelay = driverEnableDelay
        + timeToPercentage(90) * GWLDriverResistance
          * globalWordlineCapacitance
        + timeToPercentage(63) * globalWordlineResistance
          * globalWordlineCapacitance;
    
    // Calculating trcd
    trcd = globalWordlineDelay + localWordlineDelay + cellDelay + localBitlineDelay;

    cellDelay99p = timeToPercentage(99) / timeToPercentage(90)
                   * cellDelay;

    localBitlineDelay99p = timeToPercentage(99) / timeToPercentage(90)
                           * localBitlineDelay;

    ACTtoRefreshCellDelay = globalWordlineDelay + localWordlineDelay
                            + cellDelay + localBitlineDelay99p
                            + cellDelay99p;

}

void
Timing::trasCalc()
{

    CSLResistance = SCALE_QUANTITY(bankHeight, drs::millimeter_unit)
                      * wireResistance;

    CSLCapacitance = SCALE_QUANTITY(bankHeight, drs::millimeter_unit)
                      * SCALE_QUANTITY(wireCapacitance, drs::nanofarad_per_millimeter_unit)
                     + SCALE_QUANTITY(CSLLoadCapacitance, drs::nanofarad_unit);

    // delay through CSL
    tcsl = driverEnableDelay
           + timeToPercentage(90) * CSLDriverResistance
            * CSLCapacitance
           + timeToPercentage(63) * CSLResistance
            * CSLCapacitance;


    globalDatalineResistance = SCALE_QUANTITY(bankHeight, drs::millimeter_unit)
                      * wireResistance;

    globalDatalineCapacitance = SCALE_QUANTITY(bankHeight, drs::millimeter_unit)
                      * SCALE_QUANTITY(wireCapacitance, drs::nanofarad_per_millimeter_unit);

    // delay through global dataline
    tgdl = driverEnableDelay
           + timeToPercentage(90) * GDLDriverResistance
             * globalDatalineCapacitance
           + timeToPercentage(63) * globalDatalineResistance
             * globalDatalineCapacitance;


    // The longest DQ main wire for a non-3D architecture
    //  extends throught the internal edge of the edge banks all the way
    //  to the other side of the channel
    // For a 3D design, it connects to all banks,
    //  from the column decoder and throught the TSV area
    if ( is3D ) {
        DQWireLength = nHorizontalBanks
                            * ( 2.0 * colDecoderHeight + TSVHeight)
                       + (nHorizontalBanks - 1.0)
                            * bankWidth
                       + DQtoTSVWireLength;
    } else {
        DQWireLength = channelWidth - 1.0*bankWidth;
    }

    DQWireResistance = SCALE_QUANTITY(DQWireLength, drs::millimeter_unit)
                        * wireResistance;

    DQWireCapacitance = DQWireLength
                      * SCALE_QUANTITY(wireCapacitance, drs::nanofarad_per_micrometer_unit);

    // delay through global dataline
    tdq = driverEnableDelay
           + timeToPercentage(90) * DQDriverResistance
             * DQWireCapacitance
           + timeToPercentage(63) * DQWireResistance
             * DQWireCapacitance;
    
    // Calculating tccd:
    // CSL driver is already enabled (not in the critical path)
    tccd = tcsl + SSAPrechargeDelay + tgdl - driverEnableDelay;

    // Estimation of signal delay from the input to the output of the SSA
    inOutSSADelay = 1.25 * tccd;

    // Calculating tcl (same as tcas):
    tcas = cmdDecoderDelay + tcsl + tgdl
          + inOutSSADelay + tdq + 2.0 * IODelay;
    
    // Calculating trtp:
    trtp = tcsl + tgdl + inOutSSADelay;
    
    // Calculating tras:
//    tras = trcd + tcas + bitlineDelay - tdq - 1; TODO - Discuss with Christian about this timing!!!!
    // From Matthias thesis pg. 20 Fig. 2.5: Basic DRAM protocol -> tras = trcd + tccd + trtp
    tras = trcd + tccd + trtp; // trcd99p

    // Calculating twr:
    twr = cmdDecoderDelay + localBitlineDelay + tgdl + tWRMargin;

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
Timing::tckCalc()
{
    maxCoreFreq = drs::clock / SCALE_QUANTITY(tccd, drs::microsecond_unit);

     // If not specified, calculate the core freq
     if (dramCoreFreq == 0*drs::megahertz_clock) {
         if (dramType.find("DDR") != string::npos) {
             clockFactor = prefetch / 2;
         } else {
             clockFactor = prefetch;
         }

         dramCoreFreq = dramFreq / clockFactor;
     }

     clkPeriod = 1.0 / SCALE_QUANTITY(dramFreq, drs::gigahertz_clock_unit);
     tck = 1*drs::clock * clkPeriod;
     coreClkPeriod = 1.0 / SCALE_QUANTITY(dramCoreFreq, drs::gigahertz_clock_unit);
     tckCore = 1*drs::clock * coreClkPeriod;
}

void
Timing::trefICalc()
{

    // Normal op temp
    if (temperature > 0*bu::celsius::degrees
         && temperature < 85*bu::celsius::degrees)
    {
      trefI = SCALE_QUANTITY(trefIBase, drs::nanosecond_unit) / refreshMode;
    }
    // Extended op temp
    else if (temperature > 85*bu::celsius::degrees
              && temperature < 95*bu::celsius::degrees)
    {
      trefI = SCALE_QUANTITY(trefIBase, drs::nanosecond_unit) / refreshMode / 2.0;
    }
    // Outside temp range
    else
    {
      std::string exceptionMsgThrown("[ERROR] ");
      exceptionMsgThrown.append("Operating temperature is defined ");
      exceptionMsgThrown.append("only from 0 to 95 degrees Celsius.");
      throw exceptionMsgThrown;
    }

}

void
Timing::trfcCalc()
{
    // Normal op temp
    if (temperature > 0*bu::celsius::degrees
         && temperature < 85*bu::celsius::degrees)
    {
      nRowsRefreshedPerARCmd = ceil(nBanks * nBankLogicalRows
                                * trefI / SCALE_QUANTITY(retentionTime, drs::nanosecond_unit)
                                );
    }
    // Extended op temp
    else if (temperature > 85*bu::celsius::degrees
              && temperature < 95*bu::celsius::degrees)
    {
      nRowsRefreshedPerARCmd = ceil(2.0 * nBanks * nBankLogicalRows
                                * trefI / SCALE_QUANTITY(retentionTime, drs::nanosecond_unit)
                                );
    }
    // Outside temp range
    else
    {
      std::string exceptionMsgThrown("[ERROR] ");
      exceptionMsgThrown.append("Operating temperature is defined ");
      exceptionMsgThrown.append("only from 0 to 95 degrees Celsius.");
      throw exceptionMsgThrown;
    }

    // Assuming ACT-PRE-ACT-PRE... cycles until the needs number of rows are refreshed
    // Based on: Using Run-Time Reverse-Engineering to Optimize DRAM Refresh,
    // D. Mathew, E. Zulian, M. Jung, K. Kraft, C. Weis, B. Jacob, N. Wehn,
    // MEMSYS 2017, New York, USA
    trfc = nRowsRefreshedPerARCmd * 2.0 * tck + ACTtoRefreshCellDelay + trp;

}

void
Timing::clkTiming()
{

    // Calculating trl (delay in ns):
    //additionalLatencyTrl = tal (Added Latency to column accesses)
    trl = tcas + additionalLatencyTrl * clkPeriod;

    //trcd in clk cycles
    trcd_clk = ceil(trcd/clkPeriod);

    //tcl in clk cycles
    tcas_clk = ceil(tcas/clkPeriod);

    //tcl_act in clk cycles
    tcas_coreClk = ceil(tcas/coreClkPeriod);

    //tras in clk cycles
    tras_clk = ceil(tras/clkPeriod);

    //trp in clk cycles
    trp_clk = ceil(trp/clkPeriod);

    //trc in clk cycles
    trc_clk = ceil(trc/clkPeriod);
    
    //trl in clk cycles
    trl_clk = ceil(trl/clkPeriod);

    //trl_act in clk cycles
    trl_coreClk = ceil(trl/coreClkPeriod);

    //twl in clk cycles
    twl_clk = trl_clk - 1*drs::clock;

    //trtp in clk cycles
    trtp_clk = ceil(trtp/clkPeriod);

    //tccd in clk cycles
    tccd_clk = ceil(tccd/clkPeriod);

    //tccd_act in clk cycles
    tccd_coreClk = ceil(tccd/coreClkPeriod);

    //twr in clk cycles
    twr_clk = ceil(twr/clkPeriod);

    //trfc in clk cycles
    trfc_clk = ceil(trfc/clkPeriod);
    
    //trefI in clk cycles
    trefI_clk = ceil(trefI/clkPeriod);

    // If frequency is too high,  warn the user but do all calculations anyway
    if( dramCoreFreq > maxCoreFreq ) {
        warning.append("[WARNING] ");
        warning.append("Specified frequency ");
        warning.append("too high for DRAM Desing. ");
        warning.append("Go Down with Frequency!!\n");
        warning.append("If user wants to keep the high frequency, ");
        warning.append("try using a smaller bank or a higher ");
        warning.append("subarray2rowbufferfactor.\n");
    }

}

void
Timing::timingCompute()
{
    try {
        trcdCalc();
        trasCalc();
        trpCalc();
        trcCalc();
        tckCalc();
        trefICalc();
        trfcCalc();

        clkTiming();
    }catch (std::string exceptionMsgThrown){
        throw exceptionMsgThrown;
    }

}

void
Timing::printTimings()
{

    std::cout << "\nTime variables:\n";
    PRINT_VAR(cellDelay);
    PRINT_VAR(localWordlineDelay);
    PRINT_VAR(localBitlineDelay);
    PRINT_VAR(globalWordlineDelay);
    PRINT_VAR(tcsl);
    PRINT_VAR(tgdl);
    PRINT_VAR(tdq);
    PRINT_VAR(tcas);
    PRINT_VAR(trtp);
    PRINT_VAR(tccd);
    PRINT_VAR(tras);
    PRINT_VAR(twr);
    PRINT_VAR(trp);
    PRINT_VAR(trc);
    PRINT_VAR(trfc);
    PRINT_VAR(trefI);

}
