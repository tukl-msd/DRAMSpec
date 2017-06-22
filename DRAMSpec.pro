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
HEADERS += core/SubArray.h
HEADERS += core/Tile.h
HEADERS += core/Bank.h
HEADERS += core/Channel.h
HEADERS += core/Timing.h
HEADERS += core/Current.h

HEADERS += utils/utils.h
HEADERS += parser/ArgumentsParser.h
HEADERS += parser/TechnologyValues.h
HEADERS += parser/DramSpec.h

# Expanded BOOST/UNITS
HEADERS += expandedBoostUnits/BaseDimensions/bank.h
HEADERS += expandedBoostUnits/BaseDimensions/cell.h
HEADERS += expandedBoostUnits/BaseDimensions/clock.h
HEADERS += expandedBoostUnits/BaseDimensions/subarray.h
HEADERS += expandedBoostUnits/BaseDimensions/tile.h
HEADERS += expandedBoostUnits/BaseDimensions/page.h

HEADERS += expandedBoostUnits/BaseUnits/bank.h
HEADERS += expandedBoostUnits/BaseUnits/cell.h
HEADERS += expandedBoostUnits/BaseUnits/clock.h
HEADERS += expandedBoostUnits/BaseUnits/subarray.h
HEADERS += expandedBoostUnits/BaseUnits/tile.h
HEADERS += expandedBoostUnits/BaseUnits/page.h

HEADERS += expandedBoostUnits/DerivedDimensions/capacitance_per_bank.h
HEADERS += expandedBoostUnits/DerivedDimensions/capacitance_per_cell.h
HEADERS += expandedBoostUnits/DerivedDimensions/capacitance_per_length.h
HEADERS += expandedBoostUnits/DerivedDimensions/capacitance_per_subarray.h
HEADERS += expandedBoostUnits/DerivedDimensions/capacitance_per_tile.h
HEADERS += expandedBoostUnits/DerivedDimensions/cell_per_subarray.h
HEADERS += expandedBoostUnits/DerivedDimensions/clock_frequency.h
HEADERS += expandedBoostUnits/DerivedDimensions/clock_period.h
HEADERS += expandedBoostUnits/DerivedDimensions/current_page_per_information.h
HEADERS += expandedBoostUnits/DerivedDimensions/current_per_clock_frequency.h
HEADERS += expandedBoostUnits/DerivedDimensions/information_per_bank.h
HEADERS += expandedBoostUnits/DerivedDimensions/information_per_cell.h
HEADERS += expandedBoostUnits/DerivedDimensions/information_per_page.h
HEADERS += expandedBoostUnits/DerivedDimensions/information_per_subarray.h
HEADERS += expandedBoostUnits/DerivedDimensions/information_per_tile.h
HEADERS += expandedBoostUnits/DerivedDimensions/length_per_bank.h
HEADERS += expandedBoostUnits/DerivedDimensions/length_per_cell.h
HEADERS += expandedBoostUnits/DerivedDimensions/length_per_subarray.h
HEADERS += expandedBoostUnits/DerivedDimensions/length_per_tile.h
HEADERS += expandedBoostUnits/DerivedDimensions/page_per_tile.h
HEADERS += expandedBoostUnits/DerivedDimensions/resistance_per_bank.h
HEADERS += expandedBoostUnits/DerivedDimensions/resistance_per_cell.h
HEADERS += expandedBoostUnits/DerivedDimensions/resistance_per_length.h
HEADERS += expandedBoostUnits/DerivedDimensions/resistance_per_subarray.h
HEADERS += expandedBoostUnits/DerivedDimensions/resistance_per_tile.h
HEADERS += expandedBoostUnits/DerivedDimensions/subarray_per_tile.h
HEADERS += expandedBoostUnits/DerivedDimensions/tile_per_bank.h

HEADERS += expandedBoostUnits/Units/dramSpec_units.h
HEADERS += expandedBoostUnits/Units/bank.h
HEADERS += expandedBoostUnits/Units/capacitance_per_bank.h
HEADERS += expandedBoostUnits/Units/capacitance_per_cell.h
HEADERS += expandedBoostUnits/Units/capacitance_per_length.h
HEADERS += expandedBoostUnits/Units/capacitance_per_subarray.h
HEADERS += expandedBoostUnits/Units/capacitance_per_tile.h
HEADERS += expandedBoostUnits/Units/cell_per_subarray.h
HEADERS += expandedBoostUnits/Units/cell.h
HEADERS += expandedBoostUnits/Units/clock_frequency.h
HEADERS += expandedBoostUnits/Units/clock_period.h
HEADERS += expandedBoostUnits/Units/clock.h
HEADERS += expandedBoostUnits/Units/current_page_per_information.h
HEADERS += expandedBoostUnits/Units/current_per_clock_frequency.h
HEADERS += expandedBoostUnits/Units/information_per_bank.h
HEADERS += expandedBoostUnits/Units/information_per_cell.h
HEADERS += expandedBoostUnits/Units/information_per_page.h
HEADERS += expandedBoostUnits/Units/information_per_subarray.h
HEADERS += expandedBoostUnits/Units/information_per_tile.h
HEADERS += expandedBoostUnits/Units/length_per_bank.h
HEADERS += expandedBoostUnits/Units/length_per_cell.h
HEADERS += expandedBoostUnits/Units/length_per_subarray.h
HEADERS += expandedBoostUnits/Units/length_per_tile.h
HEADERS += expandedBoostUnits/Units/page_per_tile.h
HEADERS += expandedBoostUnits/Units/page.h
HEADERS += expandedBoostUnits/Units/resistance_per_bank.h
HEADERS += expandedBoostUnits/Units/resistance_per_cell.h
HEADERS += expandedBoostUnits/Units/resistance_per_length.h
HEADERS += expandedBoostUnits/Units/resistance_per_subarray.h
HEADERS += expandedBoostUnits/Units/resistance_per_tile.h
HEADERS += expandedBoostUnits/Units/scaled_si_units.h
HEADERS += expandedBoostUnits/Units/scaled_information_units.h
HEADERS += expandedBoostUnits/Units/subarray_per_tile.h
HEADERS += expandedBoostUnits/Units/subarray.h
HEADERS += expandedBoostUnits/Units/tile_per_bank.h
HEADERS += expandedBoostUnits/Units/tile.h

HEADERS += expandedBoostUnits/expanded_make_system.hpp
HEADERS += expandedBoostUnits/dramSpecUnitsSystem.h

#DRAMSpec SOURCE files
SOURCES += core/SubArray.cpp
SOURCES += core/Tile.cpp
SOURCES += core/Bank.cpp
SOURCES += core/Channel.cpp
SOURCES += core/Timing.cpp
SOURCES += core/Current.cpp

#DRAMSpec other source files
SOURCES += utils/utils.cpp
SOURCES += parser/ArgumentsParser.cpp
SOURCES += parser/TechnologyValues.cpp
SOURCES += parser/DramSpec.cpp

#Choose output directories
# and source files to be compiled
# according to the compilation mode
CONFIG(release, debug|release) {
    message(Release build!) #See messege at "General Messages" tab
    DESTDIR = build/release
    OBJECTS_DIR = build/release/.obj
    MOC_DIR = build/release/.moc
    RCC_DIR = build/release/.rcc
    UI_DIR = build/release/.ui

    QMAKE_CXXFLAGS += -Wextra -Wall

    SOURCES += main.cpp

    TARGET = dramspec
}

CONFIG(debug, debug|release) {
    message(Debug build!) #See messege at "General Messages" tab
    DESTDIR = build/debug
    OBJECTS_DIR = build/debug/.obj
    MOC_DIR = build/debug/.moc
    RCC_DIR = build/debug/.rcc
    UI_DIR = build/debug/.ui

    QMAKE_CXXFLAGS += -w

    #UNIT TEST using Boost/Test HEADERS and SOURCE files // Degub only
    SOURCES += unit_tests/unit_tests/ArgumentsParserTest.cpp
    SOURCES += unit_tests/unit_tests/TechnologyValuesTest.cpp
    SOURCES += unit_tests/unit_tests/SubArrayTest.cpp
    SOURCES += unit_tests/unit_tests/TileTest.cpp
    SOURCES += unit_tests/unit_tests/BankTest.cpp
    SOURCES += unit_tests/unit_tests/ChannelTest.cpp
    SOURCES += unit_tests/unit_tests/TimingTest.cpp
    SOURCES += unit_tests/unit_tests/CurrentTest.cpp
    #SOURCES += unit_tests/unit_tests/DramSpecTest.cpp

    SOURCES += unit_tests/unitTestRunner.cpp

    TARGET = dramspec_test

}

OTHER_FILES += technology_input/*
OTHER_FILES += architecture_input/*
OTHER_FILES += Makefile
OTHER_FILES += README.md
OTHER_FILES += runTests.sh
OTHER_FILES += buildDRAMSpec.sh

