/**
 * @author Tontsa apala frank
 * @file Server.cpp
 * @date 25/09/2022
 * @brief Server
 */
#include "Server.hpp"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>

using namespace std;



//Constructeur par defaut

Server::Server(): m_consolActivation(false),m_logActivation(true) {}

//Constructeur de recopie
Server::Server(const Server &s) {
	this->m_consolActivation=s.m_consolActivation;
	this->m_logActivation=s.m_logActivation;
}

//Un autre Constructeur
Server::Server(bool cons, bool lo): m_consolActivation(cons),m_logActivation(lo){}

//Destructeur
Server::~Server() {
}

//Declaration d'un flux permettant d'ecrire dans le fichier temp

//Operateur d'affectation
Server& Server::operator=(Server &&s) {
      m_consolActivation=s.m_consolActivation;
      m_logActivation=s.m_logActivation;
	  return *this;
}
/*
 * Definition de la methode qui permet de visualiser les donnees stock�es
 * dans des fichiers log differents
 */
void Server::consolWrite(std::string tr){
	ifstream monFlux(tr); //Ouverture du fichier en lecture
	if(monFlux){
		string ligne;
		while(getline(monFlux, ligne)){
			cout<<tr<<" : "<<ligne<<endl;
		}
	}

}
/* Dans les deux fonctions (fileWrite et consolWrite) , il n'est pas neccessaire de refermer les fichiers
 *  car elle est fermé automatiquement lorsqu'on sort du bloc ou le flux est declaré.
 *  Toutefois, on peut le fermer en utilisant le code monFlux.close();
*/

