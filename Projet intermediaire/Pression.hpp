/*!
 * @author  Cuenot Benoit  
 * @file    Pression.hpp
 * @date    11/10/2022  
 * @brief   Cette classe est le Pression.hpp. C'est la class fille de Sensor.
 *          Les méthodes et attributs sont hérités mais la méthode aleaGenVal()
 *          est redéfini.              
 */

#ifndef PRESSION_HPP_INCLUDED
#define PRESSION_HPP_INCLUDED

#include "Sensor.hpp"

class Pression : public Sensor{
      
            virtual int aleaGenVal();

    public :

            Pression();
            ~Pression();
            Pression(const Pression& objPression_p);
};



#endif // PRESSION_HPP_INCLUDED