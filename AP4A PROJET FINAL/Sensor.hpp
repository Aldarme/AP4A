/*
 *  @Author: NDJAMBA BATOMEN GABRIELLA
 *  @file Server.hpp
 *  @Created on: 9 oct. 2022
 *  @Description: Header file of class sensor,parent of light,pressure,temperature,humidity
 */
//#ifndef def_Sensor
//#define def_Sensor
//#include<stdlib.h>
//#include<string>

template<class T>class Sensor
{
protected:
	
	virtual T aleaGenval()=0;
	T ret;
	
public:
	Sensor(){}
	virtual~Sensor(){}
	Sensor(const Sensor &other){}
	virtual T getData()=0;


};

//#endif 
















