/**
 * @author Tontsa apala frank
 * @file Server.hpp
 * @date 25/09/2022
 * @brief Server
 */

#ifndef SERVER_H_
#define SERVER_H_
#include "Temperature.hpp"
#include <string>
#include <fstream>

class Server {
friend class Scheduler;
private:
	bool m_consolActivation, m_logActivation;
public:
	Server();
	Server(const Server &s);
	Server(bool cons, bool lo);
	virtual ~Server();
	Server& operator=(Server &&s);

	//Redefinition des methodes herites
	/*
	 * Pour pouvoir utiliser la methode fileWrite pour les
	 *  differents capteurs, il sera defini en template.
	 */
	template <class T>
	void fileWrite(T t, std::string tr);//Elle prend deux parametre: la premiere qui est la donn�e du capteur
										//et le deuxieme qui est le fichier dans lequel la donn�e sera stock�
	void consolWrite(std::string tr);//Prend en parametre le fichier o� les donn�es ont et�es stock�es

};

/*
 * Definition de la methode fileWrite. Elle permet de stocker les donnees dans les fichiers logs.
 * Pour se faire, nous allons inclure la bibliotecque fstream dans l'entete pour manipuler
 * ces fichiers
 */

template <class T>
void Server::fileWrite(T t, std::string tr)
{
	std::ofstream monFlux(tr.c_str(), std::ios::app);//Ouverture du fichier en ecriture et enregistrement en fin de ligne.
	if(monFlux){
		monFlux<<t<<" | ";
	}

}

#endif /* SERVER_H_ */
