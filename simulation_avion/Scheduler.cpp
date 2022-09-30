#include "Scheduler.hpp"

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
}

void Scheduler::scheduler() {

    Server server; 

    int valueHu, valueTe, valuePr, valueLi; 

    bool stop_condition = true;

    while (stop_condition)
    {
        
        clock(3); 
        valueHu = hu->getData();
        server.consoleWrite(valueHu, "humidity", "%");
        server.fileWrite(valueHu, "humidity", "%"); 

        valueTe = te->getData( ); 
        server.consoleWrite(valueTe, "temperature", "C");
        server.fileWrite(valueTe, "temperature", "C"); 

        valuePr = pr->getData(); 
        server.consoleWrite(valuePr, "pression", "hPa");
        server.fileWrite(valuePr, "pression", "hPa"); 

        valueLi = li->getData();
        server.consoleWrite(valueLi, "light", "on/off");
        server.fileWrite(valueLi, "light", "on/off"); 
 
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