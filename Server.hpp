#ifndef SERVER_H
#define SERVER_H

/*
author: Tom PALLEAU
date: 10/1/2022
licence: free
class: Server
*/

#include "Package.hpp"

class Server
{
public:
    bool m_consol;
    bool m_file;

public:
    Server(bool p_consol, bool m_file);
    void consolWrite(Package p_package);
    void fileWrite(Package p_package);
};

#endif // SERVER_H