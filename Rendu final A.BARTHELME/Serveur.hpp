#ifndef Serveur_hpp
#define Serveur_hpp
#include<iostream>
#include<string>
#include <chrono>
#include "Paquet.hpp"
#include<fstream>
class Serveur
{
    private :
        std::string m_nom;
    public :
        Serveur();
        Serveur(std::string nom);
        ~Serveur();
        template <typename T>
        void fileWriter(Paquet<T> paquet)
        {          
            int id = paquet.GetId();
            std::string fichier = "logNdef.txt";
            switch (id)
            {
                case 3:
                fichier="logHum.txt";                       
                break;
                case 1:
                fichier="logTemp.txt";                    
                break;
                case 2:
                fichier="logPress.txt";       
                break;
                default:
                std::cout << "Erreur de type de capteur" << std::endl;
            }
                
            std::ofstream log(fichier.c_str(),std::ios::app);
            if(log)
            {
                log << " " << std::endl;
                time_t now = time(0);
                char* dt = ctime(&now);
                log<< dt << " : " << std::endl;
                log << "ID Val debbug : "<< paquet.GetId()  << std::endl;
                log <<"Capteur : " <<  paquet.GetType()<< std::endl;
                log << "valeur : " << paquet.data() << " " << paquet.Getunit()  << std::endl;
            }
        }
        void fileWriter(Paquet<bool> paquet){
            std::ofstream log("logLum.txt",std::ios::app);
            if(log)
            {
                log << " " << std::endl;
                time_t now = time(0);
                char* dt = ctime(&now);
                log<< dt << " : " << std::endl;
                //log << "ID Val debbug : "<< paquet.GetId()  << std::endl;
                log <<"Capteur de luminosite "<< std::endl;
                if (paquet.data())
                {
                    log << "detection de la lumiere" << std::endl;
                }
                else
                {
                    log << "pas de lumiere detectee" << std::endl;
                }
            }
        }

        template <typename T>
        void consoleWriter(Paquet<T> paquet){
            std::cout << " " << std::endl;
            time_t now = time(0);
            char* dt = ctime(&now);
            std::cout << dt << " : " << std::endl;
            //std::cout << "ID Val debbug : "<< paquet.GetId()  << std::endl;
            std::cout <<"Capteur : " <<  paquet.GetType()<< std::endl;
            std::cout << "valeur : " << paquet.data() << " " << paquet.Getunit()  << std::endl;
        }
        void consoleWriter(Paquet<bool> paquet){
            std::cout << " " << std::endl;
            time_t now = time(0);
            char* dt = ctime(&now);
            std::cout << dt << " : " << std::endl;
            std::cout << "ID Val debbug : "<< paquet.GetId()  << std::endl;
            std::cout <<"Capteur de lumisite "  <<   std::endl;
            if (paquet.data())
            {
                std::cout << "Detection de Lumiere" << std::endl;
            }
            else
            {
                std::cout << "Pas de Lumiere detectee" << std::endl;
            } 
        
        }
};


#endif /* Serveur_hpp */