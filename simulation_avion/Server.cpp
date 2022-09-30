#include "Server.hpp"

#include <fstream>
#include <iostream>
using namespace std;



Server::Server() { 
}

Server::Server(const Server& autre) {
}

Server& Server::operator=(const Server& autre) {
    return *this; 
}

Server::~Server() {
}

void Server::consoleWrite(int value, std::string type, std::string unity) {
    cout << type + " : ";
    cout << value; 
    cout << " " + unity << endl;
}

void Server::fileWrite(int value, std::string type, std::string unity) {
    ofstream file("data.txt", ios::app);
    file << value << endl; 
}

void Server::consoleWrite() {
    cout << "" << endl;
}

void Server::fileWrite() {
    ofstream file("data.txt", ios::app);
    file << "" << endl;
}