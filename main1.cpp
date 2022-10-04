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
using  std::cout;
using  std::cin;
#include <string>
#include <fstream>
#include <random> //pour générer un temps random de simulation et affichage des données avec intervalle
//#include <cstdlib>
//il faut inclure tous les fichiers hpp des classes 
#include "Brightness.hpp"
#include "Brightness.cpp"

#include "Humidity.hpp"
#include "Humidity.cpp"

#include "Pressure.hpp"
#include "Pressure.cpp"

#include "Scheduler.hpp"
#include "Scheduler.cpp"

#include "Sensor.hpp"
#include "Sensor.cpp"

#include "Temperature.hpp"
#include "Temperature.cpp"

#include "Server.hpp"
#include "Server.cpp"





int main()
{

    
    Server Ser1;
    int userchoice=0;
    int time=0;
    int frequency=0;

    cout<<"Hello et bienvenue sur notre platforme de moniteur environnement intérieur de notre avion en vol.\n"<<endl;
    cout<<"******Que souhaitez vous faire?******\n"<<endl;
    cout<<"1-Afficher les données inetrne de notre avion et les écrire dans des fichiers .txt\n 2-Afficher seulement les données inetrnes de notre avion de vol\n 3-QUITTER la platforme\n "<<endl;
    //cout<<"*************************************************************************************"<<endl;

    //scanf("%d",&userchoice);
    cin >> userchoice; //le compilateur n'accepte pas le cin j'ai essayé un compilateur en ligne tout est marché.  es
    cin.ignore();
    
    



    while((userchoice!=1) && (userchoice!=2) && (userchoice!=3)){
        cout<<"Le choix que vous avez effectuer est invalide! Veuillez insérrez seulemnt 1 ou 2 ou 3.\n"<<endl;

    }
    if((userchoice)==3){
        exit(0);//quitter le programme
    }

    cout<<"\nPendant combien de Secondes voulez vous recevoir des données ?" <<endl;
    scanf("%d",&time);


    while((time>1000)||(time<0)){
	cerr<< "Veuillez rentrer une durée valide !"<<endl;
	scanf("%d",&time);
    }

    cout<<"\n A quelle intervalle de temps voulez vous recevoir ces données ?"<<endl;
    scanf("%d",&frequency);

    while((frequency>time)||(frequency<0)){
	cerr<< "Veuillez rentrer un intervalle de temps valide !"<<endl;
	scanf("%d",&frequency);
    }

    //CHOIX1: Afficher et Ecrire dans fichier 
    if(userchoice==1){
        Ser1.setconsoleAvtivation(true);
        Ser1.setlogActivation(true);
    }

    //CHOIX2:Afficher seulement

    else if(userchoice==2){
        Ser1.setconsoleAvtivation(true);
        Ser1.setlogActivation(false);
    }
    

    Scheduler Sch1;
    Sch1.transmetData1(Ser1,frequency,time);


    return 0;
    /*FIN */
    
    }

