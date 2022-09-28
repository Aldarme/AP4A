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
    m_server.consoleWrite(this->m_temperature,this->m_humidity,this->m_light,this->m_pression);   
    m_server.fileWrite(this->m_temperature,this->m_humidity,this->m_light,this->m_pression);
    this_thread::sleep_for(chrono::milliseconds(2*1000));
    cout<<endl<<"====================="<<endl<<endl;
}
