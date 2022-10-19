/**
 * @author mayer_thibault
 * @file Scheduler.cpp
 * @date 03/10/2022
 * @brief Récupère les données des capteurs
 *        Envoie les données au serveur
 *        Gère les intervalles de temps
 */

#include "Scheduler.hpp"

//Get all data from sensors
void Scheduler::getAllCapteursData()
{
	m_pressure = m_pressure.getData();
	m_lux = m_lux.getData();
	m_habs = m_habs.getData();
	m_temperature = m_temperature.getData();
	sendDataToServer(m_serv, m_pressure, m_lux, m_habs, m_temperature);
};

//Send data to server
void Scheduler::sendDataToServer(Server param_serv, Pressure param_p, Light param_l, Humidity param_h, Temperature param_t)
{
	param_serv.getData(param_p, param_l, param_h, param_t);
};