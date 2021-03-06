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
      << setw(18) << " pAmp = " 
      << setw(11) << pAmp
      << endl ;
      
 cout << left << scientific << setprecision(6)
      << setw(18) << " pAmp / rho / L = " 
      << setw(11) << pAmp / rho / L
      << endl ;  
 
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
      << setw(12) << " ->   y+ = "
      << setw(5) << yPlus
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

 // print to screen ( ref stuff )
 
//  cout << "-----------------------------------------------------------" << endl ;
//  cout << " HAGEN-POISEUILLE reference                                " << endl ;
//  
//  cout << left << scientific << setprecision(3)
//       << setw(18) << " pAmp = " 
//       << setw(11) << pAmpHP
//       << endl ;
//  
//  cout << left << scientific << setprecision(3)
//       << setw(18) << " uCenterLine = " 
//       << setw(11) << uCenterLineHP
//       << left << fixed << setprecision(1)
//       << setw(12) << " ->   Re = "
//       << setw(5) << ReCenterLineHP
//       << endl ;
// 
//  cout << left << scientific << setprecision(3)
//       << setw(18) << " uPeak = " 
//       << setw(11) << uPeakHP
//       << left << fixed << setprecision(1)
//       << setw(12) << " ->   Re = "
//       << setw(5) << RePeakHP
//       << endl ;
// 
//  cout << left << scientific << setprecision(3)
//       << setw(18) << " uGradWall = "
//       << setw(11) << uGradWallHP
//       << setw(12) << " ->   y+ = "
//       << setw(5) << yPlusHP
//       << endl ;
//       
//  cout << left << scientific << setprecision(3)
//       << setw(18) << " uTau = " 
//       << setw(11) << uTauHP
//       << left << fixed << setprecision(1)
//       << setw(12) << " ->   Re = "
//       << setw(5) << ReTauHP
//       << endl ; 
// 
//  cout << setw(29) << " "
//       << left << fixed << setprecision(1)
//       << setw(12) << "      Wo = "
//       << setw(5) << 0.0
//       << endl ;

// print to file 

 writeOsci( uCenterLine, uMean, uGradWall, uTau, t, nt ) ;
      
#endif
  
/******************************************************************************\
   end of file
\******************************************************************************/