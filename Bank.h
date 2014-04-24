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
//This class repesents the highest level of abstraction which the DRAM bank.
//The DRAM Bank is a group of Memoryarrays in the horizantal direction. 
//The class bank inherits from memoryarray class.
#ifndef BANK_H
#define BANK_H
#include "MemoryArray.h"
#include <iostream>
class Bank:public MemoryArray
{
  public:
	//constructor
	Bank(const std::string& techname,const std::string& paraname)
	:MemoryArray(techname,paraname), sizeofBank(0), sizeofhalfBank(0),
	numberofMemoryArrays(0), Bankwidth(0), chipwidth(0), chiparea(0),
	Bankheight(0)
	{
	    //order of functions is important
	    bool BINIT = false;
	    BINIT = Bankinit();
	    if(BINIT == false){
                std::cout<<"ERROR: Function for Bank Initialization not called"<<
                "\t"<<"Order of Functions is important"<<"\n";
                throw(" Function for Bank Initialization not called");
            }
	    bool AREAC = false;
	    AREAC = calcchiparea();
	    if(AREAC == false){
                std::cout<<"ERROR: Function for area calculation not called"<<
                "\t"<<"Order of Functions is important"<<"\n";
                throw(" Function for area calculation not called");
            }	
	}
  protected:	
	//size of bank
	int sizeofBank;
	//size of halfbank
	int sizeofhalfBank;
	//number of memory arrays
	int numberofMemoryArrays;
	//width of bank	
	float Bankwidth;
	//width of chip
	float chipwidth;
	//height of chip
	float chipheight;
	//Area of chip
	float chiparea;
	//performing the half bank calc
	//performing the bank init
	bool 
	Bankinit();
	//calculate the area of the chip
	bool 
	calcchiparea();
  public:
	//height of bank
        float Bankheight;
};
#endif //BANK_H
