#!/bin/bash

script="`readlink -f "${BASH_SOURCE[0]}"`"
CALLDIR="`dirname "$script"`";
cd ${CALLDIR};

qmake CONFIG+=debug DRAMSpec.pro;
make -s;

cd build/debug/;
./dramspec_test;
