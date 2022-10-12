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

class Humidity
{
  public:
    Humidity();
    ~Humidity();
    void run();
    Humidity getData();
    float getValue();
    std::string getType();
};

#endif