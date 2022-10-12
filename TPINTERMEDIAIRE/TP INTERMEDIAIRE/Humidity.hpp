//Humidity.hpp

#include "Sensor.hpp"

class Humidity : public Sensor
{
public:

    Humidity() {
        m_value = 10;
        m_maxValue = 50;
        m_minValue = 0;
    }

};


