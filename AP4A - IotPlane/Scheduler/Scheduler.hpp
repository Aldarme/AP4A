/**
 * @author NANMEGNI_NGASSAM
 * @file Scheduler.hpp
 * @date 19/10/2022
 * @licence libre
 */
#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

//Inclusion des assets(capteurs et serveur)
#include "../Serveur/Serveur.hpp"
#include "../Sensor/Humidity/Humidity.hpp" 
#include "../Sensor/Light/Light.hpp" 
#include "../Sensor/Pression/Pression.hpp" 
#include "../Sensor/Temperature/Temperature.hpp" 


/**
 * @class Scheduler
 * @brief Synchronise les capteurs avec le serveur ( Elle récupère les valeurs disponilbles au niveau des capteurs et les envoie au serveur suivant une fréquence de temps)
 */
class Scheduler
{
public:
  // FORME CANONIQUE
  Scheduler();
  Scheduler( const Scheduler& autre );
  virtual ~Scheduler();
  Scheduler& operator=(const Scheduler& autre);

  //AUTRES METHODES
  //Synchronisation de la recuperation des donnees au niveau des capteurs, l'affichage et les logs
  void scheduler( Serveur& DB, Humidity& humidity, Temperature& temp, Light& ligth, Pression& pression);
};

#endif // SCHEDULER_HPP