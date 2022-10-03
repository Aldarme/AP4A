#include <iostream>
#include <fstream>
#include <string>
#include "Scheduler.cpp"
#include "Server.cpp"
#include "Sensor.cpp"
#include "Temperature.cpp"
#include "Light.cpp"
#include "Pressure.cpp"
#include "Humidity.cpp"
#include <ctime>

using namespace std;

int main(){
    srand(time(0));

    Scheduler alpha;

    alpha.SignalServer();
    
}