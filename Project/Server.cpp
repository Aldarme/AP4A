/**
 * @author Muna Ayuni MAHATHIR
 * @file Server.cpp
 * @brief This class is to receive and store all the data received from class Scheduler.
 */

#include "Server.hpp"
#include <iostream>
#include <fstream>
using namespace std ;


// This is used to show all the datas collected from sensor on the console.
void Server::ConsoleWrite (std::string type_p,int val_p,std::string unit_p,bool activ_p)
{

   if(activ_p==true)
   {
    cout<<type_p<<" : "<<val_p<<unit_p<<"         " ;
    if (type_p=="Pression") cout<<endl ;
   }

}

//This is used to store all the datas collected in the sensor's respective file Log
void Server::fileWrite (std::string type_p,int val_p,std::string unit_p,bool activ_p)
{
    ofstream LogSensor("Log"+type_p+".txt",std::ios::app) ;
    if (activ_p==true)
    {
        LogSensor<<val_p<< unit_p <<endl ;
        LogSensor.close();
    }
}

//This is used so that the user can decide whether or not show the datas on the console. 
bool Server::ActivConsole()
{
    char choix ;
    cout<<"Do you want to activate the console?"<<endl ;
    cout<<"Press 'y' for yes or press 'n' for no "<<endl ;
    cin>>choix ;
    cout<<endl ;

    while(true)
    {
       switch (choix)
        {
            case 'y' : return true ;break;
            case 'n' : return false ; break ;
            default : cout<< "Please answer only with y for yes, n for no "<<endl;cin>>choix; cout<<endl ; break ;
        }

    }


}

//This is used so that the user can decide whether or not to store the upcoming datas in their respective file Log
bool Server::ActivFile()
{
    char choix ;
    cout<<"Do you want to update the file with all the new datas?"<<endl ;
    cout<<"Press 'y' for yes or press 'n' for no "<<endl ;
    cin>>choix ;
    cout<<endl ;

    while(true)
    {
       switch (choix)
        {
            case 'y' : return true ; break;
            case 'n' : return false ; break ;
            default : cout<< "Please answer only with y for yes, n for no "<<endl;cin>>choix;cout<<endl ; break ;
        }

    }

}
