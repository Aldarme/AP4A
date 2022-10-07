
/**
 * @author Jules Ferlin
 * @file main.cpp
 * @date 03/10/2022
 * @brief Fichier main, avec fonction main qui lance le programme. Se chage juste de déclarer un shceduler et de lancer la simulation
 */




#include <iostream>
#include "scheduler.hpp"

int main()
{
  // Initialise un Scheduler pour ensuite lancer la simulation
  Scheduler s;
  s.startSimulation();
  return 0;
}
