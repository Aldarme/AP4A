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
protected:
  bool aleaGenVal(); //retourne un vrai ou un faux au sujet de la présence de la lumière dans l'avion

public:
  // FORME CANONIQUE
  Light();
  Light(const Light& autre);
  virtual ~Light();
  Light& operator=(const Light& autre);
};

#endif // LIGHT_HPP