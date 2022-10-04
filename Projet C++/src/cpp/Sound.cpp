/*
@author BENEDUCI Marie
@file  Sound.cpp
@date 26/09/2022
@brief Implementation de la Classe capteur permetant d'avoir les données de son
*/

#include "../hpp/Sound.hpp"

Sound :: Sound(){
    m_data = aleaGenVal(); //instanciation de la valeur Sound avec un nombre aléatoire generé par la fonction de la classe mère Sensor
}
