/**
 * @author YUHUIFEI
 * @file HUMIDITY.h
 * @date 29/09/2022
 * @brief :La classe HUMIDITY permettra de caract¨¦riser un capteur d'humidit¨¦.
 */
#ifndef HUMIDITY_H
#define HUMIDITY_H
#include "SENSOR.h"
#pragma once
using namespace std;

//Obtenir des donn¨¦es al¨¦atoires
void Humidity::sense()
{
	this->m_value = Sensor<float>::aleaGenVal();
}
#endif//HUMIDITY.H
