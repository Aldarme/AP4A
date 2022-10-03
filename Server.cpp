#include <iostream>
#include "Sensor.hpp"
#include "Server.hpp"
#include <string>
#include <fstream>
#include <time.h> 
#include<ctime>


using std::cout;
Server::Server():m_version(1.0)
{
  //  std::cout<<"I'm here in constructeur par defaut!\n";
}
Server::Server(const Server& autre)
{
    //cout<<"je suis dans recopie\n";
    m_version=autre.m_version;
}

Server& Server::operator=(const Server&autre)
{
    //cout<<"je suis dans l'operateur d'affectation\n";
    m_version=autre.m_version;
    return *this;
}

void Server::consoleWrite1(Temperature &temp,Humidity &humid,Light &light,Pression &press)
{
    time_t now = time(0);
    tm* localtm = localtime(&now);
        
    cout<<asctime(localtm);//afficher le temps du recuperation des donnes
        //-->le type du capteur:     data                         unite
    cout<<"-->"<<temp.m_type<<":"<<temp.getData(temp.m_type)<<" "<<temp.m_unite<<"\n";
    cout<<"-->"<<humid.m_type<<":"<<humid.getData(humid.m_type)<<" "<<humid.m_unite<<"\n";
    cout<<"-->"<<light.m_type<<":"<<light.getData(light.m_type)<<" "<<light.m_unite<<"\n";
    cout<<"-->"<<press.m_type<<":"<<press.getData(press.m_type)<<" "<<press.m_unite<<"\n";
}
void Server::fileWriteatt(Temperature &temp,Humidity &humid,Light &light,Pression &press)
{
    time_t now = time(0);
        tm* localtm = localtime(&now);
        
        cout<<"-";
        std::ofstream myfile; 
        myfile.open ("logs.txt",std::ios::app);
        myfile <<asctime(localtm);//afficher le temps du recuperation des donnes
          //-->le type du capteur:     data                         unite
        myfile<<"-->"<<temp.m_type<<":"<<temp.getData(temp.m_type)<<" "<<temp.m_unite<<"\n";
        myfile<<"-->"<<humid.m_type<<":"<<humid.getData(humid.m_type)<<" "<<humid.m_unite<<"\n";
        myfile<<"-->"<<light.m_type<<":"<<light.getData(light.m_type)<<" "<<light.m_unite<<"\n";
        myfile<<"-->"<<press.m_type<<":"<<press.getData(press.m_type)<<" "<<press.m_unite<<"\n";
        myfile.close(); 
       // myfile<<"-->"<<"Humidity"<<" :"<<d2<<" % \n";
        //myfile<<"-->"<<"Light"<<" :"<<d3<<" dB \n";
        //myfile<<"-->"<<"Light"<<" :"<<d4<<" hPa \n";
        //myfile<<"-->"<<"Pression"<<" :"<<d4<<" dB\n";
        

}
void Server::ReadFile()
{
    std::fstream newfile;

    newfile.open("logs.txt",std::ios::in); //open a file to perform read operation using file object
   if (newfile.is_open()){   //checking whether the file is open
      string tp;
      while(getline(newfile, tp)){  //read data from file object and put it into string.
         cout << tp << "\n";   //print the data of the string
      }
      newfile.close();  
   }}




//les autre methodes extra
void Server::consoleWrite2(float d1,float d2,float d3,float d4)
{
    time_t now = time(0);
    tm* localtm = localtime(&now);
        
    cout<<asctime(localtm);//afficher le temps du recuperation des donnes
    cout<<"-->"<<"Temperature"<<":"<<d1<<" Celsuis\n";   
    cout<<"-->"<<"Humidity"<<" :"<<d2<<" % \n";
    cout<<"-->"<<"Light"<<" :"<<d3<<" dB\n";
    cout<<"-->"<<"Pression"<<" :"<<d4<<" hPa\n";
    //cout<<"-->"<<"Pression"<<" :"<<d4<<" hPa\n";
}

void Server::fileWrite(float d1,float d2,float d3,float d4)
{
        time_t now = time(0);
        tm* localtm = localtime(&now);
        
        cout<<"-";
        std::ofstream myfile; 
        myfile.open ("logs.txt",std::ios::app);
        myfile <<asctime(localtm);//afficher le temps du recuperation des donnes
        myfile<<"-->"<<"Temperature"<<":"<<d1<<" Celsuis\n";
        myfile<<"-->"<<"Humidity"<<" :"<<d2<<" % \n";
        myfile<<"-->"<<"Light"<<" :"<<d3<<" dB \n";
        myfile<<"-->"<<"Light"<<" :"<<d4<<" hPa \n";
        //myfile<<"-->"<<"Pression"<<" :"<<d4<<" dB\n";

        
        myfile.close(); 
}



