/**
 * @author Thibaud Leclere <thibaud.leclere@utbm.fr>
 * @file Server.cpp
 * @date 28/09/2022
 * @brief Implémentation de la class Server
 * @brief Reçoit et stock les données des capteurs
 */

#include "Server.hpp"

Server::Server() = default;
Server::~Server() = default;
Server::Server(const Server& s) = default;
Server& Server::operator=(const Server& s) = default;


void Server::consoleWrite(int valeurs[])
{
    std::cout << "=== Donnees Sensors ===" << std::endl;
    std::cout << "Humidity\t: " << valeurs[0] << " %" << std::endl;
    std::cout << "Light\t\t: " << (valeurs[1] ? "on" : "off") << std::endl;
    std::cout << "Pressure\t: " << valeurs[2] << " hPa" << std::endl;
    std::cout << "Temperature\t: " << valeurs[3] << " K" << std::endl;
}

void Server::fileWrite(int valeurs[])
{
    std::ofstream logHumidity;
    logHumidity.open("../logs/humidity.txt", std::ofstream::app);
    logHumidity << valeurs[0] << " %" << std::endl;
    logHumidity.close();

    std::ofstream logLight;
    logLight.open("../logs/light.txt", std::ofstream::app);
    logLight << (valeurs[1] ? "on" : "off") << std::endl;
    logLight.close();

    std::ofstream logPressure;
    logPressure.open("../logs/pressure.txt", std::ofstream::app);
    logPressure << valeurs[2] << " hPa" << std::endl;
    logPressure.close();

    std::ofstream logTemperature;
    logTemperature.open("../logs/temperature.txt", std::ofstream::app);
    logTemperature << valeurs[3] << " K" << std::endl;
    logTemperature.close();
}
