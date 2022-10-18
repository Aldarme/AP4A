#pragma once

#include "light.hpp"

light::light()
	{
		this->value = aleaGenVal();
		//this->value = 0;
		this->name = 'l';
	};

light::light(const light& l)
	{
		this->value = l.value;
		this->name = l.name;
	};

bool light:: aleaGenVal() {
		random_device rd;
		default_random_engine eng(rd());
		bernoulli_distribution d(0.5);
		return d(eng);
	}
