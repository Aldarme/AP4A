#include "Scheduler.h"
#include <iostream>

int main() {
    Scheduler scheduler;
    int count = 0;
    while(count < 7){
        scheduler.wait(4.);
        count++;
    }
    
}
