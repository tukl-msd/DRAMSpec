# DRAMSpec [1]
a DRAM Current and Timing Generator

## LICENSE 
Copyright (c) 2015, University of Kaiserslautern
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

1. Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its
   contributors may be used to endorse or promote products derived from
   this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER
OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

Author: Omar Naji, Matthias Jung, Christian Weis

## Installing

### Cloning from github (recursive to get submodules!)
	git clone --recursive <URL>

### compiling DRAMSpec
	make

### Running DRAMSpec
running DRAMSpec (use -term if you want to add IO termination Current)
If you do not want to add IO termination current than do not add -term
parameter

	./dramspec -t technologyfilename -p parameterfilename -term

#### Example:
	./dramspec -t technology_input/techddr3_5x.json -p architecture_input/parddr3.json

## Reference
[1] A High-Level DRAM Timing, Power and Area Exploration Tool
O. Naji, A. Hansson, C. Weis, M. Jung, N. Wehn. Accepted for publication, IEEE International Conference on Embedded Computer Systems Architectures Modeling and Simulation (SAMOS), July, 2015, Samos Island, Greece
