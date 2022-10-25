/*
 *  @Author: NDJAMBA BATOMEN GABRIELLA
 *  @file Server.cpp
 *  @Created on: 9 oct. 2022
 *  @Description: implementation file of class server 
 */


#include <fstream>
#include <windows.h>
#include "Server.hpp"


Server::Server(): m_consolactive(false),m_logactive(true) {}
Server::Server(const Server &s) 
{
	this->m_consolactive=s.m_consolactive;
	this->m_logactive=s.m_logactive;
}
Server::Server(bool cons, bool lo): m_consolactive(cons),m_logactive(lo){}
Server& Server::operator=(Server &&s) 
{
      m_consolactive=s.m_consolactive;
      m_logactive=s.m_logactive;
	  return *this;
}
//definition of the function that allows us to visualise the data stored in the different log files
void Server::consolWrite(std::string f)
{
	std::ifstream file(f); //opening the file in reading mode
	if(file){
		while(getline(file, li))
		{
			cout<<f<<" : "<<li<<endl;
		}
	}

}
//definition of the function that allows us to store the data in the different log files
void Server::fileWrite(T t, std::string f)
{
	std::ofstream file(f.c_str(), std::ios::app);//opening the file in writing mode
	if(file){
		file<<t<<" | ";
	}

}
//the files are closed automatically
