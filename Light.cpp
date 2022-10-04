
#include <iostream>
#include <cstdio>
#include "Sensor.hpp"
#include "Light.hpp"
using namespace std;

Light::Light()
{
    min = 0;
    max = 1000;
        
    (*this).value = aleaGenVal();
}

