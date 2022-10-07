/**
 * @author Jules Ferlin
 * @file server.hpp
 * @date 03/10/2022
 * @brief Fichier header contenant la définition de la classe Server
 */


// Define Guards
#ifndef PROJET_AP4A_SERVER_HPP
#define PROJET_AP4A_SERVER_HPP

#include <iostream>
#include <fstream>
#include "Sensors/Humidite.hpp"
#include "Sensors/Light.hpp"
#include "Sensors/Pression.hpp"
#include "Sensors/Temperature.hpp"


/**
 * @class Server
 * @brief Classe permettant de faire la liaison entre le serveur et les capteurs
 */
class Server
{
private:
  bool m_consolActivation;    ///< Attribut permettant de vérifier l'écriture des informations dans la console
  bool m_logActivation;       ///< Attribut permettant de vérifier l'écriture des informations dans les fichiers logs
public:
  // Définition de la forme canonique
  Server();
  Server(const Server& server_p);
  ~Server();
  Server& operator=(const Server& server_p);

  /**
   * @brief Demande à l'utilisateur si il veut écrire dans la console ou non
   */
  void toggleConsolWrite();

  /**
   * @brief Demande à l'utilisateur si il veut écrire dans les logs ou non
   */
  void toggleLogWrite();

  /**
   * @brief Fonction pour écrire dans les logs
   * @param nomCapteur_p Nom du capteur à écrire
   * @param valeur_p Valeur du capteur
   * @param unite_p Unité du capteur
   */
  template<typename T>
  void fileWrite(const std::string& nomCapteur_p,T valeur_p,const std::string& unite_p);

  /**
   * @brief Fonction pour écrire dans la console
   * @param nomCapteur_p Nom du capteur à écrire
   * @param valeur_p Valeur du capteur
   * @param unite_p Unité du capteur
   */
  template<typename T>
  void consolWrite(const std::string& nomCapteur_p,T valeur_p,const std::string& unite_p);
};

template<typename T>
void Server::fileWrite(const std::string& nomCapteur_p, const T valeur_p, const std::string& unite_p)
{
  // Si l'utilisateur a choisi d'afficher dans les logs alors on lui affiche
  if (this->m_logActivation == 1)
  {
    std::ofstream file(nomCapteur_p + ".txt", std::ios::app);
    file << nomCapteur_p << " " << valeur_p << " " << unite_p << std::endl;
    file.close();
  }
}

template<typename T>
void Server::consolWrite(const std::string& nomCapteur_p, const T valeur_p, const std::string& unite_p)
{
  // Si l'utilisateur a choisi d'afficher dans les logs alors on lui affiche
  if (this->m_consolActivation == 1)
    std::cout << nomCapteur_p << " " << valeur_p << " " << unite_p << std::endl;
}


#endif //PROJET_AP4A_SERVER_HPP
