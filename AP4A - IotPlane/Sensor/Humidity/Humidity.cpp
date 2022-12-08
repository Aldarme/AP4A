/**
 * @author NANMEGNI_NGASSAM
 * @file Humidity.cpp
 * @date 19/10/2022
 * @licence libre
 */
#include "Humidity.hpp"

//FORME CANONIQUE
Humidity::Humidity() : unit("g/m3"), delay(2) 
{
}
Humidity::Humidity(const Humidity& autre) : unit(autre.unit), delay(autre.delay)
{
}
Humidity::Humidity(std::string unit, int delay) : unit(unit), delay(delay)
{
}
Humidity::~Humidity()
{
}
Humidity& Humidity::operator=(const Humidity& autre)
{
  this->unit = autre.unit;
  this->delay = autre.delay;
  return *this;
}

//AUTRES METHODES
float Humidity::aleaGenVal()
{
  //L'humidité à bord d'un avion doit être compris entre 13 et 20 g/m3 inclus
  float genVal = 0.0;
  srand(time(NULL));
  
  genVal = (rand()%7) + 13; //Partie entière aléatoire de l'humidité entre 12 et 19
  genVal += (rand()%100)/100; //Partie décimale aléatoire de l'humidité entre 0.00 et 0.99
  return genVal;
}

int Humidity::getDelay()
{
  int valeur = this->delay;
  return valeur;
}