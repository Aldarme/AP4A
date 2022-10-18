/**
 * @author DURUPT Corentin
 * @file Scheduler.cpp
 * @date 23/09/2022
 * @brief This is the implementation of the different methods of the class Scheduler.
*/

#include<windows.h>
#include"Scheduler.hpp"
#include"Server.hpp"
#include "Temperature.hpp"
#include "Humidity.hpp"
#include "Light.hpp"
#include "Pressure.hpp"
#include<iostream>
using namespace std;

Scheduler::Scheduler(){}

Scheduler::~Scheduler(){}

Scheduler::Scheduler(int freq_t, int freq_h, int freq_l, int freq_p){
    this->m_frequency_t = freq_t;
    this->m_frequency_h = freq_h;
    this->m_frequency_l = freq_l;
    this->m_frequency_p = freq_p;
}

void Scheduler::timer(Temperature& t, Humidity& h, Light& l, Pressure& p){
    int time_start = 0;
    int time_end = 500000;

    while(time_start != time_end){
        Server server(t, h, l, p);
        if(time_start % this->m_frequency_t == 0){
            t.getData();
            server.action("display and stock", server, t);
        } 
        if(time_start % this->m_frequency_h == 0){
            h.getData();
            server.action("display and stock", server, h);
        } 
        if(time_start % this->m_frequency_l == 0){
            l.getData();
            server.action("display and stock", server, l);
        } 
        if(time_start % this->m_frequency_p == 0){
            p.getData();
            server.action("display and stock", server, p);
        }
        time_start++;
    }

}

