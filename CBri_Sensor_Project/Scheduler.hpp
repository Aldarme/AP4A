/**
 * @author Clément BRICHET
 * @file Scheduler.h
 * @date 23/09/2022
 * @brief This project's goal is to simulate a plane environment with its sensors and retrieve the randomly generated data from the sensors.
 * */

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Temperature.hpp"
#include "Humidity.hpp"
#include "Pressure.hpp"
#include "Light.hpp"

#include "Server.hpp"
#include <unistd.h>

class Scheduler
{
    private:
        Humidity m_hSensor;
        Temperature m_tSensor;
        Light m_lSensor;
        Pressure m_pSensor;

        Server m_serv;

        bool m_logActivated, m_consoleActivated;


    public:
        //Canonic functions
        Scheduler();
        Scheduler(const Scheduler&);
        Scheduler& operator=(const Scheduler&);
        ~Scheduler();

        /// @brief This function is the core of the project; this is where all the writing and activating happens.
        void startScheduler(void);

        /// @brief This functions allows us to activate/desactivate log writing
        void switchLogActivation(void);

        /// @brief This functions allows us to activate/desactivate console writing
        void switchConsoleActivation(void);
};

#endif //SCHEDULER_H