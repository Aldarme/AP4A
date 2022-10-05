/**
 *  @author adamzm
 *  @file Server.cpp
 */

#include "Server.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

// consoleWrite(char) : show on terminal the data asked
void Server::consoleWrite(int data_p, string type_p) {
    cout << type_p << " : " << data_p << endl;

}

// fileWrite(char) : write a log.txt concerning the data asked
void Server::fileWrite(int data_p, string type_p) {
    ofstream myFile("log" + type_p + ".txt", std::ios_base::app);
    myFile << data_p << endl;
    myFile.close();
}