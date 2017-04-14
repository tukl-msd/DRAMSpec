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

#include "DramSpec.h"

using namespace std;

DRAMSpec::DRAMSpec(int argc, char** argv)
{
    runDramSpec(argc, argv);
}

//function for writing results in json
void
DRAMSpec::jsonOutputWrite(int dramConfigID)
{
    //parsing the timing results in ns
    rapidjson::Document timingnsdoc;
    timingnsdoc.SetObject();

    //parsing of trcd
    timingnsdoc.AddMember("trcd", dram->trcd.value() , timingnsdoc.GetAllocator());

    //parsing of tcl ( tcl = tcas )
    timingnsdoc.AddMember("tcl", dram->tcas.value() , timingnsdoc.GetAllocator());

    //parsing of tras
    timingnsdoc.AddMember("tras", dram->tras.value() , timingnsdoc.GetAllocator());

    //parsing of trp
    timingnsdoc.AddMember("trp", dram->trp.value() , timingnsdoc.GetAllocator());

    //parsing of trc
    timingnsdoc.AddMember("trc", dram->trc.value() , timingnsdoc.GetAllocator());

    //parsing of trl (which is equal to tcas == tcl)
    timingnsdoc.AddMember("trl", dram->tcas.value() , timingnsdoc.GetAllocator());

    // Don't have this modelled
//    //parsing of twl
//    timingnsdoc.AddMember("twl", dram->twl , timingnsdoc.GetAllocator());

    //parsing of trtp
    timingnsdoc.AddMember("trtp", dram->trtp.value() , timingnsdoc.GetAllocator());

    //parsing of tccd
    timingnsdoc.AddMember("tccd", dram->tccd.value() , timingnsdoc.GetAllocator());

    //parsing of twr
    timingnsdoc.AddMember("twr", dram->twr.value() , timingnsdoc.GetAllocator());

    //parsing of trfc
    timingnsdoc.AddMember("trfc", dram->trfc.value() , timingnsdoc.GetAllocator());

    //parsing of tref1
    timingnsdoc.AddMember("tref1", dram->tref1.value() , timingnsdoc.GetAllocator());

    // Convert JSON document to string
    rapidjson::GenericStringBuffer< rapidjson::UTF8<> > timingnsbuffer;
    rapidjson::Writer< rapidjson::GenericStringBuffer<
    rapidjson::UTF8<> > > timingnswriter(timingnsbuffer);
    timingnsdoc.Accept(timingnswriter);
    const char* timingnsstr = timingnsbuffer.GetString();

    //open a file
    stringstream timingnsresstr;
    timingnsresstr << string("timingnsresult_")
                   << dramConfigID
                   << string(".json");
    ofstream timingnsresultfile(timingnsresstr.str().c_str());
    timingnsresultfile << timingnsstr;
    timingnsresultfile.close();

    //parsing the timing results in clock cycles
    rapidjson::Document timingdoc;
    timingdoc.SetObject();

    //parsing of frequency
    timingdoc.AddMember("Frequency", dram->dramFreq.value(), timingdoc.GetAllocator());

    //parsing of trcd in cc ( clock cycles )
    timingdoc.AddMember("trcd_cc", dram->trcd_clk.value() , timingdoc.GetAllocator());

    //parsing of tcl in cc ( tcl = tcas )
    timingdoc.AddMember("tcl_cc", dram->tcas_clk.value() , timingdoc.GetAllocator());

    //parsing of tras in cc
    timingdoc.AddMember("tras_cc", dram->tras_clk.value() , timingdoc.GetAllocator());

    //parsing of trp in cc
    timingdoc.AddMember("trp_cc", dram->trp_clk.value() , timingdoc.GetAllocator());

    //parsing of trc in cc
    timingdoc.AddMember("trc_cc", dram->trc_clk.value() , timingdoc.GetAllocator());

    //parsing of trl in cc
    timingdoc.AddMember("trl_cc", dram->trl_clk.value() , timingdoc.GetAllocator());

    //parsing of twl in cc
    timingdoc.AddMember("twl_cc", dram->twl_clk.value() , timingdoc.GetAllocator());

    //parsing of trtp in cc
    timingdoc.AddMember("trtp_cc", dram->trtp_clk.value() , timingdoc.GetAllocator());

    //parsing of tccd in cc
    timingdoc.AddMember("tccd_cc", dram->tccd_clk.value() , timingdoc.GetAllocator());

    //parsing of twr in cc
    timingdoc.AddMember("twr_cc", dram->twr_clk.value() , timingdoc.GetAllocator());

    //parsing of trfc in cc
    timingdoc.AddMember("trfc_cc", dram->trfc_clk.value() , timingdoc.GetAllocator());

    //parsing of tref1 in cc
    timingdoc.AddMember("tref1_cc", dram->tref1_clk.value() , timingdoc.GetAllocator());

    // Convert JSON document to string
    rapidjson::GenericStringBuffer< rapidjson::UTF8<> > timingbuffer;
    rapidjson::Writer< rapidjson::GenericStringBuffer<
    rapidjson::UTF8<> > > timingwriter(timingbuffer);
    timingdoc.Accept(timingwriter);
    const char* timingstr = timingbuffer.GetString();

    //Placing timing results (in clock cycles) in different files according to file number
    stringstream timingresstr;
    timingresstr << string("timingresult_")
                 << dramConfigID
                 << string(".json");
    ofstream timingresultfile(timingresstr.str().c_str());
    timingresultfile << timingstr;
    timingresultfile.close();

    //parsing the currents
    rapidjson::Document currentdoc;
    currentdoc.SetObject();

    //parsing of IDD0
    currentdoc.AddMember("IDD0", dram->IDD0.value() , currentdoc.GetAllocator());

    //parsing of IDD1
    currentdoc.AddMember("IDD1", dram->IDD1.value() , currentdoc.GetAllocator());

    //parsing of IDD4R
    currentdoc.AddMember("IDD4R", dram->IDD4R.value() , currentdoc.GetAllocator());

    //parsing of IDD4W
    currentdoc.AddMember("IDD4W", dram->IDD4W.value() , currentdoc.GetAllocator());

    //parsing of IDD2n
    currentdoc.AddMember("IDD2n", dram->IDD2n.value() , currentdoc.GetAllocator());

    //parsing of IDD3n
    currentdoc.AddMember("IDD3n", dram->IDD3n.value() , currentdoc.GetAllocator());

    //parsing of IDD5
    currentdoc.AddMember("IDD5", dram->IDD5.value() , currentdoc.GetAllocator());

    //convert JSON document to string
    rapidjson::GenericStringBuffer< rapidjson::UTF8<> > currentbuffer;
    rapidjson::Writer< rapidjson::GenericStringBuffer
    < rapidjson::UTF8<> > > currentwriter(currentbuffer);
    currentdoc.Accept(currentwriter);
    const char* currentstr = currentbuffer.GetString();

    //Placing current results in different files according to file number
    stringstream currentresstr;
    currentresstr << string("currentresult_")
                  << dramConfigID
                  << string(".json");
    ofstream currentresultfile(currentresstr.str().c_str());
    currentresultfile << currentstr;
    currentresultfile.close();
}

//function for writing results in csv file or cout
string
DRAMSpec::arrangeOutput(const string outputType)
{
    int lineWidth;
    string separator;
    // If outputing to csv file, keep the lines as short as possible
    //  and add a comma separator between label and value
    if (outputType == "csv") {
        lineWidth = 0;
        separator = ",";
    }
    // If outputing to terminal, build a more human readable table
    else if (outputType == "stdout") {
        lineWidth = 30;
        separator = "";
    }

    ostringstream resultTable;

    resultTable
    << BUILD_LINE("trcd [ns]", dram->trcd.value())
    << BUILD_LINE("tcl [ns]", dram->tcas.value())
    << BUILD_LINE("tras [ns]", dram->tras.value())
    << BUILD_LINE("trp [ns]", dram->trp.value())
    << BUILD_LINE("trc [ns]", dram->trc.value())
    << BUILD_LINE("trl [ns]", dram->tcas.value())
    << BUILD_LINE("trtp [ns]", dram->trtp.value())
    << BUILD_LINE("tccd [ns]", dram->tccd.value())
    << BUILD_LINE("twr [ns]", dram->twr.value())
    << BUILD_LINE("trfc [ns]", dram->trfc.value())
    << BUILD_LINE("tref1 [ns]", dram->tref1.value())

    << BUILD_LINE("trcd [cc]", dram->trcd_clk.value())
    << BUILD_LINE("tcl [cc]", dram->tcas_clk.value())
    << BUILD_LINE("actual tcl [cc]", dram->tcas_actualClk.value())
    << BUILD_LINE("tras [cc]", dram->tras_clk.value())
    << BUILD_LINE("trp [cc]", dram->trp_clk.value())
    << BUILD_LINE("trc [cc]", dram->trc_clk.value())
    << BUILD_LINE("trl [cc]", dram->tcas_clk.value())
    << BUILD_LINE("actual trl [cc]", dram->tcas_actualClk.value())
    << BUILD_LINE("trtp [cc]", dram->trtp_clk.value())
    << BUILD_LINE("tccd [cc]", dram->tccd_clk.value())
    << BUILD_LINE("actual tccd [cc]", dram->tccd_actualClk.value())
    << BUILD_LINE("twr [cc]", dram->twr_clk.value())
    << BUILD_LINE("trfc [cc]", dram->trfc_clk.value())
    << BUILD_LINE("tref1 [cc]", dram->tref1_clk.value())

    << BUILD_LINE("IDD0 [mA]", dram->IDD0.value())
    << BUILD_LINE("IDD1 [mA]", dram->IDD1.value())
    << BUILD_LINE("IDD4R [mA]", dram->IDD4R.value())
    << BUILD_LINE("IDD4W [mA]", dram->IDD4W.value())
    << BUILD_LINE("IDD2n [mA]", dram->IDD2n.value())
    << BUILD_LINE("IDD3n [mA]", dram->IDD3n.value())
    << BUILD_LINE("IDD5 [mA]", dram->IDD5.value())

    << BUILD_LINE("Subarray height [um]", dram->subArrayHeight.value())
    << BUILD_LINE("Subarray width [um]", dram->subArrayWidth.value())
    << BUILD_LINE("Tile height [um]", dram->tileHeight.value())
    << BUILD_LINE("Tile width [um]", dram->tileWidth.value())
    << BUILD_LINE("Bank height [um]", dram->bankHeight.value())
    << BUILD_LINE("Bank width [um]", dram->bankWidth.value())
    << BUILD_LINE("Chip height [um]", dram->chipHeight.value())
    << BUILD_LINE("Chip width [um]", dram->chipWidth.value())
    << BUILD_LINE("Chip area [(mm)^2]", dram->chipArea.value())

    << BUILD_LINE("DRAM frequency [MHz]", dram->dramFreq.value())
    << BUILD_LINE("Max core frequency [MHz]", dram->maxCoreFreq.value())
    << BUILD_LINE("Actual core frequency [MHz]", dram->actualCoreFreq.value())
    << BUILD_LINE("Clock period [ns]", dram->clk.value())
    ;

    return resultTable.str();
}

void DRAMSpec::runDramSpec(int argc, char** argv)
{
    arg = new ArgumentsParser(argc, argv);

    try {
       arg->runArgParser();
    } catch(string exceptionMsgThrown) {
        throw exceptionMsgThrown;
    }

    output << "_______________________________________________________"
           << "_______________________________________________________"
           << "_______________________________________________________"
           << endl;

    //Loop through all the corresponding inputs (arch and tech files)
    // and fill the array to print in a clean layout
    for(unsigned int configID = 0; configID < arg->nConfigurations; configID++)
    {
        ofstream csvResultFile;
        string csvResultFileName("results_for_config_");
        csvResultFileName.append(to_string(configID));
        csvResultFileName.append(".csv");
        csvResultFile.open(csvResultFileName, ofstream::trunc);

        output << "DRAM Configuration: "
               << configID+1
               << endl;
        output << "\tTechnology filename: "
               << arg->technologyFileName[configID]
               << endl;
        output << "\tParameter filename:  "
               << arg->architectureFileName[configID]
               << endl;

        try{
            // Current is the last thing calculated for the dram
            // Maybe the inheritance style should be adjusted for
            //  intelligibility purposes
            dram = new Current(arg->technologyFileName[configID],
                               arg->architectureFileName[configID],
                               arg->IOTerminationCurrentFlag);
        } catch(string exceptionMsgThrown) {
            throw exceptionMsgThrown;
        }
        jsonOutputWrite(configID+1);

        csvResultFile << "Label,"
                      << "Technology filename: " << arg->technologyFileName[configID]
                      << "  Parameter filename: " << arg->architectureFileName[configID]
                      << endl;

        csvResultFile << arrangeOutput("csv");
        csvResultFile.close();

        output << arrangeOutput("stdout") << endl;
        output  << "_______________________________________________________"
                << "_______________________________________________________"
                << "_______________________________________________________"
                << endl;

    }
}
