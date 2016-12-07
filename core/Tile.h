///*
// * Copyright (c) 2015, University of Kaiserslautern
// * All rights reserved.
// *
// * Redistribution and use in source and binary forms, with or without
// * modification, are permitted provided that the following conditions are
// * met:
// *
// * 1. Redistributions of source code must retain the above copyright notice,
// *    this list of conditions and the following disclaimer.
// *
// * 2. Redistributions in binary form must reproduce the above copyright
// *    notice, this list of conditions and the following disclaimer in the
// *    documentation and/or other materials provided with the distribution.
// *
// * 3. Neither the name of the copyright holder nor the names of its
// *    contributors may be used to endorse or promote products derived from
// *    this software without specific prior written permission.
// *
// * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
// * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER
// * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// *
// * Authors: Omar Naji,
// *          Matthias Jung,
// *          Christian Weis,
// *          Kamal Haddad,
// *          Andr'e Lucas Chinazzo
// */

////This class repesents the third level of abstraction of the DRAM structure,
////being a tilea grouping of subarrays which are a grouping of cells.
//#ifndef TILE_H
//#define TILE_H

//#include "SubArray.h"
//#include <iostream>
//class Tile : public SubArray
//{
//  public:
//    Tile(const std::string& techname,const std::string& paraname)
//        : SubArray(techname,paraname),
//          tileSize(0),
//          tileWidth(0),
//          tileHeight(0),
//          tileArea(0)
//    {
//        //order of functions is important
//        bool TINIT = false;
//        TINIT = tileInit();
//        if(TINIT == false)
//        {
//                std::cout<<"ERROR: Function for Tile Initialization not called"<<
//                "\t"<<"Order of Functions is important"<<"\n";
//                throw(" Function for Tile Initialization not called");
//        }
//        bool TLENGTH = false;
//        TLENGTH = tileLenghtCalc();
//        if(TLENGTH == false)
//        {
//                std::cout<<"ERROR: Function for Tile Lengths calculation not called"<<
//                "\t"<<"Order of Functions is important"<<"\n";
//                throw(" Function for Tile Width and Height calculation not called");
//        }
//    }
//  public:
//    //size in number of bits of a single tile
//    int tileSize;
//    //Width in micrometer of a single tile
//    int tileWidth;
//    //Height in micrometer of a single tile
//    int tileHeight;
//    //Area in micrometer squared of a single tile
//    float tileArea;

//    bool tileInit();

//    bool tileLenghtCalc();

//    bool tileAreaCalc();
//};

//#endif // TILE_H
