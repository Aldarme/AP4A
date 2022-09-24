#include <iostream>
#include "Scheduler.cpp"

int main(){
    Temperature T;
    Humidity H;
    Light L;
    Pression P;
    Server Ser;
    Scheduler Sch(Ser,T,H,L,P);
    
    Sch.setValue();
    return 0;
}