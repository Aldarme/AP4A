#include "Server.hpp"
#include <fstream>
#include <ctime>
using namespace std;

server server::getData(scheduler s)
{
    m_packet = s.transferData();
    return *this;
}

void server::consolWrite()
{
    time_t current = time(0);
    tm *ltm = localtime(&current);
    cout << ltm->tm_hour << ':' << ltm->tm_min << ':' << ltm->tm_sec << " Temperature : " << m_packet.m_temp << endl;
    cout << ltm->tm_hour << ':' << ltm->tm_min << ':' << ltm->tm_sec << " Pressure : " << m_packet.m_press << endl;
    cout << ltm->tm_hour << ':' << ltm->tm_min << ':' << ltm->tm_sec << " Light : " << m_packet.m_light << endl;
    cout << ltm->tm_hour << ':' << ltm->tm_min << ':' << ltm->tm_sec << " Humidity : " << m_packet.m_humid << "\n"
         << endl;
}

void server::fileWrite()
{
    ofstream file("flight_record.txt", ios::out | ios::app);
    time_t current = time(0);
    tm *ltm = localtime(&current);
    if (file)
    {
        file << ltm->tm_hour << ':' << ltm->tm_min << ':' << ltm->tm_sec << " Temperature : " << m_packet.m_temp << endl;
        file << ltm->tm_hour << ':' << ltm->tm_min << ':' << ltm->tm_sec << " Pressure : " << m_packet.m_press << endl;
        file << ltm->tm_hour << ':' << ltm->tm_min << ':' << ltm->tm_sec << " Light : " << m_packet.m_light << endl;
        file << ltm->tm_hour << ':' << ltm->tm_min << ':' << ltm->tm_sec << " Humidity : " << m_packet.m_humid << "\n"
             << endl;

        file.close();
    }
    else
    {
        cerr << "Cannot open file" << endl;
    }
}

void server::fileReset()
{
    ofstream file("flight_record.txt", ios::out | ios::trunc);
    time_t current = time(0);
    char* dt = ctime(&current);
    if (file)
    {
        file << dt << " FLIGHT RECORD\n\n" << endl;
    }
    else
    {
        cerr << "Cannot open file" << endl;
    }
}