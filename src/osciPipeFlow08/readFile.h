/*****************************************************************************\

   + readFile.h

   + open input file
   + initialise variables
   + search keywords and read data

   + daniel feldmann - 19th march 2012

\******************************************************************************/

// open input file

string fileName ;
cout << " Enter case name : " ;
cin  >> fileName ;                                             // read base name 
stringstream ioString ;
ioString << fileName ;
ioString << ".v8" ;                               // version 8 input file suffix
ioString >> fileName ;
ifstream datFile ;
datFile.open(fileName.c_str()) ;

// initialise input variables

string keyWord ;                                  // search string in input file
double R    = 0.0 ;                                          // pipe radius, [m]
double L    = 0.0 ;                                          // pipe lenght, [m]
int    nr   = 0   ;                          // number of points per radius, [-]    
int    nt   = 0   ;                           // number of points per cycle, [-]
int    wp   = 2   ;                 // write profile flag (0=no, 1=full, 2=half)
double f    = 0.0 ;                               // oscillation frequency, [Hz]
double vTid = 0.0 ;                                       // tidal volume, [m^3]
double nu   = 0.0 ;                              // kinematic viscosity, [m^2/s]
double rho  = 0.0 ;                                         // density, [kg/m^3]

// search keywords and read data

if ( datFile.is_open() )                                           // file good?
{

 while ( ! datFile.eof() )                                       // end of file?
 {
   
  datFile >> keyWord ;                                       // read next string

  if ( keyWord == "pipeRadius" )
  {
   datFile >> R ;
   cout << " " << keyWord << " = " << R << endl ;
  }

  if ( keyWord == "pipeLength" )
  {
   datFile >> L ;
   cout << " " << keyWord << " = " << L << endl ;
  }

  if ( keyWord == "nPointsRadius" )
  {
   datFile >> nr ;
   cout << " " << keyWord << " = " << nr << endl ;
  }

  if ( keyWord == "nPointsCycle" )
  {
   datFile >> nt ;
   cout << " " << keyWord << " = " << nt << endl ;
  }

  if ( keyWord == "writeProfile" )
  {
   datFile >> wp ;
   cout << " " << keyWord << " = " << wp << endl ;
  }

  if ( keyWord == "osciFrequency" )
  {
   datFile >> f ;
   cout << " " << keyWord << " = " << f << endl ;
  }

  if ( keyWord == "tidalVolume" )
  {
   datFile >> vTid ;
   cout << " " << keyWord << " = " << vTid << endl ;
  }

  if ( keyWord == "kinViscosity" )
  {
   datFile >> nu ;
   cout << " " << keyWord << " = " << nu << endl ;
  }

  if ( keyWord == "fluidDensity" )
  {
   datFile >> rho ;
   cout << " " << keyWord << " = " << rho << endl ;
  }

 }
 
 datFile.close() ;                                          // close file stream

}
else                                                              // file error!
{
  
 cerr << " No such file! " << endl ;
 return 1 ;
 
}
  
/******************************************************************************\
   end of file
\******************************************************************************/
