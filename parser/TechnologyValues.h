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

    //Bitline per cell capa
    bu::quantity<drs::attofarad_per_cell_unit> capacitancePerBLCell;

    //Bitline per cell resistance
    bu::quantity<drs::resistance_per_cell_unit> resistancePerBLCell;

    //Wordline per cell capa
    bu::quantity<drs::attofarad_per_cell_unit> capacitancePerWLCell;

    //Wordline per cell resistance
    bu::quantity<drs::resistance_per_cell_unit> resistancePerWLCell;

    //cell capa
    bu::quantity<drs::picofarad_per_cell_unit> capacitancePerCell;

    //cell resistance
    bu::quantity<drs::resistance_per_cell_unit> resistancePerCell;

    //wire resistance in ohm/mm
    bu::quantity<drs::ohm_per_millimeter_unit> wireResistance;

    //wire capa in ff/mm
    bu::quantity<drs::femtofarad_per_millimeter_unit> wireCapacitance;

    //cell width
    bu::quantity<drs::micrometer_per_cell_unit> cellWidth;

    //cell height
    bu::quantity<drs::micrometer_per_cell_unit> cellHeight;

    //cells per subarray row
    bu::quantity<drs::cell_per_subarray_unit> cellsPerLWL;

    //cells per subarray row redundancy
    bu::quantity<drs::cell_per_subarray_unit> cellsPerLWLRedundancy;

    //cells per subarray column
    bu::quantity<drs::cell_per_subarray_unit> cellsPerLBL;

    //cells per subarray column redundancy
    bu::quantity<drs::cell_per_subarray_unit> cellsPerLBLRedundancy;

    //sense amp height
    bu::quantity<drs::micrometer_unit> BLSenseAmpHeight;

    //wordline driver width
    bu::quantity<drs::micrometer_unit> WLDriverWidth;

    //global wordline driver resistance in ohm
    bu::quantity<si::resistance> GWLDriverResistance;

    //Local wordline driver resistance in ohm
    bu::quantity<drs::resistance_per_subarray_unit> LWLDriverResistance;

    //WRrestore resistance
    bu::quantity<drs::resistance_per_subarray_unit> WRResistance;

    //CSL driver resistance in ohm
    bu::quantity<si::resistance> CSLDriverResistance;

    //GDL driver resistance in ohm
    bu::quantity<si::resistance> GDLDriverResistance;

    //DQ driver resistance in ohm
    bu::quantity<si::resistance> DQDriverResistance;

    //current of SSA in microamperes
    bu::quantity<drs::microampere_unit> Issa;

    //voltage vpp
    bu::quantity<si::electric_potential> vpp;

    //voltage vcc
    bu::quantity<si::electric_potential> vcc;

    //background current slope
    bu::quantity<drs::milliampere_per_megahertz_clock_unit> backgroundCurrentSlope;

    //background current offset
    bu::quantity<drs::milliampere_unit> backgroundCurrentOffset;

    //Current per IO pin at a given frequency (measurement or estimation)
    bu::quantity<drs::milliampere_unit> IddOcdRcvAtFrequencyPoint;

    //Frequency at which the current per IO pin was measured/estimated at
    bu::quantity<drs::megahertz_clock_unit> IddOcdRcvFrequencyPoint;

    //Row decoder (between tiles) width
    bu::quantity<drs::micrometer_unit> rowDecoderWidth;

    //Column decoder (between tiles) width
    bu::quantity<drs::micrometer_unit> colDecoderHeight;

    //DQ driver (between banks) height
    bu::quantity<drs::micrometer_unit> DQDriverHeight;

    //Space between banks driver in width direction
    bu::quantity<drs::micrometer_unit> bankSpacingWidth;

    //DRAM Type
    string dramType;

    //3D ON/OFF Feature
    //set 3D on for HMC/WideIO
    string ThreeD;

    // vaults per layer
    // set to 0 for non 3D DRAMs
    double vaultsPerLayer;

    //size of DRAM
    bu::quantity<drs::gibibit_unit> dramSize;

    //# of banks
    bu::quantity<drs::bank_unit> nBanks;

    //Interface
    double Interface;

    //DRAM Frequency
    bu::quantity<drs::megahertz_clock_unit> dramFreq;

    //DRAM Core Frequency
    //if this value is not specified then calculate this value:
    //Core Freq= Freq / (n.prefetch / n.DataRate)
    bu::quantity<drs::megahertz_clock_unit> dramCoreFreq;

    //Number of Prefetch
    double Prefetch;

    //additional latency required for trl calculation
    bu::quantity<drs::clock_unit> additionalLatencyTrl;

    // Row buffer size this value is given in KBytes (hard conversion needed)
    bu::quantity<drs::kibibyte_per_page_unit> pageStorage;

    // DLL ON/OFF Feature
    string DLL;

    // Required tref by user
    bu::quantity<drs::microsecond_unit> tRef1Required;

    // Ratio of banks refreshed pro command
    double banksRefreshFactor;

    // Subarray to rowbuffer factor
    double subArrayToPageFactor;

    // Retention time
    bu::quantity<drs::millisecond_unit> retentionTime;

    // Number of tiles per bank
    bu::quantity<drs::tile_per_bank_unit> tilesPerBank;

    // Spanning factor of pages across tiles
    bu::quantity<drs::page_per_tile_unit> pageSpanningFactor;

    // DRAM Bitline Architecture: OPEN or FOLDED bit-line
    string BLArchitecture;

//  !!!!!!!! TIMING VARIABLES WHICH WHERE HARDCODED IN THE ORIGINAL VERSION !!!!!!!!
    //Driver offset !!!  TODO: What exactly is it?  !!!
    bu::quantity<drs::nanosecond_unit> driverOffset;
    //SSA Delay !!!  TODO: Check value !!!
    bu::quantity<drs::nanosecond_unit> BitlineSenseAmpDelay;
    //Load capacitance !!!  TODO: What exactly is it?  !!!
    bu::quantity<drs::femtofarad_per_bank_unit> CSLLoadCapacitance;
    //Command decoder latency !!!  TODO: What exactly is it?  !!!
    bu::quantity<drs::nanosecond_unit> cmdDecoderLatency;
    //Internal latency !!!  TODO: What exactly is it?  !!!
    bu::quantity<drs::nanosecond_unit> interfaceLatency;
    //I/O latency !!!  TODO: What exactly is it?  !!!
    bu::quantity<drs::nanosecond_unit> IODelay;
    //Delay for SSA precharging !!!  TODO: What exactly is it?  !!!
    bu::quantity<drs::nanosecond_unit> SSAPrechargeDelay;
    //Security margin !!!  TODO: What exactly is it?  !!!
    bu::quantity<drs::nanosecond_unit> securityMargin;
    //Equalizer delay !!!  TODO: What exactly is it?  !!!
    bu::quantity<drs::nanosecond_unit> equalizerDelay;
    //Act cmd delay !!!  TODO: What exactly is it?  !!!
    bu::quantity<drs::nanosecond_unit> actCmdDelay;
    //pre cmd delay !!!  TODO: What exactly is it?  !!!
    bu::quantity<drs::nanosecond_unit> preCmdDelay;
    //offset !!!  TODO: What exactly is it?  !!!
    bu::quantity<drs::nanosecond_unit> offset;

    string warning;


    void technologyValuesInitialize();

    double getJSONNumber(const rapidjson::Document& jsonDoc,
                         const char* memberName);

    string getJSONString(const rapidjson::Document& jsonDoc,
                         const char* memberName);

    void readjson(const string& t,const string& p);

};
#endif //TECHNOLOGYVALUES_H
