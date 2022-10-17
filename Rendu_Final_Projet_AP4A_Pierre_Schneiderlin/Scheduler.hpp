/**
 * @author Pierre Schneiderlin
 * @file Scheduler.hpp
 * @date 22/09/2022
 * @brief header contenant la déclaration de la classe Scheduler, qui permet de définir la fréquence à laquelle les données des capteurs
 * (des objets de classe mère Sensor, attributs de la classe Scheduler) seront récupérées, puis transmises au serveur (à l'objet de classe Server,
 * attribut de la classe Scheduler) pour être affichées (console) et/ou stockées (fichiers).
 */

#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <chrono>
#include <thread>
#include "main.hpp"
#include "Sensor.hpp"
#include "Server.hpp"

#include "TemperatureSensor.hpp"
#include "HumiditySensor.hpp"
#include "PressionSensor.hpp"
#include "LightSensor.hpp"

/**
 * @class Scheduler
 * @brief Classe permettant de définir la fréquence à laquelle les données des capteurs (des objets de classe mère Sensor, attributs de la classe Scheduler)
 * seront récupérées, puis transmises au serveur (à l'objet de classe Server, attribut de la classe Scheduler)
 * pour être affichées (console) et/ou stockées (fichiers).
 */
class Scheduler
{

private:
    Server m_server; /// Contient l'objet de classe Server permettant d'écrire des données dans la console et des fichiers

    TemperatureSensor m_temperature; /// Contient un objet de classe TemperatureSensor permettant de générer des valeurs à la façon d'un capteur de température
    HumiditySensor m_humidity; /// Contient un objet de classe HumiditySensor permettant de générer des valeurs à la façon d'un capteur de'humidité
    LightSensor m_light; /// Contient un objet de classe LightSensor permettant de générer des valeurs à la façon d'un capteur de lumière
    PressionSensor m_pression; /// Contient un objet de classe PressionSensor permettant de générer des valeurs à la façon d'un capteur de pression

public:

    //////////////////////////////////// FORME CANONIQUE ////////////////////////////////////

    /**
     * Constructeur par défaut
     */
    Scheduler():m_server(),m_temperature(),m_humidity(),m_light(),m_pression(){};

    /**
     * Constructeur par recopie
     * @param s - l'objet de classe Scheduler à recopier
     */
    Scheduler(const Scheduler& s);

    /**
     * Destructeur
     */
    virtual ~Scheduler()= default;;

     /**
     * Opérateur d'affectation "="
     * @param s - l'objet de classe Scheduler dont on souhaite copier les attributs dans l'objet appelé
     * @return l'objet appelé modifié
     */
    Scheduler& operator=(const Scheduler& s);

    /////////////////////////////////////////////////////////////////////////////////////////

    /**
     * Méthode permettant d'accéder à l'attribut m_server de l'objet de classe Scheduler
     * @return la référence de l'attribut Server m_server
     */
    Server& getServer();

    /**
     * Méthode permettant d'accéder à l'attribut m_temperature de l'objet de classe Scheduler
     * @return la référence de l'attribut TemperatureSensor m_temperature
     */
    TemperatureSensor& getTemperatureSensor();

    /**
     * Méthode permettant d'accéder à l'attribut m_humidity de l'objet de classe Scheduler
     * @return la référence de l'attribut HumiditySensor m_humidity
     */
    HumiditySensor& getHumiditySensor();

    /**
     * Méthode permettant d'accéder à l'attribut m_pression de l'objet de classe Scheduler
     * @return la référence de l'attribut PressionSensor m_pression
     */
    PressionSensor& getPressionSensor();

    /**
     * Méthode permettant d'accéder à l'attribut m_light de l'objet de classe Scheduler
     * @return la référence de l'attribut LightSensor m_light
     */
    LightSensor& getLightSensor();

    /**
     * Méthode affectant à l'attribut m_data de chaque attribut de classe mère Sensor une valeur aléatoire
     */
    void setRandDataAllSensor();

    /**
     * Méthode permettant de demander à l'utilisateur de saisir une période de prélèvement pour un type de capteur donné
     * @param type - la chaîne de caractères indiquant le type du capteur
     * @return la période choisie par l'utilisateur
     */
    static int setPeriod(const std::string& type);

    /**
     * Méthode pilotant tout le processus de réception et d'envoi des données des capteurs au serveur (réception des données des capteurs (attribut
     * m_data de chaque objet de classe mère Sensor), et envoi de ces données à son attribut de classe Server pour l'affichage dans la console et/ou
     * l'écriture dans les fichiers de logs) selon une fréquence définie
     * @param time - le nombre de secondes durant lesquelles doit se dérouler le programme ("" les capteurs doivent générer des données)
     * @return true si l'utilisateur a choisi de continuer la simulation et qu'elle s'est bien déroulée, ou false s'il a souhaité l'arrêter
     */
    bool beginSimulation(int time);

};

#endif //SCHEDULER_HPP
