/**
 * @author Arthur
 * @file Scheduler.hpp
 * @date 03/10/22
 * @brief Déclaration de la classe Scheduler
 */


//DEFINE_GUARDS
#pragma once
#ifndef SCHEDULER_H
#define SCHEDULER_H

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include "Data.hpp"
#include "DataPacket.hpp"
#include "Server.hpp"


class Scheduler
{
public:    
    DataPacket dataValue;

    Scheduler(): dataValue(){};
    Scheduler(const Scheduler& s): dataValue(s.dataValue){};
    ~Scheduler(){};

    Scheduler getData();
    void sendDataToServer(Server& server);
    void wait();
};

#endif //SCHEDULER.H