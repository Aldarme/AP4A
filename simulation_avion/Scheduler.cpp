#include "Scheduler.hpp"

#include <stdlib.h>
#include <time.h>

#include <fstream>
#include <iostream>
using namespace std;

#include <chrono> 
using namespace std::chrono;

Scheduler::Scheduler()
{
    pHu = new Humidity(); 
    pTe = new Temperature(); 
    pPr = new Pression(); 
    pLi = new Light(); 
}

Scheduler::~Scheduler()
{
    delete pHu; 
    delete pTe; 
    delete pPr; 
    delete pLi; 
}

void Scheduler::scheduler() {

    Server server; 

    server.resetLogs();
    srand(time(NULL));

    int valueHu, valueTe, valuePr, valueLi; 

    bool stop_condition = true;

    while (stop_condition)
    {
        
        clock(3); 
        valueHu = pHu->getData();
        server.consoleWrite(valueHu, pHu->getSensorType(), pHu->getSensorUnity());
        server.fileWrite(valueHu, pHu->getSensorType(), pHu->getSensorUnity()); 

        valueTe = pTe->getData( ); 
        server.consoleWrite(valueTe, pTe->getSensorType(), pTe->getSensorUnity());
        server.fileWrite(valueTe, pTe->getSensorType(), pTe->getSensorUnity());

        valuePr = pPr->getData(); 
        server.consoleWrite(valuePr, pPr->getSensorType(), pPr->getSensorUnity());
        server.fileWrite(valuePr, pPr->getSensorType(), pPr->getSensorUnity()); 

        valueLi = pLi->getData();
        server.consoleWrite(valueLi, pLi->getSensorType(), pLi->getSensorUnity());
        server.fileWrite(valueLi, pLi->getSensorType(), pLi->getSensorUnity());
 
        server.consoleWrite();
        server.fileWrite();

    }
}

void clock(int time) {

    auto start = high_resolution_clock::now(); 
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);

    do {
        stop = high_resolution_clock::now(); 
        duration = duration_cast<seconds>(stop - start); 
    } while (duration.count() < time); 

}