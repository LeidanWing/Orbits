#IFNDEF ORBITS_H
#DEF ORBITS_H

#include "dimParam.h"

class Orbit 
{
	
	// Planet properties
	std::string m_planetName;
	dimParam<float> m_mu; // Planet's standard graviational parameter. The product of planet mass times the gravitational constant G
	dimParam<float> r_inf; // Radius of planet's sphere of influence [m]
	
	// Geometric definition of orbit (Orbital elements for a 2D Orbit)
	dimParam<float> m_w; // Argument of periapsis [rad]
	dimParam<float> m_e; // Excentricity [adimensional]
	dimParam<float> m_a; // Semimajor axis [m]
	
	public:
		
		// Constructor
		Orbit (std::string i_planetName, dimParam i_mu, dimParam i_r_inf, dimParam i_w, dimParam i_e, dim_param i_a);
		
		// TODO > Define required functions for the orbital calculation interface
		
}
#ENDIF //ORBITS_H