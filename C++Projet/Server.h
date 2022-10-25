
//  ∗ @author Xiyu LUO
//  ∗ @file Server . h
//  ∗ @date 25/10/2022

// Define guards
#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <fstream>

using namespace std;

// ∗ @class Server
// ∗ @Class Sensor is used to abstract the real server connected to sensors
//    It provides a member function dataRcv for receiving data from the sensor
//    It provides two pritave member functions consolWrite and fileWrite
//    The first one is used to display the received data and the second one is used to write the data to the log file
//    Both of these functions can be disabled or enabled under certain conditions


template <class T>
class Server{
private:
    bool consolActivation;  //Enable or disable the display of data
    bool logActivation;  //Enable or disable the storage of data
    void fileWrite(T t);    //Write the data received from the sensor to the log file
    void consolWrite(T t);  //Display the data received from the sensor to the screen
public:
    Server(): consolActivation(0),logActivation(0){};
    ~Server(){};
    void dataRcv(T t);  //  Responsible for processing the data received from the sensor
};

#endif // SERVER_H