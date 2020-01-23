/*****************************************************************************\

   + velocities.h

   + returns several velocity properties for given Reynolds number, Womersley
     number, and pressure gradient according to the analytical solution of the
     Navier-Stokes equation for a laminar oscillatory flow of a viscous fluid
     in a rigid straight pipe geometry of constant circular cross-section
     according to T.SEXL, Z. Phys. A 61 (1930), p. 349-362
     and J.R.WOMERSLEY, J. Physiol. 127 (1955), p. 553-563
     
   + velocity v at radial position r and time t
   
   + cross-sectional mean velocity vBar at time t
   
   + wall normal velocity gradient vGrad at time t

   + daniel feldmann - 27th january 2014

\******************************************************************************/

#ifndef velocities_HEADER
#define velocities_HEADER

#include "complexBessel.h"

// define constants
const double pi = atan2(0.0, -1.0);                                        // pi 
complex<double> i(0.0, 1.0);                                   // imaginary unit
complex<double> i32(-0.707106781186547, 0.707106781186548);             // i^3/2
complex<double> phi(0.0, -0.0 * pi);                   // phase shift cos to sin

// calculate axial velocity component at one radial position
double v(const double Re, const double Wo, const double A,
         const double r, const double R, const double t)
{
 complex<double> v(0.0, 0.0) ;                                 // axial velocity
 complex<double> a(0.0, 0.0) ;                                      // amplitude
 complex<double> b(0.0, 0.0) ;                                // Bessel argument
 complex<double> n(0.0, 0.0) ;                                      // numerator
 complex<double> d(0.0, 0.0) ;                                    // denumerator
 complex<double> e(0.0, 0.0) ;                                       // exponent
 // see e.g. WOMERSLEY J. Physiol. 127 (1955), p. 553-563
 a = (A * Re) / (i * 4.0 *  Wo * Wo);
 b = i32 * Wo;
 n = complexBessel(b * r / R, 0);                                          // J0
 d = complexBessel(b, 0);                                                  // J0
 e = exp(i * 4.0 * Wo * Wo / Re * t + phi);
 v = a * (1.0 - (n / d)) * e;
 return v.real();                                         // physically relevant
}

// calculate cross-sectional mean (bulk) velocity
double vBar(const double Re, const double Wo, const double A, const double t)
{
 complex<double> vBar(0.0, 0.0) ;                               // bulk velocity
 complex<double> a(0.0, 0.0) ;                                      // amplitude
 complex<double> b(0.0, 0.0) ;                                // Bessel argument
 complex<double> n(0.0, 0.0) ;                                      // numerator
 complex<double> d(0.0, 0.0) ;                                    // denumerator
 complex<double> e(0.0, 0.0) ;                                       // exponent
 // see e.g. WOMERSLEY J. Physiol. 127 (1955), p. 553-563
 a = (A * Re) / (i * 4.0 *  Wo * Wo);
 b = i32 * Wo;
 n = 2.0 * Wo * i32 * complexBessel(b, 1);                                 // J1
 d = -i * Wo * Wo * complexBessel(b, 0);                                   // J0
 e = exp(i * 4.0 * Wo * Wo / Re * t + phi);
 vBar = a * (1.0 - (n / d)) * e;            // integral of v (2/R^2*int(v*r*dr))
 return vBar.real();                                      // physically relevant
}

// calculate shear-stress at one radial position
double taurz(const double Re, const double Wo, const double A,
             const double R, const double r, const double t)
{
 complex<double> tau(0.0, 0.0);                                  // shear-stress
 complex<double> a(0.0, 0.0);                                       // amplitude
 complex<double> b(0.0, 0.0);                                 // Bessel argument
 complex<double> n(0.0, 0.0);                                       // numerator
 complex<double> d(0.0, 0.0);                                     // denumerator
 complex<double> e(0.0, 0.0);                                        // exponent
 a = (-A * R) / (i32 * Wo);   // ????
 b = i32 * Wo;
 n = complexBessel(b * r / R, 1);                                          // J1
 d = complexBessel(b, 0);                                                  // J0
 e = exp(i * 4.0 * Wo * Wo / Re * t + phi);
 tau = a * n / d * e;                   // derivative of velocity (mu * dv/dr) 
 return tau.real();                                       // physically relevant
}


// calculate driving pressure gradient
double dpdx(const double Re, const double Wo, const double A, const double t)
{
 complex<double> pGrad(0.0, 0.0);                           // pressure gradient
 complex<double> a(0.0, 0.0);                                       // amplitude
 complex<double> e(0.0, 0.0);                                        // exponent
  // see e.g. WOMERSLEY J. Physiol 127, p. 553-563, (1955)
 a = -A;                                          // (p1-p2)/l = A*e^(i omega t)
 e = exp(i * 4.0 * Wo * Wo / Re * t + phi);
 pGrad = a * e;                                             // pressure gradient 
 return pGrad.real();                                     // physically relevant
}

#endif

/******************************************************************************\
   end of file
\******************************************************************************/
