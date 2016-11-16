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
#include "../units/NewUnits.h"

class TechnologyValues
{
  public:
    TechnologyValues(const std::string& techname,const std::string&
    paraname) : Techname(""), Paraname(""), DRAMType(""), dramsize(0),
    Freq(0), CoreFreq(0), Prefetch(0), DLL(""), tref1required(0),
    Blpercellcapa(0), Blpercellresistance(0), Wlpercellcapa(0),
    Wlpercellresistance(0), cellcapa(0), cellresistance(0), 
    wireresistance(0), wirecapa(0), cellwidth(0), cellheight(0),
    cellPerLWL(0), cellsPerLWLRedundancy(0),cellsPerLBL(0),
    cellsPerLBLRedundancy(0), blsaheight(0), wldwidth(0),
    subArrayRatioToPage(1), GWLDresistance(0), LWDresistance(0),
    WRresistance(0), CSLDresistance(0), GDLDresistance(0), DQDresistance(0),
    pageSize(0), I_SSA(0), vpp(0), vcc(0), Interface(16),
    backgroundcurrentslope(0), backgroundcurrentoffset(0), IDD_OCD_RCV(0),
    banksrefreshfactor(0), rowrefreshrate(0), retentiontime(0), tilesperbank(0)
    {
       Techname = techname;
       Paraname = paraname;
    }

    // Technologyfile name to be read
    std::string Techname;

    // Parameter file name to be read
    std::string Paraname;

    // type of the DRAM
    std::string DRAMType;

    // technology node
    int technologynode;

    // size of DRAM
    int dramsize;

    // # of banks 
    int numberofbanks; 

    // Frequency in MHz
    int Freq;

    // Core Frequency in Mhz
    int CoreFreq;

    // Prefetch number
    int Prefetch;

    // additional latency tal added to trl 
     int tal;

    // DLL ON/OFF Feature
    std::string DLL;

    //3D ON/OFF Feature
    std::string ThreeD;

    //Vaults per Layer 
    int vaultsperlayer;

    //required refresh period
    //possibility to set the refresh period 
    float tref1required;

    //capacitance of bitline per cell
    int Blpercellcapa ;

    //resistance of bitline per cell
    int Blpercellresistance ;

    //capacitance of wordline per cell
    int Wlpercellcapa;

    //resistance of wordline per cell
    int Wlpercellresistance;

    // capacitance per cell
    int cellcapa;

    // resistance per cell 
    int cellresistance;

    // resistance of wire ohm/mm
    int wireresistance;

    // capa of wire ff/mm
    int wirecapa;

    //the width of one cell
    float cellwidth;

    //the height of one cell
    float cellheight;

    //the number of cells per row per subarray
    int cellPerLWL;

    //the number of cells in the cellsperrowvalue which are redundant
    int cellsPerLWLRedundancy;

    //the number of cells per column per subarray
    int cellsPerLBL;

    //the number of cells in the cellspercolumn which are redundant
    int cellsPerLBLRedundancy;

    //the height of the bitline sense amplifier
    int blsaheight;

    //the width of the wordline drive
    int wldwidth;

    //this factor decides if you are placing as many subarrays as the page 
    //size in the horizantal direction or more or less
    float subArrayRatioToPage;    

    //the resistance of the global wordline driver (in Ohm)
    //the resistance values should change with different page size and 
    //different technologies(value for rowbuffer = 2kB )
    float GWLDresistance;

    //the resistance of the local wordline driver (in Ohm) for 
    //512 x 512 subarray
    float LWDresistance;

    //the resistance of the WR ( wordline restor which selects one LWL for 
    //512 x 512 subaarray
    float WRresistance;

    //the resistance of the CSL driver ( in Ohm )
    float CSLDresistance;

    //the resistance of the GDL driver ( in Ohm )
    float GDLDresistance;

    //the resistance of the DQ driver ( in Ohm )
    float DQDresistance;
    
    //the row buffer size /page size
    float pageSize;
    
    //current of Secondary sense amp in microamperes
    int I_SSA;

    //voltage vpp 
    float vpp;

    //voltage vcc
    float vcc;

    //interface number in bits
    int Interface;

    //Backgroundcurrentslope
    float backgroundcurrentslope;

    //Backgroundcurrentoffset
    float backgroundcurrentoffset;

    //current pro IO OCD
    float IDD_OCD_RCV;

    //number of banks refreshred pro command factor
    float banksrefreshfactor;

    //number of times a row is refreshed in retention time
    float rowrefreshrate;	

    // retention time
    float retentiontime;
    
    //number of tiles per bank
    int tilesperbank;

    //reading from json file
    void readjson(const std::string& t,const std::string& p);    
};
#endif //TECHNOLOGYVALUES_H
