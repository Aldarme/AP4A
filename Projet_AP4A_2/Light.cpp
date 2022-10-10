#include "Light.hpp"

//constructeur par défaut des capteurs Light
Light::Light()
{

    this->m_name = ESensors::e_light;
    this->m_valeur = 0;

}

//constructeur par recopie des capteurs Light
Light::Light(const Light& l)
{

    this->m_name = l.m_name;
    this->m_valeur = l.m_valeur;

}

//destructeur
Light::~Light()
{

}

bool Light::aleaGenVal(){
    int m_temp = rand() % 2;
    if(m_temp == 1){
        return m_valeur = true;
    }
    else
    {
        return m_valeur = false;
    }
}