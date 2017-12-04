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



#ifndef CHANNELTEST_CPP
#define CHANNELTEST_CPP

#include <boost/test/included/unit_test.hpp>

#include "../../core/Channel.h"

BOOST_AUTO_TEST_SUITE( testChannel )

BOOST_AUTO_TEST_CASE( checkChannel_real_input )
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

    Channel channel;
    try {
        channel = Channel(inputFileName.technologyFileName[0],
                    inputFileName.architectureFileName[0]);
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    expectedMsg = string("Empty");
    if ( exceptionMsg != expectedMsg ) {
        BOOST_FAIL( exceptionMsg );
    }


    BOOST_CHECK_MESSAGE( channel.channelStorage == 1*drs::gibibits,
                        "Channel storage size different from the expected."
                        << "\nExpected: " << 1*drs::gibibits
                        << "\nGot: " << channel.channelStorage);

    BOOST_CHECK_MESSAGE( ceil(channel.channelWidth) == 11193*drs::micrometer,
                        "Width of channel different from the expected."
                        << "\nExpected: " << 11193*drs::micrometer
                        << "\nGot: " << ceil(channel.channelWidth));

    BOOST_CHECK_MESSAGE( ceil(channel.channelHeight) == 4897*drs::micrometer,
                        "Height of channel different from the expected."
                        << "\nExpected: " << 4897*drs::micrometer
                        << "\nGot: " << ceil(channel.channelHeight));

    BOOST_CHECK_MESSAGE( ceil(channel.channelArea) == 55*drs::square_millimeter,
                        "Area of channel different from the expected."
                        << "\nExpected: " << 55*drs::square_millimeter
                        << "\nGot: " << ceil(channel.channelArea));

}

BOOST_AUTO_TEST_CASE( checkChannel_dummy_input )
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

    Channel channel;
    try {
        channel = Channel(inputFileName.technologyFileName[0],
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

    exceptionMsg = "Empty";
    try {
        channel.readjson(inputFileName.technologyFileName[0],
                      inputFileName.architectureFileName[0]);
        channel.channelCompute();
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    expectedMsg = "[ERROR] ";
    expectedMsg.append("Total number of banks ");
    expectedMsg.append("must be a power of two.");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);


}

BOOST_AUTO_TEST_CASE( checkChannel_different_bank_configs )
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

    Channel channel;
    try {
        channel = Channel(inputFileName.technologyFileName[0],
                    inputFileName.architectureFileName[0]);
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    expectedMsg = string("Empty");
    if ( exceptionMsg != expectedMsg ) {
        BOOST_FAIL( exceptionMsg );
    }


    channel.nBanks = 1.0*drs::bank;
    channel.nHorizontalBanks = 0.0*drs::bank;
    channel.nVerticalBanks = 0.0*drs::bank;
    try {
        channel.tileCompute();
    }catch (string exceptionMsgThrown){
        cerr << exceptionMsgThrown << endl;
    }
    channel.bankCompute();
    channel.channelCompute();

    BOOST_CHECK_MESSAGE( channel.channelStorage == 1*drs::gibibits,
                        "Channel storage size different from the expected."
                        << "\nExpected: " << 1*drs::gibibits
                        << "\nGot: " << channel.channelStorage);

    BOOST_CHECK_MESSAGE( ceil(channel.channelWidth) == 2799*drs::micrometer,
                        "Width of channel different from the expected."
                        << "\nExpected: " << 2799*drs::micrometer
                        << "\nGot: " << ceil(channel.channelWidth));

    BOOST_CHECK_MESSAGE( ceil(channel.channelHeight) == 15378*drs::micrometer,
                        "Height of channel different from the expected."
                        << "\nExpected: " << 15378*drs::micrometer
                        << "\nGot: " << ceil(channel.channelHeight));

    BOOST_CHECK_MESSAGE( ceil(channel.channelArea) == 44*drs::square_millimeter,
                        "Area of channel different from the expected."
                        << "\nExpected: " << 44*drs::square_millimeter
                        << "\nGot: " << ceil(channel.channelArea));

    channel.nBanks = 2.0*drs::bank;
    channel.nHorizontalBanks = 0.0*drs::bank;
    channel.nVerticalBanks = 0.0*drs::bank;
    try {
        channel.tileCompute();
    }catch (string exceptionMsgThrown){
        cerr << exceptionMsgThrown << endl;
    }
    channel.bankCompute();
    channel.channelCompute();

    BOOST_CHECK_MESSAGE( channel.channelStorage == 1*drs::gibibits,
                        "Channel storage size different from the expected."
                        << "\nExpected: " << 1*drs::gibibits
                        << "\nGot: " << channel.channelStorage);

    BOOST_CHECK_MESSAGE( ceil(channel.channelWidth) == 5597*drs::micrometer,
                        "Width of channel different from the expected."
                        << "\nExpected: " << 5597*drs::micrometer
                        << "\nGot: " << ceil(channel.channelWidth));

    BOOST_CHECK_MESSAGE( ceil(channel.channelHeight) == 8061*drs::micrometer,
                        "Height of channel different from the expected."
                        << "\nExpected: " << 8061*drs::micrometer
                        << "\nGot: " << ceil(channel.channelHeight));

    BOOST_CHECK_MESSAGE( ceil(channel.channelArea) == 46*drs::square_millimeter,
                        "Area of channel different from the expected."
                        << "\nExpected: " << 46*drs::square_millimeter
                        << "\nGot: " << ceil(channel.channelArea));

    channel.nBanks = 4.0*drs::bank;
    channel.nHorizontalBanks = 0.0*drs::bank;
    channel.nVerticalBanks = 0.0*drs::bank;
    try {
        channel.tileCompute();
    }catch (string exceptionMsgThrown){
        cerr << exceptionMsgThrown << endl;
    }
    channel.bankCompute();
    channel.channelCompute();

    BOOST_CHECK_MESSAGE( channel.channelStorage == 1*drs::gibibits,
                        "Channel storage size different from the expected."
                        << "\nExpected: " << 1*drs::gibibits
                        << "\nGot: " << channel.channelStorage);

    BOOST_CHECK_MESSAGE( ceil(channel.channelWidth) == 5597*drs::micrometer,
                        "Width of channel different from the expected."
                        << "\nExpected: " << 5597*drs::micrometer
                        << "\nGot: " << ceil(channel.channelWidth));

    BOOST_CHECK_MESSAGE( ceil(channel.channelHeight) == 8556*drs::micrometer,
                        "Height of channel different from the expected."
                        << "\nExpected: " << 8556*drs::micrometer
                        << "\nGot: " << ceil(channel.channelHeight));

    BOOST_CHECK_MESSAGE( ceil(channel.channelArea) == 48*drs::square_millimeter,
                        "Area of channel different from the expected."
                        << "\nExpected: " << 48*drs::square_millimeter
                        << "\nGot: " << ceil(channel.channelArea));

    channel.nBanks = 8.0*drs::bank;
    channel.nHorizontalBanks = 0.0*drs::bank;
    channel.nVerticalBanks = 0.0*drs::bank;
    try {
        channel.tileCompute();
    }catch (string exceptionMsgThrown){
        cerr << exceptionMsgThrown << endl;
    }
    channel.bankCompute();
    channel.channelCompute();

    BOOST_CHECK_MESSAGE( channel.channelStorage == 1*drs::gibibits,
                        "Channel storage size different from the expected."
                        << "\nExpected: " << 1*drs::gibibits
                        << "\nGot: " << channel.channelStorage);

    BOOST_CHECK_MESSAGE( ceil(channel.channelWidth) == 11193*drs::micrometer,
                        "Width of channel different from the expected."
                        << "\nExpected: " << 11193*drs::micrometer
                        << "\nGot: " << ceil(channel.channelWidth));

    BOOST_CHECK_MESSAGE( ceil(channel.channelHeight) == 4897*drs::micrometer,
                        "Height of channel different from the expected."
                        << "\nExpected: " << 4897*drs::micrometer
                        << "\nGot: " << ceil(channel.channelHeight));

    BOOST_CHECK_MESSAGE( ceil(channel.channelArea) == 55*drs::square_millimeter,
                        "Area of channel different from the expected."
                        << "\nExpected: " << 55*drs::square_millimeter
                        << "\nGot: " << ceil(channel.channelArea));

}

BOOST_AUTO_TEST_SUITE_END()

#endif // CHANNELTEST_CPP
