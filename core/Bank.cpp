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
// * Authors: Omar Naji, Matthias Jung, Christian Weis, Kamal Haddad
// */

///*
//* This file SEEMS to describe three different abstraction levels
//*  of the DRAM structure: the Tile; the Bank; and the Chip
//* Once implemented the Tile level, in the Tile.cpp and .h files,
//*  this file will describe only the Bank (fourth) level.
//*/

//#define pagePerTile 0.5 // This will be a user input

//#include "Bank.h"
//#include <iostream>
//#include <cmath>

//bool
//Bank::Bankinit()
//{
//    // Calculate size of bank * 1024 (transform to MBits)
//    sizeofBank = dramSize * 1024 / nBanks;

//    // Calculate size of halfbank:

//    // Depending on the tilesperbank parameter, wer either consider
//    //  a monolithic bank, half bank, or quarter bank architecture
//    switch(tilesPerBank)
//    {
//        case 1: sizeofhalfBank = (sizeofBank); //Monolithic
//                break;

//        case 2: sizeofhalfBank = (sizeofBank/2.0); //HalfBank
//                break;

//        case 4: sizeofhalfBank = (sizeofBank/4.0); //QuarterBank
//                break;

//        default: std::cerr << "ERROR: tilesperbank must be 1,2 or 4"
//                           << std::endl;
//                 exit (EXIT_FAILURE);
//                 break;
//    }

//    // Calculate number of memoryarrays pro halfbank + 1
//    // (open-bit array structure)
//    numberofMemoryArrays = sizeofhalfBank/sizeofMemoryArray + 1;

//    // Calculate bank height required for CSL and MDQ...
//    // FIXME: Ask Christian why this is the case ...
//    if(numberofMemoryArrays% 2 == 0)
//    {
//        Bankheight = numberofMemoryArrays * (MemoryArrayheight+BLSenseAmpHeight);
//    }
//    else
//    {
//        Bankheight = numberofMemoryArrays*MemoryArrayheight
//                     + BLSenseAmpHeight * (numberofMemoryArrays-1);
//    }


//    return true;
//}

//bool
//Bank::calcchiparea()
//{
//    // Calculate number of subarrrays in the width
//    // direction * 1024 (to Bytes) * 8 (to bits)
//    int subArrayPerTile;

//    // mwldwidth//master wordline driver width ( value taken from a real
//    // chip designed)
//    float mwldwidth = 240; //row decoder width

//    // columnlogicwidth values taken from a real chip design
//    float columnlogicwidth = 200;

//    // dq width values taken from a real chip design
//    float dqwidth = 500;

//    int columns, rows, x, y;
    
//    // FIXME: Ask Christian if this is correct ...
//    // Depending on the number of tiles per banks, the size and arrangements of
//    // the banks vary between monolithic, halfbank, quarterbank:
//    if(tilesPerBank == 1)
//    {
//        //For the case of monolithic banks
//        // FIXME: why is the 0.5 there? we should explain that in a comment
////      [subArray/tile]   [page/tile]
//        subArrayPerTile = pagePerTile
////                         [Kbyte/page]
//                          * pageSize
////                    [KByte -> Kbit]
//                          * 1024
////                     [Kbit -> bit]
//                          * 8
////                                   []
//                          / subArrayRatioToPage
//                          / (float)(cellsPerLWL - cellsPerLWLRedundancy); // cellperlwl
//        // assert(page2tile pagesize cellinarow)
////      [um/mwl]      [lwl/mwl]       [um/lwl]
//        tileWidth = subArrayPerTile * subArrayWidth
////                     [um/mwl]
//                     + WLDriverWidth // /drs::mwl
////                     [um/mwl]
//                     + mwldwidth; // /drs::mwl;

//        //For the case of 3D architecture
//        if(ThreeD == "ON")
//        {
//            if(nBanks > 1)
//            {
//                //If the number of banks is greater than 1
//                // and is an even power of 2
//                if( ((int)log2(nBanks) % 2) == 0)
//                {
//                                //|-Isn't it sqrt(Numberofbanks)?-|
//                                //           \\\///
//                    chipwidth = pow(2,(int)(log2(nBanks)/2)) * tileWidth;
//                    chipheight = (Bankheight+ columnlogicwidth)
//                                  *pow(2,(int)(log2(nBanks)/2))
//                                 + dqwidth*pow(2,(int)(log2(nBanks)/2))/2;
//                }
//                //If the number of banks is greater than 1
//                // and is an odd power of 2
//                else
//                {
//                    //     |------Isn't it always 1?-----|
//                    rows =   (int)log2(nBanks)
//                           - (int)(log2(nBanks)/2);
//                    x = pow(2,rows); // So this is 2, right?

//                    columns = (int)(log2(nBanks)/2);
//                    y = pow(2,columns);

//                    chipwidth = y * tileWidth;
//                    chipheight = (Bankheight + columnlogicwidth) * x
//                                 + (x/2) * dqwidth;
//                }

//            }
//            //Case if there is one bank,
//            // unlikely case but necessary nonetheless
//            if(nBanks == 1)
//            {
//                chipwidth =  tileWidth;
//                chipheight = Bankheight  + columnlogicwidth + dqwidth;
//            }

//        }
//        else if(ThreeD == "OFF")
//        {
//            //If it is not 3D architecture
//            if(nBanks > 3)
//            {
//                chipwidth = (nBanks/4)* tileWidth;
//                chipheight = (Bankheight + columnlogicwidth) * 4
//                             + 2 *(dqwidth);
//            }
//            else
//            {
//                chipwidth =  tileWidth;
//                chipheight = (Bankheight  + columnlogicwidth)* nBanks
//                             + dqwidth;
//            }
//        }
//        else
//        {
//            std::cout << "ERROR: 3D has a wrong value" << std::endl;
//            exit (EXIT_FAILURE);
//        }

//    } else if (tilesPerBank == 2)
//    {
//        //For the case of half banks
//        subArrayPerTile = 0.5f * pageSize
//                             * subArrayRatioToPage
//                             * 1024
//                             * 8
//                             / (float)(cellsPerLWL - cellsPerLWLRedundancy);

//        tileWidth = subArrayPerTile * subArrayWidth + WLDriverWidth + mwldwidth;

//        //If it is a 3D architecture
//        if(ThreeD == "ON")
//        {
//                if(nBanks > 1)
//            {
//                if((int)log2(nBanks) % 2 == 0)
//                {
//                    //If the number of banks is greater than 1
//                    // and it is an even power of 2,
//                    // the number of banks horizontally,
//                    // and vertically are made equal (square shaped)
//                    chipwidth = pow(2,(int)(log2(nBanks)/2))
//                                 *tileWidth*2;
//                    chipheight = (Bankheight+ columnlogicwidth)
//                                  *pow(2,(int)(log2(nBanks)/2))
//                                 + dqwidth
//                                  *pow(2,(int)(log2(nBanks)/2))/2
//                                 + 50*(pow(2,(int)(log2(nBanks)/2))-1);

//                }
//                else
//                {
//                    //If the number of banks is greater than 1
//                    // and it is not an even (odd) power of 2,
//                    // the number of banks horizontally,
//                    // and vertically are arranged such that
//                    // no dummy is needed,
//                    // so it is more rectangular in the x direction
//                    rows = (int)log2(nBanks)
//                           - (int)(log2(nBanks)/2);
//                    x = pow(2,rows);
//                    columns = (int)(log2(nBanks)/2);
//                    y = pow(2,columns);
//                    chipwidth = y * tileWidth*2;
//                    chipheight = (Bankheight + columnlogicwidth) * x
//                                 + (x/2) * dqwidth
//                                 + 50*(x-1);
//                }

//            }
//            //Case if there is one bank,
//            // unlikely case but necessary nonetheless
//            if(nBanks == 1)
//            {
//                //The chip width is equal to twice the bank width,
//                // because it is a quarter bank
//                // and it has 2 quarter banks horizontally,
//                // multiplied by the number of banks horizontally
//                chipwidth =  tileWidth*2;

//                //The bank height
//                // in addition to the column logic width
//                // multiplied by 2 because of the quarter bank and
//                // multiplied by the number of banks vertically
//                // in addition to the dq width
//                // and an extra 100 micrometers and 50 micrometers in between
//                // for Power TSVs and test structures  because it is 3D
//                chipheight = Bankheight  + columnlogicwidth + dqwidth;
//            }


//        }
//        //If it is not 3D architecture
//        if(ThreeD == "OFF")
//        {
//            if(nBanks > 3)
//            {
//                //DEEPAK
//                chipwidth = (nBanks/4)*(tileWidth*2);
//                //DEEPAK
//                chipheight = (Bankheight +columnlogicwidth) *4 + 2*dqwidth;
//            }
//            else
//            {
//                chipwidth = tileWidth;
//                chipheight = (Bankheight + columnlogicwidth)* nBanks
//                             + dqwidth;
//            }
//        }
//    } else if (tilesPerBank == 4)
//    {
//        //For the case of quarter banks
//        subArrayPerTile = 0.5f * pageSize
//                             * subArrayRatioToPage
//                             * 1024
//                             * 8
//                             /(float)(cellsPerLWL - cellsPerLWLRedundancy);

//        tileWidth = subArrayPerTile * subArrayWidth + WLDriverWidth + mwldwidth;

//        if(ThreeD == "ON") //If it is 3D architecture
//        {
//            if(nBanks > 1)
//            {
//                if((int)log2(nBanks) % 2 == 0)
//                {
//                    //If the number of banks is greater than 1
//                    // and it is an even power of 2,
//                    // the number of banks horizontally,
//                    // and vertically are made equal (square shaped)
//                    chipwidth = pow(2,(int)(log2(nBanks)/2))
//                                * tileWidth*2;

//                    chipheight = (Bankheight + columnlogicwidth)
//                                   *pow(2,(int)(log2(nBanks)/2))*2
//                                 + (dqwidth+100)
//                                   *pow(2,(int)(log2(nBanks)/2))/2
//                                 + 50*(pow(2,(int)(log2(nBanks)/2))-1);
//                }
//                else
//                {
//                    //If the number of banks is greater than 1
//                    // and it is not an even (odd) power of 2,
//                    // the number of banks horizontally,
//                    // and vertically are arranged such that
//                    // no dummy is needed,
//                    // so it is more rectangular in the x direction
//                    rows = (int)log2(nBanks)
//                            - (int)(log2(nBanks)/2);
//                    x = pow(2,rows);
//                    columns = (int)(log2(nBanks)/2);
//                    y = pow(2,columns);
//                    //The chip width is equal to twice the bank width,
//                    // because it is a quarter bank
//                    // and it has 2 quarter banks horizontally,
//                    // multiplied by the number of banks horizontally
//                    chipwidth = y * tileWidth*2;

//                    //The bank height
//                    // in addition to the column logic width
//                    // multiplied by 2 because of the quarter bank and
//                    // multiplied by the number of banks vertically
//                    // in addition to the dq width and
//                    // an extra 100 micrometers and 50 micrometers in between
//                    // for Power TSVs and test structures  because it is 3D
//                    chipheight = ((Bankheight + columnlogicwidth) * x*2)
//                                  + (x/2) * (dqwidth+100)
//                                  + 50*(x-1);
//                }

//            }
//            //Case if there is one bank,
//            // unlikely case but necessary nonetheless
//            if(nBanks == 1)
//            {
//                chipwidth =  tileWidth*2;
//                chipheight = Bankheight  + columnlogicwidth + dqwidth+100;
//            }
//        }
//        //If it is not 3D architecture
//        if(ThreeD == "OFF")
//        {
//            if(nBanks > 3)
//            {
//                chipwidth = (nBanks/4)* tileWidth*2;
//                chipheight = (Bankheight + columnlogicwidth) * 8
//                              + 2 *(dqwidth+100);
//            }
//            else
//            {
//                chipwidth =  tileWidth;
//                chipheight = Bankheight  + columnlogicwidth + dqwidth+100;
//            }

//        }

//    }
//    else
//    {
//        std::cout << "ERROR: tilesperbank must be 1,2 or 4" << std::endl;
//        exit (EXIT_FAILURE);
//    }
//    // Warning if non-3D chip dimensions exceed 11x9 mm
//    if(ThreeD == "OFF" && (chipheight > 9000 || chipwidth > 11000))
//    {
//        std::cout<< "Chip dimensions are larger than 11x9 mm"<<"\n";
//    }
//    // Warning if 3D chip dimensions exceed 12x12 mm
//    if(ThreeD == "ON" && (chipheight > 12000 || chipwidth > 12000))
//    {
//        std::cout<< "Chip dimensions are larger than 12x12 mm"<<"\n";
//    }
//    //chip area in mm^2
//    chiparea = chipwidth * chipheight/1000000;

//    std::cout << std::endl<< std::endl << numberofMemoryArrays*subArrayPerTile*512*512*8*tilesPerBank/1024/1024/1024<< std::endl<< std::endl<< std::endl;


//    return true;
//}
