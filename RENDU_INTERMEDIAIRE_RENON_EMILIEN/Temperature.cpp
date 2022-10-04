/**
 * @author RENON Emilien
 * @file Teperature.hpp
 * @date 04/10/2022
 * @brief La classe Temperature permettra de caractèriser un capteur de température.
 */

#include "Temperature.hpp"
using namespace std;

Temperature::Temperature(){
    this->m_name="Temperature (°C)";
    this->m_sensor=e_temperature;
}