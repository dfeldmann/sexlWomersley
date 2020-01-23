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
      << setw(10) << " D = " 
      << setw(10) << D
      << setw(10) << " L = " 
      << setw(10) << L
      << endl ;
 
 cout << left << scientific << setprecision(3)
      << setw(10) << " pAmp = " 
      << setw(10) << pAmp
      << setw(10) << " uAmp = " 
      << setw(10) << uAmp
      << endl ;
      
cout << left << scientific << setprecision(3)
      << setw(10) << " nu = " 
      << setw(10) << nu
      << setw(10) << " rho = " 
      << setw(10) << rho
      << endl ; 
 
 cout << "-----------------------------------------------------------" << endl ;
      
 cout << left << scientific << setprecision(3)
      << setw(18) << " uCenterLineMax = " 
      << setw(11) << uCenterLineMax / uRef
      << left << fixed << setprecision(1)
      << setw(12) << " ->   Re = "
      << setw(5) << ReCenterLine
      << endl ;

 cout << left << scientific << setprecision(3)
      << setw(18) << " uPeak = " 
      << setw(11) << uPeak / uRef
      << left << fixed << setprecision(1)
      << setw(12) << " ->   Re = "
      << setw(5) << RePeak
      << endl ;
       
 cout << left << scientific << setprecision(3)
      << setw(18) << " uGradWallMax = " 
      << setw(11) << uGradWallMax / uRef
      << setw(12) << " ->   y+ = "
      << setw(5) << yPlus
      << endl ;
      
 cout << left << scientific << setprecision(3)
      << setw(18) << " uTauMax = " 
      << setw(11) << uTauMax / uRef
      << left << fixed << setprecision(1)
      << setw(12) << " ->   Re = "
      << setw(5) << ReTau
      << endl ;   

 cout << setw(29) << " "
      << left << fixed << setprecision(2)
      << setw(12) << "      Wo = "
      << setw(5) << Wo
      << endl ;
 
 // print to file ( osci only ) 

 writeOsci( uCenterLine, uMean, uGradWall, uTau, t, nt, uRef) ;

 
 // set reference velocity for HAGEN-POISEUILLE
 
 double uRefHP = uPeakHP ;   // default
 
 if ( vRef == "uTau" )
 {
  uRefHP = uTauHP ;
 }
 
 // print to screen ( ref stuff )
 
 
 cout << "-----------------------------------------------------------" << endl ;
 cout << " HAGEN-POISEUILLE reference                                " << endl ;
 
 cout << left << scientific << setprecision(3)
      << setw(18) << " pAmp = " 
      << setw(11) << pAmpHP
      << endl ;
 
 cout << left << scientific << setprecision(3)
      << setw(18) << " uCenterLine = " 
      << setw(11) << uCenterLineHP / uRef
      << left << fixed << setprecision(1)
      << setw(12) << " ->   Re = "
      << setw(5) << ReCenterLineHP
      << endl ;

 cout << left << scientific << setprecision(3)
      << setw(18) << " uPeak = " 
      << setw(11) << uPeakHP / uRef
      << left << fixed << setprecision(1)
      << setw(12) << " ->   Re = "
      << setw(5) << RePeakHP
      << endl ;

 cout << left << scientific << setprecision(3)
      << setw(18) << " uGradWall = "
      << setw(11) << uGradWallHP / uRef
      << setw(12) << " ->   y+ = "
      << setw(5) << yPlusHP
      << endl ;
      
 cout << left << scientific << setprecision(3)
      << setw(18) << " uTau = " 
      << setw(11) << uTauHP / uRef
      << left << fixed << setprecision(1)
      << setw(12) << " ->   Re = "
      << setw(5) << ReTauHP
      << endl ; 

 cout << setw(29) << " "
      << left << fixed << setprecision(1)
      << setw(12) << "      Wo = "
      << setw(5) << 0.0
      << endl ;

#endif
  
/******************************************************************************\
   end of file
\******************************************************************************/