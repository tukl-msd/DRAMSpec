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



#include "ArgumentsParser.h"

using namespace std;

ArgumentsParser::ArgumentsParser(int argc, char** argv)
{
    cpargc = argc;
    for ( int it = 0; it < argc; it++ ) {
      cpargv.push_back((string)argv[it]);
    }
    argvID = 1;
    nConfigurations = 0;
    IOTerminationCurrentFlag = false;
    printInternalTimings = false;
}

void ArgumentsParser::runArgParser()
{
    if ( argvID >= cpargc ) {
        // Help run (no arguments)
        if ( cpargc == 1 ) {
            helpStrStream << helpMessage;
        }
        // Or end of parsing
        return;
    }

    // Help run (by argument)
    if ( cpargv[argvID] == "-h" ) {
        helpStrStream << helpMessage;
    }

    // Normal run
    if( cpargv[argvID] == "-t") {
        argvID++;
        if(!getTechFileName()) {
            string exceptionMsgThrown("[ERROR] ");
            exceptionMsgThrown.append("Unexpected argument \'");
            exceptionMsgThrown.append(cpargv[argvID]);
            exceptionMsgThrown.append("\'\n");
            exceptionMsgThrown.append(helpMessage);
            throw exceptionMsgThrown;
       }
    }
    else if( cpargv[argvID] == "-p") {
        argvID++;
        if(!getArchFileName()) {
            string exceptionMsgThrown("[ERROR] ");
            exceptionMsgThrown.append("Unexpected argument \'");
            exceptionMsgThrown.append(cpargv[argvID]);
            exceptionMsgThrown.append("\'\n");
            exceptionMsgThrown.append(helpMessage);
            throw exceptionMsgThrown;
       }
    }
    else if( cpargv[argvID] == "-term") {
        IOTerminationCurrentFlag = true;
        argvID++;
        runArgParser();
    }
    else if( cpargv[argvID] == "-internaltimings") {
        printInternalTimings = true;
        argvID++;
        runArgParser();
    }
    else {
        string exceptionMsgThrown("[ERROR] ");
        exceptionMsgThrown.append("Unexpected argument \'");
        exceptionMsgThrown.append(cpargv[argvID]);
        exceptionMsgThrown.append("\'\n");
        exceptionMsgThrown.append(helpMessage);
        throw exceptionMsgThrown;
    }

    if( technologyFileName.size() == architectureFileName.size() )
    {
        nConfigurations = technologyFileName.size();
    }
    else
    {
        string exceptionMsgThrown("[ERROR] ");
        exceptionMsgThrown.append("Number of technology files (");
        exceptionMsgThrown.append(to_string(technologyFileName.size()));
        exceptionMsgThrown.append(") is different from ");
        exceptionMsgThrown.append("the number of archtecture files (");
        exceptionMsgThrown.append(to_string(architectureFileName.size()));
        exceptionMsgThrown.append("). Could not proceed.");
        throw exceptionMsgThrown;
    }

     if ( nConfigurations == 0 )
     {
         string exceptionMsgThrown("[ERROR] ");
         exceptionMsgThrown.append("No technology nor architecture ");
         exceptionMsgThrown.append("file provided!\n");
         exceptionMsgThrown.append(helpMessage);
         throw exceptionMsgThrown;

     }

}


bool ArgumentsParser::getTechFileName()
{
    while (argvID < cpargc) {

        if( cpargv[argvID] == "-p") {
            argvID++;
            if(!getArchFileName()) { return false; }
        }
        else if( cpargv[argvID] == "-term") {
            IOTerminationCurrentFlag = true;
            argvID++;
            if(!getTechFileName()) { return false; }
        }
        else if( cpargv[argvID] == "-internaltimings") {
            printInternalTimings = true;
            argvID++;
            if(!getTechFileName()) { return false; }
        }
        else if (cpargv[argvID][0] == '-') {
            return false;
        }
        else {
            technologyFileName.push_back(cpargv[argvID]);
            argvID++;
            if(!getTechFileName()) { return false; }
        }

        argvID++;
    }

    return true;
}

bool ArgumentsParser::getArchFileName()
{
    while (argvID < cpargc) {

        if( cpargv[argvID] == "-t") {
            argvID++;
            if(!getTechFileName()) { return false; }
        }
        else if( cpargv[argvID] == "-term") {
            IOTerminationCurrentFlag = true;
            argvID++;
            if(!getArchFileName()) { return false; }
        }
        else if( cpargv[argvID] == "-internaltimings") {
            printInternalTimings = true;
            argvID++;
            if(!getArchFileName()) { return false; }
        }
        else if (cpargv[argvID][0] == '-') {
            return false;
        }
        else {
            architectureFileName.push_back(cpargv[argvID]);
            argvID++;
            if(!getArchFileName()) { return false; }
        }

        argvID++;
    }

    return true;
}
