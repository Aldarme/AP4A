#include <iostream>
#include "Sensor.hpp"
#include "Server.hpp"
#include "Temperature.hpp"

#include <string>
#include <fstream>
#include <time.h> 
#include<ctime>
#include <string.h>

using std::cout;
Server::Server():version(1.0)
{
  //  std::cout<<"I'm here in constructeur par defaut!\n";
}
Server::Server(const Server& autre)
{
    //cout<<"je suis dans recopie\n";
    version=autre.version;
}

Server& Server::operator=(const Server&autre)
{
    //cout<<"je suis dans l'operateur d'affectation\n";
    version=autre.version;
    return *this;
}








//Merci a template qui m'a permis de gagner du temps et eviter le copiage
template <class G> void Server::consoleWrite1(G capteur)//originale
{
    time_t now = time(0);
    tm* localtm = localtime(&now);
        
    cout<<asctime(localtm);//afficher le temps du recuperation des donnes
        
  
    if (strcmp(capteur.gettype(),"Temperature")==0)
    //      --> <le type du capteur>  :                            data correspond au capteur et de son type                  unite
    {cout<<"-->"<<capteur.gettype()<<":"<< capteur.template getData<float>(capteur.gettype(),capteur.getUnite())<<" "<<capteur.getUnite()<<"\n";}
    else if(strcmp(capteur.gettype(),"Humidity")==0)
    {cout<<"-->"<<capteur.gettype()<<":"<<std::boolalpha<<capteur.template getData<float>(capteur.gettype(),capteur.getUnite())<<" "<<capteur.getUnite()<<"\n";}
   else if(strcmp(capteur.gettype(),"Light")==0)
    {
        bool res;
        res=capteur.template getData<bool>(capteur.gettype(),capteur.getUnite());
        if (res==true)
        {
        cout<<"-->"<<capteur.gettype()<<":"<<std::boolalpha<<res<<",Il y'a de lumiere!"<<"\n";
        }
        else
        {
        cout<<"-->"<<capteur.gettype()<<":"<<std::boolalpha<<res<<",Pas de lumiere!"<<"\n";

        }
    }
    else
    {cout<<"-->"<<capteur.gettype()<<":"<<capteur.template getData<int>(capteur.gettype(),capteur.getUnite())<<" "<<capteur.getUnite()<<"\n";}
}








//logger les informations dans des fichiers
template<typename T>void Server::fileWrite2(T capteur)//Merci a template qui m'a permis de gagner du temps et eviter le copiage
{
        time_t now = time(0);
        tm* localtm = localtime(&now);
        
       // cout<<"-";
        std::ofstream myfile; 
        char filename[18];
        strcpy(filename,capteur.gettype());//pour que le nom du fichier soit le meme nom de capteur
        strcat(filename,".txt");//concatenation du nom de fichier avec .txt
        myfile.open (filename,std::ios::app);//creation du fichier
        myfile <<asctime(localtm);//afficher le temps du recuperation des donnes
          //-->le type du capteur:     data                         unite
 if (strcmp(capteur.gettype(),"Temperature")==0)
 //      --> <le type du capteur>  :                            data correspond au capteur et de son type                  <unite>
    {myfile<<"-->"<<capteur.gettype()<<":"<< capteur.template getData<float>(capteur.gettype(),capteur.getUnite())<<" "<<capteur.getUnite()<<"\n";}
    else if(strcmp(capteur.gettype(),"Humidity")==0)
    {myfile<<"-->"<<capteur.gettype()<<":"<<capteur.template getData<float>(capteur.gettype(),capteur.getUnite())<<" "<<capteur.getUnite()<<"\n";}
    else if(strcmp(capteur.gettype(),"Light")==0)
    {
        bool res;
        res=capteur.template getData<bool>(capteur.gettype(),capteur.getUnite());
        if (res==true)
        {
        myfile<<"-->"<<capteur.gettype()<<":"<<std::boolalpha<<res<<",Il y'a de lumiere!"<<"\n";
        }
        else
        {
        myfile<<"-->"<<capteur.gettype()<<":"<<std::boolalpha<<res<<",Pas de lumiere!"<<"\n";

        }
    }
    else
    {myfile<<"-->"<<capteur.gettype()<<":"<<capteur.template getData<int>(capteur.gettype(),capteur.getUnite())<<" "<<capteur.getUnite()<<"\n";}
}






void Server::ReadFile(int choix_du_fichier_a_lire)//lire seulement
{
    std::fstream newfile;
    switch (choix_du_fichier_a_lire)//choisir le fichier a lire
    {
    case 1:
        newfile.open("Temperature.txt",std::ios::in);
        break;
    case 2:
        newfile.open("Humidity.txt",std::ios::in);
        break;
    case 3:
        newfile.open("Light.txt",std::ios::in);
        break;
    case 4:
        newfile.open("Pression.txt",std::ios::in);
        break;

    default:
        break;
    }
     //open a file to perform read operation using file object
   if (newfile.is_open()){   //checking whether the file is open
      string tp;
      while(getline(newfile, tp)){  //read data from file object and put it into string.
         cout << tp << "\n";   //print the data of the string
      }
      newfile.close();  
   }}




















//les autre methodes extra 


/*
void Server::fileWrite(float d1,float d2,float d3,float d4)
{
        time_t now = time(0);
        tm* localtm = localtime(&now);
        
       // cout<<"-";
        std::ofstream myfile; 
        myfile.open ("logs.txt",std::ios::app);
        myfile <<asctime(localtm);//afficher le temps du recuperation des donnes
        myfile<<"-->"<<"Temperature"<<":"<<d1<<" Celsuis\n";
        myfile<<"-->"<<"Humidity"<<" :"<<d2<<" % \n";
        myfile<<"-->"<<"Light"<<" :"<<d3<<" dB \n";
        myfile<<"-->"<<"Light"<<" :"<<d4<<" hPa \n";
        //myfile<<"-->"<<"Pression"<<" :"<<d4<<" dB\n";

        
        myfile.close(); 
}*/





/*

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
*/

/*void Server::fileWriteatt(Temperature &temp,Humidity &humid,Light &light,Pression &press)
{
    time_t now = time(0);
        tm* localtm = localtime(&now);
        
        cout<<"-";
        std::ofstream myfile; 
        myfile.open ("logs.txt",std::ios::app);
        myfile <<asctime(localtm);//afficher le temps du recuperation des donnes
          //-->le type du capteur:     data                         unite
        myfile<<"-->"<<temp.type<<":"<<temp.getData(temp.gettype())<<" "<<temp.unite<<"\n";
        myfile<<"-->"<<humid.type<<":"<<humid.getData(humid.gettype())<<" "<<humid.unite<<"\n";
        myfile<<"-->"<<light.type<<":"<<light.getData(light.gettype())<<" "<<light.unite<<"\n";
        myfile<<"-->"<<press.type<<":"<<press.getData(press.gettype())<<" "<<press.unite<<"\n";
        myfile.close(); 
       // myfile<<"-->"<<"Humidity"<<" :"<<d2<<" % \n";
        //myfile<<"-->"<<"Light"<<" :"<<d3<<" dB \n";
        //myfile<<"-->"<<"Light"<<" :"<<d4<<" hPa \n";
        //myfile<<"-->"<<"Pression"<<" :"<<d4<<" dB\n";
        

}*/
/*
void Server::consoleWrite(Temperature &temp)
{
    time_t now = time(0);
    tm* localtm = localtime(&now);
        
    cout<<asctime(localtm);//afficher le temps du recuperation des donnes
        //-->le type du capteur:     data                         unite
    cout<<"-->"<<temp.gettype()<<":"<<temp.getData()<<" "<<temp.capteur.getUnite()<<"\n";
};
void Server::consoleWrite(Humidity &humid)
{
    time_t now = time(0);
    tm* localtm = localtime(&now);
        
    cout<<asctime(localtm);//afficher le temps du recuperation des donnes
        //-->le type du capteur:     data                         unite
    cout<<"-->"<<humid.gettype()<<":"<<humid.getData()<<" "<<humid.capteur.getUnite()<<"\n";
};
void Server::consoleWrite(Light &light)
{
    time_t now = time(0);
    tm* localtm = localtime(&now);
        
   //afficher le temps du recuperation des donnes
        //-->le type du capteur:     data                         unite
    cout<<asctime(localtm)<<"-->"<<light.gettype()<<":"<<light.getData()<<" "<<light.capteur.getUnite()<<"\n";

};
void Server::consoleWrite(Pression &press)
{
    time_t now = time(0);
    tm* localtm = localtime(&now);
        
    cout<<asctime(localtm);//afficher le temps du recuperation des donnes
        //-->le type du capteur:     data                         unite
    cout<<"-->"<<press.gettype()<<":"<<press.getData()<<" "<<press.capteur.getUnite()<<"\n";
};
*/