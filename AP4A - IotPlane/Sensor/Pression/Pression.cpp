/**
 * @author NANMEGNI_NGASSAM
 * @file Pression.cpp
 * @date 19/10/2022
 * @licence libre
 */
#include "Pression.hpp"

//FORME CANONIQUE
Pression::Pression() : unit("Pa"), delay(2) 
{
}
Pression::Pression(const Pression& autre) : unit(autre.unit), delay(autre.delay)
{
}
Pression::Pression(std::string unit, int delay) : unit(unit), delay(delay)
{
}
Pression::~Pression()
{
}
Pression& Pression::operator=(const Pression& autre)
{
  this->unit = autre.unit;
  this->delay = autre.delay;
  return *this;
}

// AUTRES METHODES
int Pression::aleaGenVal()
{
  //La pression à bord d'un avion doit être compris entre 80000 pa et 100000 pa  inclus
  int genVal = 0;
  srand(time(NULL));
  genVal = ((rand()%20) + 80)*1000; //Valeur aléatoire comprise entre 80 000 et 10 000 pa
  return genVal;
}

int Pression::getDelay()
{
  int valeur = this->delay;
  return valeur;
}
