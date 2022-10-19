
#include <iostream>
#include <cstdio>
#include "Scheduler.hpp"
#include "Server.hpp"




Server::Server() // on va questionner l'utilisateur pour savoir si il veut des logs/ feedback dans la console
{
    std::string log;
    std::string console;
    cout << "le serveur se lance" << "\n\n\n";
    cout << "Voulez vous des logs ? (yes pour oui) : "; //si yes est écrit, il y aura des logs, sinon il n'y en aura pas 
    cin >> log;
    m_fileActivation = log=="yes"?true:false;
    cout << "Voulez vous un feedback en temps reel dans la console ? (yes pour oui) : ";//si yes est écrit, on ecrira dans la console
    cin >> console; 
    m_consoleActivation = console=="yes"?true:false;
}

Server::Server(const Server &server_p)
{
    (*this).m_consoleActivation = server_p.m_consoleActivation;
    (*this).m_fileActivation = server_p.m_fileActivation;
}

Server &Server::operator=(const Server &server_p)
{
    if((*this).m_fileActivation != server_p.m_fileActivation)
    {
        (*this).m_fileActivation = server_p.m_fileActivation;
    }
    if((*this).m_consoleActivation != server_p.m_consoleActivation)
    {
        (*this).m_consoleActivation = server_p.m_consoleActivation;
    }
    return (*this);
}


void Server::start()
{
    
    std::ofstream m_fio; //on va effacer les precedentes entrées lors de l'initialisation
    m_fio.open("Humidity.txt", std::ios::trunc);
    m_fio.close();
    m_fio.open("Temperature.txt", std::ios::trunc);
    m_fio.close();
    m_fio.open("Pression.txt", std::ios::trunc);
    m_fio.close();
    m_fio.open("Light.txt", std::ios::trunc);
    m_fio.close();

}

void Server::consoleWrite(std::string capteur_p, struct CaptorValues s_captor_values_p) // print en fonction de quel capteur
{   
    if(capteur_p == "Humidity")
    {
        cout << "taux d'humidite : " << s_captor_values_p.value_humidity << "%" << endl;
    }
    if(capteur_p == "Temperature")
    {
        cout << "temperature : " << s_captor_values_p.value_temperature << " degres C" << endl;
    }
    if(capteur_p == "Pression")
    {
        cout << "pression : " << s_captor_values_p.value_pression << " hPa" << endl;
    }
    if(capteur_p == "Light")
    {
        std::string OnOrOff = s_captor_values_p.value_light==0?"off":"on";
        cout << "lumiere : " << OnOrOff << endl;
    }
} 

void Server::fileWrite(std::string capteur_p, struct CaptorValues s_captor_values_p)//ouvre et ecris dans les txt correspondants les valeurs precedement récupérées 
{
    ofstream fio; 

    if(capteur_p == "Humidity")
    {
        fio.open("Humidity.txt", std::ios::app);
        fio << "taux d'humidité : " << s_captor_values_p.value_humidity << "%" << endl;
        fio.close();
    }
    if(capteur_p == "Temperature")
    {
        fio.open("Temperature.txt", std::ios::app);
        fio << "temperature : " << s_captor_values_p.value_temperature << " °C" << endl;
        fio.close();
    }
    if(capteur_p == "Pression")
    {
        fio.open("Pression.txt", std::ios::app);
        fio << "pression : " << s_captor_values_p.value_pression << " hPa" << endl;
        fio.close();
    }
    if(capteur_p == "Light")
    {
        fio.open("Light.txt", std::ios::app);
        std::string OnOrOff = s_captor_values_p.value_light==0?"off":"on";
        fio << "lumière : " << OnOrOff << endl;
        fio.close();

    }


}