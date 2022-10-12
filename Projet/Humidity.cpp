/**
 * @author mayer_thibault
 * @file Humidity.cpp
 * @date 02/10/2022
 * @brief capteur humidité qui hérite de Sensor
 */

#include <cstdlib>
#include <iostream>
#include "Sensor.hpp"

class Humidity : protected Sensor
{
  private : 
    float m_habs;                                       //Humidité absolue en g/m3
  public : 
    Humidity():m_habs(0.0f){};                          //Constructeur par défaut
    Humidity(const float& h):m_habs(h){};               //Constructeur par recopie
    virtual ~Humidity(){};                              //Destructeur
    Humidity &operator=(const Humidity& param_l)        //Opérateur d'affectation
    {
      this->m_habs = param_l.m_habs;
      return* this;
    };
    //function that collect habs from Humidity
    Humidity getData()
    {
      float _temp = Sensor::aleaGenVal();
      this->m_habs = _temp;
      return Humidity(_temp);
    };

    float getValue()
    {
      return this->m_habs;
    };

    std::string getType()
    {
      return "Humidity";
    };
};