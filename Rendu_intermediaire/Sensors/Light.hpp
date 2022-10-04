/**
 * @author Jules Ferlin
 * @file Light.hpp
 * @date 03/10/2022
 * @brief Fichier header contenant la définition des méthodes de la classe Light
 */

#ifndef PROJET_AP4A_LIGHT_HPP
#define PROJET_AP4A_LIGHT_HPP

#include "../sensor.hpp"

/**
 * @class Light
 * @brief Classe Light héritant de la classe Sensor
 */
class Light : public Sensor<TYPE>
{
public:
    // Forme canonique
    Light();
    Light(const Light& l_p);
    ~Light();
    Light& operator=(const Light& l_p);

    /**
     * Redéfinition de la méthode aleaGenVal de la classe Sensor afin de renvoyer 0 ou 1
     * @return Retourne 0 ou 1
     */
    TYPE aleaGenVal();

    /**
     * Redéfinition de la méthode getData de la classe Sensor afin de renvoyer 0 ou 1
     * @return Retourn la valeur aléatoire retourné par aleaGenVal
     */
    TYPE getData();
};

#endif //PROJET_AP4A_LIGHT_HPP
