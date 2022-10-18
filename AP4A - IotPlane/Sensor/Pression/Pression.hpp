/**
 * @author NANMEGNI_NGASSAM
 * @file Pression.hpp
 * @date 18/10/2022
 * @licence libre
 */

#ifndef PRESSION_HPP
#define PRESSION_HPP
/**
 * @class Pression
 * @brief Capteur particulier qui met à disposition  les données de pression de l'avion
 */
#include "../Sensor.hpp"

class Pression : public Sensor<int>
{
private:
  std::string unity;
  
protected:
  int aleaGenVal();

public:
  //FORME CANONIQUE
  Pression();
  Pression(const Pression& autre);
  virtual ~Pression();
  Pression& operator=(const Pression& autre);

  //AUTRES METHODES

};

#endif // PRESSION_HPP