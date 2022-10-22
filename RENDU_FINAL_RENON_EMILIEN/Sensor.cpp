/**
 * @author RENON_Emilien
 * @file Sensor.hpp
 * @date 21/09/2022
 * @brief La classe Sensor permettra de créer les données des capteurs.
 */

#include "Sensor.hpp"
using namespace std;

template <class T>
void Sensor<T>::aleaValue()
{
    switch(this->m_sensor)
    {
            case e_temperature : 
            {   
                //Utilisation de static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(MAX-MIN))) pour avoir des float randoms
                this->m_value = 18 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(22-18))); 
            }
            break;
            case e_humidity : 
            {
                //Utilisation de static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(MAX-MIN))) pour avoir des float randoms
                this->m_value = 40 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(60-40)));
            }
            break;
            case e_light : 
            {   
                //Utilisation d'un random entre 0 et 1 puis d'un switch pour donner la valeur du booléen
                int boolean;
                boolean = rand()%2;
                if(boolean == 1)
                {
                    this->m_value = true;
                }else
                {
                    this->m_value = false;
                }
            }
            break;
            case e_pression : 
            { 
                //Utilisation d'un random classique pour un int
                this->m_value = rand()%81 + 75;
            }
            break;
    }
}

template <class T>
ostream& operator<<(ostream &param_os, const Sensor<T> &param_sensor)
{
    //Création d'une surcharge d'opérateur pour un cout pour rendre l'écriture dans la console plus simple
    param_os << param_sensor.m_name <<" : "<<param_sensor.m_value<<endl;
    return param_os;
}

template <class T>
ofstream& operator<<(ofstream &param_of, const Sensor<T> &param_sensor)
{
    //Création d'une surcharge d'opérateur pour un fichier pour rendre l'écriture dans un fichier plus simple
    param_of << param_sensor.m_name <<";"<<param_sensor.m_value<<";";
    return param_of;
}