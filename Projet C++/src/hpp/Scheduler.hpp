/*
@author BENEDUCI Marie
@file  Scheduler.hpp
@date 19/09/2022
@brief  Déclaration de la Classe ayant pour objectif d'envoyer au Server les données des Sensor récupérées
*/
#include <iostream>
#include <chrono>
#include <thread>
#include <functional>

#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

class Scheduler
{
private:
    void task1(int i);
    void task2(int i);
    void task3(int i);
    void task4(int i);
    void thread_function()
{
    std::cout << "thread function\n";
}

void thread_function2()
{
    std::cout << "thread function2\n";
}

public:
    Scheduler(); // Constructeur par défaut
    ~Scheduler(); // Destructeur
    Scheduler (const Scheduler&); // Constructeur de recopie
    Scheduler &operator=(const Scheduler&); // Opérateur d'affectation
    int getSensorData(); // Fonction de récuperation des données des Sensors
};



#endif