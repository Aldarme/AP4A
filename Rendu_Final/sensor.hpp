/**
 * @author Jules Ferlin
 * @file Sensor.hpp
 * @date 03/10/2022
 * @brief Fichier header contenant la définition et l'implémentation de des attributs et méthode de la classe Sensor
 */


// Define Guards
#ifndef PROJET_AP4A_Sensor_HPP
#define PROJET_AP4A_Sensor_HPP
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>

/**
 * @class Sensor
 * @brief Classe définissant les Sensors. Cette classe est une classe mere pour tous les types de capteur
 */
template<class T>
class Sensor
{
protected:
  T m_minValeur, m_maxValeur;    ///< Valeur minimum et maximum que le capteur peut avoir
  std::string m_nomCapteur;      ///< Nom du capteur pour l'écriture dans la console et dans les fichiers logs
  std::string m_unite;           ///< Unité des valeurs du capteur pour affichage dans la console et écriture dans les fichiers logs
  int m_delai;                   ///< Délai entre deux mesures
public:
  // Forme canonique
  Sensor<T>();
  Sensor<T>(const Sensor<T>& Sensor_p);
  ~Sensor<T>();
  Sensor<T>& operator=(const Sensor<T>& Sensor_p);

  /**
   * @brief Fait appelle à aleaGenVal pour générer une valeur pour un capteur
   * @return Retourne la valeur générée pour être utilisation
   */
  virtual T getData();

  /**
   * @brief Créer une valeur aléatoire compris entre minVal_p et maxVal_p
   * @param minVal_p Borne minimum
   * @param maxVal_p Borne maximum
   * @return Retourne la valeur générée aléatoirement
   */
  T aleaGenVal(float minVal_p, float maxVal_p);

  /**
   * @brief Fonction permettant d'obtenir le nom de l'objet, du capteur
   * @return Retourne le nom de l'objet appelant
   */
  std::string getName();

  /**
   * @brief Fonction permettant d'obtenir l'unité de l'objet, du capteur
   * @return Retourne l'unité de l'objet appelant
   */
  std::string getUnite();

  /**
   * @brief Initialise la valeur de délai entre chaque mesure pour le capteur appelant
   */
  void setDelai();

  /**
   * @brief Fonction permettant d'obtenir le délai entre chaque mesure
   * @return Retourne le délai
   */
  int getDelai();
};

template<typename T>
Sensor<T>::Sensor()
{
  this->m_minValeur = 0;
  this->m_maxValeur = 1;
  this->m_nomCapteur = "Sensor";
  this->m_unite = "";
  this->m_delai = 1;
}

template<typename T>
Sensor<T>::Sensor(const Sensor<T>& Sensor_p): m_minValeur(this->m_minValeur), m_maxValeur(this->m_maxValeur), m_nomCapteur(this->m_nomCapteur), m_unite(this->m_unite) {}

template<typename T>
Sensor<T>::~Sensor<T>() = default;

template<typename T>
Sensor<T>& Sensor<T>::operator=(const Sensor<T>& Sensor_p)
{
  this->m_minValeur = Sensor_p.m_minValeur;
  this->m_maxValeur = Sensor_p.m_maxValeur;
  return *this;
}

template<typename T>
T Sensor<T>::getData()
{
  return this->aleaGenVal(this->m_minValeur, this->m_maxValeur);
}

template<typename T>
T Sensor<T>::aleaGenVal(float minVal_p, float maxVal_p)
{
  return (minVal_p + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(maxVal_p-minVal_p))));
}

template<typename T>
std::string Sensor<T>::getName()
{
  return this->m_nomCapteur;
}

template<typename T>
std::string Sensor<T>::getUnite()
{
  return this->m_unite;
}

template<typename T>
void Sensor<T>::setDelai()
{
  std::cout << "Entrez le d\x82""lai entre chaque mesure du capteur " << this->m_nomCapteur << " (entre 0 et 4)";
  std::cin >> this->m_delai;
  while (this->m_delai <= 0 || this->m_delai > 4)
  {
    fflush(stdin);
    std::cout << "Vous devez entrer une valeur entre 0 et 4. R\x82""essayez." << std::endl;
    std::cout << "Entrez le d\x82""lai entre chaque mesure du capteur " << this->m_nomCapteur << " (entre 0 et 4)";
    std::cin >> this->m_delai;
  }
  fflush(stdin);
}

template<typename T>
int Sensor<T>::getDelai()
{
  return this->m_delai;
}


#endif //PROJET_AP4A_Sensor_HPP
