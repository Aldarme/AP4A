/**
 * @file Server.cpp
 * @author Aurélien PETRA
 * @brief Ecrit les données d'un packet dans la console ou des fichiers textes
 * @version 0.1
 * @date 2022-10-11
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Server.hpp"
using namespace std;

server& server::operator=(const server& param_s)
{
    consoleActivation = param_s.consoleActivation;
    fileActivation = param_s.fileActivation;
    return *this;
}

void server::consolWrite(const packet param_p)
{
    if (consoleActivation)
    {
        time_t current = time(0);
        tm *ltm = localtime(&current);
        cout << ltm->tm_hour << ':' << ltm->tm_min << ':' << ltm->tm_sec << " Temperature : " << param_p.m_temp << endl;
        cout << ltm->tm_hour << ':' << ltm->tm_min << ':' << ltm->tm_sec << " Pressure : " << param_p.m_press << endl;
        cout << ltm->tm_hour << ':' << ltm->tm_min << ':' << ltm->tm_sec << " Light : " << param_p.m_light << endl;
        cout << ltm->tm_hour << ':' << ltm->tm_min << ':' << ltm->tm_sec << " Humidity : " << param_p.m_humid << "\n"
             << endl;
    }
}

void server::fileWrite(const packet param_p)
{
    if (fileActivation)
    {
        ofstream file1("flight_record_temperature.txt", ios::out | ios::app);
        ofstream file2("flight_record_pressure.txt", ios::out | ios::app);
        ofstream file3("flight_record_light.txt", ios::out | ios::app);
        ofstream file4("flight_record_humidity.txt", ios::out | ios::app);
        time_t current = time(0);
        tm *ltm = localtime(&current);

        if (file1)
        {
            file1 << ltm->tm_hour << ':' << ltm->tm_min << ':' << ltm->tm_sec << " Temperature : " << param_p.m_temp << endl;
            file1.close();
        }
        else
        {
            cerr << "Cannot open file" << endl;
        }
        if (file2)
        {
            file2 << ltm->tm_hour << ':' << ltm->tm_min << ':' << ltm->tm_sec << " Pressure : " << param_p.m_press << endl;
            file2.close();
        }
        else
        {
            cerr << "Cannot open file" << endl;
        }
        if (file3)
        {
            file3 << ltm->tm_hour << ':' << ltm->tm_min << ':' << ltm->tm_sec << " Light : " << param_p.m_light << endl;
            file3.close();
        }
        else
        {
            cerr << "Cannot open file" << endl;
        }
        if (file1)
        {
            file4 << ltm->tm_hour << ':' << ltm->tm_min << ':' << ltm->tm_sec << " Humidity : " << param_p.m_humid
                  << endl;
            file1.close();
        }
        else
        {
            cerr << "Cannot open file" << endl;
        }
    }
}

void server::fileReset()
{
    if (fileActivation)
    {
        char c = 'c';
        time_t current = time(0);
        char *dt = ctime(&current);

        while (c != 'Y' && c != 'N')
        {
            cout << "Voulez-vous effacer les donnees des anciens vols ? (Y/N)"
                 << endl;
            cin >> c;
        }

        if (c == 'Y')
        {
            ofstream file1("flight_record_temperature.txt", ios::out | ios::trunc);
            if (file1)
            {
                file1 << dt << "FLIGHT RECORD\n\n"
                      << endl;
                file1.close();
            }
            else
            {
                cerr << "Cannot open file" << endl;
            }

            ofstream file2("flight_record_pressure.txt", ios::out | ios::trunc);
            if (file2)
            {
                file2 << dt << "FLIGHT RECORD\n\n"
                      << endl;
                file2.close();
            }
            else
            {
                cerr << "Cannot open file" << endl;
            }
            ofstream file3("flight_record_light.txt", ios::out | ios::trunc);
            if (file3)
            {
                file3 << dt << "FLIGHT RECORD\n\n"
                      << endl;
                file3.close();
            }
            else
            {
                cerr << "Cannot open file" << endl;
            }

            ofstream file4("flight_record_humidity.txt", ios::out | ios::trunc);
            if (file4)
            {
                file4 << dt << "FLIGHT RECORD\n\n"
                      << endl;
                file4.close();
            }
            else
            {
                cerr << "Cannot open file" << endl;
            }
        }
        else
        {
            ofstream file1("flight_record_temperature.txt", ios::out | ios::app);
            if (file1)
            {
                file1 << "\n\n"
                      << dt << "FLIGHT RECORD\n\n"
                      << endl;
                file1.close();
            }
            else
            {
                cerr << "Cannot open file" << endl;
            }

            ofstream file2("flight_record_pressure.txt", ios::out | ios::app);
            if (file2)
            {
                file2 << "\n\n"
                      << dt << "FLIGHT RECORD\n\n"
                      << endl;
                file2.close();
            }
            else
            {
                cerr << "Cannot open file" << endl;
            }

            ofstream file3("flight_record_light.txt", ios::out | ios::app);
            if (file3)
            {
                file3 << "\n\n"
                      << dt << "FLIGHT RECORD\n\n"
                      << endl;
                file3.close();
            }
            else
            {
                cerr << "Cannot open file" << endl;
            }

            ofstream file4("flight_record_humidity.txt", ios::out | ios::app);
            if (file4)
            {
                file4 << "\n\n"
                      << dt << "FLIGHT RECORD\n\n"
                      << endl;
                file4.close();
            }
            else
            {
                cerr << "Cannot open file" << endl;
            }
        }
    }
}

server &server::chooseFileActivation()
{
    char c = 'c';
    while (c != 'Y' && c != 'N')
    {
        cout << "Voulez-vous enregistrer les donnees dans des fichiers ? (Y/N)"
             << endl;
        cin >> c;
    }

    if (c == 'Y')
    {
        fileActivation = true;
    }
    else
    {
        fileActivation = false;
    }

    return *this;
}

server &server::chooseConsoleActivation()
{
    char c = 'c';
    while (c != 'Y' && c != 'N')
    {
        cout << "Voulez-vous afficher les donnees dans dans la console ? (Y/N)"
             << endl;
        cin >> c;
    }

    if (c == 'Y')
    {
        consoleActivation = true;
    }
    else
    {
        consoleActivation = false;
    }

    return *this;
}