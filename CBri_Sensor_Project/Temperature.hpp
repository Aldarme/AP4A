/**
 * @author BRICHET_Clement
 * @file Temperature.h
 * @date 23/09/2022
 * @brief Simulates a temperature captor by giving a random value.
 * */

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "Sensor.hpp"
#include <cstdlib>
#include <time.h>

class Temperature: public Sensor<float>
{
    private:
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