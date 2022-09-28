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
    /*string const file("C:/Users/rapha/AP4A/datas.txt");
    ofstream monFlux(file.c_str());
    if(monFlux) {
        string chaine;
        for (int i = 0; i < 10; i++) {
            chaine += convertInt(data)+"\n";
        }
            monFlux << chaine << endl ;
            cout <<"Chaine : " << chaine << endl;
    }
     else{
        cerr << "Cannot open the file" << endl;
     }*/

    /*string filename3("output3.txt");
    FILE *o_file = fopen(filename3.c_str(), "w+");
    if (o_file){
        fwrite(text.c_str(), 1, text.size(), o_file);
        cerr << "Done Writing!" << endl;
    }*/
}

string convertInt(int number){
    stringstream ss;
    ss << number;
    return ss.str();
}
