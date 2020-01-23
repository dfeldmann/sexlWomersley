/*****************************************************************************\

   + writeFile.h

   + write radial velocity profile u(r,t) for time step t to file
     filename  : u.tttt.dat
     1st column: radial position (x axis)
     2nd column: velocity        (y axis)

   + write oscillatory velocity properties over time t to file
    filename  : u.osci.dat
    1st column: time                 (t)
    2nd column: center line          (u_cl)
    3rd column: cross-sectional mean (u_bar)
    4th column: wall gradient        (du/dr)
    5th column: friction velocity    (u_tau)

   + daniel feldmann - 21st may 2010

\******************************************************************************/

#ifndef writeFiles_HEADER
#define writeFiles_HEADER

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

// write radial velocity profile u(r,t) for time step t to file

void writeU( double *u, double *r, int nr, int it, int writeProfile, double uRef)
{

 if ( 0 < writeProfile )                              // output file requested ?
 {
 
  stringstream fileString ;
  string       fileName ;
  ofstream     fileStream ;

  // construct file name
 
  fileString.clear() ;                               // delete previous contents
  fileString << "u." ;                                          // set base name
  fileString <<  setfill('0') << setw(4) << it ;          // add time step label
  fileString << ".dat" ;                                           // add suffix
  fileString >> fileName ;

  fileStream.open( fileName.c_str() ) ;

  if ( fileStream )                                                // file good?
  {
 
   fileStream << left << scientific << setprecision(10) << showpos ;   // format
  
   // write values for each radial position
  
   if ( 2 > writeProfile )                            // full profile requested?
   {
    
     for ( int j = nr  ; j > 0; --j )            // complete profile (r = 0..-R)
     {
    
      fileStream << setw(20) << u[j] / uRef ;                        // velocity
      fileStream << setw(20) << -1.0 * r[j] ;                        // position
      fileStream << endl ;
  
     }
   
   }
  
   for ( int j = 0; j < nr + 1; ++j )         // write radial profile (r = 0..R)
   {
    
    fileStream << setw(20) << u[j] / uRef ;                          // velocity
    fileStream << setw(20) << r[j] ;                                 // position
    fileStream << endl ;
  
   }

   fileStream.close() ;

  }
  else                                                               // file bad!
  {
   cerr << " Output error with file: " << fileName << endl ;
  }

 }                                                     // end of output requested

}                                                              // end of function

// write oscillatory velocity properties over time t to file

void writeOsci( double *uCenterLine,  double *uMean, 
		double *uGradWall,    double *uTau,
		double *t, int nt, double uRef )
{

 stringstream fileString ;
 string       fileName ;
 ofstream     fileStream ;

 // construct file name
 
 fileString.clear() ;                                // delete previous contents
 fileString << "u.osci" ;                                       // set base name
 //fileString <<  setfill('0') << setw(4) << it ;         // add time step label
 fileString << ".dat" ;                                            // add suffix
 fileString >> fileName ;

 fileStream.open( fileName.c_str() ) ;

 if ( fileStream )                                                 // file good?
 {
 
  fileStream << left << scientific << setprecision(10) << showpos ;// set format
  
  // write values for each time step
  
  for ( int i = 0; i < nt; ++i )
  {
    
   fileStream << setw(20) << t[i] ;                                      // time
   fileStream << setw(20) << uCenterLine[i] / uRef ;              // center line
   fileStream << setw(20) << uMean[i] / uRef ;           // cross-sectional mean
   fileStream << setw(20) << uGradWall[i] / uRef ;              // wall gradient
   fileStream << setw(20) << uTau[i] / uRef ;               // friction velocity
   fileStream << endl ;
  
  }

  fileStream.close() ;
  cout << " Written file: " << fileName << endl ;

 }
 else                                                               // file bad!
 {
  cerr << " Output error with file: " << fileName << endl ;
 }

}

#endif

/******************************************************************************\
   end of file 
\******************************************************************************/