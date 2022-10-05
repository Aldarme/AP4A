/**
 * @author NANMEGNI_NGASSAM
 * @file Sensor.cpp
 * @date 24/09/2022
 * @licence libre
 */
#include "Sensor.hpp"

Sensor::Sensor()
{
}
Sensor::Sensor(const Sensor& autreSensor)
{
}
Sensor::~Sensor()
{
}
Sensor& Sensor::operator=(const Sensor& autreSensor)
{
}
float Sensor::aleaGenVal()
{
  float aleaVal = 0;
  // Géneration d'une variable aléatoire
  srand(time(NULL));
  aleaVal = (rand()%10) +18;//géneration d'une valeur comprise entre 18 et 27
  return aleaVal;
}
float Sensor::getData()
{
  float valeurRecup;
  valeurRecup = aleaGenVal();
  return valeurRecup;
}