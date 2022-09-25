#include "Server.h"


Server::Server() {
    Scheduler s;
    this->consoleWrite(s);
}

Server::Server(const Server& s) {
    
}

Server::~Server() {

}

void Server::operator=(const Server& s) {
 
}

void Server::consoleWrite(Scheduler& s) {
   
}

void Server::fileWrite(int Type) {

}

void Server::operator>>(int Type) {

}
void Server::dataRcv(int Type) {

}