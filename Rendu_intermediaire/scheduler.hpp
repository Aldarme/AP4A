/**
 * @author Jules Ferlin
 * @file scheduler.hpp
 * @date 03/10/2022
 * @brief Fichier header contenant la définition de la classe Scheduler
 */


// Define Gards
#ifndef PROJET_AP4A_SCHEDULER_HPP
#define PROJET_AP4A_SCHEDULER_HPP

#include "sensor.hpp"
#include "server.hpp"


/**
 * @class Scheduler
 * @brief Classe Scheduler, classe principale qui "orchestre" le programme. Et rattaché aux autres classes
 */
class Scheduler
{
private:
  Humidite m_humidite;        ///< Attribut définissant le capteur humidite
  Light m_light;              ///< Attribut définissant le capteur lumière
  Pression m_pression;        ///< Attribut définissant le capteur pression
  Temperature m_temperature;  ///< Attribut définissant le capteur température
  Server m_server;            ///< Attribut définissant le serveur pour écrire et les données
  int m_durerSimulation;             ///< Attribut définissant le durée de la simulation
  float m_data[4];            ///< Attribut définissant les informations reçu par les capteurs

  /**
   * @brief Demande à l'utilisateur d'entrer la durer de la simulation
   */
  void setDurerSimulation();
public:
  // Forme canonique
  Scheduler();
  Scheduler(const Scheduler& scheduler_p);
  ~Scheduler();
  Scheduler& operator=(const Scheduler& scheduler_p);

  /**
   * @brief Méthode principale du programme qui s'occupe d'initialiser certaines variable et ensuite de récupérer les données et de les envoyer au serveur
   */
  void startSimulation();
};


#endif //PROJET_AP4A_SCHEDULER_HPP
