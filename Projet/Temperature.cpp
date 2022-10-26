/**
 * @author Erhart Eliott
 * @file Temperature.cpp
 * @date 03/10/2022
 * @brief 
 */

#include "Temperature.hpp"

float Temperature::aleaGenVal(float min, float max) 
	{
        bool sign;

		srand((int)time(0));

		if(aleaVal <= min)
		{
			aleaVal = aleaVal + (float)(rand()%10)/10;        
		}
		else if(aleaVal >= max)
		{
			aleaVal = aleaVal - (float)(rand()%10)/10;          
		}
		else
		{
			sign = (bool)(rand()%(2));                     
			if(sign)
			{
				aleaVal = aleaVal + (float)(rand()%10)/10;
			}
			else
			{
				aleaVal = aleaVal - (float)(rand()%10)/10;
			}
		}

		return aleaVal;
	}