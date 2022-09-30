#ifndef HUMIDITY_H
#define HUMIDITY_H

#include "Sensor.hpp"

#include <string> 

class Humidity: public Sensor 
{
private:
    int value; 
    std::string type; // = "Humidity";
    std::string unity; // = "%";

public:
    Humidity();
    Humidity(const Humidity& h); 
    Humidity& operator=(const Humidity& h); 
    ~Humidity();


    int aleaGenValue() override; 
    std::string getType() override;
    std::string getUnity() override;

};


#endif // HUMIDITY_H