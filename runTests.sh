#!/bin/bash

script="`readlink -f "${BASH_SOURCE[0]}"`"
CALLDIR="`dirname "$script"`";
cd ${CALLDIR};

qmake CONFIG+=debug DRAMSpec.pro;
echo "Compiling...";
make -s;

cd build/debug/;
echo "Testing...";
./dramspec_test;
