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
	 * @brief Default constructor, sets the clock to 0 seconds
	 */
	Clock();
	/**
	 * @brief Default copy constructor
	 */
	Clock(const Clock& clock);
	/**
	 * @brief Default destructor
	 */
	~Clock();

	/**
	 * @brief gives the time since the instantiation of a Clock object
	 * @return the time
	 */
	long getTime() const;
};

#endif //AP4A_CLOCK_HPP
