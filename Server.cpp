#include "Server.hpp"
#include <iostream>

Server::Server(){} 

void Server::question()
/*Tant que l'utilisateur écrit autre chose de "yes" ou "no" la question est reposée*/
{
    std::string console;
    std::string log;
    while (!(log == "yes" || log == "no")) //tant que log n'est pas yes ou log n'est pas no

    /*puisque bool a un type de base on ne peut pas faire la condition avec un bool car il n'entre pas dans la boucle.
    En utilisant do...while il entre dans la boucle mais ne se répète pas car par défaut log=false donc on utilise un string*/
    {
        std::cout << "Logs? (yes/no)" << std::endl;
        std::cin >> log;
        if(log=="yes") m_log = true;
        if(log=="no") m_log = false;
    }
    while (!(console == "yes" || console == "no"))
    {
        std::cout <<"console? (yes/no)" << std::endl;
        std::cin >>console;
        if(console=="yes") m_console = true;
        if(console=="no") m_console = false;
    }
}

void Server::consoleWrite(std::string typeCapteur_p, captor_data value_p) //fonction qui permet d'écrire les données des capteurs dans la console
{
    if (typeCapteur_p == "Humidity") //si on est sur le capteur d'humidité alors on va chercher la valeur du capteur et on l'écrit dans la console
    {
        time_t now = time(nullptr);//permet de donner l'heure exacte
        std::cout << ctime(&now) << " Humidity = "<< value_p.humidityValue <<std::endl;
    }
    if (typeCapteur_p == "Light")//id pour les autres capteurs
    {
        time_t now = time(nullptr);
        std::cout << ctime(&now) << " Light = "<< value_p.lightValue <<std::endl;
    }
    if (typeCapteur_p == "Pressure")
    {
        time_t now = time(nullptr);
        std::cout << ctime(&now) << " Pressure = "<< value_p.pressureValue <<std::endl;
    }
    if (typeCapteur_p == "Temperature")
    {
        time_t now = time(nullptr);
        std::cout << ctime(&now) << " Temperature = "<< value_p.tempValue <<std::endl;
    }
}


void Server::fileWrite(std::string typeCapteur_p, captor_data value_p)
 /*fonction qui permet de créer/d'ouvrir les logs et d'écrire les valeurs des capteurs à l'intérieur
 on aura décidé que les valeurs se mettent a la suite dans les logs a chaque appel du programme pour garder un historique des valeurs*/
{
    time_t now = time(nullptr);
    std::ofstream file;

    file.open("log_"+typeCapteur_p+".txt", std::ios::app);
    file << ctime(&now) << " Captor " << typeCapteur_p << " : ";


    if(typeCapteur_p == "Humidity") //pour chaque capteur on écrit sa valeur dans son fichier log associé
    {
        file <<"percentage humidity: " << value_p.humidityValue << "%" << "\r\n";
    }
    if(typeCapteur_p== "Light")
    {
        file <<"Light: " << value_p.lightValue << "\r\n";
    } 
    if(typeCapteur_p == "Pressure")
    {
        file << "Pressure value: " << value_p.pressureValue << "Hpa" << "\r\n";
    } 
    if(typeCapteur_p == "Temperature")
    {
        file << "valeur Temperature: " << value_p.tempValue << "°C"<< "\r\n";
    }
    file.close();
}