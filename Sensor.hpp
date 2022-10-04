#pragma once 
#include <iostream>
#include <cstdio>
class Humidity;
class Temperature;
class Pression;
class Light;
using namespace std;



class Sensor 
{
    protected :
        int min;
        int max;
        int aleaGenVal(); 
        int value;

    public :
        Sensor(); //constructeur
        int getData();
};

