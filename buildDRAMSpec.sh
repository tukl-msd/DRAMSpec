#!/bin/bash

STARTTIME=$(date +%s)

script="`readlink -f "${BASH_SOURCE[0]}"`"
CALLDIR="`dirname "$script"`";
cd ${CALLDIR};

qmake CONFIG+=release DRAMSpec.pro;
echo "Compiling...";
make -s -j4;

ENDTIME=$(date +%s)
echo "Ready after $(($ENDTIME - $STARTTIME)) seconds!";


