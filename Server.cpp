#include "Server.hpp"
#include <iostream>

Server::Server() 
{
}

void Server::consoleWrite(std::string typeCapteur, type value, std::string typeVal)
{
    time_t now = time(nullptr);
    std::cout << ctime(&now) << " Capteur " << typeCapteur << " = ";
    if(typeVal == "int")
    {
        std::cout << value.valInt << std::endl;
    } else if(typeVal == "bool")
    {
        std::cout << value.valBool << std::endl;
    } else if(typeVal == "float")
    {
        std::cout << value.valFloat << std::endl;
    }
}

void Server::fileWrite(std::string typeCapteur, type value, std::string typeVal)
{
/*les valeurs dans les fichiers txt ne seront pas effacées, les nouvelles valeurs seront à la suite des anciennes pour garder un historique de ces dernières*/
    time_t now = time(nullptr);
    std::ofstream file;

    file.open("log_"+typeCapteur+".txt", std::ios::app); // append
    file << ctime(&now) << " DATA " << typeCapteur << " = ";

/*pour le rendu intermédiaire, les "bool" et les "float" ne sont pas utilisés*/
    if(typeVal == "int")
    {
        file << value.valInt << "\r\n";
    } else if(typeVal == "bool")
    {
        file << value.valBool << "\r\n";
    } else if(typeVal == "float")
    {
        file << value.valFloat << "\r\n";
    }
    file.close();
}
