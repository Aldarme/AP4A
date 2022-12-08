/**
 * @author NANMEGNI_NGASSAM
 * @file Scheduler.cpp
 * @date 19/10/2022
 * @licence libre
 */
#include "Scheduler.hpp"

using namespace std;

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
void Scheduler::scheduler( Serveur& DB, Humidity& humidity, Temperature& temperature, Light& light, Pression& pression)
{
  //recuperation des frequences des capteurs
  int humidityDelay = humidity.getDelay();
  int lightDelay = light.getDelay();
  int pressionDelay = pression.getDelay();
  int temperatureDelay = temperature.getDelay(); 

  for(int i=0; i > -1 ; i++)
  {
    //Parametrage des temps d'attente des capteurs
    if(i%lightDelay == 0) 
    {
      if(i%pressionDelay == 0)
      {
        if(i%humidityDelay == 0)
        {
          if(i%temperatureDelay == 0)
          {
            DB.dataRcv(temperature.getData(), humidity.getData(), light.getData(), pression.getData());
          }
          else
          {
            DB.dataRcv(0.0, humidity.getData(), light.getData(), pression.getData());
          }//condition recuperation temperature
        }
        else
        {
          DB.dataRcv(0.0, 0.0, light.getData(), pression.getData());
        }// condition recuperation humidite
      }
      else
      {
        DB.dataRcv(0.0, 0.0, light.getData(), 0);
      } // condition recuperation pression
    } //condition recuperation light
  }

}  // fin methode scheduler

