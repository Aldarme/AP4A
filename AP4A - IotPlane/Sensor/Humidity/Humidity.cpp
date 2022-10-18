/**
 * @author NANMEGNI_NGASSAM
 * @file Humidity.cpp
 * @date 24/09/2022
 * @licence libre
 */
#include "Humidity.hpp"

//FORME CANONIQUE
Humidity::Humidity()
{
}
Humidity::Humidity(const Humidity& autre)
{
}
Humidity& Humidity::operator=(const Humidity& autre)
{
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