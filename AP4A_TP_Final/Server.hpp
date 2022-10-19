/**
 *@author Lola ROQUILLON 
 *@file Server.hpp
 *@date 28/09/2022
 *@brief Cette classe affiche les différentes données des capteurs dans la console puis les stockent dans leur fichier respectif
 */

#ifndef SERVER_H
#define SERVER_H
#include <string>

//regroupement de valeurs des capteurs
struct Sac_struct
{
    std::string s_temp;
    std::string s_hum;
    std::string s_press;
    std::string s_light;
};

class Server{
    public :
        //forme canonique
        Server()=default;                           //constructeur
        virtual ~Server()=default;                  //destructeur
        Server(const Server& s)=default;            //constructeur par recopie
        Server& operator=(const Server& s)=default; //operateur d'affectation

        void fileWrite(Sac_struct sac);             //sauvegarde
        void consolWrite(Sac_struct sac);           //affichage    
};

#endif //SERVER_H