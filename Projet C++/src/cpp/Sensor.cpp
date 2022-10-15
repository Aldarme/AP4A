/*
@author BENEDUCI Marie
@file  Sensor.cpp
@date 19/09/2022
@brief  Implementation de la Classe ayant pour objectif de generer à intervalle régulier des données en int
*/


#ifndef SENSOR_HPP
#define SENSOR_HPP
#include "../hpp/Sensor.hpp"
#endif

#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <iomanip>
#include <map>


// template<typename T>
// Sensor<T>::Sensor(){
// }

// template<typename T>
// Sensor<T>::~Sensor()
// {
// }


// template<typename T>
// T Sensor<T>::aleaGenVal(){ //Fonction de generation de nombre aléatoire entre 1 et 10
//     //float random
//     // std::random_device rd;
//     // std::default_random_engine eng(rd());
//     // std::uniform_real_distribution<float> distr(0, 40);
//     // std::setprecision(6);
//     // float randomData = distr(eng);
//     // return randomData;

//     //int random
//     // int randomNumber = rand() % 10 + 1;
//     // return randomNumber;

//     //bool random
//     T randomData = 0 + (rand() % (1 - 0 + 1)) == 1;
//     return randomData;

// }

// template<typename T>
// T Sensor<T>::getData(){ // Fonction permettant de récuperer la donnée à envoyer
//     return m_data;
// }