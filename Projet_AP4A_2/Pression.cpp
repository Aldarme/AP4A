#include "Pression.hpp"

//constructeur par défaut des capteurs Pression
Pression::Pression()
{

    this->m_name = ESensors::e_pression;
    this->m_valeur = 0;

}

//constructeur par recopie des capteurs Pression
Pression::Pression(const Pression& p)
{

    this->m_name = p.m_name;
    this->m_valeur = p.m_valeur;

}

//destructeur
Pression::~Pression()
{
    
}

int Pression::aleaGenVal(){
    return rand() % 100 + 700;
}