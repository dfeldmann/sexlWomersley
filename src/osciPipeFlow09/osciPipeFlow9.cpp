/*****************************************************************************\

   + osciPipeFlow9.cpp

   + read data from input file ( case.v9 )
   + read radial positions of flowsi grid from file
   + initialise variables etc
   + calculate pressure amplitude to match predefined peak velocity
   + calculate radial velocity profiles for time t
   + write profile to output files ( u.tttt.dat )
   + calculate several characteristic velocities and parameters
   + final output to file and screen

   + daniel feldmann - 20th december 2011

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
#include "parameters.h"
#include "hagenPoiseuille.h"
#include "writeFiles.h"

int main()
{

 cout << "===========================================================" << endl ;
 cout << " Oscillatory pipe flow                       ( Version 9 ) " << endl ;
 cout << "-----------------------------------------------------------" << endl ; 

 // read data from input file

 #include "readFile.h"

 // initialise fields and variabel according to data from file
 
 #include "init.h"

 cout << "-----------------------------------------------------------" << endl;

 // calc pressure amplitude to match predefined Re and Wo

 for(int k=0; k<3; ++k)                                        // iteration loop
 {
  
 uAmpStar = 0.0;                                                        // reset
 
 for(int l=0; l < (nt + 1); ++l)                                    // time loop          
 {

  t[l] = l * dt;                                                  // actual time
//   cout << t[l] << endl;

  // calc (peak) mean velocity

  uMean[l] = vBar(Re, Wo, AStar, t[l]);
  if (abs(uMean[l]) > uAmpStar)
  {
   uAmpStar = abs(uMean[l]);                               // find peak velocity
  }

 }

 A = AStar * uAmp / uAmpStar;                      // correct pressure amplitude
 
 cout << left << scientific << setprecision(13)
      << " Iteration k = " << k
      << ", A* = "         << AStar
      << ", A  = "         << A
      << ", uPeak* = "     << uAmpStar
      << ", uPeak  = "     << uAmp
      << endl;
 
 AStar = A;
 
 }
 
 // calc several velocity properties
 
 for (int i=0; i < (nt + 1); ++i)                            // main (time) loop          
 {

  t[i] = i * dt;                                                  // actual time
   
  // calc center line velocity
  
  uCenterLine[i] = v(Re, Wo, A, 0.0, t[i]);                          // axis r=0
  if ( abs( uCenterLine[i] ) > uCenterLineMax )
  {
   uCenterLineMax = abs( uCenterLine[i] ) ;                     // find max in T
  }
  
  // calc (peak) mean velocity
  
  uMean[i] = vBar(Re, Wo, A, t[i]);
  if ( abs( uMean[i] ) > uPeak )
  {
   uPeak = abs(uMean[i]);                                  // find peak velocity
  }
  
  // calc (max.) velocity gradient at the wall
  
  uGradWall[i] = 0.0;
  uGradWallMax = 0.0;
//   uGradWall[i] = vGrad( R, R, L, pAmp, omega, t[i], nu, rho) ;       // wall r=R
//   if ( abs( uGradWall[i] ) > uGradWallMax )
//   {
//    uGradWallMax = abs( uGradWall[i] ) ;                         // find max in T
//   }
 
  // calc (max.) friction velocity
  
  uTau[i] = 0.0;
  uTauMax = 0.0;
//   uTau[i] = frictionVelocity( uGradWall[i], nu ) ;
//   if ( abs( uTau[i] ) > uTauMax )
//   {
//    uTauMax = abs( uTau[i] ) ;
//   }
  
  
  // calc (peak) driving pressure gradient
  
  pGrad[i] = dpdx(Re, Wo, A, t[i]);
  if (abs(pGrad[i]) > pGradMax)
  {
   pGradMax = abs(pGrad[i]);                      // find peak pressure gradient
  }
  
 }                                                    // end fo main (time) loop


 // set reference velocity
 
 double uRef = uPeak ;
 
 if ( vRef == "uTau" )
 {
  uRef = uTauMax ;
 }
 
 if ( vRef == "uPeak" )
 {
  uRef = uPeak ;
 }

//  // write radial velocity profile
// 
//  if ( 0 < wp )
//  {
// 
//   for (int i = 0 ; i < (nt + 1) ; ++i )                              // time loop          
//   {
// 
//     t[i] = i * dt ;                                                // actual time
//    
//    // calc radial velocity profile
//   
//    for (int j = 0 ; j < (nr + 1) ; ++j )                           // radial loop
//    {
//     
// //     r[j] = j * dr ;                                            // actual position
//     u[j] = v( r[j], R, L, pAmp, omega, t[i], nu, rho ) ;
//        
//    }                                                        // end of radial loop
//   
//    writeU( u, r, nr, i, wp, uRef, Re, 1440) ;
//   
//   }                                                           // end of time loop
//   
//  }                                                     // end of if write profile
// 
 // calc non-dimensionl parameters

//  ReTau = Reynolds( uTauMax, D, nu ) ;
//  RePeak = Reynolds( uPeak, D, nu ) ;
//  ReCenterLine = Reynolds( uCenterLineMax, D, nu ) ;
//  yPlus = D / ReTau ;

 // calc HAGEN-POISEUILLE flow as reference
 
//  double uPeakHP        = uAmp ;                          // predefined in case.in
//  double uCenterLineHP  = 2.0 * uPeakHP ;                     // parabolic profile
//  double pAmpHP         = dpHP( R, L, uPeakHP, nu, rho ) ;
//  double uGradWallHP    = vGradHP( R, L, pAmpHP, nu, rho ) ;
//  double uTauHP         = frictionVelocity( uGradWallHP, nu ) ;
//  double ReCenterLineHP = Reynolds( uCenterLineHP, D, nu ) ;
//  double RePeakHP       = Reynolds( uPeakHP, D, nu ) ;
//  double ReTauHP        = Reynolds( uTauHP, D, nu ) ;
//  double yPlusHP        = D / ReTauHP ;
 
 // write final output to file and screen
 
 #include "finalOutput.h"
 
 // close main program
 
 #include "close.h"
 
}
/******************************************************************************\
   end of file
\******************************************************************************/
