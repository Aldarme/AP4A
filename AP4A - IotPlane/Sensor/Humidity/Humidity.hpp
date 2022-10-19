/**
 * @author NANMEGNI_NGASSAM
 * @file Humidity.hpp
 * @date 18/10/2022
 * @licence libre
 */

#ifndef HUMIDITY_HPP
#define HUMIDITY_HPP
/**
 * @class Humidity
 * @brief Capteur particulier qui récupère les données liées à l'humidité
 */
#include "../Sensor.hpp"

class Humidity : public Sensor<float>
{
private:
  std::string unit;
  int delay;

protected:
  float aleaGenVal();
  
public:
  //FORME CANONIQUE
  Humidity();
  Humidity(const Humidity& autre);
  Humidity(std::string unit, int delay);
  virtual ~Humidity();
  Humidity& operator=(const Humidity& autre);

  //AUTRES METHODES
  int getDelay();
  
};

#endif // HUMIDITY_HPP