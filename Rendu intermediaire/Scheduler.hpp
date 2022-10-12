
#ifndef Scheduler_hpp
#define Scheduler_hpp
#include<string>
#include "AllSensor.hpp"

#include "Paquet.hpp"

class Scheduler
{
    public : 
        Scheduler();
        Scheduler(Temperature T1, Humidite H1, Pression PR1, Luminosite L1);
        void StartScheduler();
        // Paquet GetAll();
        
    private:
        Temperature T1;
        Humidite H1;
        Pression PR1;
        Luminosite L1;

};



#endif /* Scheduler_hpp */
