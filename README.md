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

Author: Omar Naji, Matthias Jung, Christian Weis, Kamal Haddad, Andre Lucas Chinazzo

## Installing

### Cloning from github (recursive to get submodules!)
``` bash
    git clone --recursive <URL>
```

### Building DRAMSpec

1. To be sure DRAMSpec repository was properly cloned, build and run the program in test mode:

``` bash
    ./runTests.sh
```

2. After getting the "No errors detected" message, you are ready to build DRAMSpec itself. To do that, simply run the [buildDRAMSpec.sh](buildDRAMSpec.sh) script:

``` bash
    ./buildDRAMSpec.sh
```

The executable is now available under `build/release/` by the name `dramspec`.

### Running DRAMSpec

The program expect as parameters (at least) one technology and one achitecture description files. The flags `-t` and `-p` precede the technology and architecture description files, respectively. The optional `-term` flag will include the IO termination currents for read and write operations of the DRAM.

``` bash
    ./build/release/dramspec -t <path/to/technologyfilename> -p <path/to/parameterfilename> [-term]
```

#### Examples:

``` bash
    ./build/release/dramspec -t technology_input/techddr3_5x.json -p architecture_input/parddr3.json
```

It is also possible to run multiple input files at once:

``` bash
    ./build/release/dramspec -t t1.json t2.json -p p1.json p1.json -term
```
Note: the number of technology and architecture description files must be equal.

## Reference
[1] A High-Level DRAM Timing, Power and Area Exploration Tool
O. Naji, A. Hansson, C. Weis, M. Jung, N. Wehn. Accepted for publication, IEEE
International Conference on Embedded Computer Systems Architectures Modeling
and Simulation (SAMOS), July, 2015, Samos Island, Greece

