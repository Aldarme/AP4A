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

class Humidity : public Sensor
{
private:
  float m_habs;

public:
  Humidity();
  Humidity(const float& h);
  Humidity& operator=(const Humidity& param_h);
  void run();
  Humidity getData();
  float getValue();
  std::string getType();
};

#endif