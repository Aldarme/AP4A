#ifndef SENSOR_H
#define SENSOR_H


#include <iostream>
#include <cstdlib>
#include <time.h>


template <class T> class  Sensor{

    public:    
    T data;

    Sensor<T>(): data(){};
    Sensor<T>(const Sensor<T>& s): data(s.data){};
    T getData();  
    
    virtual T aleaGenVal(T minValue, T maxValue) = 0;
	~Sensor(){};
}
#endif