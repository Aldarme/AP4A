/**
* @author laduguie
* @file Sensor.hpp
* @date 28/09/2022
* @brief The sensor takes the 4 data to send to the scheduler
*/

#ifndef SENSOR_H
#define SENSOR_H
#include <iostream>
union type
{
    int valInt;
    bool valBool;   //on utilisera pas valBool et valFloat pour le rendu intermédiaire
    float valFloat;
};
class Sensor
{
    protected:
        int aleaGenVal();
        int min = 0;
        int max = 100;
    public:
        type getData()
        {
            type temp;
            temp.valInt = aleaGenVal();
            return temp;
        }

        std::string getType()
        {
            return "int";
        }

        Sensor(){} //constructeur par défaut
        Sensor(const Sensor&); //constructeur par recopie
        Sensor &operator=(const Sensor&); //operateur d'afffectation
        ~Sensor(){} //Destructeur

};

#endif
