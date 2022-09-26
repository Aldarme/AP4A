/**
 * @author Timothe Watteau
 * @file Clock.cpp
 * @date 25/09/2022
 * @brief Clock class, to time the log of all the sensors values
 */

#include "Clock.hpp"

Clock::Clock()
{
	this->m_clock = clock();
}
Clock::Clock(const Clock& clock)
{
	this->m_clock = clock.m_clock;
}
Clock::~Clock() = default;

long Clock::getTime() const {
	return clock() / 1000;
}
