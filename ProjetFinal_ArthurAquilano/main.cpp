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
#include "DataHumidity.cpp"
#include "DataTemperature.cpp"
#include "DataLight.cpp"
#include "DataPressure.cpp"
#include "Sensor.cpp"

#include "Data.hpp"
#include "DataPacket.hpp"
#include "Scheduler.hpp"
#include "Sensor.hpp"
#include "Server.hpp"

void StartProgram();

int main ()
{
    Scheduler scheduler;
    Server server;

    char userAction;

    StartProgram();
    server.resetFile();
    while (1){
    scheduler.getData();
    scheduler.sendDataToServer(server);

    server.consolWrite();
    server.fileWrite();

    scheduler.wait();
    }

    return EXIT_SUCCESS;

};


/** @brief Demande à l'utilisateur si il veut démarrer le programe
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