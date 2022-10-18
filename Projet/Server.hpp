/**
* @author Alan HERVE
* @file Server.hpp
* @date 01/10/2022
* @brief Is in charge of writing values received from the captors in files and in the console
**/


#ifndef SERVER_HPP
#define SERVER_HPP
#pragma once
#include <iostream>
#include <fstream>



class Server {

    private:

        bool m_consolActivation;
        bool m_logActivation;
        
    
    public: 

    Server() :
    m_consolActivation(true),
    m_logActivation(true)
    {

        
        this->initiateFile();
        


    }

    Server(const Server& copy) :
    m_consolActivation(copy.m_consolActivation),
    m_logActivation(copy.m_logActivation)
    {

        
    }
    
    void activateConsole();

    void activateLog();

    void deActivateConsole();
    void deActivateLog();
    void activateAll();
    void deActivateAll();

    bool statusConsole();
    bool statusLog();

    virtual ~Server(){
        
    }



   //initiate log files
    void initiateFile();

    
/**
* @brief Open different file depending on parameter's type and then write value into said file
* @param classparam one of the 4 child classes of Sensor
**/
template <class Type> void fileWrite(Type p_classparam)
{
    if(this->m_logActivation){


        std::string display_data;
        std::ofstream myfile;

        switch (p_classparam.type)
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
            std::cout << "ERROR, NO DATA TO SAVE !!" << std::endl;
            break;
        }

        if (myfile.is_open())
        {
            myfile << p_classparam.info << std::endl;
            myfile.close();
        }else
        {
            std::cout << "ERROR, FILE NOT OPENING" << std::endl;
        }

        

    }
}

/**
* @brief Displays information of parameter, display is unique for each child class of Sensor
* @param classparam one of the four child class of class Sensor
**/
template <class Type> void consoleWrite(Type p_classparam)
{
    
    if(this->m_consolActivation){

        switch (p_classparam.type)
        {
        case 0:
       
            std::cout << "Printing contents of sensor : Humidity : " << p_classparam.info <<std::endl;
            break;
        case 1:
            std::cout << "Printing contents of sensor : Light : " << p_classparam.info <<std::endl;
            break;
        case 2:
            std::cout << "Printing contents of sensor : Pression : " << p_classparam.info <<std::endl;
            break;
        case 3:
            std::cout << "Printing contents of sensor : Temperature : " << p_classparam.info <<std::endl;
            break;
        default:
            std::cout << "ERROR, NO DATA TO DISPLAY OR WRONG PARAMETER ENTERED!!" << std::endl;
            break;
        }

    }
    
}
};




#endif