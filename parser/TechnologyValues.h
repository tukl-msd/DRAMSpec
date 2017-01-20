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
#include <string>
#include "rapidjson/include/rapidjson/document.h"
#include <sstream>
#include <fstream>

#include "../expandedBoostUnits/Units/dramSpec_units.h"
#include <boost/units/conversion.hpp>

namespace bu=boost::units;
namespace si=boost::units::si;
namespace inf=boost::units::information;
namespace drs=boost::units::dramspec;

class TechnologyValues
{
  public:

    TechnologyValues() : //Empty constructor for test proposes
        Techname(""),
        Paraname(""),

        technologyNode(0*drs::nanometer),
        capacitancePerBLCell(0*drs::attofarads_per_cell),
        resistancePerBLCell(0*drs::ohm_per_cell),
        capacitancePerWLCell(0*drs::attofarads_per_cell),
        resistancePerWLCell(0*drs::ohm_per_cell),
        capacitancePerCell(0*drs::picofarads_per_cell),
        resistancePerCell(0*drs::ohm_per_cell),
        wireResistance(0*drs::ohm_per_millimeter),
        wireCapacitance(0*drs::femtofarad_per_millimeter),
        cellWidth(0*drs::micrometer_per_cell),
        cellHeight(0*drs::micrometer_per_cell),
        cellsPerLWL(0*drs::cell_per_subarray),
        cellsPerLWLRedundancy(0*drs::cell_per_subarray),
        cellsPerLBL(0*drs::cell_per_subarray),
        cellsPerLBLRedundancy(0*drs::cell_per_subarray),
        BLSenseAmpHeight(0*drs::micrometer),
        WLDriverWidth(0*drs::micrometer),
        GWLDriverResistance(0*si::ohm),
        LWLDriverResistance(0*drs::ohm_per_subarray),
        WRResistance(0*drs::ohm_per_subarray),
        CSLDriverResistance(0*si::ohm),
        GDLDriverResistance(0*si::ohm),
        DQDriverResistance(0*si::ohm),
        Issa(0*drs::microampere),
        Vpp(0*si::volt),
        Vcc(0*si::volt),
        backgroundCurrentSlope(0*drs::milliamperes_per_megahertz),
        backgroundCurrentOffset(0*drs::microampere),
        IddOcdRcv(0*drs::microampere),

        dramType(""),
        ThreeD(""),
        vaultsPerLayer(0),
        dramSize(0*drs::gibibit),
        nBanks(0*drs::bank),
        Interface(16),
        dramFreq(0*drs::megahertz_clock),
        dramCoreFreq(0*drs::megahertz_clock),
        Prefetch(0),
        additionalLatencyTrl(0*drs::clock),
        pageStorage(0*drs::kibibit_per_page),
        DLL(""),
        tRef1Required(0*drs::nanosecond),
        banksRefreshFactor(0),
        rowRefreshRate(0),
        subArrayToPageFactor(0),
        retentionTime(0*drs::millisecond),
        tilesPerBank(0*drs::tile_per_bank),
        pageSpanningFactor(0*drs::page_per_tile),
        BLArchitecture("")
    {}

    TechnologyValues(const std::string& techname,
                     const std::string& paraname) :
        Techname(""),
        Paraname(""),

        technologyNode(0*drs::nanometer),
        capacitancePerBLCell(0*drs::attofarads_per_cell),
        resistancePerBLCell(0*drs::ohm_per_cell),
        capacitancePerWLCell(0*drs::attofarads_per_cell),
        resistancePerWLCell(0*drs::ohm_per_cell),
        capacitancePerCell(0*drs::picofarads_per_cell),
        resistancePerCell(0*drs::ohm_per_cell),
        wireResistance(0*drs::ohm_per_millimeter),
        wireCapacitance(0*drs::femtofarad_per_millimeter),
        cellWidth(0*drs::micrometer_per_cell),
        cellHeight(0*drs::micrometer_per_cell),
        cellsPerLWL(0*drs::cell_per_subarray),
        cellsPerLWLRedundancy(0*drs::cell_per_subarray),
        cellsPerLBL(0*drs::cell_per_subarray),
        cellsPerLBLRedundancy(0*drs::cell_per_subarray),
        BLSenseAmpHeight(0*drs::micrometer),
        WLDriverWidth(0*drs::micrometer),
        GWLDriverResistance(0*si::ohm),
        LWLDriverResistance(0*drs::ohm_per_subarray),
        WRResistance(0*drs::ohm_per_subarray),
        CSLDriverResistance(0*si::ohm),
        GDLDriverResistance(0*si::ohm),
        DQDriverResistance(0*si::ohm),
        Issa(0*drs::microampere),
        Vpp(0*si::volt),
        Vcc(0*si::volt),
        backgroundCurrentSlope(0*drs::milliamperes_per_megahertz),
        backgroundCurrentOffset(0*drs::microampere),
        IddOcdRcv(0*drs::microampere),

        dramType(""),
        ThreeD(""),
        vaultsPerLayer(0),
        dramSize(0*drs::gibibit),
        nBanks(0*drs::bank),
        Interface(16),
        dramFreq(0*drs::megahertz_clock),
        dramCoreFreq(0*drs::megahertz_clock),
        Prefetch(0),
        additionalLatencyTrl(0*drs::clock),
        pageStorage(0*drs::kibibit_per_page),
        DLL(""),
        tRef1Required(0*drs::nanosecond),
        banksRefreshFactor(0),
        rowRefreshRate(0),
        subArrayToPageFactor(0),
        retentionTime(0*drs::millisecond),
        tilesPerBank(0*drs::tile_per_bank),
        pageSpanningFactor(0*drs::page_per_tile),
        BLArchitecture("")
    {
       Techname = techname;
       Paraname = paraname;
    }

    // Technologyfile name to be read
    std::string Techname;

    // Parameter file name to be read
    std::string Paraname;

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
    bu::quantity<si::electric_potential> Vpp;

    //voltage vcc
    bu::quantity<si::electric_potential> Vcc;

    //background current slope
    bu::quantity<drs::milliampere_per_megahertz_unit> backgroundCurrentSlope;

    //background current offset
    bu::quantity<drs::microampere_unit> backgroundCurrentOffset;

    //IDD pro IO for OCD
    bu::quantity<drs::microampere_unit> IddOcdRcv;

    //Row decoder (between tiles) width
    bu::quantity<drs::micrometer_unit> rowDecoderWidth;

    //Column decoder (between tiles) width
    bu::quantity<drs::micrometer_unit> colDecoderHeight;

    //DQ driver (between banks) height
    bu::quantity<drs::micrometer_unit> DQDriverHeight;

    //Space between banks driver in width direction
    bu::quantity<drs::micrometer_unit> bankSpacingWidth;

    //DRAM Type
    std::string dramType;

    //3D ON/OFF Feature
    //set 3D on for HMC/WideIO
    std::string ThreeD;

    // vaults per layer
    // set to 0 for non 3D DRAMs
    double vaultsPerLayer;

    //size of DRAM
    bu::quantity<drs::gibibit_unit> dramSize;

    //# of banks
    bu::quantity<drs::bank_unit> nBanks;

    //Interface
    int Interface;

    //DRAM Frequency
    bu::quantity<drs::megahertz_clock_unit> dramFreq;

    //DRAM Core Frequency
    //if this value is not specified then calculate this value:
    //Core Freq= Freq / (n.prefetch / n.DataRate)
    bu::quantity<drs::megahertz_clock_unit> dramCoreFreq;

    //Number of Prefetch
    int Prefetch;

    //additional latency required for trl calculation
    bu::quantity<drs::clock_unit> additionalLatencyTrl;

    // Row buffer size this value is given in KBytes (hard conversion needed)
    bu::quantity<drs::kibibit_per_page_unit> pageStorage;

    // DLL ON/OFF Feature
    std::string DLL;

    // Required tref by user
    bu::quantity<drs::nanosecond_unit> tRef1Required;

    // Factor for number of banks refreshed pro command
    double banksRefreshFactor;

    // Number of times a row is refreshed in retention time
    double rowRefreshRate;

    // Subarray to rowbuffer factor
    double subArrayToPageFactor;

    // Retention time
    bu::quantity<drs::millisecond_unit> retentionTime;

    // Number of tiles per bank
    bu::quantity<drs::tile_per_bank_unit> tilesPerBank;

    // Spanning factor of pages across tiles
    bu::quantity<drs::page_per_tile_unit> pageSpanningFactor;

    // DRAM Bitline Architecture: OPEN or FOLDED bit-line
    std::string BLArchitecture;

    void readjson(const std::string& t,const std::string& p);

};
#endif //TECHNOLOGYVALUES_H
