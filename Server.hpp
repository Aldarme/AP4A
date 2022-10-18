/*      author:TRABOULSI Rawan
        *SERVER
        *Créé le 19/09/2020          */
        
#ifndef SERVER_HPP
#define SERVER_HPP
#include <string>
#include <fstream>
#include <iostream>
#include <type_traits>//pour traiter les types des capteurs dans les templates
#include <cstdint>

#include "Sensor.hpp"
#include "Temperature.hpp"
#include "Pressure.hpp"
#include "Humidity.hpp"
#include "Brightness.hpp"
#include "Server.hpp"
using namespace std;



class Server{
                //Les Attributs
        private:
                bool m_consoleActivation;
                bool m_logActvation;

        /*void consoleWrite pour le rendu finale prend en paramètre une valeur template et un int id pour identifier temperature et humidité qui sont de même type
        c'est une fct qui permet d'écrire les valeurs des 4 capteurs sur le console de l'utilisateur */

        template <class T>
        void consoleWrite(T value_p,int id_p){
                time_t now=time(0);
                char* dt=ctime(&now);
                if(std::is_same<T,int>::value){
                        std::cout<<"La pression à l'intérieur de l'avion est de:"<<value_p<<"Pascal"<<dt<<"\n"<<std::endl;
                }
                if( (std::is_same<T,float>::value)&&(id_p==1) ){
                        std::cout<<"La températue à l'intérieur de l'avion est de:"<<value_p<<"degré Celsius"<<dt<<"\n"<<std::endl;
                }
                if( (std::is_same<T,float>::value)&&(id_p==4) ){
                        std::cout<<"L'humidité à l'intérieur de l'avion  est de:"<<value_p<<"%"<<dt<<"\n"<<std::endl;
                }
                if(std::is_same<T,bool>::value){
                        std::cout<<"La présence de lumière est de:"<<value_p<<dt<<"\n"<<std::endl;
                        std::cout<<std::boolalpha<<std::endl; //boolalpha pour afficher la valeure de true en alphabétique et non pas sous forme de binaire
                }
        }

                /****
		 * void fileWrite pour la partie finale du projet qui prend en parametre 1 valeur template et un entier id (qui permet de différencier humidité et la température qui sont de même type)
		 * elle permet d'écrire ces données sur 4 fichiers .txt qui sont crée dans le dossier 
		 */
                template < class T >
                void fileWrite(T value_p,int id_p){
                        time_t now = time(0);//pour pouvoir utiliser le temps du systeme.
			char* dt = ctime(&now);
                        if(std::is_same<T,int>::value){
                                std::string const Pressure("C:/FichiersAP4A/Pressure.txt");
                                std::ofstream txt1(Pressure.c_str(),std::ios::app);
                                if(txt1){
                                        txt1 <<"La pression à l'intérieur de l'avion :"<<value_p<<"Pascal"<<dt<<"\n"<<std::endl;
                                }
                        }

                        if((std::is_same<T,float>::value) && (id_p==1)){
                                std::string const Temperature("C:/FichiersAP4A/Temperature.txt");
                                std::ofstream txt2(Temperature.c_str(),std::ios::app);
                                if(txt2){
                                        txt2 <<"La Températureà l'intérieur de l'avion :"<<value_p<<"degré Celsius"<<dt<<"\n"<<std::endl;
                                }
                        }

                        if((std::is_same<T,float>::value)&&(id_p==4)){		
				std::string const Humidity("C:/FichiersAP4A/Humidity.txt");
				std::ofstream txt3(Humidity.c_str(),std::ios::app);
				if(txt3){
					txt3<< "L'humidité à l'intérieur de l'avion : "<<value_p<<"%-----> "<<dt <<"\n"<<std::endl;
					}
			}

                        if(std::is_same<T,bool>::value){
				std::string const Brightness("C:/FichiersAP4A/Brightness.txt");
				std::ofstream txt4(Brightness.c_str(),std::ios::app);
				if(txt4){
					txt4 << "Luminosité à l'intérieur de l'avion est: "<<value_p<<dt <<"\n"<<std::endl;
					}
                        }
                }

        public:
        //Forme canonique de coplien
        Server();//constructeur par défaut
        Server(const Server &S); //constructer par recopie
        Server &operator=(const Server & S);//operateur d'affectation
     //   virtual~Server();//destructeur
        Server(bool consoleActivation_p,bool logActivation_p);//constructeur par paramètres


        /*pour avoir accès aux consolActivation et logActivation*/
        bool getconsoleActivation();
        bool getlogActivation();
        void setconsoleAvtivation(bool consoleActivation_p);//activer la console
        void setlogActivation(bool logActivation_p);//activer le log

        
        template <class T>
        void dataRcv(T value_p,Server&server_p,int id_p){
                 consoleWrite(value_p,id_p);
                 if(server_p.m_logActvation==true)
                 {
                        fileWrite(value_p,id_p);
                 }
                
        }

};


#endif //SERVER_H
