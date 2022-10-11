#ifndef LIGHT_H
#define LIGHT_H
#include "Sensor.hpp"
#pragma once

using namespace std;

class Light : public Sensor<bool>{
private:
public:
	
	Light(){};
    Light(const Light&); 
    Light &operator=(const Light&);
	~Light(){};
};
#endif