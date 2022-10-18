/**
 * @author NANMEGNI_NGASSAM
 * @file Scheduler.hpp
 * @date 18/10/2022
 * @licence libre
 */
#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include "../Serveur/Serveur.hpp" // Inclusion du serveur
#include "../Sensor/Humidity/Humidity.hpp" // Inclusion du capteur d'humidité
#include "../Sensor/Light/Light.hpp" // Inclusion du capteur de lumière
#include "../Sensor/Pression/Pression.hpp" // Inclusion du capteur d'humidité
#include "../Sensor/Temperature/Temperature.hpp" // Inclusion du capteur d'humidité


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
  void scheduler( Serveur& DB, Humidity& humidity, Temperature& temp, Light& ligth, Pression& pression);
};

#endif // SCHEDULER_HPP