#include "../hpp/Scheduler.hpp"

#include<cstdio>
#include<iostream>



int main()

{
    Scheduler sch; //création d'un objet Scheduleur
    sch.getSensorData(); //Lancement de la fonction permettant de run tout le programme en recuperant les données envoyées des sensors et les envoyant au Server pour l'affichage et le stockage
    return 0;

}

