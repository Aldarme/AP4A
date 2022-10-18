/**
 * @author Cameron ROCHEBILLARD
 * @file temperature.hpp
 * @date 18/10/2022
 * @brief représente un capteur
 */

 //
 //Define guards 
 #ifndef TEMPERATURE_H
 #define TEMPERATURE_H


/**
 * @class Temperature
 * représente un capteur
 */


class Temperature: public Sensor<float>
{
    public:
        float T_min ;
        float T_max ;
};

 #endif //TEMPERATURE_H