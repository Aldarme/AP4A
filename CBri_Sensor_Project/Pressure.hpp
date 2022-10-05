/**
 * @author BRICHET_Clement
 * @file Pressure.h
 * @date 23/09/2022
 * @brief Simulates a pressure captor by giving a random value.
 * */

#ifndef PRESSURE_H
#define PRESSURE_H

#include "Sensor.hpp"
#include <cstdlib>
#include <time.h>

class Pressure: public Sensor<int>
{
    private:
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