/*****************************************************************************\

   + close.h

   + free memory
   
   + daniel feldmann - 12th february 2010

\******************************************************************************/
#ifndef close_HEADER
#define close_HEADER
 
// free memory

 delete[] r ;
 delete[] u ;
 delete[] uCenterLine ;
 delete[] uGradWall ;
 delete[] uTau ;

 cout << "===========================================================" << endl ;

 return(0) ; 
 
#endif
  
/******************************************************************************\
   end of file
\******************************************************************************/