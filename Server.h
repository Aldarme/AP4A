#include <iostream>

#include "Sensor.h"
#include "Scheduler.h"

class Server {

public:
    Server();
    ~Server();
    Server(const Server& s);
    void operator=(const Server& s);
    void operator>>(int Type);
    void dataRcv(int Type);

    void consoleWrite(int s);
    void fileWrite(int data);
};