/*
Sensor.h

Created on:2022/10/01

Author:LI Z1ppo


*/

#ifndef SENSOR_H_
#define SENSOR_H_

#include "stdlib.h"
#include "time.h"

template <class sensorT>

class Sensor
{
protected:
	sensorT m_data;
	int m_frequence;
public:

	Sensor(){m_frequence = 0;};
	virtual ~Sensor(){};
	virtual sensorT getData(){
		this->aleaGenVal();
		return this->m_data;
	};
	virtual sensorT aleaGenVal(){
		return this->m_data;
	};

	virtual int showFrequence(){
		return this->m_frequence;
	}

	virtual void setFrequence(int fr){
		this->m_frequence=fr;
	}
};




#endif /* SENSOR_H_ */
