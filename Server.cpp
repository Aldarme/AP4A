
#include <iostream>
#include <cstdio>
#include "Scheduler.hpp"
#include "Server.hpp"


using namespace std;


Server::Server() // on va questionner l'utilisateur pour savoir si il veut des logs/ feedback dans la console
{
    cout << "le serveur se lance" << "\n\n\n";
    cout << "Voulez vous des logs ? (yes pour oui) : ";
    cin >> file;
    cout << "Voulez vous un feedback en temps reel dans la console ? (yes pour oui) : ";
    cin >> console; 
}


void Server::start()
{
    
    std::ofstream fio; //on va effacer les precedentes entrées lors de l'initialisation
    fio.open("Humidity.txt", std::ios::trunc);
    fio.close();
    fio.open("Temperature.txt", std::ios::trunc);
    fio.close();
    fio.open("Pression.txt", std::ios::trunc);
    fio.close();
    fio.open("Light.txt", std::ios::trunc);
    fio.close();

}

void Server::consoleWrite(std::string Capteur, struct CaptorValues captor_values) // print en fonction de quel capteur
{   
    if(Capteur == "Humidity")
    {
        cout << "taux d'humidite : " << captor_values.value_humidity << "%" << endl;
    }
    if(Capteur == "Temperature")
    {
        cout << "temperature : " << captor_values.value_temperature << " degres C" << endl;
    }
    if(Capteur == "Pression")
    {
        cout << "pression : " << captor_values.value_pression << " hPa" << endl;
    }
    if(Capteur == "Light")
    {
        std::string OnOrOff = captor_values.value_light==0?"off":"on";
        cout << "lumiere : " << OnOrOff << endl;
    }
} 

void Server::fileWrite(std::string Capteur, struct CaptorValues captor_values)//ouvre et ecris dans les txt correspondants les valeurs precedement récupérées 
{
    ofstream fio; 

    if(Capteur == "Humidity")
    {
        fio.open("Humidity.txt", std::ios::app);
        fio << "taux d'humidité : " << captor_values.value_humidity << "%" << endl;
        fio.close();
    }
    if(Capteur == "Temperature")
    {
        fio.open("Temperature.txt", std::ios::app);
        fio << "temperature : " << captor_values.value_temperature << " °C" << endl;
        fio.close();
    }
    if(Capteur == "Pression")
    {
        fio.open("Pression.txt", std::ios::app);
        fio << "pression : " << captor_values.value_pression << " hPa" << endl;
        fio.close();
    }
    if(Capteur == "Light")
    {
        fio.open("Light.txt", std::ios::app);
        std::string OnOrOff = captor_values.value_light==0?"off":"on";
        fio << "lumière : " << OnOrOff << endl;
        fio.close();

    }


}