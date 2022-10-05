/**
 * @author NANMEGNI_NGASSAM
 * @file Simulateur_vol.cpp
 * @date 24/09/2022
 * @licence public
 */
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <cstdlib>
#include "Sensor.cpp"
#include "Humidity.cpp"
#include "Temperature.cpp"
#include "Light.cpp"
#include "Sound.cpp"
#include "Serveur.cpp"
#include "Scheduler.cpp"


using namespace std;

int main()
{
  Serveur db;
  db.dataDisplayParameters(true, true);
  HumiditySensor humidity;
  TemperatureSensor temp;
  LightSensor light;
  SoundSensor sound;
  Scheduler timer;
  timer.scheduler(db,humidity,temp,light,sound);
  return 0;
}