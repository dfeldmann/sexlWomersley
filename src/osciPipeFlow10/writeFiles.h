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
void writeU(double *u, double *r, int nr, int it, double t, int writeProfile)
{
 if (0 < writeProfile)                                // output file requested ?
 {
  stringstream fileString ;
  string       fileName ;
  ofstream     fileStream ;
  
  // construct file name and open file
  fileString.clear();                                // delete previous contents
  fileString << "u.";                                           // set base name
  fileString <<  setfill('0') << setw(4) << it;           // add time step label
  fileString << ".dat";                                            // add suffix
  fileString >> fileName;
  fileStream.open(fileName.c_str());

  if (fileStream)                                                  // file good?
  {
   fileStream << left << scientific << setprecision(10) << showpos;    // format
   // write header
   fileStream << "# t = " << t;                       // oscilaltion phase, time
   fileStream << endl;
   fileStream << "# r                 u_z";              // column description
   fileStream << endl;
   
   // write values for each radial position
   if (2 > writeProfile)                              // full profile requested?
   {
    for (int j = nr; j > 0; --j)                    // negative half (r = -R..0)
     {
      fileStream << setw(20) << -1.0 * r[j] ;                        // position
      fileStream << setw(20) << u[j];                                // velocity
      fileStream << endl;
     }
   }
   for (int j = 0; j < nr + 1; ++j)                  // positive half (r = 0..R)
   {
    fileStream << setw(20) << r[j];                                  // position
    fileStream << setw(20) << u[j];                                  // velocity
    fileStream << endl ;
   }
   fileStream.close();                                             // close file
  }
  else                                                              // file bad!
  {
   cerr << " Output error with file: " << fileName << endl;
  }
 }                                                     // end of output requested
}                                                              // end of function



// write oscillatory velocity properties over time t to file
void writeOsci(double *t, double *pGrad,
               double *uMean, double *uCenterLine, 
               double *tauWall, int nt)
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
  fileStream << left << scientific << setprecision(13) << showpos; // set format
  // write header
  fileStream << "# time                 "
             << "amplitude              "
             << "uBulk                  "
             << "uAxis                  "
             << "tauWall                ";                 // column description
  fileStream << endl; 
  
  // write values for each time step
  
  for ( int i = 0; i < nt; ++i )
  {
    
   fileStream << setw(23) << t[i];                                       // time
   fileStream << setw(23) << pGrad[i];                      // pressure gradient
   fileStream << setw(23) << uMean[i];   // cross-sectional mean (bulk) velocity
   fileStream << setw(23) << uCenterLine[i];             // center line velocity
   fileStream << setw(23) << tauWall[i];                    // wall shear-stress
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
