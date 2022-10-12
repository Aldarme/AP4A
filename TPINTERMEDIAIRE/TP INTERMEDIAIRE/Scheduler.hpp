#pragma once
//scheduler.hpp

#include "Sensor.hpp"
#include "Server.hpp"
#include "Humidity.hpp"
#include "Light.hpp"
#include "Temperature.hpp"
#include "Sound.hpp"

class Scheduler
{
private:
    Temperature m_temperature;
    Humidity m_humidity;
    Light m_light;
    Sound m_sound;
    Server m_server;
    int m_dureeTotale;
    int m_delta;
public:
    // Forme canonique de Coplien
    Scheduler();
    Scheduler(const Scheduler& scheduler_p);
    ~Scheduler();
    Scheduler& operator=(const Scheduler& scheduler);

    void launchSimulation();

    void genRandom();

    void sendValues();

    friend class sensor;

};