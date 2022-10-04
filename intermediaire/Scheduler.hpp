/**
 * @author Céliane ALLAIRE
 * @file Scheduler.hpp
 * @date 28/09/2022
 * @brief 
 * */

//
//Define guards
#ifndef SCHEDULER_H
#define SCHEDULER_H


/**
 * @class Scheduler
 * @brief classe scheduler. Gère l'envoi régulier des données des différents sensors jusqu'au server.
 */
class Scheduler
{
private:
    float m_interval; //Utilisé pour définir l'intervale de temps entre chaque récolte de données
public:
// Definition de la forme canonique
    Scheduler():m_interval(){}; //Constructeur pas défaut
    Scheduler(const Scheduler& param_s):m_interval(param_s.m_interval){}; //Constructeur par recopie
    Scheduler& operator=(const Scheduler& param_s); //Opérateur d'affectation
    ~Scheduler(); //Destructeur

    //Récuperer toutes les données en même temps
    void getData();
    void startSimulation(Humidity& humid_p, Light& light_p, Pression& press_p, Temperature& temp_p);
    //Transmettre les données en même temps : one solution is taking all the data as parameters OR creating a new class "Packet" that holds the different data [Therefore easier to send out all the data at the same time]
    bool sendDataToServer(Humidity& humid_p, Light& light_p, Pression& press_p, Temperature& temp_p); //Sends data to server, returns TRUE if successful FALSE if not

    //Fonction Attendre() Pas pertinent pour rendu final
};


#endif  // SCHEDULER_H