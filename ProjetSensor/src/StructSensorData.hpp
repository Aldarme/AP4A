/**
 * @author Thibaud Leclere <thibaud.leclere@utbm.fr>
 * @file Sensor.hpp
 * @date 12/10/2022
 * @brief Définition de la structure SensorData
 * @brief Utilisée pour communiquer les informations d'un capteur
 * @brief Les valeurs sont stockées au format string, car le but est uniquement de les afficher, 
 *        ainsi tout type de donnée peut être stocké (int, float, bool, etc)
 */

#ifndef SENSORDATA_H
#define SENSORDATA_H

#include <string>

struct SensorData
{
    std::string sensorName; //Nom à afficher du capteur
    std::string sensorValue;//Valeur du capteur
    std::string sensorUnit; //Unité du capteur
};

#endif // SENSORDATA_H
