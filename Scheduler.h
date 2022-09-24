#pragma once

#include "Sensor.cpp"

#include "Temperature.cpp"
#include "Light.cpp"
#include "Humidity.cpp"
#include "Pression.cpp"

class Scheduler {
private :
    Sensor s1, s2, s3, s4;
public:
    Scheduler();
    
private:
    void delta();
    void write(Sensor& s);
};

