/**
 * @author Timothe Watteau
 * @file main.cpp
 * @date 25/09/2022
 * @brief main file
 */

#include "iostream"
#include "ctime"
#include "Scheduler/Scheduler.hpp"

int main()
{
	srand(time(nullptr)); // randomizing the seed

	Scheduler scheduler;

	scheduler.LaunchScheduler();

  return 0;
}