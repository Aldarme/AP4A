/**
 *  @author adamzm
 *  @file Sensor.h
 */

#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>


class Sensor {
    protected:
        int m_data;

        // generate a random integer
        virtual int aleaGenVal() = 0;

    public:
        // constructor
        Sensor(int data_p = 0) {
            m_data = data_p;
        }

        // constructor by copy
        Sensor(const Sensor& sensor_p) {
            this->m_data = sensor_p.m_data;
        }
        
        // destructor
        ~Sensor() {}

        // operator=
        Sensor& operator=(const Sensor& sensor_p) {
            this->m_data = sensor_p.m_data;
        }

        // getData : return the value of the sensor concerned
        int getData(); 
};

class Temperature : public Sensor {
    public:
        // constructor
        Temperature(int data_p = 0) {
            m_data = data_p;
        }

        // aleaGenVal() : generate random integer between 20 and 30 degree Celcius
        int aleaGenVal();
};

class Humidity : public Sensor {
    public:
        // constructor
        Humidity(int data_p = 0) {
            m_data = data_p;
        }

        // aleaGenVal() : generate random integer between 1 and 15% humidity
        int aleaGenVal();
};

class Pressure : public Sensor {
    public : 
        // constructor
        Pressure(int data_p = 0) {
            m_data = data_p;
        }

        // aleaGenVal() : generate random integer between 10 and 15 PSI
        int aleaGenVal();
};

class Light : public Sensor {
    public:
        //constructor
        Light(int data_p = 0) {
            m_data = data_p;
        }

        // aleaGenVal() : generate random integer between 1 and 0;
        int aleaGenVal();
};

#endif // SENSOR_H