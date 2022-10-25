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
* @brief permet de recevoir les données des capteurs par Scheduler et de les afficher dans la console et/ou les stocker dans le fichier de log
*/

class Server {

private:

	//Definition des attributs 
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
	void fileWrite(const Packet);

	/**
	* @brief Permet d'écrire les valeurs des capteurs dans la console
	* @return void
	* @param Packet
	*/
	void consoleWrite(const Packet);

	/**
	* @brief Permet la saisie par l'utilisateur de l'activation ou non de l'affichage dans la console
	* @return type référence sur Server
	* @param void
	*/
	Server& setConsole();

	/**
	* @brief permet la saisie par l'utilisateur de l'écriture ou non de dans la fichier de log
	* @return type référence sur Server
	* @param void
	*/
	Server& setLogActivation();

	/**
	* @brief permet de récupérer la valeur de consoleActivation
	* @return bool
	* @param void
	*/
	bool getConsoleActiv();

	/**
	* @brief permet de récupérer la valeur de logActivation
	* @return bool
	* @param void
	*/
	bool getLogActiv();
};

#endif  // Sensor_H
