/**
 * @author DURUPT Corentin
 * @file Main.cpp
 * @date 20/09/2022
 * @brief This is the main fonction of the program.
*/
#include <windows.h>
#include <iostream>
#include "Sensor.cpp"
#include "Scheduler.cpp"
#include "Server.cpp"
#include "Temperature.cpp"
#include "Humidity.cpp"
#include "Light.cpp"
#include "Pressure.cpp"
using namespace std;


int main(){

    Temperature T_sensor("Temperature");
    Humidity H_sensor("Humidity");
    Light L_sensor("Light");
    Pressure P_sensor("Pressure");

    //frequency is in milisecondes
    Scheduler scheduler(3000, 2000, 1000, 4000);

    cout << "[Server]" << endl;
    scheduler.timer(T_sensor, H_sensor, L_sensor, P_sensor);
    
}
