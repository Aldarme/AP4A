#include <iostream>
#include "Server.hpp"
#include "Scheduler.hpp"
#include <unistd.h>

Scheduler::Scheduler():m_temp(),m_humid(),m_light(),m_press(),m_version(2062022.2){};
  //  std::cout<<"I'm here in constructeur par defaut!\n";

//ils sont passer par reference pour eviter le copiage(j'aime l'optimisation de la memoire)
Scheduler::Scheduler(Temperature &atemp2,Humidity &ahumid2,Light &alight2,Pression &apress2)
{

    m_temp=atemp2;
    m_humid=ahumid2;
    m_light=alight2;
    m_press=apress2;
}
Scheduler::Scheduler(const Scheduler &p)
{
   // cout<<"\nJe suis dans recopie\n";
    m_temp=p.m_temp;
    m_humid=p.m_humid;
    m_light=p.m_light;
    m_press=p.m_press;
}

Scheduler& Scheduler::operator=(const Scheduler &p)
{
  //  cout<<"\nJe suis dans apperateur d'affectation\n";
    m_temp=p.m_temp;
    m_humid=p.m_humid;
    m_light=p.m_light;
    m_press=p.m_press;
    return *this;
}

void Scheduler::Scheduler_in_and_out(Server MYFIRSTSERVER,int& choix2)//,char type2[])//,Sensor humidity)
{
   for (int i=0;i<300;i++)
   {
        //type2="Temperature";
        //ici j'ai créer 2 types de methode dans Scheduler

        //premier methode:consolewrite(atemp,ahumid,alight,apress);
        //deuxieme methode:consolewrite2(datatemp,datahumid,datalight,datapression)
        //la premiere prend en parametre les capteurs (c'est mieux pour que je puisse'afficher les unité des capteurs avec un acces au leurs attribut privé en créant une relation d'amitié entre la classe server et les classes capteurs  )
        //la deuxieme prend en parametre directement les data mais dans ce cas quand je veux afficher dans les console ou dans le file je devrais moi meme ecrire les types (Ce n'est pas recommandé)
        //c'est pour cela que je vais utiliser la premiere 
        //meme chose pour le filewrite
        /*
        les argument au cas j'ai utilisé la deuxieme methode:
        float TemperatureData_Returned_From_TheCapteur=atemp.getData(atemp.type); 
        float HumidityData_Returned_From_TheCapteur=ahumid.getData(ahumid.type);
        float LightData_Returned_From_TheCapteur=alight.getData(alight.type);
        float PressionData_Returned_From_TheCapteur=apress.getData(apress.type);
        */


        if (choix2==1)
        {//qui permet l'affichage sur le console
            MYFIRSTSERVER.consoleWrite1(m_temp,m_humid,m_light,m_press);
          //  MYFIRSTSERVER.consoleWrite2(TemperatureData_Returned_From_TheCapteur,HumidityData_Returned_From_TheCapteur,LightData_Returned_From_TheCapteur,PressionData_Returned_From_TheCapteur);

             sleep(1);//pause pour une second(pour que je puisse recupere les donnees chaque seconde)
        }
        else if(choix2==2)
        {//write sur le log file
            MYFIRSTSERVER.fileWriteatt(m_temp,m_humid,m_light,m_press);
         //   MYFIRSTSERVER.fileWrite(TemperatureData_Returned_From_TheCapteur,HumidityData_Returned_From_TheCapteur,LightData_Returned_From_TheCapteur,PressionData_Returned_From_TheCapteur);
            sleep(1);
        }
    }
        if (choix2==3)
        {//lire le fichier log
            MYFIRSTSERVER.ReadFile();
        }
        
}
       
          
//encapsulation
Temperature Scheduler::getTemp()
{
        return m_temp;
}
void Scheduler::setTemp(Temperature temp)
{
 m_temp=temp;
}
Humidity Scheduler::getHumid()
{
        return m_humid;
}
void Scheduler::setHumid(Humidity humid)
{
    m_humid=humid;
}
Light Scheduler::getLight()
{
        return m_light;
}
void Scheduler::setLight(Light light)
{
    m_light=light;
}
Pression Scheduler::getPress()
{
        return m_press;
}
void Scheduler::setPress(Pression press)
{
    m_press=press;
}



