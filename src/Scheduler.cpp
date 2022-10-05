#include "Scheduler.h"
#include "windows.h"
#include <conio.h>

#include <iostream>
#include <chrono>

using namespace std;


Scheduler::Scheduler()
{
	m_server = new Server();
	m_frequency = 2.;

    m_sensor1 = new Humidity();
    m_sensor2 = new Light();
    m_sensor3 = new Pression();
    m_sensor4 = new Temperature();
}

Scheduler::Scheduler(Scheduler& scheduler_p)
{
    this->m_sensor1 = scheduler_p.m_sensor1;
    this->m_sensor2 = scheduler_p.m_sensor2;
    this->m_sensor3 = scheduler_p.m_sensor3;
    this->m_sensor4 = scheduler_p.m_sensor4;
    
    m_server = scheduler_p.m_server;
	m_frequency = scheduler_p.m_frequency;
}

Scheduler& Scheduler::operator=(Scheduler& scheduler_p)
{
    this->m_sensor1 = scheduler_p.m_sensor1;
    this->m_sensor2 = scheduler_p.m_sensor2;
    this->m_sensor3 = scheduler_p.m_sensor3;
    this->m_sensor4 = scheduler_p.m_sensor4;

    m_server = scheduler_p.m_server;
	m_frequency = scheduler_p.m_frequency;

    return *this;
}

void Scheduler::wait(float frequency_p)
{
    char detection;

    time_t lastTime = time(NULL); 
    time_t delta = 0;
    while (delta < frequency_p)
    {
        if(kbhit())
        {
            detection = getch();
            checkAnswer(detection);
            if((detection == 'y' || detection == 'q') && !m_server->m_consoleActivation && !m_server->m_logActivation)
            {
                return;
            }
        }
        time_t now = time(NULL);
        delta = (now - lastTime);
    }
}

bool Scheduler::isRunning()
{
    return (m_server->m_consoleActivation || m_server->m_logActivation);
}

void Scheduler::clock()
{
    while(isRunning()){
        this->wait(m_frequency);
        m_sensor1->refreshData();
        m_sensor2->refreshData();
        m_sensor3->refreshData();
        m_sensor4->refreshData();
        if(m_server->m_consoleActivation)
        {
            m_server->consoleWrite(*m_sensor1);
            m_server->consoleWrite(*m_sensor2);
            m_server->consoleWrite(*m_sensor3);
            m_server->consoleWrite(*m_sensor4);
            cout << "" << endl; 
        }
        if(m_server->m_logActivation)
        {
            m_server->fileWrite(*m_sensor1);
            m_server->fileWrite(*m_sensor2);
            m_server->fileWrite(*m_sensor3);
            m_server->fileWrite(*m_sensor4);
        }
    }
}

void Scheduler::ask()
{
    char answer;
    do{
        cout << "Activate console only : c" << endl;
        cout << "Activate logs only : l" << endl;
        cout << "Activate logs and console : y" << endl; 
        cout << "\nTo desactivate/activate \n\t- logs\n\t- console\n\t- both\nduring the program, press the same keys as mentionned above during the program" << endl;
        cout << "\n-- Press 'q' to simply quit the programm --\n" << endl;
        cin >> answer;
    }while(answer != 'c' && answer != 'l' && answer != 'y' && answer != 'q');

    checkAnswer(answer);
    this->clock();
}

void Scheduler::checkAnswer(char answer_p)
{
    switch(answer_p){
        case 'q' :
            m_server->m_consoleActivation = false;
            m_server->m_logActivation = false;
            cout << "Quitting program" << endl;
        break;
        case 'c' :
            if(m_server->m_consoleActivation){
                m_server->m_consoleActivation = false;
                cout << "Console log desactivated!" << endl;
            }
            else
            {
                m_server->m_consoleActivation = true;
                cout << "Console log activated!" << endl;
            }
        break;
        case 'l' :
            if (m_server->m_logActivation)
            {
                m_server->m_logActivation = false;
                cout << "Logs desactivated!" << endl;
            }
            else
            {
                m_server->m_logActivation = true;
                cout << "Logs activated!" << endl;
            }
        break;
        case 'y' :
            if(m_server->m_consoleActivation && m_server->m_logActivation)
            {
                m_server->m_consoleActivation = false;
                m_server->m_logActivation = false;
                cout << "Console & Logs desactivated!" << endl;
            }
            else
            {
                m_server->m_consoleActivation = true;
                m_server->m_logActivation = true;
                cout << "Console & Logs activated!" << endl;
            }
        break;
    }
}