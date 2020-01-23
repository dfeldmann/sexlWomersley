/*****************************************************************************\

   + hagenPoiseuille.h

   + returns several properties for HAGEN-POISEUILLE pipe flow 

   + cross-sectional mean velocity
   
   + center line (max.) velocity
   
   + pressure gradient

   + daniel feldmann - 22nd february 2011

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

// calc axial driving pressure

double dpHP(const double R, const double dx,
	    const double uMean, const double nu, const double rho)
{
  
 double dpHP = 0.0 ;
 dpHP = 8.0 * uMean * rho * nu * dx / ( R * R ) ;
 return dpHP ;
 
}

#endif

/******************************************************************************\
   end of file
\******************************************************************************/