/**
 * @author Tontsa apala frank
 * @file Scheduler.hpp
 * @date 25/09/2022
 * @brief Scheduler
 */


#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include "Server.hpp"
#include "Sensor.hpp"
#include "Temperature.hpp"
#include "Light.hpp"
#include "Pression.hpp"
#include "Humidity.hpp"

class Scheduler {

private:
	//Implementation d'aggregation et initialisation des differentes classes
	Server m_sev;
	Temperature temp;
	Light lit;
	Pression pres;
	Humidity humi;

public:
	Scheduler();
	virtual ~Scheduler();
	void Store_data();
};

#endif /* SCHEDULER_H_ */
