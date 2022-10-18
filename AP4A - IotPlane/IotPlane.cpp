/**
 * @author NANMEGNI_NGASSAM
 * @file Simulateur_vol.cpp
 * @date 24/09/2022
 * @licence public
 */
//Inclusion des libraries standards
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
//Inclusion des fichiers propre à mon projet
#include "Sensor/Sensor.hpp"
#include "Sensor/Humidity/Humidity.hpp"
#include "Sensor/Temperature/Temperature.hpp"
#include "Sensor/Light/Light.hpp"
#include "Sensor/Pression/Pression.hpp"
#include "Serveur/Serveur.hpp"
#include "Scheduler/Scheduler.hpp"


using namespace std;

int main()
{
  Serveur db;
  db.dataDisplayParameters(true, true);
  Humidity humidity;
  Temperature temp;
  Light light;
  Pression pression;
  Scheduler timer;
  timer.scheduler(db,humidity,temp,light,pression);
  return 0;
}