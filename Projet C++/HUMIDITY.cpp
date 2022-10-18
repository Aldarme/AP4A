/**
 * @author YUHUIFEI
 * @file HUMIDITY.cpp
 * @date 29/09/2022
 * @brief :La classe HUMIDITY permettra de caract¨¦riser un capteur d'humidit¨¦.
 */
#ifndef HUMIDTY_CPP
#define HUMIDITY_CPP

#include <iostream>
#include<string>
#include "Humidity.h"
using namespace std;

//Obtenir des donn¨¦es al¨¦atoires
void Humidity::sense()
{
	this->m_value = Sensor<float>::aleaGenVal();
}
#endif