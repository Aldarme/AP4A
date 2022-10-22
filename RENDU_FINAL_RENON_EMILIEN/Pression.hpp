/**
 * @author RENON_Emilien
 * @file Pression.hpp
 * @date 04/10/2022
 * @brief La classe Pression permettra de caractériser un capteur de pression.
 */

//
// Define guards
#ifndef PRESSION_H
#define PRESSION_H
#include "Sensor.hpp"

/**
 * @class Pression
 * @brief La classe Pression simule le fonctionnement du capteur de pression
 */
template <class T>
class Pression : public Sensor<int>
{
public:
    // Definition de la forme canonique
    Pression(){
        this->m_name="Pression (hPa)";
        this->m_sensor=e_pression;
    }

    Pression(const Pression &param_pression);
    ~Pression(){};
    // ...
      
};


#endif // PRESSION_H