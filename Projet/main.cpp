/**
 * @author mayer_thibault
 * @file main.cpp
 * @date 07/10/2022
 * @brief main file
 */
#include "Server.hpp"
#include "pressure.hpp"
#include "Humidity.hpp"
#include "Light.hpp"
#include "Temperature.hpp"
#include "Scheduler.hpp"
#include <iostream>
#include <chrono>
#include <thread>

//Malgrès quelques heures a essayer de build et compiler le programme, je n'ai pas réussi a le faire fonctionner
//Je regrette de ne pas avoir envoyer de message mais je croyais vraiment que j'allais réussir a le faire fonctionner
//Le rendu final sera fonctionnel et j'espère que vous regarderez tout de même les différentes classes qui expriment
//tout de même mon raisonnement sur ce projet
int main(int argc, char **argv)
{
	Scheduler m_sched;
	//run the scheduler every second
	while (true)
	{
		m_sched.getAllCapteursData();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));   //sleep for 1 second
	}
	return 0;
}