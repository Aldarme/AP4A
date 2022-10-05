/**
 * @author Muna Ayuni MAHATHIR
 * @file Scheduler.cpp
 * @brief This file is the implementation of class Server.
 */

#include "Scheduler.hpp"
#include "Sensor.hpp"
#include "Server.hpp"
#include <time.h>
#include <unistd.h>
using namespace std ;

//This is constructor of class Scheduler which calls the method of class server to activate or not the console and storage of datas in file log 
Scheduler::Scheduler()
{
    Server s ;
    m_activeC= s.ActivConsole();
    m_activeF = s.ActivFile();

}


//This is used to collect data from Sensor and to send data to Server at the same time
void Scheduler::takedata()
{
   Sensor* sens ;
   Server s ;

   int temp,hum,light,press ;

   srand(time(0)) ;


   // to get data of the temperature 
   sens =new Temperature() ;
   temp = sens->getdata(); 
   s.ConsoleWrite("Temperature",temp,"°C",m_activeC);
   s.fileWrite("Temperature",temp,"°C",m_activeF);


   // Interval between one sensor to another
   sleep(1);


   // to get data of the humidity
   sens =new Humidity();
   hum = sens->getdata();
   s.ConsoleWrite("Humidity",hum,"%",m_activeC);
   s.fileWrite("Humidity",hum,"%",m_activeF);

    // Interval between one sensor to another
   sleep(1);

   // to get data of the light
   sens =new Light() ;
   light = sens->getdata();
   s.ConsoleWrite("Light",light,"",m_activeC);
   s.fileWrite("Light",light,"",m_activeF);


   // Interval between one sensor to another
   sleep(1);


   // to get data of the pressure
   sens =new Pression() ;
   press = sens->getdata();
   s.ConsoleWrite("Pression",press,"hPa",m_activeC);
   s.fileWrite("Pression",press,"hPa",m_activeF);


   // the interval before collecting new set of data
   sleep(2);
}
