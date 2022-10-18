/**
 * @author NANMEGNI_NGASSAM
 * @file Pression.cpp
 * @date 24/09/2022
 * @licence libre
 */
#include "Pression.hpp"

//FORME CANONIQUE
Pression::Pression() : unity("Pa")
{
}
Pression::Pression(const Pression& autre) : unity(autre.unity)
{
}
Pression::~Pression()
{
}
Pression& Pression::operator=(const Pression& autre)
{
  this->unity = autre.unity;
  return *this;
}

//
int Pression::aleaGenVal()
{
  //La pression à bord d'un avion doit être compris entre 80000 pa et 100000 pa  inclus
  int genVal = 0;
  srand(time(NULL));
  genVal = ((rand()%20) + 80)*1000; //Valeur aléatoire comprise entre 80 000 et 10 000 pa
  return genVal;
}
