/**
 * @author Céliane ALLAIRE
 * @file Scheduler.cpp
 * @date 28/09/2022
 * @brief 
 * */

#include "Scheduler.hpp"
#include "Sensors/Humidity.cpp"
#include "Sensors/Light.cpp"
#include "Sensors/Pression.cpp"
#include "Sensors/Temperature.cpp"
#include "Packet.cpp"
#include <iostream>
#include <ctime>

using namespace std;

Packet& Scheduler::getData(Humidity& humid_p, Light& light_p, Pression& press_p, Temperature& temp_p){
    Packet packet;
    packet.setData(humid_p.getData(), light_p.getData(), press_p.getData(), temp_p.getData());
    return packet;
}

void Scheduler::startSimulation(){
    //Initialisation et création de notre horloge et nos sensors
    int time;
    Humidity humid;
    Light light;
    Pression press;
    Temperature temp;


    cout << "==== BIENVENUE DANS LA SIMULATION CAPTEURS ====" << endl;
    while (this->m_simDuration <= 0) //Boucle pour vérifier que notre valeur entrée est positive et non NULL
    {
        cout << "Veuillez entrer la durée souhaitée de la simulation [en secondes] :" << endl;
        cin >> this->m_simDuration;
    }
    while (this->m_interval <= 0)
    {
        cout << "Veuillez entrer à qu'elle fréquence vous souhaitez récuperer les informations des capteurs [en secondes] :" << endl;
        cin >> this->m_interval;
    }
    cout << "=== Lancement de la simulation ===" << endl;
    
    //Cette boucle garantié que la simulation dure le temps souhaitée
    while (this->m_chrono != this->m_simDuration + this->m_interval) //On continue uniquement la simulation si il nous reste assez de temps
    {
        Packet packet = getData(humid, light, press, temp);
        sendDataToServer(packet); //Should exit the loop if the method is unsuccessful
        
        //mettre à jour le chrono à la fin de la boucle
        this->m_chrono = time;
    }
    
}

bool Scheduler::sendDataToServer(Packet& packet_p){
    return 0;
}



