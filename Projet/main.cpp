/**
 * @author Erhart Eliott
 * @file main.cpp
 * @date 03/10/2022
 * @brief Fichier main
 */

///J'ai inclus les cpp car j'avais des erreurs.
#include "Server.cpp"
#include "Scheduler.cpp"

#include <fstream>
#include <iostream>

int main()
{
    Server A;
    Scheduler B;
    

    A.displayChoice();
    A.fileClear();

    while (1)
    {
        B.getAll();
        B.sendData(A);
        A.fileWrite(tps);
        A.consoleWrite(tps);
        B.wait();
    }

    return 0;
}