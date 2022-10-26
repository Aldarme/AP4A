/** 
 * @author SCHERRER Guillaume
 * @file Scheduler.hpp
 * @date 25/09/2022
 * @brief Cette classe a pour but de créer le timing de lecture des capteurs.
 *  
*/

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "AP4A_Final.hpp"

class Scheduler
{
    // Struct pour récuperer les valeurs générées, puis pour les envoyer au serveur et les afficher


    private:
        float m_period_in_seconds; // période du scanning des capteurs
        int m_PeriodeCapt[4];
        int m_choix_save; // choix de l'utilisateur concernant la méthode d'affichage
        int m_MasterCount;

    public:
        Scheduler(int, int*); // constructor
        ~Scheduler();   // destructor
        Scheduler(Scheduler& scheduler); // constructeur de recopie 
        Scheduler& operator=(const Scheduler& scheduler); //opérateur d'affectation

        /** 
        * @brief fonction "maître " du programme 
        * @return aucun
        * @param aucun 
        *
        */
        void ProcessScheduler();

        /** 
        * @brief fonction qui récupère et stocke les valeurs retournées  par les capteurs
        * @return rien car de type void
        * @param pointeur sur le tableau de valeurs mesurées
        *
        */
        void GetSensorData(float*);

        /** 
        * @brief fonction qui transfère les données au serveur
        * @return rien car de type void
        * @param pointeur sur le tableau de valeurs mesurées
        *
        */
        void TransferDataToServer(ValeursCapteurs &);

        /** 
        * @brief fonction qui permet d'arrêter le programme en cours 
        * @return rien car de type void
        * @param aucun
        *
        */
        void Stop();

        /** 
        * @brief fonction qui permet de demander sous quel forme les valeurs doivent être affiché. 
        * @return le choix sous forme d'un "int"
        * @param aucun
        *
        */
        int GetChoice();

        /** 
        * @brief fonction qui créé un "délai" entre les captures de mesures. 
        * @return aucun
        * @param aucun
        *
        */
        void Delay();

        /** 
        * @brief fonction qui permet la mesure à intervalles irréguliers entre capteurs mais avec des intervalles réguliers pour chaque capteur. 
        * @return aucun
        * @param int-> l'itération de la mesure (= measure_number) ainsi qu'un pointeur sur le tableau de valeurs mesurées
        *
        */
        void MeasureAndProcess(ValeursCapteurs&); //on passe la structure par référence

        /** 
        * @brief fonction pour vérifier si l'uutilisateur souhaite continuer les mesures à la fin de chaque boucle de mesures
        * @return aucun
        * @param aucun
        *
        */
        bool Keypress();
        
};


#endif
