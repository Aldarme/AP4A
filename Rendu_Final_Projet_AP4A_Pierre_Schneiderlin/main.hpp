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
 * Constantes définissant les noms des données, utilisés dans l'affichage dans la console
 */
#define TEMP "Temperature"
#define HUM "Humidity"
#define LI "Light"
#define PRE "Pression"

/**
 * Constantes définissant les unités utilisées pour les données de chaque capteur, utilisées dans l'affichage dans la console
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
 * Constantes définissant les caractères utilisés pour la saisie d'un utilisateur lorsqu'il souhaite répondre à un question posée par le programme
 */
#define YES 'O'
#define NO 'N'
#define QUIT 'Q'

/**
 *  * Fonction permettant de contrôler la réponse d'un utilisateur à une question fermée et de renvoyer sa réponse
 * @param yes_p - Le caractère signifiant Oui que l'utilisateur devra entrer pour répondre Oui
 * @param no_p - Le caractère signifiant Non que l'utilisateur devra entrer pour répondre Non
 * @return la réponse de l'utilisateur à la question fermée : soit true pour OUI ou false pour NON
 */
bool yesNoAnswerControl(char yes_p, char no_p);

/**
 *
 * Fonction permettant de contrôler la réponse d'un utilisateur à une demande d'entrée d'un entier
 * @param min_p - l'entier minimum accepté lors de la saisie
 * @param max_p - l'entier maximum accepté lors de la saisie
 * @return l'entier entré par l'utilisateur
 */
int intInputControl(int min_p, int max_p);

#endif //MAIN_HPP
