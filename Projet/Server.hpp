/**
 * @file Server.hpp
 * @author Aurélien PETRA
 * @brief Ecrit les données d'un packet dans la console ou des fichiers textes
 * @version 0.1
 * @date 2022-10-11
 *
 * @copyright Copyright (c) 2022
 *
 */

// Define guards
#ifndef SERVER_H
#define SERVER_H

#include "Packet.hpp"
#include <iostream>
#include <fstream>
#include <ctime>

/**
 * @class server
 * @brief Ecrit les données d'un packet dans la console ou des fichiers textes
 */
class server
{
private:
    bool consoleActivation;
    bool fileActivation;

public:
    server() : consoleActivation(), fileActivation() {}
    server(const server &param_s) : consoleActivation(param_s.consoleActivation), fileActivation(param_s.fileActivation) {}
    ~server() {}
    server &operator=(const server &);

    /**
     * @brief Ecrit dans la console les valeurs comprises dans un packet
     * @param packet - packet dont les attributs seront écris
     */
    void consolWrite(const packet);

    /**
     * @brief Ecrit dans des fichiers txt les valeurs comprises dans un packet
     * @param packet - packet dont les attributs seront écris
     */
    void fileWrite(const packet);

    /**
     * @brief Permet d'initialiser des fichiers pour la méthode fileWrite, soit supprimer leur contenu et écrire un entête, soit écrire un entête à la suite des données existantes
     *
     */
    void fileReset();

    /**
     * @brief Détermine la valeur de l'attribut fileActivation
     *
     * @return server&
     */
    server &chooseFileActivation();

    /**
     * @brief Détermine la valeur de l'attribut consoleActivation
     *
     * @return server&
     */
    server &chooseConsoleActivation();
};

#endif // SERVER_H