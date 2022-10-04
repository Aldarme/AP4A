/**
 * @author Tontsa apala frank
 * @file Main.cpp
 * @date 25/09/2022
 * @brief main simulation file 
 */

#include <iostream>
#include <fstream>
#include <string>
#include "Scheduler.cpp"
#include "Server.cpp"
#include "Sensor.cpp"
#include "Temperature.cpp"
#include "Light.cpp"
#include "Pression.cpp"
#include "Humidity.cpp"
#include <ctime>

using namespace std;

int main(){
    srand(time(0));

    Scheduler alpha;

    alpha.SignalServer();
    
}