//
// Created by Jules Ferlin on 24/09/2022.
//

#ifndef PROJET_AP4A_SERVER_HPP
#define PROJET_AP4A_SERVER_HPP

#include <iostream>
#include <fstream>
#include "Sensors/Humidite.hpp"
#include "Sensors/Light.hpp"
#include "Sensors/Pression.hpp"
#include "Sensors/Temperature.hpp"

class Server
{
private:
    bool m_consolActivation;
    bool m_logActivation;
public:
    Server();
    Server(const Server& param_server);
    ~Server();
    Server& operator=(const Server& param_server);
/*
    template<typename T>
    void fileWrite(Sensor<T> param_sensor);
*/
    template<typename T>
    void fileWrite(const std::string& param_name,T param_value,const std::string& param_unite);
    template<typename T>
    void consolWrite(const std::string& param_name,T param_value,const std::string& param_unite);


};
/*
template<typename T>
void fileWrite(Sensor<T> param_sensor)
{
    std::ofstream file(param_sensor.getName() + ".txt", std::ios::app);
    file << param_sensor.getData() << " " << param_sensor.getUnite() << std::endl;
    file.close();
}
 */

template<typename T>
void Server::fileWrite(const std::string& param_name, const T param_value, const std::string& param_unite)
{
    std::ofstream file(param_name + ".txt", std::ios::app);
    file << param_name << " " << param_value << " " << param_unite << std::endl;
    file.close();
}

template<typename T>
void Server::consolWrite(const std::string& param_name, const T param_value, const std::string& param_unite)
{
    std::cout << param_name << " " << param_value << " " << param_unite << std::endl;
}


#endif //PROJET_AP4A_SERVER_HPP
