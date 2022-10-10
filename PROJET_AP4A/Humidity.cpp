/**
 * @author RENON Emilien
 * @file Humidity.hpp
 * @date 04/10/2022
 * @brief La classe Humidity permettra de caractèriser un capteur d'humidité.
 */

#include "Humidity.hpp"
using namespace std;

template <class T>
Humidity<T>::Humidity(){
    this->m_name="Humidity (%)";
    this->m_sensor=e_humidity;
}