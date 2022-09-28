/**
 * @author choulot_hugo
 * @file Scheduler.cpp
 * @date 23/09/2022
 * @brief Cette classe permet de gérer les flux de données envoyé par les capteurs
 */

#include <iostream>
#include "Scheduler.hpp"
#include "Sensor.hpp"
#include "Server.hpp"

using namespace std;

Scheduler::Scheduler(){
    m_temperature_scheduler = 0;
    m_humidity_scheduler = 0;
    m_light_scheduler = 0;
    m_pression_scheduler = 0;
}

Scheduler::Scheduler(const Scheduler& s){
    this->m_temperature_scheduler = s.m_temperature_scheduler;
    this->m_humidity_scheduler = s.m_humidity_scheduler;
    this->m_light_scheduler = s.m_light_scheduler;
    this->m_pression_scheduler = s.m_pression_scheduler;
}

Scheduler::~Scheduler(){

}

void Scheduler::sendData(Temperature& t, Humidity& h, Light& l, Pression& p, Server& s){
    
    m_temperature_scheduler = t.aleaGenVal();
    m_humidity_scheduler = h.aleaGenVal();
    m_light_scheduler = l.aleaGenVal();
    m_pression_scheduler = p.aleaGenVal();

    s.m_temperature_test = m_temperature_scheduler;
    s.m_humidity_test = m_humidity_scheduler;
    s.m_light_test = m_light_scheduler;
    s.m_pression_test = m_pression_scheduler;

    s.consoleWrite();
    s.fileWrite("C:/Users/hugoc/OneDrive/Bureau/Projet_AP4A_1/Capteurs.csv");
}