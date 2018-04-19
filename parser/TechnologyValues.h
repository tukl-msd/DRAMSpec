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



//This class presents the main key technology points used by this tool.
//The values are read from a json file 
#ifndef TECHNOLOGYVALUES_H
#define TECHNOLOGYVALUES_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <stdio.h>
#include <string>

#include "rapidjson/include/rapidjson/document.h"

#include "../utils/utils.h"

#include "../expandedBoostUnits/Units/dramSpec_units.h"
#include <boost/units/conversion.hpp>

namespace bu=boost::units;
namespace si=boost::units::si;
namespace inf=boost::units::information;
namespace drs=boost::units::dramspec;

using namespace std;

class TechnologyValues
{
  public:

    TechnologyValues() //Empty constructor for test proposes
    {
        technologyValuesInitialize();
    }

    TechnologyValues(const string& technologyFileName,
                     const string& architectureFileName)
    {
        technologyValuesInitialize();
        try {
            readjson(technologyFileName, architectureFileName);
        } catch(string exceptionMsgThrown) {
            throw exceptionMsgThrown;
        }

    }

    // Technologyfile name to be read
    string techFileName;

    // Parameter file name to be read
    string archFileName;

    //Technology node in nm
    bu::quantity<drs::nanometer_unit> technologyNode;

    //voltage vpp
    bu::quantity<si::electric_potential> vpp;

    //voltage vdd
    bu::quantity<si::electric_potential> vdd;

    //wire resistance in ohm/mm
    bu::quantity<drs::ohm_per_millimeter_unit> wireResistance;

    //wire capa in ff/mm
    bu::quantity<drs::femtofarad_per_millimeter_unit> wireCapacitance;

    //cell capacitance
    bu::quantity<drs::femtofarad_unit> capacitancePerCell;

    //cell resistance
    bu::quantity<drs::kiloohm_unit> resistancePerCell;

    //cell width
    bu::quantity<drs::micrometer_unit> cellWidth;

    //cell height
    bu::quantity<drs::micrometer_unit> cellHeight;

    //Bitline per cell capa
    bu::quantity<drs::attofarad_unit> capacitancePerBLCell;

    //Bitline per cell resistance
    bu::quantity<drs::ohm_unit> resistancePerBLCell;

    //Wordline per cell capa
    bu::quantity<drs::attofarad_unit> capacitancePerWLCell;

    //Wordline per cell resistance
    bu::quantity<drs::ohm_unit> resistancePerWLCell;

    //sense amp height
    bu::quantity<drs::micrometer_unit> BLSenseAmpHeight;

    //wordline driver width
    bu::quantity<drs::micrometer_unit> LWLDriverWidth;

    //Local wordline driver resistance in ohm
    bu::quantity<drs::ohm_unit> LWLDriverResistance;

    //Row decoder (between tiles) width
    bu::quantity<drs::micrometer_unit> rowDecoderWidth;

    //global wordline driver resistance in ohm
    bu::quantity<drs::ohm_unit> GWLDriverResistance;

    //current of SSA in microamperes
    bu::quantity<drs::microampere_per_bit_unit> Issa;

    //Write Restore Driver Resistance
    bu::quantity<drs::ohm_unit> WRDriverResistance;

    //Column decoder (between tiles) height
    bu::quantity<drs::micrometer_unit> colDecoderHeight;

    //CSL driver resistance in ohm
    bu::quantity<drs::ohm_unit> CSLDriverResistance;

    //Load capacitance
    bu::quantity<drs::femtofarad_unit> CSLLoadCapacitance;

    //GDL driver resistance in ohm
    bu::quantity<drs::ohm_unit> GDLDriverResistance;

    //DQ driver (between banks) height
    bu::quantity<drs::micrometer_unit> DQDriverHeight;

    //Length of the wire going from the DQ main wiring to the TSV
    bu::quantity<drs::micrometer_unit> DQtoTSVWireLength;

    //DQ driver resistance in ohm
    bu::quantity<drs::ohm_unit> DQDriverResistance;

    //Background current slope with frequency
    bu::quantity<drs::milliampere_per_megahertz_clock_unit> idd2nFreqSlope;

    //Background current alpha coefficient (models temperature dependency)
    bu::quantity<drs::milliampere_unit> idd2nTempAlpha;

    //Background current beta coefficient (models temperature dependency)
    bu::quantity<drs::per_temperature_unit> idd2nTempBeta;

    //Background current reference temperature (models temperature dependency)
    bu::quantity<bu::celsius::temperature> idd2nRefTemp;

    //Background current offset (current at ref temp and 0 MHz)
    bu::quantity<drs::milliampere_unit> idd2nOffset;

    //Current slope per IO pin in relation to clock frequency
    bu::quantity<drs::microampere_per_megahertz_clock_unit> IddOcdRcvSlope;

    //Current of the resources shared by all banks
    bu::quantity<drs::milliampere_unit> fullySharedResourcesCurrent;

    //Current of the resources shared by blocks of banks
    bu::quantity<drs::milliampere_unit> semiSharedResourcesCurrent;

    //Size of the block of banks that share the same "semi shared" resources
    double nBanksPerSemiSharedResource;

    //Height of the TSV area needed for each bank I/O
    bu::quantity<drs::micrometer_unit> TSVHeight;

    //Additional latency required for trl calculation
    bu::quantity<drs::clock_unit> additionalLatencyTrl;

    //Driver enabling delay
    bu::quantity<drs::nanosecond_unit> driverEnableDelay;

    //Signal delay from input to output of SSA
    bu::quantity<drs::nanosecond_unit> inOutSSADelay;

    //Command decoder delay - clock wave pipeline delay
    bu::quantity<drs::nanosecond_unit> cmdDecoderDelay;

    //I/O interface delay
    bu::quantity<drs::nanosecond_unit> IODelay;

    //Delay for SSA precharging
    bu::quantity<drs::nanosecond_unit> SSAPrechargeDelay;

    // Security margin for Write Recovery
    bu::quantity<drs::nanosecond_unit> tWRMargin;

    //Equalizer circuit enabling delay
    bu::quantity<drs::nanosecond_unit> equalizerDelay;

    //Vdd -> Vpp pump circuitry efficiency
    double vppPumpsEfficiency;



    //DRAM Type
    string dramType;

    //3D ON/OFF Feature (set for WideIO and HBM)
    bool is3D;

    // DLL ON/OFF Feature
    bool isDLL;

    // External Vpp source
    bool hasExternalVpp;

    //size of DRAM Channel
    bu::quantity<drs::gibibit_unit> channelSize;

    //# of banks
    double nBanks;

    //# of banks in the horizontal direction
    double nHorizontalBanks;

    //# of banks in the vertical direction
    double nVerticalBanks;

    //cells per subarray row
    double cellsPerLWL;

    //cells per subarray row redundancy
    double cellsPerLWLRedundancy;

    //cells per subarray column
    double cellsPerLBL;

    //cells per subarray column redundancy
    double cellsPerLBLRedundancy;

    //Interface (channel-wise)
    bu::quantity<drs::bit_unit> interface;

    //Number of prefetched words (interface wide) per CAS
    double prefetch;

    //DRAM Frequency
    bu::quantity<drs::megahertz_clock_unit> dramFreq;

    //DRAM Core Frequency
    bu::quantity<drs::megahertz_clock_unit> dramCoreFreq;

    // Number of tiles per bank
    double nTilesPerBank;

    // Page size - number of local sense amp. activated in a row access
    bu::quantity<drs::kibibyte_unit> pageStorage;

    // Spanning factor of a page across tiles
    //  How much of the page storage is in each tile
    double pageSpanningFactor;

    // Subarray to page factor (inverse percentage bitlines that are sensed per row access)
    double subArrayToPageFactor;

    // DRAM Bitline Architecture: OPEN or FOLDED bitline
    string BLArchitecture;

    // Retention time
    bu::quantity<drs::millisecond_unit> retentionTime;

    // Normal mode and temp. average interval between AR commands
    bu::quantity<drs::microsecond_unit> trefIBase;

    // Refresh mode according to JEDEC (eg., JESD79-4B)
    double refreshMode;

    // Temperature used for timings and currents calculations
    bu::quantity<bu::celsius::temperature> temperature;



    // String to output warnings
    string warning;


    void technologyValuesInitialize();

    double getJSONNumber(const rapidjson::Document& jsonDoc,
                         const char* memberName,
                         const string& attributeType);
    double getJSONNumber(const rapidjson::Document& jsonDoc,
                         const char* memberName,
                         const string& attributeType,
                         double deafultValue);

    string getJSONString(const rapidjson::Document& jsonDoc,
                         const char* memberName,
                         const string& attributeType);

    void readjson(const string& t,const string& p);

};
#endif //TECHNOLOGYVALUES_H
