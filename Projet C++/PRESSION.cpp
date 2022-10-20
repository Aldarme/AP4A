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

class Pression : public Sensor<int>
{
private:
    const string name = "Pression";//G¨¦n¨¦ration de diff¨¦rents types de donn¨¦es en nommant les capteurs
    int m_press;//Le capteur de pression transmet une valeur de type int
public:
    Pression()
    {
        cout << this->name << ":";
        this->type = "pression";
        this->m_value = Sensor<int>::aleaGenVal();
    }

    ~Pression()
    {

    }
    Pression& operator=(const Pression& param_s)
    {
        this->m_press = param_s.m_press;
        return *this;
    }
    void sense();
};

#endif