/**
 * @author A.BARTHELME
 * @file paquet.cpp
 * @date 12/10/2022
 * @brief Fichier de la classe paquet, cette classe permet de transformer les données en paquet
 * @version Intermediaire 
*/




#include<iostream>
#include<string>
using namespace std;

#include "Paquet.hpp"

Paquet::Paquet(){
    m_val = 0;
    m_type = "Capteur/nom par defaut";
    m_unite = "Unite par defaut";
}

Paquet::Paquet(float val){
    m_val = val;
    m_type = "Capteur/nom par defaut";
    m_unite = "Unite par defaut";
}

Paquet::Paquet(float val, std::string type, std::string unite){
    m_val = val;
    m_type = type;
    m_unite = unite;
}

Paquet::Paquet(const Paquet &paquet){
    m_val = paquet.m_val;
    m_type = paquet.m_type;
    m_unite = paquet.m_unite;
}

Paquet::~Paquet(){
}

Paquet& Paquet::operator=(const Paquet &paquet){
    m_val = paquet.m_val;
    m_type = paquet.m_type;
    m_unite = paquet.m_unite;
    return *this;
}

string Paquet::data(){
    string data = to_string(m_val)  + " " + m_unite + ", mesure depuis : " + m_type;
    return data;
}

string Paquet::Getunit(){
    return m_unite;
}
