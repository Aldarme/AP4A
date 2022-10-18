/**
 * @author NANMEGNI_NGASSAM
 * @file Serveur.hpp
 * @date 18/10/2022
 * @licence libre
 */

#ifndef SERVEUR_HPP
#define SERVEUR_HPP
#include<iostream>
#include<string>

/**
 * @class Serveur
 * @brief Reçoit les données provenants des différents capteurs, et eventuellement les stocke dans les logs et les affiche en console.
 */
class Serveur
{
private:
  bool m_consoleActivation; // conditionne l'affichage en console des données
  bool m_logActivation; // Conditionne l'ecriture dans le fichier de Logs des données

protected:
  // Ouverture d'un fichier log et ajout des données receuillis avec la reférence horaire
  void fileWrite(float temp, float humidity, bool light, int pression);
   // Affichage des données receuillis à l'intérieur de la console
  void consoleWrite(float temp, float humidity, bool light, int pression);
  
public:
  // FORME CANONIQUE
  Serveur();
  Serveur(const Serveur& autre);
  virtual ~Serveur();
  Serveur& operator=(const Serveur& autre);

  // AUTRES METHODES
  //Permet de modifier les valeurs de m_consoleActivation et de m_logActivation 
  void dataDisplayParameters(bool console, bool log);

  //Recois les données du scheduler et les affichent conformement au dataDisplayParameters
  void dataRcv(float temp, float humidity, bool light, int pression);
};

#endif //SERVEUR_HPP















