/**
 * @author BRICHET_Clement
 * @file Temperature.h
 * @date 23/09/2022
 * @brief This project's goal is to simulate a plane environment with its sensors and retrieve the randomly generated data from the sensors.
 * */

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "Sensor.hpp"
#include <cstdlib>
#include <time.h>

/// @brief A sensor dedicated to checking the air temperature in the plane.
class Temperature: public Sensor<float>
{
    private:
        /// @brief This functions is what allows us to generate a bounded random values that the sensor "detected".
        /// @return A random value between two bounds (defined in the function).
        float aleaGenVal();
    public:
        //Canonic functions
        Temperature();
        Temperature(const Temperature&);
        Temperature& operator=(const Temperature&);
        ~Temperature();
        void setData();
    
    
};

#endif //TEMPERATURE_H