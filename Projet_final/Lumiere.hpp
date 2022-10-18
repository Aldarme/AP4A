/**
 * @author Cameron ROCHEBILLARD
 * @file Lumiere.hpp
 * @date 18/10/2022
 * @brief représente un capteur
 */

 //
 //Define guards 
 #ifndef LUMIERE_H
 #define LUMIERE_H

/**
 * @class Lumiere 
 * représente un capteur
 */

class Light: public Sensor<bool>
{
    public:
        bool L_min;
        bool L_max;
};

 #endif //LUMIERE_H