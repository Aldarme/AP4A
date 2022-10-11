#include "Scheduler.hpp"
using namespace std;

scheduler &scheduler::operator=(const scheduler &param_s)
{
    m_packet = param_s.m_packet;
    return *this;
}

void scheduler::timer()
{
    Sleep(1000);
}

void scheduler::loop(server param_serv)
{
    string str = "s";
    int loop = 0;
    int i = 0;

    do
    {
        cout << "Pendant combien de secondes voulez enregistrer les donnees des capteurs ?"
             << endl;
        cin >> str;

    } while (str.find_first_not_of("0123456789") != string::npos);
    loop = stoi(str);

    while (i < loop)
    {
        getData();
        param_serv.consolWrite(transferData());
        param_serv.fileWrite(transferData());
        i++;
        timer();
    }
}

scheduler &scheduler::getData()
{
    temperature t;
    pressure p;
    light_ l;
    humidity h;

    m_packet.m_temp = t.aleaGenVal();
    m_packet.m_press = p.aleaGenVal();
    m_packet.m_light = l.aleaGenVal();
    m_packet.m_humid = h.aleaGenVal();

    return *this;
}

packet scheduler::transferData()
{
    return m_packet;
}