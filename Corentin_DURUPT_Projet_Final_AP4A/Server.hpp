/**
 * @author DURUPT Corentin
 * @file Server.hpp
 * @date 20/09/2022
 * @brief this header is composed of the class Server
*/

#ifndef _SERVER_H
#define _SERVER_H

#include "Sensor.hpp"
#include "Temperature.hpp"
#include "Humidity.hpp"
#include "Light.hpp"
#include "Pressure.hpp"
#include<iostream>

/**
 * @class Server
 * @brief this class allows to create a Server. This one allows to display Sensors' datas in the console and to stock them in respective files
*/
class Server 
{
public:
    Temperature m_data_sensor_temperature; //a Temperature's Sensor
    Humidity m_data_sensor_humidity; //a Humidity's Sensor
    Light m_data_sensor_light; //a Light's Sensor
    Pressure m_data_sensor_pressure; //a Pressure's Sensor

public:
    //Definition of the Coplian's form
    /**
     *@brief the default constructor 
    */
    Server();
    /**
     *@brief the copy constructor 
     *@param ser => the Server
    */
    Server(const Server& ser);
    /**
     *@brief Overload of the affectation's operator
     *@return the pointer on the Server
     *@param ser => the Server 
    */
    Server& operator=(const Server& ser);
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
    *@param sensor => the reliated sensor
    */
   template <typename T>
    std::string data_sensor_contents(const Sensor<T>& sensor);
    /**
     *@brief this method allows to fill Sensor's datas in a respective file
     *@param ser => the Server
     *@param sen => the reliated sensor
    */
    template<typename T>
    void fileWrite(const Server& ser, const Sensor<T>& sen);
    /**
     *@brief this method allows to display the Sensors' datas in the console 
     *@param ser => the Server
     *@param sen => the reliated sensor
    */
    template <typename T>
    void consolWrite(const Server& ser, Sensor<T>& sen);
    /**
     *@brief this methods allows to the server to realise the willing action of the user
     *@param action_name => the name of the action that the server will effectuate. It could be "display", "stock" or "display and stock"
     *@param server => the server
     *@param sensor => the reliated sensor
    */
    template <typename T>
    void action(std::string action_name, Server& server, Sensor<T>& sensor);
};

#endif // _SERVER_H