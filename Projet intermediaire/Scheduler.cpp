/**
 * @author Tontsa apala frank
 * @file Scheduler.hpp
 * @date 25/09/2022
 * @brief Scheduler
 */


#include <iostream>
#include "Scheduler.hpp"

void Scheduler::dataServer(){
    this->sv.consoleWrite(this->H,this->L,this->P,this->T); 
    
    this->sv.fileWrite(this->H,this->L,this->P,this->T); 
}
