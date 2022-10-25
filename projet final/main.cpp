#include <iostream>
#include <string>
#include <stdlib.h>

#include "Scheduler.hpp"
#include "DataPacket.hpp"
#include "Server.hpp"
#include "Pression.hpp"
#include "Humidity.hpp"
#include "Temperature.hpp"
#include "Light.hpp"
#include "Sensor.hpp"


int main ()
{

    int time = 0;

    Scheduler scheduler1;
    Server server1;


   
    
    while (1){
    time++;
    scheduler1.getData(time);
  

    server1.consolWrite(time);
    server1.fileWrite(time);

    Sleep(10000);

    }

   