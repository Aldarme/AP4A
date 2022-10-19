/**
 * @author BRICHET_Clement
 * @file Server.h
 * @date 23/09/2022
 * @brief This project's goal is to simulate a plane environment with its sensors and retrieve the randomly generated data from the sensors.
 * */

#ifndef SERVER_H
#define SERVER_H

#include "Sensor.hpp"
#include <iostream>
#include <fstream>

/**
 * @class Server
 * @brief The server is charged of printing and saving the data in the console and log files respectively.
 * */

class Server
{
    private:

    public:
        //Canonic functions
        Server();
        Server(const Server&);
        Server& operator=(const Server&);
        ~Server();

        /**
         * @brief This function allows us to save data in log .txt files, depending on which sensor it works with.
         * @param sourceSensor_p: We give a sensor to the function so that it can find the associated log file and retrieve the stored data.
         * */
        template <class Type> void fileWrite(Type sourceSensor_p)
        {
            std::ofstream myFile;
            myFile.open(sourceSensor_p.getType()+"_log.txt", std::ios::app);    //This is how we decide where to write the log data.
            myFile << "Data from the " << sourceSensor_p.getType() << " sensor: " << sourceSensor_p.getData() << sourceSensor_p.getUnit() << "\n" << std::endl; //Just to make things slightly prettier.
            myFile.close();
        }

        /**
         * @brief This function allows us to show the data directly in the console.
         * @param sourceSensor_p: We put a sensor in parameter so that it can retrieve the data stored inside.
         * */
        template <class Type> void consoleWrite(Type sourceSensor_p)
        {
            std::cout << "Data from the " << sourceSensor_p.getType() << " sensor: " << sourceSensor_p.getData() << sourceSensor_p.getUnit() << "\n" << std::endl;
        }
};

#endif //SERVER_H