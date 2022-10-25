#include "Server.hpp"
#include <iostream>
#include <fstream>
#using namespace std

float tTemperature = 0;
float tHumidity = 0;
int tPressure = 0;
bool tLight = false;

void Server::fileWrite(int time)
{
   
    if (data.temperature != tTemperature)
    {
        
        ofstream logTemperature("Logs/logTemperature.txt", ios::app);
        if (logTemperature)
        {
            logTemperature << time << "s" << " Température   " << data.temperature << " °C" << endl;
            logTemperature.close();
            tempTemperature = data.temperature;
        }
        else cout << "Cannot open" << endl;
    }


    if (logLight)
    {
        ofstream logLight("Logs/logLight.txt", ios::app);
        if (data.light == 0)
        {
            logLight << time << "s" << " | Light off" << endl;
            logLight.close();
            tLight = donnee.light;
        } else
        {
            logLight << time << "s" << " | Light on" << endl;
            logLight.close();
            tLight = date.light;
        }
     } else cout << "Cannot open" << endl;


    if (date.humidity != tempHumidity)
    {
        ofstream logHumidity("Logs/logHumidity.txt", ios::app);
        if (logHumidity)
        {
            logHumidity << time << "s" << " | Humidité- " << data.humidity << " g/m^3" <<endl;
            logHumidity.close();
            tHumidity = data.humidity;
        }
        else std::cout << "Cannot open" << endl;
    }

    if (date.pressure != tempPressure)
    {
        ofstream logPressure("Logs/logPressure.txt", ios::app);
        if (logPressure)
        {
            logPressure << time << "s" << " | Pression- " << data.pressure << " kPa" <<endl;
            logPressure.close();
            tPressure = data.pressure;
        }
        else cout << "Cannot open" << endl;
    }

    
           
};

void Server::consolWrite(int time)
{
    cout << time << "s" <<
            " T is" << data.temperature <<endl
            " H is" << data.humidity <<endl
            " P is" << data.pressure <<ednl
            " L is" << data.light << endl;
};
