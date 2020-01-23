/*****************************************************************************\

   + hagenPoiseuille.h

   + returns several velocities for HAGEN-POISEUILLE pipe flow 

   + cross-sectional mean velocity
   
   + center line (max.) velocity 

   + daniel feldmann - 10th february 2011

\******************************************************************************/

#ifndef hagenPoiseuille_HEADER
#define hagenPoiseuille_HEADER

// calc cross-sectional mean velocity

double vBarHP(const double R,  const double dx,
	       const double dp, const double nu, const double rho)
{
  
 double vBarHP = 0.0 ;
 vBarHP = R * R * dp/ ( 8.0 * rho * nu * dx ) ; 
 return vBarHP ;
 
}

// calc center line (max.) velocity

double vMaxHP(const double R,  const double dx,
	      const double dp, const double nu, const double rho)
{
  
 double vBarHP = 0.0 ;
 vBarHP = R * R * dp/ ( 4.0 * rho * nu * dx ) ;
 return vBarHP ;
 
}

// calc velocity gradient

double vGradHP(const double R,  const double dx,
	      const double dp, const double nu, const double rho)
{
  
 double vGradBarHP = 0.0 ;
 vGradBarHP = R * dp/ ( 2.0 * rho * nu * dx ) ;
 return vGradBarHP ;
 
}

#endif

/******************************************************************************\
   end of file
\******************************************************************************/