/*
 * Copyright (c) 2017, University of Kaiserslautern
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
 * Authors: Omar Naji,
 *          Matthias Jung,
 *          Christian Weis,
 *          Kamal Haddad,
 *          Andre Lucas Chinazzo
 */


#ifndef ARGUMENTSPARSER_H
#define ARGUMENTSPARSER_H

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class ArgumentsParser {
public:
    ArgumentsParser(int argc, char** argv);

    vector<string> technologyFileName;
    vector<string> architectureFileName;
    unsigned int nConfigurations;
    bool IOTerminationCurrentFlag;
    bool printInternalTimigs;

    ostringstream helpStrStream;
    const char* helpMessage =
            "  Mandatory:\n"
            "    -t    <path/to/technologyfile.json>   "
              "(Specify which technology description file should be used.)\n"
            "    -p    <path/to/architecturefile.json> "
              "(Specify which architecture description file should be used.)\n"
            "  Optional:\n"
            "    -term                                 "
              "(Include IO termination currents for read and write operations.)\n"
            "    -internaltimings                      "
              "(Enable print out of internal timings.)\n"
            "For more information, see README.md.\n";

    void runArgParser();

private:
    int cpargc;
    char** cpargv;
    int argvID;

    bool getTechFileName();
    bool getArchFileName();

};

#endif // ARGUMENTSPARSER_H
