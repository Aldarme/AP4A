#include <iostream>
#include "Server.hpp"

static void Server::displayValue(std::vector<float> param_array)
{
    std::cout<<"Temperature :"<<param_array.at(0)<<"\n"; //array.at(0) is the same as array[0] 
    std::cout<<"Humidity :"<<param_array.at(1)<<"\n";
    std::cout<<"Light :"<<param_array.at(2)<<"\n";
    std::cout<<"Pression :"<<param_array.at(3)<<"\n";
}; //Use the command std::cout to print the value into the console
