/*****************************************************************************\

   + init.h

   + initialise constants
   + initialise space variables, read radial points from file, if requested
   + initialise time variables
   + initialise velocity fields and variables
   + initialise non-dimensional parameters
   
   + daniel feldmann - 28th january 2014

\******************************************************************************/
#ifndef init_HEADER
#define init_HEADER

#include <cmath>

// constants

const double pi = atan2(0.0, -1.0);                                 // define pi 

// spatial stuff

const double R      = 0.5;                                   // pipe radius, [m]
const double D      = 2.0 * R;                             // pipe diameter, [m]
const double rStart = 0.0;                         // radial start position, [m]
const double rEnd   = R;                             // radial end position, [m]
const double dr = R / (nr);    // radial increment in case of equidistant grid
double *r;                                               // radial position, [m]
r = new double[nr + 1]; 

// open radial position file

datFile.open(rsFileName.c_str());

// read radial positions from file

if ( datFile.is_open() )                                           // file good?
{
 int ir = 1;                                           // radial postion counter
 while ( ! datFile.eof() )                                       // end of file?
 {
  datFile >> r[ir];                                                      // read 
  ir = ir + 1;                                               // increase counter
 }
 datFile.close();                                           // close file stream
}
else                                                              // file error!
{
 cout << " No such radial position file! " << endl ;
 cout << " Construct " << nr
      << " equidistant points with dr = " << dr
      << endl ;
 for(int j=0; j<(nr+1); ++j)                                        // radial loop
 {
  r[j] = j * dr;                                              // actual position
//   cout << r[j] << endl;
 } 
 
//  return 1 ;

}

// time stuff

const double omega  = 4.0 * Wo * Wo / Re;            // angular frequency, [rad]
const double f      = omega / (2.0 * pi);                     // frequency, [Hz]
const double T      = 1.0 / f;                                    // period, [s]
const double tStart = 0.0 ;                                   // start time, [s]
const double tEnd   = T ;                                       // end time, [s]
const double dt     = tEnd / nt ;                              // time step, [s]

double *t ;                                                         // time, [s]
t = new double[nt + 1] ;                                         

// fluid properties
// 
// const double nu   = pi * D * D / ( 2.0 * T * Wo * Wo ) ;  // kin. visc., [m^2/s]
// const double rho  = 1.0 ;                                   // density, [kg/m^3]

// driving pressure 

double A = 0.0;                                      // final pressure amplitude
double AStar = 1.0;                                             // initial guess
double uAmpStar = 0.0;
const double uAmp = 1;                          // peak of mean velocity , [m/s]

double *pGrad;
pGrad = new double[nt+1];
double pGradMax = 0.0;

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

double *C ;                                                     // amplitude, 
C = new double[nt + 1] ;

double uPeak = 0.0  ;                           // peak of mean velocity , [m/s]
double uGradWallMax = 0.0 ;                     // velocity wall gradient, [1/s]
double uTauMax = 0.0 ;                          // max. friction velocity, [m/s]
double uCenterLineMax = 0.0 ;                // max. center line velocity, [m/s]

// non-dimensional parameters

//double Wo = 0.0 ;                                            // Womersley number
double ReTau = 0.0 ;                        // friction velocity Reynolds number
double RePeak = 0.0 ;                           // peak velocity Reynolds number
double ReCenterLine = 0.0 ;               // max. axial velocity Rexnolds number
double yPlus = 0.0 ;                                               // wall units

#endif
  
/******************************************************************************\
   end of file
\******************************************************************************/