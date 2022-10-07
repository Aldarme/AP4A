/**
 * @author Jules Ferlin
 * @file scheduler.cpp
 * @date 03/10/2022
 * @brief Fichier source contenant l'implémentation des méthodes de la classe Scheduler
 */


#include "scheduler.hpp"

Scheduler::Scheduler() : m_durerSimulation(0), m_humidite(), m_light(), m_pression(), m_temperature(), m_server() {}

Scheduler::Scheduler(const Scheduler& s_p) : m_durerSimulation(s_p.m_durerSimulation), m_temperature(s_p.m_temperature), m_pression(s_p.m_pression), m_light(s_p.m_light), m_humidite(s_p.m_humidite), m_server(s_p.m_server) {}

Scheduler::~Scheduler() = default;

Scheduler& Scheduler::operator=(const Scheduler& scheduler_p)
{
  this->m_humidite = scheduler_p.m_humidite;
  this->m_light = scheduler_p.m_light;
  this->m_pression = scheduler_p.m_pression;
  this->m_temperature = scheduler_p.m_temperature;
  this->m_durerSimulation = scheduler_p.m_durerSimulation;
  return *this;
}

void Scheduler::setDurerSimulation()
{
  int durer;
  std::cout << "Entrez la durer de la simulation (en seconde):";
  std::cin >> durer;
  while (durer <= 0) // Boucle tant que la valeur est inférieure à 0.
  {
    fflush(stdin);
    std::cout << "Vous devez entrer une valeur sup\x82""rieur \x85"" 0" << std::endl << "Entre la durer de la simulation:";
    std::cin >> durer;
  }
  this->m_durerSimulation = durer;
  fflush(stdin);
}

void Scheduler::startSimulation()
{
  // Demande le temps de la simulation et le délai de capture des données de chaque capteur
  this->setDurerSimulation();
  this->m_humidite.setDelai();
  this->m_light.setDelai();
  this->m_pression.setDelai();
  this->m_temperature.setDelai();

  // Demande à l'utilisateur s'il souhaite écrire dans la console ou les logs
  this->m_server.toggleConsolWrite();
  this->m_server.toggleLogWrite();
  clock_t start;

  // Récupéré le temps d'exécution du programme au démarrage de la boucle en seconde
  start = (clock()/CLOCKS_PER_SEC);

  // Boucle tant que le temps d'exécution de la boucle ne correspond pas au temps entré par l'utilisateur
  while (((clock()/CLOCKS_PER_SEC) - start) < this->m_durerSimulation)
  {
    if (((clock()/CLOCKS_PER_SEC) - start) % this->m_humidite.getDelai() == 0)
    {
      this->m_server.consolWrite(this->m_humidite.getName(), this->m_humidite.getData(), this->m_humidite.getUnite());
      this->m_server.fileWrite(this->m_humidite.getName(), this->m_humidite.getData(), this->m_humidite.getUnite());
    }

    if (((clock()/CLOCKS_PER_SEC) - start) % this->m_light.getDelai() == 0)
    {
      this->m_server.consolWrite(this->m_light.getName(), this->m_light.getData(), this->m_light.getUnite());
      this->m_server.fileWrite(this->m_light.getName(), this->m_light.getData(), this->m_light.getUnite());
    }

    if (((clock()/CLOCKS_PER_SEC) - start) % this->m_pression.getDelai() == 0)
    {
      this->m_server.consolWrite(this->m_pression.getName(), this->m_pression.getData(), this->m_pression.getUnite());
      this->m_server.fileWrite(this->m_pression.getName(), this->m_pression.getData(), this->m_pression.getUnite());
    }

    if (((clock()/CLOCKS_PER_SEC) - start) % this->m_temperature.getDelai() == 0)
    {
      this->m_server.consolWrite(this->m_temperature.getName(), this->m_temperature.getData(), this->m_temperature.getUnite());
      this->m_server.fileWrite(this->m_temperature.getName(), this->m_temperature.getData(), this->m_temperature.getUnite());
    }

    // Pause de 1 seconde
    sleep(1);
  }
}