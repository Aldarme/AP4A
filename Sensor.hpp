/**
 * @author DURUPT Corentin
 * @file Sensor.hpp
 * @date 21/09/2022
 * @brief yhis header is composed of the mother class Sensor and its different subclasses Temperature, Humidity, Light and Pressure
*/

#ifndef _SENSOR_H
#define _SENSOR_H

#include<iostream>

/**
 * @class Sensor
 * @brief This class allows to build a Sensor. a Sensor is composed of a name and a data, this data will be gererate randomly.
 */
class Sensor 
{
private :
    std::string m_sensor_name; //the name of the sensor
    int m_data; //the data of the sensor
    
public :
    /**
    *@brief the default constructor 
    */
    Sensor();
    /**
    *@brief the destructor 
    */
    ~Sensor();
    /**
    *@brief this constructor initialize the name of the Sensor
    *@param name => a string matches the name of the Sensor
    */
    Sensor(std::string);
    /**
    *@brief this method allows to get the Sensor's data
    *@return the pointer on the Sensor 
    */
    Sensor getData();

private :
    /**
    *@brief this method allows to generate a random data 
    *@return the pointer on the Sensor
    */
    Sensor aleaGenVal();

/**
*@brief the class Server is allowed to use the Sensor's attributes 
*/
friend class Server;
/**
*@brief the class Scheduler is allowed to use the Sensor's attributes 
*/
friend class Scheduler;
/**
*@brief Overload of the display's operator
*@return a variable of ostream's type
*@param os => a variable of ostream's type
*@param sensor => a Sensor
*/
friend std::ostream& operator<<(std::ostream& os, const Sensor& sensor);
};

/**
 * @class Temperature
 * @brief this class allows to create a Temperature's Sensor 
*/
class Temperature : public Sensor
{
public :
    Temperature();
    Temperature(std::string name) : Sensor(name){};
};

/**
 * @class Humidity
 * @brief this class allows to create a Humidity's Sensor 
*/
class Humidity : public Sensor 
{
public :
    Humidity();
    Humidity(std::string name) : Sensor(name){};
};

/**
 * @class Light
 * @brief this class allows to create a Light's Sensor 
*/
class Light : public Sensor
{
public :
    Light();
    Light(std::string name) : Sensor(name){};
};

/**
 * @class Pressure
 * @brief this class allows to create a Pressure's Sensor 
*/
class Pressure : public Sensor
{
public :
    Pressure();
    Pressure(std::string name) : Sensor(name){};
};
#endif // _SENSOR_H



