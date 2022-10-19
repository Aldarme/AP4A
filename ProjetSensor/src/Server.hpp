/**
 * @author Thibaud Leclere <thibaud.leclere@utbm.fr>
 * @file Server.hpp
 * @date 28/09/2022
 * @brief Définition de la class Server
 * @brief Reçoit et envoie les données des capteurs
 */

// Define guards
#ifndef SERVER_H
#define SERVER_H

#include "Sensor.hpp"

#include <iostream>
#include <fstream>

class Server
{
private:
    //Booléens permettant de savoir où envoyer les informations
    bool m_sendConsole = true, m_sendLog = true;

    //Chemin du dossier où stocker les logs (sans "/" à la fin)
    std::string m_logsDirectory = "../logs";

    /**
     * @brief Ecrit les données reçues dans la console
     * @param data Structure SensorData, contenant les informations d'un capteur
     */
    void consoleWrite(SensorData data);
    
    /**
     * @brief Ecrit les données de chaque Sensor dans un fichier (dans le dossier logs)
     * @param data Structure SensorData, contenant les informations d'un capteur
     */
    void fileWrite(SensorData data);

    /**
     * @brief Crée le dossier des logs s'il n'existe pas, et supprime son contenu
    */
    void initLogs();

public:
    //Forme canonique
    Server();
    virtual ~Server();
    Server(const Server& s);
    Server& operator=(const Server& s);

    /**
     * @brief Reçoit les données d'un capteur, et les affiche dans la console et/ou dans les logs
     * @param data Structure SensorData, contenant les informations à afficher d'un capteur
    */
    void rcvData(SensorData data);

    /**
     * @brief Demande à l'utilisateur où envoyer les données des capteurs (console et/ou logs)
    */
    void askOutputs();
};

#endif // SERVER_H
