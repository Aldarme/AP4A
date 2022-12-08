/**
 * @author NANMEGNI_NGASSAM
 * @file Serveur.cpp
 * @date 24/09/2022
 * @licence public
 */
#include "Serveur.hpp"

using namespace std;

// Implémentation des méthodes de la classe Serveur
Serveur::Serveur() : m_consoleActivation(true), m_logActivation(true)
{
}

Serveur::Serveur(const Serveur& autreServeur) : m_consoleActivation(autreServeur.m_consoleActivation), m_logActivation(autreServeur.m_logActivation) 
{
}

Serveur::~Serveur()
{
}

Serveur& Serveur::operator=(const Serveur& autreServeur)
{
  this -> m_consoleActivation = autreServeur.m_consoleActivation;
  this -> m_logActivation = autreServeur.m_logActivation;
  return *this;
}

void Serveur::dataDisplayParameters(bool console, bool log)
{
  this -> m_consoleActivation = console;
  this -> m_logActivation = log;
}

void Serveur::dataRcv(float temp, float humidity, float light, float sound)
{
  if(this -> m_consoleActivation)
  {
    consoleWrite(temp, humidity, light, sound);
  }

  if( this -> m_logActivation)
  {
    fileWrite(temp, humidity, light, sound);
  }
}

void Serveur::consoleWrite(float temp, float humidity, float light, float sound)
{
  // Formatage des ecrits à l'intérieur de la console 
  cout << "Les donnees receuillis actuellement sont : " << endl;
  cout << "temperature : " << temp << " C" << endl;
  cout << "humidity : " << humidity << " g/m3" << endl;
  cout << "light : " << light << " Cd" << endl;
  cout << "sound : " << sound << " Db" << endl;
}

void Serveur::fileWrite(float temp, float humidity, float light, float sound)
{
  string cheminAccesLog ="Logs.txt";
  ofstream fluxLog(cheminAccesLog.c_str(), ios::app);

  // Formatage des ecrits à l'intérieur du fichier de Logs
  fluxLog << " ********** DONNEES RECEUILLIS ********** " << endl;
  fluxLog << temp <<" C" << endl;
  fluxLog << humidity <<" g/m3" << endl;
  fluxLog << light <<" Cd" << endl;
  fluxLog << sound <<" Db" << endl;
}