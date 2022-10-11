/*!
 * @author  Cuenot Benoit  
 * @file    Light.hpp
 * @date    11/10/2022  
 * @brief   Cette classe est le Light.hpp. C'est la class fille de Sensor.
 *          Les méthodes et attributs sont hérités mais la méthode aleaGenVal()
 *          est redéfini.              
 */


#ifndef LIGHT_HPP_INCLUDED
#define LIGHT_HPP_INCLUDED

#include "Sensor.hpp"

class Light : public Sensor{
      
        virtual int aleaGenVal();

    public :

        Light();
        ~Light();
        Light(const Light& objLight_p);
};



#endif // LIGHT_HPP_INCLUDED