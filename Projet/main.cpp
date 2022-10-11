#include "Scheduler.hpp"

int main()
{
    scheduler sched;
    server serv;

    serv.chooseConsoleActivation();
    serv.chooseFileActivation();
    serv.fileReset();
    sched.loop(serv);

    return EXIT_SUCCESS;
}