/**
 * @author BRICHET_Clement
 * @file Light.h
 * @date 23/09/2022
 * @brief Simulates a light captor by giving a random value.
 * */

#ifndef LIGHT_H
#define LIGHT_H

#include "Sensor.hpp"
#include <cstdlib>
#include <time.h>

class Light: public Sensor<bool>
{
    private:
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