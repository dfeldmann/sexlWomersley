/*****************************************************************************\

   + close.h

   + free memory
   
   + daniel feldmann - 12th february 2010

\******************************************************************************/
#ifndef close_HEADER
#define close_HEADER
 
// free memory
delete[] t;
delete[] r;
delete[] u;
delete[] uMean;
delete[] uCenterLine;
delete[] tauWall;

// cout << "=============================================================" << endl;
return(0); 

#endif

/******************************************************************************\
   end of file
\******************************************************************************/