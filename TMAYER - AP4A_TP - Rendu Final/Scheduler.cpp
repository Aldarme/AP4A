/**
 * @author mayer_thibault
 * @file Scheduler.cpp
 * @date 03/10/2022
 * @brief Récupère les données des capteurs
 *        Envoie les données au serveur
 *        Gère les intervalles de temps
 */

#include "Scheduler.hpp"
#include "Data.hpp"
#include "Server.hpp"
#include "Sensor.hpp"

#include <chrono>
#include <thread>
#include <iostream>

Scheduler::Scheduler()
{
	time_t periodT = 2;
	time_t periodL = 3;
	time_t periodH = 4;
	time_t periodP = 1;

	//on crée les capteurs
	m_temperature = Temperature(periodT);
	m_habs = Humidity(periodH);
	m_pressure = Pressure(periodP);
	m_lux = Light(periodL);

	//on crée le serveur
	m_serv = Server();
}

//Run the scheduler
void Scheduler::run()
{
	while(k < 20)
	{
		time_t curentTime = time(0);
		if(curentTime - this->m_temperature.getLastTime() >= this->m_temperature.getMesurePeriod())
		{
				// Mesure
				Data<float> data = m_temperature.getData();
				//On transmet au serveur
				m_serv.writeToFile(m_serv.T, m_temperature.getType(), data.getValue(), data.toString());
				m_serv.consoleWrite(m_temperature.getType(), data.getValue(), data.toString());
		}
		if(curentTime - this->m_habs.getLastTime() >= this->m_habs.getMesurePeriod())
		{
				// Mesure
				Data<float> data = m_habs.getData();
				//On transmet au serveur
				m_serv.writeToFile(m_serv.H, m_habs.getType(), data.getValue(), data.toString());
				m_serv.consoleWrite(m_habs.getType(), data.getValue(), data.toString());
		}
		if(curentTime - this->m_pressure.getLastTime() >= this->m_pressure.getMesurePeriod())
		{
				// Mesure
				Data<int> data = m_pressure.getData();
				//On transmet au serveur
				m_serv.writeToFile(m_serv.P, m_pressure.getType(), data.getValue(), data.toString());
				m_serv.consoleWrite(m_pressure.getType(), data.getValue(), data.toString());
		}
		if(curentTime - this->m_lux.getLastTime() >= this->m_lux.getMesurePeriod())
		{
				// Mesure
				Data<bool> data = m_lux.getData();
				//On transmet au serveur
				m_serv.writeToFile(m_serv.L, m_lux.getType(), data.getValue(), data.toString());
				m_serv.consoleWrite(m_lux.getType(), data.getValue(), data.toString());
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));   //sleep for 1 second
		k++;
	}
};