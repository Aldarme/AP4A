#include "Sensor.hpp"
#include <cstdlib>
#include <ctime>
using namespace std;

sensor sensor::aleaGenVal(int min, int max)
{
    srand((int)time(0));
    m_data = rand() % (max + 1 - min) + min;
    return *this;
}

int sensor::getData()
{
    return m_data;
}

sensor temperature::getAlea()
{
    return aleaGenVal(20, 25);
}

sensor pressure::getAlea()
{
    return aleaGenVal(75, 81);
}

sensor light_::getAlea()
{
    return aleaGenVal(0, 1);
}

sensor humidity::getAlea()
{
    return aleaGenVal(5, 10);
}