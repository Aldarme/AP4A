/*      author:TRABOULSI Rawan
        *SERVER
        *Créé le 29/09/2020          */


#include "Server.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <Windows.h>

Server::Server():m_consoleActivation(false),m_logActvation(false){
        //constructeur par defaut
}

Server::Server(bool consoleActivation_p,bool logActivation_p):m_consoleActivation(consoleActivation_p),m_logActvation(logActivation_p){
        //construvteur par paramètres
}

Server::Server(const Server & S){
        m_consoleActivation=S.m_consoleActivation;
        m_logActvation=S.m_logActvation;
}

Server &Server::operator=(const Server & S){
        m_consoleActivation=S.m_consoleActivation;
        m_logActvation=S.m_logActvation;
        return *this;

}
bool Server::getconsoleActivation(){
        return m_consoleActivation;
}
bool Server::getlogActivation(){
        return m_logActvation;
}

void Server:: setconsoleAvtivation(bool consolActivation_p){
 m_consoleActivation=consolActivation_p;

}
void Server::setlogActivation(bool logActivation_p){
        m_logActvation=logActivation_p;
}
//les fcts consoleWrite et fileWrite

void Server:: consoleWrite(int pressure_p,int humidity_p,int brightness_p,int temp_p){
        cout<<"La pression au bout d l'avion est de :"<<pressure_p<<"Pascal \n"<<endl;
        cout<<"L'humidité est d'une valeur de :"<<humidity_p<<"%\n"<<endl;
        cout<<"Il fait :"<<temp_p<<"dans l'avion\n"<<endl;
        cout<<"Luminosité de l'écosystème:\n"<<brightness_p<<endl;
}

void Server::fileWrite(int pressure_p,int humidity_p,int brightness_p,int temp_p){
       //le temps avec la date du jour de l'écriture du fichier.txt
        time_t now;
	time(&now);
        struct tm *local = localtime(&now);
        int hour = local->tm_hour;
	int minute = local->tm_min;
	int seconde = local->tm_sec;
	int day = local->tm_mday;
	int month = local->tm_mon + 1;
	int year = local->tm_year + 1900;

        //l'écriture du output dans un fichier.txt en utilisant ofstream
        string const Humidity("C:/Users/Rawan/fichiers_AP4A/Humidity.txt");
        ofstream txt1(Humidity.c_str(),ios::app);
        if(txt1){
                txt1<<"l'humidité dans l'avion est de:"<<humidity_p<<"%"<<"  le "<<day<<"/"<<month<<"/"<<year <<" à " << hour <<":"<<minute<<":"<<seconde<<"\n \n";
        }

        string const Light("C:/Users/Rawan/fichiers_AP4A/Light.txt");
        ofstream txt2(Light.c_str(),ios::app);
        if(txt2){
                txt2<<"Il ya :"<<brightness_p<<"de luminosité dans l'avion"<<"  le "<<day<<"/"<<month<<"/"<<year <<" à " << hour <<":"<<minute<<":"<<seconde<<"\n \n";
        }

        string const Pressure("C:/Users/Rawan/fichiers_AP4A/Pressure.txt");
        ofstream txt3(Pressure.c_str(),ios::app);
        if(txt3){
                txt3<<"La pression est de:"<<pressure_p<<"Pascal"<<"  le "<<day<<"/"<<month<<"/"<<year <<" à " << hour <<":"<<minute<<":"<<seconde<<"\n\n";
        }

        string const Temperature("C:/Users/Rawan/fichiers_AP4A/Temperature.txt");
        ofstream txt4(Temperature.c_str(),ios::app);
        if(txt4){
                txt4<<"La température est :"<<temp_p<<" Celsius"<<"  le "<<day<<"/"<<month<<"/"<<year <<" à " << hour <<":"<<minute<<":"<<seconde<<"\n \n";
        }  

}

void Server :: dataRcv(int pressure_p,int humidity_p,int brightness_p,int temp_p,Server &server_p){
       if (server_p.m_logActvation==true){
        consoleWrite(pressure_p,humidity_p,brightness_p,temp_p);
        fileWrite(pressure_p,humidity_p,brightness_p,temp_p);
       }
       else{
        consoleWrite(pressure_p,humidity_p,brightness_p,temp_p);
       }

}


