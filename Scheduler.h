#pragma once

#include "Sensor.h"

#include "Temperature.h"
#include "Light.h"
#include "Humidity.h"
#include "Pression.h"

class Scheduler {
private :
    Sensor s1, s2, s3, s4;
public:
    Scheduler();
    
private:
    void delta();
    void write(Sensor& s);
};

