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

#include "main.hpp"
#include "Sensors.hpp"
#include "Server.hpp"

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

    Scheduler():m_server(),m_temperature(),m_humidity(),m_light(),m_pression(){};
    Scheduler(const Server& s,const TemperatureSensor& t, const HumiditySensor& h, const LightSensor& l, const PressionSensor& p):m_server(s),m_temperature(t),m_humidity(h),m_light(l),m_pression(p){};
    Scheduler(const Scheduler& s);
    ~Scheduler(){};

    /////////////////////////////////////////////////////////////////////////////////////////

    /**
     * Méthode définissant la surcharge de l'opérateur d'affectation "="
     * @param s - l'objet de classe Scheduler dont on souhaite copier les attributs dans l'objet appelé
     * @return l'objet appelé modifié
     */
    Scheduler& operator=(const Scheduler& s);

    /**
     * Méthode définissant la surcharge de l'opérateur de sortie <<
     * @param os - le flux de sortie par lequel on souhaite diriger l'objet s
     * @param s - l'objet de classe Scheduler que l'on souhaite diriger vers le flux de sortie os
     * @return le flux de sortie dans lequel se trouve l'objet de classe Scheduler tel qu'on souhaite qu'il soit affiché
     */
    friend std::ostream& operator<<(std::ostream& os, Scheduler& s);

    /**
     * Méthode permettant d'accéder à l'attribut m_server de l'objet de classe Scheduler
     * @return la référence de l'attribut Server m_server
     */
    Server& getServer();

    /**
     * Méthode permettant d'accéder à l'attribut m_temperature de l'objet de classe Scheduler
     * @return la référence de l'attribut TemperatureSensor m_temperature
     */
    Sensor& getTemperatureSensor();

    /**
     * Méthode permettant d'accéder à l'attribut m_humidity de l'objet de classe Scheduler
     * @return la référence de l'attribut HumiditySensor m_humidity
     */
    Sensor& getHumiditySensor();

    /**
     * Méthode permettant d'accéder à l'attribut m_pression de l'objet de classe Scheduler
     * @return la référence de l'attribut PressionSensor m_pression
     */
    Sensor& getPressionSensor();

    /**
     * Méthode permettant d'accéder à l'attribut m_light de l'objet de classe Scheduler
     * @return la référence de l'attribut LightSensor m_light
     */
    Sensor& getLightSensor();

    /**
     * Méthode affectant à l'attribut m_data de chaque attribut de classe mère Sensor une valeur aléatoire
     */
    void setRandDataAllSensor();

    /**
     * Méthode pilotant tout le processus de réception et d'envoi des données des capteurs au serveur (réception des données des capteurs (attribut
     * m_data de chaque objet de classe mère Sensor), et envoi de ces données à son attribut de classe Server pour l'affichage dans la console et/ou
     * l'écriture dans les fichiers de logs) selon une fréquence définie
     * @param time - le nombre de secondes durant lesquelles doit se dérouler le programme ("" les capteurs doivent générer des données)
     */
    void sendDataToServer(int time);

};


#endif //SCHEDULER_HPP
