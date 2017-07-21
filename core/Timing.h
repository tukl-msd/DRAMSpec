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



//In this class the timing specification of DRAMs is done
//The class uses an initialized DRAM Channel to compute the timing specification

#ifndef TIMING_H
#define TIMING_H

#include "Channel.h"

namespace bu=boost::units;
namespace si=boost::units::si;
namespace inf=boost::units::information;
namespace drs=boost::units::dramspec;

class Timing : public Channel
{
  public:
    Timing() : //Empty constructor for test proposes
        Channel()
    {
        timingInitialize();
    }

    Timing(const string& technologyFileName,
           const string& architectureFileName) :
        Channel(technologyFileName, architectureFileName)
    {
        timingInitialize();
        try {
            timingCompute();
        }catch (string exceptionMsgThrown){
            throw exceptionMsgThrown;
        }
    }
  
    //Delay of cell
    bu::quantity<drs::nanosecond_unit> cellDelay;

    //Resistance of local wordline
    bu::quantity<drs::resistance_per_subarray_unit> localWordlineResistance;
    //Capacitace of local wordline
    bu::quantity<drs::nanofarad_per_subarray_unit> localWordlineCapacitance;
    //Delay of local wordline
    bu::quantity<drs::nanosecond_unit> localWordlineDelay;

    //Resistance of local bitline
    bu::quantity<drs::resistance_per_subarray_unit> localBitlineResistance;
    //Capacitace of local bitline
    bu::quantity<drs::nanofarad_per_subarray_unit> localBitlineCapacitance;
    //Delay of local bitline
    bu::quantity<drs::nanosecond_unit> localBitlineDelay;

    //Resistance of global wordline
    bu::quantity<drs::resistance_per_tile_unit> globalWordlineResistance;
    //Capacitace of global wordline
    bu::quantity<drs::nanofarad_per_tile_unit> globalWordlineCapacitance;
    //Delay through global wordline driver and wiring
    bu::quantity<drs::nanosecond_unit> globalWordlineDelay;

    //t_rcd: ACT to internal read or write delay time
    bu::quantity<drs::nanosecond_unit> trcd;

    //Resistance of CSL wire
    bu::quantity<drs::resistance_per_bank_unit> CSLResistance;
    //Capacitace of CSL wire
    bu::quantity<drs::nanofarad_per_bank_unit> CSLCapacitance;
    //Delay through CSL driver and wiring
    bu::quantity<drs::nanosecond_unit> tcsl;

    //Resistance of global dataline wire
    bu::quantity<drs::resistance_per_bank_unit> globalDatalineResistance;
    //Capacitace of global dataline wire
    bu::quantity<drs::nanofarad_per_bank_unit> globalDatalineCapacitance;
    //Delay through global dataline driver and wiring
    bu::quantity<drs::nanosecond_unit> tgdl;

    //DQ wire length
    bu::quantity<drs::millimeter_unit> DQWireLength;
    // Factor which defines the page size * subArrayToPageFactor relation
    bu::quantity<drs::kibibyte_per_page_unit> bankWidthFactor;
    //Resistance of DQ wire
    bu::quantity<si::resistance> DQWireResistance;
    //Capacitace of DQ wire
    bu::quantity<drs::nanofarad_unit> DQWireCapacitance;
    //Delay through DQ driver and wiring
    bu::quantity<drs::nanosecond_unit> tdq;


    //tcl = tcas - Column Access Strobe delay
    bu::quantity<drs::nanosecond_unit> tcas;

    //trl = tcas + tal - Read (Latency) delay
    bu::quantity<drs::nanosecond_unit> trl;

    //trtp - Read to Precharge delay
    bu::quantity<drs::nanosecond_unit> trtp;

    //tccd - Column-to-Column delay
    bu::quantity<drs::nanosecond_unit> tccd;


    //tras - Row Access Strobe delay
    bu::quantity<drs::nanosecond_unit> tras;

    //twr - Write Recovery delay
    bu::quantity<drs::nanosecond_unit> twr;

    //trp - Row Precharge delay
    bu::quantity<drs::nanosecond_unit> trp;

    //trc - Row Cycle delay
    bu::quantity<drs::nanosecond_unit> trc;

    //trfc - Refresh Cycle delay
    bu::quantity<drs::nanosecond_unit> trfc;

    //trefI - Refresh Interval delay
    bu::quantity<drs::nanosecond_unit> trefI;

    //Maximum core frequency
    bu::quantity<drs::megahertz_clock_unit> maxCoreFreq;

    //Ratio between bus and core frequencies
    double clockFactor;

    //Clock period
    bu::quantity<drs::nanosecond_per_clock_unit> clkPeriod;
    //Core clock period
    bu::quantity<drs::nanosecond_per_clock_unit> coreClkPeriod;

    //trcd in number of clocks
    bu::quantity<drs::clock_unit> trcd_clk;
    //tcas in number of clocks
    bu::quantity<drs::clock_unit> tcas_clk;
    //tcas in number of core clocks
    bu::quantity<drs::clock_unit> tcas_coreClk;
    //tras in number of clocks
    bu::quantity<drs::clock_unit> tras_clk;
    //trp in number of clocks
    bu::quantity<drs::clock_unit> trp_clk;
    //trc in number of clocks
    bu::quantity<drs::clock_unit> trc_clk;
    //trl in number of clocks
    bu::quantity<drs::clock_unit> trl_clk;
    //trl in number of core clocks
    bu::quantity<drs::clock_unit> trl_coreClk;
    //twl in number of clocks
    bu::quantity<drs::clock_unit> twl_clk;
    //trtp in number of clocks
    bu::quantity<drs::clock_unit> trtp_clk;
    //tccd in number of clocks
    bu::quantity<drs::clock_unit> tccd_clk;
    //tccd in number of core clocks
    bu::quantity<drs::clock_unit> tccd_coreClk;
    //twr in number of clocks
    bu::quantity<drs::clock_unit> twr_clk;
    //trfc in number of clocks
    bu::quantity<drs::clock_unit> trfc_clk;
    //trefI in number of clocks
    bu::quantity<drs::clock_unit> trefI_clk;

    void timingInitialize();

    void trcdCalc();

    void trasCalc();

    void trpCalc();

    void trcCalc();

    void trfcCalc();

    void trefICalc();

    void clkTiming();

    void timingCompute();

    void printTiming();
};

#endif
