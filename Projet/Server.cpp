#include "Server.hpp"
using namespace std;

server server::getData(scheduler s)
{
    m_packet = s.transferData();
    return *this;
}

void server::consolWrite()
{
    cout << "Temperature : " << m_packet.m_temp << endl;
    cout << "Pression : " << m_packet.m_press << endl;
    cout << "Light : " << m_packet.m_light << endl;
    cout << "Humidity : " << m_packet.m_humid << "\n" << endl;
}