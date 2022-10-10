/**
 *  @author BIN ADNAN Muhammad Izzat Affandi
 *  @file Sensor.cpp
 *  @date 8/10/2022
 *  @brief This file contains implementations of the class "Server"
 */

#include "Server.hpp"
#include "Packet.hpp"
#include <iostream>
#include <fstream>

void Server::consolWrite(Packet packet_p)
{
    std::cout<<"Temperature : "<<packet_p.getTemperature()<<std::endl;
    std::cout<<"Pression : "<<packet_p.getPression()<<std::endl;
    std::cout<<"Humidity : "<<packet_p.getHumidity()<<std::endl;
    std::cout<<"Light : "<<packet_p.getLight()<<std::endl;
}

void Server::fileWrite(Packet packet_p)
{
    std::ofstream fichLog;
    fichLog.open("logTemperature.txt",std::ios_base::app);
    fichLog <<"\n"<<packet_p.getTemperature() << " °C";
    fichLog.close();
    fichLog.open("logPression.txt",std::ios_base::app);
    fichLog <<"\n"<< packet_p.getPression() << " PSI";
    fichLog.close();
    fichLog.open("logHumidity.txt",std::ios_base::app);
    fichLog <<"\n"<< packet_p.getHumidity() << " %";
    fichLog.close();
    fichLog.open("logLight.txt",std::ios_base::app);
    fichLog <<"\n"<< packet_p.getLight();
    fichLog.close();
    
}