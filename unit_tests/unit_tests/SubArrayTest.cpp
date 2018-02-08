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



#ifndef SUBARRAYTEST_CPP
#define SUBARRAYTEST_CPP

#include <boost/test/included/unit_test.hpp>

#include "../../core/SubArray.h"

BOOST_AUTO_TEST_SUITE( testSubArray )

BOOST_AUTO_TEST_CASE( checkSubArray_real_input)
{

    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "technology_input/test_technology.json",
                        "-p",
                        "architecture_input/test_architecture.json"};

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

    SubArray subarray;

    try {
        subarray = SubArray(inputFileName.technologyFileName[0],
                            inputFileName.architectureFileName[0]);
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    expectedMsg = string("Empty");
    if ( exceptionMsg != expectedMsg ) {
        BOOST_FAIL( exceptionMsg );
    }


    BOOST_CHECK_MESSAGE( subarray.subArrayStorage == 262144*drs::bits,
                         "Size of subarray different from the expected."
                        << "\nExpected: " << 262144*drs::bits
                        << "\nGot: " << subarray.subArrayStorage);

    BOOST_CHECK_MESSAGE( subarray.subArrayRowStorage == 512*drs::bits,
                        "Size of subarray row different from the expected."
                        << "\nExpected: " << 512*drs::bits
                        << "\nGot: " << subarray.subArrayRowStorage);

    BOOST_CHECK_MESSAGE( subarray.subArrayColumnStorage == 512*drs::bits,
                         "Size of subarray column different from the expected."
                        << "\nExpected: " << 512*drs::bits
                        << "\nGot: " << subarray.subArrayColumnStorage);

    BOOST_CHECK_MESSAGE( subarray.subArrayWidth == 71.88*drs::micrometer,
                        "Width of subarray different from the expected."
                        << "\nExpected: " << 71.88*drs::micrometer
                        << "\nGot: " << subarray.subArrayWidth);

    BOOST_CHECK_MESSAGE( subarray.subArrayHeight == 114.32*drs::micrometer,
                        "Height of subarray different from the expected."
                        << "\nExpected: " << 114.32*drs::micrometer
                        << "\nGot: " << subarray.subArrayHeight);

    BOOST_CHECK_MESSAGE( subarray.GWLDriverResistance == 400*drs::ohms,
                        "Resistance of global wordline driver different from the expected."
                        << "\nExpected: " << 400*drs::ohms
                        << "\nGot: " << subarray.GWLDriverResistance);

    BOOST_CHECK_MESSAGE( subarray.LWLDriverResistance == 1000*drs::ohms,
                        "Resistance of local wordline driver different from the expected."
                        << "\nExpected: " << 1000*drs::ohms
                        << "\nGot: " << subarray.LWLDriverResistance);

    BOOST_CHECK_MESSAGE( subarray.WRDriverResistance == 600*drs::ohms,
                        "WR restore driver resistance different from the expected."
                        << "\nExpected: " << 600*drs::ohms
                        << "\nGot: " << subarray.WRDriverResistance);

}

BOOST_AUTO_TEST_CASE( checkSubArray_dummy_input )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "technology_input/tech_dummy_input.json",
                        "-p",
                        "architecture_input/arch_dummy_input.json"};

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

    SubArray subarray;

    try {
        subarray = SubArray(inputFileName.technologyFileName[0],
                            inputFileName.architectureFileName[0]);
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    expectedMsg = string("Empty");
    if ( exceptionMsg != expectedMsg ) {
        BOOST_FAIL( exceptionMsg );
    }


    BOOST_CHECK_MESSAGE( subarray.subArrayStorage == 11229034*drs::bits,
                         "Size of subarray different from the expected."
                        << "\nExpected: " << 11229034*drs::bits
                        << "\nGot: " << subarray.subArrayStorage);

    BOOST_CHECK_MESSAGE( subarray.subArrayRowStorage == -2258*drs::bits,
                        "Size of subarray row different from the expected."
                        << "\nExpected: " << -2258*drs::bits
                        << "\nGot: " << subarray.subArrayRowStorage);

    BOOST_CHECK_MESSAGE( subarray.subArrayColumnStorage == -4973*drs::bits,
                         "Size of subarray column different from the expected."
                        << "\nExpected: " << -4973*drs::bits
                        << "\nGot: " << subarray.subArrayColumnStorage);

    BOOST_CHECK_MESSAGE( subarray.subArrayWidth == 5901281*drs::micrometer,
                        "Width of subarray different from the expected."
                        << "\nExpected: " << 5901281*drs::micrometer
                        << "\nGot: " << subarray.subArrayWidth);

    BOOST_CHECK_MESSAGE( subarray.subArrayHeight == 2606889*drs::micrometer,
                        "Height of subarray different from the expected."
                        << "\nExpected: " << 2606889*drs::micrometer
                        << "\nGot: " << subarray.subArrayHeight);

    BOOST_CHECK_MESSAGE( subarray.GWLDriverResistance == 4005*drs::ohms,
                        "Resistance of global wordline driver different from the expected."
                        << "\nExpected: " << 4005*drs::ohms
                        << "\nGot: " << subarray.GWLDriverResistance);

    BOOST_CHECK_MESSAGE( subarray.LWLDriverResistance == 5422*drs::ohms,
                        "Resistance of local wordline driver different from the expected."
                        << "\nExpected: " << 5422*drs::ohms
                        << "\nGot: " << subarray.LWLDriverResistance);

    BOOST_CHECK_MESSAGE( subarray.WRDriverResistance == 6131*drs::ohms,
                        "WR restore driver resistance different from the expected."
                        << "\nExpected: " << 6131*drs::ohms
                        << "\nGot: " << subarray.WRDriverResistance);


}

BOOST_AUTO_TEST_CASE( checkSubArray_different_pageStorages )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "technology_input/tech_dummy_input.json",
                        "-p",
                        "architecture_input/arch_dummy_input.json"};

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

    SubArray subarray;

    try {
        subarray = SubArray(inputFileName.technologyFileName[0],
                            inputFileName.architectureFileName[0]);
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    expectedMsg = string("Empty");
    if ( exceptionMsg != expectedMsg ) {
        BOOST_FAIL( exceptionMsg );
    }


    subarray.readjson(inputFileName.technologyFileName[0],
                      inputFileName.architectureFileName[0]);
    subarray.subArrayCompute();
    subarray.pageStorage = 1*drs::kibibytes;
    subarray. driverUpdate();
    BOOST_CHECK_MESSAGE( subarray.GWLDriverResistance == 4605*drs::ohms,
                        "Resistance of global wordline driver different from the expected."
                        << "\nExpected: " << 4605*drs::ohms
                        << "\nGot: " << subarray.GWLDriverResistance);

    subarray.readjson(inputFileName.technologyFileName[0],
                      inputFileName.architectureFileName[0]);
    subarray.subArrayCompute();
    subarray.pageStorage = 2*drs::kibibytes;
    subarray. driverUpdate();
    BOOST_CHECK_MESSAGE( subarray.GWLDriverResistance == 4405*drs::ohms,
                        "Resistance of global wordline driver different from the expected."
                        << "\nExpected: " << 4405*drs::ohms
                        << "\nGot: " << subarray.GWLDriverResistance);

    subarray.readjson(inputFileName.technologyFileName[0],
                      inputFileName.architectureFileName[0]);
    subarray.subArrayCompute();
    subarray.pageStorage = 4*drs::kibibytes;
    subarray. driverUpdate();
    BOOST_CHECK_MESSAGE( subarray.GWLDriverResistance == 4205*drs::ohms,
                        "Resistance of global wordline driver different from the expected."
                        << "\nExpected: " << 4205*drs::ohms
                        << "\nGot: " << subarray.GWLDriverResistance);

    subarray.readjson(inputFileName.technologyFileName[0],
                      inputFileName.architectureFileName[0]);
    subarray.subArrayCompute();
    subarray.pageStorage = 8*drs::kibibytes;
    subarray. driverUpdate();
    BOOST_CHECK_MESSAGE( subarray.GWLDriverResistance == 4105*drs::ohms,
                        "Resistance of global wordline driver different from the expected."
                        << "\nExpected: " << 4105*drs::ohms
                        << "\nGot: " << subarray.GWLDriverResistance);

    subarray.readjson(inputFileName.technologyFileName[0],
                      inputFileName.architectureFileName[0]);
    subarray.subArrayCompute();
    subarray.pageStorage = 16*drs::kibibytes;
    subarray. driverUpdate();
    BOOST_CHECK_MESSAGE( subarray.GWLDriverResistance == 4005*drs::ohms,
                        "Resistance of global wordline driver different from the expected."
                        << "\nExpected: " << 4005*drs::ohms
                        << "\nGot: " << subarray.GWLDriverResistance);

}

BOOST_AUTO_TEST_CASE( checkSubArray_different_bitPerLWL )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "technology_input/tech_dummy_input.json",
                        "-p",
                        "architecture_input/arch_dummy_input.json"};

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

    SubArray subarray;

    try {
        subarray = SubArray(inputFileName.technologyFileName[0],
                            inputFileName.architectureFileName[0]);
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    expectedMsg = string("Empty");
    if ( exceptionMsg != expectedMsg ) {
        BOOST_FAIL( exceptionMsg );
    }


    subarray.readjson(inputFileName.technologyFileName[0],
                      inputFileName.architectureFileName[0]);
    subarray.subArrayCompute();
    subarray.subArrayRowStorage = 255*drs::bits; // < 256
    subarray. driverUpdate();
    BOOST_CHECK_MESSAGE( subarray.LWLDriverResistance == 5422*drs::ohms,
                        "Resistance of local wordline driver different from the expected."
                        << "\nExpected: " << 5422*drs::ohms
                        << "\nGot: " << subarray.LWLDriverResistance);

    BOOST_CHECK_MESSAGE( subarray.WRDriverResistance == 6131*drs::ohms,
                        "WR restore driver resistance different from the expected."
                        << "\nExpected: " << 6131*drs::ohms
                        << "\nGot: " << subarray.WRDriverResistance);


    subarray.readjson(inputFileName.technologyFileName[0],
                      inputFileName.architectureFileName[0]);
    subarray.subArrayCompute();
    subarray.subArrayRowStorage = 256*drs::bits;
    subarray. driverUpdate();
    BOOST_CHECK_MESSAGE( subarray.LWLDriverResistance == 5322*drs::ohms,
                        "Resistance of local wordline driver different from the expected."
                        << "\nExpected: " << 5322*drs::ohms
                        << "\nGot: " << subarray.LWLDriverResistance);

    BOOST_CHECK_MESSAGE( subarray.WRDriverResistance == 6031*drs::ohms,
                        "WR restore driver resistance different from the expected."
                        << "\nExpected: " << 6031*drs::ohms
                        << "\nGot: " << subarray.WRDriverResistance);


    subarray.readjson(inputFileName.technologyFileName[0],
                      inputFileName.architectureFileName[0]);
    subarray.subArrayCompute();
    subarray.subArrayRowStorage = 512*drs::bits;
    subarray. driverUpdate();
    BOOST_CHECK_MESSAGE( subarray.LWLDriverResistance == 5222*drs::ohms,
                        "Resistance of local wordline driver different from the expected."
                        << "\nExpected: " << 5222*drs::ohms
                        << "\nGot: " << subarray.LWLDriverResistance);

    BOOST_CHECK_MESSAGE( subarray.WRDriverResistance == 5931*drs::ohms,
                        "WR restore driver resistance different from the expected."
                        << "\nExpected: " << 5931*drs::ohms
                        << "\nGot: " << subarray.WRDriverResistance);


    subarray.readjson(inputFileName.technologyFileName[0],
                      inputFileName.architectureFileName[0]);
    subarray.subArrayCompute();
    subarray.subArrayRowStorage = 1024*drs::bits;
    subarray. driverUpdate();
    BOOST_CHECK_MESSAGE( subarray.LWLDriverResistance == 5122*drs::ohms,
                        "Resistance of local wordline driver different from the expected."
                        << "\nExpected: " << 5122*drs::ohms
                        << "\nGot: " << subarray.LWLDriverResistance);

    BOOST_CHECK_MESSAGE( subarray.WRDriverResistance == 5831*drs::ohms,
                        "WR restore driver resistance different from the expected."
                        << "\nExpected: " << 5831*drs::ohms
                        << "\nGot: " << subarray.WRDriverResistance);


    subarray.readjson(inputFileName.technologyFileName[0],
                      inputFileName.architectureFileName[0]);
    subarray.subArrayCompute();
    subarray.subArrayRowStorage = 1025*drs::bits; // > 1024
    subarray. driverUpdate();
    BOOST_CHECK_MESSAGE( subarray.LWLDriverResistance == 5022*drs::ohms,
                        "Resistance of local wordline driver different from the expected."
                        << "\nExpected: " << 5022*drs::ohms
                        << "\nGot: " << subarray.LWLDriverResistance);

    BOOST_CHECK_MESSAGE( subarray.WRDriverResistance == 5731*drs::ohms,
                        "WR restore driver resistance different from the expected."
                        << "\nExpected: " << 5731*drs::ohms
                        << "\nGot: " << subarray.WRDriverResistance);

}

BOOST_AUTO_TEST_SUITE_END()

#endif // SUBARRAYTEST_CPP
