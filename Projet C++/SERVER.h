/**
 * @author YUHUIFEI
 * @file SERVER.h
 * @date 15/10/2022
 * @brief La classe Server Classe permettant de recevoir les donn¨¦es des capteurs et de les ¨¦crire dans le journal.
 */
#ifndef SERVER_HPP
#define SERVER_HPP
#include"SENSOR.h"
#include <string>
#include <fstream>
#include "PRESSION.h"
#include "HUMIDITY.h"
#include "LIGHT.h"
#include "TEMPERATURE.h"

using namespace std;


class Server
{
public:
	Server(){}
	~Server(){}
    template<class T>
    void consoleWrite(const Sensor<T>& param_sensor)
    {
        cout << param_sensor;
    }
    // Ecrire les donn¨¦es du capteur dans un fichier
    template <class T>
	void fileWrite(const Temperature & param_sensor)
	{
        ofstream myFile("C:\Users\·ÑØ¹êÍ\AP4A\Projet C++\data\data_temperature.csv", ios::app); 
        if (myFile)
        {
            myFile << param_sensor << endl;//Ecrire les donn¨¦es du capteur dans un fichier
            myFile.close();
        }
        else
        {
            cout << "ERROR,open failed!" << endl;
        }
	}
    // Ecrire les donn¨¦es du capteur dans un fichier
    template <class T>
    void fileWrite(const Humidity& param_sensor)
    {
        ofstream myFile("C:\Users\·ÑØ¹êÍ\AP4A\Projet C++\data\data_humidity.csv", ios::app);
        if (myFile)
        {
            myFile << param_sensor << endl;
            myFile.close();
        }
        else
        {
            cout << "ERROR,open failed!" << endl;
        }
    }
    // Ecrire les donn¨¦es du capteur dans un fichier
    template <class T>
    void fileWrite(const Light& param_sensor)
    {
        ofstream myFile("C:\Users\·ÑØ¹êÍ\AP4A\Projet C++\data\data_light.csv", ios::app);
        if (myFile)
        {
            myFile << param_sensor << endl;
            myFile.close();
        }
        else
        {
            cout << "ERROR,open failed!" << endl;
        }
    }
    // Ecrire les donn¨¦es du capteur dans un fichier
    template <class T>
    void fileWrite(const Pression& param_sensor)
    {
        ofstream myFile("C:\Users\·ÑØ¹êÍ\AP4A\Projet C++\data\data_pression.csv", ios::app);
        if (myFile)
        {
            myFile << param_sensor << endl;
            myFile.close();
        }
        else
        {
            cout << "ERROR,open failed!" << endl;
        }
    }

};





#endif//SERVER.H