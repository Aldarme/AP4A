/**
 * @author Augustin Athané
 * @file Sensor.cpp
 * @date 24/09/2022
 * @brief Cette classe mère permet de créer les différents capteurs grâce à un lien d'héritage
 * Il vas falloir créer un thread, les valeurs seront modifiés toutes les secondes mais récupérer par le Scheduler à différentes periodes.
 * Pour plus de réalisme on pourra incrémenter par une valeur aléatoire (nég ou pos) plutôt que de créer une valeur aléatoire
 */

#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <iostream>
#include <cstdlib>


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
        int value;
        bool simulation;
        int MAX;
        int MIN;

        //Méthodes protected
        virtual int aleaGenVal(); //0

        int intRand(const int & min, const int & max);
        
    public :
        //Constructeur par default
        Sensor();

        //Constructer par recopie
        Sensor(const Sensor &other);

        //Destructeur
        ~Sensor();

        //Méthodes
        int getData();

        void endSimulation();

        void startSimulation();

        void operator() ();

        

};

class Temperature : public Sensor
{
    public :
        //Constructeur par défault
        Temperature();
        Temperature(const Temperature &other);
        ~Temperature();

};

class Humidity : public Sensor
{
    public :
        Humidity();
        Humidity(const Humidity &other);
        ~Humidity();

};

class Light : public Sensor
{
    public :
        Light();
        Light(const Light &other);
        ~Light();
        int aleaGenVal() override;
      
};

class Pression : public Sensor
{
    public :
        Pression();
        Pression(const Pression &other);
        ~Pression();

};

#endif // SENSOR_HPP