/*!
 * @author  Cuenot Benoit  
 * @file    Humidity.hpp
 * @date    11/10/2022  
 * @brief   Cette classe est le Humidity.hpp. C'est la class fille de Sensor.
 *          Les méthodes et attributs sont hérités mais la méthode aleaGenVal()
 *          est redéfini.              
 */

#ifndef HUMIDITY_HPP_INCLUDED
#define HUMIDITY_HPP_INCLUDED

#include "Sensor.hpp"

class Humidity : public Sensor{
      
        virtual int aleaGenVal();

    public :

        Humidity();
        ~Humidity();
        Humidity(Humidity& ObjHumidity_p);
};

#endif // HUMIDITY_HPP_INCLUDED