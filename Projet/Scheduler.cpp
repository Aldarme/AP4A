/**
 * @file Scheduler.cpp
 * @author Aurélien PETRA
 * @brief Fait le lien entre la classe sensor et la classe server et définie une horloge
 * @version 0.1
 * @date 2022-10-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

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

void scheduler::loop(server &param_serv)
{
    string str = "s";
    int loop = 0;
    int i = 0;

    temperature t;
    pressure p;
    light_ l;
    humidity h;

    int count_temp = 1;
    int count_light = 4;
    int count_humid = 1;

    do
    {
        cout << "Pendant combien de secondes voulez enregistrer les donnees des capteurs ?"
             << endl;
        cin >> str;

    } while (str.find_first_not_of("0123456789") != string::npos);
    loop = stoi(str);

    t.aleaInitVal();
    p.aleaInitVal();
    l.aleaInitVal();
    h.aleaInitVal();

    while (i < loop)
    {
        thread th(Sleep, 1000);

        if (count_temp == 1)
        {
            getTemp(t);
            count_temp = 0;
        }
        else
        {
            count_temp++;
        }

        getPress(p);

        if (count_light == 4)
        {
            getLight(l);
            count_light = 0;
        }
        else
        {
            count_light++;
        }

        if (count_humid == 1)
        {
            getHumid(h);
            count_humid = 0;
        }
        else
        {
            count_humid++;
        }

        th.join();
        param_serv.consolWrite(m_packet);
        param_serv.fileWrite(m_packet);
        i++;
    }
}

scheduler &scheduler::getData(temperature param_t, pressure param_p, light_ param_l, humidity param_h)
{
    getTemp(param_t);
    getPress(param_p);
    getLight(param_l);
    getHumid(param_h);

    return *this;
}

scheduler &scheduler::getTemp(temperature param_t)
{
    param_t.aleaGenVal();
    m_packet.m_temp = param_t.getData();

    return *this;
}

scheduler &scheduler::getPress(pressure param_p)
{
    param_p.aleaGenVal();
    m_packet.m_press = param_p.getData();

    return *this;
}

scheduler &scheduler::getLight(light_ param_l)
{
    param_l.aleaGenVal();
    m_packet.m_light = param_l.getData();

    return *this;
}

scheduler &scheduler::getHumid(humidity param_h)
{
    param_h.aleaGenVal();
    m_packet.m_humid = param_h.getData();

    return *this;
}