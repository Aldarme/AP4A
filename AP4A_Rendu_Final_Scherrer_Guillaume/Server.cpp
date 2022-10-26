/** 
 * @author SCHERRER Guillaume
 * @file Server.cpp
 * @date 25/09/2022
 * @brief definiton ds corps des méthodes de Server.hpp
 *  
*/

// generiques:
#include <iostream>
#include <fstream>
#include "AP4A_Final.hpp"

// classes:
#include "Server.hpp"



Server::Server() // constructer
{
    m_Temperature = 0.0f;
    m_Humidity = 0.0f; 
    m_Pressure = 0; 
    m_Light = 0;

    PressureFile.open("Pression.txt", std::ios::out); //ios::out = write mode
    TemperatureFile.open("Temperature.txt", std::ios::out); //ios::out = write mode
    LightFile.open("Lumiere.txt", std::ios::out); //ios::out = write mode
    HumidityFile.open("Humidite.txt", std::ios::out); //ios::out = write mode

    PressureFile << "Voici les différentes valeur mesurées pour la pression : \n\n" ;
    TemperatureFile << "Voici les différentes valeur mesurées pour la température: \n\n" ;
    LightFile << "Voici les différentes valeur mesurées pour la lumière: \n\n" ;
    HumidityFile << "Voici les différentes valeur mesurées pour l'humidité: \n\n" ;
}

Server::~Server() { } // destructor

void Server::CloseAll()
{
    //fermeture ds fichiers
    PressureFile.close(); 
    TemperatureFile.close();
    LightFile.close();
    HumidityFile.close();

}

void Server::UpdateValues(ValeursCapteurs &valeurs, int choix) 
{
    // on attribue les valerus venant 
    m_Temperature = valeurs.m_measured_Temperature;
    m_Humidity = valeurs.m_measured_Humidity;
    m_Pressure = valeurs.m_measured_Pressure;
    m_Light = valeurs.m_measured_Light;

    switch(choix) 
    {
        case 1:
            consolWrite();
            break;

        case 2:
            fileWrite();
            break;

        case 3: 
            consolWrite();
            fileWrite();
            break;
        default:
            consolWrite();
    }
}

   
void Server::consolWrite()  // 
{

    std::cout << "Température: " << m_Temperature << " deg °C    ";
 
    if (m_Light==false)
    {
        std::cout << "Lumière: allumée    ";
    }
    else
    {
        std::cout << "Lumière: éteinte    ";
    }
    
    std::cout << "Humidité: " << m_Humidity << " % rel    ";
    
    std::cout << "Pression: " << m_Pressure << " Pa / 0."<< m_Pressure << " Bar \n";
    
}



void Server::fileWrite()
{
    if(PressureFile && TemperatureFile && LightFile && HumidityFile)  // tous les fichiers ouverts
    {

      
        TemperatureFile << "Température:  "<< m_Temperature << " °C \n";
       
       if (m_Light==false)
        {
            LightFile << "Lumière: allumée   \n ";
        }
        else
        {
            LightFile << "Lumière: éteinte   \n ";
        }
      
        HumidityFile << "Humidité:  "<< m_Humidity << " % rel. \n";

        PressureFile << "Pression:  "<< m_Pressure << " Pa \n";
        
    }
    else 
    {
        std::cout<< "Erreur, impossible d'ouvrir un ou plusieurs fichiers \n";
    }
   
}

