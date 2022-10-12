/**
 * @file Scheduler.cpp
 * @author Loric Ravassard
 * @brief Récupère les données du sensor, envoie les données au serveur, gère les cycles
 * @version 1
 * @date 2022-09-28
 */

#include "Scheduler.hpp"

#include <chrono>
#include <thread>
#include <iostream>

void Scheduler::getAllData()
{
  std::time_t now;
  char buffer [80];
  std::time(&now);
  std::strftime(buffer,sizeof(buffer),"%d/%m/%Y %H:%M:%S", std::localtime(&now)); //récupère la date a laquelle on a récupéré les données

  //on rempli le package avec toutes les données
  m_dataPkg.addMeasure(buffer, "humidity", m_humidity.getData(), m_humidity.getUnit());
  m_dataPkg.addMeasure(buffer, "light", m_light.getData(), m_light.getUnit());
  m_dataPkg.addMeasure(buffer, "pressure", m_pressure.getData(), m_pressure.getUnit());
  m_dataPkg.addMeasure(buffer, "temperature", m_temperature.getData(), m_temperature.getUnit());
}

void Scheduler::sendData()
{
  m_server.dataRcv(m_dataPkg);
  m_dataPkg.clear();
}

void Scheduler::run(int time_p, int wait_p)
{
  int timeEnd = time_p*1000;  //conversion en ms
  int timeSend = wait_p*1000; //conversion en ms
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
  
  std::chrono::duration<int,std::milli> runningTime (timeEnd);
  std::chrono::system_clock::time_point end = std::chrono::system_clock::now() + runningTime; //definition de la date de fin de la simulation

  std::chrono::duration<int,std::milli> waitingTime (timeSend);
  std::chrono::system_clock::time_point endWait = std::chrono::system_clock::now() + waitingTime; //definition de la date de la première récupération des données

  while(std::chrono::system_clock::now() < end) //Tourne pendant le temps qui a été défini par l'utilisateur
  {
    if(std::chrono::system_clock::now() >= endWait)
    {
      getAllData();
      sendData(); 
      endWait = std::chrono::system_clock::now() + waitingTime;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
  
}