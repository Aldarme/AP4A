#include<iostream>
#include<string>
#include<ctime>
#include "AllSensor.hpp"
#include "Sensor.hpp"

using namespace std;

Pression::Pression() : Sensor() {}

Pression::Pression(string nom) : Sensor(nom, "hPa") {
    m_nom = nom;
    m_unite = "hPa";
    m_type = 2;
}

Pression::~Pression(){
}

int Pression::GetPression(){
    srand(time(0));
    int pression = rand() % 1030 + 100;
    return pression;
}

void Pression::InfoPression(){
    std::cout << "Le capteur " << m_nom << " a pour valeur " << GetPression() << " " << m_unite << std::endl;
    std::cout << "Nom du capteur : " << m_nom << std::endl;
    std::cout << "Unite du capteur : " << m_unite << std::endl;
    std::cout << "Pression : " << GetPression() << std::endl;
}


