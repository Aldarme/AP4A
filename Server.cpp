#include "Server.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

string convertInt(int e);

Server::Server() {
    
}

Server::Server(const Server& s) {
    
}

Server::~Server() {
    
}

void Server::operator=(const Server& s) {
    
}

void Server::consoleWrite(int s) {
    cout << s << endl;
}

void Server::fileWrite(int data) {
    string filename("C:/Users/rapha/AP4A/datas.txt");
    FILE *o_file = fopen(filename.c_str(), "a");
    if (o_file){
        string chaine;
        chaine += convertInt(data)+"\n";
        fwrite(chaine.c_str(), 1, chaine.size(), o_file);
    }
}

string convertInt(int number){
    stringstream ss;
    ss << number;
    return ss.str();
}
