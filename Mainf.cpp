/*TP AP4A:PROJET :RENDU INTERMEDIAIRE
AUTHOR:TRABOULSI Rawan
Créé le 01/10/2022
*************Fichier main de notre écosystème avion(ce que l'utilisateur va choisir
 par exemple le temps de simulation,écriture dans un fichier,ou bien affichage
  seulement des données sur la console )*****************
*/

#define WIN32_LEAN_AND_MEAN 
#include <iostream>
using namespace std;
using std::cout;
using std::cin;

#include <cstdlib>
#include <fstream>
#include <random>
#include <direct.h>//pour créer un dossier pour les fichiers texte sur n'importe quel ordinateur


#include "Humidity.hpp"
#include "Humidity.cpp"
#include "Brightness.hpp"
#include"Brightness.cpp"
#include "Pressure.hpp"
#include"Pressure.cpp"
#include "Scheduler.hpp"
#include"Scheduler.cpp"
#include "Sensor.hpp"
#include "Server.hpp"
#include"Server.cpp"
#include "Temperature.hpp"
#include"Temperature.cpp"


int main(){
    Server Ser1;
    int userchoice=0;

    cout<<"Hello et bienvenue sur notre platforme de Moniteur Environnement Intérieur de notre avion en vol.\n"<<endl;
    cout<<"******Que souhaitez vous faire?******\n"<<endl;
    cout<<"1-Afficher les données inetrne de notre avion et les écrire dans des fichiers .txt\n 2-Afficher seulement les données inetrnes de notre avion de vol\n 3-QUITTER la platforme\n "<<endl;
    //cout<<"*************************************************************************************"<<endl;

    //scanf("%d",&userchoice);
    cin >> userchoice; 
    cin.ignore();

    while((userchoice!=1) && (userchoice!=2) && (userchoice!=3))
    {
        cout<<"Le choix que vous avez effectuer est invalide! Veuillez insérrez seulemnt 1 ou 2 ou 3.\n"<<endl;
    }
    if((userchoice)==3){
        exit(0);//quitter le programme
    }
    if(userchoice==1){
        std::cout<<"En activant l'écriture des fichiers, un dossier nommé C:/FichiersAP4A sera créé sur votre ordinateur \n"<<std::endl;
        _mkdir("C:\\FichiersAP4A");
        Ser1.setconsoleAvtivation(true);
        Ser1.setlogActivation(true);
    }else{
        Ser1.setconsoleAvtivation(true);
        Ser1.setlogActivation(true);
    }

    int time_temperature,time_pressure,time_brightness,time_humidity,time_total=0;
    cout<<"Saisir la durée de l'affichage des capteurs ,c'est la durée totale du programme:"<<endl;
    cout<<"Saisir le temps d'intervalle pour la température:"<<endl;
    cin>>time_temperature;
    cout<<"Saisir le temps d'intervalle pour la pression:"<<endl;
    cin>>time_pressure;
    cout<<"Saisir le temps d'intervalle pour l'humidité:"<<endl;
    cin>>time_humidity;
    cout<<"Saisir le temps d'intervalle pour la luminosité:"<<endl;
    cin>>time_brightness;

    
    Scheduler Sch1;
    Sch1.transmetDATA(Ser1,time_total,time_temperature,time_pressure,time_humidity,time_brightness);

}