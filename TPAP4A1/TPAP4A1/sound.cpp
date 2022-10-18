#pragma once

#include "sound.hpp"

sound::sound()
{
	this->value = aleaGenVal();
	//this->value = 0;
	this->name = 's';
};

sound::sound(const sound& s) {
	this->value = s.value;
	this->name = s.name;
};

int sound::aleaGenVal() {
	random_device rd;
	default_random_engine eng(rd());
	uniform_int_distribution<int> distr(FLOAT_MIN, FLOAT_MAX);
	return distr(eng);
}