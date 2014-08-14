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
#include "TechnologyValues.h"
#include <iostream>
#include <string>
#include "rapidjson/include/rapidjson/document.h"
#include <sstream>
#include <fstream>
using namespace std;
void 
TechnologyValues::readjson(const std::string& t,const std::string& p){
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
    technologynode = techdocument["Technologynode"].GetInt(); 
    //Bitline per cell capa
    assert(techdocument.HasMember("BLpercellcapa"));
    assert(techdocument["BLpercellcapa"].IsNumber());
    Blpercellcapa = techdocument["BLpercellcapa"].GetInt();
    //Bitline per cell resistance
    assert(techdocument.HasMember("BLpercellresistance")); 
    assert(techdocument["BLpercellresistance"].IsNumber());
    Blpercellresistance = techdocument["BLpercellresistance"].GetInt();
    //Wordline per cell capa
    assert(techdocument.HasMember("WLpercellcapa"));
    assert(techdocument["WLpercellcapa"].IsNumber());
    Wlpercellcapa = techdocument["WLpercellcapa"].GetInt();
    //Wordline per cell resistance
    assert(techdocument.HasMember("WLpercellresistance"));
    assert(techdocument["WLpercellresistance"].IsNumber());
    Wlpercellresistance = techdocument["WLpercellresistance"].GetInt();
    //cell capa
    assert(techdocument.HasMember("cellcapa"));
    assert(techdocument["cellcapa"].IsNumber());
    cellcapa = techdocument["cellcapa"].GetInt();
    //cell resistance
    assert(techdocument.HasMember("cellresistance"));
    assert(techdocument["cellresistance"].IsNumber());
    cellresistance = techdocument["cellresistance"].GetInt();
    //wire resistance in ohm/mm
    assert(techdocument.HasMember("wireresistance"));
    assert(techdocument["wireresistance"].IsNumber());
    wireresistance = techdocument["wireresistance"].GetInt();
    //wire capa in ff/mm
    assert(techdocument.HasMember("wirecapa"));
    assert(techdocument["wirecapa"].IsNumber());
    wirecapa = techdocument["wirecapa"].GetInt();
    //cell width 
    assert(techdocument.HasMember("cellwidth"));
    assert(techdocument["cellwidth"].IsNumber());
    cellwidth = techdocument["cellwidth"].GetDouble();
    //cell height
    assert(techdocument.HasMember("cellheight"));
    assert(techdocument["cellheight"].IsNumber());
    cellheight = techdocument["cellheight"].GetDouble();
    //cells per row 
    assert(techdocument.HasMember("cellsperrow"));
    assert(techdocument["cellsperrow"].IsNumber());
    cellsperrow = techdocument["cellsperrow"].GetDouble();
    //cells per row redundancy
    assert(techdocument.HasMember("cellsperrowredundancy"));
    assert(techdocument["cellsperrowredundancy"].IsNumber());
    cellsperrowredundancy = techdocument["cellsperrowredundancy"].
    GetDouble();
    //cells per column 
    assert(techdocument.HasMember("cellspercolumn"));
    assert(techdocument["cellspercolumn"].IsNumber());
    cellspercolumn = techdocument["cellspercolumn"].GetDouble();
    //cells per column redundancy 
    assert(techdocument.HasMember("cellspercolumnredundancy"));
    assert(techdocument["cellspercolumnredundancy"].IsNumber());
    cellspercolumnredundancy = techdocument["cellspercolumnredundancy"].
    GetDouble();
    //sense amp height
    assert(techdocument.HasMember("blsa-height"));
    assert(techdocument["blsa-height"].IsNumber());
    blsaheight = techdocument["blsa-height"].GetDouble();
    //wordline driver width 
    assert(techdocument.HasMember("WL-driver"));
    assert(techdocument["WL-driver"].IsNumber());
    wldwidth = techdocument["WL-driver"].GetDouble();
    //global wordline driver resistance in ohm
    assert(techdocument.HasMember("GWLDresistance"));
    assert(techdocument["GWLDresistance"].IsNumber());
    GWLDresistance = techdocument["GWLDresistance"].GetDouble();
    //Local wordline driver resistance in ohm
    assert(techdocument.HasMember("LWDresistance"));
    assert(techdocument["LWDresistance"].IsNumber());
    LWDresistance = techdocument["LWDresistance"].GetDouble();
    //WRrestore resistance 
    assert(techdocument.HasMember("WRresistance"));
    assert(techdocument["WRresistance"].IsNumber());
    WRresistance = techdocument["WRresistance"].GetDouble();
    //CSL driver resistance in ohm
    assert(techdocument.HasMember("CSLDresistance"));
    assert(techdocument["CSLDresistance"].IsNumber());
    CSLDresistance = techdocument["CSLDresistance"].GetDouble();
    //GDL driver resistance in ohm
    assert(techdocument.HasMember("GDLDresistance"));
    assert(techdocument["GDLDresistance"].IsNumber());
    GDLDresistance = techdocument["GDLDresistance"].GetDouble();
    //DQ driver resistance in ohm
    assert(techdocument.HasMember("DQDresistance"));
    assert(techdocument["DQDresistance"].IsNumber());
    DQDresistance = techdocument["DQDresistance"].GetDouble();
    //current of SSA in microamperes
    assert(techdocument.HasMember("I_SSA"));
    assert(techdocument["I_SSA"].IsNumber());
    I_SSA = techdocument["I_SSA"].GetInt();
    //voltage vpp
    assert(techdocument.HasMember("vpp"));
    assert(techdocument["vpp"].IsNumber());
    vpp  = techdocument["vpp"].GetDouble() ;
    //voltage vcc
    assert(techdocument.HasMember("vcc"));
    assert(techdocument["vcc"].IsNumber());
    vcc  = techdocument["vcc"].GetDouble();
    //backgroundcurrentslope
    assert(techdocument.HasMember("Backgroundcurrentslope"));
    assert(techdocument["Backgroundcurrentslope"].IsNumber()); 
    backgroundcurrentslope  = techdocument["Backgroundcurrentslope"].
    GetDouble();
    //backgroundcurrentoffset
    assert(techdocument.HasMember("Backgroundcurrentoffset"));
    assert(techdocument["Backgroundcurrentoffset"].IsNumber());
    backgroundcurrentoffset  = techdocument["Backgroundcurrentoffset"].
    GetDouble();
    //IDD pro IO for OCD
    assert(techdocument.HasMember("IDD_OCD_RCV"));
    assert(techdocument["IDD_OCD_RCV"].IsNumber());
    IDD_OCD_RCV  = techdocument["IDD_OCD_RCV"].GetDouble();
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
    DRAMType = paradocument["DRAMType"].GetString();
    //size of DRAM
    assert(paradocument.HasMember("Size"));
    assert(paradocument["Size"].IsNumber()); 
    dramsize = paradocument["Size"].GetInt();
    //# of banks
    assert(paradocument.HasMember("Numberofbanks"));
    assert(paradocument["Numberofbanks"].IsNumber());
    numberofbanks = paradocument["Numberofbanks"].GetInt();      
    //Interface
    assert(paradocument.HasMember("Interface"));
    assert(paradocument["Interface"].IsNumber());   
    Interface = paradocument["Interface"].GetInt();   
    //DRAM Frequency
    assert(paradocument.HasMember("Freq"));
    assert(paradocument["Freq"].IsNumber());
    Freq = paradocument["Freq"].GetInt();
    //Number of Prefetch
    assert(paradocument.HasMember("Prefetch"));
    assert(paradocument["Prefetch"].IsNumber());
    Prefetch = paradocument["Prefetch"].GetInt();
    //std::cout << "Freq should be 533" <<"\t"<<Freq<<".\n" ;
    assert(paradocument.HasMember("additionallatency"));
    assert(paradocument["additionallatency"].IsNumber());
    tal = paradocument["additionallatency"].GetInt();
    // row buffer size this value is given in KBytes 
    assert(paradocument.HasMember("Rowbuffersize"));
    assert(paradocument["Rowbuffersize"].IsNumber());
    rowbuffersize  = paradocument["Rowbuffersize"].GetDouble();
    //DLLON/OFF Feature
    assert(paradocument.HasMember("DLL"));
    assert(paradocument["DLL"].IsString());
    DLL = paradocument["DLL"].GetString();
    //required tref by user
    assert(paradocument.HasMember("Requiredrefreshperiod"));
    assert(paradocument["Requiredrefreshperiod"].IsNumber());
    tref1required  = paradocument["Requiredrefreshperiod"].GetDouble();
    //factor for number of banks refreshed pro command
    assert(paradocument.HasMember("banksrefreshfactor"));
    assert(paradocument["banksrefreshfactor"].IsNumber());
    banksrefreshfactor = paradocument["banksrefreshfactor"].GetDouble();
    //number of times a row is refreshed in retention time
    assert(paradocument.HasMember("rowrefreshrate"));
    assert(paradocument["rowrefreshrate"].IsNumber());
    rowrefreshrate = paradocument["rowrefreshrate"].GetDouble();
    //subarray to rowbuffer factor
    assert(paradocument.HasMember("subarray2rowbufferfactor"));
    assert(paradocument["subarray2rowbufferfactor"].IsNumber());
    subarray2rowbufferfactor = paradocument["subarray2rowbufferfactor"].
    GetDouble(); 
}
