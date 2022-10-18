/**
 * @author NANMEGNI_NGASSAM
 * @file Serveur.cpp
 * @date 24/09/2022
 * @licence public
 */
#include "Serveur.hpp"
#include<iostream>
#include<fstream>

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

void Serveur::dataRcv(float temp, float humidity, bool light, int pression)
{
  if(this -> m_consoleActivation)
  {
    consoleWrite(temp, humidity, light, pression);
  }

  if( this -> m_logActivation)
  {
    fileWrite(temp, humidity, light, pression);
  }
}

void Serveur::consoleWrite(float temp, float humidity, bool light, int pression)
{
  // Formatage des ecrits à l'intérieur de la console 
  cout << "Les donnees receuillis actuellement sont : " << endl;
  cout << "temperature : " << temp << " C";
  cout << "   ";
  cout << "humidity : " << humidity << " g/m3";
  cout << "   ";
  // Display "Light : on" or "Light : off" according to the state of light
  if(light)
  {
    cout << "ligth : On ";
  }
  else
  {
    cout << "ligth : Off";
  }
  cout << "   ";
  
  cout << "Pression : " << pression << " Pa" << endl;
}

void Serveur::fileWrite(float temp, float humidity, bool light, int pression)
{
  string cheminAccesLog ="Data.txt";
  ofstream fluxLog(cheminAccesLog.c_str(), ios::app);

  // Formatage des ecrits à l'intérieur du fichier de Logs
  fluxLog << "Temperature : " << temp <<" C   ";
  fluxLog << "   ";
  fluxLog << "Humidity : " << humidity <<" g/m3   ";
  fluxLog << "   ";
  // Display "Light : on" or "Light : off" according to the state of light
  if (light)
  {
    fluxLog << "Light : on ";
  }
  else
  {
    fluxLog << "Light : off";
  }
  fluxLog << "   ";
  fluxLog << "Pression : " << pression <<" Pa" << endl;
}