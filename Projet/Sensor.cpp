#include "Sensor.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Sensor::Sensor()
{
    this->value=7;
}

Sensor::Sensor(float value)
{
    this->value=value;
}

Sensor::~Sensor()
{

}
void Sensor::setter(float val)
{
    this->value=val;
}

int Sensor::getData()
{
    return this->value;
}

float aleaGenVal(int max){
    float generatedNumber;
    generatedNumber=rand()%max;
    return generatedNumber;
}

bool aleaGenValBool(int max){
    bool generatedNumber=false;
    int k;
    k=rand()%max;
    if (k==1)
    {
        /* code */
        generatedNumber=true;
    }
    
    return generatedNumber;
}

/*
{
    this->value=rand()%50;
}*/
// generate random value
/*int generateRandom()
{
    srand((unsigned) time(NULL));
    //srand(unsigned int 9);
    int random = (rand()%30);
    return random;
}*/

Temperature::Temperature()
{
        this->value=27;
}

Temperature::~Temperature()
{

}

Pressure::Pressure()
{
    this->value=39;
}

Pressure::~Pressure()
{

}

Humidity::Humidity()
{
    this->value=21;
}

Humidity::~Humidity()
{

}

Light::Light()
{
    this->lightPresent=true;
}

Light::~Light()
{

}

int Light::getData()
{
    return this->lightPresent;
}

void Light::setter(bool state)
{
    this->lightPresent=state;
}

//methode getData (all)

/*void getData()
{
    int ran=generateRandom();
    std::cout<<"value :"<<ran<<std::endl;
}*/




