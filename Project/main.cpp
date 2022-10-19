#include "Server.hpp"
#include "Scheduler.hpp"
#include "Sensor.hpp"
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    srand(time(0)) ;
    Scheduler sched ;
    sched.takedata();

}
