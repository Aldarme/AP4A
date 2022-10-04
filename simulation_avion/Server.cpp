#include "Server.hpp"

#include <fstream>
#include <iostream>
using namespace std;


Server::Server() { 
    this->logsActivated = false; 
    this->consoleActivated = false; 
}

Server::Server(const Server& param) {
    this->logsActivated = param.logsActivated; 
    this->consoleActivated = param.consoleActivated; 
}

Server& Server::operator=(const Server& param) {
    this->logsActivated = param.logsActivated;
    this->consoleActivated = param.consoleActivated;
    return *this; 
}

Server::~Server() {
}


void Server::consoleWrite(int value, std::string type, std::string unity) {
    if (this->consoleActivated) {
        cout << type + " : ";
        cout << value; 
        cout << " " + unity << endl;
    }
}

void Server::consoleWrite() {
    if (this->consoleActivated) {
        cout << endl;
    }
}

void Server::activateConsole() {
    this->consoleActivated = true; 
}

void Server::fileWrite(int value, std::string type, std::string unity) {
    if (this->logsActivated) {
    ofstream file("data.txt", ios::app);
    file << type + " : ";
    file << value;
    file << " " + unity << endl;
    file.close();
    }

}

void Server::fileWrite() {
    if (this->logsActivated) {
        ofstream file("data.txt", ios::app);
        file << "" << endl;
        file.close();
    }
}

void Server::resetLogs() {
    ofstream file("data.txt", ios::trunc);
    file.close();
}

void Server::activateLogs() {
    this->logsActivated = true; 
}