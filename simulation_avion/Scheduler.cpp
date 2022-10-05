#include "Scheduler.hpp"

#include <stdlib.h>
#include <time.h>

#include <fstream>
#include <iostream>
using namespace std;

#include <chrono> 
using namespace std::chrono;

#define WAITING_TIME 3


//Definition of the canonical form
Scheduler::Scheduler()
{
    m_pHu = new Humidity(); 
    m_pTe = new Temperature(); 
    m_pPr = new Pression(); 
    m_pLi = new Light(); 
}

Scheduler::Scheduler(const Scheduler& param_sc)
{
    m_pHu = new Humidity(); 
    *(this->m_pHu) = *(param_sc.m_pHu);

    m_pTe = new Temperature(); 
    *(this->m_pTe) = *(param_sc.m_pTe);

    m_pPr = new Pression(); 
    *(this->m_pPr) = *(param_sc.m_pPr);

    m_pLi = new Light(); 
    *(this->m_pLi) = *(param_sc.m_pLi);
}

Scheduler& Scheduler::operator=(const Scheduler& param_sc)
{
    *(this->m_pHu) = *(param_sc.m_pHu);
    *(this->m_pTe) = *(param_sc.m_pTe);
    *(this->m_pPr) = *(param_sc.m_pPr);
    *(this->m_pLi) = *(param_sc.m_pLi);
    return *this;
}

Scheduler::~Scheduler()
{
    delete m_pHu; 
    delete m_pTe; 
    delete m_pPr; 
    delete m_pLi; 
}

//manage all the simulation
void Scheduler::scheduler() 
{
    //create the server
    Server server; 

    //reset logs + ask the user if he want to activate the console and the logs 
    server.resetLogs();
    initilizeServerParameters(server);

    srand(time(NULL));

    int valueHu, valueTe, valuePr, valueLi; 

    //endless loop
    while (true)
    {
        
        clock(WAITING_TIME); 
        valueHu = m_pHu->getData();
        server.consoleWrite(valueHu, m_pHu->getSensorType(), m_pHu->getSensorUnity());
        server.fileWrite(valueHu, m_pHu->getSensorType(), m_pHu->getSensorUnity()); 

        valueTe = m_pTe->getData( ); 
        server.consoleWrite(valueTe, m_pTe->getSensorType(), m_pTe->getSensorUnity());
        server.fileWrite(valueTe, m_pTe->getSensorType(), m_pTe->getSensorUnity());

        valuePr = m_pPr->getData(); 
        server.consoleWrite(valuePr, m_pPr->getSensorType(), m_pPr->getSensorUnity());
        server.fileWrite(valuePr, m_pPr->getSensorType(), m_pPr->getSensorUnity()); 

        valueLi = m_pLi->getData();
        server.consoleWrite(valueLi, m_pLi->getSensorType(), m_pLi->getSensorUnity());
        server.fileWrite(valueLi, m_pLi->getSensorType(), m_pLi->getSensorUnity());
 
        //add a new line in the logs and the console
        server.consoleWrite();
        server.fileWrite();

    }
}

//wait param_time seconds
void clock(int param_time) 
{
    auto start = high_resolution_clock::now(); 
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);

    do {
        stop = high_resolution_clock::now(); 
        duration = duration_cast<seconds>(stop - start); 
    } while (duration.count() < param_time); 
}


//ask the user if he want to activate the console and the logs
void initilizeServerParameters(Server& param_server) 
{
    //ask the user if he wants to activate the logs
    char answer; 
    cout << "Do you want to activate the logs ? (y/n)" << endl; 
    cin >> answer; 
    if (answer == 'y') 
    {
        param_server.activateLogs();
    }
    //ask the user if he wants to activate the console
    cout << "Do you want to activate the console ? (y/n)" << endl; 
    cin >> answer; 
    if (answer == 'y') 
    {
        param_server.activateConsole();
    }
}