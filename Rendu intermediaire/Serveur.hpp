#ifndef Serveur_hpp
#define Serveur_hpp
#include<string>
#include "Paquet.hpp"
class Serveur
{
    private :
        std::string m_nom;
    public :
        Serveur();
        Serveur(std::string nom);
        void fileWriter(Paquet paquet);
        void consoleWriter(Paquet paquet);
        void CleanFile();
};


#endif /* Serveur_hpp */