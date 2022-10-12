/**
 * @author Erhart Eliott
 * @file main.cpp
 * @date 03/10/2022
 * @brief Fichier main
 */

///J'ai inclus les cpp car j'avais des erreurs.
#include "Server.cpp"
#include "Sensor.cpp"
#include "Scheduler.cpp"

#include "Server.hpp"
#include "Sensor.hpp"
#include "Scheduler.hpp"
#include "Packet.hpp"

#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    Server A;
    Scheduler B;
    int tps = 0;

    A.fileClear();

    while (1)
    {
        B.getAll();
        B.sendData(A);
        A.fileWrite(tps);
        A.consoleWrite(tps);
        B.wait();
        tps++;
    }

    return 0;
}