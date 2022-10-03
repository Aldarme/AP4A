#ifndef PRESSION_H
#define PRESSION_H

#include "Sensor.hpp" 

#include <string>

class Pression:public Sensor
{
private:

public:

    Pression();
    Pression(const Pression& p); 
    Pression& operator=(const Pression& p); 
    ~Pression();

    int aleaGenValue() override;
    std::string getType() override;
    std::string getUnity() override; 

};

#endif // PRESSION_H