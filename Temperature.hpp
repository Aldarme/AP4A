/*author:TRABOULSI Rawan
*TEMPERATURE
*Créé le 19/09/2022
*Fichier Header dont on déclare la classe Temperature avec ses attributs et ses déclarations de méthodes*/

#ifndef TEMPERATURE_HPP
#define TEMPERATURE_HPP
#include "Sensor.hpp"
#include <string>


class Temperature:public Sensor<float>{
    //Forme Canonique de Coplien (constructeurs,destructeur et operateur d'affectation)
    public:
    Temperature();//constructeur par défaut
    Temperature(const Temperature & autre);//constructeur de recopie
    Temperature & operator=(const Temperature &);//operateur d'affectation
    virtual ~Temperature();//Destructeur

    //Les Méthodes
    int getTmax();
    int getTmin();
    int getTemp();

    //Les attributs 
    private:
    int m_Tmax;
    int m_Tmin;
    int m_Temp;

};
#endif //TEMPERATURE_H

