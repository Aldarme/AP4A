/**
 * @author RENON Emilien
 * @file Light.hpp
 * @date 04/10/2022
 * @brief La classe Light permettra de caractèriser un capteur de lumière.
 */

#include "Light.hpp"
using namespace std;

template <class T>
Light<T>::Light(){
    this->m_name="Light (lm)";
    this->m_sensor=e_light;
}