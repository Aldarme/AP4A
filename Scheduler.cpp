
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
    m_seconds = 0;
}

void Scheduler::start()
{

    pHumidity = new Humidity();
    pPression = new Pression();
    pTemperature = new Temperature();
    pLight = new Light();
    pServer = new Server();
    (*pServer).start(); // on crée les sensors et le server qu'on lance alors
    

    while(true)
    {
        m_seconds++;
        s_captor_values.value_humidity = (*pHumidity).getData();//prend chaque valeur et les stocks dans une struct
        s_captor_values.value_pression = (*pPression).getData();
        s_captor_values.value_temperature = (*pTemperature).getData();
        s_captor_values.value_light = (*pLight).getData();

        mySleep(1000); //recommence chaque seconde
        
        if (m_seconds%1==0)//toute les secondes
        { 
            (*pServer).m_consoleActivation==true?(*pServer).consoleWrite("Humidity", s_captor_values):NULL;
            (*pServer).m_fileActivation==true?(*pServer).fileWrite("Humidity", s_captor_values):NULL;
        }
        if (m_seconds%2==0)//toute les 2 secondes
        {
            (*pServer).m_consoleActivation==true?(*pServer).consoleWrite("Temperature", s_captor_values):NULL;
            (*pServer).m_fileActivation==true?(*pServer).fileWrite("Temperature", s_captor_values):NULL;
        }
        if (m_seconds%3==0)//toute les 3 secondes
        {
            (*pServer).m_consoleActivation==true?(*pServer).consoleWrite("Pression", s_captor_values):NULL;
            (*pServer).m_fileActivation==true?(*pServer).fileWrite("Pression", s_captor_values):NULL;
        }
        if (m_seconds%4==0)//toute les 4 secondes
        {
            (*pServer).m_consoleActivation==true?(*pServer).consoleWrite("Light", s_captor_values):NULL;
            (*pServer).m_fileActivation==true?(*pServer).fileWrite("Light", s_captor_values):nullptr;
        }
    }
}

void Scheduler::mySleep(int sleepMs_p) //cross-platform sleep
{
    #ifdef LINUX
        usleep(sleepMs_p * 1000);   
    #endif
    #ifdef WIN32
        Sleep(sleepMs_p);
    #endif
}

