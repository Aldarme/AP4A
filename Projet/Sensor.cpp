/**
 * @author mayer_thibault
 * @file Sensor.cpp
 * @date 02/10/2022
 * @brief
 */

#include <cstdlib>

class Sensor
{
private:
public:
	Sensor();
	~Sensor();
	void run();
	//function that randomise value between 0 and 100
	float aleaGenVal()
	{
		return (rand() % 100) + 1.0f;
	};
};
