/**
 * @author Céliane ALLAIRE
 * @file Server.hpp
 * @date 28/09/2022
 * @brief 
 * */

//
//Define guards
#ifndef SERVER_H
#define SERVER_H


/**
 * @class Server
 * @brief classe server. Gère la réception et l'enregistrement des données des différents capteurs dans la console et un fichier
 */
class Server
{
private:
    bool m_consolActivation; 
    bool m_logActivation; 
    void fileWrite(Packet& data_p); //écrit les résultat de nos sensors dans le fichier commun (pour rendu intermédiaire)
    void consolWrite(Packet& data_p); //écrit les résultats de nos sensors dans la console
public:
// Definition de la forme canonique
    Server():m_consolActivation(), m_logActivation(){}; //Constructeur pas défaut
    Server(const Server& param_s):m_consolActivation(param_s.m_consolActivation), m_logActivation(param_s.m_logActivation){}; //Constructeur par recopie
    Server& operator=(const Server& param_s); //Opérateur d'affectation
    ~Server(); //Destructeur

};


#endif  // SERVER_H