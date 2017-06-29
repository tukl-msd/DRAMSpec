# DRAMSpec [1]
a DRAM Current and Timing Generator

## LICENSE
Copyright (c) 2015-2017, University of Kaiserslautern
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

DRAMSpec requires some libraries from [boost](http://www.boost.org/). If you do not have it or the version you have is older than the 1.58, please follow the first four (4) steps from their [getting started](http://www.boost.org/doc/libs/1_63_0/more/getting_started/unix-variants.html) section.

### Cloning from github (recursive to get submodules!)
``` bash
    git clone --recursive <URL>
```

### Building DRAMSpec

1. To be sure DRAMSpec repository was properly cloned, build and run the program in test mode either by using the script below or compiling and running the debug version of the program manually. If chosen to do manually, make sure you run the executable directly from within the directory `build/debug`!

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
    ./build/release/dramspec -t <t1.json> <t2.json> -p <p1.json> <p1.json> [-term]
```
Note: the number of technology and architecture description files must be equal.

## Input Data

### DRAM Technology related inputs

| Abbreviation | Description | Unit |
|:------------:|:-----------:|:----:|
||||

### DRAM Architecture related inputs

| Abbreviation | Description | Unit |
|:------------:|:-----------:|:----:|
||||

## Output Data

### Timings [2]

| Abbreviation | Description | Unit |
|:------------:|:-----------:|:----:|
||||
|Frequency|Nominal Synchronous DRAM clock frequency.|MHz|
|Core Frequency| DRAM core clock frequency.|MHz|
|Max Core Frequency|Maximun DRAM core clock frequency.|MHz|
||||
||ESTIMATED ANALOG DELAYS||
|tRCD|Row to Column command Delay. The time interval between row access and data ready at sense amplifiers.|ns|
|tCL or tCAS| Column Access Strobe delay. The time interval between column access command and the start of data return by the DRAM device(s).|ns|
|tRAS|Row Access Strobe delay. The time interval between a row access command and data restoration in a DRAM array.|ns|
|tRP|Row Precharge delay. The time interval that it takes for a DRAM array to be precharged for another row access.|ns|
|tRC|Row Cycle delay. The time interval between accesses to different rows in a bank. tRC = tRAS + tRP.|ns|
|tRL|Read Latency delay. tRL = tCL + tAL, where tAL is the Added Latency to column accesses.|ns|
|tRTP|Read to Precharge delay. The time interval between a read and a precharge command.|ns|
|tCCD|Column-to-Column Delay. The minimum intra-device column-to-column command timing, determined by internal prefetch length.|ns|
|tWR|Write Recovery delay. The minimum time interval between the end of write data burst and the start of a precharge command.|ns|
|tRFC|Refresh Cycle delay. The time interval between Refresh and Activation commands.|ns|
|tREFI|Refresh Interval. Average time interval in between Refresh commands. |ns|
||||
||ESTIMATED LATENCIES <br>(in minimum number of clock cycles)||
|tRCD|Row to Column command Delay latency. The time interval between row access and data ready at sense amplifiers.|cc|
|tCL or tCAS| Column Access Strobe latency. The time interval between column access command and the start of data return by the DRAM device(s).|cc|
|Core tCL or tCAS| Column Access Strobe latency. The time interval between column access command and the start of data return by the DRAM device(s). Given in minimum number of clock cycles of the DRAM core.|cc|
|tRAS|Row Access Strobe latency. The time interval between a row access command and data restoration in a DRAM array.|cc|
|tRP|Row Precharge latency. The time interval that it takes for a DRAM array to be precharged for another row access.|cc|
|tRC|Row Cycle latency. The time interval between accesses to different rows in a bank. tRC = tRAS + tRP.|cc|
|tRL|Read Latency latency. tRL = tCL + tAL, where tAL is the Added Latency to column accesses.|cc|
|Core tRL|Read Latency latency. tRL = tCL + tAL, where tAL is the Added Latency to column accesses.  Given in minimum number of clock cycles of the DRAM core.|cc|
|tRTP|Read to Precharge latency. The time interval between a read and a precharge command.|cc|
|tCCD|Column-to-Column Delay latency. The minimum intra-device column-to-column command timing, determined by internal prefetch length.|cc|
|Core tCCD|Column-to-Column Delay latency. The minimum intra-device column-to-column command timing, determined by internal prefetch length. Given in minimum number of clock cycles of the DRAM core.|cc|
|tWR|Write Recovery latency. The minimum time interval between the end of write data burst and the start of a precharge command.|cc|
|tRFC|Refresh Cycle latency. The time interval between Refresh and Activation commands.|cc|
|tREFI|Refresh Interval latency. Average time interval in between Refresh commands. |cc|

### Currents [3]

| Abbreviation | Description | Unit |
|:------------:|:-----------:|:----:|
||||
|IDD0|Operating One Bank Active-Precharge Current.|mA|
|IDD1|Operating One Bank Active-Read-Precharge Current.|mA|
|IDD2N|Precharge Standby Current|mA|
|IDD3N|Active Standby Current|mA|
|IDD4R|Operating Burst Read Current|mA|
|IDD4W|Operating Burst Write Current|mA|
|IDD5B|Burst Refresh Current|mA|

### Physical sizings

| Abbreviation | Description | Unit |
|:------------:|:-----------:|:----:|
||||
|Subarray height|Height (column direction) of one subarray including sense amplifier.|um|
|Subarray width|Width (row direction) of one subarray including local wordline driver.|um|
|Tile height|Height (column direction) of one tile (bank subsection) including column address decoder.|um|
|Tile width|Width (row direction) of one tile (bank subsection) including row address decoder.|um|
|Bank height|Height (column direction) of one bank including DQ driver.|um|
|Bank width|Width (row direction) of one bank.|um|
|Channel height|Height (column direction) of one channel including TSV if 3D design.|um|
|Channel width|Width (row direction) of one channel.|um|
|Channel area|Area of one channel.|(mm)^2|


## Reference
[1] A High-Level DRAM Timing, Power and Area Exploration Tool,
O. Naji, A. Hansson, C. Weis, M. Jung, N. Wehn.,
IEEE International Conference on Embedded Computer Systems Architectures Modeling and Simulation (SAMOS), July, 2015, Samos Island, Greece

[2] Memory Systems: Cache, DRAM, Disk,
B. Jacob, S. Ng and D. Wang,
Morgan Kaufmann, 2007

[3] DDR3 SDRAM standard (revision F),
JEDEC,
July 2012.
