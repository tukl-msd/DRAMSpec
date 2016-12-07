///*
// * Copyright (c) 2015, University of Kaiserslautern
// * All rights reserved.
// *
// * Redistribution and use in source and binary forms, with or without
// * modification, are permitted provided that the following conditions are
// * met:
// *
// * 1. Redistributions of source code must retain the above copyright notice,
// *    this list of conditions and the following disclaimer.
// *
// * 2. Redistributions in binary form must reproduce the above copyright
// *    notice, this list of conditions and the following disclaimer in the
// *    documentation and/or other materials provided with the distribution.
// *
// * 3. Neither the name of the copyright holder nor the names of its
// *    contributors may be used to endorse or promote products derived from
// *    this software without specific prior written permission.
// *
// * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
// * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER
// * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// *
// * Authors: Omar Naji, Matthias Jung, Christian Weis
// */

////In this class the timing specification of DRAMs is done
////The class uses an initialized DRAM Bank to compute the timing Specification
//#ifndef TIMING_H
//#define TIMING_H
//#include "Bank.h"
//class Timing
//{
//  public:
//    Timing( const std::string& techname, const std::string& paraname )
//    :n(techname,paraname), wlc(0), blc(0), GWDC(0), CSLcapa(0), GDLcapa(0),
//    DQcapa(0), clk(0), trcd(0), tcl(0), tcl_act(0), tras(0), trp(0), trc(0),
//    trl(0), trl_act(0), twl(0), trtp(0), tccd(0), tccd_act(0), twr(0),
//    trfc(0), tref1(0), tGWLD(0), wlthau(0), blthau(0), trcd_clk(0),
//    tcl_clk(0), tcl_act_clk(0), tras_clk(0), trp_clk(0), trc_clk(0),
//    trl_clk(0), trl_act_clk(0), twl_clk(0), trtp_clk(0), tccd_clk(0),
//    tccd_act_clk(0), twr_clk(0), trfc_clk(0), tref1_clk(0), ActFreq(0)
//    {
//        //do not change order of function
//        bool TRCD = false;
//        TRCD = calctrcd();
//        if (TRCD == false){
//            std::cout<<"ERROR: Function for trcd timing not called"<<
//                "\t"<<"Order of Functions is important"<<"\n";
//            throw(" Function for trcd timing  not called");
//        }
//        bool TRAS = false;
//        TRAS = calctras();
//        if (TRAS == false){
//            std::cout<<"ERROR: Function for tras timing not called"<<
//                "\t"<<"Order of Functions is important"<<"\n";
//            throw(" Function for tras timing not called");
//        }
//        bool TRP = false;
//        TRP = calctrp();
//        if (TRP == false){
//            std::cout<<"ERROR: Function for trp timing not called"<<
//                "\t"<<"Order of Functions is important"<<"\n";
//            throw(" Function for trp timing not called");
//        }
//        bool TRC = false;
//        TRC = calctrc();
//        if (TRC == false){
//            std::cout<<"ERROR: Function for trc timing not called"<<
//                "\t"<<"Order of Functions is important"<<"\n";
//            throw(" Function for trc timing not called");
//        }
//        bool TRL = false;
//        TRL = calctrl();
//        if (TRL == false){
//            std::cout<<"ERROR: Function for trl timing not called"<<
//                "\t"<<"Order of Functions is important"<<"\n";
//            throw(" Function for trl timing not called");
//        }
//        bool TWL = false;
//        TWL = calctwl();
//        if (TWL == false){
//            std::cout<<"ERROR: Function for twl timing not called"<<
//                "\t"<<"Order of Functions is important"<<"\n";
//            throw(" Function for twl timing not called");
//        }
//        bool TRFC = false;
//        TRFC = calctrfc();
//        if (TRFC == false){
//            std::cout<<"ERROR: Function for trfc timing not called"<<
//                "\t"<<"Order of Functions is important"<<"\n";
//            throw(" Function for trfc timing not called");
//        }
//        bool TREF1 = false;
//        TREF1 = calctref1();
//        if (TREF1 == false){
//            std::cout<<"ERROR: Function for tref1 timing not called"<<
//                "\t"<<"Order of Functions is important"<<"\n";
//            throw(" Function for tref1 timing not called");
//        }
//        bool TCLK = false;
//        TCLK = Timingclk();
//        if (TCLK == false){
//            std::cout<<"ERROR: Function for clocked timings not called"<<
//                "\t"<<"Order of Functions is important"<<"\n";
//            throw(" Function for clocked timings not called");
//        }
//    }
  
//    //capacitace of local wordline
//    float wlc;

//    //capacitance of local bitline
//    float blc;

//    //capacitance of global wordline
//    float GWDC;

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
//    float wlthau;

//    //timing for local bitline
//    float blthau;

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

//    //bank used for the timing calculation
//    Bank n;

//    //function for printing timing results
//    void printTiming();

//    //Actual Frequency in MHz
//    float ActFreq;


//  protected:

//    //function used for trcd calculation
//    bool calctrcd();

//    //function used for tras calculation
//    bool calctras();

//    //function used for trp calculation
//    bool calctrp();

//    //function used for trc calculation
//    bool calctrc();

//    //function used for trl calculation
//    bool calctrl();

//    //function used for twl calculation
//    bool calctwl();

//    //function for calculating refresh cycle time
//    bool calctrfc();

//    //function for calculating average refresh period
//    bool calctref1();

//    //function changing timing parameters to clock cycles
//    bool Timingclk();
//};
//#endif
