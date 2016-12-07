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
#include <iostream>
#include <string>
#include "rapidjson/include/rapidjson/document.h"
#include <sstream>
#include <fstream>

namespace bu=boost::units;
namespace si=boost::units::si;
namespace inf=boost::units::information;
namespace drs=boost::units::dramspec;

void 
TechnologyValues::readjson(const std::string& t,const std::string& p)
{
    //technology file
    std::string techname;

    //parameter file
    std::string paraname;
    techname = t;
    paraname = p;

    //load the technology json file and put it into a single string:
    std::ifstream techin(techname.c_str());
    std::stringstream techbuffer;
    techbuffer << techin.rdbuf();
    if (techbuffer.bad()) {
        std::cout<<"Error: filename does not exist"<<"\n";
    }
    std::string testtech = techbuffer.str();

    //parsing the json file
    //pointing to the string
    const char* techjson = testtech.c_str();

    //using the library for parsing
    rapidjson::Document techdocument;
    techdocument.Parse<0>(techjson);

    //reading the values from the technology json file
    assert(techdocument.IsObject());

    //Technology node in nm
    assert(techdocument.HasMember("Technologynode"));
    assert(techdocument["Technologynode"].IsNumber());
    double technologyNode_value = techdocument["Technologynode"].GetDouble();
    technologyNode = technologyNode_value*drs::nanometer;

    //Bitline per cell capa
    assert(techdocument.HasMember("BLpercellcapa"));
    assert(techdocument["BLpercellcapa"].IsNumber());
    double capacitancePerBLCell_value = techdocument["BLpercellcapa"].GetDouble();
    capacitancePerBLCell =capacitancePerBLCell_value*drs::attofarads_per_cell;

    //Bitline per cell resistance
    assert(techdocument.HasMember("BLpercellresistance")); 
    assert(techdocument["BLpercellresistance"].IsNumber());
    double resistancePerBLCell_value = techdocument["BLpercellresistance"].GetDouble();
    resistancePerBLCell = resistancePerBLCell_value*drs::ohm_per_cell;

    //Wordline per cell capa
    assert(techdocument.HasMember("WLpercellcapa"));
    assert(techdocument["WLpercellcapa"].IsNumber());
    double capacitancePerWLCell_value = techdocument["WLpercellcapa"].GetDouble();
    capacitancePerWLCell = capacitancePerWLCell_value*drs::attofarads_per_cell;

    //Wordline per cell resistance
    assert(techdocument.HasMember("WLpercellresistance"));
    assert(techdocument["WLpercellresistance"].IsNumber());
    double resistancePerWLCell_value = techdocument["WLpercellresistance"].GetDouble();
    resistancePerWLCell = resistancePerWLCell_value*drs::ohm_per_cell;

    //cell capa
    assert(techdocument.HasMember("cellcapa"));
    assert(techdocument["cellcapa"].IsNumber());
    double capacitancePerCell_value = techdocument["cellcapa"].GetDouble();
    capacitancePerCell = capacitancePerCell_value*drs::picofarads_per_cell;

    //cell resistance
    assert(techdocument.HasMember("cellresistance"));
    assert(techdocument["cellresistance"].IsNumber());
    double resistancePerCell_value = techdocument["cellresistance"].GetDouble();
    resistancePerCell = resistancePerCell_value*drs::ohm_per_cell;

    //wire resistance in ohm/mm
    assert(techdocument.HasMember("wireresistance"));
    assert(techdocument["wireresistance"].IsNumber());
    double wireResistance_value = techdocument["wireresistance"].GetDouble();
    wireResistance = wireResistance_value*drs::ohm_per_millimeter;

    //wire capa in ff/mm
    assert(techdocument.HasMember("wirecapa"));
    assert(techdocument["wirecapa"].IsNumber());
    double wireCapacitance_value = techdocument["wirecapa"].GetDouble();
    wireCapacitance = wireCapacitance_value*drs::femtofarad_per_millimeter;

    //cell width
    assert(techdocument.HasMember("cellwidth"));
    assert(techdocument["cellwidth"].IsNumber());
    double cellWidth_value = techdocument["cellwidth"].GetDouble();
    cellWidth = cellWidth_value*drs::micrometers_per_cell;

    //cell height
    assert(techdocument.HasMember("cellheight"));
    assert(techdocument["cellheight"].IsNumber());
    double cellHeight_value = techdocument["cellheight"].GetDouble();
    cellHeight = cellHeight_value*drs::micrometers_per_cell;

    //cells per subarray row
    assert(techdocument.HasMember("cellsperrow"));
    assert(techdocument["cellsperrow"].IsNumber());
    double cellsPerLWL_value = techdocument["cellsperrow"].GetDouble();
    cellsPerLWL = cellsPerLWL_value*drs::cell_per_sa_row;

    //cells per subarray row redundancy
    assert(techdocument.HasMember("cellsperrowredundancy"));
    assert(techdocument["cellsperrowredundancy"].IsNumber());
    double cellsPerLWLRedundancy_value = techdocument["cellsperrowredundancy"].GetDouble();
    cellsPerLWLRedundancy = cellsPerLWLRedundancy_value*drs::cell_per_sa_row;

    //cells per subarray column
    assert(techdocument.HasMember("cellspercolumn"));
    assert(techdocument["cellspercolumn"].IsNumber());
    double cellsPerLBL_value = techdocument["cellspercolumn"].GetDouble();
    cellsPerLBL = cellsPerLBL_value*drs::cell_per_sa_col;

    //cells per subarray column redundancy
    assert(techdocument.HasMember("cellspercolumnredundancy"));
    assert(techdocument["cellspercolumnredundancy"].IsNumber());
    double cellsperLBLRedundancy_value = techdocument["cellspercolumnredundancy"].GetDouble();
    cellsPerLBLRedundancy = cellsperLBLRedundancy_value*drs::cell_per_sa_col;

    //sense amp height
    assert(techdocument.HasMember("blsa-height"));
    assert(techdocument["blsa-height"].IsNumber());
    double BLSenseAmpHeight_value = techdocument["blsa-height"].GetDouble();
    BLSenseAmpHeight = BLSenseAmpHeight_value*drs::micrometer;

    //wordline driver width 
    assert(techdocument.HasMember("WL-driver"));
    assert(techdocument["WL-driver"].IsNumber());
    double WLDriverWidth_value = techdocument["WL-driver"].GetDouble();
    WLDriverWidth = WLDriverWidth_value*drs::micrometer;

    //global wordline driver resistance in ohm
    assert(techdocument.HasMember("GWLDresistance"));
    assert(techdocument["GWLDresistance"].IsNumber());
    double GWLDriverResistance_value = techdocument["GWLDresistance"].GetDouble();
    GWLDriverResistance = GWLDriverResistance_value*si::ohm;

    //Local wordline driver resistance in ohm
    assert(techdocument.HasMember("LWDresistance"));
    assert(techdocument["LWDresistance"].IsNumber());
    double LWLDriverResistance_value = techdocument["LWDresistance"].GetDouble();
    LWLDriverResistance = LWLDriverResistance_value*drs::ohms_per_sa_row;

    //WRrestore resistance
    assert(techdocument.HasMember("WRresistance"));
    assert(techdocument["WRresistance"].IsNumber());
    double WRResistance_value = techdocument["WRresistance"].GetDouble();
    WRResistance = WRResistance_value*drs::ohms_per_sa_col;

    //CSL driver resistance in ohm
    assert(techdocument.HasMember("CSLDresistance"));
    assert(techdocument["CSLDresistance"].IsNumber());
    double CSLDriverResistance_value = techdocument["CSLDresistance"].GetDouble();
    CSLDriverResistance = CSLDriverResistance_value*si::ohm;

    //GDL driver resistance in ohm
    assert(techdocument.HasMember("GDLDresistance"));
    assert(techdocument["GDLDresistance"].IsNumber());
    double GDLDriverResistance_value = techdocument["GDLDresistance"].GetDouble();
    GDLDriverResistance = GDLDriverResistance_value*si::ohm;

    //DQ driver resistance in ohm
    assert(techdocument.HasMember("DQDresistance"));
    assert(techdocument["DQDresistance"].IsNumber());
    double DQDriverResistance_value = techdocument["DQDresistance"].GetDouble();
    DQDriverResistance = DQDriverResistance_value*si::ohm;

    //current of SSA in microamperes
    assert(techdocument.HasMember("I_SSA"));
    assert(techdocument["I_SSA"].IsNumber());
    double Issa_value = techdocument["I_SSA"].GetDouble();
    Issa = Issa_value*drs::microampere;

    //voltage vpp
    assert(techdocument.HasMember("vpp"));
    assert(techdocument["vpp"].IsNumber());
    double Vpp_value  = techdocument["vpp"].GetDouble() ;
    Vpp = Vpp_value*si::volt;

    //voltage vcc
    assert(techdocument.HasMember("vcc"));
    assert(techdocument["vcc"].IsNumber());
    double Vcc_value  = techdocument["vcc"].GetDouble();
    Vcc = Vcc_value*si::volt;

    //backgroundcurrentslope    
    assert(techdocument.HasMember("Backgroundcurrentslope"));
    assert(techdocument["Backgroundcurrentslope"].IsNumber()); 
    double backgroundCurrentSlope_value  = techdocument["Backgroundcurrentslope"].GetDouble();
    backgroundCurrentSlope = backgroundCurrentSlope_value*drs::milliamperes_per_megahertz;

    //backgroundcurrentoffset
    assert(techdocument.HasMember("Backgroundcurrentoffset"));
    assert(techdocument["Backgroundcurrentoffset"].IsNumber());
    double backgroundCurrentOffset_value  = techdocument["Backgroundcurrentoffset"].GetDouble();
    backgroundCurrentOffset = backgroundCurrentOffset_value*drs::microampere;

    //IDD pro IO for OCD
    assert(techdocument.HasMember("IDD_OCD_RCV"));
    assert(techdocument["IDD_OCD_RCV"].IsNumber());
    double IddOcdRcv_value  = techdocument["IDD_OCD_RCV"].GetDouble();
    IddOcdRcv = IddOcdRcv_value*drs::microampere;

    //load the parameter file and put in into a single string
    std::ifstream parain(paraname.c_str());
    std::stringstream parabuffer;
    parabuffer << parain.rdbuf();
    if (parabuffer.bad()) {
    std::cout<<"Error: Parameter filename does not exist"<<"\n";
    }
    std::string testpara = parabuffer.str();

    //parsing the json file
    //pointing to the string
    const char* parajson = testpara.c_str();

    //using the library for parsing
    rapidjson::Document paradocument;
    paradocument.Parse<0>(parajson);

    //reading the values from the parameter json file
    assert(paradocument.IsObject());

    //DRAM Type
    assert(paradocument.HasMember("DRAMType"));
    assert(paradocument["DRAMType"].IsString());
    dramType = paradocument["DRAMType"].GetString();

    //3D ON/OFF Feature
    //set 3D on for HMC/WideIO
    assert(paradocument.HasMember("3D"));
    assert(paradocument["3D"].IsString());
    ThreeD = paradocument["3D"].GetString();

    // vaults per layer
    // set to 0 for non 3D DRAMs
    assert(paradocument.HasMember("Vaultsperlayer"));
    assert(paradocument["Vaultsperlayer"].IsNumber()); 
    vaultsPerLayer = paradocument["Vaultsperlayer"].GetDouble();

    //size of DRAM
    assert(paradocument.HasMember("Size"));
    assert(paradocument["Size"].IsNumber()); 
    double dramSize_value = paradocument["Size"].GetDouble();
    dramSize = dramSize_value*drs::gibibit;

    //# of banks
    assert(paradocument.HasMember("Numberofbanks"));
    assert(paradocument["Numberofbanks"].IsNumber());
    double nBanks_value = paradocument["Numberofbanks"].GetDouble();
    nBanks = nBanks_value*drs::bank;

    //Interface
    assert(paradocument.HasMember("Interface"));
    assert(paradocument["Interface"].IsNumber());   
    Interface = paradocument["Interface"].GetDouble();

    //DRAM Frequency
    assert(paradocument.HasMember("Freq"));
    assert(paradocument["Freq"].IsNumber());
    double dramFreq_value = paradocument["Freq"].GetDouble();
    dramFreq = dramFreq_value*drs::megahertz_clock;

    //DRAM Core Frequency
    //if this value is not specified then calculate this value:
    //Core Freq= Freq / (n.prefetch / n.DataRate)
    assert(paradocument.HasMember("CoreFreq"));
    assert(paradocument["CoreFreq"].IsNumber());
    double dramCoreFreq_value = paradocument["CoreFreq"].GetDouble();
    dramCoreFreq = dramCoreFreq_value*drs::megahertz_clock;

    //Number of Prefetch
    assert(paradocument.HasMember("Prefetch"));
    assert(paradocument["Prefetch"].IsNumber());
    Prefetch = paradocument["Prefetch"].GetDouble();

    //additional latency required for trl calculation
    assert(paradocument.HasMember("additionallatency"));
    assert(paradocument["additionallatency"].IsNumber());
    double additionalLatencyTrl_value = paradocument["additionallatency"].GetDouble();
    additionalLatencyTrl = additionalLatencyTrl_value*drs::clock;

    // Row buffer size this value is given in KBytes  
    assert(paradocument.HasMember("Rowbuffersize"));
    assert(paradocument["Rowbuffersize"].IsNumber());
    double pageSize_value  = paradocument["Rowbuffersize"].GetDouble();
    pageSize = pageSize_value*drs::kibibyte;


    // DLLON/OFF Feature
    assert(paradocument.HasMember("DLL"));
    assert(paradocument["DLL"].IsString());
    DLL = paradocument["DLL"].GetString();

    // Required tref by user
    assert(paradocument.HasMember("Requiredrefreshperiod"));
    assert(paradocument["Requiredrefreshperiod"].IsNumber());
    double tRef1Required_value  = paradocument["Requiredrefreshperiod"].GetDouble();
    tRef1Required = tRef1Required_value*drs::nanosecond;

    // Factor for number of banks refreshed pro command
    assert(paradocument.HasMember("banksrefreshfactor"));
    assert(paradocument["banksrefreshfactor"].IsNumber());
    banksRefreshFactor = paradocument["banksrefreshfactor"].GetDouble();

    // Number of times a row is refreshed in retention time
    assert(paradocument.HasMember("rowrefreshrate"));
    assert(paradocument["rowrefreshrate"].IsNumber());
    rowRefreshRate = paradocument["rowrefreshrate"].GetDouble();

    // Subarray to rowbuffer factor
    assert(paradocument.HasMember("subarray2rowbufferfactor"));
    assert(paradocument["subarray2rowbufferfactor"].IsNumber());
    subArrayRatioToPage = paradocument["subarray2rowbufferfactor"].GetDouble();

    // Retention time
    assert(paradocument.HasMember("retentiontime"));
    assert(paradocument["retentiontime"].IsNumber());
    double retentionTime_value = paradocument["retentiontime"].GetDouble();
    retentionTime = retentionTime_value*drs::millisecond;

    // Number of tiles per bank
    assert(paradocument.HasMember("tilesperbank"));
    assert(paradocument["tilesperbank"].IsNumber());
    double tilesPerBank_value = paradocument["tilesperbank"].GetDouble();
    tilesPerBank = tilesPerBank_value*drs::tile_per_bank;

}
