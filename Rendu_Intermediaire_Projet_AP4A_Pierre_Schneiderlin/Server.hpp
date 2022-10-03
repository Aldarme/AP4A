/**
 * @author Pierre Schneiderlin
 * @file Server.hpp
 * @date 22/09/2022
 * @brief header contenant la déclaration de la classe Server qui permet d'écrire les données qu'elle reçoit (via un objet de classe Scheduler)
 * dans la console et/ou dans des fichiers en fonction de la valeur de ses deux attributs.
 */

#ifndef SERVER_HPP
#define SERVER_HPP

#include "main.hpp"

/**
 * @class Server
 * @brief Classe permettant d'écrire les données qu'elle reçoit (via un objet de classe Scheduler) dans la console
 * et/ou dans des fichiers en fonction de la valeur de ses deux attributs.
 */
class Server
{

private:

    bool m_consolActivation; /// Indique si l'objet doit écrire les données dans la console ou non
    bool m_logActivation; /// Indique si l'objet doit écrire les données dans les fichiers ou non

public:

    //////////////////////////////////// FORME CANONIQUE ////////////////////////////////////

    Server():m_consolActivation(),m_logActivation(){}
    Server(bool c, bool l):m_consolActivation(c),m_logActivation(l){}
    Server(const Server& s):m_consolActivation(s.m_consolActivation),m_logActivation(s.m_logActivation){}
    ~Server(){}

    /////////////////////////////////////////////////////////////////////////////////////////

    /**
     * Méthode définissant la surcharge de l'opérateur d'affectation "="
     * @param s - l'objet de classe Server dont on souhaite copier les attributs dans l'objet appelé
     * @return l'objet appelé modifié
     */
    Server& operator=(const Server& s);

    /**
     * Méthode définissant la surcharge de l'opérateur de sortie <<
     * @param os - le flux de sortie par lequel on souhaite diriger l'objet s
     * @param s - l'objet de classe Server que l'on souhaite diriger vers le flux de sortie os
     * @return le flux de sortie dans lequel se trouve l'objet de classe Server tel qu'on souhaite qu'il soit affiché
     */
    friend std::ostream& operator<<(std::ostream& os, Server& s);

    /**
     * Méthode permettant d'accéder à l'attribut m_consolActivation de l'objet de classe Server
     * @return la valeur de l'attribut booléen m_consolActivation
     */
    bool getConsolActivation() const;

    /**
     * Méthode permettant d'accéder à l'attribut m_logActivation de l'objet de classe Server
     * @return la valeur de l'attribut booléen m_logActivation
     */
    bool getLogActivation() const;

    /**
     * Méthode permettant de modifier l'attribut m_consolActivation de l'objet de classe Server
     * @param setConsol - la valeur booléenne à affecter à l'attribut m_consolActivation
     */
    void setConsolActivation(bool setConsol);

    /**
     * Méthode permettant de modifier l'attribut m_logActivation de l'objet de classe Server
     * @param setLog - la valeur booléenne à affecter à l'attribut m_logActivation
     */
    void setLogActivation(bool setLog);

    /**
     * Méthode permettant d'écrire un flottant dans une ligne d'un fichier
     * @param nomFichier - le nom du fichier dans lequel on souhaite écrire le flottant
     * @param data - le flottant que l'on souhaite écrire dans le fichier
     */
    void fileWrite(const std::string& nomFichier, float data);

    /**
     * Méthode permettant d'écrire une donnée flottante et son unité dans la console
     * @param dataUnit - l'unité
     * @param data - le flottant à écrire dans la console
     */
    void consoleWrite(const std::string& dataUnit, float data);
};

#endif //SERVER_HPP
