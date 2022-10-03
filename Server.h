#include <iostream>

#include "Sensor.h"
#include "Scheduler.h"

class Server {

public:
    Server();
    ~Server();
    Server(const Server& s);
    void operator=(const Server& s);

    void consoleWrite(int s, const char** spec);
    void fileWrite(int data, const char** spec);
};