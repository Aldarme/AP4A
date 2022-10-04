/**
 * @author Cameron ROCHEBILLARD
 * @file main.cpp
 * @date 4/10/2022
 * @brief est le code principal du program 
 */

 //
 //Define guards 
 #ifndef MAIN_H
 #define MAIN_H

 #include <Scheduler.hpp>

int main(){
    Scheduler Sch;
    Sch.scheduler();
    return 0;
}

 #endif //MAIN_H