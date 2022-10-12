#include"AllSensor.hpp"
#include "Sensor.hpp"
#include<iostream>
#include<string>
#include<ctime>

using namespace std;

Luminosite::Luminosite() : Sensor() {}


Luminosite::Luminosite(string nom): Sensor(nom, "Lux"){
    m_nom = nom;
    m_unite = "Lux";
}

Luminosite::~Luminosite(){
}

float Luminosite::GetLuminosite()
{
    srand(time(0));
    float luminosite = rand() % 1000 + 1;
    return luminosite;
}

void Luminosite::InfoLuminosite(){
    std::cout << "Le capteur " << m_nom << " a pour valeur " << GetLuminosite() << " " << m_unite << std::endl;
    std::cout << "Nom du capteur : " << m_nom << std::endl;
    std::cout << "Unite du capteur : " << m_unite << std::endl;
    std::cout << "Luminosite : " << GetLuminosite() << std::endl;
}
