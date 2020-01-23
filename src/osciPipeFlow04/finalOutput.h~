/*****************************************************************************\

   + finalOutput.h

   + print to screen

   + print to file (u.osci.dat)
   
   + daniel feldmann - 12th february 2010

\******************************************************************************/
#ifndef finalOutput_HEADER
#define finalOutput_HEADER

 #include "writeFiles.h"

 // print to screen ( osci stuff)
 
 cout << "-----------------------------------------------------------" << endl ;
 cout << left << scientific << setprecision(3)
      << setw(18) << " uCenterLineMax = " 
      << setw(11) << uCenterLineMax
      << left << fixed << setprecision(1)
      << setw(12) << " ->   Re = "
      << setw(5) << ReCenterLine
      << endl ;

 cout << left << scientific << setprecision(3)
      << setw(18) << " uPeak = " 
      << setw(11) << uPeak
      << left << fixed << setprecision(1)
      << setw(12) << " ->   Re = "
      << setw(5) << RePeak
      << endl ;
       
 cout << left << scientific << setprecision(3)
      << setw(18) << " uGradWallMax = " 
      << setw(11) << uGradWallMax
      << left << fixed << setprecision(1)
      << endl ;
      
 cout << left << scientific << setprecision(3)
      << setw(18) << " uTauMax = " 
      << setw(11) << uTauMax
      << left << fixed << setprecision(1)
      << setw(12) << " ->   Re = "
      << setw(5) << ReTau
      << endl ;   

 cout << setw(29) << " "
      << left << fixed << setprecision(1)
      << setw(12) << "      Wo = "
      << setw(5) << Wo
      << endl ;
 
 // print to file ( osci only ) 

 writeOsci( uCenterLine, uMean, uGradWall, uTau, t, nt ) ;

 // print to screen ( ref stuff )
 
 cout << "-----------------------------------------------------------" << endl ;
 cout << " HAGEN-POISEUILLE reference                                " << endl ;
 
 cout << left << scientific << setprecision(3)
      << setw(18) << " uCenterLineMax = " 
      << setw(11) << uCenterLineMaxHP
      << left << fixed << setprecision(1)
      << setw(12) << " ->   Re = "
      << setw(5) << ReCenterLineHP
      << endl ;

 cout << left << scientific << setprecision(3)
      << setw(18) << " uPeak = " 
      << setw(11) << uPeakHP
      << left << fixed << setprecision(1)
      << setw(12) << " ->   Re = "
      << setw(5) << RePeakHP
      << endl ;
      
 cout << left << scientific << setprecision(3)
      << setw(18) << " uGradWallHP = " 
      << setw(11) << uGradWallHP
      << left << fixed << setprecision(1)
      << endl ;
      
 cout << left << scientific << setprecision(3)
      << setw(18) << " uTau = " 
      << setw(11) << uTauHP
      << left << fixed << setprecision(1)
      << setw(12) << " ->   Re = "
      << setw(5) << ReTauHP
      << endl ; 

#endif
  
/******************************************************************************\
   end of file
\******************************************************************************/