/**
 * @author RENON Emilien
 * @file Scheduler.cpp
 * @date 23/09/2022
 * @brief 
 */

#include "Scheduler.hpp"
using namespace std;

Scheduler::Scheduler(Server &param_server,Temperature &param_temperature,Humidity &param_humidity,Light &param_light,Pression &param_pression){
    this->m_server=param_server;
    this->m_temperature=param_temperature;
    this->m_humidity=param_humidity;
    this->m_light=param_light;
    this->m_pression=param_pression;
}


void Scheduler::setValue(){
    int interval = 0;
    m_temperature.aleaValue();
    m_humidity.aleaValue();
    m_light.aleaValue();
    m_pression.aleaValue();
    m_server.consoleWrite(m_temperature.getValue());
    m_server.consoleWrite(m_humidity.getValue());
    m_server.consoleWrite(m_pression.getValue());
    m_server.consoleWrite(m_light.getValue());
    this_thread::sleep_for(chrono::milliseconds(this->m_time*1000));
    
}
