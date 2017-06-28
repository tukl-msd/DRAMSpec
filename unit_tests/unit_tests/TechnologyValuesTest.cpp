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

#ifndef TECHNOLOGYVALUESTEST_CPP
#define TECHNOLOGYVALUESTEST_CPP

#include <boost/test/included/unit_test.hpp>

#include "../../parser/TechnologyValues.h"

BOOST_AUTO_TEST_SUITE( testTechnologyValues )

BOOST_AUTO_TEST_CASE( checkInputTechnologyValues_real_input )
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
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

    TechnologyValues techValues;
    try {
        techValues = TechnologyValues(inputFileName.technologyFileName[0],
                         inputFileName.architectureFileName[0]);
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    expectedMsg = string("Empty");
    if ( exceptionMsg != expectedMsg ) {
        BOOST_FAIL( exceptionMsg );
    }

    BOOST_CHECK_MESSAGE( techValues.technologyNode == 58*drs::nanometer,
                        "Technology node different from the expected."
                        << "\nExpected: " << 58*drs::nanometer
                        << "\nGot: " << techValues.technologyNode);

    BOOST_CHECK_MESSAGE( techValues.vpp == 2.8*si::volt,
                         "VPP different from the expected."
                        << "\nExpected: " << 2.8*si::volt
                        << "\nGot: " << techValues.vpp);

    BOOST_CHECK_MESSAGE( techValues.vcc == 1.1*si::volt,
                         "VCC different from the expected."
                        << "\nExpected: " << 1.1*si::volt
                        << "\nGot: " << techValues.vcc);

    BOOST_CHECK_MESSAGE( techValues.wireResistance == 100*drs::ohm_per_millimeter,
                         "Wire resistance different from the expected."
                        << "\nExpected: " << 100*drs::ohm_per_millimeter
                        << "\nGot: " << techValues.wireResistance);

    BOOST_CHECK_MESSAGE( techValues.wireCapacitance == 382*drs::femtofarads_per_millimeter,
                         "Wire capacitance different from the expected."
                        << "\nExpected: " << 382*drs::femtofarads_per_millimeter
                        << "\nGot: " << techValues.wireCapacitance);

    BOOST_CHECK_MESSAGE( techValues.capacitancePerCell == 20*drs::femtofarads_per_cell,
                        "Capacitance per cell different from the expected."
                        << "\nExpected: " << 20*drs::femtofarads_per_cell
                        << "\nGot: " << techValues.capacitancePerWLCell);

    BOOST_CHECK_MESSAGE( techValues.resistancePerCell == 20*drs::kiloohm_per_cell,
                        "Resistance per cell different from the expected."
                        << "\nExpected: " << 20*drs::kiloohm_per_cell
                        << "\nGot: " << techValues.resistancePerWLCell);

    BOOST_CHECK_MESSAGE( techValues.cellWidth == 0.12*drs::micrometer_per_cell,
                         "Cell width different from the expected."
                        << "\nExpected: " << 0.12*drs::micrometer_per_cell
                        << "\nGot: " << techValues.cellWidth);

    BOOST_CHECK_MESSAGE( techValues.cellHeight == 0.18*drs::micrometer_per_cell,
                         "Cell height different from the expected."
                        << "\nExpected: " << 0.18*drs::micrometer_per_cell
                        << "\nGot: " << techValues.cellHeight);

    BOOST_CHECK_MESSAGE( techValues.cellsPerLWL == 524*drs::cell_per_subarray,
                         "Cells per local wordline different from the expected."
                        << "\nExpected: " << 524*drs::cell_per_subarray
                        << "\nGot: " << techValues.cellsPerLWL);

    BOOST_CHECK_MESSAGE( techValues.cellsPerLWLRedundancy == 12*drs::cell_per_subarray,
                         "Redundant cells per local wordline different from the expected."
                        << "\nExpected: " << 12*drs::cell_per_subarray
                        << "\nGot: " << techValues.cellsPerLWLRedundancy);

    BOOST_CHECK_MESSAGE( techValues.cellsPerLBL == 524*drs::cell_per_subarray,
                         "Cells per local bitline different from the expected."
                        << "\nExpected: " << 524*drs::cell_per_subarray
                        << "\nGot: " << techValues.cellsPerLBL);

    BOOST_CHECK_MESSAGE( techValues.cellsPerLBLRedundancy == 12*drs::cell_per_subarray,
                         "Redundant cells per local bitline different from the expected."
                        << "\nExpected: " << 12*drs::cell_per_subarray
                        << "\nGot: " << techValues.cellsPerLBLRedundancy);

    BOOST_CHECK_MESSAGE( techValues.capacitancePerBLCell == 160*drs::attofarads_per_cell,
                        "Capacitance per bitline cell different from the expected."
                        << "\nExpected: " << 160*drs::attofarads_per_cell
                        << "\nGot: " << techValues.capacitancePerBLCell);

    BOOST_CHECK_MESSAGE( techValues.resistancePerBLCell == 36*drs::ohm_per_cell,
                        "Resistance per bitline cell different from the expected."
                        << "\nExpected: " << 36*drs::ohm_per_cell
                        << "\nGot: " << techValues.resistancePerBLCell);

    BOOST_CHECK_MESSAGE( techValues.capacitancePerWLCell == 150*drs::attofarads_per_cell,
                        "Capacitance per wordline cell different from the expected."
                        << "\nExpected: " << 150*drs::attofarads_per_cell
                        << "\nGot: " << techValues.capacitancePerWLCell);

    BOOST_CHECK_MESSAGE( techValues.resistancePerWLCell == 46*drs::ohm_per_cell,
                        "Resistance per wordline cell different from the expected."
                        << "\nExpected: " << 46*drs::ohm_per_cell
                        << "\nGot: " << techValues.resistancePerWLCell);

    BOOST_CHECK_MESSAGE( techValues.BLSenseAmpHeight == 20*drs::micrometer,
                         "Bitline sense amp. height different from the expected."
                        << "\nExpected: " << 20*drs::micrometer
                        << "\nGot: " << techValues.BLSenseAmpHeight);

    BOOST_CHECK_MESSAGE( techValues.LWLDriverWidth == 9*drs::micrometer,
                         "Wordline driver width different from the expected."
                        << "\nExpected: " << 9*drs::micrometer
                        << "\nGot: " << techValues.LWLDriverWidth);

    BOOST_CHECK_MESSAGE( techValues.LWLDriverResistance == 1000*drs::ohm_per_subarray,
                         "Local wordline driver resistance different from the expected."
                        << "\nExpected: " << 1000*drs::ohm_per_subarray
                        << "\nGot: " << techValues.LWLDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.rowDecoderWidth == 240*drs::micrometer,
                         "Row decoder (between tiles) width different from the expected."
                        << "\nExpected: " << 240*drs::micrometer
                        << "\nGot: " << techValues.rowDecoderWidth);

    BOOST_CHECK_MESSAGE( techValues.GWLDriverResistance == 400*si::ohm,
                         "Global wordline driver resistance different from the expected."
                        << "\nExpected: " << 400*si::ohm
                        << "\nGot: " << techValues.GWLDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.Issa == 300*drs::microampere_per_bit,
                         "SSA current different from the expected."
                        << "\nExpected: " << 300*drs::microampere_per_bit
                        << "\nGot: " << techValues.Issa);

    BOOST_CHECK_MESSAGE( techValues.WRResistance == 600*drs::ohm_per_subarray,
                         "WRrestore resistance different from the expected."
                        << "\nExpected: " << 600*drs::ohm_per_subarray
                        << "\nGot: " << techValues.WRResistance);

    BOOST_CHECK_MESSAGE( techValues.colDecoderHeight == 200*drs::micrometer,
                         "Column decoder (between tiles) width different from the expected."
                        << "\nExpected: " << 200*drs::micrometer
                        << "\nGot: " << techValues.colDecoderHeight);

    BOOST_CHECK_MESSAGE( techValues.CSLDriverResistance == 600*si::ohm,
                         "CSL driver resistance different from the expected."
                        << "\nExpected: " << 600*si::ohm
                        << "\nGot: " << techValues.CSLDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.GDLDriverResistance == 600*si::ohm,
                         "GDL driver resistance different from the expected."
                        << "\nExpected: " << 600*si::ohm
                        << "\nGot: " << techValues.GDLDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.DQDriverHeight == 250*drs::micrometer,
                         "DQ driver (between banks) height different from the expected."
                        << "\nExpected: " << 250*drs::micrometer
                        << "\nGot: " << techValues.DQDriverHeight);

    BOOST_CHECK_MESSAGE( techValues.DQDriverResistance == 500*si::ohm,
                         "DQ driver resistance different from the expected."
                        << "\nExpected: " << 500*si::ohm
                        << "\nGot: " << techValues.DQDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.backgroundCurrentSlope == 0.025*drs::milliamperes_per_megahertz_clock,
                         "Background current slope different from the expected."
                        << "\nExpected: " << 0.025*drs::milliamperes_per_megahertz_clock
                        << "\nGot: " << techValues.backgroundCurrentSlope);

    BOOST_CHECK_MESSAGE( techValues.backgroundCurrentOffset == 17*drs::milliampere,
                         "Background current offset different from the expected."
                        << "\nExpected: " << 17*drs::milliampere
                        << "\nGot: " << techValues.backgroundCurrentOffset);

    BOOST_CHECK_MESSAGE( techValues.IddOcdRcvSlope == 5.629*drs::microamperes_per_megahertz_clock,
                         "Current slope per IO pin different from the expected."
                        << "\nExpected: " << 5.629*drs::microamperes_per_megahertz_clock
                        << "\nGot: " << techValues.IddOcdRcvSlope);

    BOOST_CHECK_MESSAGE( techValues.TSVHeight == 2*drs::micrometer,
                         "Height of the TSV area needed for each bank I/O different from the expected."
                        << "\nExpected: " << 2*drs::micrometer
                        << "\nGot: " << techValues.TSVHeight);




    BOOST_CHECK_MESSAGE( techValues.dramType == "DDR",
                         "DRAM type different from the expected."
                        << "\nExpected: " << "DDR"
                        << "\nGot: " << techValues.dramType);

    BOOST_CHECK_MESSAGE( techValues.is3D == false,
                         "3D flag different from the expected."
                        << "\nExpected: " << false
                        << "\nGot: " << techValues.is3D);

    BOOST_CHECK_MESSAGE( techValues.isDLL == true,
                         "DLL flag different from the expected."
                        << "\nExpected: " << true
                        << "\nGot: " << techValues.isDLL);

    BOOST_CHECK_MESSAGE( techValues.dramSize == 1*drs::gibibit,
                         "DRAM Size different from the expected."
                        << "\nExpected: " << 1*drs::gibibit
                        << "\nGot: " << techValues.dramSize);

    BOOST_CHECK_MESSAGE( techValues.nBanks == 8*drs::bank,
                         "Number of banks different from the expected."
                        << "\nExpected: " << 8*drs::bank
                        << "\nGot: " << techValues.nBanks);

    BOOST_CHECK_MESSAGE( techValues.nHorizontalBanks == 0*drs::bank,
                         "Number of banks in the row direction different from the expected."
                        << "\nExpected: " << 0*drs::bank
                        << "\nGot: " << techValues.nHorizontalBanks);

    BOOST_CHECK_MESSAGE( techValues.nVerticalBanks == 0*drs::bank,
                         "Number of banks in the column direction different from the expected."
                        << "\nExpected: " << 0*drs::bank
                        << "\nGot: " << techValues.nVerticalBanks);

    BOOST_CHECK_MESSAGE( techValues.Interface == 16*drs::bit,
                         "Interface different from the expected."
                        << "\nExpected: " << 16*drs::bit
                        << "\nGot: " << techValues.Interface);

    BOOST_CHECK_MESSAGE( techValues.Prefetch == 8,
                         "Prefetch different from the expected."
                        << "\nExpected: " << 8
                        << "\nGot: " << techValues.Prefetch);

    BOOST_CHECK_MESSAGE( techValues.dramFreq == 800*drs::megahertz_clock,
                         "DRAM frequency different from the expected."
                        << "\nExpected: " << 800*drs::megahertz_clock
                        << "\nGot: " << techValues.dramFreq);

    BOOST_CHECK_MESSAGE( techValues.dramCoreFreq == 0*drs::megahertz_clock,
                         "DRAM core frequency different from the expected."
                        << "\nExpected: " << 0*drs::megahertz_clock
                        << "\nGot: " << techValues.dramCoreFreq);

    BOOST_CHECK_MESSAGE( techValues.tilesPerBank == 2*drs::tile_per_bank,
                         "Tiles per bank different from the expected."
                        << "\nExpected: " << 2*drs::tile_per_bank
                        << "\nGot: " << techValues.tilesPerBank);

    BOOST_CHECK_MESSAGE( techValues.pageStorage == 2*drs::kibibyte_per_page,
                         "Page size different from the expected."
                        << "\nExpected: " << 2*drs::kibibyte_per_page
                        << "\nGot: " << techValues.pageStorage);

    BOOST_CHECK_MESSAGE( techValues.pageSpanningFactor == 0.5*drs::page_per_tile,
                         "Pages per tile different from the expected."
                        << "\nExpected: " << 0.5*drs::page_per_tile
                        << "\nGot: " << techValues.pageSpanningFactor);

    BOOST_CHECK_MESSAGE( techValues.subArrayToPageFactor == 1,
                         "Ratio of subarrays activated pro command different from the expected."
                        << "\nExpected: " << 1
                        << "\nGot: " << techValues.subArrayToPageFactor);

    BOOST_CHECK_MESSAGE( techValues.BLArchitecture == "OPEN",
                        "Bitline architecture different from the expected."
                        << "\nExpected: " << "OPEN"
                        << "\nGot: " << techValues.BLArchitecture);

    BOOST_CHECK_MESSAGE( techValues.retentionTime == 32*drs::millisecond,
                         "Retention time different from the expected."
                        << "\nExpected: " << 32*drs::millisecond
                        << "\nGot: " << techValues.retentionTime);

    BOOST_CHECK_MESSAGE( techValues.tRef1Required == 3.9*drs::microsecond,
                         "Required tRef1 different from the expected."
                        << "\nExpected: " << 3.9*drs::microsecond
                        << "\nGot: " << techValues.tRef1Required);

    BOOST_CHECK_MESSAGE( techValues.banksRefreshFactor == 2,
                         "Bank refresh factor different from the expected."
                        << "\nExpected: " << 2
                        << "\nGot: " << techValues.banksRefreshFactor);

    BOOST_CHECK_MESSAGE( techValues.additionalLatencyTrl == 0*drs::clock,
                         "Additional latency to trl different from the expected."
                        << "\nExpected: " << 0*drs::clock
                        << "\nGot: " << techValues.additionalLatencyTrl);

    BOOST_CHECK_MESSAGE( techValues.driverOffset == 0.6*drs::nanoseconds,
                        "Driver offset time different from the expected."
                        << "\nExpected around: " << 0.6*drs::nanoseconds
                        << "\nGot: " << techValues.driverOffset);

    BOOST_CHECK_MESSAGE( techValues.BitlineSenseAmpDelay == 2*drs::nanoseconds,
                        "Secondary sense amplifier delay different from the expected."
                        << "\nExpected around: " << 2*drs::nanoseconds
                        << "\nGot: " << techValues.BitlineSenseAmpDelay);

    BOOST_CHECK_MESSAGE( techValues.cmdDecoderLatency == 2*drs::nanoseconds,
                        "Command decoder latency different from the expected."
                        << "\nExpected around: " << 2*drs::nanoseconds
                        << "\nGot: " << techValues.cmdDecoderLatency);

    BOOST_CHECK_MESSAGE( techValues.interfaceLatency == 1*drs::nanoseconds,
                        "Interface latency different from the expected."
                        << "\nExpected around: " << 1*drs::nanoseconds
                        << "\nGot: " << techValues.interfaceLatency);

    BOOST_CHECK_MESSAGE( techValues.IODelay == 1*drs::nanoseconds,
                        "IO Delay different from the expected."
                        << "\nExpected around: " << 1*drs::nanoseconds
                        << "\nGot: " << techValues.IODelay);

    BOOST_CHECK_MESSAGE( techValues.SSAPrechargeDelay == 1*drs::nanoseconds,
                        "Delay of precharge SSA different from the expected."
                        << "\nExpected around: " << 1*drs::nanoseconds
                        << "\nGot: " << techValues.SSAPrechargeDelay);

    BOOST_CHECK_MESSAGE( techValues.securityMargin == 1*drs::nanoseconds,
                        "Security margin different from the expected."
                        << "\nExpected around: " << 1*drs::nanoseconds
                        << "\nGot: " << techValues.securityMargin);

    BOOST_CHECK_MESSAGE( techValues.equalizerDelay == 1*drs::nanoseconds,
                        "Equalizer delay different from the expected."
                        << "\nExpected around: " << 1*drs::nanoseconds
                        << "\nGot: " << techValues.equalizerDelay);

    BOOST_CHECK_MESSAGE( techValues.actCmdDelay == 5*drs::nanoseconds,
                        "Act commmand delay different from the expected."
                        << "\nExpected around: " << 5*drs::nanoseconds
                        << "\nGot: " << techValues.actCmdDelay);

    BOOST_CHECK_MESSAGE( techValues.preCmdDelay == 5*drs::nanoseconds,
                        "Pre command delay different from the expected."
                        << "\nExpected around: " << 5*drs::nanoseconds
                        << "\nGot: " << techValues.preCmdDelay);

    BOOST_CHECK_MESSAGE( techValues.offset == 10*drs::nanoseconds,
                        "Offset time different from the expected."
                        << "\nExpected around: " << 10*drs::nanoseconds
                        << "\nGot: " << techValues.offset);

    BOOST_CHECK_MESSAGE( techValues.CSLLoadCapacitance == 8*drs::femtofarads_per_bank,
                        "Load capacitance of CSL different from the expected."
                        << "\nExpected around: " << 8*drs::femtofarads_per_bank
                        << "\nGot: " << techValues.CSLLoadCapacitance);

}


BOOST_AUTO_TEST_CASE( checkInputTechnologyValues_dummy_input )
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

    TechnologyValues techValues;
    try {
        techValues = TechnologyValues(inputFileName.technologyFileName[0],
                         inputFileName.architectureFileName[0]);
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    expectedMsg = string("Empty");
    if ( exceptionMsg != expectedMsg ) {
        BOOST_FAIL( exceptionMsg );
    }


    BOOST_CHECK_MESSAGE( techValues.technologyNode == 1*drs::nanometer,
                        "Technology node different from the expected."
                        << "\nExpected: " << 1*drs::nanometer
                        << "\nGot: " << techValues.technologyNode);

    BOOST_CHECK_MESSAGE( techValues.vpp == 2*si::volt,
                         "VPP different from the expected."
                        << "\nExpected: " << 2*si::volt
                        << "\nGot: " << techValues.vpp);

    BOOST_CHECK_MESSAGE( techValues.vcc == 3*si::volt,
                         "VCC different from the expected."
                        << "\nExpected: " << 3*si::volt
                        << "\nGot: " << techValues.vcc);

    BOOST_CHECK_MESSAGE( techValues.wireResistance == 4*drs::ohm_per_millimeter,
                         "Wire resistance different from the expected."
                        << "\nExpected: " << 4*drs::ohm_per_millimeter
                        << "\nGot: " << techValues.wireResistance);

    BOOST_CHECK_MESSAGE( techValues.wireCapacitance == 5*drs::femtofarads_per_millimeter,
                         "Wire capacitance different from the expected."
                        << "\nExpected: " << 5*drs::femtofarads_per_millimeter
                        << "\nGot: " << techValues.wireCapacitance);

    BOOST_CHECK_MESSAGE( techValues.capacitancePerCell == 6*drs::femtofarads_per_cell,
                        "Capacitance per cell different from the expected."
                        << "\nExpected: " << 6*drs::femtofarads_per_cell
                        << "\nGot: " << techValues.capacitancePerWLCell);

    BOOST_CHECK_MESSAGE( techValues.resistancePerCell == 7*drs::kiloohm_per_cell,
                        "Resistance per cell different from the expected."
                        << "\nExpected: " << 7*drs::kiloohm_per_cell
                        << "\nGot: " << techValues.resistancePerWLCell);

    BOOST_CHECK_MESSAGE( techValues.cellWidth == 8*drs::micrometer_per_cell,
                         "Cell width different from the expected."
                        << "\nExpected: " << 8*drs::micrometer_per_cell
                        << "\nGot: " << techValues.cellWidth);

    BOOST_CHECK_MESSAGE( techValues.cellHeight == 9*drs::micrometer_per_cell,
                         "Cell height different from the expected."
                        << "\nExpected: " << 9*drs::micrometer_per_cell
                        << "\nGot: " << techValues.cellHeight);

    BOOST_CHECK_MESSAGE( techValues.cellsPerLWL == 10*drs::cell_per_subarray,
                         "Cells per local wordline different from the expected."
                        << "\nExpected: " << 10*drs::cell_per_subarray
                        << "\nGot: " << techValues.cellsPerLWL);

    BOOST_CHECK_MESSAGE( techValues.cellsPerLWLRedundancy == 11*drs::cell_per_subarray,
                         "Redundant cells per local wordline different from the expected."
                        << "\nExpected: " << 11*drs::cell_per_subarray
                        << "\nGot: " << techValues.cellsPerLWLRedundancy);

    BOOST_CHECK_MESSAGE( techValues.cellsPerLBL == 12*drs::cell_per_subarray,
                         "Cells per local bitline different from the expected."
                        << "\nExpected: " << 12*drs::cell_per_subarray
                        << "\nGot: " << techValues.cellsPerLBL);

    BOOST_CHECK_MESSAGE( techValues.cellsPerLBLRedundancy == 13*drs::cell_per_subarray,
                         "Redundant cells per local bitline different from the expected."
                        << "\nExpected: " << 13*drs::cell_per_subarray
                        << "\nGot: " << techValues.cellsPerLBLRedundancy);

    BOOST_CHECK_MESSAGE( techValues.capacitancePerBLCell == 14*drs::attofarads_per_cell,
                        "Capacitance per bitline cell different from the expected."
                        << "\nExpected: " << 14*drs::attofarads_per_cell
                        << "\nGot: " << techValues.capacitancePerBLCell);

    BOOST_CHECK_MESSAGE( techValues.resistancePerBLCell == 15*drs::ohm_per_cell,
                        "Resistance per bitline cell different from the expected."
                        << "\nExpected: " << 15*drs::ohm_per_cell
                        << "\nGot: " << techValues.resistancePerBLCell);

    BOOST_CHECK_MESSAGE( techValues.capacitancePerWLCell == 16*drs::attofarads_per_cell,
                        "Capacitance per wordline cell different from the expected."
                        << "\nExpected: " << 16*drs::attofarads_per_cell
                        << "\nGot: " << techValues.capacitancePerWLCell);

    BOOST_CHECK_MESSAGE( techValues.resistancePerWLCell == 17*drs::ohm_per_cell,
                        "Resistance per wordline cell different from the expected."
                        << "\nExpected: " << 17*drs::ohm_per_cell
                        << "\nGot: " << techValues.resistancePerWLCell);

    BOOST_CHECK_MESSAGE( techValues.BLSenseAmpHeight == 18*drs::micrometer,
                         "Bitline sense amp. height different from the expected."
                        << "\nExpected: " << 18*drs::micrometer
                        << "\nGot: " << techValues.BLSenseAmpHeight);

    BOOST_CHECK_MESSAGE( techValues.LWLDriverWidth == 19*drs::micrometer,
                         "Wordline driver width different from the expected."
                        << "\nExpected: " << 19*drs::micrometer
                        << "\nGot: " << techValues.LWLDriverWidth);

    BOOST_CHECK_MESSAGE( techValues.LWLDriverResistance == 20*drs::ohm_per_subarray,
                         "Local wordline driver resistance different from the expected."
                        << "\nExpected: " << 20*drs::ohm_per_subarray
                        << "\nGot: " << techValues.LWLDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.rowDecoderWidth == 21*drs::micrometer,
                         "Row decoder (between tiles) width different from the expected."
                        << "\nExpected: " << 21*drs::micrometer
                        << "\nGot: " << techValues.rowDecoderWidth);

    BOOST_CHECK_MESSAGE( techValues.GWLDriverResistance == 22*si::ohm,
                         "Global wordline driver resistance different from the expected."
                        << "\nExpected: " << 22*si::ohm
                        << "\nGot: " << techValues.GWLDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.Issa == 23*drs::microampere_per_bit,
                         "SSA current different from the expected."
                        << "\nExpected: " << 23*drs::microampere_per_bit
                        << "\nGot: " << techValues.Issa);

    BOOST_CHECK_MESSAGE( techValues.WRResistance == 24*drs::ohm_per_subarray,
                         "WRrestore resistance different from the expected."
                        << "\nExpected: " << 24*drs::ohm_per_subarray
                        << "\nGot: " << techValues.WRResistance);

    BOOST_CHECK_MESSAGE( techValues.colDecoderHeight == 25*drs::micrometer,
                         "Column decoder (between tiles) width different from the expected."
                        << "\nExpected: " << 25*drs::micrometer
                        << "\nGot: " << techValues.colDecoderHeight);

    BOOST_CHECK_MESSAGE( techValues.CSLDriverResistance == 26*si::ohm,
                         "CSL driver resistance different from the expected."
                        << "\nExpected: " << 26*si::ohm
                        << "\nGot: " << techValues.CSLDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.GDLDriverResistance == 27*si::ohm,
                         "GDL driver resistance different from the expected."
                        << "\nExpected: " << 27*si::ohm
                        << "\nGot: " << techValues.GDLDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.DQDriverHeight == 28*drs::micrometer,
                         "DQ driver (between banks) height different from the expected."
                        << "\nExpected: " << 28*drs::micrometer
                        << "\nGot: " << techValues.DQDriverHeight);

    BOOST_CHECK_MESSAGE( techValues.DQDriverResistance == 29*si::ohm,
                         "DQ driver resistance different from the expected."
                        << "\nExpected: " << 29*si::ohm
                        << "\nGot: " << techValues.DQDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.backgroundCurrentSlope == 30*drs::milliamperes_per_megahertz_clock,
                         "Background current slope different from the expected."
                        << "\nExpected: " << 30*drs::milliamperes_per_megahertz_clock
                        << "\nGot: " << techValues.backgroundCurrentSlope);

    BOOST_CHECK_MESSAGE( techValues.backgroundCurrentOffset == 31*drs::milliampere,
                         "Background current offset different from the expected."
                        << "\nExpected: " << 31*drs::milliampere
                        << "\nGot: " << techValues.backgroundCurrentOffset);

    BOOST_CHECK_MESSAGE( techValues.IddOcdRcvSlope == 32*drs::microamperes_per_megahertz_clock,
                         "Current slope per IO pin different from the expected."
                        << "\nExpected: " << 32*drs::microamperes_per_megahertz_clock
                        << "\nGot: " << techValues.IddOcdRcvSlope);

    BOOST_CHECK_MESSAGE( techValues.TSVHeight == 33*drs::micrometer,
                         "Height of the TSV area needed for each bank I/O different from the expected."
                        << "\nExpected: " << 33*drs::micrometer
                        << "\nGot: " << techValues.TSVHeight);




    BOOST_CHECK_MESSAGE( techValues.dramType == "DDR",
                         "DRAM type different from the expected."
                        << "\nExpected: " << "DDR"
                        << "\nGot: " << techValues.dramType);

    BOOST_CHECK_MESSAGE( techValues.is3D == false,
                         "3D flag different from the expected."
                        << "\nExpected: " << false
                        << "\nGot: " << techValues.is3D);

    BOOST_CHECK_MESSAGE( techValues.isDLL == false,
                         "DLL flag different from the expected."
                        << "\nExpected: " << false
                        << "\nGot: " << techValues.isDLL);

    BOOST_CHECK_MESSAGE( techValues.dramSize == 100*drs::gibibit,
                         "DRAM Size different from the expected."
                        << "\nExpected: " << 100*drs::gibibit
                        << "\nGot: " << techValues.dramSize);

    BOOST_CHECK_MESSAGE( techValues.nBanks == 101*drs::bank,
                         "Number of banks different from the expected."
                        << "\nExpected: " << 101*drs::bank
                        << "\nGot: " << techValues.nBanks);

    BOOST_CHECK_MESSAGE( techValues.nHorizontalBanks == 102*drs::bank,
                         "Number of banks in the row direction different from the expected."
                        << "\nExpected: " << 102*drs::bank
                        << "\nGot: " << techValues.nHorizontalBanks);

    BOOST_CHECK_MESSAGE( techValues.nVerticalBanks == 103*drs::bank,
                         "Number of banks in the column direction different from the expected."
                        << "\nExpected: " << 103*drs::bank
                        << "\nGot: " << techValues.nVerticalBanks);

    BOOST_CHECK_MESSAGE( techValues.Interface == 104*drs::bit,
                         "Interface different from the expected."
                        << "\nExpected: " << 104*drs::bit
                        << "\nGot: " << techValues.Interface);

    BOOST_CHECK_MESSAGE( techValues.Prefetch == 105,
                         "Prefetch different from the expected."
                        << "\nExpected: " << 105
                        << "\nGot: " << techValues.Prefetch);

    BOOST_CHECK_MESSAGE( techValues.dramFreq == 106*drs::megahertz_clock,
                         "DRAM frequency different from the expected."
                        << "\nExpected: " << 106*drs::megahertz_clock
                        << "\nGot: " << techValues.dramFreq);

    BOOST_CHECK_MESSAGE( techValues.dramCoreFreq == 107*drs::megahertz_clock,
                         "DRAM core frequency different from the expected."
                        << "\nExpected: " << 107*drs::megahertz_clock
                        << "\nGot: " << techValues.dramCoreFreq);

    BOOST_CHECK_MESSAGE( techValues.tilesPerBank == 108*drs::tile_per_bank,
                         "Tiles per bank different from the expected."
                        << "\nExpected: " << 108*drs::tile_per_bank
                        << "\nGot: " << techValues.tilesPerBank);

    BOOST_CHECK_MESSAGE( techValues.pageStorage == 109*drs::kibibyte_per_page,
                         "Page size different from the expected."
                        << "\nExpected: " << 109*drs::kibibyte_per_page
                        << "\nGot: " << techValues.pageStorage);

    BOOST_CHECK_MESSAGE( techValues.pageSpanningFactor == 110*drs::page_per_tile,
                         "Pages per tile different from the expected."
                        << "\nExpected: " << 110*drs::page_per_tile
                        << "\nGot: " << techValues.pageSpanningFactor);

    BOOST_CHECK_MESSAGE( techValues.subArrayToPageFactor == 111,
                         "Ratio of subarrays activated pro command different from the expected."
                        << "\nExpected: " << 111
                        << "\nGot: " << techValues.subArrayToPageFactor);

    BOOST_CHECK_MESSAGE( techValues.BLArchitecture == "112",
                        "Bitline architecture different from the expected."
                        << "\nExpected: " << "112"
                        << "\nGot: " << techValues.BLArchitecture);

    BOOST_CHECK_MESSAGE( techValues.retentionTime == 113*drs::millisecond,
                         "Retention time different from the expected."
                        << "\nExpected: " << 113*drs::millisecond
                        << "\nGot: " << techValues.retentionTime);

    BOOST_CHECK_MESSAGE( techValues.tRef1Required == 114*drs::microsecond,
                         "Required tRef1 different from the expected."
                        << "\nExpected: " << 114*drs::microsecond
                        << "\nGot: " << techValues.tRef1Required);

    BOOST_CHECK_MESSAGE( techValues.banksRefreshFactor == 115,
                         "Bank refresh factor different from the expected."
                        << "\nExpected: " << 115
                        << "\nGot: " << techValues.banksRefreshFactor);

    BOOST_CHECK_MESSAGE( techValues.additionalLatencyTrl == 116*drs::clock,
                         "Additional latency to trl different from the expected."
                        << "\nExpected: " << 116*drs::clock
                        << "\nGot: " << techValues.additionalLatencyTrl);

    BOOST_CHECK_MESSAGE( techValues.driverOffset == 117*drs::nanoseconds,
                        "Driver offset time different from the expected."
                        << "\nExpected around: " << 117*drs::nanoseconds
                        << "\nGot: " << techValues.driverOffset);

    BOOST_CHECK_MESSAGE( techValues.BitlineSenseAmpDelay == 118*drs::nanoseconds,
                        "Secondary sense amplifier delay different from the expected."
                        << "\nExpected around: " << 118*drs::nanoseconds
                        << "\nGot: " << techValues.BitlineSenseAmpDelay);

    BOOST_CHECK_MESSAGE( techValues.cmdDecoderLatency == 119*drs::nanoseconds,
                        "Command decoder latency different from the expected."
                        << "\nExpected around: " << 119*drs::nanoseconds
                        << "\nGot: " << techValues.cmdDecoderLatency);

    BOOST_CHECK_MESSAGE( techValues.interfaceLatency == 120*drs::nanoseconds,
                        "Interface latency different from the expected."
                        << "\nExpected around: " << 120*drs::nanoseconds
                        << "\nGot: " << techValues.interfaceLatency);

    BOOST_CHECK_MESSAGE( techValues.IODelay == 121*drs::nanoseconds,
                        "IO Delay different from the expected."
                        << "\nExpected around: " << 121*drs::nanoseconds
                        << "\nGot: " << techValues.IODelay);

    BOOST_CHECK_MESSAGE( techValues.SSAPrechargeDelay == 122*drs::nanoseconds,
                        "Delay of precharge SSA different from the expected."
                        << "\nExpected around: " << 122*drs::nanoseconds
                        << "\nGot: " << techValues.SSAPrechargeDelay);

    BOOST_CHECK_MESSAGE( techValues.securityMargin == 123*drs::nanoseconds,
                        "Security margin different from the expected."
                        << "\nExpected around: " << 123*drs::nanoseconds
                        << "\nGot: " << techValues.securityMargin);

    BOOST_CHECK_MESSAGE( techValues.equalizerDelay == 124*drs::nanoseconds,
                        "Equalizer delay different from the expected."
                        << "\nExpected around: " << 124*drs::nanoseconds
                        << "\nGot: " << techValues.equalizerDelay);

    BOOST_CHECK_MESSAGE( techValues.actCmdDelay == 125*drs::nanoseconds,
                        "Act commmand delay different from the expected."
                        << "\nExpected around: " << 125*drs::nanoseconds
                        << "\nGot: " << techValues.actCmdDelay);

    BOOST_CHECK_MESSAGE( techValues.preCmdDelay == 126*drs::nanoseconds,
                        "Pre command delay different from the expected."
                        << "\nExpected around: " << 126*drs::nanoseconds
                        << "\nGot: " << techValues.preCmdDelay);

    BOOST_CHECK_MESSAGE( techValues.offset == 127*drs::nanoseconds,
                        "Offset time different from the expected."
                        << "\nExpected around: " << 127*drs::nanoseconds
                        << "\nGot: " << techValues.offset);

    BOOST_CHECK_MESSAGE( techValues.CSLLoadCapacitance == 128*drs::femtofarads_per_bank,
                        "Load capacitance of CSL different from the expected."
                        << "\nExpected around: " << 128*drs::femtofarads_per_bank
                        << "\nGot: " << techValues.CSLLoadCapacitance);

}


BOOST_AUTO_TEST_CASE( checkInputTechnologyValues_no_tech_file )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "../../technology_input/not_a_file.json",
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
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

    TechnologyValues techValues;
    try {
        techValues = TechnologyValues(inputFileName.technologyFileName[0],
                         inputFileName.architectureFileName[0]);
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    expectedMsg = string("[ERROR] ");
    expectedMsg.append("Could not open technology file: ");
    expectedMsg.append(inputFileName.technologyFileName[0]);
    expectedMsg.append("!\n");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);
}

BOOST_AUTO_TEST_CASE( checkInputTechnologyValues_no_arch_file )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "../../technology_input/test_technology.json",
                        "-p",
                        "../../architecture_input/not_a_file.json"};

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

    TechnologyValues techValues;
    try {
        techValues = TechnologyValues(inputFileName.technologyFileName[0],
                                      inputFileName.architectureFileName[0]);
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    expectedMsg = string("[ERROR] ");
    expectedMsg.append("Could not open architecture file: ");
    expectedMsg.append(inputFileName.architectureFileName[0]);
    expectedMsg.append("!\n");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

}

BOOST_AUTO_TEST_CASE( checkInputTechnologyValues_bad_tech_file )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "../../main.cpp",
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
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

    TechnologyValues techValues;
    try {
        techValues = TechnologyValues(inputFileName.technologyFileName[0],
                                      inputFileName.architectureFileName[0]);
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    expectedMsg = string("[ERROR] ");
    expectedMsg.append("Could not parse ");
    expectedMsg.append(inputFileName.technologyFileName[0]);
    expectedMsg.append(" as a JSON document.\n");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);

}

BOOST_AUTO_TEST_CASE( checkInputTechnologyValues_bad_arch_file )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "../../technology_input/test_technology.json",
                        "-p",
                        "../../main.cpp"};

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

    TechnologyValues techValues;
    try {
        techValues = TechnologyValues(inputFileName.technologyFileName[0],
                                      inputFileName.architectureFileName[0]);
    }catch (string exceptionMsgThrown){
        exceptionMsg = exceptionMsgThrown;
    }
    expectedMsg = string("[ERROR] ");
    expectedMsg.append("Could not parse ");
    expectedMsg.append(inputFileName.architectureFileName[0]);
    expectedMsg.append(" as a JSON document.\n");
    BOOST_CHECK_MESSAGE( exceptionMsg == expectedMsg,
                        "Error message different from what was expected."
                        << "\nExpected: " << expectedMsg
                        << "\nGot: " << exceptionMsg);
}

BOOST_AUTO_TEST_SUITE_END()

#endif

