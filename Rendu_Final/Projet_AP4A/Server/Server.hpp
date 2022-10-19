/**
 * @author Augustin Athané
 * @file Server.hpp
 * @date 24/09/2022
 * @brief Le serveur récupère les données ordonnées envoyés par le scheduler. Une fois récupérer ses données sont stockés ou/et affichés dans la console
 */


#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <cstdlib>

class Server
{
    //Variables
    private :
        //Valeur des sensors
        float valTemperature;
        float valHumidity;
        bool valLight;
        int valPression;

        //Bool pour savoir quoi afficher
        bool doLog;
        bool doPrintConsole;

        //Bool pour savoir si on est en simulation
        bool simulation;

    public :
        //Constructeur par défault
        Server();

        //Constructeur paramétré
        Server(float t, float h, bool l, int p);

        //Constructeur par recopie
        Server(const Server &s);

        //Destructeur
        ~Server();

        //Méthodes

        //Démarer et arrêter la simulation
        void startSimulation();

        void endSimulation();

        //Visualiser les données dans la console
        void consoleWrite();

        //Socker les donnees des capteurs dans des fichiers de logs 
        void fileWrite();

        //Recevoir des données des capteurs
        void updateTemp(float t);

        void updateHumidity(float h);

        void updateLight(bool l);

        void updatePression(int p);

        //Modifier les booléens d'affichages
        void updateDoLog(bool doLog_);

        void updateDoPrintConsole(bool doPrintConsole_);
};

#endif // SERVER_HPP