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

