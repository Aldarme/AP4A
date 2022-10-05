/**
 * @author BRICHET_Clement
 * @file Humidity.h
 * @date 23/09/2022
 * @brief Simulates a humidity captor by giving a random value.
 * */

#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "Sensor.hpp"
#include <cstdlib>
#include <time.h>

class Humidity: public Sensor<float>
{
    private:
        float aleaGenVal();
    public:
        //Canonic functions
        Humidity();
        Humidity(const Humidity&);
        Humidity& operator=(const Humidity&);
        ~Humidity();
        void setData(void);
};

#endif //HUMIDITY_H