/**
 * @author BRICHET_Clement
 * @file Humidity.h
 * @date 23/09/2022
 * @brief This project's goal is to simulate a plane environment with its sensors and retrieve the randomly generated data from the sensors.
 * */

#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "Sensor.hpp"
#include <cstdlib>
#include <time.h>

/// @brief A sensor dedicated to checking the humidity rate in the plane.
class Humidity: public Sensor<float>
{
    private:
        /// @brief This functions is what allows us to generate a bounded random values that the sensor "detected".
        /// @return A random value between two bounds (defined in the function).
        float aleaGenVal();
    public:
        //Canonic functions
        Humidity();
        Humidity(const Humidity&);
        Humidity& operator=(const Humidity&);
        ~Humidity();

        //Setter
        void setData(void);
};

#endif //HUMIDITY_H