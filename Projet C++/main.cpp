#include <iostream>
#include"SCHEDULER.h"
int main()
{
    Temperature m_SensorTemperature;
    Humidity m_SensorHumidity;
    Light m_SensorLight;
    Pression m_SensorPression;
    Server m_Ser;
    ////définir le temps d'intervalle
    int m_time = 2; 
    int m_time_temperature=1000; 
    int m_time_pression=2000; 
    int m_time_light=3000; 
    int m_time_humidity=4000; 

    Scheduler m_Scheduler(m_Ser, m_SensorTemperature, m_SensorHumidity, m_SensorLight, m_SensorPression);
    srand(time(NULL));

    for (int m_actual_time = 1; m_actual_time <= m_time * 1000; m_actual_time++) {
        m_Scheduler.sendServer(m_actual_time, m_time_temperature, m_time_pression, m_time_light, m_time_humidity);
    }
    return 0;
}

