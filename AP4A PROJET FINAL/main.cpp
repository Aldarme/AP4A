/*
 *  @Author: NDJAMBA BATOMEN GABRIELLA
 *  @file Humidity.cpp
 *  @Created on: 9 oct. 2022
 *  @Description: Implementation file main where we call our funtion getinfo with an object 
 * responsible of executing this function
 */

#include<iostream>
#include "Scheduler.hpp"
using namespace std;



int main(){

	//welcome text
	cout<< "Welcome to this server !!"<<endl;
	
	//Instanciation of class scheduler
	Scheduler m_sc;
	m_sc.getinfo();//function gt info is called

    return 0;
}

