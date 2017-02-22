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
 * Authors: Omar Naji, Matthias Jung, Christian Weis, Kamal Haddad
 */

#include "Current.h"
#include <math.h>
#include <iostream>
#include <fstream>

// Background current calculation
void
Current::backgroundCurrentCalc()
{
    // Precharge background current (scaling with Freq)
    IDD2n = backgroundCurrentSlope * dramFreq
            + backgroundCurrentOffset;

    if (DLL =="OFF") {
        // !!! TODO: WHY ONLY 60% ? !!!
        IDD2n = IDD2n - IDD2n*0.4;
    }

    // Active background current:
    // IDD3n is equal to IDD2n + active-adder
    // Assumption : active-adder current = 4mA for 2K page
    // and changes linearly while changing page size
    IDD3n = IDD2n + currentPerPageSizeSlope * pageStorage;

}

//bool
//Current::calcIDD0()
//{
//    // Number of active subarrays
//    int numberofactivesubarrays = (pageSize * 8 * 1024)
//    / (cellsPerLWL - cellsPerLWLRedundancy);

//    // Charge of master wordline //3.3 is efficiency factor of the vpp pumps
//    Q_MWL = GWDC *  Vpp * 3.3;

//    // Charge of local wordline
//    Q_LWL = wlc *  Vpp * numberofactivesubarrays * 3.3 ;

//    //charge of local bitline//8 bytes to bits // 1024 kbits to bits
//    Q_LBL = (float)blc * (float)Vcc/2 * (float)pageSize * 8 * 1024;
 
//    //Extra charge added as the number of tiles per bank is changed
//    float Q_tilesperbank = 0;

//    //If it is a halfbank, Charge = wire capacitance * number of wires * length of wire * voltage
//    if(tilesPerBank == 2)
//    Q_tilesperbank = wireCapacitance * 13 * 0.25 * Vcc/2;
//    //If it is a quarterbank, Charge = wire capacitance * number of wires * length of wire * voltage * 2
//    if(tilesPerBank == 4)
//    Q_tilesperbank = wireCapacitance * 13 * 0.25 * Vcc/2 * 2;
 
//    // Total charges in pC
//    float Q_total0 = (( Q_MWL + Q_LWL + Q_LBL + Q_tilesperbank) * 2) / 1000 ;

//    // Current caused by charging and discharging of capas in mA
//    // Clock cycles of trc in ns
//    float Trc = trc_clk * clk;
//    float IDD_Q = Q_total0/Trc;

//    IDD0 = IDD_Q + IDD3n;

//    return true;
//}

//bool
//Current::calcIDD1()
//{
//    // Charges of SSA / SSA active for 1.5 ns
//    Q_SSA = (float)(Interface * Prefetch * Issa) * 1.5;

//    // Charges for CSL// 8 bits pro CSL
//    Q_CSL = CSLcapa *  Vcc * ((Interface *
//    Prefetch) / 8 );

//    // Charge of global Dataline
//    Q_MDL = GDLcapa *  Vcc * Interface * Prefetch;

//    // Charges for Dataqueue // 1 Read is done for interface x prefetch

//    Q_DQ =(float) ( Interface * Prefetch * DQcapa
//    * Vcc );
     
//    // read charges in pC
//    Q_READ = (Q_SSA + 2*Q_CSL + 2*Q_MDL + Q_DQ) ;
//    float Q_total1 = ( (Q_MWL + Q_LWL + Q_LBL + Q_READ)*2 ) / 1000;
//    float Trc = trc_clk * clk;
//    IDD1 =  Q_total1 / Trc + IDD3n;

//    return true;
//}

//bool
//Current::calcIDD4R()
//{
//    // Scale the IDD_OCD_RCV with frequency linearly
//    // ( I = 2.5 mA for 533 MHz, 0 for 0 MHz )
//    IddOcdRcv = (IddOcdRcv/533) * dramFreq;
//    float clkconstant;

//    // Charges for 4 Reads
//    if(DramType == "DDR") {
//        clkconstant = 2;
//    } else {
//        clkconstant = 1;
//    }

//    float Q_tilesperbank = 0;

//    if(tilesPerBank == 2)
//    Q_tilesperbank = wireCapacitance * 13 * 0.25 * Vcc * 10;
 
//    if(tilesPerBank == 4)
//    Q_tilesperbank = wireCapacitance * 13 * 0.25 * Vcc * 2 * 10;

//    float Q_total4R = (Q_READ + Q_tilesperbank) / 1000;
//    // Number of output signals for read = interface number
//    // + 1 datastrobe signal pro 4 bits
//    float ioTermRdCurrent;
//    if (includeTerm) {
//       ioTermRdCurrent = (Interface + Interface/4) * IddOcdRcv;
//    }
//    else {
//       ioTermRdCurrent = 0;
//    }
//    //DRAM core freq
//    float core_freq = 0;
//    if (dramCoreFreq != 0) {
//        // 1/core_freq in ns
//        core_freq = (float)dramCoreFreq / 1000;
//        std::cout<<"core freq"<< core_freq << std::endl;
//    } else {
//        core_freq = 1/((Prefetch / clkconstant) * clk);
//    }
//    //current IDD4R ;
//    IDD4R = Q_total4R * core_freq + IDD3n + ioTermRdCurrent;

//    return true;
//}

//bool
//Current::calcIDD4W()
//{
//    //number of signals for write is number of signals for read
//    //+ 1 extra signal for rcv per 8 bits
//    int rcvconst;
//    if(Interface/8 < 1) {
//        rcvconst = 1 ;
//    } else {
//        rcvconst = 0 ;
//    }
//    //additional IO term current for Writes
//    float ioTermWraddCurrent;
//    if (includeTerm) {
//        ioTermWraddCurrent = (Interface/8 + rcvconst) * IddOcdRcv;
//    }
//    else {
//        ioTermWraddCurrent = 0;
//    }
//    IDD4W = IDD4R + ioTermWraddCurrent;

//    return true;
//}

//bool
//Current::calcIDD5()
//{
//    // Charges for refresh
//    // Charges of IDD0 x 2 ( 2 rows pro command)x # of banksrefreshed pro
//    // x # of rows pro command
//    float Q_refresh = ((( Q_MWL + Q_LWL + Q_LBL ) * 2) / 1000) * 2 *
//    banksRefreshFactor *rowRefreshRate* nBanks;

//    // Refresh current
//    float Trfc = trfc_clk * clk;
//    IDD5 = Q_refresh / Trfc + IDD3n;

//    // Checking the current for the required refresh period
//    // Calculate the number of times each row if refreshed in 64 ms
//    // retention time
//    //        []                   [ns]          [us]
//    int numberofrowactivation = tref1/(tRef1Required*1000);

//    // Calculate the refresh current for the required period
//    std::cout<<"Remark: for the required refresh time of " <<
//    tRef1Required << " us, each row will be refreshed"
//    <<"\t"<<numberofrowactivation
//    <<"\t"<< "times more than required for a retention time of "<<retentionTime<< " ms"
//    <<"\n";
//    return true;
//}

//void
//Current::printCurrent()
//{
	

//}
