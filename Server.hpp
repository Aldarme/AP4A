#ifndef SERVER_H
#define SERVER_H

#include "Package.hpp"

class Server
{
public:
    void consolWrite(Package p_package);
    void fileWrite(Package p_package);
};

#endif // SERVER_H