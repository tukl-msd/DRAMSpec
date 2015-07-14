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

#include "parser/ResultParser.h"
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>

int 
main(int argc, char* argv[])
{
    std::string techname;
    std::string paraname;
    bool term = false;

    // check number of arguments!
    if (argc != 6 && argc != 5)
    {
    	std::cout<< std::endl << "Number of arguments is incorrect" <<".\n";
        return 0;
    }
    // Parse command line arguments:
    for (int i = 1; i < argc; i++) 
    {
        if (std::string(argv[i]) == "-t")
        {
            techname = argv[i+1];
            std::cout << "Technology filename" << "\t" << techname <<".\n"; 
            // Check if technology filename correct:
            std::ifstream tout(techname.c_str());
            if(tout.fail())
            {
                std::cout << std::endl << " Technology File not specified! "
                    << std::endl;
                return -1;
            }
        }
        if (std::string(argv[i]) == "-p")
        {
            paraname = argv[i+1];
            std::cout << "Parameter filename" << "\t" << paraname <<".\n";
            // Check if parameter filename correct:
            std::ifstream pout(paraname.c_str());
            if(pout.fail())
            {
                std::cout << std::endl << " Parameter File not specified! "
                    << std::endl;
                return -1;
            } 
        }
        if (std::string(argv[i]) == "-term")
        {
            term = true;
        }

    }

    // Calculating timing specification:
    Timing t(techname, paraname);
    // Calculating power specification ( currents ):
    Current i(&t, term);

    // Printing the results:
    t.printTiming();
    i.printCurrent();

    // Result parser:
    ResultParser result( t , i );
    result.jsonwriter();
    return 0;
}
