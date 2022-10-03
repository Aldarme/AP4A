/*
@author BENEDUCI Marie
@file  Server.hpp
@date 19/09/2022
@brief  Classe ayant pour objectif de recevoir les données des capteurs, les stocker dans un fichier de log (rendu intermediaire) et les afficher dans la console
*/


class Server
{
private:
    void fileWrite(char nom[], int value, char unit[]) ; // fonction d'écriture des données reçues pour chaques capteurs dans un fichier log (pour le rendu intermédiaire)
    void consolWrite(char nom[], int value, char unit[]); // fonction d'écriture des données reçues pour chaques capteurs dans le terminal
    

public:
    Server(); // Constructeur par défaut
    ~Server(); // Destructeur
    Server (const Server&); // Constructeur de recopie
    Server &operator=(const Server&); // Opérateur d'affectation
    void newStatement(int relevé); // fonction d'affichage du numéro de relevé des données des Sensors.
    void fileAndConsoleWrite(char nom[], int value, char unit[]); // Fonction regroupant l'affichage dans la console et le stockage dans le fichier log
    
};

