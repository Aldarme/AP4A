/**
 * @author Augustin Athané
 * @file Sensor.cpp
 * @date 24/09/2022
 * @brief Cette classe mère permet de créer les différents capteurs grâce à un lien d'héritage
 * */

#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <iostream>
#include <cstdlib>
#include <random>
#include <time.h>


//  Declaration  classe ,  fonctions . . .
enum type_sensor{
    e_temperature,
    e_humidity,
    e_light,
    e_pression
};

class Sensor
{
    protected : // Protected pour y avoir accès avec l'héritage
        //Variables
        type_sensor type;
        bool simulation;
        int MAX;
        int MIN;

        //Méthodes protected
        
    public :
    
        //Constructeur par default
        Sensor();

        //Constructer par recopie
        Sensor(const Sensor &other);

        //Destructeur
        ~Sensor();

        //Méthodes

        void endSimulation();

        virtual void startSimulation() = 0;

        // On créer notre propre fonction Rand pour que les valeurs aléatoires ne proviennent pas du thread_local, cette fonction est expliquée plus en détail dans le fichier readme 
        // Le générateur créer une valeur double aléatoire puis les trnasforme dans le type T voulu
        int intRand(const int min, const int max);
        float floatRand(const float min, const float max);
};



#endif // SENSOR_HPP