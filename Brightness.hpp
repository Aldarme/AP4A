/*      author:TRABOULSI Rawan
        BRIGHTNESS
        Créé le 19/09/2020 */


#ifndef BRIGHTNESS_HPP
#define BRIGHTNESS_HPP
#include "Sensor.hpp"
#include <string>

class Brightness: public Sensor<bool>{//Luminosité de type bool
    //Les Attributs
    private:
    int m_Brightnessmax;
    int m_Brightnessmin;
    

    
    
    public:

    Brightness();
    Brightness(const Brightness & autre);
    Brightness &operator=(const Brightness &);
    virtual~Brightness();
    //Les Méthodes
    int getBrightnessmax();
    int getBrightnessmin();

    


};

#endif //BRIGHTNESS_H