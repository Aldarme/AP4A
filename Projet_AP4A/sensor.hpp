/**
 * @author Jules Ferlin
 * @file Sensor.hpp
 * @date 03/10/2022
 * @brief Fichier header contenant la définition et l'implémentation de des attributs et méthode de la classe Sensor
 */

#ifndef PROJET_AP4A_Sensor_HPP
#define PROJET_AP4A_Sensor_HPP
#include <cstdlib>
#include <ctime>
#include <iostream>


/**
 * @class Sensor
 * @brief Classe définisant les Sensors. Cette classe est une classe mere pour tous les types de capteur
 */
template<class T>
class Sensor
{
protected:
    T m_minValue, m_maxValue;      ///< Valeur minimum et maximum que le capteur peut avoir
    std::string m_name;            ///< Nom du capteur pour l'ecriture dans la console et dans les fichiers logs
    std::string m_unite;           ///< Unité des valeurs du capteur pour affichage dans la console et écriture dans les fichiers logs
public:
    // Forme canonique
    Sensor<T>();
    Sensor<T>(const Sensor<T>& param_Sensor);
    ~Sensor<T>();
    Sensor<T>& operator=(const Sensor<T>& param_Sensor);

    /**
     * @brief Fait appelle à aleaGenVal pour générer une valeur pour un capteur
     * @return Retourne la valeur générée pour etre utilisation
     */
    virtual T getData();

    /**
     * @brief Créer une valeur aléatoire compris entre param_minVal et param_maxVal
     * @param param_minVal Borne minimum
     * @param param_maxVal Borne maximum
     * @return Retourne la valeur générée aléatoirement
     */
    T aleaGenVal(float param_minVal, float param_maxVal);

    /**
     * Fonction permettant d'obtenir le nom de l'objet, du capteur
     * @return Retourne le nom de l'onjet appelant
     */
    std::string getName();

    /**
     * Fonction permettant d'obtenir l'unité de l'objet, du capteur
     * @return Retourne l'unité de l'objet appelant
     */
    std::string getUnite();

};

template<typename T>
Sensor<T>::Sensor()
{
    this->m_minValue = 0;
    this->m_maxValue = 1;
    this->m_name = "Sensor";
    this->m_unite = "";
}

template<typename T>
Sensor<T>::Sensor(const Sensor<T>& param_Sensor): m_minValue(this->m_minValue), m_maxValue(this->m_maxValue), m_name(this->m_name), m_unite(this->m_unite) {}

template<typename T>
Sensor<T>::~Sensor<T>() = default;

template<typename T>
Sensor<T>& Sensor<T>::operator=(const Sensor<T>& param_Sensor) {
    this->m_minValue = param_Sensor.m_minValue;
    this->m_maxValue = param_Sensor.m_maxValue;
    return *this;
}

template<typename T>
T Sensor<T>::getData()
{
    return this->aleaGenVal(this->m_minValue, this->m_maxValue);
}

template<typename T>
T Sensor<T>::aleaGenVal(float param_minVal, float param_maxVal)
{
    return (param_minVal + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(param_maxVal-param_minVal))));
}

template<typename T>
std::string Sensor<T>::getName()
{
    return this->m_name;
}

template<typename T>
std::string Sensor<T>::getUnite()
{
    return this->m_unite;
}


#endif //PROJET_AP4A_Sensor_HPP
