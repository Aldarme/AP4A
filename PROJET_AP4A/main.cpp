#include <iostream>
#include "Scheduler.cpp"

int main(){
    Temperature T;
    Humidity H;
    Light L;
    Pression P;
    Server Ser;
    Scheduler Sch(Ser,T,H,L,P);
    
    for(int i=0;i<9;i++){
        Sch.setValue();
    }
    return 0;
}