/**
 * @file Server.hpp
 * @author Loric Ravassard
 * @brief Gestion des données reçues : affichage dans la console et/ou dans les logs 
 * en fonction du choix de l'utilisateur
 * @version 2
 * @date 2022-09-27
 */

#ifndef SERVER_H
#define SERVER_H

#include "Package.hpp"
#include <fstream>
#include <iostream>
#include <iomanip>

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
    template <typename T> void fileWrite(Package<T>& data_p)
    {
      //Le fichier est créé s'il n'existe pas déjà
      std::ofstream file("../logs/"+data_p.getName()+".csv", std::ios::app);  //on ouvre le fichier et on écrit à la suite de ce qui est déjà écrit
      file << data_p.getDate() << "," << std::boolalpha << data_p.getValue() << "," << data_p.getUnit() << std::endl; //boolalpha permet d'écrire les booléen avec true/false
      file.close();
    };

    /**
     * @brief écrit les données dans la console
     * 
     * @param data_p 
     */
    template <typename T> void consoleWrite(Package<T>& data_p) 
    {
      std::cout << "[" << data_p.getDate() << "] " << data_p.getName() << " -> " << std::boolalpha << data_p.getValue() << " " << data_p.getUnit() << std::endl;
      //boolalpha permet d'écrire les booléen avec true/false
    };

    /**
     * @brief reçoit les données du Scheduler pour pouvoir les afficher dans la console et/ou dans les logs
     * 
     * @param data_p 
     */
    template <typename T> void dataRcv(Package<T>& data_p)
    {
      if(m_consolActivation)
      {
        consoleWrite(data_p);
      }
      if(m_logActivation)
      {
        fileWrite(data_p);
      }
    };

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