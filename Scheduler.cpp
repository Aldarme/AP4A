#include "Scheduler.h"

#include <iostream>

using namespace std;

Scheduler::Scheduler() {
    s1 = Humidity();
    s2 = Light();
    s3 = Pression();
    s4 = Temperature();
    delta();
}

void Scheduler::delta() {
    write(s1);
    write(s2);
    write(s3);
    write(s4);
}

void Scheduler::write(Sensor& s) {
    cout << s.getData() << endl;
}


