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

    double _mag;

    _mag = 0.922;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.cellDelay, 3) == _mag*drs::nanoseconds,
                        "Delay inside cell different from the expected."
                        << "\nExpected around: " << _mag*drs::nanoseconds
                        << "\nGot: " << timing.cellDelay);

    _mag = 25104;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.localWordlineResistance, 3) == _mag*drs::ohms_per_subarray,
                        "Resistance of local wordline different from the expected."
                        << "\nExpected around: " << _mag*drs::ohms_per_subarray
                        << "\nGot: " << timing.localWordlineResistance);

    _mag = 7.8601e-05;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.localWordlineCapacitance, 9) == _mag*drs::nanofarads_per_subarray,
                        "Capacitance of local wordline different from the expected."
                        << "\nExpected around: " << _mag*drs::nanofarads_per_subarray
                        << "\nGot: " << timing.localWordlineCapacitance);

    _mag = 4.544;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.localWordlineDelay, 3) == _mag*drs::nanoseconds,
                        "Delay through local wordline different from the expected."
                        << "\nExpected around: " << _mag*drs::nanoseconds
                        << "\nGot: " << timing.localWordlineDelay);

    _mag = 18864;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.localBitlineResistance, 3) == _mag*drs::ohms_per_subarray,
                        "Bitline resistance different from the expected."
                        << "\nExpected around: " << _mag*drs::ohms_per_subarray
                        << "\nGot: " << timing.localBitlineResistance);

    _mag = 8.384e-05;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.localBitlineCapacitance, 9) == _mag*drs::nanofarads_per_subarray,
                        "Bitline capacitance different from the expected."
                        << "\nExpected around: " << _mag*drs::nanofarads_per_subarray
                        << "\nGot: " << timing.localBitlineCapacitance);

    _mag = 3.642;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.localBitlineDelay, 3) == _mag*drs::nanoseconds,
                        "Delay through bitline different from the expected."
                        << "\nExpected around: " << _mag*drs::nanoseconds
                        << "\nGot: " << timing.localBitlineDelay);

    _mag = 115.908;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.globalWordlineResistance, 3) == _mag*drs::ohms_per_tile,
                        "Resistance of global wordline different from the expected."
                        << "\nExpected around: " << _mag*drs::ohms_per_tile
                        << "\nGot: " << timing.globalWordlineResistance);

    _mag = 4.43e-4;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.globalWordlineCapacitance, 6) == _mag*drs::nanofarads_per_tile,
                        "Capacitance of global wordline different from the expected."
                        << "\nExpected around: " << _mag*drs::nanofarads_per_tile
                        << "\nGot: " << timing.globalWordlineCapacitance);

    _mag = 1.059;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.globalWordlineDelay, 3) == _mag*drs::nanoseconds,
                        "Delay through global wordline different from the expected."
                        << "\nExpected around: " << _mag*drs::nanoseconds
                        << "\nGot: " << timing.globalWordlineDelay);

    _mag = 10.165;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trcd, 3) == _mag*drs::nanoseconds,
                        "trcd different from the expected."
                        << "\nExpected around: " << _mag*drs::nanoseconds
                        << "\nGot: " << timing.trcd);

    _mag = 2.045;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tcsl, 3) == _mag*drs::nanoseconds,
                        "tcsl different from the expected."
                        << "\nExpected around: " << _mag*drs::nanoseconds
                        << "\nGot: " << timing.tcsl);

    _mag = 232.344;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.globalDatalineResistance, 3) == _mag*drs::ohms_per_bank,
                        "Resistance of global dataline different from the expected."
                        << "\nExpected around: " << _mag*drs::ohms_per_bank
                        << "\nGot: " << timing.globalDatalineResistance);

    _mag = 8.88e-4;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.globalDatalineCapacitance, 6) == _mag*drs::nanofarads_per_bank,
                        "Capacitance of global dataline different from the expected."
                        << "\nExpected around: " << _mag*drs::nanofarads_per_bank
                        << "\nGot: " << timing.globalDatalineCapacitance);

    _mag = 2.032;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tgdl, 3) == _mag*drs::nanoseconds,
                        "tgdl different from the expected."
                        << "\nExpected around: " << _mag*drs::nanoseconds
                        << "\nGot: " << timing.tgdl);

    _mag = 8394.48;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.DQWireLength, 3) == _mag*drs::micrometers,
                        "Length of bank to DQ wire different from the expected."
                        << "\nExpected around: " << _mag*drs::micrometers
                        << "\nGot: " << timing.DQWireLength);

    _mag = 839.448;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.DQWireResistance, 3) == _mag*si::ohms,
                        "Resistance of bank to DQ wire different from the expected."
                        << "\nExpected around: " << _mag*si::ohms
                        << "\nGot: " << timing.DQWireResistance);

    _mag = 3.207e-3;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.DQWireCapacitance, 6) == _mag*drs::nanofarads,
                        "Capacitance of bank do DQ wire different from the expected."
                        << "\nExpected around: " << _mag*drs::nanofarads
                        << "\nGot: " << timing.DQWireCapacitance);

    _mag = 6.969;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tdq, 3) == _mag*drs::nanoseconds,
                        "tdq different from the expected."
                        << "\nExpected around: " << _mag*drs::nanoseconds
                        << "\nGot: " << timing.tdq);

    _mag = 20.638;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tcas, 3) == _mag*drs::nanoseconds,
                        "tcas different from the expected."
                        << "\nExpected around: " << _mag*drs::nanoseconds
                        << "\nGot: " << timing.tcas);

    _mag = 21.888;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trl, 3) == _mag*drs::nanoseconds,
                        "trl different from the expected."
                        << "\nExpected around: " << _mag*drs::nanoseconds
                        << "\nGot: " << timing.trl);

    _mag = 9.670;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trtp, 3) == _mag*drs::nanoseconds,
                        "trtp different from the expected."
                        << "\nExpected around: " << _mag*drs::nanoseconds
                        << "\nGot: " << timing.trtp);

    _mag = 4.476;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tccd, 3) == _mag*drs::nanoseconds,
                        "tccd different from the expected."
                        << "\nExpected around: " << _mag*drs::nanoseconds
                        << "\nGot: " << timing.tccd);

    _mag = 24.310;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tras, 3) == _mag*drs::nanoseconds,
                        "tras different from the expected."
                        << "\nExpected around: " << _mag*drs::nanoseconds
                        << "\nGot: " << timing.tras);

    _mag = 8.673;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.twr, 3) == _mag*drs::nanoseconds,
                        "twr different from the expected."
                        << "\nExpected around: " << _mag*drs::nanoseconds
                        << "\nGot: " << timing.twr);

    _mag = 9.186;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trp, 3) == _mag*drs::nanoseconds,
                        "trp different from the expected."
                        << "\nExpected around: " << _mag*drs::nanoseconds
                        << "\nGot: " << timing.trp);

    _mag = 33.495;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trc, 3) == _mag*drs::nanoseconds,
                        "trc different from the expected."
                        << "\nExpected around: " << _mag*drs::nanoseconds
                        << "\nGot: " << timing.trc);

    _mag = 43.913;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trfc, 3) == _mag*drs::nanoseconds,
                        "trfc different from the expected."
                        << "\nExpected around: " << _mag*drs::nanoseconds
                        << "\nGot: " << timing.trfc);

    _mag = 7812.5;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trefI, 2) == _mag*drs::nanoseconds,
                        "trefI different from the expected."
                        << "\nExpected around: " << _mag*drs::nanoseconds
                        << "\nGot: " << timing.trefI);

    _mag = 223.446;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.maxCoreFreq, 3) == _mag*drs::megahertz_clock,
                        "Maximum core frequency different from the expected."
                        << "\nExpected around: " << _mag*drs::megahertz_clock
                        << "\nGot: " << timing.maxCoreFreq);

    _mag = 4;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.clockFactor, 3) == _mag,
                        "Clock factor different from the expected."
                        << "\nExpected around: " << _mag
                        << "\nGot: " << timing.clockFactor);

    _mag = 1.25;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.clkPeriod, 3) == _mag*drs::nanoseconds_per_clock,
                        "Clock different from the expected."
                        << "\nExpected around: " << _mag*drs::nanoseconds_per_clock
                        << "\nGot: " << timing.clkPeriod);

    _mag = 5;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.coreClkPeriod, 3) == _mag*drs::nanoseconds_per_clock,
                        "Core clock different from the expected."
                        << "\nExpected around: " << _mag*drs::nanoseconds_per_clock
                        << "\nGot: " << timing.coreClkPeriod);

    _mag = 9;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trcd_clk, 3) == _mag*drs::clocks,
                        "trcd in number of clocks different from the expected."
                        << "\nExpected around: " << _mag*drs::clocks
                        << "\nGot: " << timing.trcd_clk);

    _mag = 17;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tcas_clk, 3) == _mag*drs::clocks,
                        "tcas in number of clocks different from the expected."
                        << "\nExpected around: " << _mag*drs::clocks
                        << "\nGot: " << timing.tcas_clk);

    _mag = 5;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tcas_coreClk, 3) == _mag*drs::clocks,
                        "tcas in number of core clocks different from the expected."
                        << "\nExpected around: " << _mag*drs::clocks
                        << "\nGot: " << timing.tcas_coreClk);

    _mag = 20;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tras_clk, 3) == _mag*drs::clocks,
                        "tras in number of clocks different from the expected."
                        << "\nExpected around: " << _mag*drs::clocks
                        << "\nGot: " << timing.tras_clk);

    _mag = 8;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trp_clk, 3) == _mag*drs::clocks,
                        "trp in number of clocks different from the expected."
                        << "\nExpected around: " << _mag*drs::clocks
                        << "\nGot: " << timing.trp_clk);

    _mag = 27;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trc_clk, 3) == _mag*drs::clocks,
                        "trc in number of clocks different from the expected."
                        << "\nExpected around: " << _mag*drs::clocks
                        << "\nGot: " << timing.trc_clk);

    _mag = 18;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trl_clk, 3) == _mag*drs::clocks,
                        "trl in number of clocks different from the expected."
                        << "\nExpected around: " << _mag*drs::clocks
                        << "\nGot: " << timing.trl_clk);

    _mag = 5;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trl_coreClk, 3) == _mag*drs::clocks,
                        "trl in number of core clocks different from the expected."
                        << "\nExpected around: " << _mag*drs::clocks
                        << "\nGot: " << timing.trl_coreClk);

    _mag = 17;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.twl_clk, 3) == _mag*drs::clocks,
                        "twl in number of clocks different from the expected."
                        << "\nExpected around: " << _mag*drs::clocks
                        << "\nGot: " << timing.twl_clk);

    _mag = 8;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trtp_clk, 3) == _mag*drs::clocks,
                        "trtp in number of clocks different from the expected."
                        << "\nExpected around: " << _mag*drs::clocks
                        << "\nGot: " << timing.trtp_clk);

    _mag = 4;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tccd_clk, 3) == _mag*drs::clocks,
                        "tccd in number of clocks different from the expected."
                        << "\nExpected around: " << _mag*drs::clocks
                        << "\nGot: " << timing.tccd_clk);

    _mag = 1;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tccd_coreClk, 3) == _mag*drs::clocks,
                        "tccd in number of core clocks different from the expected."
                        << "\nExpected around: " << _mag*drs::clocks
                        << "\nGot: " << timing.tccd_coreClk);

    _mag = 7;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.twr_clk, 3) == _mag*drs::clocks,
                        "twr in number of clocks different from the expected."
                        << "\nExpected around: " << _mag*drs::clocks
                        << "\nGot: " << timing.twr_clk);

    _mag = 36;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trfc_clk, 3) == _mag*drs::clocks,
                        "trfc in number of clocks different from the expected."
                        << "\nExpected around: " << _mag*drs::clocks
                        << "\nGot: " << timing.trfc_clk);

    _mag = 6250;
    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trefI_clk, 3) == _mag*drs::clocks,
                        "trefI in number of clocks different from the expected."
                        << "\nExpected around: " << _mag*drs::clocks
                        << "\nGot: " << timing.trefI_clk);

}

BOOST_AUTO_TEST_SUITE_END()

#endif // TIMINGTEST_CPP
