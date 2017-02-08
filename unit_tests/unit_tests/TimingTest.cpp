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

#ifndef TIMINGTEST_CPP
#define TIMINGTEST_CPP

#include <boost/test/included/unit_test.hpp>

#include "../core/Timing.h"

BOOST_AUTO_TEST_SUITE( testTiming )

BOOST_AUTO_TEST_CASE( checkTiming_real_input )
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

    Timing timing(inputFileName.technologyFileName[0],
                      inputFileName.architectureFileName[0]);

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

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.bitlineResistance, 3) == 18864*drs::ohms_per_subarray,
                        "Bitline resistance different from the expected."
                        << "\nExpected around: " << 18864*drs::ohms_per_subarray
                        << "\nGot: " << timing.bitlineResistance);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.bitlineCapacitance, 9) == 8.384e-05*drs::nanofarads_per_subarray,
                        "Bitline capacitance different from the expected."
                        << "\nExpected around: " << 8.384e-05*drs::nanofarads_per_subarray
                        << "\nGot: " << timing.bitlineCapacitance);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.bitlineDelay, 3) == 3.642*drs::nanoseconds,
                        "Delay through bitline different from the expected."
                        << "\nExpected around: " << 3.642*drs::nanoseconds
                        << "\nGot: " << timing.bitlineDelay);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.globalWordlineResistance, 3) == 115.908*drs::ohms_per_tile,
                        "Resistance of global wordline different from the expected."
                        << "\nExpected around: " << 115.908*drs::ohms_per_tile
                        << "\nGot: " << timing.globalWordlineResistance);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.globalWordlineCapacitance, 6) == 4.43e-4*drs::nanofarads_per_tile,
                        "Capacitance of global wordline different from the expected."
                        << "\nExpected around: " << 4.43e-4*drs::nanofarads_per_tile
                        << "\nGot: " << timing.globalWordlineCapacitance);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.driverOffset, 3) == 0.6*drs::nanoseconds,
                        "Driver offset time different from the expected."
                        << "\nExpected around: " << 0.6*drs::nanoseconds
                        << "\nGot: " << timing.driverOffset);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.globalWordlineDelay, 3) == 1.059*drs::nanoseconds,
                        "Delay through global wordline different from the expected."
                        << "\nExpected around: " << 1.059*drs::nanoseconds
                        << "\nGot: " << timing.globalWordlineDelay);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.SSADelay, 3) == 2*drs::nanoseconds,
                        "Secondary sense amplifier delay different from the expected."
                        << "\nExpected around: " << 2*drs::nanoseconds
                        << "\nGot: " << timing.SSADelay);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trcd, 3) == 12.165*drs::nanoseconds,
                        "trcd different from the expected."
                        << "\nExpected around: " << 12.165*drs::nanoseconds
                        << "\nGot: " << timing.trcd);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.CSLLoadCapacitance, 3) == 8*drs::femtofarads_per_bank,
                        "Load capacitance of CSL different from the expected."
                        << "\nExpected around: " << 8*drs::femtofarads_per_bank
                        << "\nGot: " << timing.CSLLoadCapacitance);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tcsl, 3) == 1.905*drs::nanoseconds,
                        "tcsl different from the expected."
                        << "\nExpected around: " << 1.905*drs::nanoseconds
                        << "\nGot: " << timing.tcsl);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.globalDatalineResistance, 3) == 212.344*drs::ohms_per_bank,
                        "Resistance of global dataline different from the expected."
                        << "\nExpected around: " << 212.344*drs::ohms_per_bank
                        << "\nGot: " << timing.globalDatalineResistance);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.globalDatalineCapacitance, 6) == 8.12e-4*drs::nanofarads_per_bank,
                        "Capacitance of global dataline different from the expected."
                        << "\nExpected around: " << 8.12e-4*drs::nanofarads_per_bank
                        << "\nGot: " << timing.globalDatalineCapacitance);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tgdl, 3) == 1.892*drs::nanoseconds,
                        "tgdl different from the expected."
                        << "\nExpected around: " << 1.892*drs::nanoseconds
                        << "\nGot: " << timing.tgdl);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.DQWireLength, 3) == 5*drs::millimeters,
                        "Length of bank to DQ wire different from the expected."
                        << "\nExpected around: " << 5*drs::millimeters
                        << "\nGot: " << timing.DQWireLength);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.bankWidthFactor, 3) == 16*drs::kibibits_per_page,
                        "Bank width factor different from the expected."
                        << "\nExpected around: " << 16*drs::kibibits_per_page
                        << "\nGot: " << timing.bankWidthFactor);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.DQWireResistance, 3) == 500*si::ohms,
                        "Resistance of bank to DQ wire different from the expected."
                        << "\nExpected around: " << 500*si::ohms
                        << "\nGot: " << timing.DQWireResistance);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.DQWireCapacitance, 6) == 1.91e-3*drs::nanofarads,
                        "Capacitance of bank do DQ wire different from the expected."
                        << "\nExpected around: " << 1.91e-3*drs::nanofarads
                        << "\nGot: " << timing.DQWireCapacitance);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tdq, 3) == 3.749*drs::nanoseconds,
                        "tdq different from the expected."
                        << "\nExpected around: " << 3.749*drs::nanoseconds
                        << "\nGot: " << timing.tdq);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.cmdDecoderLatency, 3) == 2*drs::nanoseconds,
                        "Command decoder latency different from the expected."
                        << "\nExpected around: " << 2*drs::nanoseconds
                        << "\nGot: " << timing.cmdDecoderLatency);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.interfaceLatency, 3) == 1*drs::nanoseconds,
                        "Interface latency different from the expected."
                        << "\nExpected around: " << 1*drs::nanoseconds
                        << "\nGot: " << timing.interfaceLatency);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.IODelay, 3) == 1*drs::nanoseconds,
                        "IO Delay different from the expected."
                        << "\nExpected around: " << 1*drs::nanoseconds
                        << "\nGot: " << timing.IODelay);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tcas, 3) == 13.546*drs::nanoseconds,
                        "tcas different from the expected."
                        << "\nExpected around: " << 13.546*drs::nanoseconds
                        << "\nGot: " << timing.tcas);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trtp, 3) == 5.797*drs::nanoseconds,
                        "trtp different from the expected."
                        << "\nExpected around: " << 5.797*drs::nanoseconds
                        << "\nGot: " << timing.trtp);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tccd, 3) == 4.197*drs::nanoseconds,
                        "tccd different from the expected."
                        << "\nExpected around: " << 4.197*drs::nanoseconds
                        << "\nGot: " << timing.tccd);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.SSAPrechargeDelay, 3) == 1*drs::nanoseconds,
                        "Delay of precharge SSA different from the expected."
                        << "\nExpected around: " << 1*drs::nanoseconds
                        << "\nGot: " << timing.SSAPrechargeDelay);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tras, 3) == 22.159*drs::nanoseconds,
                        "tras different from the expected."
                        << "\nExpected around: " << 22.159*drs::nanoseconds
                        << "\nGot: " << timing.tras);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.securityMargin, 3) == 1*drs::nanoseconds,
                        "Security margin different from the expected."
                        << "\nExpected around: " << 1*drs::nanoseconds
                        << "\nGot: " << timing.securityMargin);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.twr, 3) == 8.534*drs::nanoseconds,
                        "twr different from the expected."
                        << "\nExpected around: " << 8.534*drs::nanoseconds
                        << "\nGot: " << timing.twr);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.equalizerDelay, 3) == 1*drs::nanoseconds,
                        "Equalizer delay different from the expected."
                        << "\nExpected around: " << 1*drs::nanoseconds
                        << "\nGot: " << timing.equalizerDelay);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trp, 3) == 9.186*drs::nanoseconds,
                        "trp different from the expected."
                        << "\nExpected around: " << 9.186*drs::nanoseconds
                        << "\nGot: " << timing.trp);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trc, 3) == 31.344*drs::nanoseconds,
                        "trc different from the expected."
                        << "\nExpected around: " << 31.344*drs::nanoseconds
                        << "\nGot: " << timing.trc);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.actCmdDelay, 3) == 5*drs::nanoseconds,
                        "Act commmand delay different from the expected."
                        << "\nExpected around: " << 5*drs::nanoseconds
                        << "\nGot: " << timing.actCmdDelay);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.preCmdDelay, 3) == 5*drs::nanoseconds,
                        "Pre command delay different from the expected."
                        << "\nExpected around: " << 5*drs::nanoseconds
                        << "\nGot: " << timing.preCmdDelay);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.offset, 3) == 10*drs::nanoseconds,
                        "Offset time different from the expected."
                        << "\nExpected around: " << 10*drs::nanoseconds
                        << "\nGot: " << timing.offset);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trfc, 3) == 41.969*drs::nanoseconds,
                        "trfc different from the expected."
                        << "\nExpected around: " << 41.969*drs::nanoseconds
                        << "\nGot: " << timing.trfc);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tref1, 2) == 1953.13*drs::nanoseconds,
                        "tref1 different from the expected."
                        << "\nExpected around: " << 1953.13*drs::nanoseconds
                        << "\nGot: " << timing.tref1);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.maxCoreFreq, 3) == 238.291*drs::megahertz_clock,
                        "Maximum core frequency different from the expected."
                        << "\nExpected around: " << 238.291*drs::megahertz_clock
                        << "\nGot: " << timing.maxCoreFreq);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.actualCoreFreq, 3) == 266.5*drs::megahertz_clock,
                        "Actual core frequency different from the expected."
                        << "\nExpected around: " << 266.5*drs::megahertz_clock
                        << "\nGot: " << timing.actualCoreFreq);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.clk, 3) == 0.939*drs::nanoseconds_per_clock,
                        "Clock different from the expected."
                        << "\nExpected around: " << 0.939*drs::nanoseconds_per_clock
                        << "\nGot: " << timing.clk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.actualClk, 3) == 3.753*drs::nanoseconds_per_clock,
                        "Actual clock different from the expected."
                        << "\nExpected around: " << 3.753*drs::nanoseconds_per_clock
                        << "\nGot: " << timing.actualClk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trcd_clk, 3) == 13*drs::clocks,
                        "trcd in number of clocks different from the expected."
                        << "\nExpected around: " << 13*drs::clocks
                        << "\nGot: " << timing.trcd_clk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tcas_clk, 3) == 15*drs::clocks,
                        "tcas in number of clocks different from the expected."
                        << "\nExpected around: " << 15*drs::clocks
                        << "\nGot: " << timing.tcas_clk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tcas_actualClk, 3) == 4*drs::clocks,
                        "tcas in number of clocks by the actual clock different from the expected."
                        << "\nExpected around: " << 4*drs::clocks
                        << "\nGot: " << timing.tcas_actualClk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tras_clk, 3) == 24*drs::clocks,
                        "tras in number of clocks different from the expected."
                        << "\nExpected around: " << 24*drs::clocks
                        << "\nGot: " << timing.tras_clk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trp_clk, 3) == 10*drs::clocks,
                        "trp in number of clocks different from the expected."
                        << "\nExpected around: " << 10*drs::clocks
                        << "\nGot: " << timing.trp_clk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trc_clk, 3) == 34*drs::clocks,
                        "trc in number of clocks different from the expected."
                        << "\nExpected around: " << 34*drs::clocks
                        << "\nGot: " << timing.trc_clk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trl_clk, 3) == 15*drs::clocks,
                        "trl in number of clocks different from the expected."
                        << "\nExpected around: " << 15*drs::clocks
                        << "\nGot: " << timing.trl_clk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trl_actualClk, 3) == 4*drs::clocks,
                        "trl in number of clocks by the actual clock different from the expected."
                        << "\nExpected around: " << 4*drs::clocks
                        << "\nGot: " << timing.trl_actualClk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.twl_clk, 3) == 14*drs::clocks,
                        "twl in number of clocks different from the expected."
                        << "\nExpected around: " << 14*drs::clocks
                        << "\nGot: " << timing.twl_clk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trtp_clk, 3) == 7*drs::clocks,
                        "trtp in number of clocks different from the expected."
                        << "\nExpected around: " << 7*drs::clocks
                        << "\nGot: " << timing.trtp_clk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tccd_clk, 3) == 5*drs::clocks,
                        "tccd in number of clocks different from the expected."
                        << "\nExpected around: " << 5*drs::clocks
                        << "\nGot: " << timing.tccd_clk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tccd_actualClk, 3) == 2*drs::clocks,
                        "tccd in number of clocks by the actual clock different from the expected."
                        << "\nExpected around: " << 2*drs::clocks
                        << "\nGot: " << timing.tccd_actualClk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.twr_clk, 3) == 10*drs::clocks,
                        "twr in number of clocks different from the expected."
                        << "\nExpected around: " << 10*drs::clocks
                        << "\nGot: " << timing.twr_clk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.trfc_clk, 3) == 45*drs::clocks,
                        "trfc in number of clocks different from the expected."
                        << "\nExpected around: " << 45*drs::clocks
                        << "\nGot: " << timing.trfc_clk);

    BOOST_CHECK_MESSAGE( ROUND_UP(timing.tref1_clk, 3) == 2083*drs::clocks,
                        "tref1 in number of clocks different from the expected."
                        << "\nExpected around: " << 2083*drs::clocks
                        << "\nGot: " << timing.tref1_clk);

}

//BOOST_AUTO_TEST_CASE( checkChip_dummy_input )
//{
//    int sim_argc = 5;
//    char* sim_argv[] = {"./executable",
//                        "-t",
//                        "../technology_input/tech_dummy_input.json",
//                        "-p",
//                        "../architecture_input/arch_dummy_input.json"};

//    ArgumentsParser inputFileName(sim_argc, sim_argv);

//    std::string exceptionMsg("Empty");
//    try {
//        inputFileName.runArgParser();
//    }catch (std::string exceptionMsgThrown){
//        exceptionMsg = exceptionMsgThrown;
//    }

//    std::string expectedMsg("Empty");
//    BOOST_CHECK_MESSAGE( exceptionMsg, 3) == expectedMsg,
//                        "Error message different from what was expected."
//                        << "\nExpected: " << expectedMsg
//                        << "\nGot: " << exceptionMsg);

//    try {
//        Chip chip(inputFileName.technologyFileName[0],
//                  inputFileName.architectureFileName[0]);
//    }catch (std::string exceptionMsgThrown){
//        exceptionMsg = exceptionMsgThrown;
//    }

//    expectedMsg = "[ERROR] Architecture must have ";
//    expectedMsg.append("1, 2 or 4 tile per bank.");
//    BOOST_CHECK_MESSAGE( exceptionMsg, 3) == expectedMsg,
//                        "Error message different from what was expected."
//                        << "\nExpected: " << expectedMsg
//                        << "\nGot: " << exceptionMsg);

//    Chip chip;
//    chip.readjson(inputFileName.technologyFileName[0],
//                  inputFileName.architectureFileName[0]);
//    try {
//        chip.chipCompute();
//    }catch (std::string exceptionMsgThrown){
//        exceptionMsg = exceptionMsgThrown;
//    }

//    expectedMsg = "[ERROR] Architecture must have ";
//    expectedMsg.append("1, 2, 4, 6 or 8 banks.");
//    BOOST_CHECK_MESSAGE( exceptionMsg, 3) == expectedMsg,
//                        "Error message different from what was expected."
//                        << "\nExpected: " << expectedMsg
//                        << "\nGot: " << exceptionMsg);


//}

//BOOST_AUTO_TEST_CASE( checkChip_different_bank_configs )
//{
//    int sim_argc = 5;
//    char* sim_argv[] = {"./executable",
//                        "-t",
//                        "../technology_input/techddr3_5x.json",
//                        "-p",
//                        "../architecture_input/parddr3.json"};

//    ArgumentsParser inputFileName(sim_argc, sim_argv);

//    std::string exceptionMsg("Empty");
//    try {
//        inputFileName.runArgParser();
//    }catch (std::string exceptionMsgThrown){
//        exceptionMsg = exceptionMsgThrown;
//    }

//    std::string expectedMsg("Empty");
//    BOOST_CHECK_MESSAGE( exceptionMsg, 3) == expectedMsg,
//                        "Error message different from what was expected."
//                        << "\nExpected: " << expectedMsg
//                        << "\nGot: " << exceptionMsg);

//    Chip chip(inputFileName.technologyFileName[0],
//                      inputFileName.architectureFileName[0]);

//    chip.nBanks = 1.0*drs::bank;
//    try {
//        chip.tileCompute();
//    }catch (std::string exceptionMsgThrown){
//        std::cerr << exceptionMsgThrown << std::endl;
//    }
//    chip.bankCompute();
//    chip.chipCompute();

//    BOOST_CHECK_MESSAGE( chip.chipStorage, 3) == 1*drs::gibibits,
//                        "Chip storage size different from the expected."
//                        << "\nExpected: " << 1*drs::gibibits
//                        << "\nGot: " << chip.chipStorage);

//    BOOST_CHECK_MESSAGE( ceil(chip.chipWidth), 3) == 2799*drs::micrometer,
//                        "Width of chip different from the expected."
//                        << "\nExpected: " << 2799*drs::micrometer
//                        << "\nGot: " << ceil(chip.chipWidth);

//    BOOST_CHECK_MESSAGE( ceil(chip.chipHeight), 3) == 15428*drs::micrometer,
//                        "Height of chip different from the expected."
//                        << "\nExpected: " << 15428*drs::micrometer
//                        << "\nGot: " << ceil(chip.chipHeight);

//    BOOST_CHECK_MESSAGE( ceil(chip.chipArea), 3) == 44*drs::square_millimeter,
//                        "Area of chip different from the expected."
//                        << "\nExpected: " << 44*drs::square_millimeter
//                        << "\nGot: " << ceil(chip.chipArea);

//    chip.nBanks = 2.0*drs::bank;
//    try {
//        chip.tileCompute();
//    }catch (std::string exceptionMsgThrown){
//        std::cerr << exceptionMsgThrown << std::endl;
//    }
//    chip.bankCompute();
//    chip.chipCompute();

//    BOOST_CHECK_MESSAGE( chip.chipStorage, 3) == 1*drs::gibibits,
//                        "Chip storage size different from the expected."
//                        << "\nExpected: " << 1*drs::gibibits
//                        << "\nGot: " << chip.chipStorage);

//    BOOST_CHECK_MESSAGE( ceil(chip.chipWidth), 3) == 5599*drs::micrometer,
//                        "Width of chip different from the expected."
//                        << "\nExpected: " << 5599*drs::micrometer
//                        << "\nGot: " << ceil(chip.chipWidth);

//    BOOST_CHECK_MESSAGE( ceil(chip.chipHeight), 3) == 8111*drs::micrometer,
//                        "Height of chip different from the expected."
//                        << "\nExpected: " << 8111*drs::micrometer
//                        << "\nGot: " << ceil(chip.chipHeight);

//    BOOST_CHECK_MESSAGE( ceil(chip.chipArea), 3) == 46*drs::square_millimeter,
//                        "Area of chip different from the expected."
//                        << "\nExpected: " << 46*drs::square_millimeter
//                        << "\nGot: " << ceil(chip.chipArea);

//    chip.nBanks = 4.0*drs::bank;
//    try {
//        chip.tileCompute();
//    }catch (std::string exceptionMsgThrown){
//        std::cerr << exceptionMsgThrown << std::endl;
//    }
//    chip.bankCompute();
//    chip.chipCompute();

//    BOOST_CHECK_MESSAGE( chip.chipStorage, 3) == 1*drs::gibibits,
//                        "Chip storage size different from the expected."
//                        << "\nExpected: " << 1*drs::gibibits
//                        << "\nGot: " << chip.chipStorage);

//    BOOST_CHECK_MESSAGE( ceil(chip.chipWidth), 3) == 5599*drs::micrometer,
//                        "Width of chip different from the expected."
//                        << "\nExpected: " << 5599*drs::micrometer
//                        << "\nGot: " << ceil(chip.chipWidth);

//    BOOST_CHECK_MESSAGE( ceil(chip.chipHeight), 3) == 8406*drs::micrometer,
//                        "Height of chip different from the expected."
//                        << "\nExpected: " << 8406*drs::micrometer
//                        << "\nGot: " << ceil(chip.chipHeight);

//    BOOST_CHECK_MESSAGE( ceil(chip.chipArea), 3) == 48*drs::square_millimeter,
//                        "Area of chip different from the expected."
//                        << "\nExpected: " << 48*drs::square_millimeter
//                        << "\nGot: " << ceil(chip.chipArea);

//    chip.nBanks = 6.0*drs::bank;
//    try {
//        chip.tileCompute();
//    }catch (std::string exceptionMsgThrown){
//        std::cerr << exceptionMsgThrown << std::endl;
//    }
//    chip.bankCompute();
//    chip.chipCompute();

//    BOOST_CHECK_MESSAGE( chip.chipStorage, 3) == 1*drs::gibibits,
//                        "Chip storage size different from the expected."
//                        << "\nExpected: " << 1*drs::gibibits
//                        << "\nGot: " << chip.chipStorage);

//    BOOST_CHECK_MESSAGE( ceil(chip.chipWidth), 3) == 8399*drs::micrometer,
//                        "Width of chip different from the expected."
//                        << "\nExpected: " << 8399*drs::micrometer
//                        << "\nGot: " << ceil(chip.chipWidth);

//    BOOST_CHECK_MESSAGE( ceil(chip.chipHeight), 3) == 5967*drs::micrometer,
//                        "Height of chip different from the expected."
//                        << "\nExpected: " << 5967*drs::micrometer
//                        << "\nGot: " << ceil(chip.chipHeight);

//    BOOST_CHECK_MESSAGE( ceil(chip.chipArea), 3) == 51*drs::square_millimeter,
//                        "Area of chip different from the expected."
//                        << "\nExpected: " << 51*drs::square_millimeter
//                        << "\nGot: " << ceil(chip.chipArea);

//    chip.nBanks = 8.0*drs::bank;
//    try {
//        chip.tileCompute();
//    }catch (std::string exceptionMsgThrown){
//        std::cerr << exceptionMsgThrown << std::endl;
//    }
//    chip.bankCompute();
//    chip.chipCompute();

//    BOOST_CHECK_MESSAGE( chip.chipStorage, 3) == 1*drs::gibibits,
//                        "Chip storage size different from the expected."
//                        << "\nExpected: " << 1*drs::gibibits
//                        << "\nGot: " << chip.chipStorage);

//    BOOST_CHECK_MESSAGE( ceil(chip.chipWidth), 3) == 11199*drs::micrometer,
//                        "Width of chip different from the expected."
//                        << "\nExpected: " << 11199*drs::micrometer
//                        << "\nGot: " << ceil(chip.chipWidth);

//    BOOST_CHECK_MESSAGE( ceil(chip.chipHeight), 3) == 4747*drs::micrometer,
//                        "Height of chip different from the expected."
//                        << "\nExpected: " << 4747*drs::micrometer
//                        << "\nGot: " << ceil(chip.chipHeight);

//    BOOST_CHECK_MESSAGE( ceil(chip.chipArea), 3) == 54*drs::square_millimeter,
//                        "Area of chip different from the expected."
//                        << "\nExpected: " << 54*drs::square_millimeter
//                        << "\nGot: " << ceil(chip.chipArea);

//}

BOOST_AUTO_TEST_SUITE_END()

#endif // TIMINGTEST_CPP
