#pragma once

#include "humidity.hpp"

humidity::humidity()
{
	this->value = aleaGenVal();
	//this->value = 1;
	this->name = 'h';
};

humidity::humidity(const humidity& h)
{
	this->value = h.value;
	this->name = h.name;
};

float humidity::aleaGenVal() {
	random_device rd;
	default_random_engine eng(rd());
	uniform_real_distribution<float> distr(FLOAT_MIN, FLOAT_MAX);
	return distr(eng);
}