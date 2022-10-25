/**
* @author SZATKOWSKI Maxime
* @file Server.hpp
* @date 15/09/2022
* @brief Fichier header contenant la d�finition des m�thodes de la classe Server
*/

#ifndef __Server_H__
#define __Server_H__

#include "Scheduler.hpp"
#include "Packet.hpp"
#include <iostream>
#include <fstream>

/**
* @class Server
* @brief permet de recevoir les donn�es des capteurs par Scheduler et de les afficher dans la console et/ou les stocker dans le fichier de log
*/

class Server {

private:

	//Definition des attributs 
	bool consoleActivation;
	bool logActivation;

public:

//Definition de la forme canonique de Coplien

	//constructeur par d�faut
	Server();

	//constructeur par recopie
	Server(const Server& s);

	//destructeur par d�faut
	~Server() {};

	//op�rateur d'affectation
	Server& operator=(const Server& s);

	/**
	* @brief Permet d'�crire les valeurs des capteurs dans un fichier.txt
	* @return void
	* @param une cha�ne de caract�re et un Packet
	*/
	void fileWrite(const Packet);

	/**
	* @brief Permet d'�crire les valeurs des capteurs dans la console
	* @return void
	* @param Packet
	*/
	void consoleWrite(const Packet);

	/**
	* @brief Permet la saisie par l'utilisateur de l'activation ou non de l'affichage dans la console
	* @return type r�f�rence sur Server
	* @param void
	*/
	Server& setConsole();

	/**
	* @brief permet la saisie par l'utilisateur de l'�criture ou non de dans la fichier de log
	* @return type r�f�rence sur Server
	* @param void
	*/
	Server& setLogActivation();

	/**
	* @brief permet de r�cup�rer la valeur de consoleActivation
	* @return bool
	* @param void
	*/
	bool getConsoleActiv();

	/**
	* @brief permet de r�cup�rer la valeur de logActivation
	* @return bool
	* @param void
	*/
	bool getLogActiv();
};

#endif  // Sensor_H
