/**
 * @author Tontsa apala frank
 * @file Sensor.hpp
 * @date 25/09/2022
 * @brief sensor
 */

#include "Sensor.hpp"

template <class T>
//Constructeur par defaut
Sensor<T>::Sensor() {}

//Destructeur
template <class T>
Sensor<T>::~Sensor() {}

template <class T>
//Constructeur de recopie
Sensor<T>::Sensor(const Sensor &other) {}

//Pour eviter des erreurs de compilation, nous allons declarer
//les differents type du template de la classe Sensor
template class Sensor<float>; //Pour la class temperature et humidity
template class Sensor<int>; //Pour la class Pression
template class Sensor<bool>; //Pour la clalsse Light
