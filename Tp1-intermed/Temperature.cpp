/**
* @author MOhana wael
* @file : Temperature.cpp
* @date 27/09/2020
* @Description Declaration classe Temperature
*/

#include <iostream>
#include "./Temperature.hpp"

Temperature::Temperature(const Temperature& autre){ this->val = autre.val;}

Temperature::~Temperature(){}