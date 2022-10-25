/*
 *  @Author: NDJAMBA BATOMEN GABRIELLA
 *  @file Humidity.cpp
 *  @Created on: 9 oct. 2022
 *  @Description: Implementation file of scheduler which is responsible of receiving the data collected either to 
 * read or store it.
 */


//including the headers that help us use threads and sleep function
#include <process.h>
#include <stdio.h>
#include "Scheduler.hpp"
#include <Windows.h>      
#include <unistd.h>


using namespace std;


void Scheduler::getinfo(){

	while(sev.m_logactive)
	{
		//creating an id for each thread thread
		DWORD myThreadT; //id thread temperature
		DWORD myThreadL; //id thread lumiere
		DWORD myThreadH; //id thread humidite
		DWORD myThreadP; //id thread pression

		//creating each thread with thier respectif parameter
		HANDLE myHandleT = CreateThread(0, 0, myThreadT, NULL, 0, &myThreadT); //creating thread temperature
		HANDLE myHandleH = CreateThread(0, 0, myThreadH, NULL, 0, &myThreadH); //creating thread humidity
		HANDLE myHandleP = CreateThread(0, 0, myThreadP, NULL, 0, &myThreadP); //creating thread pressure
		HANDLE myHandleL = CreateThread(0, 0, myThreadL, NULL, 0, &myThreadL);  //creating thread light
		//char myChar = ' ';
		while(myChar != 't') 
		{
			myChar = getchar();
		}

		//closing each thread
		CloseHandle(myHandleL); //
		CloseHandle(myHandleP);
		CloseHandle(myHandleH);
		CloseHandle(myHandleT);
	}


DWORD WINAPI myThreadT(LPVOID lpParameter) //Thread for temperature
{
	while(1)
	{
		Sleep(5000); //suspending the execution for 5 seconds
		sev.fileWrite(temp.getData(), "Temp.txt"); //calling filewrite for temperature
		sev.consolWrite("Temp.txt"); //calling consolwrite for temperature
	}
	return 0;
}
DWORD WINAPI myThreadH(LPVOID lpParameter) //Thread for humidity
{
	while(1)
	{
		Sleep(5000); //suspending the execution for 5 seconds
		sev.fileWrite(hum.getData(),"Hum.txt"); //calling filewrite for temperature
		sev.consolWrite("Hum.txt");  //calling consolwrite for temperature
	}
	return 0;
}
DWORD WINAPI myThreadP(LPVOID lpParameter) //Thread for pressure
{
	while(1)
	{		
		Sleep(7000); //suspending the execution for 7 seconds
		sev.fileWrite(pres.getData(),"Pres.txt");  //calling filewrite for pressure
		sev.consolWrite("Pres.txt");   //calling  consolwrite for pressure
	}
	return 0;
}
DWORD WINAPI myThreadL(LPVOID lpParameter) //Thread for light
{
	while(1)
	{
		Sleep(2000); //suspending the execution for 2 seconds
		sev.fileWrite(lig.getData(),"Lig.txt");  //calling filewrite for light
		sev.consolWrite("Lig.txt"); //calling consolwrite for light
	}
	return 0;
}


}
