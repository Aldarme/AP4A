/*
@author BENEDUCI Marie
@file  Light.cpp
@date 26/09/2022
@brief  Implementation de la Classe capteur permetant d'avoir les données de luminosité
*/
#include <cstdlib>
#include <ctime>

#include "../hpp/Light.hpp"


Light :: Light(){
    m_data = this -> aleaGenVal(); //instanciation de la valeur Light avec un nombre aléatoire generé par la fonction de la classe mère Sensor
}

// bool aleaGenVal() {
//     int temp = rand() % 2;
//     bool randomData;
//         if(temp == 0){
//             randomData = false;
//         }
//         if(temp == 1){
//             randomData = true;
//         }

//         return randomData;
// }
