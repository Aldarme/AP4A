/**
 * @author mayer_thibault
 * @file Humidity.hpp
 * @date 04/10/2022
 * @brief Humidity header
 */
//Humidity.hpp
#ifndef HUMIDITY_HPP
#define HUMIDITY_HPP
#include <string>
#include "Sensor.hpp"
#include <cstdlib>
#include <iostream>

class Humidity : public Sensor
{
public:
  Humidity();
  Humidity(const Humidity& h);
  Humidity(time_t period_p);
  Humidity& operator=(const Humidity& param_h);
  Data<float> getData();
  std::string getType();
};

#endif