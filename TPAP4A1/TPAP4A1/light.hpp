#pragma once
#include "sensor.hpp"

class light:public sensor <bool>
{
private:

public:

	light();

	light(const light& l);

	virtual bool aleaGenVal() ;
};