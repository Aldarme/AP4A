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
};


#endif  // SCHEDULER_H