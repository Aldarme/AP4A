/**
 * @author Tontsa apala frank
 * @file Main.cpp
 * @date 01/10/2022
 * @brief main simulation file 
 */

#include "Scheduler.hpp"
#include <iostream>


using namespace std;

int main(){

	//Message d'acceuil et orientation
	cout<< "Bienvenue sur votre serveur !!"<<endl;
	cout<< "Veuillez consulter Les données de vos capteurs qui sont generés a des frequences distinctes "<<endl;


	//Instanciation de la classe scheduler
	Scheduler m_sc;
	m_sc.Store_data();//Appel de la fonction Store_data

}

