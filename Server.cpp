/*
author: Tom PALLEAU
date: 10/1/2022
licence: free
class: Server
*/

#include "Server.hpp"
#include <fstream>
#include <iostream>

/**
 * @brief Construct a new Server:: Server object sets the operating mode of the object
 * 
 * @param p_consol 
 * @param p_file 
 */
Server::Server(bool p_consol, bool p_file){
    m_consol = p_consol;
    m_file = p_file;
}

/**
 * @brief write the package values to the consol
 * 
 * @param p_package 
 */
void Server::consolWrite(Package p_package)
{
    std::cout << p_package << std::endl;
}

/**
 * @brief write the package values to the file
 * 
 * @param p_package 
 */
void Server::fileWrite(Package p_package)
{
    std::ofstream file(p_package.getName().append(".txt"), std::ios::app);
    file << p_package;

    file.close();
}