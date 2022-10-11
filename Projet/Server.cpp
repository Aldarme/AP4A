#include <iostream>
#include "Server.hpp"
#include <fstream>
using std::string;


Server::Server()
{
    this->serverNumber=1;
}

Server::~Server()
{

}

void Server::consolWrite(Sensor data)
{
    std::cout<<"Value: "<<data.value<<std::endl;
}

void Server::consolWrite(Packet data)
{
    std::cout<<"    Temperature: "<<data.temperature.value<<" C"<<std::endl;
    std::cout<<"    Pressure: "<<data.pressure.value<<" Pa"<<std::endl;
    std::cout<<"    Humidity: "<<data.humidity.value<<"%"<<std::endl;
    if (data.light.lightPresent==true)
    {
        std::cout<<"    Light: yes"<<std::endl;
    }
    else
    {
        std::cout<<"    Light: no"<<std::endl;
    }
}

void Server::fileWrite(Packet data,int cas)
{
   if (cas==1)
   {
    string filename("temperature.txt");
    std::ofstream file_out;
    file_out.open(filename, std::ios_base::app);
    file_out << data.temperature.value << ";";
   }
   if (cas==2)
   {
    string filename("pressure.txt");
    std::ofstream file_out;
    file_out.open(filename, std::ios_base::app);
    file_out << data.pressure.value << ";";
   }
   if (cas==3)
   {
    string filename("humidity.txt");
    std::ofstream file_out;
    file_out.open(filename, std::ios_base::app);
    file_out << data.humidity.value << ";";
   }
   if (cas==4)
   {
    string filename("light.txt");
    std::ofstream file_out;
    file_out.open(filename, std::ios_base::app);
    file_out << data.light.lightPresent << ";";
   }
   
    
    

    
    //TemperatureFile<<data.temperature.value<<";";
}


    

