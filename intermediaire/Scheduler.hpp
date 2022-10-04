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
    int m_interval; //Utilisé pour définir l'intervale de temps entre chaque récolte de données
    int m_simDuration; //La duration totale de la simulation
    int m_chrono; //Le temps écoulé depuis le commencement de la simulation
public:
// Definition de la forme canonique
    Scheduler():m_interval(), m_simDuration(), m_chrono(){}; //Constructeur pas défaut
    Scheduler(const Scheduler& param_s):m_interval(param_s.m_interval), m_simDuration(param_s.m_simDuration), m_chrono(param_s.m_chrono){}; //Constructeur par recopie
    Scheduler& operator=(const Scheduler& param_s); //Opérateur d'affectation
    ~Scheduler(); //Destructeur

    //Récuperer toutes les données en même temps
    Packet& getData(Humidity& humid_p, Light& light_p, Pression& press_p, Temperature& temp_p);
    void startSimulation();
    //Transmettre les données en même temps : one solution is taking all the data as parameters OR creating a new class "Packet" that holds the different data [Therefore easier to send out all the data at the same time]
    bool sendDataToServer(Packet& packet_p); //Sends data to server, returns TRUE if successful FALSE if not

    //On utilise la méthode sleep pour seulement envoyer les infos à l'intervalle voulu. Pas pertinent pour rendu final par contre!!!
};


#endif  // SCHEDULER_H