/**
 * @author Timothe Watteau
 * @file Plane.cpp
 * @date 25/09/2022
 * @brief plane class, ecosystem of the simulation
 */

#include "Plane.hpp"

Plane::Plane() = default;
Plane::Plane(const Plane& plane) = default;
Plane::~Plane() = default;
Plane& Plane::operator=(const Plane &plane) = default;

void Plane::LaunchSimulation(long time)
{
	this->scheduler.LaunchScheduler(time);
}
