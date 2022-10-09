#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>

class sensor
{
private:
    int m_data;

public:
    sensor() : m_data() {}
    sensor(const sensor &s) : m_data(s.m_data) {}
    ~sensor() {}

    sensor aleaGenVal(int, int);
    int getData();
};

class temperature : public sensor
{
public:
    sensor getAlea();
};

class pressure : public sensor
{
public:
    sensor getAlea();
};

class light_ : public sensor
{
public:
    sensor getAlea();
};

class humidity : public sensor
{
public:
    sensor getAlea();
};

#endif // SENSOR_H