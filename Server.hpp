/**
 * @author DURUPT Corentin
 * @file Server.hpp
 * @date 20/09/2022
 * @brief this header is composed of the class Server
*/

#ifndef _SERVER_H
#define _SERVER_H

#include "Sensor.hpp"
#include<iostream>

/**
 * @class Server
 * @brief this class allows to create a Server. This one allows to display Sensors' datas in the console and to stock them in respective files
*/
class Server 
{
private:
    Temperature m_data_sensor_temperature; //a Temperature's Sensor
    Humidity m_data_sensor_humidity; //a Humidity's Sensor
    Light m_data_sensor_light; //a Light's Sensor
    Pressure m_data_sensor_pressure; //a Pressure's Sensor

public :
    //Definition of the Coplian's form
    /**
     *@brief the default constructor 
    */
    Server();
    /**
     *@brief the copy constructor 
     *@param ser => the Server
    */
    Server(const Server&);
    /**
     *@brief Overload of the affectation's operator
     *@return the pointer on the Server
     *@param ser => the Server 
    */
    Server& operator=(const Server&);
    /**
     *@brief the destructor 
    */
    ~Server();


    /**
     *@brief this constructor allows to initialise the 4 Sensors of the Server 
     *@param t => a sensor of type Temperature 
     *@param h => a sensor of type Humidity 
     *@param l => a sensor of type Light 
     *@param p => a sensor of type Pressure 
    */
    Server(const Temperature& t, const Humidity& h, const Light& l, const Pressure& p);
    /**
    *@brief this method allows to transform datas of a Sensor (Sensor's name + data) into a string in order to fill it in a respective file 
    *@return a string which matches a ligne of a file 
    *@param s => a Sensor
    */
    string data_sensor_contents(const Sensor& s);
    /**
     *@brief this method allows to fill Sensor's datas in a respective file
     *@param ser => the Server
    */
    void fileWrite(const Server& ser);

    /**
     *@brief this method allows to display the Sensors' datas in the console 
     *@param ser => the Server
    */
    void consolWrite(const Server& ser);
};

#endif // _SERVER_H