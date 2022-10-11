/** 
 * @author SCHERRER Guillaume
 * @file Scheduler.cpp
 * @date 25/09/2022
 * @brief definiton ds corps des méthodes de Schedule.hpp
 *  
*/
// génériques
#include <iostream>
#include <time.h>

#include "AP4A_Intermediaire.hpp"

// classes:
#include "Server.hpp"
#include "Scheduler.hpp"
#include "Sensor.hpp"
#include "Temperature.hpp"
#include "Humidity.hpp"
#include "Pressure.hpp"
#include "Light.hpp"

// instancier les capteurs:
Temperature Temp_sensor(-50.0f, 150.0f); //-50 to 150 °C
Humidity Humidity_sensor(0.0f, 100.0f);  // 0 to 100% rel. humidity
Pressure Pressure_sensor(0.0f, 1000000.0f); // 0 to 10^6 Pa (0 to 10 bars)
Light Light_sensor(0.0f, 10000.0f); // 0 to 10000 Lumen

// instancier le Serveur:
Server SensorServer;

Scheduler::Scheduler(int periode) // constructor
{
    m_period_in_seconds = periode;
    std::cout << "sensor capture every " << m_period_in_seconds << " seconds \n\n";
} 

Scheduler::~Scheduler() {} // destructor


void Scheduler::ProcessScheduler() 
{
    int delay_in_clocks = m_period_in_seconds * CLOCKS_PER_SEC;
    
    float SensorData[4];

    while (1) // infinite loop
    {
        // attendre  m_period_in_seconds:
        clock_t Start_tick = clock();
        while ( (clock() - Start_tick) < delay_in_clocks )
        {
        }

        // récuperer les données des 4 capteurs:
        GetSensorData(SensorData);

        //les transferer au Serveur:
        TransferDataToServer(SensorData);


    }

    Stop();
}

void Scheduler::GetSensorData(float* SensorData)
{
    SensorData[T] = Temp_sensor.aleaSensorVal();
    SensorData[H] = Humidity_sensor.aleaSensorVal();
    SensorData[P] = Pressure_sensor.aleaSensorVal();
    SensorData[L] = Light_sensor.aleaSensorVal();
}

void Scheduler::TransferDataToServer(float* SensorData)
{
    SensorServer.UpdateValues(SensorData);
}

void Scheduler::Stop()
{
    SensorServer.CloseAll();
}
