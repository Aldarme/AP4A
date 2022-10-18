/**
 * @author Tontsa apala frank
 * @file Scheduler.hpp
 * @date 25/09/2022
 * @brief Scheduler
 */
 
 #include <windows.h>
#include <iostream>
#include <process.h>
#include <stdio.h>
#include "Scheduler.hpp"
#include "Server.hpp"
#if __WIN32               //Declaration d'entete qui permet l'utilisation de la fonction sleep
#include <Windows.h>      //pour windows et linux egalement. Cette fonction permet de faire une
#else                     //pause pour un temps precis entré en parametre defini en nanosecond
#include <unistd.h>
#endif

using namespace std;

//Constructeur par defauat
Scheduler::Scheduler() {}

//Destructeur
Scheduler::~Scheduler() {}

Server m_sev;
Temperature temp;
Light lit;
Pression pres;
Humidity humi;

DWORD WINAPI myThreadT(LPVOID lpParameter) //Thread pour la temperature.Elle sera executé toutes les 2 seconds.
{
	while(1)
	{
		Sleep(2000); //Suspension de l'execution pour 2 seconds
		m_sev.fileWrite(temp.getData(), "Temp.txt"); //appel de la methode fileWrite pour la temperature
		m_sev.consolWrite("Temp.txt"); //appel de la methode consolWrite pour la temperature
	}
	return 0;
}
DWORD WINAPI myThreadH(LPVOID lpParameter) //Thread pour l'humidit�.Elle sera executé toutes les 5 seconds.
{
	while(1)
	{
		Sleep(5000); //Suspension de l'execution pour 5 seconds
		m_sev.fileWrite(humi.getData(),"Humi.txt"); //appel de la methode fileWrite pour l'humidit�
		m_sev.consolWrite("Hum.txt");  //appel de la methode consolWrite pour l'humidit�
	}
	return 0;
}
DWORD WINAPI myThreadP(LPVOID lpParameter) //Thread pour la pression.Elle sera executé toutes les 7 seconds.
{
	while(1)
	{
		Sleep(7000); //Suspension de l'execution pour 7 seconds
		m_sev.fileWrite(pres.getData(),"Pres.txt");  //appel de la methode fileWrite pour la pression
		m_sev.consolWrite("Pres.txt");   //appel de la methode consolWrite pour la pression
	}
	return 0;
}
DWORD WINAPI myThreadL(LPVOID lpParameter) //Thread pour la lumiere. Elle sera executé toutes les 10 seconds.
{
	while(1)
	{
		Sleep(10000); //Suspension de l'execution pour 10 seconds
		m_sev.fileWrite(lit.getData(),"Lit.txt");  //appel de la fonction fileWrite pour la lumiere
		m_sev.consolWrite("Lit.txt"); //appel de la consolWrite pour la lumiere.
	}
	return 0;
}
void Scheduler::Store_data(){

	while(m_sev.m_logActivation)
	{
		//Creation d'identifiant de chaque thread
		DWORD myThreadIDT; //id thread temperature
		DWORD myThreadIDH; //id thread humidite
		DWORD myThreadIDP; //id thread pression
		DWORD myThreadIDL; //id thread lumiere

		//Creation de chaque thread avec leur fonctions respective passée en paramtre
		HANDLE myHandleT = CreateThread(0, 0, myThreadT, NULL, 0, &myThreadIDT); //creation thread temperature
		HANDLE myHandleH = CreateThread(0, 0, myThreadH, NULL, 0, &myThreadIDH); //creation thread humidite
		HANDLE myHandleP = CreateThread(0, 0, myThreadP, NULL, 0, &myThreadIDP); //creation thread pression
		HANDLE myHandleL = CreateThread(0, 0, myThreadL, NULL, 0, &myThreadIDL);  //creation thread lumiere
		char myChar = ' ';
		while(myChar != 'q') {
			myChar = getchar();
		}

		//Fermeture de chaque thread crée
		CloseHandle(myHandleL); //
		CloseHandle(myHandleP);
		CloseHandle(myHandleH);
		CloseHandle(myHandleT);
	}

}
