/**
 * @author BRICHET_Clement
 * @file Light.h
 * @date 23/09/2022
 * @brief This project's goal is to simulate a plane environment with its sensors and retrieve the randomly generated data from the sensors.
 * */

#ifndef LIGHT_H
#define LIGHT_H

#include "Sensor.hpp"
#include <cstdlib>
#include <time.h>

/// @brief A sensor dedicated to checking if the lights are on in the plane.
class Light: public Sensor<bool>
{
    private:
        /// @brief This functions is what allows us to generate a bounded random values that the sensor "detected".
        /// @return Either 0 or 1
        bool aleaGenVal();
    public:
        //Canonic functions
        Light();
        Light(const Light&);
        Light& operator=(const Light&);
        ~Light();
        void setData();
};

#endif //LIGHT_H