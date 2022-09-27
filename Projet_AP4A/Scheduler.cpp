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

    int i;

    for(i=0;i<5;i++){

        s.consoleWrite();
        s.fileWrite("C:/Users/hugoc/OneDrive/Bureau/Projet_AP4A/Capteurs.csv");

        t.setDataT(t.aleaGenVal());
        h.setDataH(h.aleaGenVal());
        l.setDataL(l.aleaGenVal());
        p.setDataP(p.aleaGenVal());
        s.setDataTemp(t.getDataT());
        s.setDataHumi(h.getDataH());
        s.setDataLigh(l.getDataL());
        s.setDataPres(p.getDataP());

        cout << i << endl;

        s.consoleWrite();
        s.fileWrite("C:/Users/hugoc/OneDrive/Bureau/Projet_AP4A/Capteurs.csv");

    };
    //cout  << "Bonjour" << endl;
}

int Scheduler::getTemperature(){
    return this->m_temperature_scheduler;
}

int Scheduler::getHumidity(){
    return this->m_humidity_scheduler;
}

int Scheduler::getLight(){
    return this->m_light_scheduler;
}

int Scheduler::getPression(){
    return this->m_pression_scheduler;
}

void Scheduler::setData(Temperature& t, Humidity& h, Light& l, Pression& p){
    this->m_temperature_scheduler = t.getDataT();
    this->m_humidity_scheduler = h.getDataH();
    this->m_light_scheduler =l.getDataL();
    this->m_pression_scheduler = p.getDataP();
}