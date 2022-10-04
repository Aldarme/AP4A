#include "Scheduler.hpp"
#include <iostream>
        
#ifdef _WIN32
    #include <windows.h>//lib pour windows
#else
    #include <unistd.h> //lib pour linux
#endif // _WIN32

void sleepcp(unsigned long milliseconds) // fonction sleep cross-plateform
{
    #ifdef _WIN32
        Sleep(milliseconds);
    #else
        usleep(milliseconds * 1000); //command for linux
    #endif // _WIN32
}

void Scheduler::run() //launch the captors
{
    int elapsedHum = 0; 
    int elapsedLight = 0;
    int elapsedPressure = 0;
    int elapsedTemp = 0;

    while(true)
    {
        /*pour le rendu intermédiaire, les valeurs sont récupérées toutes au même moment; cependant la récupération des valeurs en différé est déjà presque fonctionnel de cette manière  */
        if(elapsedHum >= 1000) 
        {
            type data = captorHumidity->getData(); // on recup la valeur une seule fois car appeler un capteur prends du temps
            objetServer.consoleWrite("Humidity", data, captorHumidity->getType());
            objetServer.fileWrite("Humidity", data, captorHumidity->getType());
            elapsedHum = 0;
        }

        if(elapsedLight >= 1000) 
        {
            type data = captorLight->getData();
            objetServer.consoleWrite("Light",data,captorLight->getType());
            objetServer.fileWrite("Light",data,captorLight->getType());
            elapsedLight = 0;
        }

        if(elapsedPressure >= 1000)
        {
            type data = captorPressure->getData();
            objetServer.consoleWrite("Pressure",data,captorPressure->getType());
            objetServer.fileWrite("Pressure",data,captorPressure->getType());
            elapsedPressure = 0;
        }

        if(elapsedTemp >= 1000)
        {
            type data = captorTemp->getData();
            objetServer.consoleWrite("Temperature",data,captorTemp->getType());
            objetServer.fileWrite("Temperature",data,captorTemp->getType());
            elapsedTemp = 0;
        }

        sleepcp(500);   //pause de 500ms
        elapsedHum+=500; /*chaque valeur correspond a la durée depuis le dernier appel du capteur, on les incrémente de 500 toutes les 500ms  */
        elapsedLight+=500;
        elapsedPressure+=500;
        elapsedTemp+=500;
    }
}
