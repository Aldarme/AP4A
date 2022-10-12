/**
 * @author lois ROGER
 * @file Sensor.hpp
 * @date 05/09/2022
 * @brief les capteurs permettent de créer différentes données et de les récupérer
*/
#ifndef SENSOR_H
#define SENSOR_H

class Sensor
{
    public:
    Sensor();
    ~Sensor();
    Sensor(const sensor& s);
    Sensor operator=(const Sensor& s);    
    int getData(int mini, int maxi);
    int aleaGenVal(int mini, int maxi);
    
    
};

#endif