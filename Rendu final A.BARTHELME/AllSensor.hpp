/**
 * @author A.BARTHELME
 * @file AllSensor.hpp
 * @date 26/10/2022
 * @brief Pour facilité la visibilité du code, j'ai regroupé tous les capteurs dans un seul fichier .hpp
 * @version Finale 
*/



#ifndef AllSensor_hpp
#define AllSensor_hpp
#include "Sensor.hpp"

class Temperature : public Sensor
{
    public : 
        Temperature();
        Temperature(std::string nom);
        float GetTemperature();
        void InfoTemperature();
        ~Temperature();
        
};

class Humidite : public Sensor
{
    public : 
        Humidite();
        Humidite(std::string nom);
        float GetHumidite();
        void InfoHumidite();
        ~Humidite();
};

class Pression : public Sensor
{
    public : 
        Pression();
        Pression(std::string nom);
        int GetPression();
        void InfoPression();
        ~Pression();
};

class Luminosite : public Sensor
{
    public : 
        Luminosite();
        Luminosite(std::string nom);
        bool GetLuminosite();
        void InfoLuminosite();
        ~Luminosite();
};


#endif  /* AllSensor_hpp */
