/*      author:TRABOULSI Rawan
        *SERVER
        *Créé le 19/09/2020          */
        
#ifndef SERVER_HPP
#define SERVER_HPP
#include "Sensor.hpp"
#include "Temperature.hpp"
#include "Pressure.hpp"
#include "Humidity.hpp"
#include "Brightness.hpp"
#include "Server.hpp"
#include <string>
#include <fstream>


using namespace std;


class Server{
                //Les Attributs
        private:
                bool m_consoleActivation;
                bool m_logActvation;

        void consoleWrite(int pressure_p,int humidity_p,int brightness_p,int temp_p);/*c'est la fonction
        qui prend en paramètre les attributs de température,d'humidité,de luminosité et de pression pour 
        les afficher au console.*/

        void fileWrite(int pressure_p,int humidity_p,int brightness_p,int temp_p);/*c'est la fonction
        qui permet d'écrire ces données sur 4 fichiers.txt qui seront créé dans C:*/


        public:
        //Forme CANONIQUE

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


        //dataRcv fct qui permet de récupérer les données du scheduler et les transmettre sur le serveur
       /*cette fct prend en paramètres la température,la pression,la luminosté,l'humidité et un serveur surlequel les données seront transimises.*/
        void dataRcv(int pressure_p,int humidity_p,int brightness_p,int temp_p,Server &server_p);
        
        


};


#endif //SERVER_H
