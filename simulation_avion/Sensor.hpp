#ifndef SENSOR_H
#define SENSOR_H

class Sensor 
{
    protected:
        int data; 
        virtual int aleaGenValue() = 0; 

    public: 

        Sensor();
        Sensor(const Sensor& s); 
        Sensor& operator=(const Sensor& s); 
        ~Sensor() {}

        int getData();

};


#endif // SENSOR_H


