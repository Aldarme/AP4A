/*
@author BENEDUCI Marie
@file  Server.hpp
@date 19/09/2022
@brief  Classe ayant pour objectif de recevoir les données des capteurs et de les visualiser dans la console et de les stocker dans des fichiers de logs
*/


class Server
{
private:
    void fileWrite(char nom[], int value, char unit[]) ;
    void consolWrite(char nom[], int value, char unit[]);
    

public:
    void newStatement(int relevé);
    void fileAndConsoleWrite(char nom[], int value, char unit[]);
    Server();
    ~Server();
    
};

