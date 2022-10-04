#ifndef SENSOR_CPP
#define SENSOR_CPP

#include "Sensor.hpp"



using namespace std;

template <class Type> Type Sensor<Type>::getData()
{
    
    return this->value;

}
         

/**
* @brief Return a ranom number, method changes depending of the type of the class using this method
* @return int for Pression and Temperature, float for Humidity, bool for light
* @param . no parameter but uses template
**/
template <class Type> Type Sensor<Type>::aleaGenVal()
{
   
    int temp_int;
    float temp_float;
    bool temp_bool;

    srand(time(NULL));

    switch (this->type)
    {
    case 0:
    {
        temp_float = (rand() % 101);
        temp_float = temp_float / 100;
        return temp_float;
    }break;
    case 1:
    {
        temp_bool = (rand() %11) < 5;
        return temp_bool;
    }break;
    case 2:
    {
        temp_int = (rand() % 3) + 7;
        return temp_int;
    }break;
    case 3:
    {
        temp_int = (rand() % 6) + 25;
        return temp_int;
    }break;
    default: 
        cout << "ERROR, USE METHOD 'aleaGenVal' ONLY FOR CHILD CLASSES OF SENSOR"<<endl;
        return 0;
        break;
    }



    return 0;
}
#endif





