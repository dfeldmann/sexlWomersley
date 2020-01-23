/*****************************************************************************\

   + complexBessel.h

   + returns factorial of k (k!) 

   + returns value Jn(z) of the Bessel function of 1st kind and
     n-th (integer) order for a complex argument z

   + see e.g. [ ABRAMOWITZ - Handbook of mathematical functions (1967) ]

                                    oo
                                  ------   
                                  \          ( -0.25 * z^2 )^k 
           Jn(z) = ( z / 2 )^n  *  \     __________________________  
                                   /
                                  /        k! x gamma( n + k + 1 ) 
                                  ------  
                                   k = 0 
  
   + daniel feldmann - 12th february 2011

\******************************************************************************/

#ifndef complexBessel_HEADER
#define complexBessel_HEADER

#include <cmath>
#include <complex>

// returns value of k!

double factorial(int k)
{

 if ( k > 1 )
 {

  return ( k * factorial ( k - 1 ) ) ;
 }
 else
 {
  return ( 1 );
 }

}

// returns value Jn(z) of the Bessel function

complex<double> complexBessel(complex<double> z, int n)
{

 complex<double> j(0.0, 0.0) ;
 const int oo = 20 ;                                                // maximum k

 if ( ! z.imag() == 0.0 )                                        // complex case
 {
      
  complex<double> a =         pow( 0.5 * z , n) ;            // calc ( z / 2 )^n 
  complex<double> b = -0.25 * pow(       z , 2) ;              // calc -0.25 z^2

  for ( int k = 0; k <= oo ; k++ )                                // sum up loop
  {

   complex<double> c = pow(b, k) ;                     // calc ( -0.25 * z^2 )^k
   
   double d = factorial( k ) ;                                        // calc k!
   double e = exp( gamma( n + k + 1 ) ) ;     // std. gamma returns ln(gamma(x)) 

   j = j + ( c / ( d * e ) ) ;                                         // sum up

  }

  j = a * j ;                                         // multiply by ( z / 2 )^n 

 }
 else                                                               // real case
 {

  j.real() = jn( static_cast<float>(z.real()), n ) ;             // use standard
  j.imag() = 0.0 ;

 }

 return j ;

}

#endif

/******************************************************************************\
   end of file
\******************************************************************************/
