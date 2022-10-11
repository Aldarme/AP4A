#ifndef PRESSION_H
#define PRESSION_H
#pragma once

#include "Sensor.hpp"
#include <iostream>

using namespace std;

class Pression : public Sensor<int>{
    private:
    public:

    Pression()
    {
        this->type = "pression";
        this->value = Sensor<int>::getData();
    }
    ~Pression(){};
};

#endif