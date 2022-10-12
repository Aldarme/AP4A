/**
 * @file main.cpp
 * @author Loric Ravassard
 * @brief lance la simulation
 * @version 1
 * @date 2022-10-05
 */

#include "Server.hpp"
#include "Scheduler.hpp"
#include <iostream>
#include <fstream>
#include <chrono>

/**
 * @brief fonction main qui demande à l'utilisateur le temps de simulation voulu 
 * et lance la simulation
 * 
 * @return int 
 */
int main()
{
  Scheduler simulation;
  int runningTime;
  int waitingTime;

  std::cout << "How much time (in seconds) do you want the simulation to run : ";
  std::cin >> runningTime;
  std::cout << "How much time (in seconds) do you want between 2 send of sensor datas : ";
  std::cin >> waitingTime;
  simulation.run(runningTime, waitingTime);

  return 0;
}