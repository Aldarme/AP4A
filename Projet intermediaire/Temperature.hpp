/*!
 * @author  Cuenot Benoit  
 * @file    Temperature.hpp
 * @date    11/10/2022  
 * @brief   Cette classe est le Temperature.hpp. C'est la class fille de Sensor.
 *          Les méthodes et attributs sont hérités mais la méthode aleaGenVal()
 *          est redéfini.              
 */

#ifndef TEMPERATURE_HPP_INCLUDED
#define TEMPERATURE_HPP_INCLUDED

#include "Sensor.hpp"

class Temperature : public Sensor{
      
        virtual int aleaGenVal();

    public :

        Temperature();
        ~Temperature();
        Temperature(const Temperature& objTemperature_p);
};



#endif // TEMPERATURE_HPP_INCLUDED