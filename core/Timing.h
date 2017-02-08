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
 * Authors: Omar Naji, Matthias Jung, Christian Weis
 */

//In this class the timing specification of DRAMs is done
//The class uses an initialized DRAM Chip to compute the timing specification

#ifndef TIMING_H
#define TIMING_H

#include "Chip.h"

namespace bu=boost::units;
namespace si=boost::units::si;
namespace inf=boost::units::information;
namespace drs=boost::units::dramspec;

class Timing : public Chip
{
  public:
    Timing() : //Empty constructor for test proposes
        Chip()
    {
        timingInitialize();
    }

    Timing(const std::string& techname, const std::string& paraname) :
        Chip(techname, paraname)
    {
        timingInitialize();
        timingCompute();
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
    bu::quantity<drs::resistance_per_subarray_unit> bitlineResistance;
    //Capacitace of local bitline
    bu::quantity<drs::nanofarad_per_subarray_unit> bitlineCapacitance;
    //Delay of local bitline
    bu::quantity<drs::nanosecond_unit> bitlineDelay;

    //Resistance of global wordline
    bu::quantity<drs::resistance_per_tile_unit> globalWordlineResistance;
    //Capacitace of global wordline
    bu::quantity<drs::nanofarad_per_tile_unit> globalWordlineCapacitance;
    //Driver offset !!!  TODO: What exactly is it?  !!!
    bu::quantity<drs::nanosecond_unit> driverOffset;
    //Delay through global wordline driver and wiring
    bu::quantity<drs::nanosecond_unit> globalWordlineDelay;

    //SSA Delay !!!  TODO: Check value !!!
    bu::quantity<drs::nanosecond_unit> SSADelay;
    //t_rcd: ACT to internal read or write delay time
    bu::quantity<drs::nanosecond_unit> trcd;

    //Resistance of CSL wire
    bu::quantity<drs::resistance_per_bank_unit> CSLResistance;
    //Capacitace of CSL wire
    bu::quantity<drs::nanofarad_per_bank_unit> CSLCapacitance;
    //Load capacitance !!!  TODO: What exactly is it?  !!!
    bu::quantity<drs::femtofarad_per_bank_unit> CSLLoadCapacitance;
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
    bu::quantity<drs::kibibit_per_page_unit> bankWidthFactor;
    //Resistance of DQ wire
    bu::quantity<si::resistance> DQWireResistance;
    //Capacitace of DQ wire
    bu::quantity<drs::nanofarad_unit> DQWireCapacitance;
    //Delay through DQ driver and wiring
    bu::quantity<drs::nanosecond_unit> tdq;

    //Command decoder latency !!!  TODO: What exactly is it?  !!!
    bu::quantity<drs::nanosecond_unit> cmdDecoderLatency;
    //Internal latency !!!  TODO: What exactly is it?  !!!
    bu::quantity<drs::nanosecond_unit> interfaceLatency;
    //I/O latency !!!  TODO: What exactly is it?  !!!
    bu::quantity<drs::nanosecond_unit> IODelay;

    //tcl = tcas - Column Access Strobe latency
    bu::quantity<drs::nanosecond_unit> tcas;

    //trtp - Read to Precharge time
    bu::quantity<drs::nanosecond_unit> trtp;

    //tccd - Column-to-Column delay
    bu::quantity<drs::nanosecond_unit> tccd;

    //Delay for SSA precharging !!!  TODO: What exactly is it?  !!!
    bu::quantity<drs::nanosecond_unit> SSAPrechargeDelay;

    //tras - Row Access Strobe latency
    bu::quantity<drs::nanosecond_unit> tras;

    //Security margin !!!  TODO: What exactly is it?  !!!
    bu::quantity<drs::nanosecond_unit> securityMargin;

    //twr - Write Recovery time
    bu::quantity<drs::nanosecond_unit> twr;

    //Equalizer delay !!!  TODO: What exactly is it?  !!!
    bu::quantity<drs::nanosecond_unit> equalizerDelay;
    //trp - Row Precharge time
    bu::quantity<drs::nanosecond_unit> trp;

    //trc - Row Cycle time
    bu::quantity<drs::nanosecond_unit> trc;

    //Act cmd delay !!!  TODO: What exactly is it?  !!!
    bu::quantity<drs::nanosecond_unit> actCmdDelay;
    //pre cmd delay !!!  TODO: What exactly is it?  !!!
    bu::quantity<drs::nanosecond_unit> preCmdDelay;
    //offset !!!  TODO: What exactly is it?  !!!
    bu::quantity<drs::nanosecond_unit> offset;
    //trfc - Refresh Cycle time
    bu::quantity<drs::nanosecond_unit> trfc;

    //tref1 - Refresh Interval time
    bu::quantity<drs::nanosecond_unit> tref1;

    //Maximum core frequency
    bu::quantity<drs::megahertz_clock_unit> maxCoreFreq;
    //Actual core frequency
    bu::quantity<drs::megahertz_clock_unit> actualCoreFreq;

    //Clock
    bu::quantity<drs::nanosecond_per_clock_unit> clk;
    //Actual clock (high and low edge)
    bu::quantity<drs::nanosecond_per_clock_unit> actualClk;

    //trcd in number of clocks
    bu::quantity<drs::clock_unit> trcd_clk;
    //tcas in number of clocks
    bu::quantity<drs::clock_unit> tcas_clk;
    //tcas in number of clocks by the actual clock
    bu::quantity<drs::clock_unit> tcas_actualClk;
    //tras in number of clocks
    bu::quantity<drs::clock_unit> tras_clk;
    //trp in number of clocks
    bu::quantity<drs::clock_unit> trp_clk;
    //trc in number of clocks
    bu::quantity<drs::clock_unit> trc_clk;
    //trl in number of clocks
    bu::quantity<drs::clock_unit> trl_clk;
    //trl in number of clocks by the actual clock
    bu::quantity<drs::clock_unit> trl_actualClk;
    //twl in number of clocks
    bu::quantity<drs::clock_unit> twl_clk;
    //trtp in number of clocks
    bu::quantity<drs::clock_unit> trtp_clk;
    //tccd in number of clocks
    bu::quantity<drs::clock_unit> tccd_clk;
    //tccd in number of clocks by the actual clock
    bu::quantity<drs::clock_unit> tccd_actualClk;
    //twr in number of clocks
    bu::quantity<drs::clock_unit> twr_clk;
    //trfc in number of clocks
    bu::quantity<drs::clock_unit> trfc_clk;
    //tref1 in number of clocks
    bu::quantity<drs::clock_unit> tref1_clk;


  protected:

    void timingInitialize();

    double timeToPercentage(double percentage);

    void trcdCalc();

    void trasCalc();

    void trpCalc();

    void trcCalc();

    void trfcCalc();

    void tref1Calc();

    void clkTiming();

    void timingCompute();
};

#endif
