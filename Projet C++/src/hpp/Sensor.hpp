/*
@author BENEDUCI Marie
@file  Sensor.hpp
@date 19/09/2022
@brief  Classe ayant pour objectif de generer à intervalle régulier des données en int
*/


class Sensor
{
protected:
    int aleaGenVal(); // Fonction de generation de nombre aléatoire entre 1 et 10

public:
    int data; 
    Sensor(); // Constructeur par défaut
    ~Sensor(); // Destructeur
    Sensor (const Sensor&); // Constructeur de recopie
    Sensor &operator=(const Sensor&); // Opérateur d'affectation
    int getData(); // Fonction permettant de récuperer la donnée à envoyer

};




