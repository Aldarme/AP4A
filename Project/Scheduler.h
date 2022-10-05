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
        int m_second; // time interval to send datas
    
    public:
        // constructor 
        Scheduler(int second_p = 3) { // default is set to 3 seconds
            m_second = second_p;
        }

        void transmitData();


};
#endif