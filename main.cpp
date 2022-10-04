
#include "Scheduler.hpp"
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    srand ((unsigned int)(time(nullptr)));
    Scheduler scheduler;
    scheduler.start();

    return 0;
};
