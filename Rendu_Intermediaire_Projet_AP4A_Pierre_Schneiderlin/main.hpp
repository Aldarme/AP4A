/**
 * @author Pierre Schneiderlin
 * @file main.hpp
 * @date 22/09/2022
 * @brief header principal contenant les déclaration des constantes et des fonctions utilisées dans le programme
 */

#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <random>
#include <ctime>
#include <unistd.h>

/**
 * Constantes définissant les bornes de valeurs que la génération aléatoire des données par les objets de classe Sensor ne doit pas franchir
 */
#define MINTEMP 23
#define MAXTEMP 25
#define MINHUM 10
#define MAXHUM 20
#define MINPRE 760
#define MAXPRE 820

/**
 * Constantes définissant les unités utilisées pour les données de chaque capteur
 */
#define UNITE_TEMP "deg C"
#define UNITE_HUM "%"
#define UNITE_PRE "hPa"
#define UNITE_LI ""

/**
 * Constantes définissant les noms des fichiers de logs dans lesquelles seront stockées les données par le serveur
 */
#define FICHIER_TEMP "temperature.txt"
#define FICHIER_HUM "humidity.txt"
#define FICHIER_PRE "pression.txt"
#define FICHIER_LI "light.txt"

/**
 * Fonction permettant de contrôler la réponse d'un utilisateur à une question fermée et de renvoyer sa réponse
 * @return la réponse de l'utilisateur à la question fermée : soit true pour OUI ou false pour NON
 */
bool yesNoAnswerControl();

#endif //MAIN_HPP
