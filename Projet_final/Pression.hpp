/**
 * @author Cameron ROCHEBILLARD
 * @file Pression.hpp
 * @date 18/10/2022
 * @brief représente un capteur
 */

 //
 //Define guards 
 #ifndef PRESSION_H
 #define PRESSION_H

/**
 * @class Pression 
 * représente un capteur
 */

class Pression: public Sensor<int>
{
    public:
        int P_min;
        int P_max;
};


 #endif //PRESSION_H