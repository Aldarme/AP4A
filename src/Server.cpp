#include "Server.h"
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string convertInt(int number_p);

Server::Server()
{
    m_consoleActivation = false;
    m_logActivation = false;
}

Server::Server(const Server& server_p)
{
    this->m_consoleActivation = server_p.m_consoleActivation;
    this->m_logActivation = server_p.m_logActivation;
}
Server& Server::operator=(const Server& server_p)
{
    this->m_consoleActivation = server_p.m_consoleActivation;
    this->m_logActivation = server_p.m_logActivation;
    return *this;
}

void Server::consoleWrite(Sensor& sensor_p)
{
    cout << sensor_p.getSpec(0) << " : " << sensor_p.getData() << " " << sensor_p.getSpec(1) << endl;
}

void Server::fileWrite(Sensor& sensor_p)
{
    string filename("C:/Users/rapha/AP4A/src/logs.txt");
    FILE *o_file = fopen(filename.c_str(), "a");
    if (o_file)
    {
        string chaine;
        chaine += sensor_p.getSpec(0);
        chaine += " ";    
        chaine += convertInt(sensor_p.getData());
        chaine += " ";
        chaine += sensor_p.getSpec(1);
        chaine += "\n";
        fwrite(chaine.c_str(), 1, chaine.size(), o_file);
    }
    fclose(o_file);
}

string convertInt(int number_p)
{
    stringstream ss;
    ss << number_p;
    return ss.str();
}
