/**
 * @author NANMEGNI_NGASSAM
 * @file Temperature.cpp
 * @date 19/10/2022
 * @licence libre
 */
#include "Temperature.hpp"

//FORME CANONIQUE
Temperature::Temperature() : unit(" C"), delay(4)
{
}
Temperature::Temperature(const Temperature& autre) : unit(autre.unit), delay(autre.delay)
{
}
Temperature::Temperature(std::string unit, int delay) : unit(unit), delay(delay)
{
}
Temperature::~Temperature()
{
}
Temperature& Temperature::operator=(const Temperature& autre)
{
  this->unit = autre.unit;
  this->delay = autre.delay;
  return *this;
}

//AUTRES METHODES
float Temperature::aleaGenVal()
{
  //La temperature dans un avion doit etre entre 18 et 27 °C 
  float temp;
  srand(time(NULL));
  temp = (rand()%10) + 17; //valeur entière aléatoire comprise entre 17 et 26
  temp += (rand()%100)/100; // valeur décimale aléatoire comprise entre 0.00 et 0.99 et ajouté à la valeur entiere
  return temp;
}

int Temperature::getDelay()
{
  int valeur = this->delay;
  return valeur;
}
