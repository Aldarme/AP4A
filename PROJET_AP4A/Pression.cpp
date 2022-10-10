/**
 * @author RENON Emilien
 * @file Teperature.hpp
 * @date 04/10/2022
 * @brief La classe Temperature permettra de caractèriser un capteur de température.
 */

#include "Pression.hpp"
using namespace std;

template <class T>
Pression<T>::Pression(){
    this->m_name="Pression (bar)";
    this->m_sensor=e_pression;
}
