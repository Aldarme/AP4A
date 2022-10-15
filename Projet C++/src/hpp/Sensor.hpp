/*
@author BENEDUCI Marie
@file  Sensor.hpp
@date 19/09/2022
@brief  Déclaration de la Classe ayant pour objectif de generer à intervalle régulier des données en int
*/
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <iomanip>
#include <map>

template<typename T>
class Sensor
{
protected:
    virtual T aleaGenVal(){
        T randomData = 0 + (rand() % (1 - 0 + 1)) == 1;
        return randomData;
    }; // Fonction de generation de nombre aléatoire entre 1 et 10

public:
    T m_data; 
    Sensor(){}; // Constructeur par défaut
    virtual ~Sensor(){}; // Destructeur
    Sensor (const Sensor&){}; // Constructeur de recopie
    Sensor &operator=(const Sensor&){}; // Opérateur d'affectation
    T getData(){
        return m_data;
    }; // Fonction permettant de récuperer la donnée à envoyer

};
