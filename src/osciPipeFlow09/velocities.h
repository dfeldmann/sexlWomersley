/*****************************************************************************\

   + velocities.h

   + returns several velocity properties for given Reynolds number, Womersley
     number, and pressure gradient according to the analytical solution of the
     Navier-Stokes equation for a laminar oscillatory flow of a viscous fluid
     in a rigid straight pipe geometry of constant circular cross-section
     according to SEXL (1930) and WOMERSLEY (1955)
     
   + velocity v at radial position r and time t
   
   + cross-sectional mean velocity vBar at time t
   
   + wall normal velocity gradient vGrad at time t

   + daniel feldmann - 27th january 2014

\******************************************************************************/

#ifndef velocities_HEADER
#define velocities_HEADER

#include "complexBessel.h"

// constants

const double pi = atan2(0.0, -1.0);                                 // define pi 
complex<double> i(0.0, 1.0);                                   // imaginary unit

complex<double> i32(-0.707106781186547, 0.707106781186548);  // i to the three half
complex<double> misqrt(0.707106781186547, -0.707106781186548);  // i to the three half

complex<double> phi(0.0, -pi/2.0);                                // phase shift

// calc velocity

double v(const double Re, const double Wo, const double A,
         const double r, const double t)
{
  
 complex<double> v(0.0, 0.0) ;                                       // velocity
 complex<double> a(0.0, 0.0) ;                                      // amplitude
 complex<double> b(0.0, 0.0) ;                                // Bessel argument
 complex<double> n(0.0, 0.0) ;                                      // numerator
 complex<double> d(0.0, 0.0) ;                                    // denumerator
 complex<double> e(0.0, 0.0) ;                                       // exponent
  
 a = -(A * Re * i) / ( 4.0 *  Wo * Wo);
 b = Wo * misqrt;
 n = complexBessel(2.0 * r * b, 0);                                        // J0
 d = complexBessel(b, 0);                                                  // J0
 e = exp(i * 4.0 * Wo * Wo / Re * t + phi);
 
 // see e.g. WOMERSLEY J. Physiol 127, p. 553-563, (1955)
 v = a * ( 1.0 - ( n / d ) ) * e;                             // velocity, [m/s] 

 return v.real() ;                                        // physically relevant

}

// calc cross-sectional mean velocity

double vBar(const double Re, const double Wo, const double A, const double t)
{
  
 complex<double> vBar(0.0, 0.0) ;               // cross-sectional mean velocity
 complex<double> i(0.0, 1.0) ;                                 // imaginary unit
 complex<double> a(0.0, 0.0) ;                                      // amplitude
 complex<double> b(0.0, 0.0) ;                                // Bessel argument
 complex<double> n(0.0, 0.0) ;                                      // numerator
 complex<double> d(0.0, 0.0) ;                                    // denumerator
 complex<double> e(0.0, 0.0) ;                                       // exponent

 a = -(i * A * Re) / (4.0 *  Wo * Wo);
 b = Wo * misqrt;
 n = 2.0 * Wo * misqrt * complexBessel(b, 1);                              // J1
 d = -i * Wo * Wo * complexBessel(b, 0);                                   // J0
 e = exp(i * 4.0 * Wo * Wo / Re * t + phi);
 
 // see e.g. WOMERSLEY J. Physiol 127, p. 553-563, (1955)
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
 complex<double> i32(-0.707106781186547, 0.707106781186548);  // i to the three half
 complex<double> phi(0.0, -pi/2.0);                                // phase shift
 
//  a = -dp / ( dx * rho * omega ) ;
//  b = sqrt( -i * omega / nu ) ;
//  n = complexBessel( r * b , 1 ) * b ;                                      // J1
//  d = complexBessel( R * b , 0 ) ;                                          // J0
//  e = exp(i * omega * t + phi);
 
 vGrad = a * n / d * e ;                      // deriviative of velocity (dv/dr) 

 return vGrad.real() ;                                    // physically relevant

}


// calc driving pressure gradient

double dpdx(const double Re, const double Wo, const double A, const double t)
{

 complex<double> pGrad(0.0, 0.0);                           // pressure gradient
 complex<double> i(0.0, 1.0);                                  // imaginary unit
 complex<double> a(0.0, 0.0);                                       // amplitude
 complex<double> e(0.0, 0.0);                                        // exponent
 
 a = -(A);
 e = exp(i * 4.0 * Wo * Wo / Re * t + phi);
 
 // see e.g. WOMERSLEY J. Physiol 127, p. 553-563, (1955)
 pGrad = a * e;                                     // pressure gradient, [Pa/m] 
 return pGrad.real();                                     // physically relevant

}

#endif

/******************************************************************************\
   end of file
\******************************************************************************/
