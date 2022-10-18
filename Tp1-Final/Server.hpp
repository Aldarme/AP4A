/**
* @author MOhana wael
* @file : Server.hpp
* @date 27/09/2022
* @Description Declaration classe Server
*/

#include <iostream>
#include <string>
#include "Sensor.hpp"
#include "./Temperature.hpp"
#include"./Light.hpp"
#include"./Pressure.hpp"
#include"./Humidity.hpp"
#ifndef Server_h
#define Server_h


class Server{

//params
    private : bool consolActivation;
    private : bool logActivation;
    

/***************CONSTRUCTORS***************/
//Default constructor
    public :  Server();
//Constructor par recopie
    public : Server(const Server&);
    
/***************OPERATORS***************/
//operator = 
   Server& operator= (const Server&);

/***************METHODS***************/
//File Write Method 
private:
template <typename T>
void fileWrite(Sensor<T>&);

//Console Write Method
private:
template <typename T>
void consoleWrite(Sensor<T> &);

//Receive Signal from scheduler
public :
template <typename T>
void receiveSignal(Sensor<T> &);


/***************DESTRUCTOR***************/
virtual ~Server();
};

#endif