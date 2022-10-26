#include "AllSensor.hpp"
#include "Sensor.hpp"
#include<iostream>
#include<string>
#include<ctime>

using namespace std;

Humidite::Humidite() : Sensor() {}



Humidite::Humidite(string nom) : Sensor(nom, "%"){
    m_nom = nom;
    m_unite = "%";
    m_type = 3;
}

Humidite::~Humidite(){
}

float Humidite::GetHumidite(){
    srand(time(0));
    float humidite = rand() % 100 + 1;
    return humidite;

}

void Humidite::InfoHumidite(){
    std::cout << "Le capteur " << m_nom << " a pour valeur " << GetHumidite() << " " << m_unite << std::endl;
    std::cout << "Nom du capteur : " << m_nom << std::endl;
    std::cout << "Unite du capteur : " << m_unite << std::endl;
    std::cout << "Humidite : " << GetHumidite() << std::endl;
}

