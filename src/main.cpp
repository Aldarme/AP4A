/**
 * @file main.cpp
 * @author Loric Ravassard
 * @brief lance la simulation
 * @version 2
 * @date 2022-10-05
 */

#include "Scheduler.hpp"
#include <iostream>

/**
 * @brief fonction main lance la simulation depuis le Scheduler
 * 
 * @return int 
 */
int main()
{
  Scheduler simulation;

  std::cout << "Press \"q\" and enter to stop the simulation" << std::endl;
  simulation.run();

  return 0;
}