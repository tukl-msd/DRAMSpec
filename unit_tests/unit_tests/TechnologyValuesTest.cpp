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

#include "../parser/TechnologyValues.h"

BOOST_AUTO_TEST_SUITE( testTechnologyValues )

BOOST_AUTO_TEST_CASE( checkInputTechnologyValues_real_input )
{
    int sim_argc = 5;
    char* sim_argv[] = {"./executable",
                        "-t",
                        "../technology_input/test_technology.json",
                        "-p",
                        "../architecture_input/test_architecture.json"};

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

    TechnologyValues techValues(inputFileName.technologyFileName[0],
                                inputFileName.architectureFileName[0]);

    techValues.readjson(techValues.techName ,
                        techValues.paraName);

    BOOST_CHECK_MESSAGE( techValues.technologyNode == 58*drs::nanometer,
                        "Technology node different from the expected."
                        << "\nExpected: " << 58*drs::nanometer
                        << "\nGot: " << techValues.technologyNode);

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

    BOOST_CHECK_MESSAGE( techValues.capacitancePerCell == 20*drs::picofarads_per_cell,
                        "Capacitance per cell different from the expected."
                        << "\nExpected: " << 20*drs::picofarads_per_cell
                        << "\nGot: " << techValues.capacitancePerWLCell);

    BOOST_CHECK_MESSAGE( techValues.resistancePerCell == 20*drs::ohm_per_cell,
                        "Resistance per cell different from the expected."
                        << "\nExpected: " << 20*drs::ohm_per_cell
                        << "\nGot: " << techValues.resistancePerWLCell);

    BOOST_CHECK_MESSAGE( techValues.wireResistance == 100*drs::ohm_per_millimeter,
                         "Wire resistance different from the expected."
                        << "\nExpected: " << 100*drs::ohm_per_millimeter
                        << "\nGot: " << techValues.wireResistance);

    BOOST_CHECK_MESSAGE( techValues.wireCapacitance == 382*drs::femtofarads_per_millimeter,
                         "Wire capacitance different from the expected."
                        << "\nExpected: " << 382*drs::femtofarads_per_millimeter
                        << "\nGot: " << techValues.wireCapacitance);

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

    BOOST_CHECK_MESSAGE( techValues.BLSenseAmpHeight == 20*drs::micrometer,
                         "Bitline sense amp. height different from the expected."
                        << "\nExpected: " << 20*drs::micrometer
                        << "\nGot: " << techValues.BLSenseAmpHeight);

    BOOST_CHECK_MESSAGE( techValues.WLDriverWidth == 9*drs::micrometer,
                         "Wordline driver width different from the expected."
                        << "\nExpected: " << 9*drs::micrometer
                        << "\nGot: " << techValues.WLDriverWidth);

    BOOST_CHECK_MESSAGE( techValues.GWLDriverResistance == 400*si::ohm,
                         "Global wordline driver resistance different from the expected."
                        << "\nExpected: " << 400*si::ohm
                        << "\nGot: " << techValues.GWLDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.LWLDriverResistance == 1000*drs::ohm_per_subarray,
                         "Local wordline driver resistance different from the expected."
                        << "\nExpected: " << 1000*drs::ohm_per_subarray
                        << "\nGot: " << techValues.LWLDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.WRResistance == 600*drs::ohm_per_subarray,
                         "WRrestore resistance different from the expected."
                        << "\nExpected: " << 600*drs::ohm_per_subarray
                        << "\nGot: " << techValues.WRResistance);

    BOOST_CHECK_MESSAGE( techValues.CSLDriverResistance == 600*si::ohm,
                         "CSL driver resistance different from the expected."
                        << "\nExpected: " << 600*si::ohm
                        << "\nGot: " << techValues.CSLDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.GDLDriverResistance == 600*si::ohm,
                         "GDL driver resistance different from the expected."
                        << "\nExpected: " << 600*si::ohm
                        << "\nGot: " << techValues.GDLDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.DQDriverResistance == 500*si::ohm,
                         "DQ driver resistance different from the expected."
                        << "\nExpected: " << 500*si::ohm
                        << "\nGot: " << techValues.DQDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.Issa == 300*drs::microampere,
                         "SSA current different from the expected."
                        << "\nExpected: " << 300*drs::microampere
                        << "\nGot: " << techValues.Issa);

    BOOST_CHECK_MESSAGE( techValues.Vpp == 2.8*si::volt,
                         "VPP different from the expected."
                        << "\nExpected: " << 2.8*si::volt
                        << "\nGot: " << techValues.Vpp);

    BOOST_CHECK_MESSAGE( techValues.Vcc == 1.1*si::volt,
                         "VCC different from the expected."
                        << "\nExpected: " << 1.1*si::volt
                        << "\nGot: " << techValues.Vcc);

    BOOST_CHECK_MESSAGE( techValues.backgroundCurrentSlope == 0.025*drs::milliamperes_per_megahertz,
                         "Background current slope different from the expected."
                        << "\nExpected: " << 0.025*drs::milliamperes_per_megahertz
                        << "\nGot: " << techValues.backgroundCurrentSlope);

    BOOST_CHECK_MESSAGE( techValues.backgroundCurrentOffset == 17*drs::microampere,
                         "Background current offset different from the expected."
                        << "\nExpected: " << 17*drs::microampere
                        << "\nGot: " << techValues.backgroundCurrentOffset);

    BOOST_CHECK_MESSAGE( techValues.IddOcdRcv == 3.0*drs::microampere,
                         "IDD pro IO for OCD different from the expected."
                        << "\nExpected: " << 3.0*drs::microampere
                        << "\nGot: " << techValues.IddOcdRcv);

    BOOST_CHECK_MESSAGE( techValues.rowDecoderWidth == 240*drs::micrometer,
                         "Row decoder (between tiles) width different from the expected."
                        << "\nExpected: " << 240*drs::micrometer
                        << "\nGot: " << techValues.rowDecoderWidth);

    BOOST_CHECK_MESSAGE( techValues.colDecoderHeight == 200*drs::micrometer,
                         "Column decoder (between tiles) width different from the expected."
                        << "\nExpected: " << 200*drs::micrometer
                        << "\nGot: " << techValues.colDecoderHeight);

    BOOST_CHECK_MESSAGE( techValues.DQDriverHeight == 500*drs::micrometer,
                         "DQ driver (between banks) height different from the expected."
                        << "\nExpected: " << 500*drs::micrometer
                        << "\nGot: " << techValues.DQDriverHeight);

    BOOST_CHECK_MESSAGE( techValues.bankSpacingWidth == 2*drs::micrometer,
                         "Space between banks driver in width direction different from the expected."
                        << "\nExpected: " << 2*drs::micrometer
                        << "\nGot: " << techValues.bankSpacingWidth);




    BOOST_CHECK_MESSAGE( techValues.dramType == "DDR",
                         "DRAM type different from the expected."
                        << "\nExpected: " << "DDR"
                        << "\nGot: " << techValues.dramType);

    BOOST_CHECK_MESSAGE( techValues.ThreeD == "OFF",
                         "3D flag different from the expected."
                        << "\nExpected: " << "OFF"
                        << "\nGot: " << techValues.ThreeD);

    BOOST_CHECK_MESSAGE( techValues.vaultsPerLayer == 1,
                         "Vaults per layer different from the expected."
                        << "\nExpected: " << 1
                        << "\nGot: " << techValues.vaultsPerLayer);

    BOOST_CHECK_MESSAGE( techValues.dramSize == 1*drs::gibibit,
                         "DRAM Size different from the expected."
                        << "\nExpected: " << 1*drs::gibibit
                        << "\nGot: " << techValues.dramSize);

    BOOST_CHECK_MESSAGE( techValues.nBanks == 8*drs::bank,
                         "Number of banks different from the expected."
                        << "\nExpected: " << 8*drs::bank
                        << "\nGot: " << techValues.nBanks);

    BOOST_CHECK_MESSAGE( techValues.Interface == 16,
                         "Interface different from the expected."
                        << "\nExpected: " << 16
                        << "\nGot: " << techValues.Interface);

    BOOST_CHECK_MESSAGE( techValues.dramFreq == 800*drs::megahertz_clock,
                         "DRAM frequency different from the expected."
                        << "\nExpected: " << 800*drs::megahertz_clock
                        << "\nGot: " << techValues.dramFreq);

    BOOST_CHECK_MESSAGE( techValues.dramCoreFreq == 0*drs::megahertz_clock,
                         "DRAM core frequency different from the expected."
                        << "\nExpected: " << 0*drs::megahertz_clock
                        << "\nGot: " << techValues.dramCoreFreq);

    BOOST_CHECK_MESSAGE( techValues.Prefetch == 8,
                         "Prefetch different from the expected."
                        << "\nExpected: " << 8
                        << "\nGot: " << techValues.Prefetch);

    BOOST_CHECK_MESSAGE( techValues.additionalLatencyTrl == 0*drs::clock,
                         "Additional latency to trl different from the expected."
                        << "\nExpected: " << 0*drs::clock
                        << "\nGot: " << techValues.additionalLatencyTrl);

    BOOST_CHECK_MESSAGE( techValues.pageStorage == 16*drs::kibibit_per_page,
                         "Page size different from the expected."
                        << "\nExpected: " << 16*drs::kibibit_per_page
                        << "\nGot: " << techValues.pageStorage);

    BOOST_CHECK_MESSAGE( techValues.DLL == "ON",
                         "DLL flag different from the expected."
                        << "\nExpected: " << "ON"
                        << "\nGot: " << techValues.DLL);

    BOOST_CHECK_MESSAGE( techValues.tRef1Required == 3.9*drs::nanosecond,
                         "Required tRef1 different from the expected."
                        << "\nExpected: " << 3.9*drs::nanosecond
                        << "\nGot: " << techValues.tRef1Required);

    BOOST_CHECK_MESSAGE( techValues.banksRefreshFactor == 1*drs::bank,
                         "Bank refresh factor different from the expected."
                        << "\nExpected: " << 1*drs::bank
                        << "\nGot: " << techValues.banksRefreshFactor);

    BOOST_CHECK_MESSAGE( techValues.rowRefreshRate == 0.5,
                         "Row refresh rate different from the expected."
                        << "\nExpected: " << 0.5
                        << "\nGot: " << techValues.rowRefreshRate);

    BOOST_CHECK_MESSAGE( techValues.subArrayToPageFactor == 1,
                         "Ratio of subarrays activated pro command different from the expected."
                        << "\nExpected: " << 1
                        << "\nGot: " << techValues.subArrayToPageFactor);

    BOOST_CHECK_MESSAGE( techValues.retentionTime == 32*drs::millisecond,
                         "Retention time different from the expected."
                        << "\nExpected: " << 32*drs::millisecond
                        << "\nGot: " << techValues.retentionTime);

    BOOST_CHECK_MESSAGE( techValues.tilesPerBank == 2*drs::tile_per_bank,
                         "Tiles per bank different from the expected."
                        << "\nExpected: " << 2*drs::tile_per_bank
                        << "\nGot: " << techValues.tilesPerBank);

    BOOST_CHECK_MESSAGE( techValues.pageSpanningFactor == 0.5*drs::page_per_tile,
                         "Pages per bank different from the expected."
                        << "\nExpected: " << 0.5*drs::page_per_tile
                        << "\nGot: " << techValues.pageSpanningFactor);

    BOOST_CHECK_MESSAGE( techValues.BLArchitecture == "OPEN",
                        "Bitline architecture different from the expected."
                        << "\nExpected: " << "OPEN"
                        << "\nGot: " << techValues.BLArchitecture);
}


BOOST_AUTO_TEST_CASE( checkInputTechnologyValues_dummy_input )
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

    TechnologyValues techValues(inputFileName.technologyFileName[0],
                                inputFileName.architectureFileName[0]);

    techValues.readjson(techValues.techName ,
                        techValues.paraName);

    BOOST_CHECK_MESSAGE( techValues.technologyNode == 1*drs::nanometer,
                        "Technology node different from the expected."
                        << "\nExpected: " << 1*drs::nanometer
                        << "\nGot: " << techValues.technologyNode);

    BOOST_CHECK_MESSAGE( techValues.capacitancePerBLCell == 2*drs::attofarads_per_cell,
                        "Capacitance per bitline cell different from the expected."
                        << "\nExpected: " << 2*drs::attofarads_per_cell
                        << "\nGot: " << techValues.capacitancePerBLCell);

    BOOST_CHECK_MESSAGE( techValues.resistancePerBLCell == 3*drs::ohm_per_cell,
                        "Resistance per bitline cell different from the expected."
                        << "\nExpected: " << 3*drs::ohm_per_cell
                        << "\nGot: " << techValues.resistancePerBLCell);

    BOOST_CHECK_MESSAGE( techValues.capacitancePerWLCell == 4*drs::attofarads_per_cell,
                        "Capacitance per wordline cell different from the expected."
                        << "\nExpected: " << 4*drs::attofarads_per_cell
                        << "\nGot: " << techValues.capacitancePerWLCell);

    BOOST_CHECK_MESSAGE( techValues.resistancePerWLCell == 5*drs::ohm_per_cell,
                        "Resistance per wordline cell different from the expected."
                        << "\nExpected: " << 5*drs::ohm_per_cell
                        << "\nGot: " << techValues.resistancePerWLCell);

    BOOST_CHECK_MESSAGE( techValues.capacitancePerCell == 6*drs::picofarads_per_cell,
                        "Capacitance per cell different from the expected."
                        << "\nExpected: " << 6*drs::picofarads_per_cell
                        << "\nGot: " << techValues.capacitancePerWLCell);

    BOOST_CHECK_MESSAGE( techValues.resistancePerCell == 7*drs::ohm_per_cell,
                        "Resistance per cell different from the expected."
                        << "\nExpected: " << 7*drs::ohm_per_cell
                        << "\nGot: " << techValues.resistancePerWLCell);

    BOOST_CHECK_MESSAGE( techValues.wireResistance == 8*drs::ohm_per_millimeter,
                        "Wire resistance different from the expected."
                        << "\nExpected: " << 8*drs::ohm_per_millimeter
                        << "\nGot: " << techValues.wireResistance);

    BOOST_CHECK_MESSAGE( techValues.wireCapacitance == 9*drs::femtofarads_per_millimeter,
                        "Wire capacitance different from the expected."
                        << "\nExpected: " << 9*drs::femtofarads_per_millimeter
                        << "\nGot: " << techValues.wireCapacitance);

    BOOST_CHECK_MESSAGE( techValues.cellWidth == 10*drs::micrometer_per_cell,
                        "Cell width different from the expected."
                        << "\nExpected: " << 10*drs::micrometer_per_cell
                        << "\nGot: " << techValues.cellWidth);

    BOOST_CHECK_MESSAGE( techValues.cellHeight == 11*drs::micrometer_per_cell,
                        "Cell height different from the expected."
                        << "\nExpected: " << 11*drs::micrometer_per_cell
                        << "\nGot: " << techValues.cellHeight);

    BOOST_CHECK_MESSAGE( techValues.cellsPerLWL == 12*drs::cell_per_subarray,
                        "Cells per local wordline different from the expected."
                        << "\nExpected: " << 12*drs::cell_per_subarray
                        << "\nGot: " << techValues.cellsPerLWL);

    BOOST_CHECK_MESSAGE( techValues.cellsPerLWLRedundancy == 13*drs::cell_per_subarray,
                        "Redundant cells per local wordline different from the expected."
                        << "\nExpected: " << 13*drs::cell_per_subarray
                        << "\nGot: " << techValues.cellsPerLWLRedundancy);

    BOOST_CHECK_MESSAGE( techValues.cellsPerLBL == 14*drs::cell_per_subarray,
                        "Cells per local bitline different from the expected."
                        << "\nExpected: " << 14*drs::cell_per_subarray
                        << "\nGot: " << techValues.cellsPerLBL);

    BOOST_CHECK_MESSAGE( techValues.cellsPerLBLRedundancy == 15*drs::cell_per_subarray,
                        "Redundant cells per local bitline different from the expected."
                        << "\nExpected: " << 15*drs::cell_per_subarray
                        << "\nGot: " << techValues.cellsPerLBLRedundancy);

    BOOST_CHECK_MESSAGE( techValues.BLSenseAmpHeight == 16*drs::micrometer,
                        "Bitline sense amp. height different from the expected."
                        << "\nExpected: " << 16*drs::micrometer
                        << "\nGot: " << techValues.BLSenseAmpHeight);

    BOOST_CHECK_MESSAGE( techValues.WLDriverWidth == 17*drs::micrometer,
                        "Wordline driver width different from the expected."
                        << "\nExpected: " << 17*drs::micrometer
                        << "\nGot: " << techValues.WLDriverWidth);

    BOOST_CHECK_MESSAGE( techValues.GWLDriverResistance == 18*si::ohm,
                        "Global wordline driver resistance different from the expected."
                        << "\nExpected: " << 18*si::ohm
                        << "\nGot: " << techValues.GWLDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.LWLDriverResistance == 19*drs::ohm_per_subarray,
                        "Local wordline driver resistance different from the expected."
                        << "\nExpected: " << 19*drs::ohm_per_subarray
                        << "\nGot: " << techValues.LWLDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.WRResistance == 20*drs::ohm_per_subarray,
                        "WRrestore resistance different from the expected."
                        << "\nExpected: " << 20*drs::ohm_per_subarray
                        << "\nGot: " << techValues.WRResistance);

    BOOST_CHECK_MESSAGE( techValues.CSLDriverResistance == 21*si::ohm,
                        "CSL driver resistance different from the expected."
                        << "\nExpected: " << 21*si::ohm
                        << "\nGot: " << techValues.CSLDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.GDLDriverResistance == 22*si::ohm,
                        "GDL driver resistance different from the expected."
                        << "\nExpected: " << 22*si::ohm
                        << "\nGot: " << techValues.GDLDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.DQDriverResistance == 23*si::ohm,
                        "DQ driver resistance different from the expected."
                        << "\nExpected: " << 23*si::ohm
                        << "\nGot: " << techValues.DQDriverResistance);

    BOOST_CHECK_MESSAGE( techValues.Issa == 24*drs::microampere,
                        "SSA current different from the expected."
                        << "\nExpected: " << 24*drs::microampere
                        << "\nGot: " << techValues.Issa);

    BOOST_CHECK_MESSAGE( techValues.Vpp == 25*si::volt,
                        "VPP different from the expected."
                        << "\nExpected: " << 25*si::volt
                        << "\nGot: " << techValues.Vpp);

    BOOST_CHECK_MESSAGE( techValues.Vcc == 26*si::volt,
                        "VCC different from the expected."
                        << "\nExpected: " << 26*si::volt
                        << "\nGot: " << techValues.Vcc);

    BOOST_CHECK_MESSAGE( techValues.backgroundCurrentSlope == 27*drs::milliamperes_per_megahertz,
                        "Background current slope different from the expected."
                        << "\nExpected: " << 27*drs::milliamperes_per_megahertz
                        << "\nGot: " << techValues.backgroundCurrentSlope);

    BOOST_CHECK_MESSAGE( techValues.backgroundCurrentOffset == 28*drs::microampere,
                        "Background current offset different from the expected."
                        << "\nExpected: " << 28*drs::microampere
                        << "\nGot: " << techValues.backgroundCurrentOffset);

    BOOST_CHECK_MESSAGE( techValues.IddOcdRcv == 29*drs::microampere,
                        "IDD pro IO for OCD different from the expected."
                        << "\nExpected: " << 29*drs::microampere
                        << "\nGot: " << techValues.IddOcdRcv);

    BOOST_CHECK_MESSAGE( techValues.rowDecoderWidth == 30*drs::micrometer,
                         "Row decoder (between tiles) width different from the expected."
                        << "\nExpected: " << 30*drs::micrometer
                        << "\nGot: " << techValues.rowDecoderWidth);

    BOOST_CHECK_MESSAGE( techValues.colDecoderHeight == 31*drs::micrometer,
                         "Column decoder (between tiles) width different from the expected."
                        << "\nExpected: " << 31*drs::micrometer
                        << "\nGot: " << techValues.colDecoderHeight);

    BOOST_CHECK_MESSAGE( techValues.DQDriverHeight == 32*drs::micrometer,
                         "DQ driver (between banks) height different from the expected."
                        << "\nExpected: " << 32*drs::micrometer
                        << "\nGot: " << techValues.DQDriverHeight);

    BOOST_CHECK_MESSAGE( techValues.bankSpacingWidth == 33*drs::micrometer,
                         "Space between banks driver in width direction different from the expected."
                        << "\nExpected: " << 33*drs::micrometer
                        << "\nGot: " << techValues.bankSpacingWidth);




    BOOST_CHECK_MESSAGE( techValues.dramType == "100",
                        "DRAM type different from the expected."
                        << "\nExpected: " << "100"
                        << "\nGot: " << techValues.dramType);

    BOOST_CHECK_MESSAGE( techValues.ThreeD == "101",
                        "3D flag different from the expected."
                        << "\nExpected: " << "101"
                        << "\nGot: " << techValues.ThreeD);

    BOOST_CHECK_MESSAGE( techValues.vaultsPerLayer == 102,
                        "Vaults per layer different from the expected."
                        << "\nExpected: " << 102
                        << "\nGot: " << techValues.vaultsPerLayer);

    BOOST_CHECK_MESSAGE( techValues.dramSize == 103*drs::gibibit,
                        "DRAM Size different from the expected."
                        << "\nExpected: " << 103*drs::gibibit
                        << "\nGot: " << techValues.dramSize);

    BOOST_CHECK_MESSAGE( techValues.nBanks == 104*drs::bank,
                        "Number of banks different from the expected."
                        << "\nExpected: " << 104*drs::bank
                        << "\nGot: " << techValues.nBanks);

    BOOST_CHECK_MESSAGE( techValues.Interface == 105,
                        "Interface different from the expected."
                        << "\nExpected: " << 105
                        << "\nGot: " << techValues.Interface);

    BOOST_CHECK_MESSAGE( techValues.dramFreq == 106*drs::megahertz_clock,
                        "DRAM frequency different from the expected."
                        << "\nExpected: " << 106*drs::megahertz_clock
                        << "\nGot: " << techValues.dramFreq);

    BOOST_CHECK_MESSAGE( techValues.dramCoreFreq == 107*drs::megahertz_clock,
                        "DRAM core frequency different from the expected."
                        << "\nExpected: " << 107*drs::megahertz_clock
                        << "\nGot: " << techValues.dramCoreFreq);

    BOOST_CHECK_MESSAGE( techValues.Prefetch == 108,
                        "Prefetch different from the expected."
                        << "\nExpected: " << 108
                        << "\nGot: " << techValues.Prefetch);

    BOOST_CHECK_MESSAGE( techValues.additionalLatencyTrl == 109*drs::clock,
                        "Additional latency to trl different from the expected."
                        << "\nExpected: " << 109*drs::clock
                        << "\nGot: " << techValues.additionalLatencyTrl);

    BOOST_CHECK_MESSAGE( techValues.pageStorage == 110*8*drs::kibibit_per_page,
                        "Page size different from the expected."
                        << "\nExpected: " << 110*8*drs::kibibit_per_page
                        << "\nGot: " << techValues.pageStorage);

    BOOST_CHECK_MESSAGE( techValues.DLL == "111",
                        "DLL flag different from the expected."
                        << "\nExpected: " << "111"
                        << "\nGot: " << techValues.DLL);

    BOOST_CHECK_MESSAGE( techValues.tRef1Required == 112*drs::nanosecond,
                        "Required tRef1 different from the expected."
                        << "\nExpected: " << 112*drs::nanosecond
                        << "\nGot: " << techValues.tRef1Required);

    BOOST_CHECK_MESSAGE( techValues.banksRefreshFactor == 113*drs::bank,
                        "Bank refresh factor different from the expected."
                        << "\nExpected: " << 113*drs::bank
                        << "\nGot: " << techValues.banksRefreshFactor);

    BOOST_CHECK_MESSAGE( techValues.rowRefreshRate == 114,
                        "Row refresh rate different from the expected."
                        << "\nExpected: " << 114
                        << "\nGot: " << techValues.rowRefreshRate);

    BOOST_CHECK_MESSAGE( techValues.subArrayToPageFactor == 115,
                        "Ratio of subarrays activated pro command different from the expected."
                        << "\nExpected: " << 115
                        << "\nGot: " << techValues.subArrayToPageFactor);

    BOOST_CHECK_MESSAGE( techValues.retentionTime == 116*drs::millisecond,
                        "Retention time different from the expected."
                        << "\nExpected: " << 116*drs::millisecond
                        << "\nGot: " << techValues.retentionTime);

    BOOST_CHECK_MESSAGE( techValues.tilesPerBank == 117*drs::tile_per_bank,
                        "Tiles per bank different from the expected."
                        << "\nExpected: " << 117*drs::tile_per_bank
                        << "\nGot: " << techValues.tilesPerBank);

    BOOST_CHECK_MESSAGE( techValues.pageSpanningFactor == 118*drs::page_per_tile,
                        "Pages per bank different from the expected."
                        << "\nExpected: " << 118*drs::page_per_tile
                        << "\nGot: " << techValues.pageSpanningFactor);

    BOOST_CHECK_MESSAGE( techValues.BLArchitecture == "119",
                        "Bitline architecture different from the expected."
                        << "\nExpected: " << "119"
                        << "\nGot: " << techValues.BLArchitecture);
}


BOOST_AUTO_TEST_SUITE_END()

#endif

