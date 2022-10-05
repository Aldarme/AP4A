/**
* @author Alan HERVE
* @file Server.hpp
* @date 01/10/2022
* @brief Is in charge of writing values received from the captors in files and in the console
**/


#ifndef SERVER_CPP
#define SERVER_CPP

#include "Server.hpp"
#include "Scheduler.cpp"

#include <iostream>
#include <fstream>
using namespace std;

/**
* @brief Open files, erasing previous contents if said previous contents exist
**/

void Server::initiateFile()
{
        ofstream myfile;

  myfile.open ("TemperatureLog.txt", std::ofstream::out | std::ofstream::trunc);
  myfile.close();
  myfile.open ("HumidityLog.txt", std::ofstream::out | std::ofstream::trunc);
  myfile.close();
  myfile.open ("PressionLog.txt", std::ofstream::out | std::ofstream::trunc);
  myfile.close();
  myfile.open ("LightLog.txt", std::ofstream::out | std::ofstream::trunc);
  myfile.close();
}

void Server::activateConsole()
{
    this->consolActivation = true;
}

void Server::activateLog()
{
        this->logActivation = true;
}

void Server::deActivateConsole()
{
        this->consolActivation = false;
}

void Server::deActivateLog()
{
        this->logActivation = false;
}

void Server::activateAll()
{
        this->activateConsole();
        this->activateLog();
}

void Server::deActivateAll()
{
        this->consolActivation = false;
        this->logActivation = false;
        
}

/**
* @brief Open different file depending on parameter's type and then write value into said file
* @param classparam one of the 4 child classes of Sensor
**/

template <class Type> void Server::fileWrite(Type classparam)
{
    std::string display_data;
    ofstream myfile;
    switch (classparam.type)
    {
    case 0:
        myfile.open ("HumidityLog.txt", std::ios::app);
        break;
    case 1:
        myfile.open ("LightLog.txt", std::ios::app);
        break;
    case 2:
        myfile.open ("PressionLog.txt", std::ios::app);
        break;
    case 3:
        myfile.open ("TemperatureLog.txt", std::ios::app);
        break;
    default:
        cout << "ERROR, NO DATA TO SAVE !!" << endl;
        break;
    }

    if (myfile.is_open())
        {
           myfile << classparam.info << endl;
            
        }
    myfile.close();
}

/**
* @brief Displays information of parameter, display is unique for each child class of Sensor
* @param classparam one of the four child class of class Sensor
**/
template <class Type> void Server::consoleWrite(Type classparam)
{
    
    
    switch (classparam.type)
    {
    case 0:
       
        cout << "Printing contents of sensor : Humidity : " << classparam.info <<endl;
        break;
    case 1:
        cout << "Printing contents of sensor : Light : " << classparam.info <<endl;
        break;
    case 2:
        cout << "Printing contents of sensor : Pression : " << classparam.info <<endl;
        break;
    case 3:
        cout << "Printing contents of sensor : Temperature : " << classparam.info <<endl;
        break;
    default:
        cout << "ERROR, NO DATA TO DISPLAY OR WRONG PARAMETER ENTERED!!" << endl;
        break;
    }

    
    
}


#endif
