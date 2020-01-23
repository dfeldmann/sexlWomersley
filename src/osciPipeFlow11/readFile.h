/*****************************************************************************\

   + readFile.h

   + open input file
   + initialise variables
   + search keywords and read data

   + daniel feldmann - 9th october 2014

\******************************************************************************/

// open input file

string fileName ;
// cout << " Enter case name : " ;
// cin  >> fileName ;                                             // read base name 
stringstream ioString ;
// ioString << fileName ;
ioString << "case.v11" ;                              // version 6 input file suffix
ioString >> fileName ;
ifstream datFile ;
datFile.open(fileName.c_str()) ;

// initialise input variables

string keyWord ;                                  // search string in input file
double Re = 0.0 ;                                             // Reynolds number
double Wo = 0.0 ;                                            // Womersley number
double A  = 0.0 ;                                          // pressure amplitude
string rsFileName ;                                 // radial position file name
int    nr  = 0;                                   // number of points per radius    
int    nt  = 0;                                    // number of points per cycle
int    wp  = 2;                     // write profile flag (0=no, 1=full, 2=half)
int nCycle = 1;                       // number of full oscillation cycle output
double phaseShift = 0.0;              // phase shift for output ref dpdx cos/sin

// search keywords and read data

if (datFile.is_open())                                             // file good?
{
 while ( ! datFile.eof() )                                       // end of file?
 {  
  datFile >> keyWord ;                                       // read next string

  if ( keyWord == "reynoldsNumber" )
  {
   datFile >> Re ;
   cout << " " << keyWord << " = " << Re << endl ;
  }

  if ( keyWord == "womersleyNumber" )
  {
   datFile >> Wo ;
   cout << " " << keyWord << " = " << Wo << endl ;
  }
  
  if ( keyWord == "pressureAmplitude" )
  {
   datFile >> A ;
   cout << " " << keyWord << " = " << A << endl ;
  }

  if ( keyWord == "rsFileName" )
  {
   datFile >> rsFileName ;
   cout << " " << keyWord << " = " << rsFileName << endl ;
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
   datFile >> wp;
   cout << " " << keyWord << " = " << wp << endl ;
  }

  if ( keyWord == "nCycle" )
  {
   datFile >> nCycle;
   cout << " " << keyWord << " = " << nCycle << endl ;
  }

  if ( keyWord == "phaseShift" )
  {
   datFile >> phaseShift;
   cout << " " << keyWord << " = " << phaseShift <<  " x pi" << endl ;
  }
  
 } 
 datFile.close() ;                                          // close file stream
}
else                                                              // file error!
{ 
 cerr << " No such input file! " << endl ;
 return 1 ;
}

/******************************************************************************\
   end of file
\******************************************************************************/
