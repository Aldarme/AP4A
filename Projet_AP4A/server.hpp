/**
 * @author Jules Ferlin
 * @file server.hpp
 * @date 03/10/2022
 * @brief Fichier header contenant la définition de la classe Server
 */


// Define Guards
#ifndef PROJET_AP4A_SERVER_HPP
#define PROJET_AP4A_SERVER_HPP

#include <iostream>
#include <fstream>
#include "Sensors/Humidite.hpp"
#include "Sensors/Light.hpp"
#include "Sensors/Pression.hpp"
#include "Sensors/Temperature.hpp"


/**
 * @class Server
 * @brief Classe permettant de faire la liaison entre le serveur et les capteurs
 */
class Server
{
private:
    bool m_consolActivation;    ///< Attribut permetant de vérifier l'écriture des informations dans la console
    bool m_logActivation;       ///< Attribut permetant de vérifier l'écriture des informations dans les fichiers logs
public:
    // Définition de la forme canonique
    Server();
    Server(const Server& param_server);
    ~Server();
    Server& operator=(const Server& param_server);

    /**
     *
     * @tparam T
     * @param param_name
     * @param param_value
     * @param param_unite
     */
    template<typename T>
    void fileWrite(const std::string& param_name,T param_value,const std::string& param_unite);

    /**
     *
     * @tparam T
     * @param param_name
     * @param param_value
     * @param param_unite
     */
    template<typename T>
    void consolWrite(const std::string& param_name,T param_value,const std::string& param_unite);


};

template<typename T>
void Server::fileWrite(const std::string& param_name, const T param_value, const std::string& param_unite)
{
    std::ofstream file(param_name + ".txt", std::ios::app);
    file << param_name << " " << param_value << " " << param_unite << std::endl;
    file.close();
}

template<typename T>
void Server::consolWrite(const std::string& param_name, const T param_value, const std::string& param_unite)
{
    std::cout << param_name << " " << param_value << " " << param_unite << std::endl;
}


#endif //PROJET_AP4A_SERVER_HPP
