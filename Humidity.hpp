/*           author:TRABOULSI Rawan
        *HUMIDITY
        *Créé le 19/09/2022          */
#ifndef HUMIDITY_HPP
#define HUMIDITY_HPP
#include "Sensor.hpp"
#include <string>


class Humidity:public Sensor{
//La Forme CANONIQUE
public:
Humidity();//Constructeur par défaut
Humidity(const Humidity & autre);//Constructeur de recopie
Humidity &operator=(const Humidity &); //operateur d'affectation
virtual ~Humidity();//destructeur

//Les Méthodes
int getHumidity();
int getHumiditymax();
int getHumiditymin();

//Les Attributs
private:
int m_humiditymin;
int m_humiditymax;
int m_humidityvalue;

};
#endif //HUMIDITY_H
