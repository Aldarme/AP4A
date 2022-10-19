/**
 * @author Muna Ayuni MAHATHIR
 * @file Scheduler.cpp
 * @brief This file is the implementation of class Server.
 */

#include "Scheduler.hpp"
#include "Sensor.hpp"
#include "Server.hpp"
#include <cstdlib>
#include <chrono>
#include <string>
#include <thread>
#include <iostream>
using namespace std ;

//This is constructor of class Scheduler which calls the method of class server to activate or not the console and storage of datas in file log 
Scheduler::Scheduler()
{
    Server s ;
    m_activeC= s.ActivConsole();
    m_activeF = s.ActivFile();

}


//This is used to collect data from Sensor and to send data to Server at the same time
// Here we'll use thread because the data will be retrieved and sent to the server with different interval of time

void Scheduler::takedata()
{

   // thread to get data of the temperature 
   std::thread getTemp ([this]()
   {
        Server s ;
        Sensor<float>* sens_f1 ;
        sens_f1 =new Temperature() ;

        while(true)
        {
          float temp = sens_f1->getdata(); 
          s.ConsoleWrite("Temperature",to_string(temp).substr(0, 5),"°C",m_activeC);
          s.fileWrite("Temperature",to_string(temp).substr(0, 5),"°C",m_activeF);
          std::this_thread::sleep_for(std::chrono::seconds(5)); // interval of 5 seconds to retrieve new temperature 
        }
   });
   

   // thread to get data of the humidity
   std::thread getHum ([this]()
   {
        Server s ;
        Sensor<float>* sens_f2 ;
        sens_f2 =new Humidity();

        while(true)
        {
               float hum = sens_f2->getdata();
               s.ConsoleWrite("Humidity",to_string(hum).substr(0, 5),"%",m_activeC);
               s.fileWrite("Humidity",to_string(hum).substr(0, 5),"%",m_activeF);
               std::this_thread::sleep_for(std::chrono::seconds(11)); // interval of 11 seconds to retrieve new humidity data
        }
   });


   // thread to get data of the light
   std::thread getLight ([this]()
   {
        Server s ;
        Sensor<bool>* sens_b ;
        sens_b =new Light() ;

        while(true)
        {
               bool light = sens_b->getdata();
               s.ConsoleWrite("Light",to_string(light),"",m_activeC);
               s.fileWrite("Light",to_string(light),"",m_activeF);
               std::this_thread::sleep_for(std::chrono::seconds(16)); // interval of 16 seconds to retrieve new Light data
        }
   });
   


   // thread to get data of the pressure
    std::thread getPress ([this]()
    {
        Server s ;
        Sensor<int>* sens_i ; 
        sens_i =new Pression() ;

        while(true)
        {
               int press = sens_i->getdata();
               s.ConsoleWrite("Pression",to_string(press),"hPa",m_activeC);
               s.fileWrite("Pression",to_string(press),"hPa",m_activeF);
               std::this_thread::sleep_for(std::chrono::seconds(21)); // interval of 21 seconds to retrieve new pressure data
        }
        
    });

    // to activate all the thread
     getTemp.join(); 
     getHum.join(); 
     getLight.join(); 
     getPress.join(); 


}


