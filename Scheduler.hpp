 /*
 @author Saad Sbat
 @file Scheduler.hpp
 @date 24/9/2022
 @C'est la classe du capteur Scheduler qui récupére les données des capteurs et les envoies au serveur pour les afficher*/
#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP
#include <iostream>
#include "Sensor.hpp"
#include "Temperature.hpp"
#include "Humidity.hpp"
#include "Light.hpp"
#include "Pression.hpp"

class Scheduler
{
private:
   float m_version;
   //string  unite;
   Temperature m_temp;//l'objet atem de la classe temperature est un attribut de classe scheduler 
   Humidity m_humid;
   Light m_light;
   Pression m_press;

   

public:
   Scheduler(/* args */);
   Scheduler(Temperature &atem2,Humidity &ahumid2,Light &alight2,Pression &apress2);
   Scheduler(const Scheduler & autre);
   ~Scheduler(){};
   Scheduler& operator=(const Scheduler &p);
   void Scheduler_in_and_out(Server MYFIRSTSERVER,int& choix2);//,char type2[]);//,Sensor humidity);
   Temperature getTemp();
   void setTemp(Temperature temp);
   Humidity getHumid();
   void setHumid(Humidity humid);
   Light getLight();
   void setLight(Light light);
   Pression getPress();
   void setPress(Pression press);




};

#endif