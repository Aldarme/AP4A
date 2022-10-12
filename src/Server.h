/*
 * @author raphael_perrin
 * @file Server.h
 * @date 05/10/2022
 * @brief Classe Server ayant pour objectif d'afficher l'état de chaque sensor dans la console ou dans un fichier logs
 */

#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Sensor.h"

class Server
{

private :
    bool m_consoleActivation;
    bool m_logActivation;

public:
    // Définition de la forme canonique
    Server();
    ~Server(){}
    Server(const Server& server_p);
    Server& operator=(const Server& server_p);

private :
    /*
    * @brief Méthode écrivant les données des sensors dans la console
    * @return void
    * @param Sensor& sensor
    */
    template <typename T> void consoleWrite(Sensor<T>& sensor_p)
    {
        std::cout << sensor_p.getSpec(0) << " : " << sensor_p.getData() << " " << sensor_p.getSpec(1) << std::endl;
    }

    /*
    * @brief Méthode écrivant les données des sensors dans un fichier logs
    * @return void
    * @param Sensor& sensor
    */
    template <typename T> void fileWrite(Sensor<T>& sensor_p)
    {
        std::string path = "C:/Users/rapha/AP4A/src/";
        path += sensor_p.getSpec(0);
        path += ".txt";
        std::string filename(path);
        FILE *o_file = fopen(filename.c_str(), "a");
        if (o_file)
        {
            std::string chaine;
            chaine += sensor_p.getSpec(0);
            chaine += " ";    
            chaine += std::to_string(sensor_p.getData());
            chaine += " ";
            chaine += sensor_p.getSpec(1);
            chaine += "\n";
            fwrite(chaine.c_str(), 1, chaine.size(), o_file);
        }
        fclose(o_file);
    }

    friend class Scheduler;
};

#endif // SERVER_H