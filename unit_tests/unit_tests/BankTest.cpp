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

#ifndef BANKTEST_CPP
#define BANKTEST_CPP

#include <boost/test/included/unit_test.hpp>

#include "../../core/Bank.h"

BOOST_AUTO_TEST_SUITE( testBank )

BOOST_AUTO_TEST_CASE( checkBank_real_input )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "../../technology_input/test_technology.json",
                        "-p",
                        "../../architecture_input/test_architecture.json"};

    ArgumentsParser inputFileName(sim_argc, sim_argv);

    std::string exceptionMsg("Empty");
    try {
        inputFileName.runArgParser();
    }catch (std::string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }

    std::string expectedMsg("Empty");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

    Bank bank(inputFileName.technologyFileName[0],
                      inputFileName.architectureFileName[0]);

    BOOST_CHECK_MESSAGE( bank.bankStorage == 134217728*drs::bits_per_bank,
                        "Bank storage size different from the expected."
                        << "\nExpected: " << 134217728*drs::bits_per_bank
                        << "\nGot: " << bank.bankStorage);

    BOOST_CHECK_MESSAGE( ceil(bank.bankWidth) == 2799*drs::micrometer_per_bank,
                        "Width of bank different from the expected."
                        << "\nExpected: " << 2799*drs::micrometer_per_bank
                        << "\nGot: " << ceil(bank.bankWidth));

    BOOST_CHECK_MESSAGE( ceil(bank.bankHeight) == 2124*drs::micrometer_per_bank,
                        "Height of bank different from the expected."
                        << "\nExpected: " << 2124*drs::micrometer_per_bank
                        << "\nGot: " << ceil(bank.bankHeight));
}

BOOST_AUTO_TEST_CASE( checkBank_dummy_input )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "../../technology_input/tech_dummy_input.json",
                        "-p",
                        "../../architecture_input/arch_dummy_input.json"};

    ArgumentsParser inputFileName(sim_argc, sim_argv);

    std::string exceptionMsg("Empty");
    try {
        inputFileName.runArgParser();
    }catch (std::string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }

    std::string expectedMsg("Empty");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

    try {
        Bank bank(inputFileName.technologyFileName[0],
                  inputFileName.architectureFileName[0]);
    }catch (std::string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }

    expectedMsg = "[ERROR] Architecture must have ";
    expectedMsg.append("1, 2 or 4 tile per bank.");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

}

BOOST_AUTO_TEST_CASE( checkBank_different_tile_configs )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "../../technology_input/test_technology.json",
                        "-p",
                        "../../architecture_input/test_architecture.json"};

    ArgumentsParser inputFileName(sim_argc, sim_argv);

    std::string exceptionMsg("Empty");
    try {
        inputFileName.runArgParser();
    }catch (std::string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }

    std::string expectedMsg("Empty");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

    Bank bank(inputFileName.technologyFileName[0],
                      inputFileName.architectureFileName[0]);

    bank.tilesPerBank = 1.0*drs::tiles_per_bank;
    bank.pageSpanningFactor = 1*drs::pages_per_tile;
    try {
        bank.tileCompute();
    }catch (std::string exceptionMsgThrown){
        std::cerr << exceptionMsgThrown << std::endl;
    }
    bank.bankCompute();

    BOOST_CHECK_MESSAGE( bank.bankStorage == 134217728*drs::bits_per_bank,
                        "Bank storage size different from the expected."
                        << "\nExpected: " << 134217728*drs::bits_per_bank
                        << "\nGot: " << bank.bankStorage);

    BOOST_CHECK_MESSAGE( ceil(bank.bankWidth) == 2550*drs::micrometer_per_bank,
                        "Width of bank different from the expected."
                        << "\nExpected: " << 2550*drs::micrometer_per_bank
                        << "\nGot: " << ceil(bank.bankWidth));

    BOOST_CHECK_MESSAGE( ceil(bank.bankHeight) == 2124*drs::micrometer_per_bank,
                        "Height of bank different from the expected."
                        << "\nExpected: " << 2124*drs::micrometer_per_bank
                        << "\nGot: " << ceil(bank.bankHeight));

    bank.tilesPerBank = 2.0*drs::tiles_per_bank;
    bank.pageSpanningFactor = 1*drs::pages_per_tile;
    try {
        bank.tileCompute();
    }catch (std::string exceptionMsgThrown){
        std::cerr << exceptionMsgThrown << std::endl;
    }
    bank.bankCompute();

    BOOST_CHECK_MESSAGE( bank.bankStorage == 134217728*drs::bits_per_bank,
                        "Bank storage size different from the expected."
                        << "\nExpected: " << 134217728*drs::bits_per_bank
                        << "\nGot: " << bank.bankStorage);

    BOOST_CHECK_MESSAGE( ceil(bank.bankWidth) == 5099*drs::micrometer_per_bank,
                        "Width of bank different from the expected."
                        << "\nExpected: " << 5099*drs::micrometer_per_bank
                        << "\nGot: " << ceil(bank.bankWidth));

    BOOST_CHECK_MESSAGE( ceil(bank.bankHeight) == 1209*drs::micrometer_per_bank,
                        "Height of bank different from the expected."
                        << "\nExpected: " << 1209*drs::micrometer_per_bank
                        << "\nGot: " << ceil(bank.bankHeight));

    bank.tilesPerBank = 4.0*drs::tiles_per_bank;
    bank.pageSpanningFactor = 1*drs::pages_per_tile;
    try {
        bank.tileCompute();
    }catch (std::string exceptionMsgThrown){
        std::cerr << exceptionMsgThrown << std::endl;
    }
    bank.bankCompute();

    BOOST_CHECK_MESSAGE( bank.bankStorage == 134217728*drs::bits_per_bank,
                        "Bank storage size different from the expected."
                        << "\nExpected: " << 134217728*drs::bits_per_bank
                        << "\nGot: " << bank.bankStorage);

    BOOST_CHECK_MESSAGE( ceil(bank.bankWidth) == 5099*drs::micrometer_per_bank,
                        "Width of bank different from the expected."
                        << "\nExpected: " << 5099*drs::micrometer_per_bank
                        << "\nGot: " << ceil(bank.bankWidth));

    BOOST_CHECK_MESSAGE( ceil(bank.bankHeight) == 1504*drs::micrometer_per_bank,
                        "Height of bank different from the expected."
                        << "\nExpected: " << 1504*drs::micrometer_per_bank
                        << "\nGot: " << ceil(bank.bankHeight));
}

BOOST_AUTO_TEST_SUITE_END()

#endif // BANKTEST_CPP
