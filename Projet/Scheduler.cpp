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

    //use a while and incrementing a value instead of putting thread to sleep to follow keyboard events better
    while (this->m_going)
    {
        m_step++;


        //khbit will see if the keyboard has been active recently
        if(kbhit()){

        //getch will see which key has been pressed, if it is either 'c' or 'l' it will have an action
        switch (getch())
        {
        case 'c':

            if(this->m_serverObject.statusConsole())
            {
                this->m_serverObject.deActivateConsole();
            }else
            {
                this->m_serverObject.activateConsole();
            }

            break;
        case 'l': 

            if(this->m_serverObject.statusLog())
            {
                this->m_serverObject.deActivateLog();
            }else
            {
                this->m_serverObject.activateLog();
            }

        default:
            break;
        }
        }

        /** For each kind of sensor :
         * 1 : get data
         * 2 : generate next data
         * 3 : send data in appropriate structure to server
         * 4 : send data in appropriate structure to server
         **/

        //Pression
        if(m_step % 35000 == 0)
        {
            this->m_pression_d.info = this->m_pressionObject.getData();
            this->m_pressionObject.next();
            this->m_serverObject.consoleWrite<pression_data>(this->m_pression_d);
            this->m_serverObject.fileWrite<pression_data>(this->m_pression_d);
            if(this->m_serverObject.statusConsole()) cout << "--------------------------------------------------" <<endl;        
            
        }

        //Light
        if(m_step % 75000 == 0)
        {
            this->m_light_d.info = this->m_lightObject.getData();
            this->m_lightObject.next();
            this->m_serverObject.consoleWrite<light_data>(this->m_light_d);
            this->m_serverObject.fileWrite<light_data>(this->m_light_d);
            
            if(this->m_serverObject.statusConsole()) cout << "--------------------------------------------------" <<endl;        

        }

        //Humidity
        if(m_step % 115000 == 0)
        {
            this->m_humidity_d.info = this->m_humidtyObject.getData();
            this->m_humidtyObject.next();
            this->m_serverObject.consoleWrite<humidity_data>(this->m_humidity_d);
            this->m_serverObject.fileWrite<humidity_data>(this->m_humidity_d);
            if(this->m_serverObject.statusConsole()) cout << "--------------------------------------------------" <<endl;        
            
        }

        //Temperature
        if(m_step % 135000 == 0)
        {
            this->m_temperature_d.info = this->m_temperatureObject.getData();
            this->m_temperatureObject.next();
            this->m_serverObject.consoleWrite<temperature_data>(this->m_temperature_d);
            this->m_serverObject.fileWrite<temperature_data>(this->m_temperature_d);
            if(this->m_serverObject.statusConsole()) cout << "--------------------------------------------------" <<endl;        
        }

        

        

        
        
    
        
       
    }
    

}



#endif