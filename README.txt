TransferCalc
------------

Introduction:
TranferCalc is a tool for Kerbal Space Program. It is meant to calculate the required maneuver parameters for a transfer between two stellar bodies in the Kerbal system. It assumes the transfer orbits are done
using Hohmann orbital maneuvers for minimum energy requirements.
This tool is developed for learning purposes, and it is similar in concept to the one found in http://ksp.olex.biz/. This online tool will be used for the validation of TransferCalc.

Main requirements:
- The tool shall calculate, given an origin body, a destination body, and a parking orbit in the origin body:
	- The phase angle between the two bodies.
	- The required delta V for the ejection burn.
	- The ejection angle from the origin body's prograde direction.
- Transfer to all major Kerbal system bodies (planets) shall be supported.
- The tool shall be used through a command line interface as well as a simplistic GUI.

Additional requirements:
- The tool shall be written in C++.
- The tool shall support Windows and Linux platforms.
- The tool shall be modular, and shall be composed of different libraries for each calculation part.
- The tool shall include unit testing for its modules.
- Building and testing shall be automatized using Jenkins. Python scripts will be used to gather results for the tests.

Limitations:
- The orbit inclination of the different bodies is not taken into account. 
- Parking orbit in the origin body is assumed to be circular, and with no inclination.

Possible expansions:
- Calculation of inclination change maneuver (delta V and position in heliocentric orbit).
- Graphical representation of the transfer orbit (3D ?)
- Calculation of circularization delta V at the destination 
- Calculation of transfer orbits to moons
