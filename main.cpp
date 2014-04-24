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
//Main Function for DCTG Tool ( DRAM Current and Timing Generation )
#include "ResultParser.h"
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
	int 
	main(int argc, char* argv[])
	{
	     std::string techname;
	     std::string paraname;
	     for (int i = 1; i < argc; i++) 
	     {
                 if (std::string(argv[i]) == "-t") {
		    techname = argv[i+1];
		    std::cout << "Technology filename" << "\t" << techname <<".\n"; 
		    //check if technology filename correct
            	    std::ifstream tout(techname.c_str());
           	    if(tout.fail()){
                       std::cout << std::endl << " Technology File not specified! "
		       <<std::endl;
                       return 0;
            	    }

		 }
		 if (std::string(argv[i]) == "-p") {
                    paraname = argv[i+1];
                    std::cout << "Parameter filename" << "\t" << paraname <<".\n";
		    //check if parameter filename correct
           	    std::ifstream pout(paraname.c_str());
            	    if(pout.fail()){
                       std::cout << std::endl << " Parameter File not specified! " <<
                       std::endl;
                       return 0;
            	    } 
                 }
	     }
	     //calculating timing specification
	     Timing t(techname, paraname);
	     //calculating power specification ( currents )
	     Current i(t);
	     //result parser
	     ResultParser result( t , i );
	     result.jsonwriter();
	     return 0;
	}
