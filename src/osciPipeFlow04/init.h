/*****************************************************************************\

   + init.h

   + initialise constants
   + initialise time variables
   + initialise space variables
   + initialise velocity fields and variables
   + initialise non-dimensional parameters
   
   + daniel feldmann - 12th february 2010

\******************************************************************************/
#ifndef init_HEADER
#define init_HEADER

#include <cmath>

// constants

const double pi = atan2(0,-1) ; 

// time stuff

const double omega  = 2.0 * pi * f ;                   // angular frequency, [-]
const double tStart = 0.0 ;                                         // start time, [s]
const double tEnd   = 1.0 / f ;                                       // end time, [s]
const double dt     = tEnd / nt ;                                    // time step, [s]

double *t ;                                                          // time, [s]
t = new double[nt + 1] ;                                         

// spacial stuff

const double rStart = 0.0 ;                              // radial start position, [m]
const double rEnd   = R ;                                  // radial end position, [m]
const double dr     = rEnd / nr ;                                  // radial step, [m]
const double D      = 2.0 * R ;                                       // diameter, [m]

double *r ;                                              // radial position, [m]
r = new double[nr + 1] ;

// velocity stuff

double *u ;                                                   // velocity, [m/s]
u = new double[nr + 1] ;                             
double *uCenterLine ;                             // center line velocity, [m/s]
uCenterLine = new double[nt + 1] ;
double *uMean ;                          // cross-sectional mean velocity, [m/s]
uMean = new double[nt + 1] ;
double *uGradWall ;                             // velocity wall gradient, [1/s]
uGradWall = new double[nt + 1] ;
double *uTau ;                                       // friction velocity, [m/s]
uTau = new double[nt + 1] ;

double uPeak = 0.0 ;                            // peak of mean velocity , [m/s]
double uGradWallMax = 0.0 ;                     // velocity wall gradient, [1/s]
double uTauMax = 0.0 ;                          // max. friction velocity, [m/s]
double uCenterLineMax = 0.0 ;                // max. center line velocity, [m/s]

// non-dimensional parameters

double Wo = 0.0 ;
double ReTau = 0.0 ; 
double RePeak = 0.0 ;
double ReCenterLine = 0.0 ;

#endif
  
/******************************************************************************\
   end of file
\******************************************************************************/