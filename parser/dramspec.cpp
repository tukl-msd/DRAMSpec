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

#include "dramspec.h"

using namespace std;

void DRAMSpec::printresult(string resultname,
                 int resultindex,
                 int numberOfConfigurations,
                 int NumberOfResults,
                 vector<float> allresults,
                 ofstream& resultsfile )
{

    resultsfile << resultname << ",";

    cout << resultname;
    // 21 - the name of the result is done to count the number of spaces
    //that should be added
    for(int i = 0; i < (21-resultname.size()) ; i++) {
        cout << " ";
    }
    for(int i = 0; i < numberOfConfigurations*NumberOfResults; i += NumberOfResults)
    {
        resultsfile << setprecision(7) << allresults.at(i+resultindex);
        if(i != ((numberOfConfigurations*NumberOfResults) - NumberOfResults))
        {
            resultsfile<<",";
        }
        fprintf(stdout, "%16.5f", allresults.at(i+resultindex));
    }

	resultsfile<<"\n";
    cout<<"\n";

}




void DRAMSpec::run()
{
    try {
       ArgumentsParser::runArgParser();
    } catch(string exceptionMsgThrown) {
        throw exceptionMsgThrown;
    }

    const int numberOfresults = 30;
    vector<float> currentsandtimings(numberOfConfigurations * numberOfresults);

    //Open results.txt file found in the same directory as main.cpp
    ofstream resultsfile;
    resultsfile.open("results.csv", ofstream::trunc);

    cout    << "_______________________________________________________"
            << "_______________________________________________________"
            << "_______________________________________________________"
            << endl;

    //Loop through all the corresponding inputs (arch and tech files)
    // and fill the array to print in a clean layout
    for(int j = 0; j<numberOfConfigurations;j++)
    {
        cout << "(" << j+1 << ") "
         << "\tTechnology filename: " << technologyFileName[j] << endl;
        cout << "\tParameter filename:  " << architectureFileName[j] << endl;

        // Calculating timing specification:
        Timing t(technologyFileName[j], architectureFileName[j]);
        // Calculating power specification ( currents ):
        Current c(&t, IOTerminationCurrentFlag);

        cout    << "_______________________________________________________"
                << "_______________________________________________________"
                << "_______________________________________________________"
                << endl;

        currentsandtimings.at(j*numberOfresults) = c.IDD2n;
        currentsandtimings.at(j*numberOfresults+1) = c.IDD3n;
        currentsandtimings.at(j*numberOfresults+2) = c.IDD0;
        currentsandtimings.at(j*numberOfresults+3) = c.IDD1;
        currentsandtimings.at(j*numberOfresults+4) = c.IDD4R;
        currentsandtimings.at(j*numberOfresults+5) = c.IDD4W;
        currentsandtimings.at(j*numberOfresults+6) = c.IDD5;
        currentsandtimings.at(j*numberOfresults+7) = t.trcd;
        currentsandtimings.at(j*numberOfresults+8) = t.tcl;
        currentsandtimings.at(j*numberOfresults+9) = t.tcl_act;
        currentsandtimings.at(j*numberOfresults+10) =t.trtp;
        currentsandtimings.at(j*numberOfresults+11) =t.tccd;
        currentsandtimings.at(j*numberOfresults+12) =t.tccd_act;
        currentsandtimings.at(j*numberOfresults+13) =t.tras;
        currentsandtimings.at(j*numberOfresults+14) =t.twr;
        currentsandtimings.at(j*numberOfresults+15) =t.trp;
        currentsandtimings.at(j*numberOfresults+16) =t.trc;
        currentsandtimings.at(j*numberOfresults+17) =t.trl;
        currentsandtimings.at(j*numberOfresults+18) =t.trl_act;
        currentsandtimings.at(j*numberOfresults+19) =t.trfc;
        currentsandtimings.at(j*numberOfresults+20) =t.tref1;
        currentsandtimings.at(j*numberOfresults+21) =t.n.Bankheight;
        currentsandtimings.at(j*numberOfresults+22) =t.n.tileWidth;
        currentsandtimings.at(j*numberOfresults+23) =t.n.chipwidth;
        currentsandtimings.at(j*numberOfresults+24) =t.n.chipheight;
        currentsandtimings.at(j*numberOfresults+25) =t.n.chiparea;
        currentsandtimings.at(j*numberOfresults+26) =(float)t.n.Freq;
        currentsandtimings.at(j*numberOfresults+27) =(float)(1/t.tccd)*1000;
        currentsandtimings.at(j*numberOfresults+28) =t.ActFreq;
        currentsandtimings.at(j*numberOfresults+29) = (1.0/t.n.Freq)*1000.0;

        //Results here are being parsed and placed in separate json files
        ResultParser result( t , c );
        result.jsonwriter(j+1);
    }
    cout << setw(32);

    resultsfile << "Label, ";
    for(int i=0; i<numberOfConfigurations; i++)
    {
    resultsfile << "Technology filename: " << technologyFileName[i]
                << "  Parameter filename: " << architectureFileName[i];
    if(i!= numberOfConfigurations -1) { resultsfile<<","; }

    cout << "(" << i+1 << ") " << setw(13);
    }
    resultsfile << endl;
    cout << "\n";

    printresult("IDD2n(in mA)", 0,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("IDD3n(in mA)", 1,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("IDD0(in mA)",  2,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("IDD1(in mA)",  3,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("IDD4R(in mA)", 4,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("IDD4W(in mA)", 5,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("IDD5(in mA)",  6,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("trcd(in ns)",  7,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("tcl(in ns)",   8,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("tcl_act(in ns)",9,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("trtp(in ns)",  10,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("tccd(in ns)",  11,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("tccd_act(in ns)",12,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("tras(in ns)",  13,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("twr(in ns)",   14,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("trp(in ns)",   15,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("trc(in ns)",   16,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("trl(in ns)",   17,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("trl_act(in ns)",18,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("trfc(in ns)",  19,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("tref1(in ns)", 20,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("Bank Height(in um)",21,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("Bank Width(in um)", 22,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("Chip Width(in um)", 23,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("Chip Height(in um)",24,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("Chip Area(in mm^2)",25,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("Frequency(in MHz)", 26,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("Max Core Freq(in MHz)",27,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("Act Core Freq(in MHz)",28,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );
    printresult("clk(in ns)",29,
            numberOfConfigurations, numberOfresults,
            currentsandtimings, resultsfile );

    //Some cleaning up...
    resultsfile.close();

}
