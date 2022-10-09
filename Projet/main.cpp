#include "Scheduler.hpp"

int main(){
    scheduler sched;
    server serv;

    serv.fileReset();
    while(1)
    {
        sched.getData();
        sched.transferData(serv);
        serv.consolWrite();
        serv.fileWrite();
        sched.timer();
    }

    return EXIT_SUCCESS;
}