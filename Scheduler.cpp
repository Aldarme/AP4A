#include "Scheduler.h"

#include <iostream>
#include <chrono>

using namespace std;

Scheduler::Scheduler() {
    s1 = Humidity();
    s2 = Light();
    s3 = Pression();
    s4 = Temperature();
}

void Scheduler::delta() {
    time_t lastTime = time(NULL);
    double delta = 0;
    double ticks = 1;
    int count = 0;

    while(count  < 7){
       time_t now = time(NULL);
        delta += (now - lastTime);
        lastTime = now;
       if(delta >= 1) {
            s1.write();
            s2.write();
            s3.write();
            s4.write();
            delta = 0;
            count++;
       }
    }
}