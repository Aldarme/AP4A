/**
 *  @author BIN ADNAN Muhammad Izzat Affandi
 *  @file Scheduler.hpp
 *  @date 4/10/2022
 *  @brief This file contains declarations of the class "Scheduler"
 */

#ifndef SENSOR_H
#define SENSOR_H

class Sensor
{
private:
    int m_data;
public:
    Sensor()
    {
        this->m_data = 0;
    };
    ~Sensor(){};
    int getData();
    void aleaGenVal(int lowest_p,int highest_p);
};

class Temperature : public Sensor
{

};

class Pression : public Sensor
{

};

class Humidity : public Sensor
{

};

class Light : public Sensor
{

};

#endif //SENSOR_H