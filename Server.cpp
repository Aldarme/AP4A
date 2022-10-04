
#include <iostream>
#include <cstdio>
#include "Scheduler.hpp"
#include "Server.hpp"


using namespace std;


Server::Server()
{
    cout << "le serveur se lance" << "\n\n\n";

}


void Server::start(){
    sec = 0;
    std::ofstream fio; //efface les precedentes entrées lors de l'initialisation
    fio.open("Humidity.txt", std::ios::trunc);
    fio.close();
    fio.open("Temperature.txt", std::ios::trunc);
    fio.close();
    fio.open("Pression.txt", std::ios::trunc);
    fio.close();
    fio.open("Light.txt", std::ios::trunc);
    fio.close();

}

void Server::consoleWrite(int Humidity, int Temperature, int Pression, int Light)
{
    cout << "Simulation seconde " << sec << ": \n";

    cout << "humidite : " << Humidity << "%" << endl
         << "temperature : " << Temperature << " degres C" << endl
         << "pression : " << Pression << " hPa" << endl
         << "lumiere : " << Light << " lux" << "\n\n";

    sec++;
} 

void Server::fileWrite(int Humidity, int Temperature, int Pression, int Light)
{


    ofstream fio; //ouvre et ecris dedans les valeurs precedement récupérées 
    fio.open("Humidity.txt", std::ios::app);
    fio << "taux d'humidité : " << Humidity << "%" << endl;
    fio.close();

    fio.open("Temperature.txt", std::ios::app);
    fio << "temperature : " << Temperature << " °C" << endl;
    fio.close();

    fio.open("Pression.txt", std::ios::app);
    fio << "pression : " << Pression << " hPa" << endl;
    fio.close();

    fio.open("Light.txt", std::ios::app);
    fio << "lumière : " << Light << " lux" << endl;
    fio.close();


}