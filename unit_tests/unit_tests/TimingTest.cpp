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



#ifndef TIMINGTEST_CPP
#define TIMINGTEST_CPP

#include <boost/test/included/unit_test.hpp>

#include "../../core/Timing.h"

BOOST_AUTO_TEST_SUITE( testTiming )

BOOST_AUTO_TEST_CASE( checkTiming_real_input )
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

    Timing timing;
    try {
        timing = Timing(inputFileName.technologyFileName[0],
                    inputFileName.architectureFileName[0]);
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    expectedMsg = string("Empty");
    if ( exceptionMsg != expectedMsg ) {
        BOOST_FAIL( exceptionMsg );
    }


    BOOST_CHECK_MESSAGE( ROUND_UP(timing.cellDelay, 3) == 0.922*drs::nanoseconds,
                        "Delay inside cell different from the expected."
                        << "\nExpected around: " << 0.922*drs::nanoseconds
                        << "\nGot: " << timing.cellDelay);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.localWordlineResistance, 3) == 25104*drs::ohms_per_subarray,
                        "Resistance of local wordline different from the expected."
                        << "\nExpected around: " << 25104*drs::ohms_per_subarray
                        << "\nGot: " << timing.localWordlineResistance);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.localWordlineCapacitance, 9) == 7.8601e-05*drs::nanofarads_per_subarray,
                        "Capacitance of local wordline different from the expected."
                        << "\nExpected around: " << 7.8601e-05*drs::nanofarads_per_subarray
                        << "\nGot: " << timing.localWordlineCapacitance);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.localWordlineDelay, 3) == 4.544*drs::nanoseconds,
                        "Delay through local wordline different from the expected."
                        << "\nExpected around: " << 4.544*drs::nanoseconds
                        << "\nGot: " << timing.localWordlineDelay);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.localBitlineResistance, 3) == 18864*drs::ohms_per_subarray,
                        "Bitline resistance different from the expected."
                        << "\nExpected around: " << 18864*drs::ohms_per_subarray
                        << "\nGot: " << timing.localBitlineResistance);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.localBitlineCapacitance, 9) == 8.384e-05*drs::nanofarads_per_subarray,
                        "Bitline capacitance different from the expected."
                        << "\nExpected around: " << 8.384e-05*drs::nanofarads_per_subarray
                        << "\nGot: " << timing.localBitlineCapacitance);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.localBitlineDelay, 3) == 3.642*drs::nanoseconds,
                        "Delay through bitline different from the expected."
                        << "\nExpected around: " << 3.642*drs::nanoseconds
                        << "\nGot: " << timing.localBitlineDelay);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.globalWordlineResistance, 3) == 139.908*drs::ohms_per_tile,
                        "Resistance of global wordline different from the expected."
                        << "\nExpected around: " << 139.908*drs::ohms_per_tile
                        << "\nGot: " << timing.globalWordlineResistance);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.globalWordlineCapacitance, 6) == 5.35e-4*drs::nanofarads_per_tile,
                        "Capacitance of global wordline different from the expected."
                        << "\nExpected around: " << 5.35e-4*drs::nanofarads_per_tile
                        << "\nGot: " << timing.globalWordlineCapacitance);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.globalWordlineDelay, 3) == 1.167*drs::nanoseconds,
                        "Delay through global wordline different from the expected."
                        << "\nExpected around: " << 1.167*drs::nanoseconds
                        << "\nGot: " << timing.globalWordlineDelay);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trcd, 3) == 10.273*drs::nanoseconds,
                        "trcd different from the expected."
                        << "\nExpected around: " << 10.273*drs::nanoseconds
                        << "\nGot: " << timing.trcd);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tcsl, 3) == 2.080*drs::nanoseconds,
                        "tcsl different from the expected."
                        << "\nExpected around: " << 2.080*drs::nanoseconds
                        << "\nGot: " << timing.tcsl);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.globalDatalineResistance, 3) == 237.344*drs::ohms_per_bank,
                        "Resistance of global dataline different from the expected."
                        << "\nExpected around: " << 237.344*drs::ohms_per_bank
                        << "\nGot: " << timing.globalDatalineResistance);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.globalDatalineCapacitance, 6) == 9.07e-4*drs::nanofarads_per_bank,
                        "Capacitance of global dataline different from the expected."
                        << "\nExpected around: " << 9.07e-4*drs::nanofarads_per_bank
                        << "\nGot: " << timing.globalDatalineCapacitance);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tgdl, 3) == 2.067*drs::nanoseconds,
                        "tgdl different from the expected."
                        << "\nExpected around: " << 2.067*drs::nanoseconds
                        << "\nGot: " << timing.tgdl);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.DQWireLength, 3) == 8394.48*drs::micrometers,
                        "Length of bank to DQ wire different from the expected."
                        << "\nExpected around: " << 8394.48*drs::micrometers
                        << "\nGot: " << timing.DQWireLength);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.DQWireResistance, 3) == 839.448*si::ohms,
                        "Resistance of bank to DQ wire different from the expected."
                        << "\nExpected around: " << 839.448*si::ohms
                        << "\nGot: " << timing.DQWireResistance);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.DQWireCapacitance, 6) == 3.207e-3*drs::nanofarads,
                        "Capacitance of bank do DQ wire different from the expected."
                        << "\nExpected around: " << 3.207e-3*drs::nanofarads
                        << "\nGot: " << timing.DQWireCapacitance);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tdq, 3) == 6.969*drs::nanoseconds,
                        "tdq different from the expected."
                        << "\nExpected around: " << 6.969*drs::nanoseconds
                        << "\nGot: " << timing.tdq);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tcas, 3) == 17.115*drs::nanoseconds,
                        "tcas different from the expected."
                        << "\nExpected around: " << 17.115*drs::nanoseconds
                        << "\nGot: " << timing.tcas);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trl, 3) == 18.365*drs::nanoseconds,
                        "trl different from the expected."
                        << "\nExpected around: " << 18.365*drs::nanoseconds
                        << "\nGot: " << timing.trl);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trtp, 3) == 6.147*drs::nanoseconds,
                        "trtp different from the expected."
                        << "\nExpected around: " << 6.147*drs::nanoseconds
                        << "\nGot: " << timing.trtp);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tccd, 3) == 4.547*drs::nanoseconds,
                        "tccd different from the expected."
                        << "\nExpected around: " << 4.547*drs::nanoseconds
                        << "\nGot: " << timing.tccd);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tras, 3) == 20.965*drs::nanoseconds,
                        "tras different from the expected."
                        << "\nExpected around: " << 20.965*drs::nanoseconds
                        << "\nGot: " << timing.tras);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.twr, 3) == 8.709*drs::nanoseconds,
                        "twr different from the expected."
                        << "\nExpected around: " << 8.709*drs::nanoseconds
                        << "\nGot: " << timing.twr);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trp, 3) == 9.186*drs::nanoseconds,
                        "trp different from the expected."
                        << "\nExpected around: " << 9.186*drs::nanoseconds
                        << "\nGot: " << timing.trp);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trc, 3) == 30.150*drs::nanoseconds,
                        "trc different from the expected."
                        << "\nExpected around: " << 30.150*drs::nanoseconds
                        << "\nGot: " << timing.trc);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trfc, 3) == 44.021*drs::nanoseconds,
                        "trfc different from the expected."
                        << "\nExpected around: " << 44.021*drs::nanoseconds
                        << "\nGot: " << timing.trfc);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trefI, 2) == 7812.5*drs::nanoseconds,
                        "trefI different from the expected."
                        << "\nExpected around: " << 7812.5*drs::nanoseconds
                        << "\nGot: " << timing.trefI);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.maxCoreFreq, 3) == 219.973*drs::megahertz_clock,
                        "Maximum core frequency different from the expected."
                        << "\nExpected around: " << 219.973*drs::megahertz_clock
                        << "\nGot: " << timing.maxCoreFreq);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.clockFactor, 3) == 4,
                        "Clock factor different from the expected."
                        << "\nExpected around: " << 4
                        << "\nGot: " << timing.clockFactor);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.clkPeriod, 3) == 1.25*drs::nanoseconds_per_clock,
                        "Clock different from the expected."
                        << "\nExpected around: " << 1.25*drs::nanoseconds_per_clock
                        << "\nGot: " << timing.clkPeriod);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.coreClkPeriod, 3) == 5*drs::nanoseconds_per_clock,
                        "Core clock different from the expected."
                        << "\nExpected around: " << 5*drs::nanoseconds_per_clock
                        << "\nGot: " << timing.coreClkPeriod);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trcd_clk, 3) == 9*drs::clocks,
                        "trcd in number of clocks different from the expected."
                        << "\nExpected around: " << 9*drs::clocks
                        << "\nGot: " << timing.trcd_clk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tcas_clk, 3) == 14*drs::clocks,
                        "tcas in number of clocks different from the expected."
                        << "\nExpected around: " << 14*drs::clocks
                        << "\nGot: " << timing.tcas_clk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tcas_coreClk, 3) == 4*drs::clocks,
                        "tcas in number of core clocks different from the expected."
                        << "\nExpected around: " << 4*drs::clocks
                        << "\nGot: " << timing.tcas_coreClk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tras_clk, 3) == 17*drs::clocks,
                        "tras in number of clocks different from the expected."
                        << "\nExpected around: " << 17*drs::clocks
                        << "\nGot: " << timing.tras_clk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trp_clk, 3) == 8*drs::clocks,
                        "trp in number of clocks different from the expected."
                        << "\nExpected around: " << 8*drs::clocks
                        << "\nGot: " << timing.trp_clk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trc_clk, 3) == 25*drs::clocks,
                        "trc in number of clocks different from the expected."
                        << "\nExpected around: " << 25*drs::clocks
                        << "\nGot: " << timing.trc_clk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trl_clk, 3) == 15*drs::clocks,
                        "trl in number of clocks different from the expected."
                        << "\nExpected around: " << 15*drs::clocks
                        << "\nGot: " << timing.trl_clk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trl_coreClk, 3) == 4*drs::clocks,
                        "trl in number of core clocks different from the expected."
                        << "\nExpected around: " << 4*drs::clocks
                        << "\nGot: " << timing.trl_coreClk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.twl_clk, 3) == 14*drs::clocks,
                        "twl in number of clocks different from the expected."
                        << "\nExpected around: " << 14*drs::clocks
                        << "\nGot: " << timing.twl_clk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trtp_clk, 3) == 5*drs::clocks,
                        "trtp in number of clocks different from the expected."
                        << "\nExpected around: " << 5*drs::clocks
                        << "\nGot: " << timing.trtp_clk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tccd_clk, 3) == 4*drs::clocks,
                        "tccd in number of clocks different from the expected."
                        << "\nExpected around: " << 4*drs::clocks
                        << "\nGot: " << timing.tccd_clk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tccd_coreClk, 3) == 1*drs::clocks,
                        "tccd in number of core clocks different from the expected."
                        << "\nExpected around: " << 1*drs::clocks
                        << "\nGot: " << timing.tccd_coreClk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.twr_clk, 3) == 7*drs::clocks,
                        "twr in number of clocks different from the expected."
                        << "\nExpected around: " << 7*drs::clocks
                        << "\nGot: " << timing.twr_clk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trfc_clk, 3) == 36*drs::clocks,
                        "trfc in number of clocks different from the expected."
                        << "\nExpected around: " << 36*drs::clocks
                        << "\nGot: " << timing.trfc_clk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trefI_clk, 3) == 6250*drs::clocks,
                        "trefI in number of clocks different from the expected."
                        << "\nExpected around: " << 6250*drs::clocks
                        << "\nGot: " << timing.trefI_clk);

}

BOOST_AUTO_TEST_SUITE_END()

#endif // TIMINGTEST_CPP
