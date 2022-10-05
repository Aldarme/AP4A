/**
 * @author  gilles_maurer
 * @file    Server.hpp
 * @date    03/10/2022
 * @brief   Server class, write data in a file and in the console
 */

#ifndef SERVER_H
#define SERVER_H

#include "Sensor.hpp"

#include <string>

class Server 
{
private:
    bool m_logsActivated;
    bool m_consoleActivated;
    
public:

    //Definition of the canonical form
    Server();
    Server(const Server& param_se);
    Server& operator=(const Server& param_se);
    ~Server();

    //write the data on the console
    void consoleWrite(int param_value, std::string param_type, std::string param_unity);

    //add a new line on the console
    void consoleWrite();

    //activate the console
    void activateConsole();
    
    //write the data in the file
    void fileWrite(int param_value, std::string param_type, std::string param_unity);
    
    //add a new line in the file
    void fileWrite();

    //reset the logs file
    void resetLogs();

    //activate the logs
    void activateLogs();
};

#endif // SERVER_H


