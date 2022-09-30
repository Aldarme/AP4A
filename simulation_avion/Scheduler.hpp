#include "Server.hpp"
#include "Sensor.hpp"

#include "Humidity.hpp"
#include "Pression.hpp"
#include "Light.hpp"
#include "Temperature.hpp"

class Scheduler
{
private:
    Sensor* hu;
    Sensor* te; 
    Sensor* pr;
    Sensor* li; 
public:
    Scheduler();
    ~Scheduler();

    void scheduler();   

};


void clock(int time);


