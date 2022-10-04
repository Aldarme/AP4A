/*
@author BENEDUCI Marie
@file  Temperature.cpp
@date 26/09/2022
@brief  Implementation de la Classe capteur permetant d'avoir les données de temperature
*/

#include "../hpp/Temperature.hpp"


Temperature :: Temperature(){
    m_data = aleaGenVal(); //instanciation de la valeur Temperature avec un nombre aléatoire generé par la fonction de la classe mère Sensor
}