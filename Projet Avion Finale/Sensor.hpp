/**
 *  @author BIN ADNAN Muhammad Izzat Affandi
 *  @file Scheduler.hpp
 *  @date 4/10/2022
 *  @brief This file contains declarations of the class "Scheduler"
 */

#ifndef SENSOR_H
#define SENSOR_H

template <class T> class Sensor
{
private:
    T m_data;
public:
    Sensor(){};
    ~Sensor(){};
    T getData();
    virtual T aleaGenVal()=0;
};

class Temperature : public Sensor<float>
{
public:
    Temperature(){};
    ~Temperature(){};
    float aleaGenVal();
};

class Pression : public Sensor<int>
{
public:
    Pression(){};
    ~Pression(){};
    int aleaGenVal();
};

class Humidity : public Sensor<float>
{
public:
    Humidity(){};
    ~Humidity(){};
    float aleaGenVal();
};

class Light : public Sensor<bool>
{
public:
    Light(){};
    ~Light(){};
    bool aleaGenVal();
};

#endif //SENSOR_H