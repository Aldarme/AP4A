#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include "Sensor.hpp"

#include <string>

class Temperature:public Sensor
{
private:
    int value; 
    std::string type; // = "Temperature";
    std::string unity; // = "C";

public:

    Temperature();
    Temperature(const Temperature& t); 
    Temperature& operator=(const Temperature& t); 
    ~Temperature();

    int aleaGenValue() override; 
    std::string getType() override;
    std::string getUnity() override;

};

#endif // TEMPERATURE_H