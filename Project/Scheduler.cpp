/**
 *  @author adamzm
 *  @file Scheduler.cpp
 */

#include "Scheduler.h"
#include "Sensor.h"
#include "Server.h"
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <string>
#include <thread>
using namespace std;

void Scheduler::setInterval() {
    int delayT, delayH, delayP, delayL;
    cout << "Please enter the delay for each sensors (in seconds)" << endl;
    cout << "Temperature : ";
    cin >> delayT;
    cout << "Humidity : ";
    cin >> delayH;
    cout << "Pressure : ";
    cin >> delayP;
    cout << "Light : ";
    cin >> delayL;

    this->m_timeT = delayT;
    this->m_timeH = delayH;
    this->m_timeP = delayP;
    this->m_timeL = delayL;
}
void Scheduler::showOnConsole() {
    char choice;

    std::cout << "Would you like to show datas on the console? (y/n)" << std::endl;
    std::cin >> choice;
    while (choice != 'y' && choice != 'n') {
        std::cout << "please enter a correct choice, 'y' or 'n'" << std::endl;
        std::cin >> choice;
    }
    showConsole = choice;
}

void Scheduler::dataQuantity() {
    int qtt;
    char answer = 'n';
    
    while (answer == 'n') {
        cout << "How many datas do you want to collect?" << endl;
        cin >> qtt;
        cout << "Are you sure? (y/n)" << endl;
        cin >> answer;
        while (answer != 'y' && answer != 'n') {
            std::cout << "please enter a correct choice, 'y' or 'n'" << std::endl;
            std::cin >> answer;
        }
    }
    dataQtt = qtt;
}

void Scheduler::transmitData() { // run multiple threads to write datas on different intervals
    
    std::thread transmitTemp([this](){
        Server server;
        Sensor<float> *sensor = new Temperature();
        server.resetFile(sensor->getType()); // reset log.txt
        for (int i = 0; i<dataQtt; ++i) {
            float data = sensor->getData();
            if (showConsole == 'y') {
                server.consoleWrite(to_string(data).substr(0, 5), sensor->getType());
            }
            server.fileWrite(to_string(data).substr(0, 5), sensor->getType());

            std::this_thread::sleep_for(std::chrono::seconds(m_timeT)); // sleep for temperature's delay timer
        } 
    });

    std::thread transmitHumid([this](){
        Server server;
        Sensor<float> *sensor = new Humidity();
        server.resetFile(sensor->getType()); // reset log.txt
        for (int i = 0; i<dataQtt; ++i) {
            float data = sensor->getData();
            if (showConsole == 'y') {
                server.consoleWrite(to_string(data).substr(0, 5), sensor->getType());
            }
            server.fileWrite(to_string(data).substr(0, 5), sensor->getType());

            std::this_thread::sleep_for(std::chrono::seconds(m_timeH)); // sleep for humidity's delay timer
        }
    });

    std::thread transmitPressure([this](){
        Server server;
        Sensor<int> *sensor = new Pressure();
        server.resetFile(sensor->getType()); // reset log.txt
        for (int i = 0; i<dataQtt; ++i) {
            int data = sensor->getData();
            if (showConsole == 'y') {
                server.consoleWrite(to_string(data), sensor->getType());
            }
            server.fileWrite(to_string(data), sensor->getType());

            std::this_thread::sleep_for(std::chrono::seconds(m_timeP)); // sleep for pressure's delay timer
        } 
    });

    std::thread transmitLight([this](){
        Server server;
        Sensor<bool> *sensor = new Light();
        server.resetFile(sensor->getType()); // reset log.txt
        for (int i = 0; i<dataQtt; ++i) {
            bool data = sensor->getData();
            if (showConsole == 'y') {
                server.consoleWrite(to_string(data), sensor->getType());
            }
            server.fileWrite(to_string(data), sensor->getType());

            std::this_thread::sleep_for(std::chrono::seconds(m_timeL)); // sleep for light's delay timer
        }
    });


    transmitTemp.join();
    transmitHumid.join();
    transmitPressure.join();
    transmitLight.join();
        
    
}
