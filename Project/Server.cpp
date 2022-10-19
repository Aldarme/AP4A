/**
 *  @author adamzm
 *  @file Server.cpp
 */

#include "Server.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// consoleWrite(string, string)
void Server::consoleWrite(string data_p, string type_p) {
    cout << type_p << " : " << data_p << endl;
}

// fileWrite(string, string)
void Server::fileWrite(string data_p, string type_p) {
    ofstream myFile("log" + type_p + ".txt", std::ios_base::app);
    myFile << data_p << endl;
    myFile.close();
}

// resetFile(string) : insert file name to reset
void Server::resetFile(string type_p) {
    ofstream myFile("log" + type_p + ".txt");
    myFile.close();
}


