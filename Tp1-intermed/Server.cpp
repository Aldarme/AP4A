/**
* @author MOhana wael
* @file : Server.cpp
* @date 27/09/2022
* @Description Definition classe Server
*/

#include <iostream>
#include "./Server.hpp"
#include <fstream>

Server::Server(){}

Server::Server(const Server& autre){
    this->consolActivation = autre.consolActivation;
    this->logActivation = autre.logActivation;
 }

 Server& Server::operator=(const Server& autre){
     this->consolActivation = autre.consolActivation;
        this->logActivation = autre.logActivation;
        return *this;
}

void Server::fileWrite(Sensor& s1, Sensor& s2, Sensor& s3, Sensor& s4){
    inoutstream.open(".\\test.txt",std::fstream::app);
    if(inoutstream.fail()){ std::cout << "error opening file";  exit(1);}
    else{
        inoutstream << "\n" + std::to_string(s1.getData()) + "\t" + std::to_string(s2.getData()) + "\t" + std::to_string(s3.getData()) + "\t" + std::to_string(s4.getData());
        inoutstream.close();
        if(!inoutstream.is_open()) std::cout << "\nFile closed";
        else{ std::cout << "\nCannot close file,exiting..."; exit(1);}
    }
}

void Server::consoleWrite(Sensor& s1, Sensor& s2, Sensor& s3, Sensor& s4){
    std::cout << "\n" << s1.getData() << "\t" << s2.getData() << "\t"<< s3.getData() << "\t" << s4.getData(); 
   }
   
Server::~Server(){}