/**
 * @author RENON Emilien
 * @file Scheduler.cpp
 * @date 23/09/2022
 * @brief 
 */

#include "Scheduler.hpp"
using namespace std;


Scheduler::Scheduler(Server &param_server,Temperature<float> &param_temperature,Humidity<float> &param_humidity,Light<bool> &param_light,Pression<int> &param_pression){
    this->m_server=param_server;
    this->m_temperature=param_temperature;
    this->m_humidity=param_humidity;
    this->m_light=param_light;
    this->m_pression=param_pression;
}


void Scheduler::sendServer(int param_time_occur,int param_time_temperature,int param_time_pression,int param_time_light,int param_time_humidity){
    if(param_time_occur%param_time_temperature==0){
        m_temperature.aleaValue();
        m_server.consoleWrite(this->m_temperature); 
        m_server.fileWrite(this->m_temperature);
    }
    if(param_time_occur%param_time_humidity==0){
        m_humidity.aleaValue();
        m_server.consoleWrite(this->m_humidity); 
        m_server.fileWrite(this->m_humidity);
    }
    if(param_time_occur%param_time_pression==0){
        m_pression.aleaValue();
        m_server.consoleWrite(this->m_pression); 
        m_server.fileWrite(this->m_pression);
    }
    if(param_time_occur%param_time_light==0){
        m_light.aleaValue();
        m_server.consoleWrite(this->m_light); 
        m_server.fileWrite(this->m_light);
    }
   
    cout<<endl<<"====================="<<endl<<endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
}
