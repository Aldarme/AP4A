#include "Server.hpp"
#include "Sensor.hpp"
#include "Scheduler.hpp"

int main(){
    scheduler sched;
    server serv;

    serv.fileReset();
    for(int i = 0; i < 10; i++)
    {
        sched.getData();
        serv.getData(sched);
        serv.consolWrite();
        serv.fileWrite();
        sched.timer();
    }

    return EXIT_SUCCESS;
}