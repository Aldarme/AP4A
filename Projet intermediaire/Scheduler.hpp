/**
 * @author Tontsa apala frank
 * @file Scheduler.hpp
 * @date 25/09/2022
 * @brief Scheduler
 */

#include <iostream>
#include <fstream>
#include <string>
#include "Server.hpp"
#include "Sensor.hpp"
#include "Temperature.hpp"
#include"Light.hpp"
#include"Pression.hpp"
#include"Humidity.hpp"

#ifndef SCHEDULER_H
#define SCHEDULER_H
class Scheduler{
  
    private : Server m_S;
     Temperature m_T;
    Humidity m_H;
    Pression m_P;
     Light m_L;

   
    public : Scheduler(){};  //constructeur

    
    public : void dataServer();


};
#endif    //SCHEDULER_H
