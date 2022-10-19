/**
 * @author NANMEGNI_NGASSAM
 * @file Simulateur_vol.cpp
 * @date 24/09/2022
 * @licence public
 */
//Inclusion des libraries standards
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
//Inclusion des fichiers propre à mon projet (Scheduler.hpp) car il cadence tout le processus
#include "Scheduler/Scheduler.hpp"


using namespace std;

int main()
{
  //Declaration et parametrage du serveur
  Serveur db;
  db.dataDisplayParameters(true, true);

  //Declaration des differents capteurs avec en paramètres l'unité et le delay, sinon paramètres par défaut
  Humidity humidity;
  Temperature temp("C", 4);
  Light light;
  Pression pression;
  int valeur = pression.getDelay();


  //Declaration et lancement du scheduler
  Scheduler timer;
  timer.scheduler(db,humidity,temp,light,pression);
  return 0;
}