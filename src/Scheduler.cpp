/**
 * @file Scheduler.cpp
 * @author Loric Ravassard
 * @brief Récupère les données du sensor, envoie les données au serveur, gère les cycles
 * @version 2
 * @date 2022-09-28
 */

#include "Scheduler.hpp"
#include "Sensor/Sensor.hpp"
#include "Sensor/Humidity.hpp"

#include <chrono>
#include <thread>
#include <iostream>

Scheduler& Scheduler::operator=(const Scheduler& other_p)
{
  m_stopSimulation = other_p.m_stopSimulation;
  return *this;
}

void Scheduler::endSimulation()
{
  char stop;
  do
  {
    std::cin >> stop;
  }while(stop != 'q' && stop != 'Q');
  m_stopSimulation = true;
}

void Scheduler::run()
{
  std::chrono::duration<int,std::milli> waitHumidity (m_humidity.getInterval()*1000); //conversion des intervalles des capteurs en duration
  std::chrono::duration<int,std::milli> waitLight (m_light.getInterval()*1000);
  std::chrono::duration<int,std::milli> waitPressure (m_pressure.getInterval()*1000);
  std::chrono::duration<int,std::milli> waitTemperature (m_temperature.getInterval()*1000);
  char answer;

  std::cout << "Do you want to print in the console ? (y/n) ";
  std::cin >> answer;
  if(answer == 'y' || answer == 'Y' || answer == 'o' || answer == 'O' || answer == '1')
  {
    m_server.consoleActivate(true);
  }
  else
  {
    m_server.consoleActivate(false);
  }
  std::cout << "Do you want to create log files ? (y/n) ";
  std::cin >> answer;
  if(answer == 'y' || answer == 'Y' || answer == 'o' || answer == 'O' || answer == '1')
  {
    m_server.logsActivate(true);
  }
  else
  {
    m_server.logsActivate(false);
  }

  std::chrono::system_clock::time_point endHumidity = std::chrono::system_clock::now() +  waitHumidity;       //definition de la date de la première récupération des données
  std::chrono::system_clock::time_point endLight = std::chrono::system_clock::now() +  waitLight;             //definition de la date de la première récupération des données
  std::chrono::system_clock::time_point endPressure = std::chrono::system_clock::now() +  waitPressure;       //definition de la date de la première récupération des données
  std::chrono::system_clock::time_point endTemperature = std::chrono::system_clock::now() +  waitTemperature; //definition de la date de la première récupération des données

  std::thread destroy(&Scheduler::endSimulation, this);  //création du thread qui attend que l'utilisateur arrête la simulation
  
  while(!m_stopSimulation)  //tourne tant que l'utilisateur n'a pas arrêté la simulation
  {
    
    if(std::chrono::system_clock::now() >= endHumidity)
    {
      getSensorData(&m_humidity, &m_dataHum);
      sendData(m_dataHum); 
      endHumidity = std::chrono::system_clock::now() + waitHumidity;
    }
    if(std::chrono::system_clock::now() >= endLight)
    {
      getSensorData(&m_light, &m_dataLight);
      sendData(m_dataLight); 
      endLight = std::chrono::system_clock::now() + waitLight;
    }
    if(std::chrono::system_clock::now() >= endPressure)
    {
      getSensorData(&m_pressure, &m_dataPress);
      sendData(m_dataPress); 
      endPressure = std::chrono::system_clock::now() + waitPressure;
    }
    if(std::chrono::system_clock::now() >= endTemperature)
    {
      getSensorData(&m_temperature, &m_dataTemp);
      sendData(m_dataTemp); 
      endTemperature = std::chrono::system_clock::now() + waitTemperature;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }

  destroy.join();
}