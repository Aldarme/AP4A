/*
 *  @Author: NDJAMBA BATOMEN GABRIELLA
 *  @file Humidity.cpp
 *  @Created on: 9 oct. 2022
 *  @Description: header file of server that contains  the attibutes and methods
 * used to either store or read the data
 */
//#ifndef def_Server
//#define def_Server
//#include "Humidity.hpp"
//#include "Temperature.hpp"
//#include "Light.hpp"
//#include "Pressure.hpp"
#include <string>

//#include "Scheduler.hpp"


class Server
{
    friend class Scheduler;
    private:
	bool m_consolactive, m_logactive;
	std::string li;
    public:
	Server();
	Server(const Server &s);
	Server(bool cons, bool lo);
	virtual ~Server(){}
	Server& operator=(Server &s);

	//Redefinition of the different inherited funtions 
	template <class T>
	void fileWrite(T t, std::string f);//the first parameter will refer to temperature,light,humidity or pressure and the second parameter is the file where they will be stored
	void consolWrite(std::string f);//takes into parameter the file where the data is stored

};




//#endif