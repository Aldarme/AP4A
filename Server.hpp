/**
 * @author Planchin Arnaud
 * @file Server.hpp
 * @date 03/10/2022
 * @brief 
 */

#ifndef SERVER_H
#define SERVER_H

#include <iostream>


class Server
{
public:

    //Défintion de la forme Canonique: 
    Server(){};


    /**
     * @brief écrire dans le fichier texte la valeur prise
     * @return Rien
     * @param s_variable - la variable à mémoriser dans le fichier texte
     */
    void fileWrite(int s_variable);

    /**
     * @brief écrire dans la console la valeur prise
     * @return Rien 
     * @param s_variable - variable à écrire dans la console
     */
    void consolWrite(int s_variable);

};



#endif // SERVER_H