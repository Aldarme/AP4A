/**
 * @author YUHUIFEI
 * @file TEMPERARURE.h
 * @date 29/09/2022
 * @brief :La classe TEMPERATURE permettra de caract¨¦riser un capteur de temp¨¦rature.
 */

#ifndef TEMPERATURE_H
#define TEMPERATURE_H
#include "SENSOR.h"
#pragma once
using namespace std;

void Temperature::sense()
{
	this->m_value = Sensor<int>::aleaGenVal();
}
#endif//TEMPERATURE.H

