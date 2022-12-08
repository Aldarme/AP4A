/**
 * @author NANMEGNI_NGASSAM
 * @file Light.cpp
 * @date 24/09/2022
 * @licence libre
 */
#include "Light.hpp"

// FORME CANONIQUE
Light::Light() : unit(""), delay(1) 
{
}
Light::Light(const Light& autre) : unit(autre.unit), delay(autre.delay)
{
}
Light::Light(int delay) : delay(delay)
{
}
Light::~Light()
{
}
Light& Light::operator=(const Light& autre)
{
  this->unit = autre.unit;
  this->delay = autre.delay;
  return *this;
}

// AUTRES METHODES
bool Light::aleaGenVal()// la valeur générée ici est soit vrai(1), soit faux(0)
{
  bool genVal = false;
  srand(time(NULL));
  genVal = (rand()%2); // met dans genVal aléatoirement un 1 ou un 0
  return genVal;
}

int Light::getDelay()
{
  int valeur = this->delay;
  return valeur;
}