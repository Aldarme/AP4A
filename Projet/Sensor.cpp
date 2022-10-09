#include "Sensor.hpp"
#include <cstdlib>
#include <ctime>
using namespace std;

sensor sensor::aleaGenVal(int param_min, int param_max)
{
    srand((int)time(0));
    m_data = rand() % (param_max + 1 - param_min) + param_min;
    return *this;
}

int sensor::getData()
{
    return m_data;
}