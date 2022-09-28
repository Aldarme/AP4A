/*
@author BENEDUCI Marie
@file  Sensor.hpp
@date 19/09/2022
@brief  Classe ayant pour objectif de generer à intervalle régulier des données en int
*/

class Sensor
{
protected:
    int aleaGenVal();

public:
    int data;
    Sensor();
    ~Sensor();
    int getData();

};




