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

void Server::consolWriteTemp(Packet packet_p)
{
    std::cout<<"Temperature : "<<packet_p.getTemperature()<<std::endl;
}

void Server::consolWritePres(Packet packet_p)
{
    std::cout<<"Pression : "<<packet_p.getPression()<<std::endl;
}

void Server::consolWriteHum(Packet packet_p)
{
    std::cout<<"Humidity : "<<packet_p.getHumidity()<<std::endl;
}

void Server::consolWriteLight(Packet packet_p)
{
    std::cout<<"Light : "<<packet_p.getLight()<<std::endl;
}

void Server::fileWriteTemp(Packet packet_p)
{
    std::ofstream fichLog;
    fichLog.open("logTemperature.txt",std::ios_base::app);
    fichLog <<"\n"<<packet_p.getTemperature() << " °C";
    fichLog.close();
}

void Server::fileWritePres(Packet packet_p)
{
    std::ofstream fichLog;
    fichLog.open("logPression.txt",std::ios_base::app);
    fichLog <<"\n"<< packet_p.getPression() << " PSI";
    fichLog.close();
}

void Server::fileWriteHum(Packet packet_p)
{
    std::ofstream fichLog;
    fichLog.open("logHumidity.txt",std::ios_base::app);
    fichLog <<"\n"<< packet_p.getHumidity() << " %";
    fichLog.close();
}

void Server::fileWriteLight(Packet packet_p)
{
    std::ofstream fichLog;
    fichLog.open("logLight.txt",std::ios_base::app);
    fichLog <<"\n"<< packet_p.getLight();
    fichLog.close();
}