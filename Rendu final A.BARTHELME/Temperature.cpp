/**
 * @author A.BARTHELME
 * @file Temperature.cpp
 * @date 12/10/2022
 * @brief Capteur de Température, tous les autres sont basés sur cette classe
 * @version Intermediaire 
*/





#include<iostream>
#include<string>
#include<ctime>
#include "AllSensor.hpp"
#include "Sensor.hpp"
using namespace std;

Temperature::Temperature() : Sensor() {}



Temperature::Temperature(string nom) : Sensor(nom, "Celsius") 
{
    m_nom = nom;
    m_unite = "Celsius";
}

float Temperature::GetTemperature()
{   srand(time(0));
    float temperature = rand() % 50 + -10;
    return temperature;
}

void Temperature::InfoTemperature() 
{
    cout << "Le capteur " << m_nom << " a pour valeur " << GetTemperature() << " " << m_unite << endl;
    cout << "Nom du capteur : " << m_nom << endl;
    cout << "Unite du capteur : " << m_unite << endl;
    cout << "Temperature : " << GetTemperature() << endl;

}

Temperature::~Temperature()
{
}



