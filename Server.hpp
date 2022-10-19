#ifndef SERVER_H
#define SERVER_H

/*
author: Tom PALLEAU
date: 10/1/2022
licence: free
class: Server
*/

#include <iostream>
#include "Package.hpp"

class Server
{
public:
    bool m_consol;
    bool m_file;

public:
    Server(bool p_consol, bool m_file);
    
    template <typename T>
    void consolWrite(Package<T> p_package)
    {
        std::cout << p_package << std::endl;
    }
    
    template <typename T>
    void fileWrite(Package<T> p_package)
    {
        std::ofstream file(p_package.getName().append(".txt"), std::ios::app);
        file << p_package;

        file.close();
    }
};

#endif // SERVER_H