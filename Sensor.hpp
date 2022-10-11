/**
 * @author Planchin Arnaud
 * @file Sensor.hpp
 * @date 03/10/2022
 * @brief 
 */

#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
template <class Type>

class Sensor
{
private:    

    void Sensor(){};
    
protected:

    /**
     * @brief Génère une valeur aléatoire en fonction du type de valeur
     * @return Une valeur de type 'Type'
     * @param - Aucun
     */
    Type aleaGenVal();

public:

    //Défintion de la forme Canonique: 
    void Sensor(){};
    void Sensor(const Sensor& s_Sensor);
    virtual ~Sensor(){};
    
    /**
     * @brief Récupère une valeur
     * @return une data de type 'Type'
     * @param - Aucun
     */
    Type GetData();

}


//Fonction de transfert pour génération de donnée
class Temperature: public Sensor{
    private:
        int temperature;
    public:
}

class Humidity: public Sensor{
    private:
        int humidite;
    public:
}

class Light: public Sensor{
    private:
        int lumiere;
    public:
}

class Pression: public Sensor{
    private:
        int pression;
    public:
}

#endif // SERNSOR_H