#ifndef SCHEDULER_CPP
#define SCHEDULER_CPP

#include "Scheduler.hpp"



using std::this_thread::sleep_for;

using namespace std;

/**
* @brief Methode starting an infinite cycle occuring every "frequency" seconds, fill values of objects into the appropriate structures before writing them in files as well as the console and
* generating new values for the objects
**/
void Scheduler::startClock()
{


    while (true)
    {
        this->pression_d.info = this->pression_object.getData();
        this->light_d.info = this->light_object.getData();
        this->humidity_d.info = this->humidty_object.getData();
        this->temperature_d.info = this->temperature_object.getData();

        this->pression_object.next();
        this->light_object.next();
        this->humidty_object.next();
        this->temperature_object.next();

        this->server_object.consoleWrite<humidity_data>(this->humidity_d);
        this->server_object.consoleWrite<light_data>(this->light_d);
        this->server_object.consoleWrite<temperature_data>(this->temperature_d);
        this->server_object.consoleWrite<pression_data>(this->pression_d);

        cout << "--------------------------------------------------" <<endl;

        this->server_object.fileWrite<humidity_data>(this->humidity_d);
        this->server_object.fileWrite<light_data>(this->light_d);
        this->server_object.fileWrite<temperature_data>(this->temperature_d);
        this->server_object.fileWrite<pression_data>(this->pression_d);


        std::this_thread::sleep_for(std::chrono::seconds(this->frequency));
    }
    

}



#endif