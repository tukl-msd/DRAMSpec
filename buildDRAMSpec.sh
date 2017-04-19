#!/bin/bash

script="`readlink -f "${BASH_SOURCE[0]}"`"
CALLDIR="`dirname "$script"`";
cd ${CALLDIR};

qmake CONFIG+=release DRAMSpec.pro;
echo "Compiling...";
make -s;
echo "Ready!";
