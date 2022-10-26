/**
 * @author mayer_thibault
 * @file Sensor.cpp
 * @date 02/10/2022
 * @brief
 */
#include "Sensor.hpp"

Sensor::Sensor():m_mesurePeriod(1), m_lastTime(0){}; //Constructeur par défaut

//Constructeur par recopie
Sensor::Sensor(const Sensor& s):m_mesurePeriod(s.m_mesurePeriod), m_lastTime(s.m_lastTime){};

Sensor::Sensor(time_t period_p)
{
	this->m_mesurePeriod = period_p;
	this->m_lastTime = time(NULL);
};

time_t Sensor::getLastTime(){
	return this->m_lastTime;
}

time_t Sensor::getMesurePeriod(){
	return this->m_mesurePeriod;
}

void Sensor::updateLastTime(){
	this->m_lastTime = time(0);
}
