#include "Packet.hpp"
#include <iostream>

Packet::Packet(){
    this->temp=0;
    this->press=0;
    this->humid=0;
    this->lumiere=true;
}

Packet::Packet(float temp, float press,float humid, bool lumiere){
    this->temp=temp;
    this->press=press;
    this->humid=humid;
    this->lumiere=lumiere;
}

Packet::Packet(Temperature temp, Pressure press,Humidity humid, Light lumiere){
    this->temperature=temp;
    this->pressure=press;
    this->humidity=humid;
    this->light=lumiere;
}

Packet::~Packet(){

}

//method

void Packet::setPacket(Temperature temp, Pressure press,Humidity humid, Light lumiere){
    this->temperature=temp;
    this->pressure=press;
    this->humidity=humid;
    this->light=lumiere;
}

void Packet::getInfo(){

    std::cout<<"temperature : "<<this->temp<<std::endl;
    std::cout<<"humidity : "<<this->humid<<std::endl;
    std::cout<<"pressure: "<<this->press<<std::endl;
    if(this->lumiere==true){
        std::cout<<"light : yes "<<std::endl;
    }
    else{
        std::cout<<"light : no "<<std::endl;
    }
}