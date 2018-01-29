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



#ifndef TILETEST_CPP
#define TILETEST_CPP

#include <boost/test/included/unit_test.hpp>

#include "../../core/Tile.h"

using boost::units::engineering_prefix;

BOOST_AUTO_TEST_SUITE( testTile )

BOOST_AUTO_TEST_CASE( checkTile_real_input )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "../../technology_input/test_technology.json",
                        "-p",
                        "../../architecture_input/test_architecture.json"};

    ArgumentsParser inputFileName(sim_argc, sim_argv);

    string exceptionMsg("Empty");
    try {
        inputFileName.runArgParser();
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    string expectedMsg("Empty");
    if ( exceptionMsg != expectedMsg ) {
        BOOST_FAIL( exceptionMsg );
    }

    Tile tile;
    try {
        tile = Tile(inputFileName.technologyFileName[0],
                    inputFileName.architectureFileName[0]);
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    expectedMsg = string("Empty");
    if ( exceptionMsg != expectedMsg ) {
        BOOST_FAIL( exceptionMsg );
    }


    BOOST_CHECK_MESSAGE( tile.tileStorage == 134217728/2.0*drs::bits,
                        "Tile storage size different from the expected."
                        << "\nExpected: " << 134217728/2.0*drs::bits
                        << "\nGot: " << tile.tileStorage);

    BOOST_CHECK_MESSAGE( ceil(tile.tileWidth) == 1160*drs::micrometer,
                        "Width of tile different from the expected."
                        << "\nExpected: " << 1160*drs::micrometer
                        << "\nGot: " << ceil(tile.tileWidth));

    BOOST_CHECK_MESSAGE( ceil(tile.tileHeight) == 2124*drs::micrometer,
                        "Height of tile different from the expected."
                        << "\nExpected: " << 2124*drs::micrometer
                        << "\nGot: " << ceil(tile.tileHeight));

    BOOST_CHECK_MESSAGE( tile.nSubArraysPerArrayBlock == 16,
                        "Number of subarrays in the wordline direction per tile "
                        << "different from the expected."
                        << "\nExpected: " << 16
                        << "\nGot: " << tile.nSubArraysPerArrayBlock);

    BOOST_CHECK_MESSAGE( tile.nArrayBlocksPerTile == 17,
                        "Number of subarrays in the bitline direction per tile "
                        << "different from the expected."
                        << "\nExpected: " << 17
                        << "\nGot: " << tile.nArrayBlocksPerTile);


}

BOOST_AUTO_TEST_CASE( checkTile_dummy_input )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "../../technology_input/tech_dummy_input.json",
                        "-p",
                        "../../architecture_input/arch_dummy_input.json"};

    ArgumentsParser inputFileName(sim_argc, sim_argv);

    string exceptionMsg("Empty");
    try {
        inputFileName.runArgParser();
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    string expectedMsg("Empty");
    if ( exceptionMsg != expectedMsg ) {
        BOOST_FAIL( exceptionMsg );
    }

    try {
        Tile tile(inputFileName.technologyFileName[0],
                  inputFileName.architectureFileName[0]);
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    expectedMsg = "[ERROR] Architecture must have ";
    expectedMsg.append("1, 2 or 4 tile per bank.");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

}

BOOST_AUTO_TEST_CASE( checkTile_different_tile_and_page_configs )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "../../technology_input/test_technology.json",
                        "-p",
                        "../../architecture_input/test_architecture.json"};

    ArgumentsParser inputFileName(sim_argc, sim_argv);

    string exceptionMsg("Empty");
    try {
        inputFileName.runArgParser();
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    string expectedMsg("Empty");
    if ( exceptionMsg != expectedMsg ) {
        BOOST_FAIL( exceptionMsg );
    }

    Tile tile;
    try {
        tile = Tile(inputFileName.technologyFileName[0],
                    inputFileName.architectureFileName[0]);
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    expectedMsg = string("Empty");
    if ( exceptionMsg != expectedMsg ) {
        BOOST_FAIL( exceptionMsg );
    }


    tile.subArrayToPageFactor = 2;
    try {
        tile.tileCompute();
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    BOOST_CHECK_MESSAGE( tile.tileStorage == 134217728/2.*drs::bits,
                        "Tile storage size different from the expected."
                        << "\nExpected: " << 134217728/2.*drs::bits
                        << "\nGot: " << tile.tileStorage);

    BOOST_CHECK_MESSAGE( ceil(tile.tileWidth) == 2310*drs::micrometer,
                        "Width of tile different from the expected."
                        << "\nExpected: " << 2310*drs::micrometer
                        << "\nGot: " << ceil(tile.tileWidth));

    BOOST_CHECK_MESSAGE( ceil(tile.tileHeight) == 1209*drs::micrometer,
                        "Height of tile different from the expected."
                        << "\nExpected: " << 1209*drs::micrometer
                        << "\nGot: " << ceil(tile.tileHeight));

    BOOST_CHECK_MESSAGE( tile.nSubArraysPerArrayBlock == 32,
                        "Number of subarrays in the wordline direction per tile "
                        << "different from the expected."
                        << "\nExpected: " << 32
                        << "\nGot: " << tile.nSubArraysPerArrayBlock);

    BOOST_CHECK_MESSAGE( tile.nArrayBlocksPerTile == 9,
                        "Number of subarrays in the bitline direction per tile "
                        << "different from the expected."
                        << "\nExpected: " << 9
                        << "\nGot: " << tile.nArrayBlocksPerTile);






    tile.subArrayToPageFactor = 1;
    tile.nTilesPerBank = 1;
    tile.pageSpanningFactor = 0.51;
    try {
        tile.tileCompute();
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }

    expectedMsg = "[ERROR] If architecture has 1 tile per bank, ";
    expectedMsg.append("the page spanning factor across the tile must be 1.");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

    tile.pageSpanningFactor = 1;
    try {
        tile.tileCompute();
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    BOOST_CHECK_MESSAGE( tile.tileStorage == 134217728*drs::bits,
                        "Tile storage size different from the expected."
                        << "\nExpected: " << 134217728*drs::bits
                        << "\nGot: " << tile.tileStorage);

    BOOST_CHECK_MESSAGE( ceil(tile.tileWidth) == 2310*drs::micrometer,
                        "Width of tile different from the expected."
                        << "\nExpected: " << 2310*drs::micrometer
                        << "\nGot: " << ceil(tile.tileWidth));

    BOOST_CHECK_MESSAGE( ceil(tile.tileHeight) == 2124*drs::micrometer,
                        "Height of tile different from the expected."
                        << "\nExpected: " << 2124*drs::micrometer
                        << "\nGot: " << ceil(tile.tileHeight));

    BOOST_CHECK_MESSAGE( tile.nSubArraysPerArrayBlock == 32,
                        "Number of subarrays in the wordline direction per tile "
                        << "different from the expected."
                        << "\nExpected: " << 32
                        << "\nGot: " << tile.nSubArraysPerArrayBlock);

    BOOST_CHECK_MESSAGE( tile.nArrayBlocksPerTile == 17,
                        "Number of subarrays in the bitline direction per tile "
                        << "different from the expected."
                        << "\nExpected: " << 17
                        << "\nGot: " << tile.nArrayBlocksPerTile);



    tile.nTilesPerBank = 2;
    tile.pageSpanningFactor = 0.51;
    try {
        tile.tileCompute();
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    expectedMsg = "[ERROR] If architecture has 2 tile per bank, ";
    expectedMsg.append("the page spanning factor across the tile must be 1 or 0.5.");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

    tile.pageSpanningFactor = 1;
    try {
        tile.tileCompute();
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    BOOST_CHECK_MESSAGE( tile.tileStorage == 67108864*drs::bits,
                        "Tile storage size different from the expected."
                        << "\nExpected: " << 67108864*drs::bits
                        << "\nGot: " << tile.tileStorage);

    BOOST_CHECK_MESSAGE( ceil(tile.tileWidth) == 2310*drs::micrometer,
                        "Width of tile different from the expected."
                        << "\nExpected: " << 2310*drs::micrometer
                        << "\nGot: " << ceil(tile.tileWidth));

    BOOST_CHECK_MESSAGE( ceil(tile.tileHeight) == 1209*drs::micrometer,
                        "Height of tile different from the expected."
                        << "\nExpected: " << 1209*drs::micrometer
                        << "\nGot: " << ceil(tile.tileHeight));

    BOOST_CHECK_MESSAGE( tile.nSubArraysPerArrayBlock == 32,
                        "Number of subarrays in the wordline direction per tile "
                        << "different from the expected."
                        << "\nExpected: " << 32
                        << "\nGot: " << tile.nSubArraysPerArrayBlock);

    BOOST_CHECK_MESSAGE( tile.nArrayBlocksPerTile == 9,
                        "Number of subarrays in the bitline direction per tile "
                        << "different from the expected."
                        << "\nExpected: " << 9
                        << "\nGot: " << tile.nArrayBlocksPerTile);


    tile.pageSpanningFactor = 0.5;
    try {
        tile.tileCompute();
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    BOOST_CHECK_MESSAGE( tile.tileStorage == 67108864*drs::bits,
                        "Tile storage size different from the expected."
                        << "\nExpected: " << 67108864*drs::bits
                        << "\nGot: " << tile.tileStorage);

    BOOST_CHECK_MESSAGE( ceil(tile.tileWidth) == 1160*drs::micrometer,
                        "Width of tile different from the expected."
                        << "\nExpected: " << 1160*drs::micrometer
                        << "\nGot: " << ceil(tile.tileWidth));

    BOOST_CHECK_MESSAGE( ceil(tile.tileHeight) == 2124*drs::micrometer,
                        "Height of tile different from the expected."
                        << "\nExpected: " << 2124*drs::micrometer
                        << "\nGot: " << ceil(tile.tileHeight));

    BOOST_CHECK_MESSAGE( tile.nSubArraysPerArrayBlock == 16,
                        "Number of subarrays in the wordline direction per tile "
                        << "different from the expected."
                        << "\nExpected: " << 16
                        << "\nGot: " << tile.nSubArraysPerArrayBlock);

    BOOST_CHECK_MESSAGE( tile.nArrayBlocksPerTile == 17,
                        "Number of subarrays in the bitline direction per tile "
                        << "different from the expected."
                        << "\nExpected: " << 17
                        << "\nGot: " << tile.nArrayBlocksPerTile);



    tile.nTilesPerBank = 4;
    tile.pageSpanningFactor = 0.51;
    try {
        tile.tileCompute();
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }

    expectedMsg = "[ERROR] If architecture has 4 tile per bank, ";
    expectedMsg.append("the page spanning factor across the tile must be 1, 0.5 or 0.25.");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

    tile.pageSpanningFactor = 1;
    try {
        tile.tileCompute();
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    BOOST_CHECK_MESSAGE( tile.tileStorage == 33554432*drs::bits,
                        "Tile storage size different from the expected."
                        << "\nExpected: " << 33554432*drs::bits
                        << "\nGot: " << tile.tileStorage);

    BOOST_CHECK_MESSAGE( ceil(tile.tileWidth) == 2310*drs::micrometer,
                        "Width of tile different from the expected."
                        << "\nExpected: " << 2310*drs::micrometer
                        << "\nGot: " << ceil(tile.tileWidth));

    BOOST_CHECK_MESSAGE( ceil(tile.tileHeight) == 752*drs::micrometer,
                        "Height of tile different from the expected."
                        << "\nExpected: " << 752*drs::micrometer
                        << "\nGot: " << ceil(tile.tileHeight));

    BOOST_CHECK_MESSAGE( tile.nSubArraysPerArrayBlock == 32,
                        "Number of subarrays in the wordline direction per tile "
                        << "different from the expected."
                        << "\nExpected: " << 32
                        << "\nGot: " << tile.nSubArraysPerArrayBlock);

    BOOST_CHECK_MESSAGE( tile.nArrayBlocksPerTile == 5,
                        "Number of subarrays in the bitline direction per tile "
                        << "different from the expected."
                        << "\nExpected: " << 5
                        << "\nGot: " << tile.nArrayBlocksPerTile);




    tile.pageSpanningFactor = 0.5;
    try {
        tile.tileCompute();
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    BOOST_CHECK_MESSAGE( tile.tileStorage == 33554432*drs::bits,
                        "Tile storage size different from the expbits_per_tileected."
                        << "\nExpected: " << 33554432*drs::bits
                        << "\nGot: " << tile.tileStorage);

    BOOST_CHECK_MESSAGE( ceil(tile.tileWidth) == 1160*drs::micrometer,
                        "Width of tile different from the expected."
                        << "\nExpected: " << 1160*drs::micrometer
                        << "\nGot: " << ceil(tile.tileWidth));

    BOOST_CHECK_MESSAGE( ceil(tile.tileHeight) == 1209*drs::micrometer,
                        "Height of tile different from the expected."
                        << "\nExpected: " << 1209*drs::micrometer
                        << "\nGot: " << ceil(tile.tileHeight));

    BOOST_CHECK_MESSAGE( tile.nSubArraysPerArrayBlock == 16,
                        "Number of subarrays in the wordline direction per tile "
                        << "different from the expected."
                        << "\nExpected: " << 16
                        << "\nGot: " << tile.nSubArraysPerArrayBlock);

    BOOST_CHECK_MESSAGE( tile.nArrayBlocksPerTile == 9,
                        "Number of subarrays in the bitline direction per tile "
                        << "different from the expected."
                        << "\nExpected: " << 9
                        << "\nGot: " << tile.nArrayBlocksPerTile);



    tile.pageSpanningFactor = 0.25;
    try {
        tile.tileCompute();
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    BOOST_CHECK_MESSAGE( tile.tileStorage == 33554432*drs::bits,
                        "Tile storage size different from the expected."
                        << "\nExpected: " << 33554432*drs::bits
                        << "\nGot: " << tile.tileStorage);

    BOOST_CHECK_MESSAGE( ceil(tile.tileWidth) == 585*drs::micrometer,
                        "Width of tile different from the expected."
                        << "\nExpected: " << 585*drs::micrometer
                        << "\nGot: " << ceil(tile.tileWidth));

    BOOST_CHECK_MESSAGE( ceil(tile.tileHeight) == 2124*drs::micrometer,
                        "Height of tile different from the expected."
                        << "\nExpected: " << 2124*drs::micrometer
                        << "\nGot: " << ceil(tile.tileHeight));

    BOOST_CHECK_MESSAGE( tile.nSubArraysPerArrayBlock == 8,
                        "Number of subarrays in the wordline direction per tile "
                        << "different from the expected."
                        << "\nExpected: " << 8
                        << "\nGot: " << tile.nSubArraysPerArrayBlock);

    BOOST_CHECK_MESSAGE( tile.nArrayBlocksPerTile == 17,
                        "Number of subarrays in the bitline direction per tile "
                        << "different from the expected."
                        << "\nExpected: " << 17
                        << "\nGot: " << tile.nArrayBlocksPerTile);


}

BOOST_AUTO_TEST_SUITE_END()

#endif // TILETEST_CPP
