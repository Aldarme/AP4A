
#include <iostream>
#include <cstdio>
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
    seconds = 0;
}

void Scheduler::start()
{

    humidity = new Humidity();
    pression = new Pression();
    temperature = new Temperature();
    light = new Light();
    server = new Server();
    (*server).start(); // on crée les sensors et le server qu'on lance alors
    

    while(true)
    {
        seconds++;
        captor_values.value_humidity = (*humidity).getData();//prend chaque valeur et les stocks dans une struct
        captor_values.value_pression = (*pression).getData();
        captor_values.value_temperature = (*temperature).getData();
        captor_values.value_light = (*light).getData();

        mySleep(1000); //recommence chaque seconde
        
        if (seconds%1==0){ //toute les secondes
            (*server).console=="yes"?(*server).consoleWrite("Humidity", captor_values):NULL;
            (*server).file=="yes"?(*server).fileWrite("Humidity", captor_values):NULL;
        }
        if (seconds%2==0){//toute les 2 secondes
            (*server).console=="yes"?(*server).consoleWrite("Temperature", captor_values):NULL;
            (*server).file=="yes"?(*server).fileWrite("Temperature", captor_values):NULL;
        }
        if (seconds%3==0){//toute les 3 secondes
            (*server).console=="yes"?(*server).consoleWrite("Pression", captor_values):NULL;
            (*server).file=="yes"?(*server).fileWrite("Pression", captor_values):NULL;
        }
        if (seconds%4==0){//toute les 4 secondes
            (*server).console=="yes"?(*server).consoleWrite("Light", captor_values):NULL;
            (*server).file=="yes"?(*server).fileWrite("Light", captor_values):nullptr;
        }
        

        
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

