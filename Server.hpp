///
///@author Gaspard Rochu
///@file Server.hpp
///@date 04/10/2022
///@brief Class where the datas are supposed to be send (here they are juste displayed on the console). We can imagine writing them in a text file in the future.
///

#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <vector>

class Server 
{
public:
    static void displayValue(std::vector<float> a); //Displaying the values into the console

};

#endif //SERVER_HPP