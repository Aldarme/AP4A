/**
 * @author mayer_thibault
 * @file Scheduler.cpp
 * @date 03/10/2022
 * @brief Récupère les données des capteurs
 *        Envoie les données au serveur
 *        Gère les intervalles de temps
 */
#include "Pressure.hpp"
#include "Humidity.hpp"
#include "Light.hpp"
#include "Temperature.hpp"
#include "Server.hpp"
#include <ctime>

class Scheduler
{
	private:
		Pressure m_pressure;
		Light m_lux;
		Humidity m_habs;
		Temperature m_temperature;
		Server m_serv;
	public:
		Scheduler();
		~Scheduler();
		void sendDataToServer(Server param_serv, Pressure param_p, Light param_l, Humidity param_h, Temperature param_t);
		void getAllCapteursData();
};
//ctor
Scheduler::Scheduler()
{

}
//dtor
Scheduler::~Scheduler()
{

}

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