/**
 * @author Muna Ayuni MAHATHIR
 * @file Sensor.hpp
 * @brief This class contains all the data necessary from each sensor. It is a base class with the child class of each sensor.
 */

#ifndef SENSOR_HPP
#define SENSOR_HPP


//The base class which contains all the sensors
class Sensor
{
    public:
        Sensor(){}
        virtual ~Sensor(){}
        int getdata() ;

    protected:
       virtual int aleagenval()=0 ;

};


// Child class of Sensor : Light which represents the light sensor 
class Light : public Sensor
{
    public:
        Light(){}
        virtual ~Light(){}
        int aleagenval () override;

};


// Child class of Sensor : Humidity which represents the humidity sensor 
class Humidity : public Sensor
{
    public:
        Humidity(){}
        virtual ~Humidity(){}
        int aleagenval() override;

};


// Child class of Sensor : Temperature which represents the temperature sensor 
class Temperature : public Sensor
{
    public:
        Temperature(){}
        virtual ~Temperature(){} 
        int aleagenval() override;

};


// Child class of Sensor : Pression which represents the pressure sensor 
class Pression : public Sensor
{
    public:
        Pression(){}
        virtual ~Pression(){}
        int aleagenval() override;

};


#endif // SENSOR_HPP