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
private:
    bool m_consol;
    bool m_file;
    
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

public:
    Server(bool p_consol, bool m_file);

    template <typename T>
    void receiveData(Package<T> p_package)
    {
        if (m_consol)
        {
            consolWrite(p_package);
        }
        if (m_file)
        {
            fileWrite(p_package);
        }
        
        
    }
};

#endif // SERVER_H