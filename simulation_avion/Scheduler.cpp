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
    hu = new Humidity(); 
    te = new Temperature(); 
    pr = new Pression(); 
    li = new Light(); 
}

Scheduler::~Scheduler()
{
    delete hu; 
    delete te; 
    delete pr; 
    delete li; 
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
        valueHu = hu->getData();
        server.consoleWrite(valueHu, hu->getSensorType(), hu->getSensorUnity());
        server.fileWrite(valueHu, hu->getSensorType(), hu->getSensorUnity()); 

        valueTe = te->getData( ); 
        server.consoleWrite(valueTe, te->getSensorType(), te->getSensorUnity());
        server.fileWrite(valueTe, te->getSensorType(), te->getSensorUnity());

        valuePr = pr->getData(); 
        server.consoleWrite(valuePr, pr->getSensorType(), pr->getSensorUnity());
        server.fileWrite(valuePr, pr->getSensorType(), pr->getSensorUnity()); 

        valueLi = li->getData();
        server.consoleWrite(valueLi, li->getSensorType(), li->getSensorUnity());
        server.fileWrite(valueLi, li->getSensorType(), li->getSensorUnity());
 
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