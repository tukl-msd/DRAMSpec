# DRAMSpec - A DRAM Current and Timing Generator

![DRAMSpec](http://www.uni-kl.de/fileadmin/3d-dram/dramSpec.png "DRAMSpec Logo")

If you use **DRAMSpec** in your research, we would appreciate a citation to: 

**A High-Level DRAM Timing, Power and Area Exploration Tool**,
O. Naji, A. Hansson, C. Weis, M. Jung, N. Wehn.,
*IEEE International Conference on Embedded Computer Systems Architectures Modeling and Simulation (SAMOS)*, July, 2015, Samos Island, Greece, [DOI](http://dx.doi.org/10.1109/SAMOS.2015.7363670)

BibTeX:

``` bibtex
@INPROCEEDINGS{DRAMSpec,
author={O. Naji and C. Weis and M. Jung and N. Wehn and A. Hansson},
booktitle={2015 International Conference on Embedded Computer Systems: Architectures, Modeling, and Simulation (SAMOS)},
title={A high-level DRAM timing, power and area exploration tool},
year={2015},
pages={149-156},
keywords={DRAM chips;energy conservation;logic design;memory architecture;microprocessor chips;DDR3;DRAMSpec;energy saving;mobile devices;open source high-level DRAM bank modeling tool;processor designers;servers;Computational modeling;Computer architecture;Delays;Integrated circuit modeling;Performance evaluation;Random access memory},
doi={10.1109/SAMOS.2015.7363670},
month={July},}
```

For more information about our other tools please visit: http://www.uni-kl.de/3d-dram/tools/

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

The program expect as parameters (at least) one technology and one achitecture description files. The flags `-t` and `-p` precede the technology and architecture description files, respectively.

The optional `-term` flag will include the IO termination currents for read and write operations of the DRAM.

For more detailed information on timings, it is possible to print out all internal timing variables using the flag `-internaltimings`.

``` bash
    ./build/release/dramspec -t <path/to/technologyfilename> -p <path/to/parameterfilename> [-term] [-internaltimings]
```

#### Examples:

``` bash
    ./build/release/dramspec -t technology_input/techddr3_5x.json -p architecture_input/parddr3.json
```

It is also possible to run multiple input files at once:

``` bash
    ./build/release/dramspec -t <t1.json> <t2.json> -p <p1.json> <p2.json> [-term] [-internaltimings]
```
Note: the number of technology and architecture description files must be equal.

## Input Data

### DRAM Technology related inputs

| Parameter | Description | Unit |
|:------------:|:-----------:|:----:|
|TechnologyNode|Technology node (not used in any calculation).|um|
|Vdd|Main power supply voltage.|V|
|Vpp|Wordlines HIGH level voltage.|V|
|WireResistance|Wire resistance per length unit (Sheet resistance).|Ohm/mm|
|WireCapacitance|Wire capacitance per length unit (Sheet capacitance).|fF/mm|
|CellCapacitance|Total capacitance of a single cell.|fF|
|CellResistance|Total resistance of a single cell.|KOhm|
|CellWidth|Length in row direction of a single cell.|um|
|CellHeight|Length in column direction of a single cell.|um|
|BitlineCapacitancePerCell|Capacitance due to each cell connected to the local bitline.|aF|
|BitlineResistancePerCell|Resistance due to each cell connected to the local bitline.|Ohm|
|WordlineCapacitancePerCell|Capacitance due to each cell connected to the local wordline.|aF|
|WordlineResistancePerCell|Resistance due to each cell connected to the local wordline.|Ohm|
|PrimarySenseAmpHeight|Lenght in column direction of the primary sense amplifier.|um|
|LocalWordlineDriverWitdh|Lenght in row direction of the local wordline driver.|um|
|LocalWordlineDriverResistance|Output resistance of the local wordline driver.|Ohm|
|RowDecoderWidth|Length in row direction of the row address decoder.|um|
|GlobalWordlineDriverResistance|Output resistance of the global wordline driver.|Ohm|
|SecondarySenseAmpCurrent|Current sinked by the secondary sense amplifier.|uA|
|WriteDriverResistance|Output resistance of the write driver.|Ohm|
|ColumnDecoderHeight|Lenght in column direction of the column address decoder.|um|
|CSLDriverResistance|Output resistance of the column select line driver.|Ohm|
|CSLLoadCapacitance|  |fF|
|GlobalDataLineDriverResistance|Output resistance of the global dataline driver.|Ohm|
|DQDriverHeight|Length in column direction of the DQ driver.|um|
|DQtoTSVWireLength|Length of the wire from DQ main line to TSV connection.|um|
|DQDriverResistance|Output resistance of the DQ driver.|Ohm|
|IDD2NFreqSlope|Slope in relation to operating frequency of the precharge background current.|mA/MHz|
|IDD2NTempAlpha|Alpha coeff. (alpha * (exp(beta * (T - TRef)) - 1)) in relation to operating temperature of the precharge background current.|mA|
|IDD2NTempBeta|Beta coeff. (alpha * (exp(beta * (T - TRef)) - 1)) in relation to operating temperature of the precharge background current.|C^-1|
|IDD2NRefTemp|Ref. temperature (alpha * (exp(beta * (T - TRef)) - 1)) in relation to operating temperature of the precharge background current.|C|
|IDD2NOffset|Constant term of precharge background current. It is IDD2n at 0 MHz and TRef.|mA|
|OCDCurrentSlope|Slope of current sinked by the off-chip driver in relation to operating frequency.|uA/MHz|
|TSVHeight|Length in column direction of TSV area.|um|
|AdditionalTRLLatency|Added latency (tAL [2]) to tCAS resulting in tRL.|cc|
|DriverEnableDelay| Time interval between driving signal to active driver. |ns|
|InOutSSADelay|Signal delay from input to output of the secondary sense amplifier.|ns|
|CommandDecoderDelay|Clock wave pipeline delay for decode and fetch command in the same cycle it is registered.|ns|
|IODelay|I/O interface delay.|ns|
|SSAPrechargeDelay|Secondary sense amplifier precharge delay.|ns|
|tWRMargin|Security margin for Write Recovery.|ns|
|EqualizerDelay|Equalizer circuit enabling delay.|ns|

### DRAM Architecture related inputs

| Parameter | Description | Unit |
|:------------:|:-----------:|:----:|
|DRAMType|DRAM type. Currently only differenciates between DDR or SDR.|-|
|3D|Flag for 3D designs. ON means it is a 3D design.|-|
|DLL|Flag for the usage of Dealy-Locked Loop. ON means the DRAM uses DLL.|-|
|ChannelSize|Data storage capacity of a single channel.|Gbit|
|NumberOfBanksPerChannel|Total number of banks in a single channel.|dimensionless|
|NumberOfHorizontalBanksPerChannel|Number of banks in row direction. Set to 0 (zero) for automatic calculation.|dimensionless|
|NumberOfVerticalBanksPerChannel|Number of banks in a column direction. Set to 0 (zero) for automatic calculation.|dimensionless|
|CellsPerSubarrayRow|Number of cells in row direction in a subarray, including redundace.|dimensionless|
|RedundantCellsPerSubarrayRow|Number of redundant cells in row direction in a subarray.|dimensionless|
|CellsPerSubarrayColumn|Number of cells in column direction in a subarray, including redundance.|dimensionless|
|RedundantCellsPerSubarrayColumn|Number of redundant cells in column direction in a subarray.|dimensionless|
|Interface|Number of datalines of the IO bus. This number is the length of a single data word.|bit|
|Prefetch|Number of prefetched data words for a single read command (RD).|dimensionless|
|Frequency|Nominal Synchronous DRAM clock frequency.|MHz|
|CoreFrequency|DRAM Core clock frequency. Set to 0 (zero) for automatic calculation.|MHz|
|TilesPerBank|Number of tiles (subsections) of a single bank.|dimensionless|
|PageSize|Amount of data sensed after an bank activate command (ACT).|KByte|
|PageSpanningFactor|Percetange of page size sensed on a single bank tile.|dimensionless|
|SubarrayToPageFactor|Ratio between number of cells in a physical row and the page size.|dimensionless|
|BitlineArchitecture|Chosen architecture of bitlines. Can be either OPEN bitlines, or FOLDED bitlines.|-|
|RetentionTime|Minimum amout of time each and every cell must keep its information before being refreshed.|ms|
|tREFI(base)|Base average interval between two AREF commands (1X refresh mode, normal temperature). Please see [4] for reference.|us|
|RefreshMode|Base tREFI divider for effective tREFI [4]. Please use 1, 2, etc, for X1, X2, ect, refresh modes.|dimensionless|
|Temperature|Operating temperature of the device.|C|

## Output Data

### Timings [2]

| Abbreviation | Description | Unit |
|:------------:|:-----------:|:----:|
||||
|Frequency|Nominal Synchronous DRAM clock frequency.|MHz|
|Core Frequency|DRAM core clock frequency.|MHz|
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

### Currents [3, 4]

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

| Parameter | Description | Unit |
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
[1] **A High-Level DRAM Timing, Power and Area Exploration Tool**,
O. Naji, A. Hansson, C. Weis, M. Jung, N. Wehn.,
*IEEE International Conference on Embedded Computer Systems Architectures Modeling and Simulation (SAMOS)*, July, 2015, Samos Island, Greece, [DOI](http://dx.doi.org/10.1109/SAMOS.2015.7363670)

[2] Memory Systems: Cache, DRAM, Disk,
B. Jacob, S. Ng and D. Wang,
Morgan Kaufmann, 2007

[3] DDR3 SDRAM standard (revision F),
JEDEC,
July 2012.

[4] DDR4 SDRAM standard (revision B),
JEDEC,
June 2017.
