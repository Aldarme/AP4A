#include "Scheduler.hpp"
#include "Server.hpp"
#include <iostream>
#include <unistd.h>
#include <thread>
#include <mutex>
std::mutex mtx;
Scheduler::Scheduler():atemp(),ahumid(),alight(),apress(),version(2062022.2){};
  //  std::cout<<"I'm here in constructeur par defaut!\n";

//ils sont passer par reference pour eviter le copiage(j'aime l'optimisation de la memoire)
Scheduler::Scheduler(Temperature &atemp2,Humidity &ahumid2,Light &alight2,Pression &apress2)
{

    atemp=atemp2;
    ahumid=ahumid2;
    alight=alight2;
    apress=apress2;
}
Scheduler::Scheduler(const Scheduler &p)
{
   // cout<<"\nJe suis dans recopie\n";
    atemp=p.atemp;
    ahumid=p.ahumid;
    alight=p.alight;
    apress=p.apress;
}

Scheduler& Scheduler::operator=(const Scheduler &p)
{
  //  cout<<"\nJe suis dans apperateur d'affectation\n";
    atemp=p.atemp;
    ahumid=p.ahumid;
    alight=p.alight;
    apress=p.apress;
    return *this;
}
void threadTemp(Server MYFIRSTSERVER,Temperature atemp,int option)
{
    sleep(1);//attendre seulement 1 second au debut 
    while (true)
    {
    mtx.try_lock();
    if (option==1){
    MYFIRSTSERVER.consoleWrite1(atemp); sleep(1.5); }//chaque 1.5s print sur le console
    //Note j'ai augmente le temps du sleep dans le cas affichage sur console pour qu'on aura le temps a lire les donnes
    else if(option==2){MYFIRSTSERVER.fileWrite2(atemp);sleep(1);}//chaque 1s print sur le fichier
    else{ MYFIRSTSERVER.consoleWrite1(atemp);MYFIRSTSERVER.fileWrite2(atemp);sleep(1.5);}//ici c'est le cas du print sur console et stocker dans les fichiers en meme temps
   
    mtx.unlock();
    };
}
void threadhumid(Server MYFIRSTSERVER,Humidity ahumid,int option)
{
    
   sleep(2);//une pause seulement dans le démarrage
   while (true)
   {
       if (option==1){
        MYFIRSTSERVER.consoleWrite1(ahumid);sleep(3);//chaque 3 seconde
        }
        else if(option==2)
        {
           MYFIRSTSERVER.fileWrite2(ahumid);sleep(2);
        }
        else if(option==4){MYFIRSTSERVER.consoleWrite1(ahumid);MYFIRSTSERVER.fileWrite2(ahumid);sleep(3);}
       
        
   };
}
void threadpress(Server MYFIRSTSERVER,Pression apress,int option)
{   while (true)
{   
    if (option==1)
     {MYFIRSTSERVER.consoleWrite1(apress);sleep(5);}
     else if(option==2){MYFIRSTSERVER.fileWrite2(apress);sleep(3);}
     else
     {
        MYFIRSTSERVER.consoleWrite1(apress);
        MYFIRSTSERVER.fileWrite2(apress);
        sleep(5);
     }
      
};
}
void threadlight(Server MYFIRSTSERVER,Light alight,int option)
{
    sleep(3);
    while (true)
    {
        if (option==1){
        MYFIRSTSERVER.consoleWrite1(alight);sleep(6);}
        else if(option==2)
        {
            MYFIRSTSERVER.fileWrite2(alight);sleep(4);
        }
        else { MYFIRSTSERVER.consoleWrite1(alight);MYFIRSTSERVER.fileWrite2(alight);sleep(6);}
    

    }
};
void Scheduler::Scheduler_in_and_out(Server MYFIRSTSERVER,int &option,int choix_du_fichier_a_lire)//,char type2[])//,Sensor humidity)
{
   
        if (option==1 || option==2|| option==4)
        {  
            //creation des threads !!!vive la multithreading!les donnees seront recuperees et transmises a des intervalles de temps differents. 
            std::thread t1 {threadTemp,MYFIRSTSERVER,atemp,option};//chaque capteur a sa propre thread
            std::thread t2 {threadhumid,MYFIRSTSERVER,ahumid,option};
            std::thread t3{threadlight,MYFIRSTSERVER,alight,option};
            std::thread t4 {threadpress,MYFIRSTSERVER,apress,option};
            t1.join();//pour attendre le thread 
            t2.join();
            t3.join();
            }


            
            else{ MYFIRSTSERVER.ReadFile(choix_du_fichier_a_lire);}//si l'option etait de lire les fichier seulements
        
}

    

       
          
//encapsulation
Temperature Scheduler::getTemp()
{
        return atemp;
}
void Scheduler::setTemp(Temperature temp)
{
    atemp=temp;
}
Humidity Scheduler::getHumid()
{
        return ahumid;
}
void Scheduler::setHumid(Humidity humid)
{
    ahumid=humid;
}
Light Scheduler::getLight()
{
        return alight;
}
void Scheduler::setLight(Light light)
{
    alight=light;
}
Pression Scheduler::getPress()
{
        return apress;
}
void Scheduler::setPress(Pression press)
{
    apress=press;
}



