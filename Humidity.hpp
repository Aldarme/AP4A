/*           author:TRABOULSI Rawan
        *HUMIDITY
        *Créé le 09/10/2022          */
#ifndef HUMIDITY_HPP
#define HUMIDITY_HPP
#include "Sensor.hpp"
#include <string>


class Humidity:public Sensor<float>{
//Les Attributs de type FLOAT
private:
float m_humiditymin;
float m_humiditymax;
float m_humidityvalue;

public:
Humidity();//Constructeur par défaut
Humidity(const Humidity & autre);//Constructeur de recopie
Humidity &operator=(const Humidity &); //operateur d'affectation
virtual ~Humidity();//destructeur

//Les Méthodes de type FLOAT
float getHumidity();
float getHumiditymax();
float getHumiditymin();

};
#endif //HUMIDITY_H
