# Copyright (c) 2016, University of Kaiserslautern
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
# 1. Redistributions of source code must retain the above copyright notice,
#    this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# 3. Neither the name of the copyright holder nor the names of its
#    contributors may be used to endorse or promote products derived from
#    this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER
# OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
# PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
# LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
# NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# Author: Matthias Jung, Andr'e Lucas Chinazzo

CONFIG += c++11

mac {
    CONFIG -= app_bundle
    INCLUDEPATH += /opt/boost/include
}

# Newest version of Boost Library
INCLUDEPATH += /users/chinazzo/libs/boost_1_62_0

#DRAMSpec HEADERS
#HEADERS += ../core/Bank.h
HEADERS += ../core/Tile.h
HEADERS += ../core/SubArray.h
#HEADERS += ../core/Current.h
#HEADERS += ../core/Timing.h

HEADERS += ../parser/ArgumentsParser.h
HEADERS += ../parser/TechnologyValues.h
#HEADERS += ../parser/ResultParser.h
#HEADERS += ../parser/DramSpec.h

# Expanded BOOST/UNITS
HEADERS += ../expandedBoostUnits/BaseDimensions/bank.h
HEADERS += ../expandedBoostUnits/BaseDimensions/cell.h
HEADERS += ../expandedBoostUnits/BaseDimensions/clock.h
HEADERS += ../expandedBoostUnits/BaseDimensions/subarray.h
HEADERS += ../expandedBoostUnits/BaseDimensions/tile.h
HEADERS += ../expandedBoostUnits/BaseDimensions/page.h

HEADERS += ../expandedBoostUnits/BaseUnits/bank.h
HEADERS += ../expandedBoostUnits/BaseUnits/cell.h
HEADERS += ../expandedBoostUnits/BaseUnits/clock.h
HEADERS += ../expandedBoostUnits/BaseUnits/subarray.h
HEADERS += ../expandedBoostUnits/BaseUnits/tile.h
HEADERS += ../expandedBoostUnits/BaseUnits/page.h

HEADERS += ../expandedBoostUnits/DerivedDimensions/capacitance_per_bank.h
HEADERS += ../expandedBoostUnits/DerivedDimensions/capacitance_per_cell.h
HEADERS += ../expandedBoostUnits/DerivedDimensions/capacitance_per_length.h
HEADERS += ../expandedBoostUnits/DerivedDimensions/capacitance_per_subarray.h
HEADERS += ../expandedBoostUnits/DerivedDimensions/capacitance_per_tile.h
HEADERS += ../expandedBoostUnits/DerivedDimensions/cell_per_subarray.h
HEADERS += ../expandedBoostUnits/DerivedDimensions/clock_frequency.h
HEADERS += ../expandedBoostUnits/DerivedDimensions/clock_period.h
HEADERS += ../expandedBoostUnits/DerivedDimensions/current_per_frequency.h
HEADERS += ../expandedBoostUnits/DerivedDimensions/information_per_bank.h
HEADERS += ../expandedBoostUnits/DerivedDimensions/information_per_cell.h
HEADERS += ../expandedBoostUnits/DerivedDimensions/information_per_page.h
HEADERS += ../expandedBoostUnits/DerivedDimensions/information_per_subarray.h
HEADERS += ../expandedBoostUnits/DerivedDimensions/information_per_tile.h
HEADERS += ../expandedBoostUnits/DerivedDimensions/length_per_bank.h
HEADERS += ../expandedBoostUnits/DerivedDimensions/length_per_cell.h
HEADERS += ../expandedBoostUnits/DerivedDimensions/length_per_subarray.h
HEADERS += ../expandedBoostUnits/DerivedDimensions/length_per_tile.h
HEADERS += ../expandedBoostUnits/DerivedDimensions/page_per_tile.h
HEADERS += ../expandedBoostUnits/DerivedDimensions/resistance_per_bank.h
HEADERS += ../expandedBoostUnits/DerivedDimensions/resistance_per_cell.h
HEADERS += ../expandedBoostUnits/DerivedDimensions/resistance_per_length.h
HEADERS += ../expandedBoostUnits/DerivedDimensions/resistance_per_subarray.h
HEADERS += ../expandedBoostUnits/DerivedDimensions/resistance_per_tile.h
HEADERS += ../expandedBoostUnits/DerivedDimensions/subarray_per_tile.h
HEADERS += ../expandedBoostUnits/DerivedDimensions/tile_per_bank.h

HEADERS += ../expandedBoostUnits/Units/dramSpec_units.h
HEADERS += ../expandedBoostUnits/Units/bank.h
HEADERS += ../expandedBoostUnits/Units/capacitance_per_bank.h
HEADERS += ../expandedBoostUnits/Units/capacitance_per_cell.h
HEADERS += ../expandedBoostUnits/Units/capacitance_per_length.h
HEADERS += ../expandedBoostUnits/Units/capacitance_per_subarray.h
HEADERS += ../expandedBoostUnits/Units/capacitance_per_tile.h
HEADERS += ../expandedBoostUnits/Units/cell_per_subarray.h
HEADERS += ../expandedBoostUnits/Units/cell.h
HEADERS += ../expandedBoostUnits/Units/clock_frequency.h
HEADERS += ../expandedBoostUnits/Units/clock_period.h
HEADERS += ../expandedBoostUnits/Units/clock.h
HEADERS += ../expandedBoostUnits/Units/current_per_frequency.h
HEADERS += ../expandedBoostUnits/Units/information_per_bank.h
HEADERS += ../expandedBoostUnits/Units/information_per_cell.h
HEADERS += ../expandedBoostUnits/Units/information_per_page.h
HEADERS += ../expandedBoostUnits/Units/information_per_subarray.h
HEADERS += ../expandedBoostUnits/Units/information_per_tile.h
HEADERS += ../expandedBoostUnits/Units/length_per_bank.h
HEADERS += ../expandedBoostUnits/Units/length_per_cell.h
HEADERS += ../expandedBoostUnits/Units/length_per_subarray.h
HEADERS += ../expandedBoostUnits/Units/length_per_tile.h
HEADERS += ../expandedBoostUnits/Units/page_per_tile.h
HEADERS += ../expandedBoostUnits/Units/page.h
HEADERS += ../expandedBoostUnits/Units/resistance_per_bank.h
HEADERS += ../expandedBoostUnits/Units/resistance_per_cell.h
HEADERS += ../expandedBoostUnits/Units/resistance_per_length.h
HEADERS += ../expandedBoostUnits/Units/resistance_per_subarray.h
HEADERS += ../expandedBoostUnits/Units/resistance_per_tile.h
HEADERS += ../expandedBoostUnits/Units/scaled_si_units.h
HEADERS += ../expandedBoostUnits/Units/scaled_information_units.h
HEADERS += ../expandedBoostUnits/Units/subarray_per_tile.h
HEADERS += ../expandedBoostUnits/Units/subarray.h
HEADERS += ../expandedBoostUnits/Units/tile_per_bank.h
HEADERS += ../expandedBoostUnits/Units/tile.h

HEADERS += ../expandedBoostUnits/expanded_make_system.hpp
HEADERS += ../expandedBoostUnits/dramSpecUnitsSystem.h

#DRAMSpec SOURCE files
#SOURCES += ../core/Bank.cpp
SOURCES += ../core/Tile.cpp
SOURCES += ../core/SubArray.cpp
#SOURCES += ../core/Current.cpp
#SOURCES += ../core/Timing.cpp

#DRAMSpec parser source files
SOURCES += ../parser/ArgumentsParser.cpp
SOURCES += ../parser/TechnologyValues.cpp
#SOURCES += ../parser/ResultParser.cpp
#SOURCES += ../parser/DramSpec.cpp

#UNIT TEST using Boost/Test HEADERS and SOURCE files
SOURCES += unit_tests/ArgumentsParserTest.cpp
SOURCES += unit_tests/TechnologyValuesTest.cpp
SOURCES += unit_tests/SubArrayTest.cpp
SOURCES += unit_tests/TileTest.cpp
#SOURCES += unit_tests/BankTest.cpp
#SOURCES += unit_tests/TimingTest.cpp
#SOURCES += unit_tests/CurrentTest.cpp

#SOURCES += unit_tests/DramSpecTest.cpp

SOURCES += unitTestRunner.cpp

TARGET = dramspec_unit_test
