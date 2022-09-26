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
    s.delta();
}

void Server::fileWrite(int Type) {

}
