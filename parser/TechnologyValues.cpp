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

#include "TechnologyValues.h"

void
TechnologyValues::technologyValuesInitialize()
{
    techFileName = "";
    archFileName = "";

    technologyNode = 0*drs::nanometer;
    capacitancePerBLCell = 0*drs::attofarads_per_cell;
    resistancePerBLCell = 0*drs::ohm_per_cell;
    capacitancePerWLCell = 0*drs::attofarads_per_cell;
    resistancePerWLCell = 0*drs::ohm_per_cell;
    capacitancePerCell = 0*drs::picofarads_per_cell;
    resistancePerCell = 0*drs::ohm_per_cell;
    wireResistance = 0*drs::ohm_per_millimeter;
    wireCapacitance = 0*drs::femtofarad_per_millimeter;
    cellWidth = 0*drs::micrometer_per_cell;
    cellHeight = 0*drs::micrometer_per_cell;
    cellsPerLWL = 0*drs::cell_per_subarray;
    cellsPerLWLRedundancy = 0*drs::cell_per_subarray;
    cellsPerLBL = 0*drs::cell_per_subarray;
    cellsPerLBLRedundancy = 0*drs::cell_per_subarray;
    BLSenseAmpHeight = 0*drs::micrometer;
    WLDriverWidth = 0*drs::micrometer;
    GWLDriverResistance = 0*si::ohm;
    LWLDriverResistance = 0*drs::ohm_per_subarray;
    WRResistance = 0*drs::ohm_per_subarray;
    CSLDriverResistance = 0*si::ohm;
    GDLDriverResistance = 0*si::ohm;
    DQDriverResistance = 0*si::ohm;
    Issa = 0*drs::microampere;
    vpp = 0*si::volt;
    vcc = 0*si::volt;
    backgroundCurrentSlope = 0*drs::milliamperes_per_megahertz_clock;
    backgroundCurrentOffset = 0*drs::milliampere;
    IddOcdRcvAtFrequencyPoint = 0*drs::milliampere;
    IddOcdRcvFrequencyPoint = 0*drs::megahertz_clock;

    dramType = "";
    is3D = false;
    vaultsPerLayer = 0;
    dramSize = 0*drs::gibibit;
    nBanks = 0*drs::bank;
    nHorizontalBanks = 0*drs::bank;
    nVerticalBanks = 0*drs::bank;
    Interface = 16;
    dramFreq = 0*drs::megahertz_clock;
    dramCoreFreq = 0*drs::megahertz_clock;
    Prefetch = 0;
    additionalLatencyTrl = 0*drs::clock;
    pageStorage = 0*drs::kibibyte_per_page;
    DLL = "";
    tRef1Required = 0*drs::microsecond;
    banksRefreshFactor = 0;
    subArrayToPageFactor = 0;
    retentionTime = 0*drs::millisecond;
    tilesPerBank = 0*drs::tile_per_bank;
    pageSpanningFactor = 0*drs::page_per_tile;
    BLArchitecture = "";

    warning = "";
}

double
TechnologyValues::getJSONNumber(const rapidjson::Document& jsonDoc,
                                const char* memberName)
{
    if ( jsonDoc.HasMember( memberName ) == false )
    {
        string exceptionMsgThrown;
        exceptionMsgThrown.append("[ERROR] ");
        exceptionMsgThrown.append("Could not find member \"");
        exceptionMsgThrown.append(memberName);
        exceptionMsgThrown.append("\" in JSON document ");
        exceptionMsgThrown.append(techFileName);
        exceptionMsgThrown.append("!\n");
        throw exceptionMsgThrown;
    }
    if ( jsonDoc[ memberName ].IsNumber() == false )
    {
        string exceptionMsgThrown;
        exceptionMsgThrown.append("[ERROR] ");
        exceptionMsgThrown.append("Member \"");
        exceptionMsgThrown.append(memberName);
        exceptionMsgThrown.append("\" in JSON document ");
        exceptionMsgThrown.append(techFileName);
        exceptionMsgThrown.append(" is expected to be a number!\n");
        throw exceptionMsgThrown;
    }

    return jsonDoc[ memberName ].GetDouble();
}

string
TechnologyValues::getJSONString(const rapidjson::Document& jsonDoc,
                                const char* memberName)
{
    if ( jsonDoc.HasMember( memberName ) == false )
    {
        string exceptionMsgThrown;
        exceptionMsgThrown.append("[ERROR] ");
        exceptionMsgThrown.append("Could not find member \"");
        exceptionMsgThrown.append(memberName);
        exceptionMsgThrown.append("\" in JSON document ");
        exceptionMsgThrown.append(techFileName);
        exceptionMsgThrown.append("!\n");
        throw exceptionMsgThrown;
    }
    if ( jsonDoc[ memberName ].IsString() == false )
    {
        string exceptionMsgThrown;
        exceptionMsgThrown.append("[ERROR] ");
        exceptionMsgThrown.append("Member \"");
        exceptionMsgThrown.append(memberName);
        exceptionMsgThrown.append("\" in JSON document ");
        exceptionMsgThrown.append(techFileName);
        exceptionMsgThrown.append(" is expected to be a string!\n");
        throw exceptionMsgThrown;
    }

    return jsonDoc[ memberName ].GetString();
}

void 
TechnologyValues::readjson(const string& t,const string& p)
{
    techFileName = t;
    archFileName = p;

    // Try to open technology file given by the user
    ifstream techFile(techFileName);
    // Test if file was (and still is) opened
    if ( techFile.is_open() == false ) {
        string exceptionMsgThrown;
        exceptionMsgThrown.append("[ERROR] ");
        exceptionMsgThrown.append("Could not open technology file: ");
        exceptionMsgThrown.append(techFileName);
        exceptionMsgThrown.append("!\n");
        throw exceptionMsgThrown;
    }

    // Find length of the file
    int techFileLength;
    techFile.seekg(0, ios::end);
    techFileLength = techFile.tellg();
    techFile.seekg(0, ios::beg);

    // Create an internal copy as a C-style string
    char* techFileText = new char[techFileLength + 1];
    techFile.read(techFileText, techFileLength);
    techFileText[ techFileLength ] = '\0';

    // Close the file
    techFile.close();

    // Parse the file as a JSON Document
    rapidjson::Document techDocument;
    techDocument.Parse(techFileText);
    if ( techDocument.HasParseError() ) {
        string exceptionMsgThrown;
        exceptionMsgThrown.append("[ERROR] ");
        exceptionMsgThrown.append("Could not parse ");
        exceptionMsgThrown.append(techFileName);
        exceptionMsgThrown.append(" as a JSON document.\n");
        throw exceptionMsgThrown;
    }

    try {
        //Technology node in nm
        technologyNode = getJSONNumber(techDocument, "Technologynode")
                         * drs::nanometer;

        //Bitline per cell capa
        capacitancePerBLCell = getJSONNumber(techDocument, "BLpercellcapa")
                               * drs::attofarads_per_cell;

        //Bitline per cell resistance
        resistancePerBLCell = getJSONNumber(techDocument, "BLpercellresistance")
                              * drs::ohm_per_cell;
        //Wordline per cell capa
        capacitancePerWLCell = getJSONNumber(techDocument, "WLpercellcapa")
                               * drs::attofarads_per_cell;

        //Wordline per cell resistance
        resistancePerWLCell = getJSONNumber(techDocument, "WLpercellresistance")
                              * drs::ohm_per_cell;

        //cell capa
        capacitancePerCell = getJSONNumber(techDocument, "cellcapa")
                             * drs::picofarads_per_cell;

        //cell resistance
        resistancePerCell = getJSONNumber(techDocument, "cellresistance")
                            * drs::ohm_per_cell;

        //wire resistance in ohm/mm
        wireResistance = getJSONNumber(techDocument, "wireresistance")
                         * drs::ohm_per_millimeter;

        //wire capa in ff/mm
        wireCapacitance = getJSONNumber(techDocument, "wirecapa")
                          * drs::femtofarad_per_millimeter;

        //cell width
        cellWidth = getJSONNumber(techDocument, "cellwidth")
                    * drs::micrometers_per_cell;

        //cell height
        cellHeight = getJSONNumber(techDocument, "cellheight")
                     * drs::micrometers_per_cell;

        //cells per subarray row
        cellsPerLWL = getJSONNumber(techDocument, "cellsperrow")
                      * drs::cell_per_subarray;

        //cells per subarray row redundancy
        cellsPerLWLRedundancy = getJSONNumber(techDocument, "cellsperrowredundancy")
                                * drs::cell_per_subarray;

        //cells per subarray column
        cellsPerLBL = getJSONNumber(techDocument, "cellspercolumn")
                      * drs::cell_per_subarray;

        //cells per subarray column redundancy
        cellsPerLBLRedundancy = getJSONNumber(techDocument, "cellspercolumnredundancy")
                                * drs::cell_per_subarray;

        //sense amp height
        BLSenseAmpHeight = getJSONNumber(techDocument, "blsa-height")
                           * drs::micrometer;

        //wordline driver width
        WLDriverWidth = getJSONNumber(techDocument, "WL-driver")
                        * drs::micrometer;

        //global wordline driver resistance in ohm
        GWLDriverResistance = getJSONNumber(techDocument, "GWLDresistance")
                              * si::ohm;

        //Local wordline driver resistance in ohm
        LWLDriverResistance = getJSONNumber(techDocument, "LWDresistance")
                              * drs::ohm_per_subarray;

        //WRrestore resistance
        WRResistance = getJSONNumber(techDocument, "WRresistance")
                       * drs::ohm_per_subarray;

        //CSL driver resistance in ohm
        CSLDriverResistance = getJSONNumber(techDocument, "CSLDresistance")
                              * si::ohm;
        //GDL driver resistance in ohm
        GDLDriverResistance = getJSONNumber(techDocument, "GDLDresistance")
                              * si::ohm;
        //DQ driver resistance in ohm
        DQDriverResistance = getJSONNumber(techDocument, "DQDresistance")
                             * si::ohm;
        //current of SSA in milliamperes
        Issa = getJSONNumber(techDocument, "I_SSA")
               * drs::microampere;
        //voltage vpp
        vpp = getJSONNumber(techDocument, "vpp")
              * si::volt;
        //voltage vcc
        vcc = getJSONNumber(techDocument, "vcc")
              * si::volt;
        //backgroundcurrentslope
        backgroundCurrentSlope = getJSONNumber(techDocument, "Backgroundcurrentslope")
                                 * drs::milliamperes_per_megahertz_clock;

        //backgroundcurrentoffset
        backgroundCurrentOffset = getJSONNumber(techDocument, "Backgroundcurrentoffset")
                                  * drs::milliampere;

        //Current per IO pin (Off Channel Driver)
        IddOcdRcvAtFrequencyPoint = getJSONNumber(techDocument, "idd_ocd")
                                    * drs::milliampere;

        //IDD pro IO for OCD
        IddOcdRcvFrequencyPoint = getJSONNumber(techDocument, "idd_ocd_freq")
                                  * drs::megahertz_clock;

        //Row decoder (between tiles) width
        rowDecoderWidth = getJSONNumber(techDocument, "rowDecoderWidth")
                          * drs::micrometer;

        //Column decoder (between tiles) width
        colDecoderHeight = getJSONNumber(techDocument, "colDecoderHeight")
                           * drs::micrometer;

        //DQ driver (between banks) height
        DQDriverHeight = getJSONNumber(techDocument, "DQDriverHeight")
                         * drs::micrometer;

        //Height of the TSV area needed for each bank I/O
        TSVHeight = getJSONNumber(techDocument, "TSVHeight")
                    * drs::micrometer;

    } catch(string exceptionMsgThrown) {
        throw exceptionMsgThrown;
    }




    // Try to open architecture file given by the user
    ifstream archFile(archFileName);
    // Test if file was (and still is) opened
    if ( archFile.is_open() == false ) {
        string exceptionMsgThrown;
        exceptionMsgThrown.append("[ERROR] ");
        exceptionMsgThrown.append("Could not open architecture file: ");
        exceptionMsgThrown.append(archFileName);
        exceptionMsgThrown.append("!\n");
        throw exceptionMsgThrown;
    }

    // Find length of the file
    int archFileLength;
    archFile.seekg(0, ios::end);
    archFileLength = archFile.tellg();
    archFile.seekg(0, ios::beg);

    // Create an internal copy as a C-style string
    char* archFileText = new char[archFileLength + 1];
    archFile.read(archFileText, archFileLength);
    archFileText[ archFileLength ] = '\0';

    // Close the file
    archFile.close();

    // Parse the file as a JSON Document
    rapidjson::Document archDocument;
    archDocument.Parse(archFileText);
    if ( archDocument.HasParseError() ) {
        string exceptionMsgThrown;
        exceptionMsgThrown.append("[ERROR] ");
        exceptionMsgThrown.append("Could not parse ");
        exceptionMsgThrown.append(archFileName);
        exceptionMsgThrown.append(" as a JSON document.\n");
        throw exceptionMsgThrown;
    }

    try {
        //DRAM Type
        dramType = getJSONString(archDocument, "DRAMType");

        //3D ON/OFF Feature
        //set 3D on for HMC/WideIO
        is3D = ( getJSONString(archDocument, "3D") == "ON" );

        // vaults per layer
        // set to 0 for non 3D DRAMs
        vaultsPerLayer = getJSONNumber(archDocument, "Vaultsperlayer");

        //size of DRAM
        dramSize = getJSONNumber(archDocument, "Size")
                         * drs::gibibit;

        //# of banks
        nBanks = getJSONNumber(archDocument, "Numberofbanks")
                         * drs::bank;

        //# of banks in the row direction
        nHorizontalBanks = getJSONNumber(archDocument, "Numberofhorizontalbanks")
                         * drs::bank;

        //# of banks in the column direction
        nVerticalBanks = getJSONNumber(archDocument, "Numberofverticalbanks")
                         * drs::bank;

        //Interface
        Interface = getJSONNumber(archDocument, "Interface");

        //DRAM Frequency
        dramFreq = getJSONNumber(archDocument, "Freq")
                         * drs::megahertz_clock;

        //DRAM Core Frequency
        //if this value is not specified then calculate this value:
        //Core Freq= Freq / (n.prefetch / n.DataRate)
        dramCoreFreq = getJSONNumber(archDocument, "CoreFreq")
                         * drs::megahertz_clock;

        //Number of Prefetch
        Prefetch = getJSONNumber(archDocument, "Prefetch");

        //additional latency required for trl calculation
        additionalLatencyTrl = getJSONNumber(archDocument, "additionallatency")
                         * drs::clock;

        // Row buffer size this value is given in KBytes (Hard conversion needed)
        pageStorage = getJSONNumber(archDocument, "Rowbuffersize")
                         * drs::kibibyte_per_page;


        // DLLON/OFF Feature
        DLL = getJSONString(archDocument, "DLL");

        // Required tref by user
        tRef1Required = getJSONNumber(archDocument, "Requiredrefreshperiod")
                         * drs::microseconds;

        // Ratio of banks refreshed pro command
        banksRefreshFactor = getJSONNumber(archDocument, "banksrefreshfactor");

        // Subarray to rowbuffer factor
        subArrayToPageFactor = getJSONNumber(archDocument, "subArrayToPageFactor");

        // Retention time
        retentionTime = getJSONNumber(archDocument, "retentiontime")
                         * drs::millisecond;

        // Number of tiles per bank
        tilesPerBank = getJSONNumber(archDocument, "tilesperbank")
                         * drs::tile_per_bank;

        // Spanning factor of pages across tiles
        pageSpanningFactor = getJSONNumber(archDocument, "pageSpanningFactor")
                         * drs::page_per_tile;

        // DRAM Bitline Architecture: OPEN or FOLDED bit-line
        BLArchitecture = getJSONString(archDocument, "bitlineArchitecture");


    //  !!!!!!!! TIMING VARIABLES WHICH WHERE HARDCODED IN THE ORIGINAL VERSION !!!!!!!!
        //Driver offset !!!  TODO: What exactly is it?  !!!
        driverOffset = getJSONNumber(archDocument, "driverOffset")
                         * drs::nanoseconds;

        //SSA Delay !!!  TODO: Check value !!!
        BitlineSenseAmpDelay = getJSONNumber(archDocument, "BLSADelay")
                         * drs::nanoseconds;

        //Load capacitance !!!  TODO: What exactly is it?  !!!
        CSLLoadCapacitance = getJSONNumber(archDocument, "CSLLoadCapacitance")
                         * drs::femtofarads_per_bank;

        //Command decoder latency !!!  TODO: What exactly is it?  !!!
        cmdDecoderLatency = getJSONNumber(archDocument, "cmdDecoderLatency")
                         * drs::nanoseconds;

        //Internal latency !!!  TODO: What exactly is it?  !!!
        interfaceLatency = getJSONNumber(archDocument, "interfaceLatency")
                         * drs::nanoseconds;

        //I/O latency !!!  TODO: What exactly is it?  !!!
        IODelay = getJSONNumber(archDocument, "IODelay")
                         * drs::nanoseconds;

        //Delay for SSA precharging !!!  TODO: What exactly is it?  !!!
        SSAPrechargeDelay = getJSONNumber(archDocument, "SSAPrechargeDelay")
                         * drs::nanoseconds;

        //Security margin !!!  TODO: What exactly is it?  !!!
        securityMargin = getJSONNumber(archDocument, "securityMargin")
                         * drs::nanoseconds;

        //Equalizer delay !!!  TODO: What exactly is it?  !!!
        equalizerDelay = getJSONNumber(archDocument, "equalizerDelay")
                         * drs::nanoseconds;

        //Act cmd delay !!!  TODO: What exactly is it?  !!!
        actCmdDelay = getJSONNumber(archDocument, "actCmdDelay")
                         * drs::nanoseconds;

        //pre cmd delay !!!  TODO: What exactly is it?  !!!
        preCmdDelay = getJSONNumber(archDocument, "preCmdDelay")
                         * drs::nanoseconds;

        //offset !!!  TODO: What exactly is it?  !!!
        offset = getJSONNumber(archDocument, "offset")
                         * drs::nanoseconds;

    } catch(string exceptionMsgThrown) {
        throw exceptionMsgThrown;
    }

}
