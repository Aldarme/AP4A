/**
 * @author NANMEGNI_NGASSAM
 * @file Sensor.hpp
 * @date 19/10/2022
 * @licence libre
 */

#ifndef SENSOR_HPP
#define SENSOR_HPP
/**
 * @class Sensor
 * @brief Receuille les informations(Pression, Temperature...) de l'environnement de vol et les passent au scheduler
 */
#include<string>
#include <time.h>

template <class T> class Sensor // classe abstraite
{
private:
  std::string unit;
  int delay;

protected:
  //methode virtuelle pure, generation des valeurs aléatoires
  virtual T aleaGenVal() = 0;// Génère les valeurs des données(temperature, pression,lumière...) de l'environnement IOT

public:
  // FORME CANONIQUE
  Sensor<T>();
  Sensor<T>(const Sensor<T>& capteur);
  Sensor<T>(std::string unit, int delay);
  virtual ~Sensor<T>();
  Sensor<T>& operator=( const Sensor<T>& capteur);

  // AUTRES METHODES
  T getData();// Recuperation des données générées (aleaGenVal())
  virtual std::string getUnit();//Recuperation de l'unité du capteur
  virtual int getDelay() = 0;//Recuperation de la frequence de timing
};



/**
 * L'implementation des classes templates doivent être rédigés dans le fichier .hpp
 */

template<class T> Sensor<T>::Sensor() : unit(), delay(4)
{
};
template<class T> Sensor<T>::Sensor(const Sensor<T>& capteur) : unit(capteur.unit), delay(capteur.delay)
{
};
template<class T> Sensor<T>::Sensor(std::string unit, int delay) : unit(unit), delay(delay)
{
}
template<class T> Sensor<T>::~Sensor<T>()
{
};
template<class T> Sensor<T>& Sensor<T>::operator=(const Sensor<T>& capteur)
{
  this->unit = capteur.unit;
  this->delay = capteur.delay;
};


// IMPLEMENTATION DES AUTRES METHODES
template<class T> T Sensor<T>::getData()
{
  T fetchedData; 
  fetchedData = aleaGenVal();
  return fetchedData;
}

template<class T> std::string Sensor<T>::getUnit()
{
  return (this->unit);
}
#endif // SENSOR_HPP