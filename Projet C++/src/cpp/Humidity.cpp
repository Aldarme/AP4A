/*
@author BENEDUCI Marie
@file  Humidity.cpp
@date 26/09/2022
@brief  Implementation de la Classe capteur permetant d'avoir les données d'humidité
*/

#include "../hpp/Humidity.hpp"



Humidity :: Humidity(){
    m_data = aleaGenVal(); //instanciation de la valeur Humidity avec un nombre aléatoire generé par la fonction de la classe mère Sensor

}
