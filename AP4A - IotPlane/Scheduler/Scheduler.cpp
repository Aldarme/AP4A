/**
 * @author NANMEGNI_NGASSAM
 * @file Scheduler.cpp
 * @date 24/09/2022
 * @licence libre
 */
#include "Scheduler.hpp"

// FORME CANONIQUE
Scheduler::Scheduler() 
{
}
Scheduler::Scheduler(const Scheduler& autre) 
{
}
Scheduler::~Scheduler()
{
}
Scheduler& Scheduler::operator=(const Scheduler& autre)
{
}

// AUTRES METHODES
void Scheduler::scheduler( Serveur& DB, Humidity& humidity, Temperature& temp, Light& light, Pression& sound)
{
  // add the unit before sending them to the server
  for(int i=0; i<1 ; i--)
  {
    DB.dataRcv(temp.getData(), humidity.getData(), light.getData(), sound.getData());
  }
}

