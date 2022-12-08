/**
 * @author NANMEGNI_NGASSAM
 * @file Temperature.hpp
 * @date 19/10/2022
 * @licence libre
 */

#ifndef TEMPERATURE_HPP
#define TEMPERATURE_HPP
/**
 * @class Temperature
 * @brief Prélève les données relatives à la temperature de l'avion
 */
#include "../Sensor.hpp"

class Temperature : public Sensor<float>
{
private:
  std::string unit;
  int delay;

protected:
  float aleaGenVal();

public:
  //FORME CANONIQUE
  Temperature();
  Temperature(const Temperature& temp);
  Temperature(std::string unit, int delay);
  virtual ~Temperature();
  Temperature& operator=(const Temperature& temp);

  //AUTRES METHODES
  int getDelay();
};

#endif //TEMPERATURE_HPP