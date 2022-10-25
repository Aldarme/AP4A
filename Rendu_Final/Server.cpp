/**
 * @author BIN ABDUL SHUKOR Muhammad Ariff
 * @file Server.cpp
 * @date 25/10/2022
 * @brief
 */

#include <iostream>
#include "Server.hpp"
#include <fstream>
#include "Packet.hpp"
using std::string;


Server::Server()
{
    this->serverNumber=1;
}





void Server::consolWrite(Temperature tp){std::cout<<"Temperature : "<<tp.value<<" C"<<std::endl;}\
void Server::consolWrite(Pressure prs){std::cout<<"Pressure : "<<prs.value<<" Pa"<<std::endl;}
void Server::consolWrite(Humidity hmd){std::cout<<"Humidity : "<<hmd.value<<" %"<<std::endl;}
void Server::consolWrite(Light lgt){std::cout<<"Light : "<<lgt.value<<std::endl;}



void Server::fileWrite(Temperature tmp)
{
    string filename("temperature.txt");
    std::ofstream file_out;
    file_out.open(filename,std::ios_base::app);
    file_out << tmp.value << ";";
}

void Server::fileWrite(Pressure tmp)
{
    string filename("pressure.txt");
    std::ofstream file_out;
    file_out.open(filename,std::ios_base::app);
    file_out << tmp.value << ";";
}

void Server::fileWrite(Humidity tmp)
{
    string filename("humidity.txt");
    std::ofstream file_out;
    file_out.open(filename,std::ios_base::app);
    file_out << tmp.value << ";";
}

void Server::fileWrite(Light tmp)
{
    string filename("light.txt");
    std::ofstream file_out;
    file_out.open(filename,std::ios_base::app);
    file_out << tmp.value << ";";
}


void Server::clearDataInFile()
{
    std::ofstream file("temperature.txt");
    file<<"The data for temperature below are in Celcius (C) \n\n";
    std::ofstream file2("pressure.txt");
    file2<<"The data for pressure below are in Pascal (Pa)\n\n";
    std::ofstream file3("humidity.txt");
    file3<<"The data for humidity below are in Percentage (%)\n\n";
    std::ofstream file4("light.txt");
    file4<<"The data below represent the present of light.\n 1 when there is light in the cabin and zero if there is no light.\n\n";
}

