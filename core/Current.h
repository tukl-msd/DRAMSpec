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
//In this class the current(power) specification of DRAMs is done.
// The class uses a timing object to do the calculations. 
//The timing object contains an initialized DRAM Bank
#ifndef CURRENT_H
#define CURRENT_H
#include "Timing.h"
class Current
{
  public: 
	Current(Timing T): IDD0(0), IDD1(0), IDD4R(0), IDD4W(0), IDD2n(0),
	IDD3n(0), IDD5(0) , t(NULL), Q_MWL(0), Q_LWL(0), Q_LBL(0), Q_SSA(0),
	Q_CSL(0), Q_MDL(0), Q_READ(0), Q_DQ(0) 
	{
	    t=&T;
	    std::cout<<"Currents in mA:" << "\n";
	    //check if function is called (order important)
	    bool background_I = false;
	    background_I = calcbackgroundCurrent();
	    if(background_I == false){
		std::cout<<"ERROR: Function for Backgroud Current not called"<<
		"\t"<<"Order of Functions is important"<<"\n";
		throw(" Function for Backgroud Current not called");
	    }
	    bool IDD0_I = false;
	    IDD0_I = calcIDD0();
	    if(IDD0_I == false){
                std::cout<<"ERROR: Function for IDD0 Current not called"<<
                "\t"<<"Order of Functions is important"<<"\n";
                throw(" Function for IDD0 Current not called");
            }
	    bool IDD1_I = false;
	    IDD1_I = calcIDD1();
	    if(IDD1_I == false){
               std::cout<<"ERROR: Function for IDD1 Current not called"<<
               "\t"<<"Order of Functions is important"<<"\n";
               throw(" Function for IDD1 Current not called");
            }
	    bool IDD4R_I = false;
	    IDD4R_I = calcIDD4R();
	    if(IDD4R_I == false){
               std::cout<<"ERROR: Function for IDD4R Current not called"<<
               "\t"<<"Order of Functions is important"<<"\n";
               throw(" Function for IDD4R Current not called");
            }
	    bool IDD4W_I = false;
	    IDD4W_I = calcIDD4W();
	    if(IDD4W_I == false){
               std::cout<<"ERROR: Function for IDD4W Current not called"<<
               "\t"<<"Order of Functions is important"<<"\n";
               throw(" Function for IDD4W Current not called");
            }
	    bool IDD5_I = false;
	    IDD5_I = calcIDD5();
	    if(IDD5_I == false){
               std::cout<<"ERROR: Function for IDD5 Current not called"<<
               "\t"<<"Order of Functions is important"<<"\n";
               throw(" Function for IDD5 Current not called");
            }		
	}

	//current IDD0 in mA ( ACT-PRE )
	float IDD0;
        //current IDD1 in mA
        float IDD1;
        //current IDD4R in mA
        float IDD4R;
        //current IDD4W in mA
        float IDD4W;
        //background current IDD2n precharge background current
        float IDD2n;
        //background current IDD3n active background current
        float IDD3n;
	//calculate the refresh current
	float IDD5;
  private:
	//object of class timing 
	Timing* t;
	//charges for MWL ( Master wordline )
	float Q_MWL;
	//charges for LWL ( local wordline )
	float Q_LWL;
	//charges for Local bitline + blsa 
	float Q_LBL;
	//charges for SSA ( Secondary sense amp )
	float Q_SSA;
	//charges for CSL (column select line )
	float Q_CSL;
	//charges for MDL ( master dataline )
	float Q_MDL;
	//charges for reading
	float Q_READ;
	//charges for DQ
	float Q_DQ;
	//function for calculation of Background Current
	bool 
	calcbackgroundCurrent();
	//function for calculation of IDD0
	bool 
	calcIDD0();
	//function for calculation of IDD1
	bool 
	calcIDD1();
	//function for calculation of IDD4R
	bool 
	calcIDD4R();
	//function for calculation of IDD4W
	bool 
	calcIDD4W();
	//function for calculation of IDD5
	bool 
	calcIDD5();
};
#endif
