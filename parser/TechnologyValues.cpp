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



#include "TechnologyValues.h"

void
TechnologyValues::technologyValuesInitialize()
{
    techFileName = "";
    archFileName = "";

    technologyNode = INVALID_VALUE*drs::nanometer;
    vpp = INVALID_VALUE*si::volt;
    vdd = INVALID_VALUE*si::volt;
    wireResistance = INVALID_VALUE*drs::ohm_per_millimeter;
    wireCapacitance = INVALID_VALUE*drs::femtofarad_per_millimeter;
    capacitancePerCell = INVALID_VALUE*drs::femtofarads;
    resistancePerCell = INVALID_VALUE*drs::kiloohm;
    cellWidth = INVALID_VALUE*drs::micrometer;
    cellHeight = INVALID_VALUE*drs::micrometer;
    capacitancePerBLCell = INVALID_VALUE*drs::attofarads;
    resistancePerBLCell = INVALID_VALUE*drs::ohm;
    capacitancePerWLCell = INVALID_VALUE*drs::attofarads;
    resistancePerWLCell = INVALID_VALUE*drs::ohm;
    BLSenseAmpHeight = INVALID_VALUE*drs::micrometer;
    LWLDriverWidth = INVALID_VALUE*drs::micrometer;
    LWLDriverResistance = INVALID_VALUE*drs::ohm;
    rowDecoderWidth = INVALID_VALUE*drs::micrometers;
    GWLDriverResistance = INVALID_VALUE*si::ohm;
    Issa = INVALID_VALUE*drs::microampere_per_bit;
    WRDriverResistance = INVALID_VALUE*drs::ohm;
    colDecoderHeight = INVALID_VALUE*drs::micrometers;
    CSLDriverResistance = INVALID_VALUE*si::ohms;
    CSLLoadCapacitance = INVALID_VALUE*drs::femtofarads;
    GDLDriverResistance = INVALID_VALUE*si::ohms;
    DQDriverHeight = INVALID_VALUE*drs::micrometers;
    DQtoTSVWireLength = INVALID_VALUE*drs::micrometers;
    DQDriverResistance = INVALID_VALUE*si::ohms;
    idd2nFreqSlope = INVALID_VALUE*drs::milliamperes_per_megahertz_clock;
    idd2nTempAlpha = INVALID_VALUE*drs::milliamperes;
    idd2nTempBeta = INVALID_VALUE*drs::eergeds;
    idd2nRefTemp = INVALID_VALUE*bu::celsius::degrees;
    idd2nOffset = INVALID_VALUE*drs::milliamperes;
    IddOcdRcvSlope = INVALID_VALUE*drs::microamperes_per_megahertz_clock;
    fullySharedResourcesCurrent = INVALID_VALUE*drs::milliamperes;
    semiSharedResourcesCurrent = INVALID_VALUE*drs::milliamperes;
    nBanksPerSemiSharedResource = INVALID_VALUE;
    TSVHeight = INVALID_VALUE*drs::micrometers;
    additionalLatencyTrl = INVALID_VALUE*drs::clocks;
    driverEnableDelay = INVALID_VALUE*drs::nanoseconds;
    inOutSSADelay = INVALID_VALUE*drs::nanoseconds;
    cmdDecoderDelay = INVALID_VALUE*drs::nanoseconds;
    IODelay = INVALID_VALUE*drs::nanoseconds;
    SSAPrechargeDelay = INVALID_VALUE*drs::nanoseconds;
    tWRMargin = INVALID_VALUE*drs::nanoseconds;
    equalizerDelay = INVALID_VALUE*drs::nanoseconds;
    vppPumpsEfficiency = INVALID_VALUE;

    dramType = "";
    is3D = false;
    isDLL = false;
    hasExternalVpp = false;
    channelSize = INVALID_VALUE*drs::gibibit;
    nBanks = INVALID_VALUE;
    nHorizontalBanks = INVALID_VALUE;
    nVerticalBanks = INVALID_VALUE;
    cellsPerLWL = INVALID_VALUE;
    cellsPerLWLRedundancy = INVALID_VALUE;
    cellsPerLBL = INVALID_VALUE;
    cellsPerLBLRedundancy = INVALID_VALUE;
    interface = INVALID_VALUE*drs::bit;
    prefetch = INVALID_VALUE;
    dramFreq = INVALID_VALUE*drs::megahertz_clock;
    dramCoreFreq = INVALID_VALUE*drs::megahertz_clock;
    nTilesPerBank = INVALID_VALUE;
    pageStorage = INVALID_VALUE*drs::kibibyte;
    pageSpanningFactor = INVALID_VALUE;
    BLArchitecture = "";
    subArrayToPageFactor = INVALID_VALUE;
    retentionTime = INVALID_VALUE*drs::millisecond;
    trefIBase = INVALID_VALUE*drs::microsecond;
    refreshMode = INVALID_VALUE;
    temperature = INVALID_VALUE*bu::celsius::degrees;

    warning = "";
}

double
TechnologyValues::getJSONNumber(const rapidjson::Document& jsonDoc,
                                const char* memberName,
                                const string& attributeType)
{
  if ( jsonDoc.HasMember( memberName ) == false )
  {
    if ( attributeType == "mandatory" ) {
      string exceptionMsgThrown;
      exceptionMsgThrown.append("[ERROR] ");
      exceptionMsgThrown.append("Could not find member \"");
      exceptionMsgThrown.append(memberName);
      exceptionMsgThrown.append("\" in JSON documents ");
      exceptionMsgThrown.append(techFileName);
      exceptionMsgThrown.append(" or ");
      exceptionMsgThrown.append(archFileName);
      exceptionMsgThrown.append("!\n");
      throw exceptionMsgThrown;
    }
    else if ( attributeType == "optional" ) {
      return INVALID_VALUE;
    }
    else {
      std::string exceptionMsgThrown("[ERROR] ");
      exceptionMsgThrown.append("Unexpected behaviour - ");
      exceptionMsgThrown.append("could not decide on attribute type. ");
      exceptionMsgThrown.append("Attribute was \"");
      exceptionMsgThrown.append(memberName);
      exceptionMsgThrown.append("\". ");
      exceptionMsgThrown.append("Attribute type was \"");
      exceptionMsgThrown.append(attributeType);
      exceptionMsgThrown.append("\".");
      throw exceptionMsgThrown;
    }
  }
  if ( jsonDoc[ memberName ].IsNumber() == false )
  {
    string exceptionMsgThrown;
    exceptionMsgThrown.append("[ERROR] ");
    exceptionMsgThrown.append("Member \"");
    exceptionMsgThrown.append(memberName);
    exceptionMsgThrown.append("\" in JSON documents ");
    exceptionMsgThrown.append(techFileName);
    exceptionMsgThrown.append(" or ");
    exceptionMsgThrown.append(archFileName);
    exceptionMsgThrown.append(" is expected to be a number!\n");
    throw exceptionMsgThrown;
  }

  return jsonDoc[ memberName ].GetDouble();
}

double
TechnologyValues::getJSONNumber(const rapidjson::Document& jsonDoc,
                                const char* memberName,
                                const string& attributeType,
                                double defaultValue)
{
  double valueFromFile, returnValue;
  valueFromFile = getJSONNumber(jsonDoc, memberName, attributeType);

  if ( valueFromFile == INVALID_VALUE ) {
    returnValue = defaultValue;
  }
  else {
    returnValue = valueFromFile;
  }
  return returnValue;
}

string
TechnologyValues::getJSONString(const rapidjson::Document& jsonDoc,
                                const char* memberName,
                                const string& attributeType)
{
  if ( jsonDoc.HasMember( memberName ) == false )
  {
    if ( attributeType == "mandatory" ) {
      string exceptionMsgThrown;
      exceptionMsgThrown.append("[ERROR] ");
      exceptionMsgThrown.append("Could not find member \"");
      exceptionMsgThrown.append(memberName);
      exceptionMsgThrown.append("\" in JSON documents ");
      exceptionMsgThrown.append(techFileName);
      exceptionMsgThrown.append(" or ");
      exceptionMsgThrown.append(archFileName);
      exceptionMsgThrown.append("!\n");
      throw exceptionMsgThrown;
    }
    else if ( attributeType == "optional" ) {
      return "";
    }
    else {
      std::string exceptionMsgThrown("[ERROR] ");
      exceptionMsgThrown.append("Unexpected behaviour - ");
      exceptionMsgThrown.append("could not decide on attribute type. ");
      exceptionMsgThrown.append("Attribute was \"");
      exceptionMsgThrown.append(memberName);
      exceptionMsgThrown.append("\". ");
      exceptionMsgThrown.append("Attribute type was \"");
      exceptionMsgThrown.append(attributeType);
      exceptionMsgThrown.append("\".");
      throw exceptionMsgThrown;
    }
  }
  if ( jsonDoc[ memberName ].IsString() == false )
  {
    string exceptionMsgThrown;
    exceptionMsgThrown.append("[ERROR] ");
    exceptionMsgThrown.append("Member \"");
    exceptionMsgThrown.append(memberName);
    exceptionMsgThrown.append("\" in JSON documents ");
    exceptionMsgThrown.append(techFileName);
    exceptionMsgThrown.append(" or ");
    exceptionMsgThrown.append(archFileName);
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
        technologyNode = getJSONNumber(techDocument,
                                       "TechnologyNode[nm]",
                                       "mandatory")
                         * drs::nanometer;

        //voltage vpp
        vpp = getJSONNumber(techDocument,
                            "Vpp[V]",
                            "mandatory")
              * si::volt;
        //voltage vdd
        vdd = getJSONNumber(techDocument,
                            "Vdd[V]",
                            "mandatory")
              * si::volt;

        //wire resistance in ohm/mm
        wireResistance = getJSONNumber(techDocument,
                                       "WireResistance[Ohm/mm]",
                                       "mandatory")
                         * drs::ohm_per_millimeter;

        //wire capa in ff/mm
        wireCapacitance = getJSONNumber(techDocument,
                                        "WireCapacitance[fF/mm]",
                                        "mandatory")
                          * drs::femtofarad_per_millimeter;

        //cell capa
        capacitancePerCell = getJSONNumber(techDocument,
                                           "CellCapacitance[fF]",
                                           "mandatory")
                             * drs::femtofarads;

        //cell resistance
        resistancePerCell = getJSONNumber(techDocument,
                                          "CellResistance[KOhm]",
                                          "mandatory")
                            * drs::kiloohm;

        //cell width
        cellWidth = getJSONNumber(techDocument,
                                  "CellWidth[um]",
                                  "mandatory")
                    * drs::micrometers;

        //cell height
        cellHeight = getJSONNumber(techDocument,
                                   "CellHeight[um]",
                                   "mandatory")
                     * drs::micrometers;

        //Bitline per cell capa
        capacitancePerBLCell = getJSONNumber(techDocument,
                                             "BitlineCapacitancePerCell[aF]",
                                             "mandatory")
                               * drs::attofarads;

        //Bitline per cell resistance
        resistancePerBLCell = getJSONNumber(techDocument,
                                            "BitlineResistancePerCell[Ohm]",
                                            "mandatory")
                              * drs::ohm;

        //Wordline per cell capa
        capacitancePerWLCell = getJSONNumber(techDocument,
                                             "WordlineCapacitancePerCell[aF]",
                                             "mandatory")
                               * drs::attofarads;

        //Wordline per cell resistance
        resistancePerWLCell = getJSONNumber(techDocument,
                                            "WordlineResistancePerCell[Ohm]",
                                            "mandatory")
                              * drs::ohm;

        //Sense amp height
        BLSenseAmpHeight = getJSONNumber(techDocument,
                                         "PrimarySenseAmpHeight[um]",
                                         "mandatory")
                           * drs::micrometer;

        //Local wordline driver width
        LWLDriverWidth = getJSONNumber(techDocument,
                                       "LocalWordlineDriverWitdh[um]",
                                       "mandatory")
                        * drs::micrometer;

        //Local wordline driver resistance in ohm
        LWLDriverResistance = getJSONNumber(techDocument,
                                            "LocalWordlineDriverResistance[Ohm]",
                                            "mandatory")
                              * drs::ohm;

        //Row decoder (between tiles) width
        rowDecoderWidth = getJSONNumber(techDocument,
                                        "RowDecoderWidth[um]",
                                        "mandatory")
                          * drs::micrometer;

        //Global wordline driver resistance in ohm
        GWLDriverResistance = getJSONNumber(techDocument,
                                            "GlobalWordlineDriverResistance[Ohm]",
                                            "mandatory")
                              * si::ohm;

        //current of SSA in milliamperes
        Issa = getJSONNumber(techDocument,
                             "SecondarySenseAmpCurrent[uA]",
                             "mandatory")
               * drs::microampere_per_bit;

        // Write Restore Driver resistance
        WRDriverResistance = getJSONNumber(techDocument,
                                           "WriteDriverResistance[Ohm]",
                                           "mandatory")
                       * drs::ohm;

        //Column decoder (between tiles) height
        colDecoderHeight = getJSONNumber(techDocument,
                                         "ColumnDecoderHeight[um]",
                                         "mandatory")
                           * drs::micrometer;

        //CSL driver resistance in ohm
        CSLDriverResistance = getJSONNumber(techDocument,
                                            "CSLDriverResistance[Ohm]",
                                            "mandatory")
                              * si::ohm;

        //CSL load capacitance
        CSLLoadCapacitance = getJSONNumber(techDocument,
                                           "CSLLoadCapacitance[fF]",
                                           "mandatory")
                         * drs::femtofarads;

        //GDL driver resistance in ohm
        GDLDriverResistance = getJSONNumber(techDocument,
                                            "GlobalDataLineDriverResistance[Ohm]",
                                            "mandatory")
                              * si::ohm;

        //DQ driver (between banks) height
        DQDriverHeight = getJSONNumber(techDocument,
                                       "DQDriverHeight[um]",
                                       "mandatory")
                         * drs::micrometer;

        //Length of the wire going from the DQ main wiring to the TSV
        DQtoTSVWireLength = getJSONNumber(techDocument,
                                          "DQtoTSVWireLength[um]",
                                          "mandatory")
                             * drs::micrometers;

        //DQ driver resistance in ohm
        DQDriverResistance = getJSONNumber(techDocument,
                                           "DQDriverResistance[Ohm]",
                                           "mandatory")
                             * si::ohm;

        //Background current slope with frequency
        idd2nFreqSlope = getJSONNumber(techDocument,
                                       "IDD2NFreqSlope[mA/MHz]",
                                       "mandatory")
                                 * drs::milliamperes_per_megahertz_clock;

        //Background current alpha coefficient (models temperature dependency)
        idd2nTempAlpha = getJSONNumber(techDocument,
                                       "IDD2NTempAlpha[mA]",
                                       "mandatory")
                                 * drs::milliamperes;

        //Background current beta coefficient (models temperature dependency)
        idd2nTempBeta = getJSONNumber(techDocument,
                                      "IDD2NTempBeta[C^-1]",
                                      "mandatory")
                                 * drs::eergeds;

        //Background current reference temperature (models temperature dependency)
        idd2nRefTemp = getJSONNumber(techDocument,
                                     "IDD2NRefTemp[C]",
                                     "mandatory")
                                 * bu::celsius::degrees;

        //Background current offset (current at ref temp and 0 MHz)
        idd2nOffset = getJSONNumber(techDocument,
                                    "IDD2NOffset[mA]",
                                    "mandatory")
                                  * drs::milliamperes;

        //Current slope per IO pin (Off Channel Driver)
        IddOcdRcvSlope = getJSONNumber(techDocument,
                                       "OCDCurrentSlope[uA/MHz]",
                                       "mandatory")
                                    * drs::microamperes_per_megahertz_clock;

        //Current of the resources shared by all banks
        fullySharedResourcesCurrent = getJSONNumber(techDocument,
                                              "FullySharedResourcesCurrent[mA]",
                                                    "mandatory")
                                      * drs::milliamperes;

        //Current of the resources shared by blocks of banks
        semiSharedResourcesCurrent = getJSONNumber(techDocument,
                                              "SemiSharedResourcesCurrent[mA]",
                                                   "mandatory")
                                     * drs::milliamperes;

        //Size of the block of banks that share the same "semi shared" resources
        nBanksPerSemiSharedResource = getJSONNumber(techDocument,
                                                "nBanksPerSemiSharedResource[]",
                                                    "mandatory");


        //Height of the TSV area needed for each bank I/O
        TSVHeight = getJSONNumber(techDocument,
                                  "TSVHeight[um]",
                                  "mandatory")
                    * drs::micrometer;

        //Additional latency required for trl calculation
        additionalLatencyTrl = getJSONNumber(techDocument,
                                             "AdditionalTRLLatency[cc]",
                                             "mandatory")
                         * drs::clock;

        //Driver enabling delay
        driverEnableDelay = getJSONNumber(techDocument,
                                          "DriverEnableDelay[ns]",
                                          "mandatory")
                         * drs::nanoseconds;

        //Signal delay from input to output of SSA
        inOutSSADelay = getJSONNumber(techDocument,
                                      "InOutSSADelay[ns]",
                                      "mandatory")
                         * drs::nanoseconds;

        //Command decoder delay - clock wave pipeline delay
        cmdDecoderDelay = getJSONNumber(techDocument,
                                        "CommandDecoderDelay[ns]",
                                        "mandatory")
                         * drs::nanoseconds;

        //I/O interface delay
        IODelay = getJSONNumber(techDocument,
                                "IODelay[ns]",
                                "mandatory")
                         * drs::nanoseconds;

        //Delay for SSA precharging
        SSAPrechargeDelay = getJSONNumber(techDocument,
                                          "SSAPrechargeDelay[ns]",
                                          "mandatory")
                         * drs::nanoseconds;

        // Security margin for Write Recovery
        tWRMargin = getJSONNumber(techDocument,
                                  "tWRMargin[ns]",
                                  "mandatory")
                         * drs::nanoseconds;

        //Equalizer circuit enabling delay
        equalizerDelay = getJSONNumber(techDocument,
                                       "EqualizerDelay[ns]",
                                       "mandatory")
                         * drs::nanoseconds;

        //Vdd -> Vpp pump circuitry efficiency
        vppPumpsEfficiency = getJSONNumber(techDocument,
                                           "VppPumpEfficiency[-]",
                                           "optional",
                                           0.3);

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
        dramType = getJSONString(archDocument,
                                 "DRAMType[-]",
                                 "mandatory");

        //3D ON/OFF Feature
        //set 3D on for HMC/WideIO/HBM
        is3D = ( getJSONString(archDocument, "3D[-]", "mandatory") == "ON" );

        // DLL ON/OFF Feature
        isDLL = ( getJSONString(archDocument, "DLL[-]", "mandatory") == "ON" );

        // External Vpp source
        string hasExternalVppStr = getJSONString(archDocument,
                                      "ExternalVPP[-]", "optional");
        if ( hasExternalVppStr == "YES" ) {
          hasExternalVpp = true;
        }
        if ( dramType.find("DDR4")    != string::npos ||
             dramType.find("HBM")     != string::npos ||
             dramType.find("WideIO")  != string::npos
        ) {
          if ( hasExternalVppStr == "" ) { // Not defined by user
            hasExternalVpp = true;
          }
          else if ( hasExternalVppStr != "YES" ) {
            warning.append("[WARNING] ");
            warning.append("DRAM type ");
            warning.append(dramType);
            warning.append(" should have external Vpp source.\n");
          }
        }

        //size of DRAM Channel
        channelSize = getJSONNumber(archDocument,
                                    "ChannelSize[Gb]",
                                    "mandatory")
                      * drs::gibibits;

        //# of banks
        nBanks = getJSONNumber(archDocument,
                               "NumberOfBanksPerChannel[]",
                               "mandatory");

        //# of banks in the row direction
        nHorizontalBanks = getJSONNumber(archDocument,
                                         "NumberOfHorizontalBanksPerChannel[]",
                                         "optional");

        //# of banks in the column direction
        nVerticalBanks = getJSONNumber(archDocument,
                                       "NumberOfVerticalBanksPerChannel[]",
                                       "optional");

        //cells per subarray row
        cellsPerLWL = getJSONNumber(archDocument,
                                    "CellsPerSubarrayRow[]",
                                    "mandatory");

        //cells per subarray row redundancy
        cellsPerLWLRedundancy = getJSONNumber(archDocument,
                                              "RedundantCellsPerSubarrayRow[]",
                                              "mandatory");

        //cells per subarray column
        cellsPerLBL = getJSONNumber(archDocument,
                                    "CellsPerSubarrayColumn[]",
                                    "mandatory");

        //cells per subarray column redundancy
        cellsPerLBLRedundancy = getJSONNumber(archDocument,
                                              "RedundantCellsPerSubarrayColumn[]",
                                              "mandatory");

        //Interface (channel-wise)
        interface = getJSONNumber(archDocument,
                                  "Interface[bit]",
                                  "mandatory")
                    * drs::bits;

        //Number of prefetched words (interface wide) per CAS
        prefetch = getJSONNumber(archDocument,
                                 "Prefetch[]",
                                 "mandatory");

        //DRAM Frequency
        dramFreq = getJSONNumber(archDocument,
                                 "Frequency[MHz]",
                                 "mandatory")
                         * drs::megahertz_clock;

        //DRAM Core Frequency
        dramCoreFreq = getJSONNumber(archDocument,
                                     "CoreFrequency[MHz]",
                                     "mandatory")
                         * drs::megahertz_clock;

        // Number of tiles per bank
        nTilesPerBank = getJSONNumber(archDocument,
                                      "TilesPerBank[]",
                                      "mandatory");

        // Page size - number of local sense amp. activated in a row access
        pageStorage = getJSONNumber(archDocument,
                                    "PageSize[KB]",
                                    "mandatory")
                         * drs::kibibyte;

        // Spanning factor of pages across tiles
        pageSpanningFactor = getJSONNumber(archDocument,
                                           "PageSpanningFactor[]",
                                           "mandatory");

        // Subarray to page factor (inverse percentage bitlines that are sensed per row access)
        subArrayToPageFactor = getJSONNumber(archDocument,
                                             "SubarrayToPageFactor[]",
                                             "mandatory");

        // DRAM Bitline Architecture: OPEN or FOLDED bitline
        BLArchitecture = getJSONString(archDocument,
                                       "BitlineArchitecture[-]",
                                       "mandatory");

        // Retention time
        retentionTime = getJSONNumber(archDocument,
                                      "RetentionTime[ms]",
                                      "mandatory")
                         * drs::millisecond;

        // Normal mode and temp. average interval between AR commands
        trefIBase = getJSONNumber(archDocument,
                                  "tREFI(base)[us]",
                                  "mandatory")
                         * drs::microsecond;

        // Refresh mode according to JEDEC (eg., JESD79-4B)
        refreshMode = getJSONNumber(archDocument,
                                    "RefreshMode[]",
                                    "mandatory");

        // Temperature used for timings and currents calculations
        temperature = getJSONNumber(archDocument,
                                    "Temperature[C]",
                                    "mandatory")
                         * bu::celsius::degrees;

    } catch(string exceptionMsgThrown) {
        throw exceptionMsgThrown;
    }

}
