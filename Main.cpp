///
///@author Gaspard Rochu
///@file Main.cpp
///@date 09/10/2022
///@brief Main, where all things start.
///

#include <iostream>
#include <time.h>
#include "Scheduler.hpp"

int main()
{
    srand(time(NULL)); //This function is used to get a random number
    Scheduler scheduler;
    std::cout << scheduler << "\n";
    scheduler.theWork(); //Calling the function theWork
    return 0;
}