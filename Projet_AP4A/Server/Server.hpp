/**
 * @author Augustin Athané
 * @file Server.hpp
 * @date 24/09/2022
 * @brief Le serveur récupère les données ordonnées envoyés par le scheduler. Une fois récupérer ses données sont stockés
 */


#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <cstdlib>

class Server
{
    //Variables
    private :
        //Pour le rendu intermédiaire tous est en int
        int valTemperature;
        int valHumidity;
        int valLight;
        int valPression;

        bool doLog;
        bool doPrintConsole;

        bool simulation;

    public :
        //Constructeurs
        //Constructeur par défault
        Server();

        //Constructeur paramétré
        Server(int t, int h, int l, int p);

        //Constructeur par recopie
        Server(const Server &s);

        //Destructeur
        ~Server();

        //Méthodes

        void startSimulation();

        void endSimulation();

        //Visualiser les données arrivantes dans la console
        void consoleWrite();

        //Socker les donn ́ees des capteurs dans des fichiers de logs 
        void fileWrite();

        //Recevoir des données des capteurs
        void updateTemp(int t);

        void updateHumidity(int h);

        void updateLight(int l);

        void updatePression(int p);

        void updateDoLog(bool doLog_);

        void updateDoPrintConsole(bool doPrintConsole_);
};

#endif // SERVER_HPP