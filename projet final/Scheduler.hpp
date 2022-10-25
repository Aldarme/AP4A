#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <Windows.h>
#include <unistd.h>

#include "DataPacket.hpp"
#include "Server.hpp"


class Scheduler{
public:
    DataPacket value;

    Scheduler(): dataValue(){};
    Scheduler(const Scheduler& s): dataValue(s.value){};
    ~Scheduler(){};

    Scheduler getData(int time);
    void send(int time, Server& server);

};

#endif 