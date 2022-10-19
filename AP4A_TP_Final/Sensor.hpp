/**
 *@author Lola ROQUILLON 
 *@file Sensor.hpp
 *@date 28/09/2022
 *@brief Cette classe crée les valeurs des capteurs de manière aléatoire et les envoi au scheduler
 */

#ifndef SENSOR_H
#define SENSOR_H
#include <random>
#include <ctime>

template <typename T>
class Sensor
{
    public :
    //forme canonique
        Sensor<T>() =default;                   //constructeur par default
        virtual ~Sensor<T>() =default;          //destructeur
        Sensor<T> (const  Sensor<T>& sensor)=default;           //constructeur par recopie
        Sensor<T>& operator=(const Sensor<T>& sensor)=default;  //operateur d'affectation

        T getData(T max_p, T min_p)   //fonction qui recupére les données aleatoires 
        {
            return (aleaGenVal(max_p, min_p));
        }      
        
    protected :
        T aleaGenVal(T max_p, T min_p)  //fonction qui genére le nombre aléatoire
        {
            if(std::is_same<T,bool>::value) //verifie si le nombre est un booleen
            {
                if (rand()%2 == 0)
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
            else
            {
                return (min_p + static_cast<T>(rand()) / static_cast<T>(RAND_MAX / (max_p- min_p))); //création de nombre aléatoire
            }
        }  
};

#endif //SENSOR_H
