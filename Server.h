#include <iostream>

#include "Sensor.h"
#include "Scheduler.h"

using namespace std;

class Server {

public:
    Server();
    ~Server();
    Server(const Server& s);
    void operator=(const Server& s);
    void operator>>(int Type);
    void dataRcv(int Type);
private:
    void consoleWrite(Scheduler& s);
    void fileWrite(int Type);
};