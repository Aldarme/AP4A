/**
 * @author YUHUIFEI
 * @file PRESSION.h
 * @date 29/09/2022
 * @brief :La classe PRESSION permettra de caract¨¦riser un capteur de pression.
 */
#ifndef PRESSION_H
#define PRESSION_H
#pragma once

#include "SENSOR.h"
#include <iostream>



using namespace std;


void Pression::sense()
{
    this->m_value = Sensor<int>::aleaGenVal();
}

#endif//PRESSION.H
