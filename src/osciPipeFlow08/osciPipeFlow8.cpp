/*****************************************************************************\

   + osciPipeFlow8.cpp

   + read data from input file ( case.v8 )
   + initialise variables etc
   + calculate pressure amplitude to match predefined peak velocity
   + calculate radial velocity profiles for time t
   + write profile to output files ( u.tttt.dat )
   + calculate several characteristic velocities and parameters
   + final output to file and screen

   + daniel feldmann - 19th march 2012

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
 cout << " Oscillatory pipe flow                       ( Version 8 ) " << endl ;
 cout << "-----------------------------------------------------------" << endl ; 

 // read data from input file

 #include "readFile.h"

 // initialise fields and variabel according to data from file
 
 #include "init.h"

 // find pressure amplitude to match predefined tidal volume
 
 for (int k = 0 ; k < (2) ; ++k )                                  // iteration
 {
  vTidStar = 0.0 ;                             // reset uncorrected tidal volume
  
  for (int l = 0 ; l < (nt + 1) ; ++l )                             // time loop          
  {
   t[l] = l * dt ;                                                // actual time

   // calculate tidal volume from mean velocity

   uMean[l] = vBar( R, L, pAmpStar, omega, t[l], nu, rho) ;
   if ( uMean[l] > 0.0 )                                           // half-cycle
   {
    deltaV   = uMean[l] * A * dt ;                  // temporal volume increment 
    vTidStar = vTidStar + deltaV ;                        // sum up tidal volume
   }

  }

  pAmp = pAmpStar * vTid / vTidStar ;              // correct pressure amplitude
  pAmpStar = pAmp ;

 }


 // main time loop to calcualte Sexl-Womersley flow

 for (int i = 0 ; i < (nt + 1) ; ++i )                       // main (time) loop          
 {

   t[i] = i * dt ;                                                       // time
   
  // calc radial velocity profile
  
  for (int j = 0 ; j < (nr + 1) ; ++j )                           // radial loop
  {
    
   r[j] = j * dr ;                                                   // position
   u[j] = v( r[j], R, L, pAmp, omega, t[i], nu, rho ) ;
       
  }                                                        // end of radial loop

  // write radial velocity profile
   
  writeU( u, r, nr, i, wp) ;

  // calc center line velocity
  
  uCenterLine[i] = v( 0.0, R, L, pAmp, omega, t[i], nu, rho ) ;      // axis r=0
  if ( abs( uCenterLine[i] ) > uCenterLineMax )
  {
   uCenterLineMax = abs( uCenterLine[i] ) ;                     // find max in T
  }
  
  // calc (peak) mean velocity
  
  uMean[i] = vBar( R, L, pAmp, omega, t[i], nu, rho) ;
  if ( abs( uMean[i] ) > uPeak )
  {
   uPeak = abs( uMean[i] ) ;                               // find peak velocity
  }
  
  // calc (max.) velocity gradient at the wall
  
  uGradWall[i] = vGrad( R, R, L, pAmp, omega, t[i], nu, rho) ;       // wall r=R
  if ( abs( uGradWall[i] ) > uGradWallMax )
  {
   uGradWallMax = abs( uGradWall[i] ) ;                         // find max in T
  }

  // calc (max.) friction velocity
  
  uTau[i] = frictionVelocity( uGradWall[i], nu ) ;
  if ( abs( uTau[i] ) > uTauMax )
  {
   uTauMax = abs( uTau[i] ) ;
  }
  
 }                                                    // end fo main (time) loop

 // calc non-dimensionl parameters

 Wo = Womersley( D, omega, nu ) ;
 ReTau = Reynolds( uTauMax, D, nu ) ;
 RePeak = Reynolds( uPeak, D, nu ) ;
 ReCenterLine = Reynolds( uCenterLineMax, D, nu ) ;
 yPlus = D / ReTau ;

 // calc reference ( HAGEN-POISEUILLE flow )
 
//  double uPeakHP        = uPeak ;                          
//  double uCenterLineHP  = 2.0 * uPeakHP ;                    // parabolic profile
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
