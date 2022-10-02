//
// Created by rayan on 26/09/2022.
//

#ifndef UNTITLED72_SCHEDULER_H
#define UNTITLED72_SCHEDULER_H
#include <vector>
#include <time.h>
#include "../Enum.h"
#include "../Server/Server.h"
#include "../Sensor/Humidity.h"
#include "../Sensor/Light.h"
#include "../Sensor/Pression.h"
#include "../Sensor/Temperature.h"
#include "Time.h"
class TimeInterval
{
    friend class Scheduler; // to easily access this class from the scheduler

private:
    SensorType m_sensorType;
    clock_t m_clock;
    int m_duration; // duration in ms
public:
    TimeInterval();
    TimeInterval(SensorType sensorType, int duration);
    virtual ~TimeInterval();
    bool checkTime();
};
class Scheduler
{
public:
    Scheduler();
    virtual ~Scheduler();

private:
    Server server;
    Light lightSensor;
    Humidity humiditySensor;
    Temperature temperatureSensor;
    Pression pressureSensor;
    std::vector<SensorBase*> listSensors;
    std::vector<TimeInterval> timeInterval;
};

#endif //UNTITLED72_SCHEDULER_H
