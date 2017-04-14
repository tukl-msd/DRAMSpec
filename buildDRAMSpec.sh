#!/bin/bash

qmake CONFIG+=release DRAMSpec.pro;
make -s;
