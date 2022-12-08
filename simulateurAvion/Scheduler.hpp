/**
 * @author NANMEGNI_NGASSAM
 * @file Scheduler.hpp
 * @date 24/09/2022
 * @licence libre
 */
#ifndef SCHEDULER_H
#define SCHEDULER_H

/**
 * @class Scheduler
 * @brief Cette classe synchronise le Sensor avec le serveur ( Elle récupère les valeurs disponilbles au niveau du sensor et les envoie au serveur suivant une fréquence de temps)
 */
class Scheduler
{
public:
  // Forme canonique de Coplien
  Scheduler();
  Scheduler( const Scheduler& autreScheduler);
  virtual ~Scheduler();
  Scheduler& operator=(const Scheduler& autreScheduler);

  //Autres méthodes de la classe
  void scheduler( Serveur& DB, HumiditySensor& humidity, TemperatureSensor& temp, LightSensor& ligth, SoundSensor& sound);
};

#endif