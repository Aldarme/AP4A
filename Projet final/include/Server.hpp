/*!
 * @author  Cuenot Benoit  
 * @file    Server.hpp
 * @date    25/10/2022  
 * @brief   Cette classe est le Server.hpp du projet, elle sert à récuperer les données des 4 capteurs 
 *          afin de les afficher ou non dans le terminal ou sur les fichiers de logs
 */

#ifndef SERVER_HPP_INCLUDED
#define SERVER_HPP_INCLUDED
#include <fstream>

class Server{
    
        private :

                /*!< Les booléens responsables de l'affichag et du log des données*/
                bool m_booleenAffichage;
                bool m_booleenLog;

        public : 

                Server();
                ~Server();
                Server(const Server& objServer_p);
                Server(bool booleenAffichage_p, bool booleenLog_p);

                void SetConsole(bool booleenAffichage_p); /*!< Fonction pour décider d'aficher la console*/
                void SetLog(bool booleenLog_p); /*!< Fonction pour décider d'écrire les données dans les logs*/

                template <typename T>
                void fileWrite(T donneecapteur_p, string nomFichier_p); /*!< Ecriture fichiers, cette une fonction template afin de pouvoir récupérer chaque type de données : bool, int, etc*/
                template <typename T>
                void consolWrite(T donneecapteur_p); /*!< Affichage console*/
};

#endif // SERVER_HPP_INCLUDED