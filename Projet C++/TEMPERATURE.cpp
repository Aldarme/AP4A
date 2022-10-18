/**
 * @author YUHUIFEI
 * @file TEMPERARURE.cpp
 * @date 29/09/2022
 * @brief :La classe TEMPERATURE permettra de caract¨¦riser un capteur de temp¨¦rature.
 */
#ifndef TEMPERATURE_CPP
#define TEMPERATURE_CPP

#include <iostream>
#include "TEMPERATURE.h"
#include <string>
using namespace std;

void Temperature::sense()
{
	this->m_value = Sensor<int>::aleaGenVal();
}
#endif