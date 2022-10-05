//
// Created by rayan on 05/10/2022.
//
#include "Time.hpp"

Time::Time() : m_TypeSensor(e_type), m_clock(), m_duration(1000){}

Time::Time(TypeSensor sT, int ms) : m_TypeSensor(sT), m_clock(), m_duration(ms){}

Time::~Time()= default;

bool Time::checkTime()
{
    if ((double)(clock() - this->m_clock) * 1000 / CLOCKS_PER_SEC >= this->m_duration)
    {
        this->m_clock = clock();
        return true;
    }
    return false;
}