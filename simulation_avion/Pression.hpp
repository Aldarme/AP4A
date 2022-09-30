#ifndef PRESSION_H
#define PRESSION_H

#include "Sensor.hpp" 

class Pression:public Sensor
{
private:
    int value; 

public:

    Pression();
    Pression(const Pression& p); 
    Pression& operator=(const Pression& p); 
    Pression& operator=(float p);
    ~Pression();

    int aleaGenValue() override; 

};

#endif // PRESSION_H