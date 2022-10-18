#include <iostream>
#include "Scheduler.hpp"


int main()
{
    /* initialize random seed: */
    srand ((unsigned int)(time(nullptr)));

    Scheduler scheduler;
    scheduler.run();    /*on lance le scheduler*/
    return 0;
}
