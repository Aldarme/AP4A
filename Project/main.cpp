/**
 *  @author adamzm
 *  @file main.cpp
 */

#include "Server.h"
#include "Sensor.h"
#include "Scheduler.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <chrono>
#include <thread>
using namespace std;


int main() {

    Scheduler scheduler;
    scheduler.setInterval();
    scheduler.showOnConsole();
    scheduler.dataQuantity();
    scheduler.transmitData();
    
    return 0;

    
}