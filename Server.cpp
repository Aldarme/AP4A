#include "Server.hpp"
#include <fstream>
#include <iostream>

void Server::consolWrite(Package p_package)
{
    std::cout << p_package << std::endl;
}

void Server::fileWrite(Package p_package)
{
    std::ofstream file(p_package.getName(), std::ios::app);
    file << p_package;

    file.close();
}