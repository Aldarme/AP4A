/**
 * @author RENON_Emilien
 * @file Scheduler.cpp
 * @date 23/09/2022
 * @brief 
 */

#include "Scheduler.hpp"
using namespace std;


Scheduler::Scheduler(const Server &param_server,const Temperature<float> &param_temperature,const Humidity<float> &param_humidity,const Light<bool> &param_light,const Pression<int> &param_pression)
{
    this->m_server=param_server;
    this->m_temperature=param_temperature;
    this->m_humidity=param_humidity;
    this->m_light=param_light;
    this->m_pression=param_pression;
}


void Scheduler::sendServer(int param_actual_time,int param_time_temperature,int param_time_pression,int param_time_light,int param_time_humidity)
{
    /* Utilisation d'un modulo : le temps actuel par rapport à l'interval de temps voulu du capteur
    *  Utilisation d'un IF pour utiliser ou non les méthodes du server.
    *  1 : Génération aléatoire de la valeur du capteur
    *  2 : Utilisation de la méthode consoleWrite de server pour écrire dans la console
    *  3 : Utilisation de la méthode fileWrite de server pour écrire dans un fichier
    */
    if(param_actual_time%param_time_temperature==0)
    {
        m_temperature.aleaValue();
        m_server.consoleWrite(this->m_temperature); 
        m_server.fileWrite(this->m_temperature);
    }
    if(param_actual_time%param_time_humidity==0)
    {
        m_humidity.aleaValue();
        m_server.consoleWrite(this->m_humidity); 
        m_server.fileWrite(this->m_humidity);
    }
    if(param_actual_time%param_time_pression==0)
    {
        m_pression.aleaValue();
        m_server.consoleWrite(this->m_pression); 
        m_server.fileWrite(this->m_pression);
    }
    if(param_actual_time%param_time_light==0)
    {
        m_light.aleaValue();
        m_server.consoleWrite(this->m_light); 
        m_server.fileWrite(this->m_light);
    }
   
    cout<<endl<<"====================="<<endl<<endl;
}
