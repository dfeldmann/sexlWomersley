/*****************************************************************************\

   + osciPipeFlow4.cpp

   + read data from input file ( case.in )
   + initialise variables etc.
   + calculate radial velocity profiles for time t
   + write profile to output files ( u.tttt.dat )
   + calculate several characteristic velocities and parameters
   + final output to file and screen

   + daniel feldmann - 19th february 2011

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
 cout << " Oscillatory pipe flow                       ( Version 4 ) " << endl ;
 cout << "-----------------------------------------------------------" << endl ; 

 // read data from input file

 #include "readFile.h"

 // initialise fields and variabel according to data from file
 
 #include "init.h"
 
 for (int i = 0 ; i < (nt + 1) ; ++i )                           // main (time) loop          
 {

   t[i] = i * dt ;                                                // actual time
   
  // calc radial velocity profile
  
  for (int j = 0 ; j < (nr + 1) ; ++j )                               // radial loop
  {
    
   r[j] = j * dr ;                                            // actual position
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

 // calc reference ( HAGEN-POISEUILLE flow )
 
 double uCenterLineMaxHP = vMaxHP(R, L, pAmp, nu, rho) ;
 double uPeakHP          = vBarHP(R, L, pAmp, nu, rho) ;
 double uGradWallHP      = vGradHP(R, L,pAmp, nu, rho) ;
 double uTauHP           = frictionVelocity( uGradWallHP, nu ) ;
 double ReCenterLineHP   = Reynolds( uCenterLineMaxHP, D, nu ) ;
 double RePeakHP         = Reynolds( uPeakHP, D, nu ) ;
 double ReTauHP          = Reynolds( uTauHP, D, nu ) ;
 
 // write final output to file and screen
 
 #include "finalOutput.h"
 
 // close main program
 
 #include "close.h"
 
}
/******************************************************************************\
   end of file
\******************************************************************************/