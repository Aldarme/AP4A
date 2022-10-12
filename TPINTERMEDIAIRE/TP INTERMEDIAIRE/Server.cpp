#include "Server.hpp"
//Server.cpp


#include "Server.hpp"
#include <iostream>
#include "Temperature.cpp"
#include "Humidity.cpp"
#include "Light.cpp"
#include "Sound.cpp"
#include <fstream>

using namespace std;



Server::Server() : m_consolActivation(), m_logActivation() {};

Server::Server(const Server& server)
{
    this->m_consolActivation = server.m_consolActivation;
    this->m_logActivation = server.m_logActivation;
}

Server::~Server() = default;

Server& Server::operator=(const Server& server)
{
    this->m_logActivation = server.m_logActivation;
    this->m_consolActivation = server.m_consolActivation;
    return *this;
}

void Server::consolWrite(const float temperature_p, const float humidity_p, const float light_p, const float sound_p)
{
    cout << "Temperature : " << temperature_p << " k" << endl;
    cout << "Humidity : " << humidity_p << " g/m3" << endl;
    cout << "Light : " << light_p << " cd" << endl;
    cout << "Sound : " << sound_p << " dB" << endl;
    cout << "               ------                  " << endl;
}

void Server::fileWrite(const float temperature_p, const float humidity_p, const float light_p, const float sound_p)
{
    ofstream myfile("logTEMP.txt");
    if (myfile.is_open())
    {
        myfile << "Temperature : " << temperature_p << " k" << endl;
        myfile.close();
    }
    else cout << "Unable to open file for temperature";

    ofstream humfile("logHUM.txt");
    if (humfile.is_open())
    {
        humfile << "Humidity : " << humidity_p << " g/m3" << endl;
        humfile.close();
    }
    else cout << "Unable to open file for humidity";

    ofstream lightfile("logLIGHT.txt");
    if (lightfile.is_open())
    {
        lightfile << "Light : " << light_p << " cd" << endl;
        lightfile.close();
    }
    else cout << "Unable to open file for light";

    ofstream soundfile("logSOUND.txt");
    if (soundfile.is_open())
    {
        soundfile << "Sound : " << sound_p << " dB" << endl;
        soundfile.close();
    }
    else cout << "Unable to open file for sound";

}

bool Server::getLogActivation()
{
    return this->m_logActivation;
}

void Server::setLogActivation(int ans_p)
{
    this->m_logActivation = ans_p;
}

bool Server::getConsolActivation()
{
    return this->m_consolActivation;
}

void Server::setConsolActivation(bool ans_p)
{
    this->m_consolActivation = ans_p;
}