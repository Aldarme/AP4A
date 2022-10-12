/**
 * @author mayer_thibault
 * @file Scheduler.hpp
 * @date 04/10/2022
 * @brief Scheduler header
 */
#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

class Scheduler
{
	public:
		Scheduler();
		~Scheduler();
		void sendDataToServer(Server param_serv, Pressure param_p, Light param_l, Humidity param_h, Temperature param_t);
		void getAllCapteursData();
};

#endif