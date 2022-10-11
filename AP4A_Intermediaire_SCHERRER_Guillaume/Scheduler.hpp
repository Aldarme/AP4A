/** 
 * @author SCHERRER Guillaume
 * @file Scheduler.hpp
 * @date 25/09/2022
 * @brief Cette classe a pour but de créer le timing de lecture des capteurs.
 *  
*/

#ifndef SCHEDULER_H
#define SCHEDULER_H

class Scheduler
{
    private:
        int m_period_in_seconds; // période du scanning des capteurs

    public:
        Scheduler(int); // constructor
        ~Scheduler();   // destructor
        Scheduler(Scheduler& scheduler); // constructeur de recopie 
        Scheduler& operator=(const Scheduler& scheduler); //opérateur d'affectation

        /** 
        * @brief fonction "maître " du programme 
        * @return rien car de type void
        * @param aucun 
        *
        */
        void ProcessScheduler();

        /** 
        * @brief fonction qui récupère et stocke les valeurs retournées  par les capteurs
        * @return rien car de type void
        * @param pointeur sur un tableau
        *
        */
        void GetSensorData(float*);

        /** 
        * @brief fonction qui transfère les données au serveur
        * @return rien car de type void
        * @param pointeur sur un tableau
        *
        */
        void TransferDataToServer(float*);

        /** 
        * @brief fonction qui permet d'arrêter le programme en cours 
        * @return rien car de type void
        * @param aucun
        *
        */
        void Stop();

};

#endif