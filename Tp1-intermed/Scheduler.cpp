/**
* @author MOhana wael
* @file : Scheduler.cpp
* @date 27/09/2022
* @Description Definition classe Scheduler
*/

#include <iostream>
#include "./Scheduler.hpp"

void Scheduler::SignalServer(){
    this->sv.consoleWrite(this->h,this->l,this->p,this->t);
    //this->sv.fileWrite(this->h,this->l,this->p,this->t);
}