/**
 * @author Clément BRICHET
 * @file Scheduler.cpp
 * @date 23/09/2022
 * @brief This project's goal is to simulate a plane environment with its sensors and retrieve the randomly generated data from the sensors.
 * */

#include "Scheduler.hpp"
#include <conio.h>

//Default constructor
Scheduler::Scheduler()
{
    //Each of them use the default constructor of each object
    Humidity hSensor;
    Temperature tSensor;
    Light lSensor;
    Pressure pSensor;

    Server s;

    //We set those values to true by default
    bool m_logActivated(true), m_consoleActivated(true);
}

//Constructor by copy
Scheduler::Scheduler(const Scheduler& sourceScheduler_p)
{
    m_hSensor = sourceScheduler_p.m_hSensor;
    m_tSensor = sourceScheduler_p.m_tSensor;
    m_lSensor = sourceScheduler_p.m_lSensor;
    m_pSensor = sourceScheduler_p.m_pSensor;

    m_serv = sourceScheduler_p.m_serv;

    m_logActivated = sourceScheduler_p.m_logActivated;
    m_consoleActivated = sourceScheduler_p.m_consoleActivated;

}

//= operator
Scheduler& Scheduler::operator=(const Scheduler& sourceScheduler_p)
{
    m_hSensor = sourceScheduler_p.m_hSensor;
    m_tSensor = sourceScheduler_p.m_tSensor;
    m_lSensor = sourceScheduler_p.m_lSensor;
    m_pSensor = sourceScheduler_p.m_pSensor;

    m_serv = sourceScheduler_p.m_serv;

    m_logActivated = sourceScheduler_p.m_logActivated;
    m_consoleActivated = sourceScheduler_p.m_consoleActivated;

    return *this;

}

//Destructor
Scheduler::~Scheduler(){}


void Scheduler::switchLogActivation(void)
{
    this->m_logActivated = !(this->m_logActivated);
}

void Scheduler::switchConsoleActivation(void)
{
    this->m_consoleActivated = !(this->m_consoleActivated);
}

void Scheduler::startScheduler(void)
{
    //This will be our time counter. It is incremented every second, but this can be changed on the sleep function later in the following loop.
    int step(0);

    //Change this condition later
    while(true)
    {
        /**We define different timers for each data:
         * Temperature: every second
         * Pressure: every two seconds
         * Light: every three seconds
         * Humidity: every five seconds
         * */

        //We start by checking if either 'l' or 'c' has been typed into the console.
        //(To activate/desactivate log or console writing respectively.)
        if(kbhit())     //Memo for self: kbhit = keyboard hit
        {
            switch(getch())
            {
                case 'l':
                    this->switchLogActivation();
                    break;
                
                case 'c':
                    this->switchConsoleActivation();
                    break;

                //We need to make sure nothing happens if any other key is typed
                default:
                    break;
            }
        }


        //if step%1
        //We make this happen every step.
        this->m_tSensor.setData();
        //We check everytime if writing is enabled, otherwise we don't need it.
        if(this->m_consoleActivated) this->m_serv.consoleWrite(m_tSensor);
        if(this->m_logActivated) this->m_serv.fileWrite(m_tSensor);
        //All of the other are similar, except we need ifs for the step counting.

        if(step%2==0)
        {
            this->m_pSensor.setData();
            if(this->m_consoleActivated) this->m_serv.consoleWrite(m_pSensor);
            if(this->m_logActivated) this->m_serv.fileWrite(m_pSensor);
        }

        if(step%3==0)
        {
            this->m_lSensor.setData();
            if(this->m_consoleActivated) this->m_serv.consoleWrite(m_lSensor);
            if(this->m_logActivated) this->m_serv.fileWrite(m_lSensor);
        }

        if(step%5==0)
        {
            this->m_hSensor.setData();
            if(this->m_consoleActivated) this->m_serv.consoleWrite(m_hSensor);
            if(this->m_logActivated) this->m_serv.fileWrite(m_hSensor);
        }

        //This is just a separator to put some air in the console writing, so we don't need it if we deactivated log writing.
        if(this->m_consoleActivated) std::cout << "\n=======================================================================\n\n" << std::endl;

        sleep(1);

        //We do this in order to avoid reaching the int limit if we let the program run for too long.
        //We do %30 because every other modulo gets "synchronised" when step=30.
        if(step%30==0){step=0;}

        step++;
    }
}