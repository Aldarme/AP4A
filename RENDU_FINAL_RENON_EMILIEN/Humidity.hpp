/**
 * @author RENON_Emilien
 * @file Humidity.hpp
 * @date 04/10/2022
 * @brief La classe Humidity permettra de caractériser un capteur d'humidité.
 */

//
// Define guards
#ifndef HUMIDITY_H
#define HUMIDITY_H
#include "Sensor.hpp"

/**
 * @class Humidity
 * @brief La classe Humidity simule le fonctionnement du capteur d'humidité.
 */
template <class T>
class Humidity : public Sensor<float>
{
public:
    // Definition de la forme canonique
    Humidity(){
        this->m_name="Humidity (%)";
        this->m_sensor=e_humidity;
    }
    Humidity(const Humidity &param_humidity);
    ~Humidity(){};
    // ...

};


#endif // HUMIDITY_H