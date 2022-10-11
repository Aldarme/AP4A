/**
* @author SZATKOWSKI Maxime
* @file Server.hpp
* @date 15/09/2022
* @brief Fichier header contenant la définition des méthodes de la classe Server
*/

#ifndef __Server_H__
#define __Server_H__

#include "Scheduler.hpp"
#include "Packet.hpp"
#include <iostream>
#include <fstream>

/**
* @class Server
* @brief
*/

class Server {

private:

	//Packet m_packet;	à envoyer directement ? via packet.m_temp...

	//Descriptif des attributs 
	bool consoleActivation;
	bool logActivation;

public:

//Definition de la forme canonique de Coplien

	//constructeur par défaut
	Server();

	//constructeur par recopie
	Server(const Server& s);

	//destructeur par défaut
	~Server() {};

	//opérateur d'affectation
	Server& operator=(const Server& s);

	/**
	* @brief Permet d'écrire les valeurs des capteurs dans un fichier.txt
	* @return void
	* @param une chaîne de caractère et un Packet
	*/
	void fileWrite(const std::string, const Packet);

	/**
	* @brief Permet d'écrire les valeurs des capteurs dans la console
	* @return void
	* @param Packet
	*/
	void consoleWrite(const Packet);

	/**
	* @brief
	* @return void 
	* @param void
	*/
	Server& setConsole();

	/**
	* @brief
	* @return void
	* @param void
	*/
	Server& setLogActivation();

	/**
	* @brief
	* @return
	* @param
	*/
	bool getConsoleActiv();

	/**
	* @brief
	* @return void
	* @param void
	*/
	bool getLogActiv();
};

#endif  // Sensor_H
