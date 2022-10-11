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
    time_t start, end;
    
    time(&start);

    while (true)
    {
        if (difftime(time(&end), start) > 3)
        {
            Package pac_h(m_humid.getData(), "humidity", "%");
            Package pac_l(m_light.getData(), "light", "");
            Package pac_t(m_temp.getData(), "temperature", "c°");
            Package pac_p(m_pres.getData(), "pressure", "psc");

            if (p_server.m_consol)
            {
                p_server.consolWrite(pac_h);
                p_server.consolWrite(pac_p);
                p_server.consolWrite(pac_t);
                p_server.consolWrite(pac_l);
            }
            if (p_server.m_file)
            {
                p_server.fileWrite(pac_h);
                p_server.fileWrite(pac_p);
                p_server.fileWrite(pac_t);
                p_server.fileWrite(pac_l);
            }
            

            time(&start);
        }
        
    }

}