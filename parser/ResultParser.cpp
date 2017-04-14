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
 * Authors: Omar Naji, Matthias Jung, Christian Weis, Kamal Haddad
 */

#include "DramSpec.h"
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
//function for writing results in json
void
DRAMSpec::jsonOutputWrite(int dramConfigID)
{
    //parsing the timing results in ns
    rapidjson::Document timingnsdoc;
    timingnsdoc.SetObject();

    //parsing of trcd
    timingnsdoc.AddMember("trcd", dram->trcd , timingnsdoc.GetAllocator());

    //parsing of tcl ( tcl = tcas )
    timingnsdoc.AddMember("tcl", dram->tcas , timingnsdoc.GetAllocator());

    //parsing of tras
    timingnsdoc.AddMember("tras", dram->tras , timingnsdoc.GetAllocator());

    //parsing of trp
    timingnsdoc.AddMember("trp", dram->trp , timingnsdoc.GetAllocator());

    //parsing of trc
    timingnsdoc.AddMember("trc", dram->trc , timingnsdoc.GetAllocator());

    // Don't have those
//    //parsing of trl
//    timingnsdoc.AddMember("trl", dram->trl , timingnsdoc.GetAllocator());

//    //parsing of twl
//    timingnsdoc.AddMember("twl", dram->twl , timingnsdoc.GetAllocator());

    //parsing of trtp
    timingnsdoc.AddMember("trtp", dram->trtp , timingnsdoc.GetAllocator());

    //parsing of tccd
    timingnsdoc.AddMember("tccd", dram->tccd , timingnsdoc.GetAllocator());

    //parsing of twr
    timingnsdoc.AddMember("twr", dram->twr , timingnsdoc.GetAllocator());

    //parsing of trfc
    timingnsdoc.AddMember("trfc", dram->trfc , timingnsdoc.GetAllocator());

    //parsing of tref1
    timingnsdoc.AddMember("tref1", dram->tref1 , timingnsdoc.GetAllocator());

    // Convert JSON document to string
    rapidjson::GenericStringBuffer< rapidjson::UTF8<> > timingnsbuffer;
    rapidjson::Writer< rapidjson::GenericStringBuffer<
    rapidjson::UTF8<> > > timingnswriter(timingnsbuffer);
    timingnsdoc.Accept(timingnswriter);
    const char* timingnsstr = timingnsbuffer.GetString();

    //open a file
    std::stringstream timingnsresstr;
    timingnsresstr << std::string("timingnsresult_")
                   << dramConfigID
                   << std::string(".json");
    std::ofstream timingnsresultfile(timingnsresstr.str().c_str());
    timingnsresultfile << timingnsstr;
    timingnsresultfile.close();

    //parsing the timing results in clock cycles
    rapidjson::Document timingdoc;
    timingdoc.SetObject();

    //parsing of frequency
    timingdoc.AddMember("Frequency", dram->dramFreq, timingdoc.GetAllocator());

    //parsing of trcd in cc ( clock cycles )
    timingdoc.AddMember("trcd_cc", dram->trcd_clk , timingdoc.GetAllocator());

    //parsing of tcl in cc ( tcl = tcas )
    timingdoc.AddMember("tcl_cc", dram->tcas_clk , timingdoc.GetAllocator());

    //parsing of tras in cc
    timingdoc.AddMember("tras_cc", dram->tras_clk , timingdoc.GetAllocator());

    //parsing of trp in cc
    timingdoc.AddMember("trp_cc", dram->trp_clk , timingdoc.GetAllocator());

    //parsing of trc in cc
    timingdoc.AddMember("trc_cc", dram->trc_clk , timingdoc.GetAllocator());

    //parsing of trl in cc
    timingdoc.AddMember("trl_cc", dram->trl_clk , timingdoc.GetAllocator());

    //parsing of twl in cc
    timingdoc.AddMember("twl_cc", dram->twl_clk , timingdoc.GetAllocator());

    //parsing of trtp in cc
    timingdoc.AddMember("trtp_cc", dram->trtp_clk , timingdoc.GetAllocator());

    //parsing of tccd in cc
    timingdoc.AddMember("tccd_cc", dram->tccd_clk , timingdoc.GetAllocator());

    //parsing of twr in cc
    timingdoc.AddMember("twr_cc", dram->twr_clk , timingdoc.GetAllocator());

    //parsing of trfc in cc
    timingdoc.AddMember("trfc_cc", dram->trfc_clk , timingdoc.GetAllocator());

    //parsing of tref1 in cc
    timingdoc.AddMember("tref1_cc", dram->tref1_clk , timingdoc.GetAllocator());

    // Convert JSON document to string
    rapidjson::GenericStringBuffer< rapidjson::UTF8<> > timingbuffer;
    rapidjson::Writer< rapidjson::GenericStringBuffer<
    rapidjson::UTF8<> > > timingwriter(timingbuffer);
    timingdoc.Accept(timingwriter);
    const char* timingstr = timingbuffer.GetString();

    //Placing timing results (in clock cycles) in different files according to file number
    std::stringstream timingresstr;
    timingresstr << std::string("timingresult_")
                 << dramConfigID
                 << std::string(".json");
    std::ofstream timingresultfile(timingresstr.str().c_str());
    timingresultfile << timingstr;
    timingresultfile.close();

    //parsing the currents
    rapidjson::Document currentdoc;
    currentdoc.SetObject();

    //parsing of IDD0
    currentdoc.AddMember("IDD0", dram->IDD0 , currentdoc.GetAllocator());

    //parsing of IDD1
    currentdoc.AddMember("IDD1", dram->IDD1 , currentdoc.GetAllocator());

    //parsing of IDD4R
    currentdoc.AddMember("IDD4R", dram->IDD4R , currentdoc.GetAllocator());

    //parsing of IDD4W
    currentdoc.AddMember("IDD4W", dram->IDD4W , currentdoc.GetAllocator());

    //parsing of IDD2n
    currentdoc.AddMember("IDD2n", dram->IDD2n , currentdoc.GetAllocator());

    //parsing of IDD3n
    currentdoc.AddMember("IDD3n", dram->IDD3n , currentdoc.GetAllocator());

    //parsing of IDD5
    currentdoc.AddMember("IDD5", dram->IDD5 , currentdoc.GetAllocator());

    //convert JSON document to string
    rapidjson::GenericStringBuffer< rapidjson::UTF8<> > currentbuffer;
    rapidjson::Writer< rapidjson::GenericStringBuffer
    < rapidjson::UTF8<> > > currentwriter(currentbuffer);
    currentdoc.Accept(currentwriter);
    const char* currentstr = currentbuffer.GetString();

    //Placing current results in different files according to file number
    std::stringstream currentresstr;
    currentresstr << std::string("currentresult_")
                  << dramConfigID
                  << std::string(".json");
    std::ofstream currentresultfile(currentresstr.str().c_str());
    currentresultfile << currentstr;
    currentresultfile.close();
}
