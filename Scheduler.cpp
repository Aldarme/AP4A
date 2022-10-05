/**
 * @author NANMEGNI_NGASSAM
 * @file Scheduler.cpp
 * @date 24/09/2022
 * @licence libre
 */
#include "Scheduler.hpp"

Scheduler::Scheduler() 
{
}
Scheduler::Scheduler(const Scheduler& autreScheduler) 
{
}
Scheduler::~Scheduler()
{
}
Scheduler& Scheduler::operator=(const Scheduler& autreScheduler)
{
}
void Scheduler::scheduler( Serveur& DB, HumiditySensor& humidity, TemperatureSensor& temp, LightSensor& light, SoundSensor& sound)
{
  for(int i=0; i<1000000; i++)
  {
    DB.dataRcv(temp.getData(), humidity.getData(), light.getData(), sound.getData());
  }
}

