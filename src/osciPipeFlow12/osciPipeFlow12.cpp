/*****************************************************************************\

   + osciPipeFlow12.cpp

   + read data from input file (case.v12)
   + read radial positions from file or create equidistant grid
   + initialise variables etc
   + calculate radial velocity profiles for time t
   + write profile to output files ( u.tttt.dat )
   + calculate several characteristic velocities and parameters
   + final output to file and screen

   + daniel feldmann - 19th february 2015

\******************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <complex>

using namespace std;

#include "velocities.h"
// #include "parameters.h"
// #include "hagenPoiseuille.h"
#include "writeFiles.h"

int main()
{
//  cout << "============================================================" << endl;
//  cout << " Oscillatory pipe flow                         (Version 12) " << endl;
//  cout << "------------------------------------------------------------" << endl; 
 #include "readFile.h"                              // read data from input file
 #include "init.h"           // initialise variabels according to data from file
 
 // calculate phase variation of several properties
 for (int i=0; i < (nt*nCycle + 1); ++i)                     // main (time) loop          
 {
  t[i] = i * dt;                                                  // actual time
  // calc center line velocity
  uCenterLine[i] = v(Re, Wo, A, 0.0, R, t[i]);                       // axis r=0
  if ( abs( uCenterLine[i] ) > uCenterLineMax )
  {
   uCenterLineMax = abs( uCenterLine[i] ) ;                     // find max in T
  }
  // calculate (peak/max) mean (bulk) velocity  
  uMean[i] = vBar(Re, Wo, A, t[i]);
  if (abs(uMean[i]) > uPeak)
  {
   uPeak = abs(uMean[i]);                                  // find peak velocity
  }
  // calc (max.) wall shear stress
  tauWall[i] = taurz(Re, Wo, A, R, R, t[i]);
  if (abs(tauWall[i]) > tauWallMax)
  {
   tauWallMax = abs(tauWall[i]);
  } 
  // calc (peak) driving pressure gradient
  pGrad[i] = dpdx(Re, Wo, A, t[i]);
  if (abs(pGrad[i]) > pGradMax)
  {
   pGradMax = abs(pGrad[i]);                      // find peak pressure gradient
  }
  
 }                                                    // end fo main (time) loop
 
 // calculate ultimate max velocity ratio
 maxVelocityRatio = uCenterLineMax / uPeak ;                  // see finalOutput
 
 // calculate and write radial profiles
 if (0 < wp)
 {
  for (int i = 0; i < (nt * nCycle + 1); ++i)                       // time loop          
  {
   t[i] = i * dt;                                                 // actual time
   for (int j = 0; j < (nr + 1); ++j)                             // radial loop
   {
    u[j] = v(Re, Wo, A, r[j], R, t[i]);                  // velocity
    // shear-stress ???
   }                                                       // end of radial loop
   writeU(u, r, nr, i, t[i], wp);                       // write profile to file
   // writeShearStress ????
  }                                                          // end of time loop
 }                                                    // end of if write profile
 
 #include "finalOutput.h"               // write final output to file and stdout
 #include "close.h"                              // free memory, close programme
}
/******************************************************************************\
   end of file
\******************************************************************************/
