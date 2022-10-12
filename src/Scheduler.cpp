#include "Scheduler.h"

#include <iostream>
#include <chrono>

using namespace std;

Scheduler::Scheduler()
{
	m_server = new Server();
	m_frequency = 2.;

    m_sensor1 = new Humidity<float>();
    m_sensor2 = new Light<bool>();
    m_sensor3 = new Pression<int>();
    m_sensor4 = new Temperature<float>();
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
    time_t lastTime = time(NULL); 
    time_t delta = 0;
    while (delta < frequency_p)
    {
        /*
        if(kbhit())
        {
            detection = getch();
            checkAnswer(detection);
            if((detection == 'y' || detection == 'q') && !m_server->m_consoleActivation && !m_server->m_logActivation)
            {
                return;
            }
        }
        */
        time_t now = time(NULL);
        delta = (now - lastTime);
    }
}

void Scheduler::ask()
{
	char answer;
	do{
		std::cout << "Activate console only : c" << std::endl;
		std::cout << "Activate logs only : l" << std::endl;
		std::cout << "Activate logs and console : y" << std::endl; 
		std::cout << "\nTo desactivate/activate \n\t- logs\n\t- console\n\t- both\nduring the program, press the same keys as mentionned above during the program" << std::endl;			std::cout << "\n-- Press 'q' to simply quit the programm --\n" << std::endl;
		std::cin >> answer;
	}while(answer != 'c' && answer != 'l' && answer != 'y' && answer != 'q');
	checkAnswer(answer);
}

void Scheduler::launchThreads(){
    std::thread thread1([this](){
		loop(*m_sensor1,1.F);
	});
	std::thread thread2([this](){
		loop(*m_sensor2,2.F);
	});
	std::thread thread3([this](){
		loop(*m_sensor3,3.F);
	});	
    std::thread thread4([this](){
	    loop(*m_sensor4,5.F);
	});
    std::thread thread5([this](){
        while(isRunning()) ask();
	});

	thread1.join();
	thread2.join();
	thread3.join();
	thread4.join();
	thread5.join();

	if(!isRunning()){
		thread1.detach();
		thread2.detach();
		thread3.detach();
		thread4.detach();
        thread5.detach();
	}
}

bool Scheduler::isRunning()
{
    return (m_server->m_consoleActivation || m_server->m_logActivation);
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