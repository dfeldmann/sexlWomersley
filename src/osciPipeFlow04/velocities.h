/*****************************************************************************\

   + velocities.h

   + returns several velocity properties for given fluid/flow properties
     according to the analytical solution of the Navier-Stokes equation for a
     laminar oscillatory flow of a viscous fluid in a rigid straight pipe
     geometry of constant circular cross-section
     
   + velocity v at radial position r and time t
   
   + cross-sectional mean velocity vBar at time t
   
   + wall normal velocity gradient vGrad at time t

   + daniel feldmann - 10th february 2011

\******************************************************************************/

#ifndef velocities_HEADER
#define velocities_HEADER

#include "complexBessel.h"

// calc velocity

double v(const double r,  const double R,     const double dx,
	 const double dp, const double omega, const double t,
	 const double nu, const double rho)
{
  
 complex<double> v(0.0, 0.0) ;                                       // velocity
 complex<double> i(0.0, 1.0) ;                                 // imaginary unit
 complex<double> a(0.0, 0.0) ;                                      // amplitude
 complex<double> b(0.0, 0.0) ;                                // Bessel argument
 complex<double> n(0.0, 0.0) ;                                      // numerator
 complex<double> d(0.0, 0.0) ;                                    // denumerator
 complex<double> e(0.0, 0.0) ;                                       // exponent
 
 a = dp / ( dx * rho * omega ) ;
 b = sqrt( -i * omega / nu ) ;
 n = complexBessel( r * b , 0 ) ;                                          // J0
 d = complexBessel( R * b , 0 ) ;                                          // J0
 e = exp( i * omega * t ) ;
 
 // see e.g. [SCHLICHTING - Boundary layer theory (1979)]
 v = a * ( 1.0 - ( n / d ) ) * e ;                             // velocity,[m/s] 

 return v.real() ;                                        // physically relevant

}

// calc cross-sectional mean velocity

double vBar(const double R,  const double dx,
	    const double dp, const double omega, const double t,
	    const double nu, const double rho)
{
  
 complex<double> vBar(0.0, 0.0) ;               // cross-sectional mean velocity
 complex<double> i(0.0, 1.0) ;                                 // imaginary unit
 complex<double> a(0.0, 0.0) ;                                      // amplitude
 complex<double> b(0.0, 0.0) ;                                // Bessel argument
 complex<double> n(0.0, 0.0) ;                                      // numerator
 complex<double> d(0.0, 0.0) ;                                    // denumerator
 complex<double> e(0.0, 0.0) ;                                       // exponent
 
 a = -dp / ( dx * rho * omega ) ;
 b = sqrt( -i * omega / nu ) ;
 n = 2.0 * complexBessel( R * b , 1 ) ;                                    // J1
 d = R * b * complexBessel( R * b , 0 ) ;                                  // J0
 e = exp( i * omega * t ) ;
  
 vBar = a * ( 1.0 - ( n / d ) ) * e ;       // integral of v (2/R^2*int(v*r*dr)) 

 return vBar.real() ;                                     // physically relevant

}

// calc velocity gradient

double vGrad(const double r,  const double R,     const double dx,
	     const double dp, const double omega, const double t,
	     const double nu, const double rho)
{
  
 complex<double> vGrad(0.0, 0.0) ;              // wall normal velocity gradient
 complex<double> i(0.0, 1.0) ;                                 // imaginary unit
 complex<double> a(0.0, 0.0) ;                                      // amplitude
 complex<double> b(0.0, 0.0) ;                                // Bessel argument
 complex<double> n(0.0, 0.0) ;                                      // numerator
 complex<double> d(0.0, 0.0) ;                                    // denumerator
 complex<double> e(0.0, 0.0) ;                                       // exponent
 
 a = -dp / ( dx * rho * omega ) ;
 b = sqrt( -i * omega / nu ) ;
 n = complexBessel( r * b , 1 ) * b ;                                      // J1
 d = complexBessel( R * b , 0 ) ;                                          // J0
 e = exp( i * omega * t ) ;
 
 vGrad = a * n / d * e ;                      // deriviative of velocity (dv/dr) 

 return vGrad.real() ;                                    // physically relevant

}

#endif

/******************************************************************************\
   end of file
\******************************************************************************/
