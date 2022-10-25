/**
 * @author Arthur
 * @file Server.cpp
 * @date 03/10/22
 * @brief Implémentation de la classe Server
 */

#include "Server.hpp"

float tempTemperature = 0;
float tempHumidity = 0;
int tempPressure = 0;
bool tempLight = false;

void Server::fileWrite(int time)
{
    //Comme il y a un envoie chaque seconde, vérifie que la valeur change avant de l'écrire dans le fichier
    if (donnee.temperature != tempTemperature)
    {
        //Defini le fichier à utiliser pour entrer les valeurs dans logDonnées, ios::app permets d'écrire à la suite de ce qui est déjà écrit
        std::ofstream logTemperature("Logs/logTemperature.txt", std::ios::app);
        if (logTemperature)
        {
            logTemperature << time << "s" << " | Température- " << donnee.temperature << " °C" << std::endl;
            logTemperature.close();
            tempTemperature = donnee.temperature;
        }
        else std::cout << "Impossible d'ouvrir le fichier" << std::endl;
    }

    if (donnee.humidity != tempHumidity)
    {
        std::ofstream logHumidity("Logs/logHumidity.txt", std::ios::app);
        if (logHumidity)
        {
            logHumidity << time << "s" << " | Humidité- " << donnee.humidity << " g/m^3" << std::endl;
            logHumidity.close();
            tempHumidity = donnee.humidity;
        }
        else std::cout << "Impossible d'ouvrir le fichier" << std::endl;
    }

    if (donnee.pressure != tempPressure)
    {
        std::ofstream logPressure("Logs/logPressure.txt", std::ios::app);
        if (logPressure)
        {
            logPressure << time << "s" << " | Pression- " << donnee.pressure << " kPa" << std::endl;
            logPressure.close();
            tempPressure = donnee.pressure;
        }
        else std::cout << "Impossible d'ouvrir le fichier" << std::endl;
    }

    std::ofstream logLight("Logs/logLight.txt", std::ios::app);
    if (logLight)
    {
        if (donnee.light == 0)
        {
            logLight << time << "s" << " | Light- off" << std::endl;
            logLight.close();
            tempLight = donnee.light;
        } else
        {
            logLight << time << "s" << " | Light- on" << std::endl;
            logLight.close();
            tempLight = donnee.light;
        }
    } else std::cout << "Impossible d'ouvrir le fichier" << std::endl;       
};

void Server::consolWrite(int time)
{
    std::cout << time << "s" <<
            " | T- " << donnee.temperature <<
            ", H- " << donnee.humidity <<
            ", P- " << donnee.pressure <<
            ", L- " << donnee.light << std::endl;
};

void Server::resetFile()
{
    //Defini le fichier à utiliser pour entrer les valeurs dans logDonnées, ios::trunc permets de supprimer le contenu du fichier
    std::ofstream logTemperature("Logs/logTemperature.txt", std::ios::trunc);
    std::ofstream logHumidity("Logs/logHumidity.txt", std::ios::trunc);
    std::ofstream logPressure("Logs/logPressure.txt", std::ios::trunc);
    std::ofstream logLight("Logs/logLight.txt", std::ios::trunc);
}
