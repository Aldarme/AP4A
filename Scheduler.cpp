/*
author: Tom PALLEAU
date: 10/1/2022
licence: free
class: Scheduler
*/

#include <time.h>
#include "Scheduler.hpp"
#include "Server.hpp"
#include "Light.hpp"
#include "Temperature.hpp"
#include "Pressure.hpp"
#include "Humidity.hpp"

using namespace std;

/**
 * @brief Construct a new Scheduler:: Scheduler object
 * get user input for consolWrite and fileWrite for server
 * 
 */
Scheduler::Scheduler()
{
    bool consol_write;
    bool file_write;
    cout << "do you wish to write in consol[0 or 1]:";
    cin >> consol_write;
    cout << "do you wish to write in file[0 or 1]:";
    cin >> file_write;

    Server server(consol_write, file_write);
    sendData(server);
}


/**
 * @brief get sensor values and store info in package then send to server
 * 
 * @param p_server 
 */
void Scheduler::sendData(Server p_server)
{
    time_t start;
    int new_time_elapsed, old_time_elapsed = 0;
    
    time(&start);

    while (true)
    {   
        new_time_elapsed = time(0) - start;

        //evoids running multiple time in same second
        if (old_time_elapsed != new_time_elapsed)
        {
            // seperate every sequence
            cout << "----------------" << endl;

            // modulo the number of seconds before sending data
            if (new_time_elapsed % 1 == 0){
                Package<int> pac_p(m_pres.getData(), "pressure", "psc");
                p_server.receiveData(pac_p);
            }
            if (new_time_elapsed % 2 == 0)
            {
                Package<float> pac_t(m_temp.getData(), "temperature", "c°");
                p_server.receiveData(pac_t);
            }
            if (new_time_elapsed % 3 == 0)
            {
                Package<float> pac_h(m_humid.getData(), "humidity", "%");
                p_server.receiveData(pac_h);
            }
            if (new_time_elapsed % 4 == 0)
            {
                Package<bool> pac_l(m_light.getData(), "light", "");
                p_server.receiveData(pac_l);
            }

            // reset
            old_time_elapsed = new_time_elapsed;
        }
    }

}