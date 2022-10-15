#include "../hpp/Scheduler.hpp"
#include "../hpp/Temperature.hpp"
#include "../hpp/Light.hpp"
#include "../hpp/Humidity.hpp"
#include "../hpp/Pression.hpp"

#include<cstdio>
#include<iostream>



int main()

{
    Scheduler sch; //création d'un objet Scheduleur
    sch.getSensorData(); //Lancement de la fonction permettant de run tout le programme en recuperant les données envoyées des sensors et les envoyant au Server pour l'affichage et le stockage
    return 0;

    // Temperature *temperature;
    // temperature = new Temperature;

    // Light *light;
    // light = new Light;

    // Humidity *humidity;
    // humidity = new Humidity;

    // Pression *pression;
    // pression = new Pression;

    
    // std::cout << temperature->getData() << std::endl;
    // std::cout << light->getData() << std::endl;
    // std::cout << humidity->getData() << std::endl;
    // std::cout << pression->getData() << std::endl;

    
}

