/*
 * Copyright (c) 2015, University of Kaiserslautern
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
 * Authors: Omar Naji, Matthias Jung, Christian Weis
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

      Current(const std::string& techname, const std::string& paraname) :
          Timing(techname, paraname)
      {
          currentInitialize();
          try {
              currentCompute();
          }catch (std::string exceptionMsgThrown){
              throw exceptionMsgThrown;
          }
      }

    bu::quantity<drs::milliampere_page_per_kibibyte_unit> currentPerPageSizeSlope;

    //current IDD0 in mA ( ACT-PRE )
    bu::quantity<drs::milliampere_unit> IDD0;

    //current IDD1 in mA
    bu::quantity<drs::milliampere_unit> IDD1;

    //current IDD4R in mA
    bu::quantity<drs::milliampere_unit> IDD4R;

    //current IDD4W in mA
    bu::quantity<drs::milliampere_unit> IDD4W;

    //background current IDD2n precharge background current
    bu::quantity<drs::milliampere_unit> IDD2n;

    //background current IDD3n active background current
    bu::quantity<drs::milliampere_unit> IDD3n;

    //calculate the refresh current
    bu::quantity<drs::milliampere_unit> IDD5;

    // bool for including IO termination current
    bool includeTerm;

    //charges for MWL ( Master wordline )
    double Q_MWL;

    //charges for LWL ( local wordline )
    double Q_LWL;

    //charges for Local bitline + blsa
    double Q_LBL;

    //charges for SSA ( Secondary sense amp )
    double Q_SSA;

    //charges for CSL (column select line )
    double Q_CSL;

    //charges for MDL ( master dataline )
    double Q_MDL;

    //charges for reading
    double Q_READ;

    //charges for DQ
    double Q_DQ;

    void currentInitialize();

    //function for calculation of Background Current
    void backgroundCurrentCalc();

    //function for calculation of IDD0
    void calcIDD0();

    //function for calculation of IDD1
    void calcIDD1();

    //function for calculation of IDD4R
    void calcIDD4R();

    //function for calculation of IDD4W
    void calcIDD4W();

    //function for calculation of IDD5
    void calcIDD5();

    void currentCompute();

    //function for printing Currents
    void printCurrent();

};
#endif
