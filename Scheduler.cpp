#include "Scheduler.h"
#include "Server.h"

#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std;

Scheduler::Scheduler() {
    sensor1 = new Humidity();
    sensor2 = new Light();
    sensor3 = new Pression();
    sensor4 = new Temperature();
}

void Scheduler::wait(float seconds) {
    time_t lastTime = time(NULL); 
    time_t delta = 0;
    while (delta < seconds) {
        time_t now = time(NULL);
        delta = (now - lastTime);
    }
}

void Scheduler::clock(){
    Server s;
    int data1,data2,data3,data4;

    while(true){
        this->wait(2.);
        data1 = sensor1->getData();
        data2 = sensor2->getData();
        data3 = sensor3->getData();
        data4 = sensor4->getData();
        s.consoleWrite(data1);
        s.consoleWrite(data2);
        s.consoleWrite(data3);
        s.consoleWrite(data4);
        s.fileWrite(data1);
        s.fileWrite(data2);
        s.fileWrite(data3);
        s.fileWrite(data4);
        cout << "" << endl; 
    }
}