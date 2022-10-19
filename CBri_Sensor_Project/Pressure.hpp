/**
 * @author BRICHET_Clement
 * @file Pressure.h
 * @date 23/09/2022
 * @brief This project's goal is to simulate a plane environment with its sensors and retrieve the randomly generated data from the sensors.
 * */

#ifndef PRESSURE_H
#define PRESSURE_H

#include "Sensor.hpp"
#include <cstdlib>
#include <time.h>

/// @brief A sensor dedicated to checking the air pressure in the plane.
class Pressure: public Sensor<int>
{
    private:
        /// @brief This functions is what allows us to generate a bounded random values that the sensor "detected".
        /// @return A random value between two bounds (defined in the function).
        int aleaGenVal();
    public:
        //Canonic functions
        Pressure();
        Pressure(const Pressure&);
        Pressure& operator=(const Pressure&);
        ~Pressure();
        void setData();
};

#endif //PRESSURE_H