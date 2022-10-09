#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>

class sensor
{
private:
    int m_data;

public:
    sensor() : m_data() {}
    sensor(const sensor &param_s) : m_data(param_s.m_data) {}
    ~sensor() {}

    sensor aleaGenVal(int, int);
    int getData();
};

#endif // SENSOR_H