/**
* @author MOhana wael
* @file : Scheduler.cpp
* @date 27/09/2022
* @Description Definition classe Scheduler
*/

#include <iostream>
#include "Scheduler.hpp"
#include <thread>
#include <windows.h>

  /***************CONSTRUCTORS***************/
  //Default constructor
  Scheduler::Scheduler(){};
  //Constructor par recopie
  Scheduler::Scheduler(const Scheduler& autre){
    this->t = autre.t;
    this->l =autre.l;
    this->h = autre.h;
    this->p = autre.p;
    this->sv = autre.sv;
};

/***************METHODS***************/ 

void Scheduler::SignalServer(){
   //i had lots of compiling issues when i tried thread implementation
   // after several times i couldn't get it to work properly i tried to install many different compiler unfortunately that didn't help i mainly had issues with thread library 
   //so i wrote this code in order to simulate threads behaviour where, each x miliseconds the Scheduler sends a signal to the Server in order to get a read from Sensors
while(1){
   for(int i=0;i<10000000;i++){
    if((i%100000 )== 0)this->sv.receiveSignal(this->l);
    if((i%150000 )== 0)this->sv.receiveSignal(this->h);
    if((i%175000 )== 0)this->sv.receiveSignal(this->p);
    if((i%200000 )== 0)this->sv.receiveSignal(this->t);
   }
}
/*
//The following code would be implemented if we were to use threads

///////----------------------------------------------------------------//////
//In Scheduler.hpp

private : void Scheduler::T_thread_function();
          void Scheduler::L_thread_function();
          void Scheduler::P_thread_function();
          void Scheduler::H_thread_function();

///////----------------------------------------------------------------//////

//In scheduler.cpp scope :
#include <thread>
#include <windows.h> // similar to <unistd>
void Scheduler::T_thread_function(){
  while(1){
    Sleep(1); //wait 1 second
    this->sv.SignalServer(this->t);
  }
}
void Scheduler::L_thread_function(){
  while(1){
    Sleep(2); //wait 2 seconds
    this->sv.SignalServer(this->t);
  }
}
void Scheduler::P_thread_function(){
  while(1){
    Sleep(3); //wait 3 seconds
    this->sv.SignalServer(this->t);
  }
}
void Scheduler::H_thread_function(){
  while(1){
    Sleep(4); //wait 4 seconds
    this->sv.SignalServer(this->t);
  }
}
//There will be a unique thread for each sensor, in order to get a read at different periods(T)
std::thread T_thread(&Scheduler::T_thread_function());
std::thread H_thread(&Scheduler::H_thread_function());
std::thread L_thread(&Scheduler::L_thread_function());
std::thread P_thread(&Scheduler::P_thread_function());


//Afin de Synchroniser tous les threads avec main Thread
T_thread.join();
H_thread.join();
L_thread.join();
P_thread.join();

*/
}

Scheduler::~Scheduler(){};