/**
 *  @author adamzm
 *  @file Scheduler.h
 */

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Sensor.h"
#include "Server.h"
#include <iostream>

class Scheduler {
    private:
        int m_timeT; // time interval to send Temperature
        int m_timeH; // time interval to send Humidity
        int m_timeP; // time interval to send Pressure
        int m_timeL; // time interval to send Light
        char showConsole; // show on console or nah
        int dataQtt; // how many datas to collect;
    
    public:
        // constructor 
        Scheduler(int temp_p = 3, int hum_p = 3, int pre_p = 3, int light_p = 3, char showConsole_p = 'n', int qtt_p = 3) { // default is set to 3 seconds
            m_timeT = temp_p;
            m_timeH = hum_p;
            m_timeP = pre_p;
            m_timeL = light_p;
            showConsole = showConsole_p;
            dataQtt = qtt_p;
        }

        //operator=
        Scheduler& operator=(const Scheduler& scheduler_p) {
            m_timeT = scheduler_p.m_timeT;
            m_timeH = scheduler_p.m_timeH;
            m_timeP = scheduler_p.m_timeP;
            m_timeL = scheduler_p.m_timeL;
            showConsole = scheduler_p.showConsole;
            dataQtt = scheduler_p.dataQtt;

            return *this;
        }

        void showOnConsole();
        void setInterval();
        void transmitData(); // thread for writing data and different intervals
        void dataQuantity(); // get how many loops the user wants


};
#endif