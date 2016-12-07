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

#ifndef ARGUMENTSPARSERTEST_CPP
#define ARGUMENTSPARSERTEST_CPP

#include <boost/test/included/unit_test.hpp>

#include "../parser/ArgumentsParser.h"

BOOST_AUTO_TEST_SUITE( testArgumentsParser )

BOOST_AUTO_TEST_CASE( checkInputParametersParser_wrong_first_flag )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-r", // Instead of "-t", user types "-r". Should throw an error.
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

    string expectedMsg("Unexpected argument \'");
    expectedMsg.append("-r"); // Same flag error: "-r" instead of "-t".
    expectedMsg.append("\'.\nUse \'-t\' and \'-p\' before the ");
    expectedMsg.append("Technology and Archtecture file names, respectively.\n");
    expectedMsg.append("Use \'-term\' to include the");
    expectedMsg.append(" OI Termination Current calculation.\n");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

}

BOOST_AUTO_TEST_CASE( checkInputParametersParser_wrong_second_flag1 )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "../technology_input/techddr3_5x.json",
                        "-o", // Instead of "-p", user types "-o". Should throw an error.
                        "../architecture_input/parddr3.json"};

    ArgumentsParser inputFileName(sim_argc, sim_argv);

    string exceptionMsg("Empty");
    try {
        inputFileName.runArgParser();
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }

    string expectedMsg("Unexpected argument \'");
    expectedMsg.append("-o"); // Same flag error: "-o" instead of "-p".
    expectedMsg.append("\'.\nUse \'-t\' and \'-p\' before the ");
    expectedMsg.append("Technology and Archtecture file names, respectively.\n");
    expectedMsg.append("Use \'-term\' to include the");
    expectedMsg.append(" OI Termination Current calculation.\n");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

}

BOOST_AUTO_TEST_CASE( checkInputParametersParser_wrong_second_flag2 )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-p",
                        "../architecture_input/parddr3.json",
                        "-r", // Instead of "-t", user types "-r". Should throw an error.
                        "../technology_input/techddr3_5x.json"};

    ArgumentsParser inputFileName(sim_argc, sim_argv);

    string exceptionMsg("Empty");
    try {
        inputFileName.runArgParser();
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }

    string expectedMsg("Unexpected argument \'");
    expectedMsg.append("-r"); // Same flag error: "-r" instead of "-t".
    expectedMsg.append("\'.\nUse \'-t\' and \'-p\' before the ");
    expectedMsg.append("Technology and Archtecture file names, respectively.\n");
    expectedMsg.append("Use \'-term\' to include the");
    expectedMsg.append(" OI Termination Current calculation.\n");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

}

BOOST_AUTO_TEST_CASE( checkInputParametersParser_1tech_1arch )
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

    BOOST_CHECK_MESSAGE(inputFileName.technologyFileName[0]
                        == sim_argv[2],
                        "\nTechnology file name missmatch!\n"
                        << "\nExpected: " << sim_argv[2]
                        << "\nGot:" << inputFileName.technologyFileName[0]);

    BOOST_CHECK_MESSAGE(inputFileName.architectureFileName[0]
                        == sim_argv[4],
                        "\nArchitecture file name missmatch!"
                        << "\nExpected: " << sim_argv[4]
                        << "\nGot:" << inputFileName.architectureFileName[0]);

    BOOST_CHECK_MESSAGE(inputFileName.IOTerminationCurrentFlag == false,
                        "\nArchitecture file name missmatch!"
                        << "\nExpected: " << false
                        << "\nGot:" << inputFileName.IOTerminationCurrentFlag);

}

BOOST_AUTO_TEST_CASE( checkInputParametersParser_2tech_2arch )
{
    int sim_argc = 7;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "../technology_input/techddr3_5x.json",
                        "../technology_input/techhmc_5x.json",
                        "-p",
                        "../architecture_input/parddr3.json",
                        "../architecture_input/parhmc.json"};

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

    BOOST_CHECK_MESSAGE(inputFileName.technologyFileName[0]
                        == sim_argv[2],
                        "\nTechnology file name missmatch!"
                        << "\nExpected: " << sim_argv[2]
                        << "\nGot:" << inputFileName.technologyFileName[0]);

    BOOST_CHECK_MESSAGE(inputFileName.technologyFileName[1]
                        == sim_argv[3],
                        "\nTechnology file name missmatch!"
                        << "\nExpected: " << sim_argv[3]
                        << "\nGot:" << inputFileName.technologyFileName[1]);

    BOOST_CHECK_MESSAGE(inputFileName.architectureFileName[0]
                        == sim_argv[5],
                        "\nArchitecture file name missmatch!"
                        << "\nExpected: " << sim_argv[5]
                        << "\nGot:" << inputFileName.architectureFileName[0]);

    BOOST_CHECK_MESSAGE(inputFileName.architectureFileName[1]
                        == sim_argv[6],
                        "\nArchitecture file name missmatch!"
                        << "\nExpected: " << sim_argv[6]
                        << "\nGot:" << inputFileName.architectureFileName[1]);

    BOOST_CHECK_MESSAGE(inputFileName.IOTerminationCurrentFlag == false,
                        "\nArchitecture file name missmatch!"
                        << "\nExpected: " << false
                        << "\nGot:" << inputFileName.IOTerminationCurrentFlag);

}

BOOST_AUTO_TEST_CASE( checkInputParametersParser_2tech_2arch_mixed )
{
    int sim_argc = 9;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "../technology_input/techddr3_5x.json",
                        "-p",
                        "../architecture_input/parddr3.json",
                        "-t",
                        "../technology_input/techhmc_5x.json",
                        "-p",
                        "../architecture_input/parhmc.json"};

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

    BOOST_CHECK_MESSAGE(inputFileName.technologyFileName[0]
                        == sim_argv[2],
                        "\nTechnology file name missmatch!"
                        << "\nExpected: " << sim_argv[2]
                        << "\nGot:" << inputFileName.technologyFileName[0]);

    BOOST_CHECK_MESSAGE(inputFileName.architectureFileName[0]
                        == sim_argv[4],
                        "\nArchitecture file name missmatch!"
                        << "\nExpected: " << sim_argv[4]
                        << "\nGot:" << inputFileName.architectureFileName[0]);

    BOOST_CHECK_MESSAGE(inputFileName.technologyFileName[1]
                        == sim_argv[6],
                        "\nTechnology file name missmatch!"
                        << "\nExpected: " << sim_argv[6]
                        << "\nGot:" << inputFileName.technologyFileName[1]);

    BOOST_CHECK_MESSAGE(inputFileName.architectureFileName[1]
                        == sim_argv[8],
                        "\nArchitecture file name missmatch!"
                        << "\nExpected: " << sim_argv[8]
                        << "\nGot:" << inputFileName.architectureFileName[1]);

    BOOST_CHECK_MESSAGE(inputFileName.IOTerminationCurrentFlag == false,
                        "\nArchitecture file name missmatch!"
                        << "\nExpected: " << false
                        << "\nGot:" << inputFileName.IOTerminationCurrentFlag);

}

BOOST_AUTO_TEST_CASE( checkInputParametersParser_2tech_2arch_term_mixed )
{
    int sim_argc = 10;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "../technology_input/techddr3_5x.json",
                        "-p",
                        "../architecture_input/parddr3.json",
                        "-term",
                        "-t",
                        "../technology_input/techhmc_5x.json",
                        "-p",
                        "../architecture_input/parhmc.json"};

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

    BOOST_CHECK_MESSAGE(inputFileName.technologyFileName[0]
                        == sim_argv[2],
                        "\nTechnology file name missmatch!"
                        << "\nExpected: " << sim_argv[2]
                        << "\nGot:" << inputFileName.technologyFileName[0]);

    BOOST_CHECK_MESSAGE(inputFileName.architectureFileName[0]
                        == sim_argv[4],
                        "\nArchitecture file name missmatch!"
                        << "\nExpected: " << sim_argv[4]
                        << "\nGot:" << inputFileName.architectureFileName[0]);

    BOOST_CHECK_MESSAGE(inputFileName.technologyFileName[1]
                        == sim_argv[7],
                        "\nTechnology file name missmatch!"
                        << "\nExpected: " << sim_argv[7]
                        << "\nGot:" << inputFileName.technologyFileName[1]);

    BOOST_CHECK_MESSAGE(inputFileName.architectureFileName[1]
                        == sim_argv[9],
                        "\nArchitecture file name missmatch!"
                        << "\nExpected: " << sim_argv[9]
                        << "\nGot:" << inputFileName.architectureFileName[1]);

    BOOST_CHECK_MESSAGE(inputFileName.IOTerminationCurrentFlag == true,
                        "\nArchitecture file name missmatch!"
                        << "\nExpected: " << true
                        << "\nGot:" << inputFileName.IOTerminationCurrentFlag);
}

BOOST_AUTO_TEST_CASE( checkInputParametersParser_different_number )
{
    int sim_argc = 11;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "../technology_input/techddr3_5x.json",
                        "-p",
                        "../architecture_input/parddr3.json",
                        "-term",
                        "-t",
                        "../technology_input/techhmc_5x.json",
                        "-p",
                        "../architecture_input/parhmc.json",
                        "../architecture_input/parddr4.json"};

    ArgumentsParser inputFileName(sim_argc, sim_argv);

    string exceptionMsg("Empty");
    try {
        inputFileName.runArgParser();
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }

    string expectedMsg("Number of technology files (");
    expectedMsg.append("2");
    expectedMsg.append(") is different from ");
    expectedMsg.append("the number of archtecture files (");
    expectedMsg.append("3");
    expectedMsg.append("). Could not proceed.");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

}

BOOST_AUTO_TEST_SUITE_END()

#endif
