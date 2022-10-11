/** 
 * @author SCHERRER Guillaume
 * @file Server.hpp
 * @date 25/09/2022
 * @brief Cette classe a pour but de récupérer les différentes valeurs issues des capteurs, 
 * puis de les afficher sur la console de et de les écrire dans un fichier de logs commun aux détecteurs (1ere version)
 *  
*/


#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <fstream>

class Server
{
private:
    float m_Temperature, m_Humidity, m_Pressure, m_Light;

public: 

    Server();   // constructeur par défaut
    ~Server();  // destructeur
    Server(Server& server); // constructeur de recopie
    Server& operator=(const Server& server); //opérateur d'affectation 

    /** 
     * @brief Cette fonciton a pour but d'écrire les différentes données des capteurs dans les fichiers associés
     * @return rien vu que c'est un void 
     * @param aucun
    */
    void fileWrite(); 

    /** 
     * @brief Cette fonciton a pour but d'écrire les différentes données des capteurs dans la console 
     * @return rien vu que c'est un void 
     * @param aucun
    */
    void consolWrite();

    /** 
    * @brief récupère les valeurs depuis le scheduler et appele les fonctions fileWrite et consolWrite
    * @return rien car de type void
    * @param pointeur sur un tableau
    *
    */
    void UpdateValues(float*);

    /** 
    * @brief fonciton qui sert uniquement à fermer le fichier de log
    * @return rien car de type void
    * @param pointeur sur un tableau
    *
    */
    void CloseAll();

    std::fstream SensorLogFile; // fichier de logs

};

#endif //SERVER_H