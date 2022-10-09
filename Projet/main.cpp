#include "Server.hpp"
#include "Sensor.hpp"
#include "Scheduler.hpp"

int main(){
    scheduler sched;
    server serv;

    for(int i = 0; i < 10; i++)
    {
        sched.getData();
        serv.getData(sched);
        serv.consolWrite();
        sched.timer();
    }

    return EXIT_SUCCESS;
}