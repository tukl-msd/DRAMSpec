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

#ifndef SUBARRAY_CPP
#define SUBARRAY_CPP

#include <boost/test/included/unit_test.hpp>

#include "../core/SubArray.h"

BOOST_AUTO_TEST_SUITE( testSubArray )

BOOST_AUTO_TEST_CASE( checkInputSubArray_real_input)
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

    SubArray subarray(inputFileName.technologyFileName[0],
                      inputFileName.architectureFileName[0]);

    BOOST_CHECK_MESSAGE( subarray.subArrayWidth == 71.88*drs::micrometer_per_sa_row,
                        "Width of subarray different from the expected."
                        << "\nExpected: " << 71.88*drs::micrometer_per_sa_row
                        << "\nGot: " << subarray.subArrayWidth);

    BOOST_CHECK_MESSAGE( subarray.subArrayHeight == 94.32*drs::micrometer_per_sa_col,
                        "Height of subarray different from the expected."
                        << "\nExpected: " << 94.32*drs::micrometer_per_sa_col
                        << "\nGot: " << subarray.subArrayHeight);

    BOOST_CHECK_MESSAGE( subarray.GWLDriverResistance == 400*si::ohm,
                        "Resistance of global wordline driver different from the expected."
                        << "\nExpected: " << 400*si::ohm
                        << "\nGot: " << subarray.GWLDriverResistance);

    BOOST_CHECK_MESSAGE( subarray.LWLDriverResistance == 1000*drs::ohms_per_sa_row,
                        "Resistance of local wordline driver different from the expected."
                        << "\nExpected: " << 1000*drs::ohms_per_sa_row
                        << "\nGot: " << subarray.LWLDriverResistance);

    BOOST_CHECK_MESSAGE( subarray.WRResistance == 600*drs::ohms_per_sa_col,
                        "WR restore resistance different from the expected."
                        << "\nExpected: " << 600*drs::ohms_per_sa_col
                        << "\nGot: " << subarray.WRResistance);

}

BOOST_AUTO_TEST_CASE( checkInputSubArray_dummy_input )
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

    SubArray subarray(inputFileName.technologyFileName[0],
                      inputFileName.architectureFileName[0]);

    BOOST_CHECK_MESSAGE( subarray.subArrayWidth == 137*drs::micrometer_per_sa_row,
                        "Width of subarray different from the expected."
                        << "\nExpected: " << 1*drs::micrometer_per_sa_row
                        << "\nGot: " << subarray.subArrayWidth);

    BOOST_CHECK_MESSAGE( subarray.subArrayHeight == 154*drs::micrometer_per_sa_col,
                        "Height of subarray different from the expected."
                        << "\nExpected: " << 154*drs::micrometer_per_sa_col
                        << "\nGot: " << subarray.subArrayHeight);

    BOOST_CHECK_MESSAGE( subarray.GWLDriverResistance == -382*si::ohm,
                        "Resistance of global wordline driver different from the expected."
                        << "\nExpected: " << -382*si::ohm
                        << "\nGot: " << subarray.GWLDriverResistance);

    BOOST_CHECK_MESSAGE( subarray.LWLDriverResistance == 219*drs::ohms_per_sa_row,
                        "Resistance of local wordline driver different from the expected."
                        << "\nExpected: " << 219*drs::ohms_per_sa_row
                        << "\nGot: " << subarray.LWLDriverResistance);

    BOOST_CHECK_MESSAGE( subarray.WRResistance == 220*drs::ohms_per_sa_col,
                        "WR restore resistance different from the expected."
                        << "\nExpected: " << 220*drs::ohms_per_sa_col
                        << "\nGot: " << subarray.WRResistance);


}

BOOST_AUTO_TEST_CASE( checkInputSubArray_different_pageSizes )
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

    SubArray subarray(inputFileName.technologyFileName[0],
                      inputFileName.architectureFileName[0]);


    subarray.subArrayInit();
    subarray.pageSize = 1*drs::kibibyte;
    subarray.driversinit();
    BOOST_CHECK_MESSAGE( subarray.GWLDriverResistance == 218*si::ohm,
                        "Resistance of global wordline driver different from the expected."
                        << "\nExpected: " << 218*si::ohm
                        << "\nGot: " << subarray.GWLDriverResistance);

    subarray.subArrayInit();
    subarray.pageSize = 2*drs::kibibyte;
    subarray.driversinit();
    BOOST_CHECK_MESSAGE( subarray.GWLDriverResistance == 18*si::ohm,
                        "Resistance of global wordline driver different from the expected."
                        << "\nExpected: " << 18*si::ohm
                        << "\nGot: " << subarray.GWLDriverResistance);

    subarray.subArrayInit();
    subarray.pageSize = 4*drs::kibibyte;
    subarray.driversinit();
    BOOST_CHECK_MESSAGE( subarray.GWLDriverResistance == -182*si::ohm,
                        "Resistance of global wordline driver different from the expected."
                        << "\nExpected: " << -182*si::ohm
                        << "\nGot: " << subarray.GWLDriverResistance);

    subarray.subArrayInit();
    subarray.pageSize = 8*drs::kibibyte;
    subarray.driversinit();
    BOOST_CHECK_MESSAGE( subarray.GWLDriverResistance == -282*si::ohm,
                        "Resistance of global wordline driver different from the expected."
                        << "\nExpected: " << -282*si::ohm
                        << "\nGot: " << subarray.GWLDriverResistance);

    subarray.subArrayInit();
    subarray.pageSize = 16*drs::kibibyte;
    subarray.driversinit();
    BOOST_CHECK_MESSAGE( subarray.GWLDriverResistance == -382*si::ohm,
                        "Resistance of global wordline driver different from the expected."
                        << "\nExpected: " << -382*si::ohm
                        << "\nGot: " << subarray.GWLDriverResistance);

}

BOOST_AUTO_TEST_CASE( checkInputSubArray_different_bitPerLWL )
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

    SubArray subarray(inputFileName.technologyFileName[0],
                      inputFileName.architectureFileName[0]);


    subarray.subArrayInit();
    subarray.cellsPerLWL = (255+24)*drs::cell_per_sa_row;
    subarray.cellsPerLWLRedundancy = 24*drs::cell_per_sa_row;
    subarray.driversinit();
    BOOST_CHECK_MESSAGE( subarray.LWLDriverResistance == 219*drs::ohms_per_sa_row,
                        "Resistance of local wordline driver different from the expected."
                        << "\nExpected: " << 219*drs::ohms_per_sa_row
                        << "\nGot: " << subarray.LWLDriverResistance);

    BOOST_CHECK_MESSAGE( subarray.WRResistance == 220*drs::ohms_per_sa_col,
                        "WR restore resistance different from the expected."
                        << "\nExpected: " << 220*drs::ohms_per_sa_col
                        << "\nGot: " << subarray.WRResistance);


    subarray.subArrayInit();
    subarray.cellsPerLWL = (256+24)*drs::cell_per_sa_row;
    subarray.cellsPerLWLRedundancy = 24*drs::cell_per_sa_row;
    subarray.driversinit();
    BOOST_CHECK_MESSAGE( subarray.LWLDriverResistance == 119*drs::ohms_per_sa_row,
                        "Resistance of local wordline driver different from the expected."
                        << "\nExpected: " << 119*drs::ohms_per_sa_row
                        << "\nGot: " << subarray.LWLDriverResistance);

    BOOST_CHECK_MESSAGE( subarray.WRResistance == 120*drs::ohms_per_sa_col,
                        "WR restore resistance different from the expected."
                        << "\nExpected: " << 120*drs::ohms_per_sa_col
                        << "\nGot: " << subarray.WRResistance);


    subarray.subArrayInit();
    subarray.cellsPerLWL = (512+24)*drs::cell_per_sa_row;
    subarray.cellsPerLWLRedundancy = 24*drs::cell_per_sa_row;
    subarray.driversinit();
    BOOST_CHECK_MESSAGE( subarray.LWLDriverResistance == 19*drs::ohms_per_sa_row,
                        "Resistance of local wordline driver different from the expected."
                        << "\nExpected: " << 19*drs::ohms_per_sa_row
                        << "\nGot: " << subarray.LWLDriverResistance);

    BOOST_CHECK_MESSAGE( subarray.WRResistance == 20*drs::ohms_per_sa_col,
                        "WR restore resistance different from the expected."
                        << "\nExpected: " << 20*drs::ohms_per_sa_col
                        << "\nGot: " << subarray.WRResistance);


    subarray.subArrayInit();
    subarray.cellsPerLWL = (1024+24)*drs::cell_per_sa_row;
    subarray.cellsPerLWLRedundancy = 24*drs::cell_per_sa_row;
    subarray.driversinit();
    BOOST_CHECK_MESSAGE( subarray.LWLDriverResistance == -81*drs::ohms_per_sa_row,
                        "Resistance of local wordline driver different from the expected."
                        << "\nExpected: " << -81*drs::ohms_per_sa_row
                        << "\nGot: " << subarray.LWLDriverResistance);

    BOOST_CHECK_MESSAGE( subarray.WRResistance == -80*drs::ohms_per_sa_col,
                        "WR restore resistance different from the expected."
                        << "\nExpected: " << -80*drs::ohms_per_sa_col
                        << "\nGot: " << subarray.WRResistance);


    subarray.subArrayInit();
    subarray.cellsPerLWL = (1025+24)*drs::cell_per_sa_row;
    subarray.cellsPerLWLRedundancy = 24*drs::cell_per_sa_row;
    subarray.driversinit();
    BOOST_CHECK_MESSAGE( subarray.LWLDriverResistance == -181*drs::ohms_per_sa_row,
                        "Resistance of local wordline driver different from the expected."
                        << "\nExpected: " << -181*drs::ohms_per_sa_row
                        << "\nGot: " << subarray.LWLDriverResistance);

    BOOST_CHECK_MESSAGE( subarray.WRResistance == -180*drs::ohms_per_sa_col,
                        "WR restore resistance different from the expected."
                        << "\nExpected: " << -180*drs::ohms_per_sa_col
                        << "\nGot: " << subarray.WRResistance);

}

BOOST_AUTO_TEST_SUITE_END()

#endif
