#include "Server.hpp"
using namespace std;

void server::consolWrite()
{
    cout << "Temperature : " << m_temperature << endl;
    cout << "Pression : " << m_pression << endl;
    cout << "Light : " << m_light << endl;
    cout << "Humidity : " << m_humidity << endl;
}