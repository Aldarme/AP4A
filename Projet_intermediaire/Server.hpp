/**
 * @author Cameron ROCHEBILLARD
 * @file Server.hpp
 * @date 27/09/2022
 * @brief permet de recevoir les donnees provenants des capteur 
 */

 //
 //Define guards 
 #ifndef SERVER_H
 #define SERVER_H

/**
 * @class Server
 */

class Server
{
    private :
        int Donnes;
    public :
        void fileWrite(int, int);
        void consolWrite(int);
};

#endif //SERVER_H