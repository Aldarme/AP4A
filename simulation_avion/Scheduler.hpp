/**
 * @author  gilles_maurer
 * @file    Scheduler.hpp
 * @date    03/10/2022
 * @brief   Scheduler class, manage the sensors and the server, use the clock to regulate
 */

#include "Server.hpp"
#include "Sensor.hpp"

#include "Humidity.hpp"
#include "Pression.hpp"
#include "Light.hpp"
#include "Temperature.hpp"

class Scheduler
{
private:
    Sensor* pHu;
    Sensor* pTe; 
    Sensor* pPr;
    Sensor* pLi; 
public:
    Scheduler();
    Scheduler(const Scheduler& param);
    Scheduler& operator=(const Scheduler& param);
    ~Scheduler();

    void scheduler();   

};

void clock(int time);

void initilizeServerParameters(Server& server);

