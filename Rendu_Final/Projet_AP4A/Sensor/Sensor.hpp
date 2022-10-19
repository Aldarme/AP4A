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

template <class T>
class Sensor
{
    protected : // Protected pour y avoir accès avec l'héritage
        //Variables
        T value;
        type_sensor type;
        bool simulation;
        int MAX;
        int MIN;

        //Méthodes protected
        
    public :
    
        //Constructeur par default
        Sensor(){
            type = e_temperature;
            simulation = false;
            value = 1;
            MAX = 30;
            MIN = 16;
        }

        //Constructer par recopie
        Sensor(const Sensor &other){
            type = other.type;
            value = other.val;
            simulation = other.simulation;
            MAX = other.MAX;
            MIN = other.MIN;
        }


        //Destructeur
        ~Sensor(){};

        // Getter
        T getData(){
            return value;
        }

        //Méthodes

        void endSimulation(){ // Fonction appelée pour arrêter la simulation
            simulation = false;
        }

        virtual void startSimulation() = 0;
        

        // On créer notre propre fonction Rand pour que les valeurs aléatoires ne proviennent pas du thread_local, cette fonction est expliquée plus en détail dans le fichier readme 
        // Le générateur créer une valeur double aléatoire puis les trnasforme dans le type T voulu
        int intRand(const int min, const int max){
            std::random_device rd;
            std::default_random_engine eng(rd());
            std::uniform_int_distribution<int> distr(min, max); 
            return distr(eng);
        }

        float floatRand(const float min, const float max) {
            std::random_device rd;
            std::default_random_engine eng(rd());
            std::uniform_real_distribution<float> distr(min, max); // différence : uniform_real au lieu de uniform_int utlisé pour générer le nombre
            return distr(eng);
        }
};



#endif // SENSOR_HPP