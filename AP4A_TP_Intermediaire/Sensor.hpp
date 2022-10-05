/**
 *@author Lola ROQUILLON 
 *@file Sensor.hpp
 *@date 28/09/2022
 *@brief Cette classe crée les valeurs des capteurs de manière aléatoire et les envoi au scheduler
 */

#ifndef SENSOR_H
#define SENSOR_H

class Sensor
{
    public :
        Sensor();                   //constructeur par default
        ~Sensor();                  //destructeur
        int getData(int, int);      //fonction qui envoi les données au scheduler
        
    protected :
        int aleaGenVal(int, int);   //fonction qui génére aléatoirement les données des capteurs
};

#endif //SENSOR_H
