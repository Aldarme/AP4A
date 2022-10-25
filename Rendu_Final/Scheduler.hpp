/**
 * @author BIN ABDUL SHUKOR Muhammad Ariff
 * @file Server.hpp\
 * @date 25/10/2022
 * @brief
 */

//Define guards
#ifndef SCHEDULER_H
#define SCHEDULER_H

class Scheduler
{
private:
    int sec_temp,sec_press,sec_humid,sec_light, nb_de_tourne,visualize,log;

public:
    // Definition de la forme canonique
    Scheduler(){};
    Scheduler(int timeTemp, int timePressure, int timeHumidity, int timeLight, int nb_de_tourne,int visualize,int log);
    ~Scheduler(){};
    void theScheduler();
};

#endif //SCHEDULER_H