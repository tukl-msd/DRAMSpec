#!/bin/bash

qmake CONFIG+=debug DRAMSpec.pro;
make -s;
cd build/debug/;
./dramspec_test;
