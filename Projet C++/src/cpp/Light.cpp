/*
@author BENEDUCI Marie
@file  Light.cpp
@date 26/09/2022
@brief  Implementation de la Classe capteur permetant d'avoir les données de luminosité
*/

#include "../hpp/Light.hpp"


Light :: Light(){
    m_data = aleaGenVal(); //instanciation de la valeur Light avec un nombre aléatoire generé par la fonction de la classe mère Sensor
}
