#include<cstdio>
#include<iostream>
#include<ctime>
#include "../hpp/Scheduler.hpp"
#include "../hpp/Temperature.hpp"
#include "../hpp/Sound.hpp"
#include "../hpp/Humidity.hpp"
#include "../hpp/Light.hpp"
#include "../hpp/Server.hpp"



Scheduler::Scheduler()
{
}

int Scheduler::getSensorData()
{
    for(int i =0;i<5; i++){
        int delay = 2;

        Temperature *temperature;
        temperature = new Temperature;
        
        Light *light;
        light = new Light;

        Humidity *humidity;
        humidity = new Humidity;

        Sound *sound;
        sound = new Sound;

        Server server;
    

        delay *= CLOCKS_PER_SEC;

        clock_t now = clock();
        
        while(clock() - now <delay);
        
        server.newStatement(i+1);
        server.fileAndConsoleWrite("Temperature" , temperature->getData(), "°C");
        server.fileAndConsoleWrite("Humidity" , humidity->getData(), "%");
        server.fileAndConsoleWrite("Light" , light->getData(), "lumens");
        server.fileAndConsoleWrite("Sound" , sound->getData(), "dB");


    }


return 0;

}