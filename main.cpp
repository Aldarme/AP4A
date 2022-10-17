
#include "Scheduler.hpp"
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    srand (time(NULL));
    Scheduler scheduler;
    scheduler.start(); //lance le scheduler

    return 0;
};
