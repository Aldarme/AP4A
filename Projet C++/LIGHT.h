/**
 * @author YUHUIFEI
 * @file LIGHT.h
 * @date 29/09/2022
 * @brief :La classe LIGHT permettra de caract¨¦riser un capteur de luminance.
 */
#ifndef LIGHT_H
#define LIGHT_H
#include "SENSOR.h"
#pragma once


void Light::sense()
{
	this->m_value = Sensor<bool>::aleaGenVal();
}
#endif//LIGHT.H


