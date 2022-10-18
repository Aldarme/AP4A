/**
 * @author NANMEGNI_NGASSAM
 * @file Light.cpp
 * @date 24/09/2022
 * @licence libre
 */
#include "Light.hpp"

// FORME CANONIQUE
Light::Light()
{
}
Light::Light(const Light& autre)
{
}
Light::~Light()
{
}
Light& Light::operator=(const Light& autre)
{
}

// AUTRES METHODES
bool Light::aleaGenVal()// la valeur générée ici est soit vrai(1), soit faux(0)
{
  bool genVal = false;
  srand(time(NULL));
  genVal = (rand()%2); // met dans genVal aléatoirement un 1 ou un 0
  return genVal;
}