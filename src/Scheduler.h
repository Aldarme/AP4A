/*
 * @author raphael_perrin
 * @file Scheduler.h
 * @date 05/10/2022
 * @brief Classe permettant l'envoit à une fréquence régulière des informations des Sensors de l'avion
 */

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Sensor.h"
#include "Server.h"
#include <thread>

#include "Temperature.h"
#include "Light.h"
#include "Humidity.h"
#include "Pression.h"

class Scheduler
{
private :
	Sensor<float>* m_sensor1;
	Sensor<bool>* m_sensor2;
	Sensor<int>* m_sensor3;
	Sensor<float>* m_sensor4;

	float m_frequency;

	Server* m_server;

public:
	// Définition de la forme canonique
    Scheduler();
	Scheduler(Scheduler& scheduler_p);
	~Scheduler()
	{
		delete m_sensor1;
		delete m_sensor2;
		delete m_sensor3;
		delete m_sensor4;
	}
	Scheduler& operator=(Scheduler& scheduler_p);

	/*
    * @brief Methode permettant de demander à l'utilisateur quel type d'affichage d'informations il souhaite lors du lancement du programme
    * @return void
    * @param none
    * 
    */

public :
	/*
    * @brief Methode permettant au programme d'afficher ou enregistrer les informations des sensors à une fréquence donnée
    * @return void
    * @param float frequency
    * 
    */
    void wait(float frequency_p);

	/*
    * @brief Methode permettant au programme de récupérer les informations des sensors indéfiniment jusqu'à la fin du programme
    * @return void
    * @param none
    */
	
	template <class T> void loop(Sensor<T>& sensor_p, float frequency_p)
	{
    	while(isRunning())
		{
            this->wait(frequency_p);
			sensor_p.refreshData();
			if(m_server->m_consoleActivation)	m_server->consoleWrite(sensor_p);
			if(m_server->m_logActivation)		m_server->fileWrite(sensor_p);
		}
	}

	/*
    * @brief Methode permettant de connaître si le scheduler est actuellement actif, c'est à dire s'il écrit soit dans les logs, soit dans la console
    * @return bool
    * @param none
    */
	bool isRunning();

	/*
    * @brief Methode permettant d'activer ou de désactiver le mode console seulement, log seulement ou les deux par l'intermédiaire de la réponse envoyée en paramètres
    * @return void
    * @param char answer_p
    */
	void checkAnswer(char answer_p);

	void ask();
	void launchThreads();
};

#endif // SCHEDULER_H