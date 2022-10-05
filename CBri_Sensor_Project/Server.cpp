/**
 * @author BRICHET_Clement
 * @file Server.cpp
 * @date 23/09/2022
 * @brief 
 * */

#include "Server.hpp"
#include "fstream"

Server::Server(){}

Server::Server(const Server& s){}

Server::~Server(){}

Server& Server::operator=(const Server& s){}

template <class Type> void consoleWrite(Type s)
{
    std::cout << s.getData() << std::endl;
}

template <class Type> void fileWrite(Type s)
{
    ofstream myFile(s.m_filename);
    myFile << s.m_value << "\n";
    myFile.close();
}