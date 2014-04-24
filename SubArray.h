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
//This class presents the smallest structure of the DRAM which is a subarray.
//The subarray is made of DRAM cells in the wordline direction (horizantal)
// and DRAM cells in the Bitline Direction (vertical)
#ifndef SUBARRAY_H
#define SUBARRAY_H
#include "TechnologyValues.h"
class SubArray:public TechnologyValues
{
  public:
	//constructor for subarray class
	SubArray(const std::string& techname,const std::string& paraname)
	:TechnologyValues(techname,paraname), SubArraywidth(0), SubArrayheight(0)
	{
    	//Order of functions is important
	    bool SINIT = false;
	    SINIT = SubArrayinit();
	    if(SINIT == false){
            std::cout<<"ERROR: Function for subarray initialization not called"
			<<"\t"<<"Order of Functions is important"<<"\n";
            throw(" Function for subarry initialization not called");
            }
	    bool DINIT = false;
	    DINIT = driversinit();
	    if(DINIT == false){
               std::cout<<"ERROR: Function for driver initialization not called"
               <<"\t"<<"Order of Functions is important"<<"\n";
               throw(" Function for driver initialization not called");
            }	
	}
  protected:
	//the width of the subarray which should be calculated
	float SubArraywidth;
	//the height of the subarray which should be calculated
	float SubArrayheight;
	// function which calculates the height and width of the subarray
	bool
	SubArraycal();
	//function to initialize the drivers resistances
	bool 
	driversinit();
	//function to init subarray
	bool 
	SubArrayinit();
};
#endif//SUBARRAY_H
