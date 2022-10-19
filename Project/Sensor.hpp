/**
 * @author Muna Ayuni MAHATHIR
 * @file Sensor.hpp
 * @brief This class contains all the data necessary from each sensor. It is a base class with the child class of each sensor.
 */

#ifndef SENSOR_HPP
#define SENSOR_HPP


//The base class which contains all the sensors
template <typename T>
class Sensor
{
    public:
        Sensor(){}
        virtual ~Sensor(){}
        T getdata() 
        {
            return this->aleagenval() ;
        }
        
    protected:
    virtual T aleagenval()=0 ;

};


// Child class of Sensor : Light which represents the light sensor 
class Light : public Sensor <bool>
{
    public:
        Light(){}
        virtual ~Light(){}
        bool aleagenval () override;

};


// Child class of Sensor : Humidity which represents the humidity sensor 
class Humidity : public Sensor <float>
{
    public:
        Humidity(){}
        virtual ~Humidity(){}
        float aleagenval() override;

};


// Child class of Sensor : Temperature which represents the temperature sensor 
class Temperature : public Sensor <float>
{
    public:
        Temperature(){}
        virtual ~Temperature(){} 
        float aleagenval() override;

};


// Child class of Sensor : Pression which represents the pressure sensor 
class Pression : public Sensor <int>
{
    public:
        Pression(){}
        virtual ~Pression(){}
        int aleagenval() override;

};


#endif // SENSOR_HPP