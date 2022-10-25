///
///@author Gaspard Rochu
///@file Scheduler.hpp
///@date 04/10/2022
///@brief Class that get datas from Sensor and send them to the Server. It's like the brain between the arms and the memory.
///

#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <iostream>
#include <Windows.h>
#include <time.h>
#include <vector>
#include "Sensor.hpp"
#include "Server.hpp"

class Scheduler
{       
public:
    Humidity hum;
    Light lig;
    Temperature tem;
    Pression pre;
    Scheduler(); //Constructor
    Scheduler(const Humidity &hum, const Light &lig, const Temperature &tem, const Pression &pre); //Constructor
    friend std::ostream &operator<<(std::ostream &os, const Scheduler &scheduler); //Overloading the << operator
    static int Clock(); //This function is used to get the time of the day
    [[noreturn]] void theWork(); //Creating a function to make a loop of all the process
    
};

#endif //SCHEDULER_HPP