/**
* @author SZATKOWSKI Maxime
* @file Server.hpp
* @date 15/09/2022
* @brief fichier source contenant l'implémentation des méthodes de la classe Server
*/

#include "Server.hpp"

using namespace std;

using std::fstream;

Server::Server()
{
    consoleActivation = 0;
    logActivation = 0;
}

Server::Server(const Server& s) 
{
    consoleActivation = s.consoleActivation;
    logActivation = s.logActivation;
}

Server& Server::operator=(const Server& s) 
{
    consoleActivation = s.consoleActivation;
    logActivation = s.logActivation;
 
    return *this;
}

void Server::consoleWrite(const Packet param_p) 
{
    cout << "Luminosity  : " << param_p.m_light << endl;                //Ecriture de la valeur de luminosité dans la console
    cout << "Pressure    : " << param_p.m_press << " hPa" << endl;      //Ecriture de la valeur de Pression dans la console
    cout << "Temperature : " << param_p.m_temp << " c" << endl;         //Ecriture de la valeur de Température dans la console
    cout << "Humidity    : " << param_p.m_humid << " %" << endl;        //Ecriture de la valeur d'Humidité dans la console
}


void Server::fileWrite(const Packet param_p)
{
    ofstream file("Temperature_record.txt", ios::out, ios::app);    //Creation d'un fichier log pour le capteur tmpererature à l'emplacement dans lequel le projet est sauvegardé
                    
    if (file)
    {  
        file << " Temperature : " << param_p.m_temp << " c" << endl;
        file.close();                                               //fermeture du fichier
    }
    else
    {
        cerr << "Cannot open file" << endl;                         //Message d'erreur dans la console si le fichier ne s'ouvre pas
    }

    ofstream file1("Pressure_record.txt", ios::out, ios::app);    //Creation d'un fichier log pour le capteur Pression à l'emplacement dans lequel le projet est sauvegardé

    if (file1)
    {
        file1 << " Pressure    : " << param_p.m_press << " hPa" << endl;
        file1.close();                                           //fermeture du fichier
    }
    else
    {
        cerr << "Cannot open file" << endl;                      //Message d'erreur dans la console si le fichier ne s'ouvre pas
    }

    ofstream file2("Luminosity_record.txt", ios::out, ios::app);    //Creation d'un fichier log pour le capteur de luminosité à l'emplacement dans lequel le projet est sauvegardé

    if (file2)
    {
        file << " Luminosity  : " << param_p.m_light << endl;
        file2.close();                                              //fermeture du fichier
    }
    else
    {
        cerr << "Cannot open file" << endl;                         //Message d'erreur dans la console si le fichier ne s'ouvre pas
    }

    ofstream file3("Humidity_record.txt", ios::out, ios::app);    //Creation d'un fichier log pour le capteur Pression à l'emplacement dans lequel le projet est sauvegardé

    if (file3)
    {
        file3 << " Humidity    : " << param_p.m_humid << " %" << endl;
        file3.close();                                             //fermeture du fichier        
    }
    else
    {
        cerr << "Cannot open file" << endl;                         //Message d'erreur dans la console si le fichier ne s'ouvre pas
    }
}

Server& Server::setConsole()
{
    char c;
    bool b;
    cout << "Voulez vous ecrire dans la console (O/N)" << endl;
    cin >> c;
    if (c == 'O') {
        b = true;
    }
    else {
        b = false;
    }
    consoleActivation = b;

    return*this;

}

Server& Server::setLogActivation()
{
    char c;
    bool b;
    cout << "Voulez vous ecrire dans le fichier log (O/N)" << endl;
    cin >> c;
    if (c == 'O') {
        b = true;
    }
    else {
        b = false;
    }
    logActivation = b;

    return*this;

}

bool Server::getConsoleActiv() 
{
    return consoleActivation;
}

bool Server::getLogActiv()
{
    return logActivation;
}