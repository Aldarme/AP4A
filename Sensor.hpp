#ifndef SENSOR_H
#define SENSOR_H

class Sensor
{
protected:
    float m_MIN_VAL;
    float m_MAX_VAL;

    float aleaGenVal();

public:
    Sensor(float p_MIN_VAL, float p_MAX_VAL);
    float getData();
};

#endif // SENSOR_H