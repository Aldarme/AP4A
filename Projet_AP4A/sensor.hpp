/**
 * @author Jules Ferlin
 * @file Sensor.hpp
 * @date
 * @brief
 */

#ifndef PROJET_AP4A_Sensor_HPP
#define PROJET_AP4A_Sensor_HPP

class Sensor
{
private:
    /* data */
public:
    Sensor();
    Sensor(Sensor& t_p);
    ~Sensor();
    Sensor(int data_p);
    int getData();
    int aleaGenVal();
};

class Temperature : public Sensor
{
private:
    /* data */
public:
    Temperature(/* args */);
    ~Temperature();
};

#endif //PROJET_AP4A_Sensor_HPP
