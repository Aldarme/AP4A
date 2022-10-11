/*!
 * @author  Cuenot Benoit  
 * @file    Server.hpp
 * @date    10/10/2022  
 * @brief   Cette classe est le Server du projet, elle sert à récuperer les données des 4 capteurs 
 *          afin de les afficher ou non dans le terminal ou sur les fichiers de logs
 */

#ifndef SERVER_HPP_INCLUDED
#define SERVER_HPP_INCLUDED
#include "Sensor.hpp"
#include <fstream>



class Server{

    private : 

            /*!< Les 4 valeurs de capteurs sont stockées dans ces variables à l'aide de la méthode dataRcv()*/

            int m_donneeTemperature;
            int m_donneeHumidity;       
            int m_donneePression;
            int m_donneeLight;
        
    public : 

            Server();
            Server(int donneeTemperature_p, int donneeHumidity_p, int donneePression_p, int donneeLight_p);
            Server(const Server& objServer_p);
            ~Server();

            void dataRcv(int ValeurTemperature_p, int ValeurHumidity_p, int ValeurPression_p, int ValeurLight_p); /*!< Récupération des valeurs de capteurs depuis le Scheduler*/
            void fileWrite(bool booleenLog_p); /*!< Ecriture fichiers*/
            void consolWrite(bool booleenAffichage_p); /*!< Affichage console*/
};

#endif // SERVER_HPP_INCLUDED