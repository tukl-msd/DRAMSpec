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



#ifndef CURRENTTEST_CPP
#define CURRENTTEST_CPP

#include <boost/test/included/unit_test.hpp>

#include "../../core/Current.h"

BOOST_AUTO_TEST_SUITE( testCurrent )

BOOST_AUTO_TEST_CASE( checkCurrent_real_input )
{
    int sim_argc = 6;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "../../technology_input/test_technology.json",
                        "-p",
                        "../../architecture_input/test_architecture.json",
                        "-term"};

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

    Current current;
    try {
        current = Current(inputFileName.technologyFileName[0],
                          inputFileName.architectureFileName[0],
                          inputFileName.IOTerminationCurrentFlag);
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    expectedMsg = string("Empty");
    if ( exceptionMsg != expectedMsg ) {
        BOOST_FAIL( exceptionMsg );
    }


    // !! Hard-coded values converted to variables !!
    BOOST_CHECK_MESSAGE( current.IDD2nPercentageIfNotDll == 0.6,
                        "Accounted percentage of IDD2n if not DLL different from the expected."
                        << "\nExpected around: " << 0.6
                        << "\nGot: " << current.IDD2nPercentageIfNotDll);

    BOOST_CHECK_MESSAGE( current.vppPumpsEfficiency == 0.3,
                        "Efficiency of VPP pumps different from the expected."
                        << "\nExpected around: " << 0.3
                        << "\nGot: " << current.vppPumpsEfficiency);

    // !!! TODO: Trouble printing out this value! !!!
//    BOOST_CHECK_MESSAGE( current.currentPerPageSizeSlope == 2.0*drs::milliamperes_page_per_kibibyte,
//                        "IDD2n current slope on page size different from the expected."
//                        << "\nExpected around: " << 2.0*drs::milliamperes_page_per_kibibyte
//                        << "\nGot: " << current.currentPerPageSizeSlope);

    BOOST_CHECK_MESSAGE( current.SSAActiveTime == 1.5*drs::nanoseconds,
                        "Active time of secondary sense amp. different from the expected."
                        << "\nExpected around: " << 1.5*drs::nanoseconds
                        << "\nGot: " << current.SSAActiveTime);

    BOOST_CHECK_MESSAGE( current.bitProCSL == 8*drs::bits,
                        "Number of bits pro CSL different fgrom the expected."
                        << "\nExpected around: " << 8*drs::bits
                        << "\nGot: " << current.bitProCSL);

    BOOST_CHECK_MESSAGE( current.IddOcdRcvSlope == 5.629*drs::microampere_per_megahertz_clock,
                        "IddOcdRcvScalingFactor different from the expected."
                        << "\nExpected around: " << 5.629*drs::microampere_per_megahertz_clock
                        << "\nGot: " << current.IddOcdRcvSlope);

    BOOST_CHECK_MESSAGE( ROUND_UP(current.nActiveSubarrays, 3) == 32,
                        "Number of active subarrays different from the expected."
                        << "\nExpected around: " << 32
                        << "\nGot: " << current.nActiveSubarrays);

    BOOST_CHECK_MESSAGE( ROUND_UP(current.nLocalBitlines, 3) == 16384,
                        "Number of local bitlines different from the expected."
                        << "\nExpected around: " << 16384
                        << "\nGot: " << current.nLocalBitlines);

    BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD0TotalCharge, 3) == 1.613*drs::nanocoulombs,
                        "Total charge accounted for IDD0 different from the expected."
                        << "\nExpected around: " << 1.613*drs::nanocoulombs
                        << "\nGot: " << current.IDD0TotalCharge);

    BOOST_CHECK_MESSAGE( ROUND_UP(current.effectiveTrc, 3) == 30*drs::nanoseconds,
                        "Effective Trc different from the expected."
                        << "\nExpected around: " << 30*drs::nanoseconds
                        << "\nGot: " << current.effectiveTrc);

    BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD0ChargingCurrent, 3) == 0.054*si::amperes,
                        "Part of IDD0 for charging lines different from the expected."
                        << "\nExpected around: " << 0.054*si::amperes
                        << "\nGot: " << current.IDD0ChargingCurrent);

    BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD1TotalCharge, 3) == 3.219*drs::nanocoulombs,
                        "Total charge accounted for IDD1 different from the expected."
                        << "\nExpected around: " << 3.219*drs::nanocoulombs
                        << "\nGot: " << current.IDD1TotalCharge);

    BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD1ChargingCurrent, 3) == 0.108*si::amperes,
                        "Part of IDD1 for charging lines different from the expected."
                        << "\nExpected around: " << 0.108*si::amperes
                        << "\nGot: " << current.IDD1ChargingCurrent);

    BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD4TotalCharge, 3) == 0.838*drs::nanocoulombs,
                        "Total charge accounted for IDD4 different from the expected."
                        << "\nExpected around: " << 0.838*drs::nanocoulombs
                        << "\nGot: " << current.IDD4TotalCharge);

    BOOST_CHECK_MESSAGE( ROUND_UP(current.ioTermRdCurrent, 3) == 90.064*drs::milliampere,
                        "I/O Termination current for reading different from the expected."
                        << "\nExpected around: " << 90.064*drs::milliampere
                        << "\nGot: " << current.ioTermRdCurrent);

    BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD4ChargingCurrent, 3) == 0.168*si::amperes,
                        "Part of IDD4 for charging lines different from the expected."
                        << "\nExpected around: " << 0.168*si::amperes
                        << "\nGot: " << current.IDD4ChargingCurrent);

    BOOST_CHECK_MESSAGE( ROUND_UP(current.ioTermWrCurrent, 3) == 9.007*drs::milliampere,
                        "I/O Termination current for writing different from the expected."
                        << "\nExpected around: " << 9.007*drs::milliampere
                        << "\nGot: " << current.ioTermWrCurrent);

    BOOST_CHECK_MESSAGE( ROUND_UP(current.refreshCharge, 3) == 12.901*drs::nanocoulombs,
                        "Total charge accounted refreshing different from the expected."
                        << "\nExpected around: " << 12.901*drs::nanocoulombs
                        << "\nGot: " << current.refreshCharge);

    BOOST_CHECK_MESSAGE( ROUND_UP(current.effectiveTrfc, 3) == 45*drs::nanoseconds,
                        "Effective Trfc different from the expected."
                        << "\nExpected around: " << 45*drs::nanoseconds
                        << "\nGot: " << current.effectiveTrfc);

    BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD5ChargingCurrent, 3) == 0.287*si::amperes,
                        "Part of IDD5 for charging lines different from the expected."
                        << "\nExpected around: " << 0.287*si::amperes
                        << "\nGot: " << current.IDD5ChargingCurrent);

    // Main variables
    BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD0, 3) == 92.754*drs::milliampere,
                        "IDD0 different from the expected."
                        << "\nExpected around: " << 92.754*drs::milliampere
                        << "\nGot: " << current.IDD0);

    BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD1, 3) == 146.276*drs::milliampere,
                        "IDD1 different from the expected."
                        << "\nExpected around: " << 146.276*drs::milliampere
                        << "\nGot: " << current.IDD1);

    BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD4R, 3) == 296.621*drs::milliampere,
                        "IDD4R different from the expected."
                        << "\nExpected around: " << 296.621*drs::milliampere
                        << "\nGot: " << current.IDD4R);

    BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD4W, 3) == 305.627*drs::milliampere,
                        "IDD4W different from the expected."
                        << "\nExpected around: " << 305.627*drs::milliampere
                        << "\nGot: " << current.IDD4W);

    BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD2n, 3) == 37*drs::milliampere,
                        "IDD2n different from the expected."
                        << "\nExpected around: " << 37*drs::milliampere
                        << "\nGot: " << current.IDD2n);

    BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD3n, 3) == 39*drs::milliampere,
                        "IDD3n different from the expected."
                        << "\nExpected around: " << 39*drs::milliampere
                        << "\nGot: " << current.IDD3n);

    BOOST_CHECK_MESSAGE( ROUND_UP(current.IDD5, 3) == 325.687*drs::milliampere,
                        "IDD5 different from the expected."
                        << "\nExpected around: " << 325.687*drs::milliampere
                        << "\nGot: " << current.IDD5);

    BOOST_CHECK_MESSAGE( ROUND_UP(current.masterWordlineCharge, 6) == 0.004133*drs::nanocoulombs,
                        "Charge accounted for master word line different from the expected."
                        << "\nExpected around: " << 0.004133*drs::nanocoulombs
                        << "\nGot: " << current.masterWordlineCharge);

    BOOST_CHECK_MESSAGE( ROUND_UP(current.localWordlineCharge, 3) == 0.024*drs::nanocoulombs,
                        "Charge accounted for local word line different from the expected."
                        << "\nExpected around: " << 0.024*drs::nanocoulombs
                        << "\nGot: " << current.localWordlineCharge);

    BOOST_CHECK_MESSAGE( ROUND_UP(current.localBitlineCharge, 3) == 0.756*drs::nanocoulombs,
                        "Charge accounted for local bit line different from the expected."
                        << "\nExpected around: " << 0.756*drs::nanocoulombs
                        << "\nGot: " << current.localBitlineCharge);

    BOOST_CHECK_MESSAGE( ROUND_UP(current.SSACharge, 3) == 0.058*drs::nanocoulombs,
                        "Charge accounted for secondary sense amp. different from the expected."
                        << "\nExpected around: " << 0.058*drs::nanocoulombs
                        << "\nGot: " << current.SSACharge);

    BOOST_CHECK_MESSAGE( ROUND_UP(current.CSLCharge, 3) == 0.034*drs::nanocoulombs,
                        "Charge accounted for column select line different from the expected."
                        << "\nExpected around: " << 0.034*drs::nanocoulombs
                        << "\nGot: " << current.CSLCharge);

    BOOST_CHECK_MESSAGE( ROUND_UP(current.masterDatalineCharge, 3) == 0.125*drs::nanocoulombs,
                        "Charge accounted for master data line different from the expected."
                        << "\nExpected around: " << 0.125*drs::nanocoulombs
                        << "\nGot: " << current.masterDatalineCharge);

    BOOST_CHECK_MESSAGE( ROUND_UP(current.DQWireCharge, 3) == 0.452*drs::nanocoulombs,
                        "Charge accounted for dataqueue wire different from the expected."
                        << "\nExpected around: " << 0.452*drs::nanocoulombs
                        << "\nGot: " << current.DQWireCharge);

    BOOST_CHECK_MESSAGE( ROUND_UP(current.readingCharge, 3) == 0.827*drs::nanocoulombs,
                        "Total charge accounted for reading lines different from the expected."
                        << "\nExpected around: " << 0.827*drs::nanocoulombs
                        << "\nGot: " << current.readingCharge);

    BOOST_CHECK_MESSAGE( current.includeIOTerminationCurrent == true,
                        "I/O termination current flag different from the expected."
                        << "\nExpected: " << true
                        << "\nGot: " << current.includeIOTerminationCurrent);

}

BOOST_AUTO_TEST_SUITE_END()

#endif // CURRENTTEST_CPP
