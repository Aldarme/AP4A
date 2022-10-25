/**
 * @author BIN ABDUL SHUKOR Muhammad Ariff
 * @file Sensor.hpp
 * @date 25/10/2022
 * @brief
 */
#ifndef SENSOR_H
#define SENSOR_H
#include <iostream>
#include <random>
#include <ctime>

template <class T>
class Sensor 
{
private:
    T value;
public:
    // Definition de la forme canonique
    Sensor(){};
    Sensor(T val):value(val) {};
    ~Sensor(){};

    T getData()
    {
        return value;
    };

    virtual T aleaGenVal()
    {
        T generatedNumber;
        generatedNumber=rand()%20+10;
        this->value=generatedNumber;
        return generatedNumber;
    }

    friend class Server;
    friend class Scheduler;
    friend class Temperature;
    friend class Pressure;
    friend class Light;
    friend class Humidity;
    friend class Packet;

};

class Temperature : public Sensor <float>{
    private:

    public:
    Temperature(){};
    Temperature(float t):Sensor(t){};
    virtual float aleaGenVal()
    {
        int low = 15;
        int high = 30;
        float r = low + static_cast<float>(rand()) * static_cast<float>(high - low) / RAND_MAX;
        this->value=r;
        return r;
    }
};

class Pressure : public Sensor <int>{
    private:

    public:
    Pressure(){};
    Pressure(int p):Sensor(p){};
    
};

class Humidity : public Sensor <float> {
    private:

    public:
    Humidity(){};
    Humidity(float h):Sensor(h){};
    virtual float aleaGenVal()
    {
        int low = 10;
        int high = 30;
        float r = low + static_cast<float>(rand()) * static_cast<float>(high - low) / RAND_MAX;
        this->value=r;
        return r;
    }
};

class Light : public Sensor <bool> {
    private:
        
    public:
    Light(){};
    Light(bool l):Sensor(l){};
    virtual bool aleaGenVal()
    {
        bool generatedValue;
        generatedValue=rand()%2;
        if (generatedValue==1)
        {
            this->value=true;
            return true;
        }
        else
        {this->value=false;return false;}
        
    }       
};

#endif //SENSOR_H