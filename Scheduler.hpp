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
#include <vector>
#include "Sensor.hpp"
#include "Server.hpp"
#include "Pression.hpp"

class Scheduler
{       
public:
    float timesleep=1000; //Used in the Sleep command in Scheduler.cpp
    std::vector<float> values;    
    static void theWork(); //Creating a function to make a loop of all the process
    
};

#endif //SCHEDULER_HPP