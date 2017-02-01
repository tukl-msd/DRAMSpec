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

class Timing : public Chip
{
  public:
    Timing(const std::string& techname, const std::string& paraname) :
        Chip(techname, paraname)
    {
        //do not change order of function
        bool TRCD = false;
        TRCD = calctrcd();
        if (TRCD == false){
            std::cout<<"ERROR: Function for trcd timing not called"<<
                "\t"<<"Order of Functions is important"<<"\n";
            throw(" Function for trcd timing  not called");
        }
        bool TRAS = false;
        TRAS = calctras();
        if (TRAS == false){
            std::cout<<"ERROR: Function for tras timing not called"<<
                "\t"<<"Order of Functions is important"<<"\n";
            throw(" Function for tras timing not called");
        }
        bool TRP = false;
        TRP = calctrp();
        if (TRP == false){
            std::cout<<"ERROR: Function for trp timing not called"<<
                "\t"<<"Order of Functions is important"<<"\n";
            throw(" Function for trp timing not called");
        }
        bool TRC = false;
        TRC = calctrc();
        if (TRC == false){
            std::cout<<"ERROR: Function for trc timing not called"<<
                "\t"<<"Order of Functions is important"<<"\n";
            throw(" Function for trc timing not called");
        }
        bool TRL = false;
        TRL = calctrl();
        if (TRL == false){
            std::cout<<"ERROR: Function for trl timing not called"<<
                "\t"<<"Order of Functions is important"<<"\n";
            throw(" Function for trl timing not called");
        }
        bool TWL = false;
        TWL = calctwl();
        if (TWL == false){
            std::cout<<"ERROR: Function for twl timing not called"<<
                "\t"<<"Order of Functions is important"<<"\n";
            throw(" Function for twl timing not called");
        }
        bool TRFC = false;
        TRFC = calctrfc();
        if (TRFC == false){
            std::cout<<"ERROR: Function for trfc timing not called"<<
                "\t"<<"Order of Functions is important"<<"\n";
            throw(" Function for trfc timing not called");
        }
        bool TREF1 = false;
        TREF1 = calctref1();
        if (TREF1 == false){
            std::cout<<"ERROR: Function for tref1 timing not called"<<
                "\t"<<"Order of Functions is important"<<"\n";
            throw(" Function for tref1 timing not called");
        }
        bool TCLK = false;
        TCLK = Timingclk();
        if (TCLK == false){
            std::cout<<"ERROR: Function for clocked timings not called"<<
                "\t"<<"Order of Functions is important"<<"\n";
            throw(" Function for clocked timings not called");
        }
    }
  
    //Delay of cell
    bu::quantity<drs::nanosecond_unit> celltau;

    //Resistance of local wordline
    bu::quantity<drs::resistance_per_subarray_unit> localWordlineResistance;
    //Capacitace of local wordline
    bu::quantity<drs::nanofarad_per_subarray_unit> localWordlineCapacitance;
    //Delay of local wordline
    bu::quantity<drs::nanosecond_unit> wltau;

    //Resistance of local bitline
    bu::quantity<drs::resistance_per_subarray_unit> blr;
    //Capacitace of local bitline
    bu::quantity<drs::nanofarad_per_subarray_unit> blc;
    //Delay of local bitline
    bu::quantity<drs::nanosecond_unit> bltau;

    //Resistance of global wordline
    bu::quantity<drs::resistance_per_tile_unit> GWDR;
    //Capacitace of global wordline
    bu::quantity<drs::nanofarad_per_tile_unit> GWDC;
    //Driver offset !!!  TODO: What exactly is it?  !!!
    bu::quantity<drs::nanosecond_unit> driverOffset;
    //Delay through global wordline driver and wiring
    bu::quantity<drs::nanosecond_unit> tGWLD;

    //SSA Delay !!!  TODO: Check value !!!
    bu::quantity<drs::nanosecond_unit> SSADelay;
    //t_rcd: ACT to internal read or write delay time
    bu::quantity<drs::nanosecond_unit> trcd;



//    //capacitanace of CSL
//    float CSLcapa;

//    //capacitance of GDL
//    float GDLcapa;

//    //capacitance of wire to DQ
//    float DQcapa;

//    //clk in ns
//    float clk;

//    //row-column delay
//    float trcd;

//    //column latency (column access strobe delay)
//    float tcl;

//    //actual column latency scaled according to the actual core Freq
//    float tcl_act;

//    //row access strobe delay
//    float tras;

//    //row precharge delay
//    float trp;

//    //row cycle delay
//    float trc;

//    //read latency delay
//    float trl;

//    //actual read latency scaled according to the actual core Freq
//    float trl_act;

//    //write latency delay
//    float twl;

//    //read to precharge delay
//    float trtp;

//    //column to column delay
//    float tccd;

//    //actual column to column delay latency scared according to the actual
//    //core Freq
//    float tccd_act;

//    //write recovery delay
//    float twr;

//    //refresh cycle time
//    float trfc;

//    //average refresh period
//    float tref1;

//    //timing for Global wordline
//    float tGWLD;

//    //timing for local wordline
//    float wltau;

//    //timing for local bitline
//    float bltau;

//    //timing parameters in clk cycles
//    //tcl in clk
//    int tcl_clk;

//    //tcl_act in clk
//    int tcl_act_clk;

//    //trch in clk
//    int trcd_clk;

//    //tras in clk
//    int tras_clk;

//    //trp in clk
//    int trp_clk;

//    //trc in clk
//    int trc_clk;

//    //trl in clk
//    int trl_clk;

//    //trl_act in clk
//    int trl_act_clk;

//    //twl in clk
//    int twl_clk;

//    //trtp in clk
//    int trtp_clk;

//    //tccd in clk
//    int tccd_clk;

//    //tccd_act in clk
//    int tccd_act_clk;

//    //twr in clk
//    int twr_clk;

//    //trfc in clk
//    int trfc_clk;

//    //tref1 in clk
//    int tref1_clk;

//    //function for printing timing results
//    void printTiming();

//    //Actual Frequency in MHz
//    float ActFreq;


  protected:

    double timeToPercentage(double percentage);

    //function used for trcd calculation
    bool calctrcd();

    //function used for tras calculation
    bool calctras();

    //function used for trp calculation
    bool calctrp();

    //function used for trc calculation
    bool calctrc();

    //function used for trl calculation
    bool calctrl();

    //function used for twl calculation
    bool calctwl();

    //function for calculating refresh cycle time
    bool calctrfc();

    //function for calculating average refresh period
    bool calctref1();

    //function changing timing parameters to clock cycles
    bool Timingclk();
};
#endif
