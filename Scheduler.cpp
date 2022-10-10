#include <iostream>
#include "Scheduler.hpp"

static void Scheduler::theWork()
{
    while (true) //This loop never end
    {
        values = Sensor::getData();
        Server::displayValue(values);      
        Sleep(timesleep); //Included with Windows.h, sleep for a time in miliseconds

    }
}