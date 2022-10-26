/**
 * @author mayer_thibault
 * @file main.cpp
 * @date 07/10/2022
 * @brief main file
 */
#include "Scheduler.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	std::cout << "***Initialisation du programme***" << std::endl;
	Scheduler m_sched;
	m_sched.run();
	std::cout << "***Fin programme***" << std::endl;
	return 0;
}