//
// Created by rayan on 26/09/2022.
//

#ifndef UNTITLED72_SENSOR_H
#define UNTITLED72_SENSOR_H
#include <iostream>
#include <cmath>
#include <limits>
#include "../Enum.h"

class SensorBase
{
protected:
    SensorData m_data; // data of the sensor

    /**
     * @brief Random number generator between type min & type max
     * @tparam T type of the random number
     * @return T random number between min & max of the given type
     */
    template <typename T>
    T aleaGenVal()
    {
        T min = std::numeric_limits<T>::min();
        T max = std::numeric_limits<T>::max();
        return aleaGenVal<T>(min, max);
    };

    /**
     * @brief Random number generator in [min, max]
     * @tparam T type of the random number
     */
    template <typename T>
    T aleaGenVal(T min, T max)
    {
        return min + std::fmod(rand(), max - min);
    };

public:
    SensorBase();
    SensorBase(SensorType sT, DataType dT);

    virtual ~SensorBase(){};
    virtual const SensorData& getData() = 0; // default value set to 0
};

template <class T>
class Sensor : public SensorBase
{
protected:
    T m_value;

public:
    Sensor<T>();
    Sensor<T>(SensorType sT, DataType dT) : SensorBase(sT, dT), m_value(){};

    virtual ~Sensor(){};
    virtual const SensorData& getData() = 0;
};

#endif //UNTITLED72_SENSOR_H
