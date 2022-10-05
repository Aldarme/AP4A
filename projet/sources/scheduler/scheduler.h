//
// Created by rayan on 05/10/2022.
//
#ifndef PROJET_SCHEDULER_H
#define PROJET_SCHEDULER_H
#include <vector>
#include <ctime>
#include "Time.hpp"
#include "../server/server.h"
#include "../sensor/humidity.h"
#include "../sensor/light.h"
#include "../sensor/temperature.h"
#include "../sensor/pression.h"


class Scheduler
{
public:
    Scheduler();
    virtual ~Scheduler();
    void QuestionAffichage();

private:
    Server server;
    Temperature temperatureSensor;
    Humidity humiditySensor;
    Light lightSensor;
    Pression pressureSensor;
    std::vector<MainSensor*> listSensors;
    std::vector<Time> time;

};

#endif //PROJET_SCHEDULER_H
