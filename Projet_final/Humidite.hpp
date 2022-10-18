/**
 * @author Cameron ROCHEBILLARD
 * @file Humidite.hpp
 * @date 18/10/2022
 * @brief représente un capteur
 */

 //
 //Define guards 
 #ifndef HUMIDITE_H
 #define HUMIDITE_H


/**
 * @class Humidite
 * représente un capteur
 */

class Humidity: public Sensor<float>
{
    public:
        float H_min;
        float H_max;
};

 #endif //HUMIDITE_H