#ifndef SENSOR_H
#define SENSOR_H

/*
author: Tom PALLEAU
date: 10/1/2022
licence: free
class: Sensor
*/

#include <random>
#include <ctime>

template <typename T=float>
class Sensor
{
protected:
    T m_MIN_VAL;
    T m_MAX_VAL;

    float aleaGenVal()
    {
        return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }
    

public:
    /**
     * @brief Construct a new Sensor:: Sensor object sets interval for getData()
     * 
     * @param p_MIN_VAL 
     * @param p_MAX_VAL 
     */
    Sensor(T p_MIN_VAL, T p_MAX_VAL)
    {
        srand(time(NULL));
        m_MIN_VAL = p_MIN_VAL;
        m_MAX_VAL = p_MAX_VAL;
    }
    float getData()
    {
        return aleaGenVal() * (m_MAX_VAL - m_MIN_VAL) + m_MIN_VAL;
    }
};

#endif // SENSOR_H