/*
Copyright (c)  2014, University of Kaiserslautern
All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software without
specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
Author: Omar Naji
*/
#include "Timing.h"
#include <math.h>
#include <iostream>
bool 
Timing::calctrcd()
{
    //trcd is divided as following
    //the first part is for wordline driver delay estimated as 2 ns
    //the second part is the delay throught the local wordline and 
    //local bitline and delay coming from cell itself
    //the 3rd part is the delay of the ssa and is estimated to 2 ns
    //calculating thau for wl
    //calculating wordline total resistance ( value in Ohm )
    //local wordline resistance equals resistance of local wordline driver+
    //resistance of cells in wordline direction
    float wlr = n.LWDresistance + (n.cellsperrow * n. Wlpercellresistance);
    //calculating wordline total capacitance ( value in ff)
    wlc = (n.cellsperrow * n.Wlpercellcapa)*(1/pow(10.0,3.0));
    //calculating wlthau( in ns ) 
    wlthau =   2.2 * wlr * wlc * (1/pow(10.0,6.0));
    //calculating bitline total resistance  
    float blr = (n.cellspercolumn * n.Blpercellresistance);
    //calculating bitline total capacitance 
    blc = (n.cellspercolumn * n.Blpercellcapa)*(1/pow(10.0,3.0));
    //calculating the blthau( in ns )
    //for timing of bitline, the voltage should reach 90% of the value 
    //or else the BLSA can kipp to the wrong value => thau*2.3
    blthau = 2.3 * blr * blc * (1/pow(10.0,6.0));
    //calculating thau for cell cellthau ( in ns )
    float cellthau = 2.2 * n.cellcapa * n.cellresistance * (1/pow(10.0,3.0));
    //calculating GWL decoder + wiring delay
    //calculating global wordline total capa in fF
    GWDC = n.wirecapa*n.MemoryArraywidth*(1/pow(10.0,3.0));
    //std::cout<<"Global wordline capa"<<GWDC<<"\n";
    //calculating delay through global wordline driver and wiring
    tGWLD =0.6 + (2.2 * n.GWLDresistance*GWDC +  n.wireresistance 
    * n.wirecapa * n.MemoryArraywidth * n.MemoryArraywidth 
    * (1/pow(10.0,6.0)))*(1/pow(10.0,6.0));
    
    //calculating trcd
    trcd = tGWLD + wlthau + blthau + cellthau + 2 ;
    return true;
}
bool
Timing::calctras()
{
    //tras is divided into 4 parts: trcd + tCAS + time for precharging
    // SSA(~2ns) + time needed to restore the bits into the cells(thau bitline)
    //calculating tCAS
    //tCAS has delay from CSL driver + Wire ,Local Dataline driver 
    //+ wire (~1 ns ), Global Data line driver + wire, Delay from 
    //SSA to Dataqueue(DQ)
    //delay through CSL
    //CSL wire capacitane in fF + 8 fF for load
    CSLcapa = n.Bankheight * n.wirecapa * (1/pow(10.0,3.0)) + 8;
    //thau CSL in ns
    float tCSL = 0.6 +  (2.2 * (n.CSLDresistance * CSLcapa) + 
    ( n.wireresistance * n.wirecapa * n.Bankheight * n.Bankheight)
    *(1/pow(10.0,6.0)))*(1/pow(10.0,6.0));
    //through global data line(voltage on dataline should reach 90%
    GDLcapa = n.Bankheight * n.wirecapa * (1/pow(10.0,3.0));
    float tGDL =  0.6 +  (2.2 * (n.GDLDresistance * GDLcapa) 
    + ( n.wireresistance * n.wirecapa * n.Bankheight * n.Bankheight)
    *(1/pow(10.0,6.0)))*(1/pow(10.0,6.0));
    //delay from SSA to DQ//assume wire length = 5mm 
    //the length of the DQ wire depends on the width of the bank
    int dqwirelength;
    
    //factor which defines the rowbuffer*subarray2rowbuffer relation
    float bankwidthfactor;
    bankwidthfactor = n.rowbuffersize * n.subarray2rowbufferfactor;
    //std::cout<<"bankwidthfactor"<<bankwidthfactor<<"\n";
    if (bankwidthfactor == 1) {
        dqwirelength = 3;
    } else if (bankwidthfactor == 2) {
        dqwirelength = 5;
    } else if(bankwidthfactor == 4) {
        dqwirelength = 7;
    } else if(bankwidthfactor == 8) {
        dqwirelength = 9;
    } else {
        dqwirelength = 5;
        std::cout<<"WARNING: YOUR PAGESIZE*Subarray2rowbuffer SEEMS to be too big!!"<<"\n";
    }
    DQcapa = 5 * n.wirecapa;
    float tDQ = 0.6 + (2.2 * (n.DQDresistance * DQcapa) + 
    ( n.wireresistance * n.wirecapa * 5 * 5))*(1/pow(10.0,6.0));
    
    //calculating tcl
    //( readout-sensing of SSA ) + tDQ + 1 ns (interface delay)
    tcl = tCSL + 1 + tGDL + 2 + tDQ + 1 ;    
    
    //calculating trtp
    //read to precharge 
    trtp = tcl - tDQ - 1 + blthau ; 
    
    //calculating tccd
    //tccd ( column to column delay) is equal time to select another CSL
    // + precharging secondary SSA + Global Dataline delay... 
    //- 0.5(delay of CSL driver isnot in the critical path)
    tccd = tCSL + 1 + tGDL - 0.5;
    
    //calculating tras 
    tras = trcd + tcl + 2 + blthau - tDQ - 1;

    //calculating twr
    twr = blthau + tGDL ;

    return true;
}
bool 
Timing::calctrp()
{
    //calculating trp
    //trp = Master wordline delay ( discharging ) + local wordline delay
    // (discharging ) + 1 ns ( equalizer delay ) 
    trp =  wlthau + 1 + blthau;

    return true;          
}
bool 
Timing::calctrc()
{
    //calculating trc
    // trc = tras + trp 
    trc = tras + trp;

    return true;
}
bool 
Timing::calctrl()
{
    //calculating trl
    //trl is equal to tcl
    trl = tcl;

    return true;
}
bool  
Timing::calctwl()
{
    return true;
}
bool
Timing::calctrfc()
{
    //time for refresh cycle
    //numberofbanks refreshed*(5(Act cmd delay ) + 
    // 5(pre cmd delay)) + 10 ns (offset)) + trc
    trfc =  ( n.rowrefreshrate * n.banksrefreshfactor * n.numberofbanks * (5 + 5) + 10 ) + trc;

    return true;
}
bool
Timing::calctref1()
{
    //time for average refresh period
    //number of rows
    //number of rows = (DRAM SIZE/#ofbanks) / rowbuffer
    int numberofrows = (n.dramsize * 1024 * 1024 / (n.numberofbanks) ) 
    / (n.rowbuffersize * 8);
    tref1 = (n.rowrefreshrate * 64 * 1000 * 1000) / (numberofrows);

    return true;
}

bool 
Timing::Timingclk()
{
    int clockfactor;
    std::cout<<"Freq" << "\t" << n.Freq << "\t" << "MHz" <<"\n";
    float freq = n.Freq;
    float freq_core_max = (1/ tccd ) * 1000 ;
    std::cout<<"Max DRAM Core Freq" << "\t" << freq_core_max 
    << "\t" << "MHz" << "\n";
    if (n.DRAMType == "DDR") {
        clockfactor = 2;
    } else {
        clockfactor = 1;
    }
    float freq_core_actual = freq/(n.Prefetch/clockfactor);
    std::cout<<"Actual DRAM Core Freq" << "\t" << 
    freq_core_actual << "\t" << "MHz" << "\n";  
    if(freq_core_actual < freq_core_max ) {
        std::cout<<"The Specified Frequency fits the DRAM Design!!!"<<"\n";
    } else {
        std::cout<<"WARNING : Specified Frequency too high"
                 <<"for DRAM Design.Go Down with Frequency!!"
                 <<"\n";
        std::cout<<"If User wants to keep the high frequency," 
                 <<"try using a smaller bank or a higher" 
                 <<"subarray2rowbufferfactor"<<"\n";
    }
    clk = (1 / freq ) * 1000;
    std::cout << "clk" << "\t" << clk << "\t" << "ns" <<"\n";
    
    //trcd in clk cycles round-up
    trcd_clk = ceil(trcd/clk);

    //tcl in clk cycles
    tcl_clk = ceil(tcl/clk); 

    //tras in clk cycles
    tras_clk = ceil(tras/clk);

    //trp in clk cycles 
    trp_clk = ceil(trp/clk);

    //trc in clk cycles
    trc_clk = ceil(trc/clk);
    
    //trl in clk cycles // tal is additional latency defined in tech. 
    //parameter
    trl_clk = ceil(tcl/clk) + n.tal;

    //twl in clk cycles
    twl_clk = trl_clk - 1;

    //trtp in clk cycles
    trtp_clk = ceil(trtp/clk);

    //tccd in clk cycles
    tccd_clk = ceil(tccd/clk);

    //twr in clk cycles
    twr_clk = ceil(twr/clk);

    //trfc in clk cycles
    trfc_clk = ceil(trfc/clk);
    
    //tref1 in clk cycles
    tref1_clk = ceil(tref1/clk);

    return true;
}
void
Timing::printTiming()
{
    //print analog timings
    std::cout << "Timing Parameters in ns" << "\n";
    std::cout << "trcd" << "\t" << trcd << ".\n";
    std::cout << "tcl" << "\t" << tcl << ".\n";
    std::cout << "trtp" << "\t" << trtp << ".\n";
    std::cout << "tccd" << "\t" << tccd << ".\n";
    std::cout << "tras" << "\t" << tras << ".\n";
    std::cout << "twr" << "\t" << twr << "\n" ;
    std::cout << "trp" << "\t" << trp << ".\n";
    std::cout << "trc" << "\t" << trc << ".\n";
    std::cout << "trl" << "\t" << trl << ".\n";
    std::cout << "trfc" << "\t" << trfc << "\n";
    std::cout << "tref1" << "\t" << tref1 << "\n";
}
