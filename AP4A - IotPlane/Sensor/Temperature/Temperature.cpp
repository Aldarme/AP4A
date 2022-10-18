/**
 * @author NANMEGNI_NGASSAM
 * @file Temperature.cpp
 * @date 24/09/2022
 * @licence libre
 */
#include "Temperature.hpp"

//FORME CANONIQUE
Temperature::Temperature() : unity("C")
{
}
Temperature::Temperature(const Temperature& temp) : unity(temp.unity)
{
}
Temperature::~Temperature()
{
}
Temperature& Temperature::operator=(const Temperature& temp)
{
  this->unity = temp.unity;
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
