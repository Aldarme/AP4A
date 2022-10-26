/**
 * @author mayer_thibault
 * @file Scheduler.hpp
 * @date 04/10/2022
 * @brief Scheduler header
 */
#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

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
		int k = 0;
	public:
		Scheduler();
		void sendDataToServer(Server param_serv, Pressure param_p, Light param_l, Humidity param_h, Temperature param_t);
		void run();
};

#endif