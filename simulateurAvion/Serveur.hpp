/**
 * @author NANMEGNI_NGASSAM
 * @file Serveur.hpp
 * @date 24/09/2022
 * @licence libre
 */

// Define guards
#ifndef SERVEUR_H
#define SERVEUR_H

/**
 * @class Serveur
 * @brief La classe Serveur reçoit les données provenants des différents capteurs, les stocke dans les logs et les affiche en console (eventuellement)
 */
class Serveur
{
private:
  bool m_consoleActivation; // conditionne l'affichage en console des données
  bool m_logActivation; // Conditionne l'ecriture dans le fichier de Logs des données
  
  // Ouverture d'un fichier log et ajout des données receuillis avec la reférence horaire
  void fileWrite(float temp, float humidity, float light, float sound);
   // Affichage des données receuillis à l'intérieur de la console
  void consoleWrite(float temp, float humidity, float light, float sound);
  

public:
  // forme canonique de Coplien
  Serveur();
  Serveur(const Serveur& autreServeur);
  virtual ~Serveur();
  Serveur& operator=(const Serveur& autreServeur);

  //Permet de modifier les valeurs de m_consoleActivation et de m_logActivation 
  void dataDisplayParameters(bool console, bool log);

  //Recois les données du scheduler et les affichent conformement au dataDisplayParameters
  void dataRcv(float temp, float humidity, float light, float sound);
};

#endif //SERVEUR_H















