#ifndef TIME__HPP_
#define TIME__HPP_

#include <ctime>
#include "../enum.h"

class Time
{
    friend class Scheduler; // to easily access this class from the scheduler

private:
    TypeSensor m_TypeSensor;
    clock_t m_clock;
    int m_duration; // duration in ms
public:
    Time();
    Time(TypeSensor TypeSensor, int duration);
    ~Time();
    bool checkTime();
};

#endif // TIME__HPP_