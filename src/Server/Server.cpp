/**
 * @file Server.cpp
 * @author Flavian THEUREL
 * @brief The server receives datas from captors and displays/saves them
 * @version 0.1
 * @date 2022-09-28
 */

#include "Server.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>

Server::Server(): m_temperatureBuffer(), m_humidityBuffer(), m_pressureBuffer(), m_lightBuffer(){}

Server::Server(const Server& serv_p): m_temperatureBuffer(serv_p.m_temperatureBuffer), m_humidityBuffer(serv_p.m_humidityBuffer), m_pressureBuffer(serv_p.m_pressureBuffer), m_lightBuffer(serv_p.m_lightBuffer){}

Server::~Server(){}

Server& Server::operator=(const Server& serv_p)
{
  m_temperatureBuffer = serv_p.m_temperatureBuffer;
  m_humidityBuffer = serv_p.m_humidityBuffer;
  m_pressureBuffer = serv_p.m_pressureBuffer;
  m_lightBuffer = serv_p.m_lightBuffer;
}

void Server::fileWriter(EType type_p)
{
  std::ofstream m_outfile;

  // Select the correct data type to print in the corresponding log file
  switch (type_p)
  {
    case e_temperature:
    {
      m_outfile.open("logs/temperature_log.txt", std::ios_base::app); // Append the new data to the Save file
      m_outfile << m_temperatureBuffer << "\t";
    }
    break;

    case e_humidity:
    {
      m_outfile.open("logs/humidity_log.txt", std::ios_base::app); // Append the new data to the Save file
      m_outfile << m_humidityBuffer << "\t";
    }
    break;

    case e_pressure:
    {
      m_outfile.open("logs/presure_log.txt", std::ios_base::app); // Append the new data to the Save file
      m_outfile << m_pressureBuffer << "\t";
    }
    break;

    case e_light:
    {
      m_outfile.open("logs/light_log.txt", std::ios_base::app); // Append the new data to the Save file
      m_outfile << m_lightBuffer << "\t";
    }
    break;
  
    default:
    break;
  }

  m_outfile.close();
}

void Server::consolWrite(EType type_p)
{
  // Select the according data type
  switch (type_p)
  {
    case e_temperature:
    {
      std::cout << "\r" << "Temperature : " << std::setw(3) << std::setfill('0') << m_temperatureBuffer << "°C" << std::flush;
    }
    break;

    case e_humidity:
    {
      std::cout << "\r" << "Humidity : " << std::setw(3) << std::setfill('0') << m_humidityBuffer << "%" << std::flush;
    }
    break;

    case e_pressure:
    {
      std::cout << "\r" << "Pressure : " << std::setw(3) << std::setfill('0') << m_pressureBuffer << "bar" << std::flush;
    }
    break;

    case e_light:
    {
      std::cout << "\r" << "Light : " << std::setw(3) << std::setfill('0') << m_lightBuffer << "L" << std::flush;
    }
    break;
  
    default:
    break;
  }
}

void Server::receiveData(EType type_p, int data_p)
{
  // Select the according data type
  switch (type_p)
  {
    case e_temperature:
    {
      m_temperatureBuffer = data_p;
    }
    break;

    case e_humidity:
    {
      m_humidityBuffer = data_p;
    }
    break;

    case e_pressure:
    {
      m_pressureBuffer = data_p;
    }
    break;

    case e_light:
    {
      m_lightBuffer = data_p;
    }
    break;
  
    default:
    break;
  }
}

void Server::operator>>(EType type_p)
{
  if (m_settingLog)
  {
    fileWriter(type_p);
  }
  if (m_settingDisplay)
  {
    consolWrite(type_p);
  }  
}