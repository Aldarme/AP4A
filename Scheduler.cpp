#include <iostream>
#include "Scheduler.hpp"
#include <unistd.h>

using namespace std;

[[noreturn]] void Scheduler::theWork() {
    while (true) //This loop never end
    {
        if (Clock() % 4 == 0) //If the clock is a multiple of 4
        {
            cout << "Pression :" << endl;
            Server::displayint(pre.getData()); //Display the value of the pression
            cout << endl;
            sleep(1); //Wait 1 second, otherwise it will display for 4.01, 4.02, 4.03...
        }
        if (Clock() % 5 == 0) //If the clock is a multiple of 5
        {
            cout << "Temperature :" << endl;
            Server::displayfloat(tem.getData()); //Display the value of the temperature
            cout << endl;
            sleep(1); //Wait 1 second, otherwise it will display for 5.01, 5.02, 5.03...
        }
        if (Clock() % 8 == 0) //If the clock is a multiple of 8
        {
            cout << "Humidity :" << endl;
            Server::displayfloat(hum.getData()); //Display the value of the humidity
            cout << endl;
            sleep(1); //Wait 1 second, otherwise it will display for 8.01, 8.02, 8.03...
        }
        if (Clock() % 10 == 0) //If the clock is a multiple of 10
        {
            cout << "Light :" << endl;
            Server::displaybool(lig.getData()); //Display the value of the light
            cout << endl;
            sleep(1); //Wait 1 second, otherwise it will display for 10.01, 10.02, 10.03...
        }
    }
}

int Scheduler::Clock() { //return the time in seconds
    time_t now = time(0); //Getting the time
    tm *ltm = localtime(&now); //Converting the time into a tm structure
    return ltm->tm_sec; //Returning the seconds part of the tm structure

}

Scheduler::Scheduler(const Humidity &hum, const Light &lig, const Temperature &tem, const Pression &pre) : hum(hum),
                                                                                                           lig(lig),
                                                                                                           tem(tem),
                                                                                                           pre(pre) {}

ostream &operator<<(ostream &os, const Scheduler &scheduler) {
    os << "hum: " << scheduler.hum << " lig: " << scheduler.lig << " tem: " << scheduler.tem << " pre: "
       << scheduler.pre;
    return os;
}

Scheduler::Scheduler() {

}; //Calling the datas


static int Clock() {
    return time(NULL);
}; //This function is used to get the time of the day