#include "Scheduler.hpp"
#include <windows.h>

void scheduler(int seconds)
{
    Sleep(seconds*1000);
}