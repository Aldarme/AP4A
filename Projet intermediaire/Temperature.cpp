/**
 * @author Tontsa apala frank
 * @file Temperature.cpp
 * @date 25/09/2022
 * @brief Temperature sensor
 */

#include <iostream>
#include "Temperature.hpp"

Temperature::Temperature(const Temperature& T)
{ this->val = T.val;}

Temperature::~Temperature(){}
