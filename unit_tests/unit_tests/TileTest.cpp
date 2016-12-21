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
 * Authors: Omar Naji
 *          Matthias Jung
 *          Christian Weis
 *          Kamal Haddad
 *          Andr'e Lucas Chinazzo
 */

#ifndef TILETEST_CPP
#define TILETEST_CPP

#include <boost/test/included/unit_test.hpp>

#include "../core/Tile.h"

BOOST_AUTO_TEST_SUITE( testTile )

BOOST_AUTO_TEST_CASE( checkTile_real_input )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "../technology_input/techddr3_5x.json",
                        "-p",
                        "../architecture_input/parddr3.json"};

    ArgumentsParser inputFileName(sim_argc, sim_argv);

    string exceptionMsg("Empty");
    try {
        inputFileName.runArgParser();
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }

    string expectedMsg("Empty");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

    Tile tile(inputFileName.technologyFileName[0],
                      inputFileName.architectureFileName[0]);

    BOOST_CHECK_MESSAGE( tile.tileStorage == 134217728*drs::bits_per_tile,
                        "Tile storage size different from the expected."
                        << "\nExpected: " << 13421772*drs::bits_per_tile
                        << "\nGot: " << tile.tileStorage);

    BOOST_CHECK_MESSAGE( tile.tileWidth == 1159.08*drs::micrometer_per_tile,
                        "Width of tile different from the expected."
                        << "\nExpected: " << 1159.08*drs::micrometer_per_tile
                        << "\nGot: " << tile.tileWidth);

    BOOST_CHECK_MESSAGE( tile.tileHeight == 3752.56*drs::micrometer_per_tile,
                        "Width of tile different from the expected."
                        << "\nExpected: " << 3752.56*drs::micrometer_per_tile
                        << "\nGot: " << tile.tileHeight);

    BOOST_CHECK_MESSAGE( tile.nSubArraysPerArrayBlock == 16*drs::subarray_per_tile,
                        "Width of tile different from the expected."
                        << "\nExpected: " << 16*drs::subarray_per_tile
                        << "\nGot: " << tile.nSubArraysPerArrayBlock);

    BOOST_CHECK_MESSAGE( tile.nArrayBlocksPerTile == 33*drs::subarray_per_tile,
                        "Width of tile different from the expected."
                        << "\nExpected: " << 33*drs::subarray_per_tile
                        << "\nGot: " << tile.nArrayBlocksPerTile);


}

BOOST_AUTO_TEST_CASE( checkTile_dummy_input )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "../technology_input/tech_dummy_input.json",
                        "-p",
                        "../architecture_input/arch_dummy_input.json"};

    ArgumentsParser inputFileName(sim_argc, sim_argv);

    string exceptionMsg("Empty");
    try {
        inputFileName.runArgParser();
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }

    string expectedMsg("Empty");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

    Tile tile(inputFileName.technologyFileName[0],
                      inputFileName.architectureFileName[0]);

    BOOST_CHECK_MESSAGE( tile.tileStorage == 134217728*drs::bits_per_tile,
                        "Tile storage size different from the expected."
                        << "\nExpected: " << 13421772*drs::bits_per_tile
                        << "\nGot: " << tile.tileStorage);


}

BOOST_AUTO_TEST_SUITE_END()

#endif // TILETEST_CPP
