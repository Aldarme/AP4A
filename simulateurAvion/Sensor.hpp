/**
 * @author NANMEGNI_NGASSAM
 * @file Sensor.hpp
 * @date 24/09/2022
 * @licence libre
 */

#ifndef SENSOR_H
#define SENSOR_H
/**
 * @class Sensor
 * @brief Cette classe prélève des informations de l'avion en vol et les transmet au serveur via le scheduler
 */
class Sensor
{
protected:
  float aleaGenVal();// Génère les valeurs données

public:
  // Forme canonique de Coplien
  Sensor();
  Sensor(const Sensor& autreSensor);
  virtual ~Sensor();
  Sensor& operator=( const Sensor& autreSensor);

  // Autres méthodes de la classe
  float getData();// Recuperation des données générées et envoie au scheduler
};

#endif