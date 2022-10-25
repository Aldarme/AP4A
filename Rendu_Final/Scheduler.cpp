/**
 * @author BIN ABDUL SHUKOR Muhammad Ariff
 * @file Scheduler.cpp
 * @date 25/10/2022
 * @brief
 */
#include "Scheduler.hpp"
#include "Sensor.cpp"
#include <windows.h>
#include "Packet.hpp"

Scheduler::Scheduler(int timeTemp,int timePressure,int timeHumidity,int timeLight,int N,int visualize, int log)
{
    this->sec_temp=timeTemp;
    this->sec_press=timePressure;
    this->sec_humid=timeHumidity;
    this->sec_light=timeLight;
    this->nb_de_tourne=N;
    this->visualize=visualize;
    this->log=log;


} 

void Scheduler::theScheduler()
{
    Temperature temp(0);
    Pressure press(0);
    Humidity hum(0);
    Light lum(0);
    
    Server scr;
    
    if (visualize==0)
    {
        std::cout<<"The program is running. Please wait a moment......"<<std::endl;
    }
    srand(time(0));

    for (int i = 1; i < this->nb_de_tourne; i++)
    {
       //check if the modulo of the interval given (seconds%interval)is 0. If 0 then proceed.
        if (i%this->sec_temp==0)
        {   
            float t;
            //generate aleatoire
            t=temp.aleaGenVal();

            if (this->visualize==1)
            {
               scr.consolWrite(temp);
            }
            if (this->log==1)
            {
            scr.fileWrite(temp);
            }
  
        }

        if (i%this->sec_press==0)
        {   
            int p;
            p=press.aleaGenVal();
            if (this->visualize==1)
            {
                scr.consolWrite(press);
            }
            if (this->log==1)
            {
                scr.fileWrite(press);
            }
        }

        if (i%this->sec_humid==0)
        {
            float h;
            h=hum.aleaGenVal();
            if (this->visualize==1)
            {
               scr.consolWrite(hum);
            }
            if (this->log==1)
            {
                scr.fileWrite(hum);
            }
        }
        if (i%this->sec_light==0)
        {
            bool l;
            l=lum.aleaGenVal();
            if (this->visualize==1)
            {
                scr.consolWrite(lum);
            }
            if (this->log==1)
            {
                scr.fileWrite(lum);
            } 
        }
        std::cout<<std::endl;
        Sleep(1000);
    }  
}

