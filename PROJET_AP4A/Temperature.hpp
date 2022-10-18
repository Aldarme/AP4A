/**
 * @author RENON_Emilien
 * @file Temperature.hpp
 * @date 04/10/2022
 * @brief La classe Temperature permettra de caractériser un capteur de température.
 */

//
// Define guards
#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include "Sensor.hpp"

/**
 * @class Temperature
 * @brief La classe Temperature simule le fonctionnement du capteur de température
 */
template <class T>
class Temperature : public Sensor<float>
{
public:
    // Definition de la forme canonique
    Temperature(){
        this->m_name="Temperature (°C)";
        this->m_sensor=e_temperature;
    }
    Temperature(const Temperature &param_temperature);
    ~Temperature(){};
    // ...
       
};


#endif // TEMPERATURE_H