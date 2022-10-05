/**
 * @author Clément BRICHET
 * @file Scheduler.h
 * @date 23/09/2022
 * @brief 
 * */

#ifndef SCHEDULER_H
#define SCHEDULER_H

class Scheduler
{
    private:
    public:
        //Canonic functions
        Scheduler();
        Scheduler(const Scheduler&);
        Scheduler& operator=(const Scheduler&);
        ~Scheduler();
};

#endif //SCHEDULER_H