/*
 * Copyright (c) 2017, University of Kaiserslautern
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Authors: Omar Naji,
 *          Matthias Jung,
 *          Christian Weis,
 *          Kamal Haddad,
 *          Andre Lucas Chinazzo
 */



// In this class the current (power) specification of DRAMs is done.
// The class uses already initialized timings to do the calculations.

#ifndef CURRENT_H
#define CURRENT_H

#include "Timing.h"

class Current : public Timing
{
    public:
      Current() : //Empty constructor for test proposes
          Timing()
      {
          currentInitialize();
      }

      Current(const string& technologyFileName,
              const string& architectureFileName,
              const bool IOTerminationCurrentFlag) :
          Timing(technologyFileName, architectureFileName)
      {
          currentInitialize();
          includeIOTerminationCurrent = IOTerminationCurrentFlag;
          try {
              currentCompute();
          }catch (string exceptionMsgThrown){
              throw exceptionMsgThrown;
          }
      }

    // !! Hard-coded values converted to variables !!
    double IDD2nPercentageIfNotDll;
    double vppPumpsEfficiency;
    bu::quantity<drs::milliampere_unit> activeBankLeakage;
    bu::quantity<drs::nanosecond_unit> SSAActiveTime;
    bu::quantity<drs::bit_unit> bitProCSL;

    // Intermediate values added as variables for code cleanness
    double nActiveSubarrays;
    double nLocalBitlines;
    bu::quantity<drs::nanocoulomb_unit> rowAddrsLinesCharge;
    bu::quantity<drs::nanocoulomb_unit> IDD0TotalCharge;
    bu::quantity<drs::nanosecond_unit> effectiveTrc;
    bu::quantity<drs::ampere_unit> IDD0ChargingCurrent;
    bu::quantity<drs::nanocoulomb_unit> IDD1TotalCharge;
    bu::quantity<drs::ampere_unit> IDD1ChargingCurrent;
    bu::quantity<drs::nanocoulomb_unit> colAddrsLinesCharge;
    bu::quantity<drs::nanocoulomb_unit> IDD4TotalCharge;
    bu::quantity<drs::milliampere_unit> ioTermRdCurrent;
    bu::quantity<drs::ampere_unit> IDD4ChargingCurrent;
    bu::quantity<drs::milliampere_unit> ioTermWrCurrent;
    bu::quantity<drs::nanocoulomb_unit> refreshCharge;
    bu::quantity<drs::nanosecond_unit> effectiveTrfc;
    bu::quantity<drs::ampere_unit> IDD5ChargingCurrent;

    // Main variables
    //current IDD0 in mA ( ACT-PRE )
    bu::quantity<drs::milliampere_unit> IDD0;

    //current IDD1 in mA
    bu::quantity<drs::milliampere_unit> IDD1;

    //current IDD4R in mA
    bu::quantity<drs::milliampere_unit> IDD4R;

    //current IDD4W in mA
    bu::quantity<drs::milliampere_unit> IDD4W;

    //Precharge background current
    bu::quantity<drs::milliampere_unit> IDD2n;

    //Rho parameter - refer to:
    // Jung, M. et al, "A New BankSensitive DRAMPower Model for Efficient
    // Design Space Exploration", 2016
    double rho;

    //Active background current
    bu::quantity<drs::milliampere_unit> IDD3n;

    //refresh current
    bu::quantity<drs::milliampere_unit> IDD5;

    //charges for MWL ( Master wordline )
    bu::quantity<drs::nanocoulomb_unit> masterWordlineCharge;

    //charges for LWL ( local wordline )
    bu::quantity<drs::nanocoulomb_unit> localWordlineCharge;

    //charges for Local bitline + blsa
    bu::quantity<drs::nanocoulomb_unit> localBitlineCharge;

    //Number of local DQ lines
    bu::quantity<drs::bit_unit> nLDQs;

    //charges for SSA ( Secondary sense amp )
    bu::quantity<drs::nanocoulomb_unit> SSACharge;

    //Number of CSL + CSLEN lines per bank
    double nCSLs;

    //charges for CSL (column select line )
    bu::quantity<drs::nanocoulomb_unit> CSLCharge;

    //charges for MDL ( master dataline )
    bu::quantity<drs::nanocoulomb_unit> masterDatalineCharge;

    //charges for DQ
    bu::quantity<drs::nanocoulomb_unit> DQWireCharge;

    //charges for reading
    bu::quantity<drs::nanocoulomb_unit> readingCharge;

    //Current per IO pin
    bu::quantity<drs::microampere_per_bit_unit> IddOcdRcv;

    // Termination current flag
    bool includeIOTerminationCurrent;

    void currentInitialize();

    //function for calculation of Background Current
    void backgroundCurrentCalc();

    //function for calculation of IDD0
    void IDD0Calc();

    //function for calculation of IDD1
    void IDD1Calc();

    //function for calculation of IDD4R
    void IDD4RCalc();

    //function for calculation of IDD4W
    void IDD4WCalc();

    //function for calculation of IDD5
    void IDD5Calc();

    void currentCompute();

    //function for printing Currents
    void printCurrent();

};
#endif
