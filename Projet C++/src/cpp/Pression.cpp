/*
@author BENEDUCI Marie
@file  Pression.cpp
@date 26/09/2022
@brief Implementation de la Classe capteur permetant d'avoir les données de pression
*/
#include <cstdlib>
#include <ctime>
#include "../hpp/Pression.hpp"

Pression :: Pression(){
    m_data = this -> aleaGenVal(); //instanciation de la valeur Sound avec un nombre aléatoire generé par la fonction de la classe mère Sensor
}


