/**
 *  @author adamzm
 *  @file main.cpp
 */

#include "Server.h"
#include "Sensor.h"
#include "Scheduler.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <fstream>

using namespace std;

int main() {
    Scheduler scheduler(5); // transmit/write data each 5 seconds

    for(int i = 0; i<10; ++i) { // run the program for 10 times. Can change in while loop to run the program infinitely
        scheduler.transmitData();
    }
}