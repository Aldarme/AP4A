/**
 *@author Lola ROQUILLON 
 *@file Server.hpp
 *@date 28/09/2022
 *@brief Cette classe affiche les différentes donNées des capteurs dans la console puis les stockent dans leur fichier respectif
 */

#ifndef SERVER_H
#define SERVER_H

class Server{
    public :
        void fileWrite();       //sauvegarde
        void consolWrite();     //affichage
        Server();               //constructeur
        ~Server();              //destructeur
        void mesDonnee(int, int, int, int); //fonction qui recupère les données envoyées par le scheduler
        
    private :
        // varibable des valeurs des capteurs
        int  m_temp, m_press, m_light, m_hum;
};


#endif //SERVER_H