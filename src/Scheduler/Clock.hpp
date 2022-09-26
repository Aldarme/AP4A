/**
 * @author Timothe Watteau
 * @file Clock.hpp
 * @date 25/09/2022
 * @brief Clock class, to time the log of all the sensors values
 */

#ifndef AP4A_CLOCK_HPP
#define AP4A_CLOCK_HPP

#include "ctime"

class Clock {
private:
	std::clock_t m_clock;

public:
	/**
	 * @brief Orthodox canonical form constructors, destructor and affectation
	 */
	Clock(); // clock is set to t=0 by default
	Clock(const Clock& clock);
	~Clock();
	Clock& operator=(const Clock& clock);

	/**
	 * @brief gives the time since the instantiation of the Clock object
	 * @return the time
	 */
	long getTime() const;
};

#endif //AP4A_CLOCK_HPP
