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

# DRAMSpec HEADERS and SOURCE files
HEADERS += ../core/Bank.h
HEADERS += ../core/Tile.h
HEADERS += ../core/MemoryArray.h
HEADERS += ../core/SubArray.h
HEADERS += ../core/Current.h
HEADERS += ../core/Timing.h

HEADERS += ../parser/ArgumentsParser.h
HEADERS += ../parser/ResultParser.h
HEADERS += ../parser/TechnologyValues.h
HEADERS += ../parser/DramSpec.h

HEADERS += ../units/NewBaseDimensions.h
HEADERS += ../units/NewDerivedDimensions.h
HEADERS += ../units/NewBaseUnits.h
HEADERS += ../units/NewSystem.h
HEADERS += ../units/NewUnits.h


SOURCES += ../core/Bank.cpp
SOURCES += ../core/Tile.cpp
SOURCES += ../core/MemoryArray.cpp
SOURCES += ../core/SubArray.cpp
SOURCES += ../core/Current.cpp
SOURCES += ../core/Timing.cpp

SOURCES += ../parser/ArgumentsParser.cpp
SOURCES += ../parser/ResultParser.cpp
SOURCES += ../parser/TechnologyValues.cpp
SOURCES += ../parser/DramSpec.cpp

#UNIT TEST using Boost/Test HEADERS and SOURCE files
SOURCES += unit_tests/ArgumentsParserTest.cpp
SOURCES += unit_tests/TechnologyValuesTest.cpp
SOURCES += unit_tests/SubArrayTest.cpp
SOURCES += unit_tests/TileTest.cpp
SOURCES += unit_tests/BankTest.cpp
SOURCES += unit_tests/TimingTest.cpp
SOURCES += unit_tests/CurrentTest.cpp

SOURCES += unit_tests/DramSpecTest.cpp

SOURCES += unitTestRunner.cpp

TARGET = dramspec_unit_test


