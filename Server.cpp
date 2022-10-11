/**
 * @author Planchin Arnaud
 * @file Server.cpp
 * @date 03/10/2022
 * @brief 
 */

#include "Server.hpp"
#include <iostream>
#include <fstream>

void Server::fileWrite(int s_variable)
{
    ofstream mon_fichier("C:/Users/arnau/AP4A/Humidity.txt");  
    mon_fichier << "hum";

    mon_fichier.close().
}

void Server::consolWrite(int s_variable)
{
    
}