/**
 * @author Thibaud Leclere <thibaud.leclere@utbm.fr>
 * @file main.cpp
 * @date 28/09/2022
 * @brief Point d'entrée de l'application
 */

#include "Scheduler.hpp"

int main(void)
{
    Scheduler scheduler;

    scheduler.awaitSensors();

    return 0;
}