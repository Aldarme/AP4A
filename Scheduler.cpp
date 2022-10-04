
#include <iostream>
#include <cstdio>
#include <Windows.h>
#include "Scheduler.hpp"

#ifdef LINUX
#include <unistd.h>
#endif
#ifdef WIN32
#include <windows.h>
#endif

using namespace std;

Scheduler::Scheduler()
{

}

void Scheduler::start()
{
    humidity = new Humidity();
    pression = new Pression();
    temperature = new Temperature();
    light = new Light();
    server = new Server();
    (*server).start();

    while(true)
    {
        
        value_humidity = (*humidity).getData();//prend chaque valeur et les stocks
        value_pression = (*pression).getData();
        value_temperature = (*temperature).getData();
        value_light = (*light).getData();
        (*server).consoleWrite(value_humidity, value_temperature, value_pression, value_light);
        (*server).fileWrite(value_humidity, value_temperature, value_pression, value_light);
        mySleep(1000); //recommence chaque seconde
        
        
    }
}

void Scheduler::mySleep(int sleepMs) //cross-platform sleep
{
    #ifdef LINUX
        usleep(sleepMs * 1000);   
    #endif
    #ifdef WIN32
        Sleep(sleepMs);
    #endif
}

