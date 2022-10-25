#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

#include "Sensor.h"
#include "Scheduler.h"
#include "Server.h"

using namespace std;
using namespace this_thread;

//Each sensor has a different frequency of being called. 
//To achieve the goal of sensor time-sharing scheduling, the program has four different threads that each control a sensor. 
//Also, using synchronization of threads, different threads will run the ThFun function synchronously.

mutex mtx;
//Define a mutex class object to create a mutual exclusion lock to avoid resource competition between threads
condition_variable_any cond;
//Define a condition_variable_any class objet
//To avoid resource grabbing between threads, conditional variables are often used in conjunction with mutually exclusive locks

template <class T>
void ThFun(Scheduler<int>& sch,int i)
//Function that run in threads
//The parameters passed in are: an entity of the scheduler class and the thread (and arguably the sensor) number
{
   mtx.lock();
   //Call the mutex class member function lock() to achieve the function of "locking"
   cond.wait(mtx);
   //Call the member function wait() of the condition_variable_any class
   //Blocks the current thread and waits for the condition to hold
   switch (i)  //The number of the thread (i) matches the sensor he controls
   {
   case 0 : //Thread 0 controlling sensor 0 (Temperature)
      sch.SendData(0);
      //Scheduler is used. It will enable the corresponding sensors and transmit the data to the server
      sleep_for(chrono::seconds(1));     
      break;
   case 1 : //Thread 1 controlling sensor 1 (Humitity)
      sleep_for(chrono::seconds(1));
      sch.SendData(1);
      break;
   case 2 : //Thread 2 controlling sensor 2 (Light)
      sleep_for(chrono::seconds(2));
      sch.SendData(2);
      break;
   case 3 : //Thread 3 controlling sensor 3 (Pression)
      sleep_for(chrono::seconds(3));
      sch.SendData(3);
      break;
   default:
      cout << "Error!" <<endl;
      break;
   }
   //In terms of time progression, we set the scheduling frequency of the sensors to collect temperature data every second, 
   //humidity data every 1 second, brightness data every 2 seconds, and pressure data every 3 seconds
   mtx.unlock();
   //Call the mutex class member function unlock() to achieve the function of "unlocking"
}

void go(){
   cond.notify_all();
   //Call the member function notify_all() of the condition_variable_any class
   //Notify all threads that the condition is met
}


int main(){
   Scheduler<int> sch;//Instance of class Scheduler
   thread Th_t(ThFun<int>,ref(sch),0);
   thread Th_h(ThFun<int>,ref(sch),1);
   thread Th_l(ThFun<int>,ref(sch),2);
   thread Th_p(ThFun<int>,ref(sch),3);
   //Create four threads and start running the ThFun function at the same time
   thread goThread(go);
   //Create a thread and start running the go function at the same time
   goThread.join(); 
   Th_t.join();
   Th_h.join();
   Th_l.join();
   Th_p.join();
   //Before each thread object is destroyed by a destructor call
   //the join() function is called to make the main thread wait for the child threads to finish executing.
   return 0;
}