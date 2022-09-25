/**
 * @author Timothe Watteau
 * @file Scheduler.cpp
 * @date 25/09/2022
 * @brief Scheduler class, indicates the frequency of data retrieving and communication with the sensors and the server
 * in order to store and display them.
 */

#include "Scheduler.hpp"

Scheduler::Scheduler() {
	this-> m_clock = *new Clock();
	this-> m_server = *new Server();
}

Scheduler::~Scheduler() = default;

void Scheduler::LaunchScheduler()
{

}