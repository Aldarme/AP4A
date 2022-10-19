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

void Scheduler::run() /*on définit ce que doit faire le scheduler*/
{
    pObjetServer->question(); //on lance la fonction question
    int elapsedHum = 0; 
    int elapsedLight = 0;
    int elapsedPressure = 0;
    int elapsedTemp = 0;
/*on assigne a chaque capteur une valeur de temps pour les lancer en différé*/

    while(true)
    {
        if(elapsedHum >= 5000) /*le capteur d'humidité est appelé toutes les 5000ms*/
        {
            structDef.humidityValue = pCaptorHumidity->getData(); /* on recupère la valeur dans la structure qui est donnée par getData*/ 
            if(pObjetServer->m_console == 1)   /*si l'utilisateur veut les valeurs dans la console alors on les écrit*/
            {
            pObjetServer->consoleWrite("Humidity", structDef);
            }
            if(pObjetServer->m_log == 1)   /*si l'utilisateur veut les logs des capteurs alors on les écrit*/
            { 
            pObjetServer->fileWrite("Humidity", structDef);
            }
            elapsedHum = 0; /*on remet le timer a 0 pour l'humidité*/
        }

        if(elapsedLight >= 8000) /*de la meme façon on appelle le capteur de lumière toutes les 8 secondes*/
        {
            structDef.lightValue = pCaptorLight->getData();
            if(pObjetServer->m_console == 1)
            {
            pObjetServer->consoleWrite("Light", structDef);
            }
            if(pObjetServer->m_log == 1)
            {
            pObjetServer->fileWrite("Light", structDef);
            }
            elapsedLight = 0;
        }

        if(elapsedPressure >= 3500) /*de la meme façon on appelle le capteur de pression toutes les 3,5s*/
        {
            structDef.pressureValue = pCaptorPressure->getData();
            if(pObjetServer->m_console == 1)
            {
            pObjetServer->consoleWrite("Pressure", structDef);
            }
            if(pObjetServer ->m_log == 1)
            {
            pObjetServer->fileWrite("Pressure", structDef);
            }
            elapsedPressure = 0;
        }

        if(elapsedTemp >= 2000) /*de la meme façon on appelle le capteur de température toutes les 2s*/
        {
            structDef.tempValue = pCaptorTemp->getData(); 
            if(pObjetServer->m_console == 1)
            {
            pObjetServer->consoleWrite("Temperature", structDef);
            }
            if(pObjetServer->m_log == 1)
            {
            pObjetServer->fileWrite("Temperature", structDef);
            }
            elapsedTemp = 0;
        }
        sleepcp(500);  //pause de 500ms
        elapsedHum+=500; /*chaque valeur correspond a la durée depuis le dernier appel du capteur, on les incrémente de 500 toutes les 500ms  */
        elapsedLight+=500;
        elapsedPressure+=500;
        elapsedTemp+=500;
    }
}
