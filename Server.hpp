///
///@author Gaspard Rochu
///@file Server.hpp
///@date 04/10/2022
///@brief Class where the datas are supposed to be send (here they are juste displayed on the console). We can imagine writing them in a text file in the future.
///

#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <Windows.h>


class Server 
{
public:
    static void displayfloat(float a); //Displaying the float value into the console
    static void displayint(int a); //Displaying the int value into the console
    static void displaybool(bool a); //Displaying the bool value into the console


};

#endif //SERVER_HPP