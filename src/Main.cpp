#include "Scheduler.h"
#include <iostream>
#include <thread>

int main()
{
    Scheduler s;

    s.ask();
    s.launchThreads();

    return 0;
}
