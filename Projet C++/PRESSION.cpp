/**
 * @author YUHUIFEI
 * @file PRESSION.cpp
 * @date 29/09/2022
 * @brief :La classe PRESSION permettra de caract¨¦riser un capteur de pression.
 */
#ifndef PRESSION_CPP
#define PRESSION_CPP


#include "PRESSION.h"
#include <iostream>

using namespace std;


void Pression::sense()
{
	this->m_value = Sensor<int>::aleaGenVal();
}

#endif