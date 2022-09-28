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
    Temperature m_temp;
    Humidity m_humi;
    Light m_lig;
    Pression m_pres;
    Server m_serv;
}

Scheduler::Scheduler(const Scheduler& s){
    this->m_temp = s.m_temp;
    this->m_humi = s.m_humi;
    this->m_lig = s.m_lig;
    this->m_pres = s.m_pres;
    this->m_serv = s.m_serv;
}

Scheduler::~Scheduler(){

}

void Scheduler::sendData(){

        m_temp.aleaGenVal();
        this->m_serv.m_temperature_test = m_temp.m_valeur;
        m_humi.aleaGenVal();
        this->m_serv.m_humidity_test = m_humi.m_valeur;
        m_lig.aleaGenVal();
        this->m_serv.m_light_test = m_lig.m_valeur;
        m_pres.aleaGenVal();
        this->m_serv.m_pression_test = m_pres.m_valeur;
        m_serv.consoleWrite();
        m_serv.fileWrite("C:/Users/hugoc/OneDrive/Bureau/Projet_AP4A/Capteurs.csv");
}
