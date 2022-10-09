#ifndef FICHIER_H
#define FICHIER_H

#include <iostream>
#include <cstdlib>
#include <ctime>

class sensor
{
private:
    int data;

public:
    sensor() : data() {}
    sensor(const sensor &s) : data(s.data) {}
    ~sensor(){}

    int min;
    int max;
    int aleaGenVal();
    sensor getData();
};

class temperature : public sensor
{
};

class pression : public sensor
{
};

class light : public sensor
{
};

class humidity : public sensor
{
};

#endif //FICHIER_H