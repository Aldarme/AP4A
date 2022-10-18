#pragma once

#include "temperature.hpp"

temperature::temperature()
{
	this->value = aleaGenVal();
	//this->value = 1;
	this->name = 't';
};

temperature::temperature(const temperature& t) {
	this->value = t.value;
	this->name = t.name;
};

float temperature::aleaGenVal() {
	random_device rd;
	default_random_engine eng(rd());
	uniform_real_distribution<float> distr(FLOAT_MIN, FLOAT_MAX);
	return distr(eng);
}