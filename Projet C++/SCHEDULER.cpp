/**
 * @author YUHUIFEI
 * @file SCHEDULER.cpp
 * @date 15/10/2022
 * @brief R¨¦cup¨¦ration des donn¨¦es dans des threads s¨¦par¨¦s et envoi au serveur
 */
#ifndef SCHEDULER_CPP
#define SCHEDULER_CPP

#include "SCHEDULER.h"
#include <thread>
#include <chrono>
#include <mutex> 
#include <condition_variable>
using namespace std;
//cr¨¦er une variable de condition
condition_variable_any cond;
// Cr¨¦er un verrou mutuellement exclusif
mutex mtx;


Scheduler::Scheduler(const Server& param_server, const Temperature& param_temperature, const Humidity& param_humidity, const Light& param_light, const Pression& param_pression)
{
    this->m_server = param_server;
    this->m_temperature = param_temperature;
    this->m_humidity = param_humidity;
    this->m_light = param_light;
    this->m_pression = param_pression;
}

void go() {
    std::cout << "go running\n";
    //Blocage des fils 2 secondes
    std::this_thread::sleep_for(std::chrono::seconds(2));
    //Notifier ¨¤ tous les threads en attente que la condition a ¨¦t¨¦ remplie.
    cond.notify_all();
}

//Fonction pour r¨¦cup¨¦rer les donn¨¦es du capteur et les ¨¦crire
void Scheduler::total_tem()
{
    // Blocage du fil jusqu'¨¤ ce que la condition soit remplie
    mtx.lock();
    cond.wait(mtx);
    m_temperature.getData();
    m_server.consoleWrite(this->m_temperature);
    m_server.fileWrite(this->m_temperature);
    mtx.unlock();
}
//Fonction pour r¨¦cup¨¦rer les donn¨¦es du capteur et les ¨¦crire
void Scheduler::total_lig()
{
    mtx.lock();
    cond.wait(mtx);
    m_light.getData();
    m_server.consoleWrite(this->m_light);
    m_server.fileWrite(this->m_light);
    mtx.unlock();
}
//Fonction pour r¨¦cup¨¦rer les donn¨¦es du capteur et les ¨¦crire
void Scheduler::total_pre()
{
    mtx.lock();
    cond.wait(mtx);
    m_pression.getData();
    m_server.consoleWrite(this->m_pression);
    m_server.fileWrite(this->m_pression);
    mtx.unlock();
}
//Fonction pour r¨¦cup¨¦rer les donn¨¦es du capteur et les ¨¦crire
void Scheduler::total_hum()
{
    mtx.lock();
    cond.wait(mtx);
    m_humidity.getData();
    m_server.consoleWrite(this->m_humidity);
    m_server.fileWrite(this->m_humidity);
    mtx.unlock();
}
void Scheduler::sendServer(int param_actual_time, int param_time_temperature, int param_time_pression, int param_time_light, int param_time_humidity)
{
    //cr¨¦er 4 threads pour chacun des quatre capteurs de donn¨¦es
    thread threads[4];
    threads[0] = thread(total_tem);
    threads[1] = thread(total_hum);
    threads[2] = thread(total_pre);
    threads[3] = thread(total_lig);
    thread goThread(go);
    //Attendre les r¨¦sultats de tous les threads avant que le thread principal puisse poursuivre l'ex¨¦cution.
    goThread.join();
    for (auto& th : threads) {
        th.join();
        if (param_actual_time % param_time_temperature == 0)
        {
            total_tem();
        }
        if (param_actual_time % param_time_humidity == 0)
        {
            total_hum();
        }
        if (param_actual_time % param_time_pression == 0)
        {
            total_pre();
        }
        if (param_actual_time % param_time_light == 0)
        {
            total_lig();
        }
    }

#endif