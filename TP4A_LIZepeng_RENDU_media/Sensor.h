/*
Sensor.h

Created on:2022/10/01

Author:LI Z1ppo


*/

#ifndef SENSOR_H
#define SENSOR_H

#include"time.h"
#include "stdlib.h"

template<class sensordata>

class Sensor
{
protected:
    sensordata s_data;
    int s_frequence;

public:

    Sensor(){s_frequence = 0;};

    virtual ~Sensor(){};

    virtual sensordata getData()
    {
		this->aleaGenVal();
		return this->s_data;
	};

    virtual sensordata aleaGenVal(){
		return this->s_data;
	};

    virtual int showFrequence(){
		return this->s_frequence;
	}


    virtual void setFrequence(int freq){
		this->s_frequence=freq;
	}
    
};










#endif/*SENSOR_H*/