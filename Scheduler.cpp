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

/*void Scheduler::clock() {
    Server s;
    time_t lastTime = time(NULL);
    double delta = 0;
    double ticks = 1;
    int count = 0;
    int data;

    while(count  < 7){
       time_t now = time(NULL);
        delta += (now - lastTime);
        lastTime = now;
       if(delta >= 1) {
            data = sensor1->getData();
            s.consoleWrite(data);
            s.fileWrite(data);
            delta --;
            count++;
       }
    }
}*/

void Scheduler::wait(int seconds) {
    time_t start = time(NULL); 
    time_t delta;
    do {
        time_t lastTime = time(NULL);
        delta = lastTime - start;
    } while (delta < seconds);
}