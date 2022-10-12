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
        step++;


        //khbit will see if the keyboard has been active recently
        if(kbhit()){

        //getch will see which key has been pressed, if it is either 'c' or 'l' it will have an action
        switch (getch())
        {
        case 'c':

            if(this->server_object.statusConsole())
            {
                this->server_object.deActivateConsole();
            }else
            {
                this->server_object.activateConsole();
            }

            break;
        case 'l': 

            if(this->server_object.statusLog())
            {
                this->server_object.deActivateLog();
            }else
            {
                this->server_object.activateLog();
            }

        default:
            break;
        }
        }

        //Pression
        if(step % 35000 == 0)
        {
            this->pression_d.info = this->pression_object.getData();
            this->pression_object.next();
            this->server_object.consoleWrite<pression_data>(this->pression_d);
            this->server_object.fileWrite<pression_data>(this->pression_d);
            if(this->server_object.statusConsole()) cout << "--------------------------------------------------" <<endl;        
            
        }

        //Light
        if(step % 75000 == 0)
        {
            this->light_d.info = this->light_object.getData();
            this->light_object.next();
            this->server_object.consoleWrite<light_data>(this->light_d);
            this->server_object.fileWrite<light_data>(this->light_d);
            
            if(this->server_object.statusConsole()) cout << "--------------------------------------------------" <<endl;        

        }

        //Humidity
        if(step % 115000 == 0)
        {
            this->humidity_d.info = this->humidty_object.getData();
            this->humidty_object.next();
            this->server_object.consoleWrite<humidity_data>(this->humidity_d);
            this->server_object.fileWrite<humidity_data>(this->humidity_d);
            if(this->server_object.statusConsole()) cout << "--------------------------------------------------" <<endl;        
            
        }

        //Temperature
        if(step % 135000 == 0)
        {
            this->temperature_d.info = this->temperature_object.getData();
            this->temperature_object.next();
            this->server_object.consoleWrite<temperature_data>(this->temperature_d);
            this->server_object.fileWrite<temperature_data>(this->temperature_d);
            if(this->server_object.statusConsole()) cout << "--------------------------------------------------" <<endl;        
        }

        

        

        
        
    
        
       
    }
    

}



#endif