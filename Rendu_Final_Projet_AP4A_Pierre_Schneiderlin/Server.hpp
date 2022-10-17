/**
 * @author Pierre Schneiderlin
 * @file Server.hpp
 * @date 22/09/2022
 * @brief header contenant la déclaration de la classe Server qui permet d'écrire les données qu'elle reçoit (via un objet de classe Scheduler)
 * dans la console et/ou dans des fichiers en fonction de la valeur de ses deux attributs. Ce fichier contient également l'implémentation de deux
 * méthodes templates de la classe Server, qui ne peuvent donc pas être implémentées dans le .cpp
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

    /**
     * Constructeur par défaut
     */
    Server():m_consolActivation(),m_logActivation(){}

    /**
     * Constructeur par recopie
     * @param s - l'objet de classe Server à recopier
     */
    Server(const Server& s):m_consolActivation(s.m_consolActivation),m_logActivation(s.m_logActivation){}

    /**
     * Destructeur
     */
    virtual ~Server()= default;

    /**
     * Opérateur d'affectation "="
     * @param s - l'objet de classe Server dont on souhaite copier les attributs dans l'objet appelé
     * @return l'objet appelé modifié
     */
    Server& operator=(const Server& s);


    /////////////////////////////////////////////////////////////////////////////////////////



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
     * Méthode permettant de demander à l'utilisateur de saisir les valeurs des attributs de l'objet
     */
    void askValueAttribute();

    /**
     * Méthode permettant d'écrire une donnée dans une ligne d'un fichier
     * @param nomFichier - le nom du fichier dans lequel on souhaite écrire le flottant
     * @param data - la donnée que l'on souhaite écrire dans le fichier
     */
    template <class T>
    void fileWrite(const std::string& nomFichier, T data);

    /**
     * Méthode permettant d'écrire une donnée suivie de son type dans la console
     * @param type - le type de la donnée
     * @param data - la valeur à écrire dans la console
     */
    template <class T>
    void consoleWrite(const std::string& type, T data);
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                        ///IMPLÉMENTATION DES MÉTHODES TEMPLATES DE LA CLASSE SERVER///
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Server::fileWrite(const std::string& nomFichier, T data)
{
    if(m_logActivation)
    {
        std::ofstream FichierStockage(nomFichier.c_str(), std::ios::app);  // Ouverture du fichier

        if (FichierStockage) {
            FichierStockage << data
                            << std::endl;                       // On écrit la donnée dans le fichier s'il n'y a pas d'erreur à l'ouverture
        } else {
            std::cout << "ERREUR : Ouverture du fichier impossible."
                      << std::endl;   // Sinon, on n'écrit pas la donnée, et on averti l'utilisateur qu'il y a eu une erreur
        }
    }
}

template <class T>
void Server::consoleWrite(const std::string& type, T data)
{
    std::string dataUnit;

    if(type==TEMP)                           // En fonction du type de la variable data, on affecte à dataUnit l'unité correspondant à ce type...
    {
        dataUnit=UNITE_TEMP;
    }
    if(type==HUM)
    {
        dataUnit=UNITE_HUM;                  //...dans le but de pouvoir l'indiquer dans l'affichage dans la console
    }
    if(type==LI)
    {
        dataUnit=UNITE_LI;
    }
    if(type==PRE)
    {
        dataUnit=UNITE_PRE;
    }
                                // Le contrôle du choix de l'utilisateur dans l'affichage ou non dans la console est maintenant réalisé
    if(m_consolActivation)      // dans cette méthode (par rapport au rendu intermédiaire). Cela évite de répéter la condition lors de son appel,
    {                           // et cela est bien plus propre de contrôler ici, car cela fait partie de la classe Server
        std::cout << type << " : "<< data << " " <<dataUnit<<std::endl;   // On écrit dans la console la donnée suivie de son unité et précédée de son type
    }
}

#endif //SERVER_HPP
