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
#include "Current.h"
#include <math.h>
#include <iostream>
//backgorund current calculation
bool 
Current::calcbackgroundCurrent()
{
	//precharge background current (scaling with Freq)
	IDD2n = t->n.backgroundcurrentslope * t-> n.Freq 
	+ t-> n.backgroundcurrentoffset; 
	if (t->n.DLL =="OFF") {
		IDD2n = IDD2n - IDD2n*0.4;
	}
	std::cout<<"IDD2n" << "\t" << IDD2n << "\n";
	//active background current
	//IDD3n is equal to IDD2n + active-adder
	//Assumption : active-adder current = 4mA for 2K page 
	//and changes linearly while changing page size
	IDD3n = IDD2n + 2 * t->n.rowbuffersize;    
	std::cout<<"IDD3n"<<"\t" << IDD3n << "\n";
	return true;
}
bool 
Current::calcIDD0()
{
	//number of active subarrays
	int numberofactivesubarrays = (t->n.rowbuffersize * 8 * 1024) 
	/ (t->n.cellsperrow - t->n.cellsperrowredundancy); 
	//charge of master wordline //3.3 is efficiency factor of the vpp pumps
	Q_MWL = t->GWDC * t-> n.vpp * 3.3;
	//charge of local wordline
 	Q_LWL = t->wlc * t-> n.vpp * numberofactivesubarrays * 3.3 ;
	//charge of local bitline//8 bytes to bits // 1024 kbits to bits
 	Q_LBL = t->blc * t-> n.vcc/2 * t->n.rowbuffersize * 8 * 1024;
	//total charges in pC
	float Q_total0 = (( Q_MWL + Q_LWL + Q_LBL ) * 2) / 1000 ;
	//current caused by charging and discharging of capas in mA
	//clock cycles of trc in ns
	float Trc = t->trc_clk * t->clk;
	float IDD_Q = Q_total0/Trc; 
	IDD0 = IDD_Q + IDD3n;
	std::cout<<"IDD0" << "\t" << IDD0 << "\n" ;
	return true;
}
bool
Current::calcIDD1()
{
	//charges of SSA / SSA active for 1.5 ns 
 	Q_SSA = (float)(t->n.Interface * t->n.Prefetch * t->n.I_SSA) * 1.5;
	//charges for CSL// 8 bits pro CSL 
 	Q_CSL = t->CSLcapa * t-> n.vcc * ((t->n.Interface * 
	t->n.Prefetch) / 8 );
	//charge of global Dataline
 	Q_MDL = t->GDLcapa * t-> n.vcc * t->n.Interface * t->n.Prefetch;
	//charges for Dataqueue // 1 Read is done for interface x prefetch
 	Q_DQ =(float) ( t->n.Interface * t->n.Prefetch * t->DQcapa 
	* t->n.vcc );
	//read charges in pC
 	Q_READ = (Q_SSA + Q_CSL + Q_MDL + Q_DQ) ;
	float Q_total1 = ( (Q_MWL + Q_LWL + Q_LBL + Q_READ)*2 ) / 1000;
	float Trc = t->trc_clk * t->clk;
	IDD1 =  Q_total1 / Trc + IDD3n;
	std::cout<<"IDD1"<<"\t"<<IDD1 << "\n" ;
	return true;
}
bool
Current::calcIDD4R()
{
	//scale the IDD_OCD_RCV with frequency linearly 
	//( I = 2.5 mA for 533 MHz, 0 for 0 MHz )
	t->n.IDD_OCD_RCV = (t->n.IDD_OCD_RCV/533) * t->n.Freq;
	float clkconstant;
	//charges for 4 Reads 
	if(t->n.DRAMType == "DDR") {
		clkconstant = 2;
	} else {
	clkconstant = 1;
	}
	float Q_total4R = (Q_READ)* 2 / 1000;
	//number of output signals for read = interface number 
	//+ 1 datastrobe signal pro 4 bits
	//current IDD4R ;  
	IDD4R = Q_total4R / ((t->n.Prefetch / clkconstant) * t->clk)  
	+ IDD3n + (t->n.Interface + t->n.Interface/4) * t->n.IDD_OCD_RCV ;
	std::cout<<"IDD4R"<<"\t"<<IDD4R<<"\n";
	return true;
}
bool 
Current::calcIDD4W()
{
	//number of signals for write is number of signals for read 
	//+ 1 extra signal for rcv per 8 bits
	IDD4W = IDD4R + (t->n.Interface/8) * t->n.IDD_OCD_RCV;
	std::cout<<"IDD4W"<<"\t" << IDD4W << "\n";
	return true;
}
bool
Current::calcIDD5()
{
	//charges for refresh
	//charges of IDD0 x 2 ( 2 rows pro command)x # of banksrefreshed pro
	//x # of rows pro command
	//cmd
	float Q_refresh = ((( Q_MWL + Q_LWL + Q_LBL ) * 2) / 1000) * 2 *
	t->n.banksrefreshfactor *t->n.rowrefreshrate* t->n.numberofbanks;
	//refresh current
	float Trfc = t->trfc_clk * t->clk;
	IDD5 = Q_refresh / Trfc + IDD3n;
	std::cout<<"IDD5"<<"\t"<<IDD5<<"\n";
	//checking the current for the required refresh period
	//calculate the number of times each row if refreshed in 64 ms
	//retention time
	int numberofrowactivation = t->tref1/(t->n.tref1required*1000);
	//calculate the refresh current for the required period
	std::cout<<"WARNING: for the required refresh time of " <<
	t->n.tref1required << "us,each row will be refreshed"
	<<"\t"<<numberofrowactivation 
	<<"\t"<< "times more than required for a retention time of 64 ms"
	<<"\n";
	return true;
}
