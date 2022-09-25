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
	Clock();
	Clock(const Clock& clock);
	~Clock();

	long getTime() const;
};

#endif //AP4A_CLOCK_HPP
