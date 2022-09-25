/**
 * @author Timothe Watteau
 * @file Plane.hpp
 * @date 25/09/2022
 * @brief plane class, ecosystem of the simulation
 */

#ifndef AP4A_PLANE_HPP
#define AP4A_PLANE_HPP

#include "Scheduler/Scheduler.hpp"

class Plane {
private:
	Scheduler scheduler;

public:
	/**
	 * Default constructor
	 */
	Plane();
	/**
	 * Default copy constructor
	 * @param plane object to copy
	 */
	Plane(const Plane& plane);
	/**
	 * Default destructor
	 */
	~Plane();

	/**
	 * Launches the simulation for a definite time, or indefinite if the time is not specified
	 * @param time time to run the simulation in seconds, optional
	 */
	void LaunchSimulation(long time = 2147483647);
};


#endif //AP4A_PLANE_HPP
