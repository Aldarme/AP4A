/**
 * @author NANMEGNI_NGASSAM
 * @file Light.hpp
 * @date 18/10/2022
 * @licence libre
 */

#ifndef LIGHT_HPP
#define LIGHT_HPP
/**
 * @class Light
 * @brief Capteur particulier qui prélève des informations de l'avion liées à la luminosité
 */
#include "../Sensor.hpp"

class Light : public Sensor<bool>
{
private:
  std::string unit;
  int delay;
  
protected:
  bool aleaGenVal(); //retourne un vrai ou un faux au sujet de la présence de la lumière dans l'avion

public:
  // FORME CANONIQUE
  Light();
  Light(const Light& autre);
  Light(int delay);
  virtual ~Light();
  Light& operator=(const Light& autre);

  //AUTRES METHODES
  int getDelay();
};

#endif // LIGHT_HPP