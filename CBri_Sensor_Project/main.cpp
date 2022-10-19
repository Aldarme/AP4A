/**
 * @author BRICHET_Clement
 * @file Humidity.cpp
 * @date 23/09/2022
 * @brief This project's goal is to simulate a plane environment with its sensors and retrieve the randomly generated data from the sensors.
 * */

#include "Scheduler.hpp"

int main()
{
    //We start by initialising the random generator.
    srand(time(0));

    //Small introduction
    std::cout << "To activate/desactivate log writing, type 'l' in the console (default: activated).\n" << std::endl;
    sleep(1);
    std::cout << "To activate/desactivate console writing, type 'c' in the console (default: activated).\n" << std::endl;
    sleep(2);

    //To separate from the rest
    std::cout << "\n=======================================================================\n\n" << std::endl;

    Scheduler sched;
    sched.startScheduler(); //The while loop is included in the scheduler
    
    return 0;
}