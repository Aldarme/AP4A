/**
 *  @author adamzm
 *  @file Sensor.h
 */

#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
#include <string>

template <class T>
class Sensor {    
    protected:
        T m_data;
        std::string m_type;

        // generate a random value
        virtual T aleaGenVal() = 0;
        

    public:
        // constructor
        Sensor(T data_p = 0, std::string type_p = "unknown") {
            m_data = data_p;
            m_type = type_p;
        }
        
        // constructor by copy
        Sensor(const Sensor& sensor_p) {
            this->m_data = sensor_p.m_data;
            this->m_type = sensor_p.m_type;
        }
        
        // destructor
        virtual ~Sensor() {}

        // operator=
        Sensor& operator=(const Sensor& sensor_p) {
            this->m_data = sensor_p.m_data;
            this->m_type = sensor_p.m_type;
        }

        // float getData : return float for Temperature and Humidity
        T getData() {
            return aleaGenVal();
        }

        // std::string getType :  return a string of teh sensor's type
        std::string getType() {
            return m_type;
        }
        
};

class Temperature : public Sensor<float> {
    
    public:
        // constructor
        Temperature(float data_p = 0.0) {
            m_data = data_p;
            m_type = "Temperature";
        }

        // aleaGenVal() : generate random integer between 20 and 30 degree Celcius
        float aleaGenVal();
};

class Humidity : public Sensor<float> {
    public:
        // constructor
        Humidity(float data_p = 0.0) {
            m_data = data_p;
            m_type = "Humidity";
        }
        

        // aleaGenVal() : generate random integer between 1 and 15% humidity
        float aleaGenVal();
};

class Pressure : public Sensor<int> {
    public : 
        // constructor
        Pressure(int data_p = 0) {
            m_data = data_p;
            m_type = "Pressure";
        }

        // aleaGenVal() : generate random integer between 10 and 15 PSI
        int aleaGenVal();
};

class Light : public Sensor<bool> {
    public:
        //constructor
        Light(bool data_p = false) {
            m_data =data_p;
            m_type = "Light";
        }

        // aleaGenVal() : generate random integer between 1 and 0;
        bool aleaGenVal();
};

#endif // SENSOR_H