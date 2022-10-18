/**
 * @author NANMEGNI_NGASSAM
 * @file Sensor.hpp
 * @date 18/10/2022
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
  std::string unity;

protected:
  //methode virtuelle pure, generation des valeurs aléatoires
  virtual T aleaGenVal() = 0;// Génère les valeurs des données(temperature, pression,lumière...) de l'environnement IOT

public:
  // FORME CANONIQUE
  Sensor<T>();
  Sensor<T>(const Sensor<T>& capteur);
  virtual ~Sensor<T>();
  Sensor<T>& operator=( const Sensor<T>& capteur);

  // AUTRES METHODES
  T getData()// Recuperation des données générées (aleaGenVal())
  {
    T fetchedData; 
    fetchedData = aleaGenVal();
    return fetchedData;
  }
  // Inserer une fonction qui retourne l'unité si besoin

};

/**
 * Template class implementation have to be declared in the hpp file
 */

template<class T> Sensor<T>::Sensor() : unity()
{
}
template<class T> Sensor<T>::Sensor(const Sensor<T>& capteur) = default;
template<class T> Sensor<T>::~Sensor<T>() = default;
template<class T> Sensor<T>& Sensor<T>::operator=(const Sensor<T>& capteur) = default;

#endif // SENSOR_HPP