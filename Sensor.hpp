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

    float aleaGenVal();
    

public:
    Sensor(T p_MIN_VAL, T p_MAX_VAL);

    float getData();
};


/**
 * @brief generate random float between 0 and 1
 * 
 * @tparam T 
 * @return float 
 */
template <typename T>
float Sensor<T>::aleaGenVal()
    {
        return static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    }

/**
 * @brief Construct a new Sensor:: Sensor object sets interval for getData()
 * and inits rand with srand
 * 
 * @param p_MIN_VAL 
 * @param p_MAX_VAL 
 */
template <typename T>
Sensor<T>::Sensor(T p_MIN_VAL, T p_MAX_VAL)
{
    srand(time(NULL));
    m_MIN_VAL = p_MIN_VAL;
    m_MAX_VAL = p_MAX_VAL;
}


/**
 * @brief using aleaGenVal a float is returned in the interval defined by constructor
 * 
 * @tparam T 
 * @return float 
 */
template <typename T>
float Sensor<T>::getData()
    {
        return aleaGenVal() * (m_MAX_VAL - m_MIN_VAL) + m_MIN_VAL;
    }

#endif // SENSOR_H