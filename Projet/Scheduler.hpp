/**
 * @author Erhart Eliott
 * @file Scheduler.hpp
 * @date 03/10/2022
 * @brief Définition de la classe Scheduler
 */

//DEFINE GUARDS
#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Server.hpp"
#include "Packet.hpp"

/** 
 * @class Scheduler
 * @brief Implémentation classe Scheduler 
 */

class Scheduler
{
public:
        /// @brief Instanciation d'un objet packet
        Packet packet;
        
        /// @brief Déclaration de la forme canonique de Coplien
        Scheduler ():packet(){}; // Constructeur par défaut
        Scheduler (const Scheduler& a):packet(a.packet){}; // Constructeur par recopie
        ~Scheduler (){}; // Destructeur
        Scheduler& operator=(const Scheduler& scheduler);

        /**
         * @brief Récupère les valeurs aléatoires obtenues dans la classe Sensor et les met dans un packet
         * @return this
         */
        Scheduler getAll();

        /**
         * @brief Envoie les valeurs présentes dans le packet vers la class Server
         * @return Rien
         * @param référence à la class Server
         */
        void sendData(Server& A);

        /**
         * @brief Attend pendant une seconde pour la récupération de donnée
         * @return Rien
         */
        void wait();
};

#endif // SCHEDULER_H