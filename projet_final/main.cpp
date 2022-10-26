/**
 * @author lois ROGER
 * @file main.hpp
 * @date 05/09/2022
 * @brief appplication du programme
*/


#include "Scheduler.hpp"
#include<iostream>



int main() 
{
    Scheduler scheduler;
    int temps = 0;
    std::cout<<"combien de secondes doit durer la simulation ?"<<std::endl;
    std::cin>>temps;
    std::cin.ignore();
    scheduler.ecriture(temps);
    return 0;
}