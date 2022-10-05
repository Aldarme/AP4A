#include "Server.hpp"

#include <fstream>
#include <iostream>
using namespace std;


//Definition of the canonical form
Server::Server() 
{ 
    this->m_logsActivated = false; 
    this->m_consoleActivated = false; 
}

Server::Server(const Server& param_se) 
{
    this->m_logsActivated = param_se.m_logsActivated; 
    this->m_consoleActivated = param_se.m_consoleActivated; 
}

Server& Server::operator=(const Server& param_se) 
{
    this->m_logsActivated = param_se.m_logsActivated;
    this->m_consoleActivated = param_se.m_consoleActivated;
    return *this; 
}

Server::~Server() 
{
}

//write the data on the console
void Server::consoleWrite(int param_value, std::string param_type, std::string param_unity) 
{
    if (this->m_consoleActivated) 
    {
        cout << param_type + " : ";
        cout << param_value; 
        cout << " " + param_unity << endl;
    }
}

//add a new line on the console 
void Server::consoleWrite()
{
    if (this->m_consoleActivated) 
    {
        cout << endl;
    }
}

//activate the console
void Server::activateConsole() 
{
    this->m_consoleActivated = true; 
}

//write the data in the file
void Server::fileWrite(int param_value, std::string param_type, std::string param_unity) 
{
    if (this->m_logsActivated) 
    {
        ofstream file("data.txt", ios::app);
        file << param_type + " : ";
        file << param_value;
        file << " " + param_unity << endl;
        file.close();
    }
}

//add a new line in the file
void Server::fileWrite() 
{
    if (this->m_logsActivated) 
    {
        ofstream file("data.txt", ios::app);
        file << "" << endl;
        file.close();
    }
}

//reset the logs file
void Server::resetLogs() 
{
    ofstream file("data.txt", ios::trunc);
    file.close();
}

//activate the logs
void Server::activateLogs() 
{
    this->m_logsActivated = true; 
}