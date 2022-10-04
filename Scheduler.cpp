/**
 * @author DURUPT Corentin
 * @file Scheduler.cpp
 * @date 23/09/2022
 * @brief This is the implementation of the different methods of the class Scheduler.
*/

#include<windows.h>
#include"Scheduler.hpp"
#include"Sensor.hpp"
#include"Server.hpp"
#include<iostream>
using namespace std;

Scheduler::Scheduler(){}

Scheduler::~Scheduler(){}

Scheduler::Scheduler(int freq){
    this->m_frequency = freq;
}

Server Scheduler::timer(Temperature& t, Humidity& h, Light& l, Pressure& p){
    t.aleaGenVal();
    h.aleaGenVal();
    l.aleaGenVal();
    p.aleaGenVal();
    Server server(t, h, l, p);
    server.consolWrite(server);
    server.fileWrite(server);
    Sleep(this->m_frequency);

    return server;
}

