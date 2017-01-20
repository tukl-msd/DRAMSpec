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

#ifndef CHIPTEST_CPP
#define CHIPTEST_CPP

#include <boost/test/included/unit_test.hpp>

#include "../core/Chip.h"

BOOST_AUTO_TEST_SUITE( testChip )

BOOST_AUTO_TEST_CASE( checkChip_real_input )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "../technology_input/techddr3_5x.json",
                        "-p",
                        "../architecture_input/parddr3.json"};

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

    Chip chip(inputFileName.technologyFileName[0],
                      inputFileName.architectureFileName[0]);

    BOOST_CHECK_MESSAGE( chip.chipStorage == 1*drs::gibibits,
                        "Chip storage size different from the expected."
                        << "\nExpected: " << 1*drs::gibibits
                        << "\nGot: " << chip.chipStorage);

    BOOST_CHECK_MESSAGE( ceil(chip.chipWidth) == 5603*drs::micrometer,
                        "Width of chip different from the expected."
                        << "\nExpected: " << 5603*drs::micrometer
                        << "\nGot: " << ceil(chip.chipWidth));

    BOOST_CHECK_MESSAGE( ceil(chip.chipHeight) == 8406*drs::micrometer,
                        "Height of chip different from the expected."
                        << "\nExpected: " << 8406*drs::micrometer
                        << "\nGot: " << ceil(chip.chipHeight));

    BOOST_CHECK_MESSAGE( ceil(chip.chipArea) == 48*drs::millimeter_squared,
                        "Area of chip different from the expected."
                        << "\nExpected: " << 48*drs::millimeter_squared
                        << "\nGot: " << ceil(chip.chipArea));

}

BOOST_AUTO_TEST_CASE( checkChip_dummy_input )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "../technology_input/tech_dummy_input.json",
                        "-p",
                        "../architecture_input/arch_dummy_input.json"};

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
        Chip chip(inputFileName.technologyFileName[0],
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

    Chip chip;
    chip.readjson(inputFileName.technologyFileName[0],
                  inputFileName.architectureFileName[0]);
    try {
        chip.chipInitialize();
    }catch (std::string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }

    expectedMsg = "[ERROR] Architecture must have ";
    expectedMsg.append("1, 2, 4, 6 or 8 banks.");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);


}

BOOST_AUTO_TEST_CASE( checkChip_different_bank_configs )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "../technology_input/techddr3_5x.json",
                        "-p",
                        "../architecture_input/parddr3.json"};

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

    Chip chip(inputFileName.technologyFileName[0],
                      inputFileName.architectureFileName[0]);

    chip.nBanks = 1.0*drs::bank;
    try {
        chip.tileInitialize();
    }catch (std::string exceptionMsgThrown){
        std::cerr << exceptionMsgThrown << std::endl;
    }
    chip.bankInitialize();
    chip.chipInitialize();

    BOOST_CHECK_MESSAGE( chip.chipStorage == 1*drs::gibibits,
                        "Chip storage size different from the expected."
                        << "\nExpected: " << 1*drs::gibibits
                        << "\nGot: " << chip.chipStorage);

    BOOST_CHECK_MESSAGE( ceil(chip.chipWidth) == 1400*drs::micrometer,
                        "Width of chip different from the expected."
                        << "\nExpected: " << 1400*drs::micrometer
                        << "\nGot: " << ceil(chip.chipWidth));

    BOOST_CHECK_MESSAGE( ceil(chip.chipHeight) == 30061*drs::micrometer,
                        "Height of chip different from the expected."
                        << "\nExpected: " << 30061*drs::micrometer
                        << "\nGot: " << ceil(chip.chipHeight));

    BOOST_CHECK_MESSAGE( ceil(chip.chipArea) == 43*drs::millimeter_squared,
                        "Area of chip different from the expected."
                        << "\nExpected: " << 43*drs::millimeter_squared
                        << "\nGot: " << ceil(chip.chipArea));

    chip.nBanks = 2.0*drs::bank;
    try {
        chip.tileInitialize();
    }catch (std::string exceptionMsgThrown){
        std::cerr << exceptionMsgThrown << std::endl;
    }
    chip.bankInitialize();
    chip.chipInitialize();

    BOOST_CHECK_MESSAGE( chip.chipStorage == 1*drs::gibibits,
                        "Chip storage size different from the expected."
                        << "\nExpected: " << 1*drs::gibibits
                        << "\nGot: " << chip.chipStorage);

    BOOST_CHECK_MESSAGE( ceil(chip.chipWidth) == 2801*drs::micrometer,
                        "Width of chip different from the expected."
                        << "\nExpected: " << 2801*drs::micrometer
                        << "\nGot: " << ceil(chip.chipWidth));

    BOOST_CHECK_MESSAGE( ceil(chip.chipHeight) == 15428*drs::micrometer,
                        "Height of chip different from the expected."
                        << "\nExpected: " << 15428*drs::micrometer
                        << "\nGot: " << ceil(chip.chipHeight));

    BOOST_CHECK_MESSAGE( ceil(chip.chipArea) == 44*drs::millimeter_squared,
                        "Area of chip different from the expected."
                        << "\nExpected: " << 44*drs::millimeter_squared
                        << "\nGot: " << ceil(chip.chipArea));

    chip.nBanks = 4.0*drs::bank;
    try {
        chip.tileInitialize();
    }catch (std::string exceptionMsgThrown){
        std::cerr << exceptionMsgThrown << std::endl;
    }
    chip.bankInitialize();
    chip.chipInitialize();

    BOOST_CHECK_MESSAGE( chip.chipStorage == 1*drs::gibibits,
                        "Chip storage size different from the expected."
                        << "\nExpected: " << 1*drs::gibibits
                        << "\nGot: " << chip.chipStorage);

    BOOST_CHECK_MESSAGE( ceil(chip.chipWidth) == 2801*drs::micrometer,
                        "Width of chip different from the expected."
                        << "\nExpected: " << 2801*drs::micrometer
                        << "\nGot: " << ceil(chip.chipWidth));

    BOOST_CHECK_MESSAGE( ceil(chip.chipHeight) == 15722*drs::micrometer,
                        "Height of chip different from the expected."
                        << "\nExpected: " << 15722*drs::micrometer
                        << "\nGot: " << ceil(chip.chipHeight));

    BOOST_CHECK_MESSAGE( ceil(chip.chipArea) == 45*drs::millimeter_squared,
                        "Area of chip different from the expected."
                        << "\nExpected: " << 45*drs::millimeter_squared
                        << "\nGot: " << ceil(chip.chipArea));

    chip.nBanks = 6.0*drs::bank;
    try {
        chip.tileInitialize();
    }catch (std::string exceptionMsgThrown){
        std::cerr << exceptionMsgThrown << std::endl;
    }
    chip.bankInitialize();
    chip.chipInitialize();

    BOOST_CHECK_MESSAGE( chip.chipStorage == 1*drs::gibibits,
                        "Chip storage size different from the expected."
                        << "\nExpected: " << 1*drs::gibibits
                        << "\nGot: " << chip.chipStorage);

    BOOST_CHECK_MESSAGE( ceil(chip.chipWidth) == 4202*drs::micrometer,
                        "Width of chip different from the expected."
                        << "\nExpected: " << 4202*drs::micrometer
                        << "\nGot: " << ceil(chip.chipWidth));

    BOOST_CHECK_MESSAGE( ceil(chip.chipHeight) == 10844*drs::micrometer,
                        "Height of chip different from the expected."
                        << "\nExpected: " << 10844*drs::micrometer
                        << "\nGot: " << ceil(chip.chipHeight));

    BOOST_CHECK_MESSAGE( ceil(chip.chipArea) == 46*drs::millimeter_squared,
                        "Area of chip different from the expected."
                        << "\nExpected: " << 46*drs::millimeter_squared
                        << "\nGot: " << ceil(chip.chipArea));

    chip.nBanks = 8.0*drs::bank;
    try {
        chip.tileInitialize();
    }catch (std::string exceptionMsgThrown){
        std::cerr << exceptionMsgThrown << std::endl;
    }
    chip.bankInitialize();
    chip.chipInitialize();

    BOOST_CHECK_MESSAGE( chip.chipStorage == 1*drs::gibibits,
                        "Chip storage size different from the expected."
                        << "\nExpected: " << 1*drs::gibibits
                        << "\nGot: " << chip.chipStorage);

    BOOST_CHECK_MESSAGE( ceil(chip.chipWidth) == 5603*drs::micrometer,
                        "Width of chip different from the expected."
                        << "\nExpected: " << 5603*drs::micrometer
                        << "\nGot: " << ceil(chip.chipWidth));

    BOOST_CHECK_MESSAGE( ceil(chip.chipHeight) == 8406*drs::micrometer,
                        "Height of chip different from the expected."
                        << "\nExpected: " << 8406*drs::micrometer
                        << "\nGot: " << ceil(chip.chipHeight));

    BOOST_CHECK_MESSAGE( ceil(chip.chipArea) == 48*drs::millimeter_squared,
                        "Area of chip different from the expected."
                        << "\nExpected: " << 48*drs::millimeter_squared
                        << "\nGot: " << ceil(chip.chipArea));

}

BOOST_AUTO_TEST_SUITE_END()

#endif // CHIPTEST_CPP
