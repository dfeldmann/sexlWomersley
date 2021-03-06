/*****************************************************************************\

   + readFile.h

   + open input file
   + initialise variables
   + search keywords and read data

   + daniel feldmann - 12th february 2010

\******************************************************************************/

// open input file

string fileName ;
cout << " Enter case name : " ;
cin  >> fileName ;                                             // read base name 
stringstream ioString ;
ioString << fileName ;
ioString << ".v6" ;                               // version 6 input file suffix
ioString >> fileName ;
ifstream datFile ;
datFile.open(fileName.c_str()) ;

// initialise input variables

string keyWord ;                                  // search string in input file
double Re = 0.0 ;                                             // Reynolds number
double Wo = 0.0 ;                                            // Womersley number
int    nr = 0 ;                                   // number of points per radius    
int    nt = 0 ;                                    // number of points per cycle
int    wp = 2 ;                     // write profile flag (0=no, 1=full, 2=half)
string vRef ;                                  // string reference velocity

// search keywords and read data

if ( datFile.is_open() )                                           // file good?
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

  if ( keyWord == "referenceVelocity" )
  {
   datFile >> vRef ;
   cout << " " << keyWord << " = " << vRef << endl ;
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