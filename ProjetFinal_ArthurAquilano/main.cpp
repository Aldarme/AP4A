/**
 * @author Arthur
 * @file main.cpp
 * @date 03/10/22
 * @brief Fichier main du programme
 */

#include <iostream>
#include <string>
#include <stdlib.h>

//J'ai include tous les fichiers .cpp pour des erreurs de références: "Undefined reference to Class::Methode au moment de la compilation"
#include "Scheduler.cpp"
#include "DataPacket.cpp"
#include "Server.cpp"
#include "DataPressure.cpp"
#include "DataHumidity.cpp"
#include "DataTemperature.cpp"
#include "DataLight.cpp"
#include "Sensor.cpp"

void StartProgram();

int main ()
{

    int time = 0;

    Scheduler scheduler;
    Server server;

    char userAction;

    StartProgram();
    server.resetFile();
    while (1){
    time++;

    scheduler.getData(time);
    scheduler.sendDataToServer(time, server);

    server.consolWrite(time);
    server.fileWrite(time);

    Sleep(1000);

    }

    return EXIT_SUCCESS;

};

/** @brief Demande à l'utilisateur s'il veut démarrer le programme
 *  @return Rien
 *  @param Aucun
 */ 
void StartProgram()
{
    char userAnswer;

    std::cout << "Voulez vous demarrer le programe? Y/N" << std::endl;
    std::cin >> userAnswer;

    while (userAnswer != 'Y' && userAnswer != 'y' && userAnswer != 'N' && userAnswer != 'n')
    {
        std::cout << "Voulez vous demarrer le programe? Y/N" << std::endl;
        std::cin >> userAnswer;
    }

    if (userAnswer == 'N' || userAnswer == 'n')
    {
        exit(0);
    };

};