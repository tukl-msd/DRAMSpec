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
    capacitancePerCell = 0*drs::femtofarads_per_cell;
    resistancePerCell = 0*drs::kiloohm_per_cell;
    wireResistance = 0*drs::ohm_per_millimeter;
    wireCapacitance = 0*drs::femtofarad_per_millimeter;
    cellWidth = 0*drs::micrometer_per_cell;
    cellHeight = 0*drs::micrometer_per_cell;
    cellsPerLWL = 0*drs::cell_per_subarray;
    cellsPerLWLRedundancy = 0*drs::cell_per_subarray;
    cellsPerLBL = 0*drs::cell_per_subarray;
    cellsPerLBLRedundancy = 0*drs::cell_per_subarray;
    BLSenseAmpHeight = 0*drs::micrometer;
    LWLDriverWidth = 0*drs::micrometer;
    GWLDriverResistance = 0*si::ohm;
    LWLDriverResistance = 0*drs::ohm_per_subarray;
    WRResistance = 0*drs::ohm_per_subarray;
    CSLDriverResistance = 0*si::ohm;
    GDLDriverResistance = 0*si::ohm;
    DQDriverResistance = 0*si::ohm;
    Issa = 0*drs::microampere_per_bit;
    vpp = 0*si::volt;
    vdd = 0*si::volt;
    backgroundCurrentSlope = 0*drs::milliamperes_per_megahertz_clock;
    backgroundCurrentOffset = 0*drs::milliampere;
    IddOcdRcvSlope = 0*drs::microamperes_per_megahertz_clock;

    dramType = "";
    is3D = false;
    dramSize = 0*drs::gibibit;
    nBanks = 0*drs::bank;
    nHorizontalBanks = 0*drs::bank;
    nVerticalBanks = 0*drs::bank;
    Interface = 0*drs::bit;
    dramFreq = 0*drs::megahertz_clock;
    dramCoreFreq = 0*drs::megahertz_clock;
    prefetch = 0;
    additionalLatencyTrl = 0*drs::clock;
    pageStorage = 0*drs::kibibyte_per_page;
    isDLL = false;
    requiredTrefI = 0*drs::microsecond;
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
        technologyNode = getJSONNumber(techDocument, "TechnologyNode[nm]")
                         * drs::nanometer;

        //voltage vpp
        vpp = getJSONNumber(techDocument, "Vpp[V]")
              * si::volt;
        //voltage vdd
        vdd = getJSONNumber(techDocument, "Vdd[V]")
              * si::volt;

        //wire resistance in ohm/mm
        wireResistance = getJSONNumber(techDocument, "WireResistance[Ohm/mm]")
                         * drs::ohm_per_millimeter;

        //wire capa in ff/mm
        wireCapacitance = getJSONNumber(techDocument, "WireCapacitance[fF/mm]")
                          * drs::femtofarad_per_millimeter;

        //cell capa
        capacitancePerCell = getJSONNumber(techDocument, "CellCapacitance[fF]")
                             * drs::femtofarads_per_cell;

        //cell resistance
        resistancePerCell = getJSONNumber(techDocument, "CellResistance[KOhm]")
                            * drs::kiloohm_per_cell;

        //cell width
        cellWidth = getJSONNumber(techDocument, "CellWidth[um]")
                    * drs::micrometers_per_cell;

        //cell height
        cellHeight = getJSONNumber(techDocument, "CellHeight[um]")
                     * drs::micrometers_per_cell;

        //Bitline per cell capa
        capacitancePerBLCell = getJSONNumber(techDocument, "BitlineCapacitancePerCell[aF]")
                               * drs::attofarads_per_cell;

        //Bitline per cell resistance
        resistancePerBLCell = getJSONNumber(techDocument, "BitlineResistancePerCell[Ohm]")
                              * drs::ohm_per_cell;
        //Wordline per cell capa
        capacitancePerWLCell = getJSONNumber(techDocument, "WordlineCapacitancePerCell[aF]")
                               * drs::attofarads_per_cell;

        //Wordline per cell resistance
        resistancePerWLCell = getJSONNumber(techDocument, "WordlineResistancePerCell[Ohm]")
                              * drs::ohm_per_cell;

        //Sense amp height
        BLSenseAmpHeight = getJSONNumber(techDocument, "PrimarySenseAmpHeight[um]")
                           * drs::micrometer;

        //Local wordline driver width
        LWLDriverWidth = getJSONNumber(techDocument, "LocalWordlineDriverWitdh[um]")
                        * drs::micrometer;

        //Local wordline driver resistance in ohm
        LWLDriverResistance = getJSONNumber(techDocument, "LocalWordlineDriverResistance[Ohm]")
                              * drs::ohm_per_subarray;

        //Row decoder (between tiles) width
        rowDecoderWidth = getJSONNumber(techDocument, "RowDecoderWidth[um]")
                          * drs::micrometer;

        //Global wordline driver resistance in ohm
        GWLDriverResistance = getJSONNumber(techDocument, "GlobalWordlineDriverResistance[Ohm]")
                              * si::ohm;

        //current of SSA in milliamperes
        Issa = getJSONNumber(techDocument, "SecondarySenseAmpCurrent[uA]")
               * drs::microampere_per_bit;

        //WRrestore resistance
        WRResistance = getJSONNumber(techDocument, "WriteDriverResistance[Ohm]")
                       * drs::ohm_per_subarray;

        //Column decoder (between tiles) height
        colDecoderHeight = getJSONNumber(techDocument, "ColumnDecoderHeight[um]")
                           * drs::micrometer;

        //CSL driver resistance in ohm
        CSLDriverResistance = getJSONNumber(techDocument, "CSLDriverResistance[Ohm]")
                              * si::ohm;

        //Load capacitance !!!  TODO: What exactly is it?  !!!
        CSLLoadCapacitance = getJSONNumber(techDocument, "CSLLoadCapacitance[fF]")
                         * drs::femtofarads_per_bank;

        //GDL driver resistance in ohm
        GDLDriverResistance = getJSONNumber(techDocument, "GlobalDataLineDriverResistance[Ohm]")
                              * si::ohm;

        //DQ driver (between banks) height
        DQDriverHeight = getJSONNumber(techDocument, "DQDriverHeight[um]")
                         * drs::micrometer;

        //DQ driver resistance in ohm
        DQDriverResistance = getJSONNumber(techDocument, "DQDriverResistance[Ohm]")
                             * si::ohm;

        //backgroundcurrentslope
        backgroundCurrentSlope = getJSONNumber(techDocument, "BackgroundCurrentSlope[mA/MHz]")
                                 * drs::milliamperes_per_megahertz_clock;

        //backgroundcurrentoffset
        backgroundCurrentOffset = getJSONNumber(techDocument, "BackgroundCurrentOffset[mA]")
                                  * drs::milliampere;

        //Current slope per IO pin (Off Channel Driver)
        IddOcdRcvSlope = getJSONNumber(techDocument, "OCDCurrentSlope[mA/MHz]")
                                    * drs::microamperes_per_megahertz_clock;


        //Height of the TSV area needed for each bank I/O
        TSVHeight = getJSONNumber(techDocument, "TSVHeight[um]")
                    * drs::micrometer;

        //additional latency required for trl calculation
        additionalLatencyTrl = getJSONNumber(techDocument, "AdditionalTRLLatency[cc]")
                         * drs::clock;

    //  !!!!!!!! TIMING VARIABLES WHICH WHERE HARDCODED IN THE ORIGINAL VERSION !!!!!!!!
        //Driver offset !!!  TODO: What exactly is it?  !!!
        driverOffset = getJSONNumber(techDocument, "DriverOffset[ns]")
                         * drs::nanoseconds;

        //SSA Delay !!!  TODO: Check value !!!
        BitlineSenseAmpDelay = getJSONNumber(techDocument, "BLSADelay[ns]")
                         * drs::nanoseconds;

        //Command decoder latency !!!  TODO: What exactly is it?  !!!
        cmdDecoderLatency = getJSONNumber(techDocument, "CommandDecoderDelay[ns]")
                         * drs::nanoseconds;

        //Internal latency !!!  TODO: What exactly is it?  !!!
        interfaceLatency = getJSONNumber(techDocument, "InterfaceDelay[ns]")
                         * drs::nanoseconds;

        //I/O latency !!!  TODO: What exactly is it?  !!!
        IODelay = getJSONNumber(techDocument, "IODelay[ns]")
                         * drs::nanoseconds;

        //Delay for SSA precharging !!!  TODO: What exactly is it?  !!!
        SSAPrechargeDelay = getJSONNumber(techDocument, "SSAPrechargeDelay[ns]")
                         * drs::nanoseconds;

        //Security margin !!!  TODO: What exactly is it?  !!!
        securityMargin = getJSONNumber(techDocument, "SecurityMargin[ns]")
                         * drs::nanoseconds;

        //Equalizer delay !!!  TODO: What exactly is it?  !!!
        equalizerDelay = getJSONNumber(techDocument, "EqualizerDelay[ns]")
                         * drs::nanoseconds;

        //Act cmd delay !!!  TODO: What exactly is it?  !!!
        actCmdDelay = getJSONNumber(techDocument, "ACTCommandDelay[ns]")
                         * drs::nanoseconds;

        //pre cmd delay !!!  TODO: What exactly is it?  !!!
        preCmdDelay = getJSONNumber(techDocument, "PRECommandDelay[ns]")
                         * drs::nanoseconds;

        //offset !!!  TODO: What exactly is it?  !!!
        offset = getJSONNumber(techDocument, "Offset[ns]")
                         * drs::nanoseconds;

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
        dramType = getJSONString(archDocument, "DRAMType[-]");

        //3D ON/OFF Feature
        //set 3D on for HMC/WideIO
        is3D = ( getJSONString(archDocument, "3D[-]") == "ON" );

        // DLL ON/OFF Feature
        isDLL = ( getJSONString(archDocument, "DLL[-]") == "ON" );

        //size of DRAM
        dramSize = getJSONNumber(archDocument, "ChannelSize[Gb]")
                         * drs::gibibit;

        //# of banks
        nBanks = getJSONNumber(archDocument, "NumberOfBanksPerChannel[]")
                         * drs::bank;

        //# of banks in the row direction
        nHorizontalBanks = getJSONNumber(archDocument, "NumberOfHorizontalBanksPerChannel[]")
                         * drs::bank;

        //# of banks in the column direction
        nVerticalBanks = getJSONNumber(archDocument, "NumberOfVerticalBanksPerChannel[]")
                         * drs::bank;

        //cells per subarray row
        cellsPerLWL = getJSONNumber(archDocument, "CellsPerSubarrayRow[]")
                      * drs::cell_per_subarray;

        //cells per subarray row redundancy
        cellsPerLWLRedundancy = getJSONNumber(archDocument, "RedundantCellsPerSubarrayRow[]")
                                * drs::cell_per_subarray;

        //cells per subarray column
        cellsPerLBL = getJSONNumber(archDocument, "CellsPerSubarrayColumn[]")
                      * drs::cell_per_subarray;

        //cells per subarray column redundancy
        cellsPerLBLRedundancy = getJSONNumber(archDocument, "RedundantCellsPerSubarrayColumn[]")
                                * drs::cell_per_subarray;

        //Interface
        Interface = getJSONNumber(archDocument, "Interface[bit]")
                    * drs::bits;

        //Number of Prefetch
        prefetch = getJSONNumber(archDocument, "Prefetch[]");

        //DRAM Frequency
        dramFreq = getJSONNumber(archDocument, "Frequency[MHz]")
                         * drs::megahertz_clock;

        //DRAM Core Frequency
        //if this value is not specified then calculate this value:
        //Core Freq= Freq / (n.prefetch / n.DataRate)
        dramCoreFreq = getJSONNumber(archDocument, "CoreFrequency[MHz]")
                         * drs::megahertz_clock;

        // Number of tiles per bank
        tilesPerBank = getJSONNumber(archDocument, "TilesPerBank[]")
                         * drs::tile_per_bank;

        // Row buffer size this value is given in KBytes (Hard conversion needed)
        pageStorage = getJSONNumber(archDocument, "PageSize[KB]")
                         * drs::kibibyte_per_page;

        // Spanning factor of pages across tiles
        pageSpanningFactor = getJSONNumber(archDocument, "PageSpanningFactor[]")
                         * drs::page_per_tile;

        // Subarray to rowbuffer factor
        subArrayToPageFactor = getJSONNumber(archDocument, "SubarrayToPageFactor[]");

        // DRAM Bitline Architecture: OPEN or FOLDED bit-line
        BLArchitecture = getJSONString(archDocument, "BitlineArchitecture[-]");

        // Retention time
        retentionTime = getJSONNumber(archDocument, "RetentionTime[ms]")
                         * drs::millisecond;

        // Required tref by user
        requiredTrefI = getJSONNumber(archDocument, "RequiredRefreshPeriod[us]")
                         * drs::microseconds;

        // Ratio of banks refreshed pro command
        banksRefreshFactor = getJSONNumber(archDocument, "BankRefreshFactor[]");

    } catch(string exceptionMsgThrown) {
        throw exceptionMsgThrown;
    }

}
