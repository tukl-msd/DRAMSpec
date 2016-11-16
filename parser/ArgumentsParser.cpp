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
 * Authors: Omar Naji
 *          Matthias Jung
 *          Christian Weis
 *          Kamal Haddad
 *          Andr'e Lucas Chinazzo
 */

#include "ArgumentsParser.h"

using namespace std;

ArgumentsParser::ArgumentsParser(int argc, char** argv)
{
    cpargc = argc;
    cpargv = argv;
    argvID = 1;
    numberOfConfigurations = 0;
    IOTerminationCurrentFlag = false;
}

void ArgumentsParser::runArgParser()
{
    if( string(cpargv[argvID]) == "-t") {
        argvID++;
        if(!getTechFileName()) {
            string exceptionMsgThrown("Unexpected argument \'");
            exceptionMsgThrown.append(cpargv[argvID]);
            exceptionMsgThrown.append("\'.\nUse \'-t\' and \'-p\' before the ");
            exceptionMsgThrown.append("Technology and Archtecture file names, respectively.\n");
            exceptionMsgThrown.append("Use \'-term\' to include the");
            exceptionMsgThrown.append(" OI Termination Current calculation.\n");
            throw exceptionMsgThrown;
       }
    }
    else if( string(cpargv[argvID]) == "-p") {
        argvID++;
        if(!getArchFileName()) {
            string exceptionMsgThrown("Unexpected argument \'");
            exceptionMsgThrown.append(cpargv[argvID]);
            exceptionMsgThrown.append("\'.\nUse \'-t\' and \'-p\' before the ");
            exceptionMsgThrown.append("Technology and Archtecture file names, respectively.\n");
            exceptionMsgThrown.append("Use \'-term\' to include the");
            exceptionMsgThrown.append(" OI Termination Current calculation.\n");
            throw exceptionMsgThrown;
       }
    }
    else if( string(cpargv[argvID]) == "-term") {
        IOTerminationCurrentFlag = true;
        argvID++;
        runArgParser();
    }
    else {
        string exceptionMsgThrown("Unexpected argument \'");
        exceptionMsgThrown.append(cpargv[argvID]);
        exceptionMsgThrown.append("\'.\nUse \'-t\' and \'-p\' before the ");
        exceptionMsgThrown.append("Technology and Archtecture file names, respectively.\n");
        exceptionMsgThrown.append("Use \'-term\' to include the");
        exceptionMsgThrown.append(" OI Termination Current calculation.\n");
        throw exceptionMsgThrown;
    }

    if( technologyFileName.size() == architectureFileName.size() )
    {
        numberOfConfigurations = technologyFileName.size();
    }
    else
    {
        string exceptionMsgThrown("Number of technology files (");
        exceptionMsgThrown.append(to_string(technologyFileName.size()));
        exceptionMsgThrown.append(") is different from ");
        exceptionMsgThrown.append("the number of archtecture files (");
        exceptionMsgThrown.append(to_string(architectureFileName.size()));
        exceptionMsgThrown.append("). Could not proceed.");
        throw exceptionMsgThrown;
    }

}


bool ArgumentsParser::getTechFileName()
{
    while (argvID < cpargc) {

        if( string(cpargv[argvID]) == "-p") {
            argvID++;
            if(!getArchFileName()) { return false; }
        }
        else if( string(cpargv[argvID]) == "-term") {
            IOTerminationCurrentFlag = true;
            argvID++;
            runArgParser();
        }
        else {
            if (cpargv[argvID][0] == '-') { return false; }

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

        if( string(cpargv[argvID]) == "-t") {
            argvID++;
            if(!getTechFileName()) { return false; }
        }
        else if( string(cpargv[argvID]) == "-term") {
            IOTerminationCurrentFlag = true;
            argvID++;
            runArgParser();
        }
        else {
            if (cpargv[argvID][0] == '-') { return false; }

            architectureFileName.push_back(cpargv[argvID]);
            argvID++;
            if(!getArchFileName()) { return false; }
        }

        argvID++;
    }

    return true;
}
