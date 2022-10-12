/**
 * @file Server.hpp
 * @author Loric Ravassard
 * @brief Gestion des données reçues : affichage dans la console et/ou dans les logs 
 * en fonction du choix de l'utilisateur
 * @version 1
 * @date 2022-09-27
 */

#ifndef SERVER_H
#define SERVER_H

#include "Package.hpp"

/**
 * @class Server
 * @brief Gestion des données reçues : affichage dans la console et/ou dans les logs 
 * en fonction du choix de l'utilisateur
 */
class Server
{
  private:
    bool m_consolActivation;  ///affiche dans la console si vrai
    bool m_logActivation; ///créer des fichiers de log si vrai
  public:
    Server() : m_consolActivation(true), m_logActivation(true){};
    Server(const Server& other_p) : m_consolActivation(other_p.m_consolActivation), m_logActivation(other_p.m_logActivation){};
    virtual ~Server(){};
    Server& operator=(const Server& other_p);

    /**
     * @brief écrit les données dans les fichiers de log de chaque capteur
     * 
     * @param data_p 
     */
    void fileWrite(Package& data_p);

    /**
     * @brief écrit les données dans la console
     * 
     * @param data_p 
     */
    void consoleWrite(Package& data_p);

    /**
     * @brief reçoit les données du Scheduler pour pouvoir les afficher dans la console et/ou dans les logs
     * 
     * @param data_p 
     */
    void dataRcv(Package& data_p);

    /**
     * @brief méthode pour que l'utilisateur puisse modifier consolActivation
     * 
     * @param param_p 
     */
    void consoleActivate(bool param_p);

    /**
     * @brief méthode pour que l'utilisateur puisse modifier logActivation
     * 
     * @param param_p 
     */
    void logsActivate(bool param_p);
};

#endif