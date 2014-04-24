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
#include "ResultParser.h"
#include <math.h>
#include <iostream>
#include <fstream>
//function for writing results in json
void 
ResultParser::jsonwriter()
{
    //parsing the timing results
    rapidjson::Document timingdoc;
    timingdoc.SetObject(); 
    //parsing of frequency 
    timingdoc.AddMember("Frequency", t->n.Freq, timingdoc.GetAllocator());
    //parsing of trcd in cc ( clock cycles )
    timingdoc.AddMember("trcd_cc", t->trcd_clk , timingdoc.GetAllocator());
    //parsing of tcl in cc
    timingdoc.AddMember("tcl_cc", t->tcl_clk , timingdoc.GetAllocator());
    //parsing of tras in cc
    timingdoc.AddMember("tras_cc", t->tras_clk , timingdoc.GetAllocator());
    //parsing of trp in cc
    timingdoc.AddMember("trp_cc", t->trp_clk , timingdoc.GetAllocator());
    //parsing of trc in cc
    timingdoc.AddMember("trc_cc", t->trc_clk , timingdoc.GetAllocator());
    //parsing of trl in cc
    timingdoc.AddMember("trl_cc", t->trl_clk , timingdoc.GetAllocator());
    //parsing of twl in cc
    timingdoc.AddMember("twl_cc", t->twl_clk , timingdoc.GetAllocator());
    //parsing of trtp in cc
    timingdoc.AddMember("trtp_cc", t->trtp_clk , timingdoc.GetAllocator());
    //parsing of tccd in cc
    timingdoc.AddMember("tccd_cc", t->tccd_clk , timingdoc.GetAllocator());
    //parsing of twr in cc
    timingdoc.AddMember("twr_cc", t->twr_clk , timingdoc.GetAllocator());
    //parsing of trfc in cc
    timingdoc.AddMember("trfc_cc", t->trfc_clk , timingdoc.GetAllocator());
    //parsing of tref1 in cc
    timingdoc.AddMember("tref1_cc", t->tref1_clk , timingdoc.GetAllocator());
    //parsing of trrd in cc
    timingdoc.AddMember("trrd_cc", t->trrd_clk , timingdoc.GetAllocator());
    //parsing of twtr in cc
    timingdoc.AddMember("twtr_cc", t->twtr_clk , timingdoc.GetAllocator());
    //parsing of tfaw in cc
    timingdoc.AddMember("tfaw_cc", t->tfaw_clk , timingdoc.GetAllocator());
    //parsing of txp in cc
    timingdoc.AddMember("txp_cc", t->txp_clk , timingdoc.GetAllocator());
    //parsing of tcke in cc
    timingdoc.AddMember("tcke_cc", t->tcke_clk , timingdoc.GetAllocator());   
    // Convert JSON document to string
    rapidjson::GenericStringBuffer< rapidjson::UTF8<> > timingbuffer;
    rapidjson::Writer< rapidjson::GenericStringBuffer< 
    rapidjson::UTF8<> > > timingwriter(timingbuffer);
    timingdoc.Accept(timingwriter);
    const char* timingstr = timingbuffer.GetString();
    //open a file
    std::ofstream timingresultfile("timingresult");
    timingresultfile<<timingstr;
    //printf("JSON: %s\n", str);
    //parsing the currents
    rapidjson::Document currentdoc;
    currentdoc.SetObject();
    //parsing of IDD0
    currentdoc.AddMember("IDD0", i->IDD0 , currentdoc.GetAllocator());
    //parsing of IDD1
    currentdoc.AddMember("IDD1", i->IDD1 , currentdoc.GetAllocator());   
    //parsing of IDD4R
    currentdoc.AddMember("IDD4R", i->IDD4R , currentdoc.GetAllocator());
    //parsing of IDD4W
    currentdoc.AddMember("IDD4W", i->IDD4W , currentdoc.GetAllocator()); 
    //parsing of IDD2n
    currentdoc.AddMember("IDD2n", i->IDD2n , currentdoc.GetAllocator());   
    //parsing of IDD3n
    currentdoc.AddMember("IDD3n", i->IDD3n , currentdoc.GetAllocator());  	
    //convert JSON document to string
    rapidjson::GenericStringBuffer< rapidjson::UTF8<> > currentbuffer;
    rapidjson::Writer< rapidjson::GenericStringBuffer
    < rapidjson::UTF8<> > > currentwriter(currentbuffer);
    currentdoc.Accept(currentwriter);
    const char* currentstr = currentbuffer.GetString();
    //printf("CurrentJSON: %s \n", currentstr);
    //open a file
    std::ofstream currentresultfile("currentresult");
    currentresultfile<<currentstr;	  	
}
