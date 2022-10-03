 /*
 @author Saad Sbat
 @file Sensor.hpp
 @date 24/9/2022
 @C'est la classe Server qui visualise les données et les stocker dans un log file 
 */


#include "Temperature.hpp"
#include "Humidity.hpp"
#include "Light.hpp"
#include "Pression.hpp"




#ifndef SERVER_HPP
#define SERVER_HPP

class Server
{
private:
   float m_version;
public:
   Server(/* args */);
   Server(const Server & autre);
   ~Server(){};
   Server&  operator=(const Server &p);
   void fileWriteatt(Temperature &temp,Humidity &humid,Light &light,Pression &press);
   void consoleWrite1(Temperature &temp,Humidity &humid,Light &light,Pression &press);
   void ReadFile();//pour lire le fichier si on veut
//des methodes extra :)
   void fileWrite(float d1,float d2,float d3,float d4);//une autre methode de writing sur le file
   void consoleWrite2(float d1,float d2,float d3,float d4);//une autre methode pour l'affichage
   
 
};
#endif