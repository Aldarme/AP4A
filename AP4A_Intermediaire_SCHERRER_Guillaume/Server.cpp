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
#include "AP4A_Intermediaire.hpp"

// classes:
#include "Server.hpp"



Server::Server() // constructer
{
    m_Temperature = 0.0f;
    m_Humidity = 0.0f; 
    m_Pressure = 0.0f; 
    m_Light = 0.0f;

    // ouvrir et reinitialiser le fichier de mesures:
    SensorLogFile.open("SensorLog.txt", std::ios::out); //ios::out = write mode ->fichier vide
    SensorLogFile << "Voici les différentes valeurs mesurées : \n\n" ;
    SensorLogFile.close();  
}

Server::~Server() { } // destructor

void Server::CloseAll()
{
    SensorLogFile.close(); // closes the log file
}

void Server::UpdateValues(float* SensorData)
{
    m_Temperature = SensorData[T];
    m_Humidity = SensorData[H];
    m_Pressure = SensorData[P];
    m_Light = SensorData[L];

    consolWrite();
    fileWrite();
}

void Server::consolWrite()  // 
{
    std::cout << "    Temperature: " << m_Temperature << " deg. C    ";  // écrire avec format pour aligner ?
    std::cout << "Humidity: " << m_Humidity << " % rel    ";
    std::cout << "Pressure: " << m_Pressure << " Pa   ";
    std::cout << "Luminosity: " << m_Light << " Lm \n";
}



void Server::fileWrite()
{
    if(SensorLogFile)
    {
        SensorLogFile.open("SensorLog.txt", std::ios::app); //ios::app = append mode ->on écrit à la suite
        SensorLogFile << " Température: "<< m_Temperature <<" °C    Humidité: "<< m_Humidity <<" % rel.    Pression:  "<< m_Pressure << " Pa     Lumière:  "<< m_Light<< " Lumen\n";  
        SensorLogFile.close(); // et on referme
    }
    else 
    {
        std::cout<< "Error: could not open file SensorLog.txt";
    }
   
}
