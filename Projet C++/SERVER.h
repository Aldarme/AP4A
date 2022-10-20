/**
 * @author YUHUIFEI
 * @file SERVER.h
 * @date 15/10/2022
 * @brief La classe Server Classe permettant de recevoir les donn¨¦es des capteurs et de les ¨¦crire dans le journal.
 */
#ifndef SERVER_HPP
#define SERVER_HPP
#include"SENSOR.h"
#include "PRESSION.h"
#include "HUMIDITY.h"
#include "LIGHT.h"
#include "TEMPERATURE.h"

using namespace std;

class Server
{
public:
	Server();
	Server(Server& s);
	~Server();
	template <class T> friend class Sensor;
	template <class T> friend class Temperature;
	template <class T> friend class Humidity;
	template <class T> friend class Pression;
	template <class T> friend class Light;
};




#endif//SERVER.H