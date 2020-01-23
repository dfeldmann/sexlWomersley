/*****************************************************************************\

   + parameters.h

   + returns several parameters
     
   + Womersley number Wo based on angular frequency and reference lenght

   + Reynolds number Re based on reference velocity and reference lenght
   
   + friction velocity utau based on velocity wall gradient

   + daniel feldmann - 10th february 2011

\******************************************************************************/

#ifndef parameters_HEADER
#define parameters_HEADER

// calc Womersley number

double Womersley(const double lRef, const double omega, const double nu)
{
  
 double Wo = 0.0 ;
 // see e.g. [LOUDON - Use of the Womersley number... (19??)]
 Wo = 0.5 * lRef * sqrt( omega / nu ) ;
 return Wo ;

}

// calc Reynolds number

double Reynolds(const double vRef, const double lRef, const double nu)
{

 double Re = 0.0 ;
 // see e.g. [... (19??)]
 Re = vRef * lRef / nu  ;
 return Re ;

}

// calc friction velocity

double frictionVelocity(const double vGradWall, const double nu)
{

 double vTau = 0.0 ;
 // see e.g. [... (19??)]
 vTau = sqrt( abs( vGradWall ) * nu ) ;                             // omit sign
 vTau = vTau * vGradWall / abs(vGradWall) ;                         //  add sign
 return vTau ;                                        

}

#endif

/******************************************************************************\
   end of file
\******************************************************************************/