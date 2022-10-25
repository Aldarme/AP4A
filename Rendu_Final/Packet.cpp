/**
 * @author BIN ABDUL SHUKOR Muhammad Ariff
 * @file Packet.cpp
 * @date 25/10/2022
 * @brief
 */

#include "Packet.hpp"
#include <iostream>


void Packet::setPacket(Temperature temp, Pressure press,Humidity humid, Light lumiere){
    this->temperature=temp;
    this->pressure=press;
    this->humidity=humid;
    this->light=lumiere;
}

void Packet::getInfo(){

    std::cout<<"Temperature : "<<this->temperature.value<<std::endl;
    std::cout<<"Pressure : "<<this->pressure.value<<std::endl;
    std::cout<<"Humidity : "<<this->humidity.value<<std::endl;
    std::cout<<"Light : "<<this->light.value<<std::endl;
}